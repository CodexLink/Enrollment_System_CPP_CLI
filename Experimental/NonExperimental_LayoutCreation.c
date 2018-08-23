#include <stdio.h>
#include <conio.h>
#include <windows.h>

void gotoxy(int x, int y);

    int main()
{
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SHOW_FULLSCREEN);
    gotoxy(25, 2);
    printf("INPUT");
    gotoxy(25, 3);
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    //PRINT OUTSIDE
    gotoxy(25, 6);
    printf("PROPERTIES");
    gotoxy(25, 8);
    printf("Press 10 To Encode All\tPress Any Subject Number Order To Encode\tEnter 'X or x' to proceed.");
    getch();
    return EXIT_SUCCESS;
}

void gotoxy(int x, int y)
{
    COORD ConsoleXY = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ConsoleXY);
}