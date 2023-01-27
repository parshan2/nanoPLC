bool _dq0_prev_state = true;

void Lifter()
{

  bool motorIsRun = GetOutputState(DQ0);
  if (motorIsRun != _dq0_prev_state)
  {
    if (motorIsRun == false)
    {
      SetOutputOn(DQ1);
      Log("Lifter on.");
    }
    _dq0_prev_state = motorIsRun;
  }

  bool lifterIsOn = GetOutputState(DQ1);
  bool lifterLimit = GetInputState(DI1);
  if ((lifterIsOn && lifterLimit) || (lifterTimoutCounter >= LIFTER_LIMIT_TIMEOUT))
  {
    SetOutputOff(DQ1);
    lifterTimoutCounter = 0;
    Log("Lifter off.");
  }

  if (lifterIsOn && SEC_TRIGED && !lifterLimit)
  {
    ++lifterTimoutCounter;
  }

  // if (lifterTimoutCounter >= LIFTER_LIMIT_TIMEOUT)
  // {
  //   Log("Error.");
  //   FAULT = true;
  // }
}
