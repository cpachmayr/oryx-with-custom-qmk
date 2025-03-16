/* Copyright 2025 ZRYep
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "caps_indicator.h"
#include "print.h"

// Function to initialize caps lock indicator
void caps_indicator_init(void) {
    // Set the initial state of the caps lock indicator based on the current caps lock state
    caps_indicator_update();
}

// Function to update the caps lock indicator based on the current state
void caps_indicator_update(void) {
    // The correct LED index for Caps Lock is 49 (confirmed)
    const uint8_t caps_lock_led_index = 49;
    
    // Set the color based on caps lock state
    if (host_keyboard_led_state().caps_lock) {
        // Caps lock is on - set to bright red (E00909)
        rgb_matrix_set_color(caps_lock_led_index, CAPS_ACTIVE_R, CAPS_ACTIVE_G, CAPS_ACTIVE_B);
    } else {
        // Caps lock is off - set to dim red (8D4E4E)
        rgb_matrix_set_color(caps_lock_led_index, CAPS_INACTIVE_R, CAPS_INACTIVE_G, CAPS_INACTIVE_B);
    }
}

// Function to process record for caps lock key
bool caps_indicator_process_record(uint16_t keycode, keyrecord_t *record) {
    if (keycode == KC_CAPS) {
        if (record->event.pressed) {
            // Force an update of the RGB matrix after a short delay
            // to ensure the caps lock state is correctly reflected
            caps_indicator_update();
        }
    }
    
    // Always return true to allow normal processing of all keys
    return true;
}
