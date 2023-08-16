/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define USE_SERIAL

#undef TAPPING_TERM
#define TAPPING_TERM 250

#define MASTER_RIGHT
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT


#undef MATRIX_ROW_PINS
#define MATRIX_ROW_PINS { B7, D5, C7, F1, F0, B6 }

//#define PMW3360_CS_PIN F7
#define PMW3360_CPI 3500
#define POINTING_DEVICE_CS_PIN F7
#define POINTING_DEVICE_INVERT_X

#define TAPPING_TERM_PER_KEY
//#define RETRO_TAPPING
//#define PERMISSIVE_HOLD
//#define MASTER_RIGHT
//#define EE_HANDS
// Rows are doubled-up
