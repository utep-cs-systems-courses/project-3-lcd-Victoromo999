
#include <msp430.h>

#include "switch.h"

#include "led.h"

#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"

#include <unistd.h>

void __interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */



  static char count = 0;

  count++;

  static char colorC = 0;

  switch (state) {
  case 1:

    buzzer_set_period(12000);

    break;

  case 2:

    newShape(COLOR_ORANGE,COLOR_PURPLE);

    count = 0;

    break;

  case 3:

    newShapeTwo(COLOR_BLUE,COLOR_GREEN);

    count = 0;

    break;

  case 4:

    newShapeThree(COLOR_RED);

    break;
  
  }
    void



      __interrupt_vec(PORT2_VECTOR) Port_2(){



      if (P2IFG & SWITCHES) {      /* did a button cause this interrupt? */



	P2IFG &= ~SWITCHES;      /* clear pending sw interrupts */



	switch_interrupt_handler();/* single handler for all switches */



      }



    }
}

