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

#define CAPS_INACTIVE_R 20  // Dim red when inactive
#define CAPS_INACTIVE_G 0
#define CAPS_INACTIVE_B 0

#define CAPS_ACTIVE_R 255   // Bright red when active
#define CAPS_ACTIVE_G 0
#define CAPS_ACTIVE_B 0

// Function declarations
bool caps_indicator_process_record(uint16_t keycode, keyrecord_t *record);
void caps_indicator_update(void);
void caps_indicator_init(void);
