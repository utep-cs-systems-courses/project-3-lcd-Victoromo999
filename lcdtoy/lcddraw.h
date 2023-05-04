#ifndef lcddraw_included
#define lcddraw_included

void drawPixel(u_char col, u_char row, u_int colorBGR);



void newShape(u_int color,u_int color2);

void newShapeTwo(u_int color,u_int color2);
void newShapeThree(u_int color);
void fillRectangle(u_char colMin, u_char rowMin, u_char width, u_char height, u_int colorBGR);
void clearScreen(u_int colorBGR);
void drawString8x12(u_char col, u_char row, char *string,

		   u_int fgColorBGR, u_int bgColorBGR);
void drawChar8x12(u_char col, u_char row, char c,

		 u_int fgColorBGR, u_int bgColorBGR);
void drawRectOutline(u_char colMin, u_char rowMin, u_char width, u_char height,

		     u_int colorBGR);

#endif // included
