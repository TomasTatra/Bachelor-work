// SPDX-License-Identifier: MIT
// Copyright (c) 2018-2022 The Pybricks Authors

/**
 * @addtogroup Servo pbio/servo: Servo control functions
 *
 * API for motors with position feedback.
 * @{
 */

#ifndef _PBIO_SERVO_H_
#define _PBIO_SERVO_H_

#include <pbio/config.h>

#if PBIO_CONFIG_SERVO

#if PBIO_CONFIG_SERVO_NUM_DEV != PBIO_CONFIG_DCMOTOR_NUM_DEV
#error "Number of DC Motors expected to be equal to number of Servo Motors."
#endif

#include <stdint.h>

#include <pbdrv/config.h>
#include <pbdrv/counter.h>

#include <pbio/error.h>
#include <pbio/port.h>
#include <pbio/dcmotor.h>
#include <pbio/tacho.h>
#include <pbio/trajectory.h>
#include <pbio/control.h>
#include <pbio/observer.h>
#include <pbio/logger.h>

#include <pbio/iodev.h>

// Number of values per row when servo data logger is active.
#define PBIO_SERVO_LOGGER_NUM_COLS (10)

/**
 * The servo system combines a dcmotor and rotation sensor with a controller
 * to provide speed and position control.
 *
 * All public pbio servo calls (pbio_servo_...) work with angles expressed
 * in degrees and speeds in degrees per second, measured at the output
 * of the external gear train, unless stated otherwise.
 *
 * Internally, the servo controller operates using millidegrees, measured at
 * the motor shaft. Scaling happens through the gear ratio value given during
 * the servo setup.
 */
typedef struct _pbio_servo_t {
    /**
     * The dcmotor being controlled.
     */
    pbio_dcmotor_t *dcmotor;
    /**
     * The tacho device that measures the motor angle.
     */
    pbio_tacho_t *tacho;
    /**
     * The controller for this servo.
     */
    pbio_control_t control;
    /**
     * Luenberger state observer to estimate motor speed.
     */
    pbio_observer_t observer;
    /**
     * Structure with data log settings and pointer to data buffer if active.
     */
    pbio_log_t log;
    /**
     * Link to parent object that uses this servo, like a drive base.
     */
    pbio_parent_t parent;
    /**
     * Internal flag used to set whether the servo state update loop should
     * keep running. This is false when the servo is unplugged or other errors
     * occur.
     */
    bool run_update_loop;
} pbio_servo_t;

/**
 * A minimal set of constant parameters for each motor type from which other
 * defaults are derived at runtime, to save space and ensure correct
 * configuration.
 */
typedef struct _pbio_servo_settings_reduced_t {
    /**
     * Type identifier indicating which motor it is.
     */
    pbio_iodev_type_id_t id;
    /**
     * Physical model parameter for this type of motor
     */
    const pbio_observer_model_t *model;
    /**
     * The rated maximum speed (deg/s), approximately equivalent to "100%" speed in other apps.
     */
    int32_t rated_max_speed;
    /**
     * Position error feedback constant. REVISIT: Derive from model.
     */
    int32_t pid_kp;
    /**
     * Speed error feedback constant. REVISIT: Derive from model.
     */
    int32_t pid_kd;
    /**
     * Feedback gain (mV/deg) to correct the observer for low estimation errors.
     */
    int32_t feedback_gain_low;
} pbio_servo_settings_reduced_t;

// Servo initialization and updates:

pbio_error_t pbio_servo_get_servo(pbio_port_id_t port, pbio_servo_t **srv);
pbio_error_t pbio_servo_setup(pbio_servo_t *srv, pbio_direction_t direction, int32_t gear_ratio, bool reset_angle);
pbio_error_t pbio_servo_actuate(pbio_servo_t *srv, pbio_dcmotor_actuation_t actuation_type, int32_t payload);
pbio_error_t pbio_servo_load_settings(pbio_control_settings_t *ctl, pbio_observer_settings_t *obs, const pbio_observer_model_t **model, pbio_iodev_type_id_t id);
void pbio_servo_update_all(void);

// Servo status:

pbio_error_t pbio_servo_get_state_control(pbio_servo_t *srv, pbio_control_state_t *state);
pbio_error_t pbio_servo_get_state_user(pbio_servo_t *srv, int32_t *angle, int32_t *speed);
bool pbio_servo_update_loop_is_running(pbio_servo_t *srv);
pbio_error_t pbio_servo_is_stalled(pbio_servo_t *srv, bool *stalled, uint32_t *stall_duration);
pbio_error_t pbio_servo_get_load(pbio_servo_t *srv, int32_t *load);

// Servo end user commands:

pbio_error_t pbio_servo_stop(pbio_servo_t *srv, pbio_control_on_completion_t on_completion);
pbio_error_t pbio_servo_reset_angle(pbio_servo_t *srv, int32_t reset_angle, bool reset_to_abs);
pbio_error_t pbio_servo_run_forever(pbio_servo_t *srv, int32_t speed);
pbio_error_t pbio_servo_run_time(pbio_servo_t *srv, int32_t speed, uint32_t duration, pbio_control_on_completion_t on_completion);
pbio_error_t pbio_servo_run_angle(pbio_servo_t *srv, int32_t speed, int32_t angle, pbio_control_on_completion_t on_completion);
pbio_error_t pbio_servo_run_target(pbio_servo_t *srv, int32_t speed, int32_t target, pbio_control_on_completion_t on_completion);
pbio_error_t pbio_servo_track_target(pbio_servo_t *srv, int32_t target);

#endif // PBIO_CONFIG_SERVO

#endif // _PBIO_SERVO_H_

/** @} */
