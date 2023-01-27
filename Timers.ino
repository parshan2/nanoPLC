
void SetupTimers()
{
  noInterrupts();
  // Clear registers
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;

  //https://www.arduinoslovakia.eu/application/timer-calculator
  OCR1A = 31249;                       // 8 Hz (16000000/((31249+1)*64))
  TCCR1B |= (1 << WGM12);              // CTC
  TCCR1B |= (1 << CS11) | (1 << CS10); // Prescaler 64
  TIMSK1 |= (1 << OCIE1A);             // Output Compare Match A Interrupt Enable
  interrupts();
}

int _TIMER_COUNTER = 0;
ISR(TIMER1_COMPA_vect)
{

  if (FAULT)
  {
    digitalWrite(RUNPIN, 1);
  }
  else
  {
    digitalWrite(RXLED, digitalRead(RXLED) ^ 1); //Turns LED ON and OFF
    digitalWrite(TLED, digitalRead(TLED) ^ 1);
    digitalWrite(RUNPIN, digitalRead(RUNPIN) ^ 1);
  }

  ++_TIMER_COUNTER;
  if (_TIMER_COUNTER == 8)
  {
    _TIMER_COUNTER = 0;
    SEC_TRIGED = true;
  }
}
