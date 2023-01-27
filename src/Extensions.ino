#include <avr/wdt.h>

void software_Reset() // Restarts program from beginning but does not reset the peripherals and registers
{
  wdt_disable();
  wdt_enable(WDTO_15MS);
  while (1)
  {
  }
}