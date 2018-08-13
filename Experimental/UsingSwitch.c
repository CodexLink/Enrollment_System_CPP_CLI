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

int main(int argc, char *argv[]) {
while(1) {
    int Selection_1 = 0;
    puts("-----------------------------");
    printf("Version " VERSION_NUMBER "\n");
    printf(PRODUCT_NAME "\n");
    puts("-----------------------------");
    //CriticalComp_Check();   // Init Function to Check for Critical Components Before Proceeding
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
    printf("1");
        printf("OldStd_Func();");
        break;
    case 2:
    printf("2");
        printf("NewStd_Func();");
        break;
    case 3:
    printf("3");
        printf("NewStd_ContinuationFunc();");
        break;
    case 4:
    printf("4");
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