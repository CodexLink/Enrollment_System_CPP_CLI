/*==============================================================================
Group LM - Enrollment System in C for Preliminary Project in Programming
Enrollment System, Version 1856-08102018 - BETA
==============================================================================
Project Leader / FrontEnd Design / Backend Programmer - Janrey Licas, Project Manager / Backend Programmer - Charles Ian Mascarenas
Code Tester / ???? - Sim Harvey Agustin Marquez, Julie Ann Luzano, Matt Matamis
==============================================================================*/
#include <stdio.h>   // Just Basic Input Output Header File
#include <stdlib.h>  // For SYSTEM Command
#include <conio.h>   // For Getch()
#include <windows.h> // Windows Designed Only Header, This Rips Compatibility.
#include <time.h> // For Time Display and Such
#include <string.h> // String Handling for Usage of Structure and Database
#define VERSION_NUMBER "2259-08102018-BETA"
#define PRODUCT_NAME "Group LM | C CLI Enrollment System for TiP Engineering and Architecture"
#define ERROR_1 "WARN.UnableReposition"
#define ERROR_2 "WARN.Win32Disable_Denied"
#define WARN_1 "ERROR.UnableToConnect"
#define WARN_2 "ERROR.UnableToCheckStorage"
#define ACMPLT "Critical Components Checkpoint Completed"
#define FUNCTION_UNFINISHED 1362565
#define DATABASE_NOT_FOUND 40
struct StudentRecords {
    int user_StudentIdentity[7];
    char user_Username, user_Password, user_UserPersonalName;

};
struct New_StudentRecords {
    char user_Name;
    char user_Birthday;
    char user_MName, user_FName, user_Nationality;
};
int OldStd_Logon();
char stdnt_NumberCreate(); // Function that creates a number
char CriticalComp_Check(); // Checks and Sets Components Before Initializing
char Argument_Initialization(argc, argv); // PASS ARGC AND ARGV To Another Function
void OldStd_Func();        // Function for Old Student
void NewStd_Func();        // Function for New Student
void NewStd_ContinuationFunc();
void PrintTranscript(); // New Function
void OldStd_Func_Enrollment_Eng(OldStudent);

int main(int argc, char *argv[]) {
    int Counter_Argument;
    char ArgumentModeReturn;
    printf("Checking for Arguments Given...");
    printf("Argument/s Count is %c", argc);
    for (Counter_Argument = 0; Counter_Argument < argc; Counter_Argument++)
    {
        printf(argv[Counter_Argument]);
        printf("\n");
    }
    if (argc < 0) {
        ArgumentModeReturn = Argument_Initialization(argc, argv);
    }
    //Insert If and Else According to FlowChart
    Sleep(2000);
    while(1) { // This will loop forever because wtf is 1?
        int Selection_1 = 0;
        puts("-----------------------------");
        printf("Version " VERSION_NUMBER "\n");
        printf(PRODUCT_NAME "\n");
        puts("-----------------------------");
        CriticalComp_Check();   // Init Function to Check for Critical Components Before Proceeding
        system("CLS");
        puts("-----------------------------");
        printf("Version " VERSION_NUMBER "\n");
        printf(PRODUCT_NAME "\n");
        puts("-----------------------------");
        puts("Main Menu");
        printf("[1] | Old Student\n");
        printf("[2] | New Student\n");
        printf("[3] | Check for Current Enrollment Status\n");
        printf("[4] | Exit Application\n");
        printf("Please enter your decision [1 - 4] | ");
        scanf("%i", &Selection_1);
        switch (Selection_1) {
        case 1:
            OldStd_Func();
            break;
        case 2:
            NewStd_Func();
            break;
        case 3:
            NewStd_ContinuationFunc();
            break;
        case 4:
            puts("Terminating Enrollment System...");
            Sleep(3000);
            return EXIT_SUCCESS;
        default:
            printf("Invalid Choice");
            Sleep(3000);
            continue;
        }
    }
}

