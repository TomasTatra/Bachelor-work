// SPDX-License-Identifier: MIT
// SPDX-License-Identifier: BSD-3-Clause
// Copyright (c) 2018-2022 The Pybricks Authors

#include <pbio/config.h>

#if PBIO_CONFIG_SERVO

#include <pbio/control.h>
#include <pbio/observer.h>
#include <pbio/iodev.h>

// Model settings auto-generated by pbio/doc/control/motor_data.py
#if PBIO_CONFIG_SERVO_PUP

static const pbio_observer_model_t model_technic_s_angular = {
    .d_angle_d_speed = 179217,
    .d_speed_d_speed = 956,
    .d_current_d_speed = -249247,
    .d_angle_d_current = 1950303,
    .d_speed_d_current = 7666,
    .d_current_d_current = -9356019,
    .d_angle_d_voltage = 5654927,
    .d_speed_d_voltage = 11702,
    .d_current_d_voltage = 349105,
    .d_angle_d_torque = -425928,
    .d_speed_d_torque = -1085,
    .d_current_d_torque = 383927,
    .d_voltage_d_torque = 22334,
    .d_torque_d_voltage = 17203,
    .d_torque_d_speed = 12282,
    .d_torque_d_acceleration = 354592,
    .torque_friction = 9182,
    .feedback_gain = 48,
};

static const pbio_observer_model_t model_technic_m_angular = {
    .d_angle_d_speed = 177194,
    .d_speed_d_speed = 934,
    .d_current_d_speed = -165023,
    .d_angle_d_current = 2407354,
    .d_speed_d_current = 8311,
    .d_current_d_current = 1058029,
    .d_angle_d_voltage = 7431528,
    .d_speed_d_voltage = 14444,
    .d_current_d_voltage = 225610,
    .d_angle_d_torque = -919183,
    .d_speed_d_torque = -2332,
    .d_current_d_torque = 629020,
    .d_voltage_d_torque = 47606,
    .d_torque_d_voltage = 8071,
    .d_torque_d_speed = 5903,
    .d_torque_d_acceleration = 163151,
    .torque_friction = 21413,
    .feedback_gain = 90,
};

static const pbio_observer_model_t model_technic_l_angular = {
    .d_angle_d_speed = 174943,
    .d_speed_d_speed = 904,
    .d_current_d_speed = -58045,
    .d_angle_d_current = 8368268,
    .d_speed_d_current = 26508,
    .d_current_d_current = 396164,
    .d_angle_d_voltage = 13442903,
    .d_speed_d_voltage = 25105,
    .d_current_d_voltage = 86900,
    .d_angle_d_torque = -3690545,
    .d_speed_d_torque = -9310,
    .d_current_d_torque = 975141,
    .d_voltage_d_torque = 133763,
    .d_torque_d_voltage = 2872,
    .d_torque_d_speed = 1919,
    .d_torque_d_acceleration = 40344,
    .torque_friction = 23239,
    .feedback_gain = 64,
};

static const pbio_observer_model_t model_interactive = {
    .d_angle_d_speed = 179110,
    .d_speed_d_speed = 941,
    .d_current_d_speed = -316164,
    .d_angle_d_current = 7311289,
    .d_speed_d_current = 35750,
    .d_current_d_current = -12014584,
    .d_angle_d_voltage = 4603893,
    .d_speed_d_voltage = 10967,
    .d_current_d_voltage = 355664,
    .d_angle_d_torque = -728461,
    .d_speed_d_torque = -1850,
    .d_current_d_torque = 668004,
    .d_voltage_d_torque = 32225,
    .d_torque_d_voltage = 11923,
    .d_torque_d_speed = 10599,
    .d_torque_d_acceleration = 207820,
    .torque_friction = 11227,
    .feedback_gain = 133,
};

static const pbio_observer_model_t model_technic_l = {
    .d_angle_d_speed = 175977,
    .d_speed_d_speed = 912,
    .d_current_d_speed = -159828,
    .d_angle_d_current = 5728019,
    .d_speed_d_current = 22787,
    .d_current_d_current = -44152415,
    .d_angle_d_voltage = 6164994,
    .d_speed_d_voltage = 12888,
    .d_current_d_voltage = 142828,
    .d_angle_d_torque = -1377701,
    .d_speed_d_torque = -3482,
    .d_current_d_torque = 794862,
    .d_voltage_d_torque = 62889,
    .d_torque_d_voltage = 6110,
    .d_torque_d_speed = 6837,
    .d_torque_d_acceleration = 108520,
    .torque_friction = 26430,
    .feedback_gain = 51,
};

