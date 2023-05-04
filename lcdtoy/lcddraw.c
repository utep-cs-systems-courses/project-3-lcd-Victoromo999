
#include "lcdutils.h"

#include "lcddraw.h"

#include <unistd.h>

void drawPixel(u_char col, u_char row, u_int colorBGR)

{

  lcd_setArea(col, row, col, row);

  lcd_writeColor(colorBGR);

}
void fillRectangle(u_char colMin, u_char rowMin, u_char width, u_char height,

		    u_int colorBGR)

{

  u_char colLimit = colMin + width, rowLimit = rowMin + height;

  lcd_setArea(colMin, rowMin, colLimit - 1, rowLimit - 1);

  u_int total = width * height;

  u_int c = 0;

  while ((c++) < total) {

    lcd_writeColor(colorBGR);

  }

}



void newShape(u_int color,u_int color2){

  clearScreen(COLOR_BLACK);

  fillRectangle(30,30,50,55,color);

  int counter =0;int counter2 =0;

  int col1=45; int col2 =60; int row =40;

  while(counter !=20){

    drawPixel(col1,row,color2);

    drawPixel(col1+1,row,color2);

    drawPixel(col2,row,color2);

    drawPixel(col2+1,row,color2);

    counter++;row++;

  }

  int col3 =45;int row2 =70;

  while(counter2!=20){

    drawPixel(col3,row2,color2);

    drawPixel(col3,row2+1,color2);

    counter2++;col3++;

  }

  drawString8x12(20,100,"THIS",COLOR_GOLD,COLOR_PURPLE);

  drawString8x12(20,110,"A",COLOR_GREEN,COLOR_PURPLE);

  drawString8x12(20,120,"TOY",COLOR_GREEN,COLOR_PURPLE);



}



void newShapeTwo(u_int color,u_int color2){

  clearScreen(COLOR_BLACK);

  fillRectangle(30,30,50,55,color);

  int counter =0;int counter2 =0;

  int col1=50; int col2 =65; int row =45;

  while(counter !=20){

    drawPixel(col1,row,color2);

    drawPixel(col1+1,row,color2);

    drawPixel(col2,row,color2);

    drawPixel(col2+1,row,color2);

    counter++;row++;

  }
  int col3 =40;int row2 =65;

  while(counter2!=20){

    drawPixel(col3,row2,color2);

    drawPixel(col3,row2+1,color2);

    counter2++;col3++;

  }

  drawString8x12(20,100,"THIS",COLOR_GOLD,COLOR_PURPLE);

  drawString8x12(20,110, "IS A",COLOR_GOLD,COLOR_RED);

  drawString8x12(20,120,"TOY",COLOR_GOLD,COLOR_PURPLE);
}

void newShapeThree(u_int Color){
clearScreen(COLOR_BLACK);
fillRectangle(30,30, 50, 55, Color);
drawString8x12(20,20, "This is a rectangle", COLOR_GREEN, COLOR_RED);
}
void clearScreen(u_int colorBGR)

{

  u_char w = screenWidth;

  u_char h = screenHeight;

  fillRectangle(0, 0, screenWidth, screenHeight, colorBGR);

}void drawChar8x12(u_char rcol, u_char rrow, char c,

		  u_int fgColorBGR, u_int bgColorBGR)

{

  u_char col = 0;

  u_char row = 0;

  u_char bit = 0x01;

  u_char oc = c - 0x20;



  lcd_setArea(rcol, rrow, rcol + 11, rrow + 8); /* relative to requested col/row */

  while (row < 8) {

    while (col < 12) {

      u_int colorBGR = (font_8x12[oc][col] & bit) ? fgColorBGR : bgColorBGR;

      lcd_writeColor(colorBGR);

      col++;

    }

    col = 0;

    bit <<= 1;

    row++;

  }

}void drawString8x12(u_char col, u_char row, char *string,

		    u_int fgColorBGR, u_int bgColorBGR)

{

  u_char cols = col;

  while (*string) {

    drawChar8x12(cols, row, *string++, fgColorBGR, bgColorBGR);

    cols += 13;

  }

}void drawRectOutline(u_char colMin, u_char rowMin, u_char width, u_char height,

		      u_int colorBGR)

{

  /**< top & bot */

  fillRectangle(colMin, rowMin, width, 1, colorBGR);

  fillRectangle(colMin, rowMin + height, width, 1, colorBGR);



  /**< left & right */

  fillRectangle(colMin, rowMin, 1, height, colorBGR);

  fillRectangle(colMin + width, rowMin, 1, height, colorBGR);

}

