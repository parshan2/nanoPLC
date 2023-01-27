
void SetupPins()
{
  pinMode(RUNPIN, OUTPUT); // Set RUNLEDPIN LED as an output
  pinMode(TLED, OUTPUT);
  pinMode(RXLED, OUTPUT); // Set RX LED as an output

  pinMode(DQ0, OUTPUT); // Set DO0 LED as an output
  pinMode(DQ1, OUTPUT); // Set DO1 LED as an output
  pinMode(DQ2, OUTPUT); // Set DO2 LED as an output

  pinMode(DI0, INPUT_PULLUP); // Set DI0 LED as an input
  pinMode(DI1, INPUT_PULLUP); // Set DI1 LED as an input
  pinMode(DI2, INPUT_PULLUP); // Set DI2 LED as an input
}

void takeReading()
{
  digitalWrite(RUNPIN, digitalRead(RUNPIN) ^ 1);
}

void SetOutputOn(int pin)
{
  digitalWrite(pin, 1);
}
void SetOutputOff(int pin)
{
  digitalWrite(pin, 0);
}

bool GetOutputState(int pin)
{
  int value = digitalRead(pin);

  if (value == 0)
    return false;

  return true;
}

bool GetInputState(int pin)
{
  int value = digitalRead(pin);

  if (value == 1)
    return false;

  return true;
}
