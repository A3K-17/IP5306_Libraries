/////////////////////////////////////////////////////////////////
/*
MIT License

Copyright (c) 2019 lewis he

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

ip5306.cpp - Arduino library for  IP5306 chip.
Created by Lewis he on May 15, 2019.
github:https://github.com/lewisxhe/IP5306_Libraries
*/
/////////////////////////////////////////////////////////////////

#include "ip5306.h"


int IP5306_Class::begin(TwoWire &port, uint8_t addr)
{
    _i2cPort = &port;   //Grab which port the user wants us to use
    _address = addr;
}
int IP5306_Class::setBoostEnable(bool en) {}
int IP5306_Class::setChargerEnable(bool en) {}
int IP5306_Class::setPlugLoadOpened(bool en) {}
int IP5306_Class::setBoostNormallyOpen(bool en) {}
int IP5306_Class::setButtonPowerOffEnable(bool en) {}
int IP5306_Class::setShutdownOption(uint8_t arg) {}
int IP5306_Class::setLedControl(uint8_t arg) {}
int IP5306_Class::setShortPressBoost(bool en) {}
int IP5306_Class::setVinRemoveBoostOn(bool en) {}
int IP5306_Class::setLowBatteryShutdown(bool en) {}
int IP5306_Class::setLightLoadShutdownTime(uint8_t arg) {}
int IP5306_Class::setChargerFullVoltage(uint8_t arg) {}
int IP5306_Class::setBatteryStopChargerCurrent(uint8_t arg) {}
int IP5306_Class::setChargerVoltage(uint8_t arg) {}
int IP5306_Class::setBatteryVoltage(uint8_t arg) {}
int IP5306_Class::setConstantPressureCharging(uint8_t arg) {}
int IP5306_Class::setChargerLoopSeletc(uint8_t arg) {}
int IP5306_Class::setChargerCurrent(uint8_t arg) {}
bool IP5306_Class:: isChargerEnable() {}
bool IP5306_Class:: isChargerFull() {}
bool IP5306_Class:: isHeavyLoad() {}
bool IP5306_Class:: isButtonDouble() {}
bool IP5306_Class:: isButtonLongPress() {}
bool IP5306_Class:: isButtonShortPress() {}