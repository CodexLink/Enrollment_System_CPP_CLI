// Group LM - Enrollment System in C for Preliminary Project in Programming
#include <stdio.h>
#include <stdlib.h>   // For SYSTEM Command
#include <conio.h>    // For Getch()
#include <windows.h>  // Windows Designed Only Header, This Rips Compatibility.
#include <winsock2.h> // Added
#include <time.h>     // For Time Display and Such
// defined marcros to avoid typing these words again.
//Calling those will result into the following strings
#define VERSION_NUMBER "2259-08102018"
#define PRODUCT_NAME "Group LM | C CLI Enrollment System for TiP Engineering and Architecture"
// Include Expected Header Such as ICMP for Communication in Windows
int stdnt_Number(int Btch_Year, int Btch_Number, int Btch_Identity_Number);
int Old_POST_Logon(char Pass, char User);
void OldStudent_Funct();
void NewStudent_Func();
int POST_Screen (int ReturnCodeValue);
// INCLUDE ALL FUNCTION PROTOTYPE HERE, BECAUSE FUNCTIONS DONE WITH BODY IS
//GOING TO BE PLACE BELOW FROM INT MAIN FUNCTION
int main(int argc, char *argv[])
{
    int Selection_1;
    int POST_Screen;
    Post = POST_Screen();
    if (POST_Screen == 0) {
    system("CLS"); // A bit of a impractical. Looking forward to clrscr
    puts("------------------------");
    printf("Version " VERSION_NUMBER "\n");
    printf(PRODUCT_NAME "\n");
    puts("------------------------");
    puts("Main Menu");
    puts("[1] Old Student");
    puts("[2] New Student");
    printf("Please enter your decision [1 - 2] | ");
    scanf("%i", &Selection_1);
    switch (Selection_1)
    {
    case 1:
        OldStudent_Func();
    case 2:
        break; //NewStudent_Func();
    }
    puts("Outside Function Detected. Exiting");
    getch();
    return 0;
    } else {
        system("CLS");
        puts("One our more critical components has failed to comply. Exiting. Exit Code is %d", ReturnCodeValue);
    }
}

int OldStudent_Func()
{
    puts("wat");
}
