//settings
int FURNACE_CYCLE_TIME = 45;
int LIFTER_LIMIT_TIMEOUT = 15; //(second) default=15

//global variables
bool DEBUG_MODE = true;
bool SEC_TRIGED = false;
long TOTAL_CYCLES = 0;
bool FAULT = false;

//addresses
int TLED = 2;
int RXLED = 17; // The RX LED has a defined Arduino pin
int RUNPIN = A0;
int DQ0 = 7;
int DQ1 = 8;
int DQ2 = 9;
int DI0 = 14;
int DI1 = 16;
int DI2 = 10;

//local variables
//int motorTimer = 0;
int furnaceTimer = 0;
int motorOffDelay = 0;
int lifterTimoutCounter = 0;

void setup()
{
  //initial pins
  SetupPins();

  //initial serial ports
  SetupSerialPorts();

  delay(2000);
  Print("====================================");
  Print("Arsina nanoPLC V0.01");
  Print("by Arsia Automation");
  Print("====================================");
  delay(2000);
  //initial timers
  SetupTimers();

  //load settings from Eeprom
  LoadSettings();

  ShowCurrentSettings();
  ShowHelp();
}

int incomingByte = 0; // for incoming serial data
void loop()
{

  //motor unit control
  MorotCycle();
  //lifter unit control
  Lifter();

  //second events
  if (SEC_TRIGED)
  {
    SEC_TRIGED = false;
    ++furnaceTimer;
    ++motorOffDelay;

    //Log("Sec Triged.");
  }
  //execute serial commans
  ExcuteCommand();
}
