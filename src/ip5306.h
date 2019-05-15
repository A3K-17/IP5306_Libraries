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

ip5306.h - Arduino library for IP5306 chip.
Created by Lewis he on May 15, 2019.
github:https://github.com/lewisxhe/IP5306_Libraries
*/
/////////////////////////////////////////////////////////////////
#pragma once

#include <Arduino.h>
#include <Wire.h>

// #define IP5306_DEBUG_PORT  Serial
#ifdef IP5306_DEBUG_PORT
#define IP5306_DEBUG(fmt, ...)                 AXP_DEBUG_PORT.printf_P( (PGM_P)PSTR(fmt), ## __VA_ARGS__ )
#else
#define IP5306_DEBUG(...)
#endif

//! Error Code
#define IP5306_PASS                      0
#define IP5306_FAIL                     -1
#define IP5306_INVALID                  -2
#define IP5306_NOT_INIT                 -3

//! Chip Address
#define IP5306_SLAVE_ADDRESS            (0x75)

#define IP5306_SYS_CTRL0                0x00
#define IP5306_SYS_CTRL1                0x01
#define IP5306_SYS_CTRL2                0x02
#define IP5306_CHARGER_CTRL0            0x20
#define IP5306_CHARGER_CTRL1            0x21
#define IP5306_CHARGER_CTRL3            0x22
#define IP5306_CHARGER_CTRL4            0x23
#define IP5306_DIG_CTRL0                0x24
#define IP5306_CHARGER_STATUS0          0x70
#define IP5306_CHARGER_STATUS1          0x71
#define IP5306_CHARGER_STATUS2          0x72
#define IP5306_KEY_CTRL                 0x77

class IP5306_Class
{
public:
    int begin(TwoWire &port = Wire, uint8_t addr = IP5306_SLAVE_ADDRESS);
    int setBoostEnable(bool en);
    int setChargerEnable(bool en);
    int setPlugLoadOpened(bool en);
    int setBoostNormallyOpen(bool en);
    int setButtonPowerOffEnable(bool en);
    
    int setShutdownOption(uint8_t arg);
    int setLedControl(uint8_t arg);
    int setShortPressBoost(bool en);
    int setVinRemoveBoostOn(bool en);
    int setLowBatteryShutdown(bool en);

    int setLightLoadShutdownTime(uint8_t arg);

    int setChargerFullVoltage(uint8_t arg);

    int setBatteryStopChargerCurrent(uint8_t arg);
    int setChargerVoltage(uint8_t arg);

    int setBatteryVoltage(uint8_t arg);
    int setConstantPressureCharging(uint8_t arg);


    int setChargerLoopSeletc(uint8_t arg);

    int setChargerCurrent(uint8_t arg);

    bool isChargerEnable();

    bool isChargerFull();

    bool isHeavyLoad();

    bool isButtonDouble();
    bool isButtonLongPress();
    bool isButtonShortPress();


private:
    int _readByte(uint8_t reg, uint8_t nbytes, uint8_t *data)
    {
        _i2cPort->beginTransmission(_address);
        _i2cPort->write(reg);
        _i2cPort->endTransmission();
        _i2cPort->requestFrom(_address, nbytes);
        uint8_t index = 0;
        while (_i2cPort->available())
            data[index++] = _i2cPort->read();
    }

    int _writeByte(uint8_t reg, uint8_t nbytes, uint8_t *data)
    {
        _i2cPort->beginTransmission(_address);
        _i2cPort->write(reg);
        for (uint8_t i = 0; i < nbytes; i++) {
            _i2cPort->write(data[i]);
        }
        _i2cPort->endTransmission();
    }

    uint8_t _address;
    bool _init = false;
    TwoWire *_i2cPort;
};