// TECHNICAL STUDENT FUNCTION
char Argument_Initialization(int argc, char argv[]) {
    char *Argument_DefaultAvailable[2] = {"-fullscreen", "-management"};
    char *Argument_FinalCheckOtpt[2] = {"NULL"};
    int Argument_Checker;
    
    for (Argument_Checker = 0; Argument_Checker < argc; Argument_Checker++) {
        if(Argument_DefaultAvailable[Argument_Checker] == argv[Argument_Checker]) {
            Argument_FinalCheckOtpt[Argument_Checker++];
        }   
    }
    printf("Initializing Mode | %c", ArgumentModeReturn);



    // SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE),CONSOLE_FULLSCREEN_MODE,0);
}

// OLD STUDENT FUNCTIONS
void OldStd_Func() {
    struct StudentRecords OldStudent;
    while(1) {
        SetConsoleTitle("LM Enrollment System | Old Student Login");
        printf("Please enter your Username: ");
        scanf("%s", OldStudent.user_Username);
        printf("Please enter your Password: ");
        scanf("%s", OldStudent.user_Password);
        printf("Please enter your Student Number: ");
        scanf("%d", &OldStudent.user_StudentIdentity);
        // if (insert database here) = TRUE then
    }
    //printf("Hello %s | %d!\n", OldStudent.user_Username, OldStudent.user_StudentIdentity);
    //printf("Also your password is %s\n", OldStudent.user_Password);
    OldStd_Func_Enrollment_Eng(OldStudent);
}
void OldStd_Func_Enrollment_Eng(struct StudentRecords OldStudent_Continuation) {
    FILE *FileDatabase_ERLM;
    char datapoint_ERLM[] = "data/2018_LM_Database_Enrollment.dat";
    int Database_Check;
    Database_Check = fopen(datapoint_ERLM, "rb");
    if (Database_Check = NULL) {
        printf("Database Not Found, Terminating Program...");
        printf("Exit Code is %i", DATABASE_NOT_FOUND);
        return DATABASE_NOT_FOUND;
    }
    else {
    SetConsoleTitle("LM Enrollment System | Old Student Login");
    char *ENRL_Selection_Eng[4] = { "1st Year College", "2nd Year College", "3rd Year College", "4th Year College" };
    char ENRL_Stats_CurrentLevel, ENRL_Stats_Eligible;
    int Counter_For_Selection = 0;
    printf("-----------------------------");
    printf("Hello and Welcome %c", OldStudent_Continuation.user_StudentIdentity);
    printf("-----------------------------");
    Sleep(2000);
    printf("Name %s | Student Number: %i", OldStudent_Continuation.user_UserPersonalName, OldStudent_Continuation.user_StudentIdentity);
    printf("Your Current Level is %c", ENRL_Stats_CurrentLevel);
    printf("Enrollment Eligibility %c", ENRL_Stats_Eligible);
    for (Counter_For_Selection; Counter_For_Selection < 5; Counter_For_Selection++) {
        printf(ENRL_Selection_Eng[Counter_For_Selection]);
    }
    Sleep(999);
    printf("Function Undefined... Press any key to continue...");
    getch();
    return FUNCTION_UNFINISHED;
    }
}
void OldStd_Func_Enrollment_Selection() {

    printf("Here are the following available");
}
//Create Selectables Here for Array
void NewStd_Func() {
    SetConsoleTitle("LM Enrollment System | New Student Creation");
    FILE *Database_ERLM;
    // Not Finished
    char user_Name;
    char user_Birthday;
    char user_MName, user_FName, user_Nationality;
}
char stdnt_NumberCreate() {
    SetConsoleTitle("LM Enrollment System | Generating Number Identity...");
    SYSTEMTIME Btch_Year;
    char Created_Student_NumData;
    GetLocalTime(&Btch_Year); // Win32 Module Function
    // Get Current Batch and Student Number
    printf("Created Student Number Data(Untouched) %d | ",Btch_Year.wYear); // Another Two Predicted Values are Btch_Num,Btch_StudentNum.
    return Created_Student_NumData;
}

