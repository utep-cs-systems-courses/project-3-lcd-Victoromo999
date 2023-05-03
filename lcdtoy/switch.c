#include <msp430.h>

#include "switch.h"

char state=0;

static char switch_update_interrupt_sense()

{

  P2IES |= (P2IN & SWITCHES);

  P2IES &= (P2IN | ~SWITCHES);

  return P2IN;

}

void switchInit()

{

  P2REN |= SWITCHES;

  P2IE |= SWITCHES;

  P2OUT |= SWITCHES;

  P2DIR &= ~SWITCHES;



  switch_update_interrupt_sense();

}

void switch_interrupt_handler(){

  char p2val = switch_update_interrupt_sense();

  if (~p2val & SW1) {
    state = 1;
}
  else if (~p2val & SW2) {
    state = 2;
  }
  else if (~p2val & SW3) {
    state = 3;
  }
  else if (~p2val & SW4) {
    state = 4;
  }
  else {
    state =0;
  }

}

