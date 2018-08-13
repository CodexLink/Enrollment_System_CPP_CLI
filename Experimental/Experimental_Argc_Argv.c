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

int main(int argc, char *argv[]) 
{
    int a;
    printf("Arguments Accounted on EXE Inline is %i\n", argc);
    for (a = 0; a < argc; a++) 
    {
        printf(argv[a]);
        printf("\n");
    }
}