char CriticalComp_Check() {
    char ModeArgumentSet = 0, ReturnCodeChar = 0;
    int Counter_DataPoint_Check;
    HWND console = 0;
    RECT ConsoleMainApp;
    HWND hwnd = GetConsoleWindow();
    HMENU hmenu = GetSystemMenu(hwnd, FALSE);
    FILE *FileDatabase_ERLM;
    FILE *FileDatabase_User;
    FILE *FileDatabase_Admin;
    char datapoint_ERLM[] = "data/2018_LM_Database_Enrollment.dat";
    char datapoint_User[] = "data/2018_LM_Database_User.dat";
    char datapoint_Admin[] = "data/2018_LM_Database_Admin.dat";
    int datepoint_date;
    SetConsoleTitle("Intializing and Checking Critical Components | LM Enrollment System\n");
        printf("Initializing and Checking Critical Components Before Actual Program Initialization\n");
        printf("COMPONENT #   | TITLE   \t  STATUS\n");
        printf("Init.Component # 1 | Resize and Move the Command Line with Respective Ordered Values\n");
    MoveWindow(console, ConsoleMainApp.left, ConsoleMainApp.top, 1000, 500, TRUE);
        printf("Init.Component # 2 | Disable Close Button\n");
    EnableMenuItem(hmenu, SC_CLOSE, MF_GRAYED);
        printf("Component # 3.1 |  | Checking Local Database on Local Storage (Using .Dat File)\n");
    for (Counter_DataPoint_Check = 1; Counter_DataPoint_Check <= 3; Counter_DataPoint_Check++) {
        if (Counter_DataPoint_Check == 1) {
            printf("Checking for DataPoint Enrollment Data...",Counter_DataPoint_Check);
            FileDatabase_ERLM = fopen(datapoint_ERLM, "r");
            if (FileDatabase_ERLM = NULL) {
                printf("Component # 3.1 | Database for Enrollment was not found! Creating Database Point...");
                fwrite(datapoint_ERLM, 1, sizeof(datapoint_ERLM), FileDatabase_ERLM);
                fclose(FileDatabase_ERLM);
            }
        }
        if (Counter_DataPoint_Check == 2) {
            printf("Component # 3.2 | Checking for DataPoint User Data...",Counter_DataPoint_Check);
            FileDatabase_User = fopen(datapoint_User, "r");
            if (FileDatabase_User = NULL) {
                printf("Component # 3.2 | Database for User was not found! Creating Database Point...");
                fwrite(datapoint_ERLM, 1, sizeof(datapoint_ERLM), FileDatabase_ERLM);
                fclose(FileDatabase_User);
            }
        }
        if (Counter_DataPoint_Check == 3) {
            printf("Component # 3.3 | Checking for DataPoint Admin Data...",Counter_DataPoint_Check);
            FileDatabase_Admin = fopen(datapoint_Admin, "r");
            if (FileDatabase_Admin = NULL) {
                printf("Component # 3.3 | Database for Admin was not found! Creating Database Point...");
                fwrite(datapoint_Admin, 1, sizeof(datapoint_Admin), FileDatabase_Admin);
                fclose(FileDatabase_Admin);
            }
            GetLocalTime(&datapoint_date);
            printf("Database Created as of %c", datapoint_date);
        } 
         else {
            fclose(FileDatabase_ERLM);
            fclose(FileDatabase_User);
            fclose(FileDatabase_Admin);
            printf("Local Database Found!");
        }
        }
        if ((strstr(ERROR_1, ReturnCodeChar)) || (strstr(ERROR_2, ReturnCodeChar)) ||
            (strstr(WARN_1, ReturnCodeChar)) || (strstr(WARN_2, ReturnCodeChar))) == TRUE)
    {
        ReturnCodeChar = "ACMPLT";
        printf("%s", ReturnCodeChar);
        Sleep(3000);
    }
    if (PostReturn == ERROR_1 || ERROR_2) {
    printf("Most of the Critical Components where unable to compile. Terminating the program in 3 seconds.");
        Sleep(3000);
        return EXIT_FAILURE;
    } else if (PostReturn == WARN_1 || WARN_2) {
    printf("Few Critical Components where unable to compile. Although it's an optional critical component, Proceeding...");
        Sleep(2500); // Wait Before Continue, Time In milliseconds
    } else {
        printf("One or more critical components has failed to comply! Terminating...\n Exit Code is %d", PostReturn);
        // A Function Defined in Windows.H to show what error that would be. (Win32API)
        return GetLastError();
    }
}