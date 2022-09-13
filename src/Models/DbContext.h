#ifndef DBCONTEXT_H
#define DBCONTEXT_H

#include <DbSetEEPROM.h>
#include <Arduino.h>
#include <TimeLib.h>
class DbContext {
    public:
        // Runtime Registers (Non-volatile memory)
        byte deviceId;
        uint16_t plan;
        uint16_t actual;
        bool isOnProgramming;
        bool aRebootIsNeeded;
        time_t startTime;
        // EEPROM Registers (Volatile memory)
        DbSetEEPROM<byte> deviceIdEEPROM = DbSetEEPROM<byte>(1);
        DbSetEEPROM<uint16_t> planEEPROM = DbSetEEPROM<uint16_t>(1,deviceIdEEPROM.lastPosition());
        DbSetEEPROM<uint16_t> actualEEPROM = DbSetEEPROM<uint16_t>(1,planEEPROM.lastPosition());
};

#endif