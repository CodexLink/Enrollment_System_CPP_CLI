// Works in turbo c compiler only
#include <stdio.h>
#include <conio.h>
#include <windows.h>
 
void gotoxy (int x,int y);

int main()
{
	
   int x, y;
 
   x = 10;
   y = 10;
 
   gotoxy(x, y);
 
   printf("C program to change cursor position.");
 
   getch();
   return 0;
}
 void gotoxy(int x, int y) 
{ 
    COORD coord;
    coord.X = x; 
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
