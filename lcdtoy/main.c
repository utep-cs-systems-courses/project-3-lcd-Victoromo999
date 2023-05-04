
#include <msp430.h>

#include "libTimer.h"

#include "led.h"

#include "buzzer.h"

#include "switch.h"

#include "lcdutils.h"

#include "lcddraw.h"







int main(void) {



  switchInit();

  


  configureClocks();/* setup master oscillator, CPU & peripheral clocks */

  lcd_init();

  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_RED);

  drawString8x12(20,50,"HELLO THERE!",COLOR_ORANGE,COLOR_BLUE);

  drawString8x12(20,60,"PICK A STATE",COLOR_BLUE,COLOR_ORANGE);

  enableWDTInterrupts();/* enable periodic interrupt */

  or_sr(0x18);/* CPU off, GIE on */



}