static const pbio_observer_model_t model_technic_xl = {
    .d_angle_d_speed = 176559,
    .d_speed_d_speed = 916,
    .d_current_d_speed = -175173,
    .d_angle_d_current = 8098298,
    .d_speed_d_current = 35736,
    .d_current_d_current = -7606150,
    .d_angle_d_voltage = 5471477,
    .d_speed_d_voltage = 12148,
    .d_current_d_voltage = 156891,
    .d_angle_d_torque = -1282598,
    .d_speed_d_torque = -3244,
    .d_current_d_torque = 729279,
    .d_voltage_d_torque = 55617,
    .d_torque_d_voltage = 6908,
    .d_torque_d_speed = 7713,
    .d_torque_d_acceleration = 116867,
    .torque_friction = 12893,
    .feedback_gain = 77,
};

#if PBIO_CONFIG_SERVO_PUP_MOVE_HUB

static const pbio_observer_model_t model_movehub = {
    .d_angle_d_speed = 176283,
    .d_speed_d_speed = 913,
    .d_current_d_speed = -202833,
    .d_angle_d_current = 7437051,
    .d_speed_d_current = 32807,
    .d_current_d_current = -8118383,
    .d_angle_d_voltage = 5022928,
    .d_speed_d_voltage = 11156,
    .d_current_d_voltage = 157720,
    .d_angle_d_torque = -966059,
    .d_speed_d_torque = -2442,
    .d_current_d_torque = 636829,
    .d_voltage_d_torque = 45536,
    .d_torque_d_voltage = 8438,
    .d_torque_d_speed = 10851,
    .d_torque_d_acceleration = 155017,
    .torque_friction = 24835,
    .feedback_gain = 94,
};

#endif // PBIO_CONFIG_SERVO_PUP_MOVE_HUB

#endif // PBIO_CONFIG_SERVO_PUP

#if PBIO_CONFIG_SERVO_EV3_NXT

static const pbio_observer_model_t model_ev3_l = {
    .d_angle_d_speed = 173282,
    .d_speed_d_speed = 881,
    .d_current_d_speed = -69014,
    .d_angle_d_current = 15363470,
    .d_speed_d_current = 49919,
    .d_current_d_current = 491835,
    .d_angle_d_voltage = 30444180,
    .d_speed_d_voltage = 57613,
    .d_current_d_voltage = 118854,
    .d_angle_d_torque = -7467749,
    .d_speed_d_torque = -18754,
    .d_current_d_torque = 2298785,
    .d_voltage_d_torque = 107106,
    .d_torque_d_voltage = 3587,
    .d_torque_d_speed = 2083,
    .d_torque_d_acceleration = 19838,
    .torque_friction = 16476,
    .feedback_gain = 80,
};

static const pbio_observer_model_t model_ev3_m = {
    .d_angle_d_speed = 174833,
    .d_speed_d_speed = 899,
    .d_current_d_speed = -179788,
    .d_angle_d_current = 5508196,
    .d_speed_d_current = 20798,
    .d_current_d_current = 4313632,
    .d_angle_d_voltage = 10143433,
    .d_speed_d_voltage = 20656,
    .d_current_d_voltage = 196531,
    .d_angle_d_torque = -1577148,
    .d_speed_d_torque = -3975,
    .d_current_d_torque = 1082649,
    .d_voltage_d_torque = 47722,
    .d_torque_d_voltage = 8051,
    .d_torque_d_speed = 7365,
    .d_torque_d_acceleration = 94428,
    .torque_friction = 18317,
    .feedback_gain = 90,
};

#endif // PBIO_CONFIG_SERVO_EV3_NXT

/**
 * Gets the maximum allowed voltage for a dc motor.
 *
 * @param [in]  id          Device type id.
 * @return                  Maximum voltage (mV) for the given motor type.
 */
int32_t pbio_dcmotor_get_max_voltage(pbio_iodev_type_id_t id) {
    if (id == PBIO_IODEV_TYPE_ID_SPIKE_S_MOTOR) {
        return 6000;
    }
    return 9000;
}

#define DEG_TO_MDEG(deg) ((deg) * 1000)

/**
 * Loads device specific model parameters and control settings.
 *
 * @param [out]  ctl           Control settings like PID constants.
 * @param [out]  obs           Observer settings like gains and stall constants.
 * @param [out]  model         Model parameters for the state observer.
 * @param [in]   id            Type identifier for which to look up the settings.
 * @return                     Error code.
 */
