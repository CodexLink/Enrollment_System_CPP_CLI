/*==============================================================================
Group LM - Enrollment System in C for Preliminary Project in Programming
Enrollment System
Version 1856-08102018 - BETA
==============================================================================
Peoples who worked on this project.
Project Leader / FrontEnd Design / Backend Programmer - Janrey Licas
Project Manager / Backend Programmer - Charles Ian Mascarenas
Code Tester / ???? - Sim Harvey Agustin Marquez
Julie Ann Luzano
Matt Matamis 
==============================================================================*/
#include <stdio.h>    // Just Basic Input Output Header File
#include <stdlib.h>   // For SYSTEM Command
#include <conio.h>    // For Getch()
#include <windows.h>  // Windows Designed Only Header, This Rips Compatibility.
//#include <winsock2.h> // Added For Communications between a potential server and a client
#include <time.h>     // For Time Display and Such
// defined marcros to avoid typing these words again.
//Calling those will result into the following strings
#define VERSION_NUMBER "2259-08102018-BETA"
#define PRODUCT_NAME "Group LM | C CLI Enrollment System for TiP Engineering and Architecture"
#define ERROR_1 "WARN.UnableReposition"
#define ERROR_2 "WARN.Win32Disable_Denied"
#define WARN_1 "ERROR.UnableToConnect"
#define WARN_2 "ERROR.UnableToCheckStorage"
#define ACMPLT "Critical Components Checkpoint Completed"

// Include Expected Header Such as ICMP for Communication in Windows
int OldStd_Logon();
char stdnt_NumberCreate();
char CriticalComp_Check(); //Checks and Sets Components Before Initializing
void OldStd_Func();                              //Function for Old Student
void NewStd_Func();                              // Function for New Student
void OldStd_Func_Enrollment();
// INCLUDE ALL FUNCTION PROTOTYPE HERE, BECAUSE FUNCTIONS DONE WITH BODY IS
//GOING TO BE PLACE BELOW FROM INT MAIN FUNCTION
int main(int argc, char *argv[])
{
    // Check for Critical Components for Compatibility
    int Selection_1, Counter_For_List_1, Err_CodeValue;
    char ReturnCodeChar, PostReturn;
    char *ListMenu_1[3] = {"[1] Old Student", "[2] New Student", "[3] Check for Current Enrollment Status"};
    system("CLS"); // A bit of a impractical. Looking forward to clrscr
    puts("------------------------");
    printf("Version " VERSION_NUMBER "\n");
    printf(PRODUCT_NAME "\n");
    // Init Function to Check for Critical Components Before Proceeding
    PostReturn = CriticalComp_Check();
    if (PostReturn == ERROR_1 || ERROR_2)
    {
    }
    else if (PostReturn == WARN_1 || WARN_2)
    {
        printf("Few Critical Components where unable to compile. Although it's an optional critical component, Proceeding...");
        Sleep(2500); // Wait Before Continue, Time In milliseconds
    }
    else
    {
        system("CLS");
        printf("One or more critical components has failed to comply. Exiting. Exit Code is %d", PostReturn);
        Err_CodeValue = GetLastError(); // A Function Defined in Windows.H to show what error that would be. (Win32API)
        return Err_CodeValue;
    }
    puts("------------------------");
    puts("Main Menu");
    for (Counter_For_List_1 = 0; Counter_For_List_1 < 3; Counter_For_List_1++)
    { // I CANT DEPLOY A DATA TYPE ON THE GO INSIDE FOR COMMAND, BECAUSE OF MODE.
        printf(ListMenu_1[Counter_For_List_1]);
    }
    printf("Please enter your decision [1 - 2] | ");
    scanf("%i", &Selection_1);
    switch (Selection_1)
    {
    case 1:
        OldStd_Func();
    case 2:
        NewStd_Func();
    }
    puts("Outside Function Detected. Exiting");
    getch();
    return 0;
}

void OldStd_Func()
{
    int user_StudentIdentity[7];
    char user_Username, user_Password;
    SetConsoleTitle("LM Enrollment System | Old Student Login");
    printf("Please enter your Username: ");
    scanf("%c", &user_Username);
    printf("Please enter your Password: ");
    scanf("%c", &user_Password);
    printf("Please enter your Student Number: ");
    scanf("%i", &user_StudentIdentity);
    //if (insert database here) = TRUE then
    printf("Hello and Welcome %c %i !", user_Username, user_StudentIdentity);
    printf("Loading...");
    //OldStd_Func_Enrollment(); else OldStd_Func. No Limit Attempts.
}
void OldStd_Func_Enrollment()
{
}
void NewStd_Func()
{
    SetConsoleTitle("LM Enrollment System | New Student Creation");
}
char stdnt_NumberCreate()
{ // NO Inside Data Type Variable to be Received
    SetConsoleTitle("LM Enrollment System | Creating a Number");
    SYSTEMTIME Btch_Year;
    char Created_Student_NumData;
    GetLocalTime(&Btch_Year); // Win32 Module Function
    // Get Current Batch and Student Number
    printf("Created Student Number Data(Untouched) %d | ", Btch_Year.wYear); // Another Two Predicted Values are Btch_Num, Btch_StudentNum.
    return Created_Student_NumData;
}

char CriticalComp_Check()
{
    char ModeArgumentSet = 0, ReturnCodeChar = 0;
    SetConsoleTitle("Intializing and Checking Critical Components | LM Enrollment System\n");
    printf("Initializing and Checking Critical Components Before Actual Program Initialization\n");
    printf("COMPONENT #   | TITLE\tSTATUS\n");
    printf("Init.Component # 1 | Resizing Command Line with Respective Ordered Values\n");
    HWND console = 0;
    RECT ConsoleMainApp;
    MoveWindow(console, ConsoleMainApp.left, ConsoleMainApp.top, 1000, 500, TRUE);
    printf("Init.Component # 2 | Disabling Close Button\n");
    HWND hwnd = GetConsoleWindow();             // Literal Meaning on Function
    HMENU hmenu = GetSystemMenu(hwnd, FALSE);   // Get System Window Like Literally
    EnableMenuItem(hmenu, SC_CLOSE, MF_GRAYED); // EnableMenuItem is almost like ModifyMenuItem On TitleBar. (Handler, Property#1, Property#2)
    printf("Component # 3 | Contacting Server for Live R/W\n");
    //Create If and Else for this
    printf("Component # 4 | Checking Local Data on Local Storage (Using WinSock)\n");
    // Create if and else here again.
    printf("Component # 5 | Checking Registry for App Integration @ Startup\n");

    //printf("Initializing Mode | %c", ModeArgumentSet);
    if ((strstr(ERROR_1, ReturnCodeChar)) || (strstr(ERROR_2, ReturnCodeChar)) || (strstr(WARN_1, ReturnCodeChar)) || (strstr(WARN_2, ReturnCodeChar))) == TRUE)
    {
        ReturnCodeChar = "ACMPLT";
		printf("%s", ReturnCodeChar);
		Sleep(3000);
    }
    return ReturnCodeChar;
}
