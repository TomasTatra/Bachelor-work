// SPDX-License-Identifier: MIT
// Copyright (c) 2022 The Pybricks Authors

#include <pbsys/config.h>

#if PBSYS_CONFIG_MAIN

#include <stdint.h>
#include <string.h>

#include <pbdrv/reset.h>
#include <pbdrv/usb.h>
#include <pbdrv/bluetooth.h>

#include <pbio/main.h>

#include <pbsys/core.h>
#include <pbsys/main.h>
#include <pbsys/status.h>
#include <pbsys/program_stop.h>
#include <pbsys/bluetooth.h>

#include "program_load.h"
#include "program_stop.h"

#include "automata/automata.h"


void HAL_Delay(uint32_t delay);
bool pbdrv_bluetooth_is_connected(pbdrv_bluetooth_connection_t connection);


/**
 * Initializes the PBIO library, runs custom main program, and handles shutdown.
 *
 * @param [in]  main    The main program.
 */
int main(int argc, char **argv) {

    pbio_init();
    pbsys_init();

    // Keep loading and running user programs until shutdown is requested.
    while (!pbsys_status_test(PBIO_PYBRICKS_STATUS_SHUTDOWN_REQUEST)) {

        // Receive a program. This cancels itself on shutdown.
        static pbsys_main_program_t program;
        pbio_error_t err = pbsys_program_load_wait_command(&program);
        if (err != PBIO_SUCCESS) {
            continue;
        }

        // Prepare pbsys for running the program.
        pbsys_status_set(PBIO_PYBRICKS_STATUS_USER_PROGRAM_RUNNING);
        pbsys_bluetooth_rx_set_callback(pbsys_main_stdin_event);
        /* important for later

        // Handle pending events triggered by the status change, such as
        // starting status light animation.
        while (pbio_do_one_event()) {
        }

        // Run the main application.
        pbsys_main_run_program(&program);

        */

        if (pbdrv_bluetooth_is_connected(PBDRV_BLUETOOTH_CONNECTION_PYBRICKS)) {
            start_automata();
        }

        pbio_do_one_event();

        // Get system back in idle state.
        pbsys_status_clear(PBIO_PYBRICKS_STATUS_USER_PROGRAM_RUNNING);
        pbsys_bluetooth_rx_set_callback(NULL);
        pbsys_program_stop_set_buttons(PBIO_BUTTON_CENTER);
        pbio_stop_all(true);
    }

    // Stop system processes and save user data before we shutdown.
    pbsys_deinit();

    // Now lower-level processes may shutdown and/or power off.
    pbsys_status_set(PBIO_PYBRICKS_STATUS_SHUTDOWN);

    // The power could be held on due to someone pressing the center button
    // or USB being plugged in, so we have this loop to keep pumping events
    // to turn off most of the peripherals and keep the battery charger running.
    for (;;) {
        // We must handle all pending events before turning the power off the
        // first time, otherwise the city hub turns itself back on sometimes.
        while (pbio_do_one_event()) {
        }

        #if PBSYS_CONFIG_BATTERY_CHARGER
        // On hubs with USB battery chargers, we can't turn off power while
        // USB is connected, otherwise it disables the op-amp that provides
        // the battery voltage to the ADC.
        if (pbdrv_usb_get_bcd() != PBDRV_USB_BCD_NONE) {
            continue;
        }
        #endif

        pbdrv_reset_power_off();
    }
}

#endif // PBSYS_CONFIG_MAIN
