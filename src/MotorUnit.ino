
int OFF_DELAY = 3;
void MorotCycle()
{
  bool isRun = GetOutputState(DQ0);

  //on condition
  if (isRun == false && furnaceTimer >= FURNACE_CYCLE_TIME)
  {
    SetOutputOn(DQ0);

    motorOffDelay =0;
    Log("Motor turned on.");
  }
  //off condtion
  bool stepLimitSwitch = GetInputState(DI0);
  if (isRun == true && stepLimitSwitch == true && motorOffDelay >= OFF_DELAY)
  {
    furnaceTimer = 0;
    motorOffDelay = 0;
    SetOutputOff(DQ0);
    Log("Motor swiched off.");

    ++TOTAL_CYCLES;
    SaveCycleCount(TOTAL_CYCLES);
    Serial.print("Cycle Count: ");
    Serial.println(TOTAL_CYCLES);
  }

  // //timer reset
  // if (motorTimer >= MOTOR_OFF_TIME)
  // {
  //   motorTimer = 0;
  //   Log("Motor timer reset.");
  // }
}
