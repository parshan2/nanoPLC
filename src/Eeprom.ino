#include <EEPROM.h>

void LoadSettings()
{
  //MOTOR_RUN_TIME = ReadMotorRunTime();
  FURNACE_CYCLE_TIME = ReadFurnaceCycleTime();
  LIFTER_LIMIT_TIMEOUT = ReadLifterTimeout();
  TOTAL_CYCLES = ReadCycleCount();

  if (TOTAL_CYCLES > 5000000)
  {
    TOTAL_CYCLES = 0;
    Serial.println("Cycle counter auto reset.");
    SaveCycleCount(TOTAL_CYCLES);
  }
}

long ReadCycleCount()
{
  return readLongFromEEPROM(100);
}

void SaveCycleCount(long value)
{
  writeLongIntoEEPROM(100, value);
}

// int ReadMotorRunTime()
// {
//   return readIntFromEEPROM(0);
// }
// void SaveMotorRuntime(int value)
// {
//   writeIntIntoEEPROM(0, value);
// }

int ReadFurnaceCycleTime()
{
  return readIntFromEEPROM(10);
}

void SaveFurnaceCycleTime(int value)
{
  writeIntIntoEEPROM(10, value);
}

int ReadLifterTimeout()
{
  return readIntFromEEPROM(20);
}
void SaveLifterTimeout(int value)
{
  writeIntIntoEEPROM(20, value);
}

void writeLongIntoEEPROM(int address, long number)
{
  EEPROM.write(address, (number >> 24) & 0xFF);
  EEPROM.write(address + 1, (number >> 16) & 0xFF);
  EEPROM.write(address + 2, (number >> 8) & 0xFF);
  EEPROM.write(address + 3, number & 0xFF);
}
long readLongFromEEPROM(int address)
{
  return ((long)EEPROM.read(address) << 24) +
         ((long)EEPROM.read(address + 1) << 16) +
         ((long)EEPROM.read(address + 2) << 8) +
         (long)EEPROM.read(address + 3);
}

void writeIntIntoEEPROM(int address, int number)
{
  EEPROM.write(address, number >> 8);
  EEPROM.write(address + 1, number & 0xFF);
}

int readIntFromEEPROM(int address)
{
  return (EEPROM.read(address) << 8) + EEPROM.read(address + 1);
}