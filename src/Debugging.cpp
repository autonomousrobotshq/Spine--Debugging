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

#include <Arduino.h>
#include "Debugging.hpp"

#ifndef ARDUINO_CI
# include <MemoryFree.h>
#endif

namespace DBG {

static unsigned long g_timer;

void TimerSet()
{
    g_timer = millis();
}

unsigned long TimerGetMillis()
{
    return (millis() - g_timer);
}

uint16_t TimerGetSeconds()
{
    return ((millis() - g_timer) / 1000);
}

void TimerPrintMillis()
{
    Serial.print("Time elapsed : ");
    Serial.print(millis() - g_timer);
    Serial.println(" milliseconds");
}

void TimerPrintSeconds()
{
    Serial.print("Time elapsed : ");
    Serial.print((millis() - g_timer) / 1000);
    Serial.println(" seconds");
}

#ifndef ARDUINO_CI
int16_t FreeRamLeft()
{
    return (freeMemory());
}

void PrintFreeRamLeft()
{
    Serial.print("Free RAM left : ");
    Serial.println(freeMemory());
}
#endif

void assert(bool condition, const String &call, int linenumber)
{
	if (!condition)
	{
		Serial.print("Assertion failed: ");
		Serial.print(call);
		Serial.print(" on line: ");
		Serial.println(linenumber);
		while(true) {};
	}
}

} // namespace DBG
