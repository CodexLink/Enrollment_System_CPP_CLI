#include <stdio.h>   // Just Basic Input Output Header File
#include <stdlib.h>  // For SYSTEM Command
#include <conio.h>   // For Getch()
#include <windows.h> // Windows Designed Only Header, This Rips Compatibility.
#include <time.h> // For Time Display and Such
#include <string.h> // String Handling for Usage of Structure and Database
#define VERSION_NUMBER "2259-08102018-BETA"
#define PRODUCT_NAME "Group LM | C CLI Enrollment System for TiP Engineering and Architecture"
#define FUNCTION_UNFINISHED 1362565
#define DATABASE_NOT_FOUND 40

char Function_CriticalComp_CheckCreate(); // Checks and Sets Components Before Initializing
char Argument_Initialization(int argc, char *argv[]);



int main(int argc, char *argv[]) {
    // When Program detects that parameter count is one and obove, initialize this function for initiating the parameters passed.
    if (argc > 1) {
        Argument_Initialization(argc, argv); // Pass ARGC and ARGV for Clean Execution.
    }
    Sleep(2000);
    while(1) { // While (AnyValue Especially One) will Loop Forever due to no datachecking, hence this will true to be looping until break; command has been called.
        int Selection_1 = 0;
        puts("-----------------------------");
        printf("Version " VERSION_NUMBER "\n");
        printf(PRODUCT_NAME "\n");
        puts("-----------------------------");
        Function_CriticalComp_CheckCreate();   // Init Function to Check for Critical Components Before Proceeding The Actual Program...
        system("CLS");
        puts("-----------------------------");
        printf("Version " VERSION_NUMBER "\n"); // Call VERSION_NUMBER String and Display
        printf(PRODUCT_NAME "\n"); // Call VERSION_NUMBER String and Display
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
            printf("OldStd_Func();");
            break;
        case 2:
            printf("NewStd_Func();");
            break;
        case 3:
            printf("NewStd_ContinuationFunc();");
            break;
        case 4:
        SetConsoleTitle("Terminating Enrollment System | LM Enrollment System");
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

char Argument_Initialization(int argc, char *argv[]) {
  HWND hwnd = GetConsoleWindow();
  HWND consoleWindow = GetConsoleWindow();
  int Argument_Checker = 0;
  printf("  @ Function \t|\t INITIALIZING \t|\t  Argument_Initialization\n");
  while(Argument_Checker != argc) {
      if (strcmp(argv[Argument_Checker], "/rstrict_wnd") == 0 ) {
   		printf("Init.Component # 1 \t|\t COMPLETE \t| Set Command Line to Full Screen\n");
    	ShowWindow(hwnd, SHOW_FULLSCREEN);
        SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
        printf("@ Function \t|\t INITIALIZED \t|\t Restricted Window Console");
      }
      if (strcmp(argv[Argument_Checker], "/mgr_md") == 0 ) {
        printf("void Function_Mgr_Mode();");
        printf("@ Function \t|\t STARTING \t|\t Management Mode");
      }
      Argument_Checker++;
  }
  system("CLS");
}

char Function_CriticalComp_CheckCreate() {

    int Counter_DataPoint_Check;
    HWND console = 0;
    RECT ConsoleMainApp;
    HWND hwnd = GetConsoleWindow();
    HMENU hmenu = GetSystemMenu(hwnd, FALSE);
    FILE *FileDatabase_ERLM;
    FILE *FileDatabase_User;
    FILE *FileDatabase_Admin;
    char datapoint_ERLM[] = "2018_LM_Database_Enrollment.dat";
    char datapoint_User[] = "2018_LM_Database_User.dat";
    char datapoint_Admin[] = "2018_LM_Database_Admin.dat";
    char *ERROR_1 = "WARN.UnableReposition";
    char *ERROR_2 = "WARN.Win32Disable_Denied";
    char *WARN_2 ="ERROR.UnableToCheckStorage";
    char *ACMPLT ="Critical Components Checkpoint Completed!";
    char *WARN_1 ="ERROR.UnableToConnect"; //For SSH
    SYSTEMTIME GetDate_Local;
    SetConsoleTitle("Intializing Critical Components | LM Enrollment System\n");
        printf("Initializing and Checking Critical Components Before Actual Program Initialization\n");
        puts("---------------------------------------------------------------------------------------------------");
        printf("COMPONENT MATERIAL\t|\t STATUS\t\t| DESCRIPTION\t\n");
        puts("---------------------------------------------------------------------------------------------------");
        printf("Init.Component # 2 \t|\t COMPLETE \t| Disable Close Button\n");
    EnableMenuItem(hmenu, SC_CLOSE, MF_DISABLED);
        printf("Init.Component # 3.1 \t|\t CHECKING \t| Checking Local Database on Local Storage (Using .Dat File)\n");
    for (Counter_DataPoint_Check = 1; Counter_DataPoint_Check <= 3; Counter_DataPoint_Check++) {
        if (Counter_DataPoint_Check == 1) {
            FileDatabase_ERLM = fopen(datapoint_ERLM, "r");
            if (FileDatabase_ERLM == NULL) {
                printf("Init.Component # 3.1 \t|\t ERROR \t\t| Database for Enrollment was not found! Creating Database Point...\n");
                //fwrite(datapoint_ERLM, 1, sizeof(datapoint_ERLM), FileDatabase_ERLM);
                FileDatabase_ERLM = fopen(datapoint_ERLM, "w+");
                fclose(FileDatabase_ERLM);
            } else {
            printf("Init.Component # 3.1 \t|\t VERIFIED \t| Local Database Found for Enrollment!\n");
            fclose(FileDatabase_ERLM);
            }
        }
        else if (Counter_DataPoint_Check == 2) {
            printf("Init.Component # 3.2 \t|\t CHECKING \t| Checking for DataPoint User Data...\n");
            FileDatabase_User = fopen(datapoint_User, "r");
            if (FileDatabase_User == NULL) {
                printf("Init.Component # 3.2 \t|\t ERROR \t\t| Database for User was not found! Creating Database Point...\n");
                //fwrite(datapoint_ERLM, 1, sizeof(datapoint_ERLM), FileDatabase_ERLM);
                FileDatabase_User = fopen(datapoint_User, "w+");
                fclose(FileDatabase_User);
            } else {
            printf("Init.Component # 3.2 \t|\t VERIFIED \t| Local Database Found for Student User!\n");
            fclose(FileDatabase_User);
            }
        }
        else if (Counter_DataPoint_Check == 3) {
            printf("Init.Component # 3.3 \t|\t CHECKING \t| Checking for DataPoint Admin Data...\n");
            FileDatabase_Admin = fopen(datapoint_Admin, "r");
            if (FileDatabase_Admin == NULL) {
                printf("Init.Component # 3.3 \t|\t ERROR \t\t| Database for Admin was not found! Creating Database Point...\n");
                //fwrite(datapoint_Admin, 1, sizeof(datapoint_Admin), FileDatabase_Admin);
                FileDatabase_Admin = fopen(datapoint_Admin, "w+");
                fclose(FileDatabase_Admin);
            }
            else {
            printf("Init.Component # 3.3 \t|\t VERIFIED \t| Local Database Found for Admin!\n");
            fclose(FileDatabase_Admin);
            }
        } 
    }
    GetLocalTime(&GetDate_Local);
    puts("---------------------------------------------------------------------------------------------------");
    printf("\nDatabase Created as of %02d:%02d\n", GetDate_Local.wHour, GetDate_Local.wMinute);
    Sleep(3000);
    puts(ACMPLT);
    printf("Press any key to continue...");
    getch();
}
