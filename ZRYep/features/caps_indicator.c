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

// Function to initialize caps lock indicator
void caps_indicator_init(void) {
    // Set the initial state of the caps lock indicator based on the current caps lock state
    caps_indicator_update();
}

// Function to update the caps lock indicator based on the current state
void caps_indicator_update(void) {
    // Calculate the LED matrix ID for the caps lock key
    // The caps lock key is at position 49 in the LED matrix based on its position in the layout
    // (bottom row, rightmost key of the main keys, not counting thumb keys)
    uint8_t led_id = 49; // Correct position for the Voyager's KC_CAPS LED
    
    // Check if caps lock is on
    if (host_keyboard_led_state().caps_lock) {
        // Caps lock is on - set to bright red
        rgb_matrix_set_color(led_id, CAPS_ACTIVE_R, CAPS_ACTIVE_G, CAPS_ACTIVE_B);
    } else {
        // Caps lock is off - set to dim red
        rgb_matrix_set_color(led_id, CAPS_INACTIVE_R, CAPS_INACTIVE_G, CAPS_INACTIVE_B);
    }
}

// Function to process record for caps lock key
bool caps_indicator_process_record(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_CAPS: {
            // We need to return true to allow the regular processing to happen
            // which will toggle the caps lock state, then our RGB matrix callback will
            // handle the LED update after the state has changed
            return true;
        }
    }
    
    // For all other keys, let the process continue normally
    return true;
}
