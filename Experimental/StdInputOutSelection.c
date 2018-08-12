#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define VERSION_NUMBER "2259-08102018-BETA"
#define PRODUCT_NAME "Group LM | C CLI Enrollment System for TiP Engineering and Architecture"
int main()
{
    char *ListMenu_1[3] = {"[1] Old Student", "[2] New Student", "[3] Check for Current Enrollment Status"};
    int Counter_For_List_1, Selection_1;
    while (getch()) {
    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    puts("-----------------------------");
    printf("Version " VERSION_NUMBER "\n");
    printf(PRODUCT_NAME "\n");
    puts("-----------------------------");
    puts("Main Menu");
    for (Counter_For_List_1 = 0; Counter_For_List_1 < 3; Counter_For_List_1++)
    {
        printf(ListMenu_1[Counter_For_List_1]);
    }
    printf("Please enter your decision [1 - 3] | ");
    Selection_1 = getch(); // Get The Input without having to use enter
    switch (Selection_1)
    {
    case 1:
        printf("OldStd_Func();");
        break;
    case 2:
        printf("NewStd_Func();");
        break;
    case 3:
        printf("NewStd_ContinuationFunc();");
        break;
    default:
        printf("Invalid Selection");
        return;
    }
    getch();
    return Selection_1;
}