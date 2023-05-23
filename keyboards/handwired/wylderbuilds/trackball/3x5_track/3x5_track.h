/*
Copyright 2021 @dlford

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

#include "quantum.h"

#define XXX KC_NO

#define LAYOUT_3x5( \
    L00, L01, L02, L03, L04,            R00, R01, R02, R03, R04, \
    L10, L11, L12, L13, L14,            R10, R11, R12, R13, R14, \
    L20, L21, L22, L23, L24,            R20, R21, R22, R23, R24, \
                   L33, L34,            R30, \
                        L43, L44,       R31, \
                        L41, L42,  R40, R41 \
) { \
    { L00, L01, L02, L03, L04 }, \
    { L10, L11, L12, L13, L14 }, \
    { L20, L21, L22, L23, L24 }, \
    { XXX, XXX, XXX, L33, L34 }, \
    { XXX, L41, L42, L43, L44 }, \
    { R00, R01, R02, R03, R04 }, \
    { R10, R11, R12, R13, R14 }, \
    { R20, R21, R22, R23, R24 }, \
    { R30, R31, XXX, XXX, XXX },                                 \
    { R40, R41, XXX, XXX, XXX }, \
}