pbio_error_t pbio_servo_load_settings(pbio_control_settings_t *ctl, pbio_observer_settings_t *obs, const pbio_observer_model_t **model, pbio_iodev_type_id_t id) {

    // Base control settings for all motors.
    ctl->speed_tolerance = DEG_TO_MDEG(50);
    ctl->position_tolerance = DEG_TO_MDEG(10);
    ctl->stall_speed_limit = DEG_TO_MDEG(20);
    ctl->stall_time = pbio_control_time_ms_to_ticks(200);
    ctl->integral_change_max = DEG_TO_MDEG(15);
    ctl->integral_deadzone = DEG_TO_MDEG(8);

    // Base observer settings for all motors.
    obs->stall_speed_limit = ctl->stall_speed_limit;
    obs->stall_time = ctl->stall_time;

    // Device type specific speed, acceleration, and PD settings.
    switch (id) {
        case PBIO_IODEV_TYPE_ID_NONE:
            return PBIO_ERROR_NOT_SUPPORTED;
        #if PBIO_CONFIG_SERVO_EV3_NXT
        case PBIO_IODEV_TYPE_ID_EV3_MEDIUM_MOTOR:
            *model = &model_ev3_m;
            ctl->speed_max = DEG_TO_MDEG(2000);
            ctl->acceleration = DEG_TO_MDEG(8000);
            ctl->pid_kp = 3000;
            ctl->pid_kd = 30;
            break;
        case PBIO_IODEV_TYPE_ID_EV3_LARGE_MOTOR:
            *model = &model_ev3_l;
            ctl->speed_max = DEG_TO_MDEG(1600);
            ctl->acceleration = DEG_TO_MDEG(3200);
            ctl->pid_kp = 15000;
            ctl->pid_kd = 250;
            break;
        #endif // PBIO_CONFIG_SERVO_EV3_NXT
        #if PBIO_CONFIG_SERVO_PUP
        case PBIO_IODEV_TYPE_ID_INTERACTIVE_MOTOR:
            *model = &model_interactive;
            ctl->speed_max = DEG_TO_MDEG(1000);
            ctl->acceleration = DEG_TO_MDEG(2000);
            ctl->pid_kp = 13500;
            ctl->pid_kd = 1350;
            break;
        #if PBIO_CONFIG_SERVO_PUP_MOVE_HUB
        case PBIO_IODEV_TYPE_ID_MOVE_HUB_MOTOR:
            *model = &model_movehub;
            ctl->speed_max = DEG_TO_MDEG(1500);
            ctl->acceleration = DEG_TO_MDEG(5000);
            ctl->pid_kp = 15000;
            ctl->pid_kd = 500;
            break;
        #endif // PBIO_CONFIG_SERVO_PUP_MOVE_HUB
        case PBIO_IODEV_TYPE_ID_TECHNIC_L_MOTOR:
            *model = &model_technic_l;
            ctl->speed_max = DEG_TO_MDEG(1470);
            ctl->acceleration = DEG_TO_MDEG(2000);
            ctl->pid_kp = 17500;
            ctl->pid_kd = 2500;
            break;
        case PBIO_IODEV_TYPE_ID_TECHNIC_XL_MOTOR:
            *model = &model_technic_xl;
            ctl->speed_max = DEG_TO_MDEG(1525);
            ctl->acceleration = DEG_TO_MDEG(2500);
            ctl->pid_kp = 17500;
            ctl->pid_kd = 2500;
            break;
        case PBIO_IODEV_TYPE_ID_SPIKE_S_MOTOR:
            *model = &model_technic_s_angular;
            ctl->speed_max = DEG_TO_MDEG(620);
            ctl->acceleration = DEG_TO_MDEG(2000);
            ctl->pid_kp = 7500;
            ctl->pid_kd = 1000;
            break;
        case PBIO_IODEV_TYPE_ID_TECHNIC_L_ANGULAR_MOTOR:
        case PBIO_IODEV_TYPE_ID_SPIKE_L_MOTOR:
            *model = &model_technic_l_angular;
            ctl->speed_max = DEG_TO_MDEG(970);
            ctl->acceleration = DEG_TO_MDEG(1500);
            ctl->pid_kp = 35000;
            ctl->pid_kd = 6000;
            break;
        case PBIO_IODEV_TYPE_ID_TECHNIC_M_ANGULAR_MOTOR:
        case PBIO_IODEV_TYPE_ID_SPIKE_M_MOTOR:
            *model = &model_technic_m_angular;
            ctl->speed_max = DEG_TO_MDEG(1080);
            ctl->acceleration = DEG_TO_MDEG(2000);
            ctl->pid_kp = 15000;
            ctl->pid_kd = 1800;
            break;
        #endif // PBIO_CONFIG_SERVO_PUP
        default:
            return PBIO_ERROR_NOT_SUPPORTED;
    }

    // The default speed is not used for servos currently (an explicit speed
    // is given for all run commands), so we initialize it to the maximum.
    ctl->speed_default = ctl->speed_max;

    // Deceleration defaults to same value as acceleration
    ctl->deceleration = ctl->acceleration;

    // Initialize maximum torque as the stall torque for maximum voltage.
    ctl->actuation_max = pbio_observer_voltage_to_torque(*model, pbio_dcmotor_get_max_voltage(id));

    // Initialize ki such that integral control saturates in about twos second
    // if the motor were stuck at the position tolerance.
    ctl->pid_ki = ctl->actuation_max / (ctl->position_tolerance / 1000) / 2;

    return PBIO_SUCCESS;
}

#endif // PBIO_CONFIG_SERVO
