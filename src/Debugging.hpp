//
// Spine - Spine - MCU code for robotics.
// Copyright (C) 2019-2021 Codam Robotics
//
// This file is part of Spine.
//
// Spine is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Spine is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Spine.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef DEBUGGING_HPP
#define DEBUGGING_HPP

#include <stdint.h>

namespace DBG {

void TimerSet();
unsigned long TimerGetMillis();
uint16_t TimerGetSeconds();

void TimerPrintMillis();
void TimerPrintSeconds();

#ifndef ARDUINO_CI
int16_t FreeRamLeft();
void PrintFreeRamLeft();
#endif

void assert(bool condition, const String &call, int linenumber);

} // namespace DBG

#endif
