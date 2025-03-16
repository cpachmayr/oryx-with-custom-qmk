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

#pragma once

#include "quantum.h"

// RGB values for caps lock indicator
#define CAPS_LOCK_KEY_ROW 3 // The row where caps lock key is located
#define CAPS_LOCK_KEY_COL 5 // The column where caps lock key is located

// Caps Lock inactive: #8D4E4E (dark red)
#define CAPS_INACTIVE_R 141  // 0x8D
#define CAPS_INACTIVE_G 78   // 0x4E
#define CAPS_INACTIVE_B 78   // 0x4E

// Caps Lock active: #E00909 (bright red)
#define CAPS_ACTIVE_R 224   // 0xE0
#define CAPS_ACTIVE_G 9     // 0x09
#define CAPS_ACTIVE_B 9     // 0x09

// Function declarations
bool caps_indicator_process_record(uint16_t keycode, keyrecord_t *record);
void caps_indicator_update(void);
void caps_indicator_init(void);
