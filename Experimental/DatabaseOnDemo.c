#include <stdio.h>   // Just Basic Input Output Header File
#include <stdlib.h>  // For SYSTEM Command
#include <conio.h>   // For Getch()
#include <windows.h> // Windows Designed Only Header, This Rips Compatibility.
#include <time.h>    // For Time Display and Such
#include <string.h>  // String Handling for Usage of Structure and Database
#define VERSION_NUMBER "2259-08102018-BETA"
#define PRODUCT_NAME "Group LM | C CLI Enrollment System for TiP Engineering and Architecture"
#define ERROR_1 "WARN.UnableReposition"
#define ERROR_2 "WARN.Win32Disable_Denied"
#define WARN_1 "ERROR.UnableToConnect"
#define WARN_2 "ERROR.UnableToCheckStorage"
#define ACMPLT "Critical Components Checkpoint Completed"
#define FUNCTION_UNFINISHED 1362565
#define DATABASE_NOT_FOUND 40
struct StudentRecords
{
    int user_StudentIdentity;
    char user_Username[20], user_Password[32], user_UserPersonalName[20];
};
struct New_StudentRecords
{
    char user_Name[25];
    char user_Birthday[30];
    char user_MName[15], user_FName[15], user_Nationality[10];
};

int OldStd_Func_Enrollment_Eng(struct StudentRecords OldStudent_Continuation);

int main()
{
    system("CLS");
    SetConsoleTitle("LM Enrollment System | Old Student Login");
    FILE *FileDatabase_ERLM;
    struct StudentRecords OldStudent;
    char datapoint_ERLM[] = "2018_LM_Database_Enrollment.dat";
    char user_Username;
    FileDatabase_ERLM = fopen(datapoint_ERLM, "r");
    while (1)
    {
        printf("Please enter your Username: ");
        scanf("%s", OldStudent.user_Username);
        printf("Please enter your Password: ");
        scanf("%s", OldStudent.user_Password);
        printf("Please enter your Student Number: ");
        scanf("%d", &OldStudent.user_StudentIdentity);
        printf("Checking Data for the User::%s...", OldStudent.user_Username);
        fread(&OldStudent, sizeof(OldStudent), 1, FileDatabase_ERLM);
            printf("%s\n", OldStudent);
            if (feof(FileDatabase_ERLM)) {
                puts("Search on File Done. End of the Line Reached.");
            }
            if (user_Username == OldStudent.user_Username) {
                puts("Data Record Found");
                break;
            }
            else {
            	puts("Data Not Found!");
            	Sleep(3000);
            	continue;
			}
            Sleep(10000);
            getch();
        
        OldStd_Func_Enrollment_Eng(OldStudent);
    }
}

int OldStd_Func_Enrollment_Eng(struct StudentRecords OldStudent_Continuation)
{
    system("CLS");
    char datapoint_ERLM[] = "2018_LM_Database_Enrollment.dat";
    int Database_Check;
    Database_Check = fopen(datapoint_ERLM, "w+");
    fclose(datapoint_ERLM);
    if (Database_Check == 0)
    {
        printf("Database Not Found, Terminating Program...");
        printf("Exit Code is %i\n", DATABASE_NOT_FOUND);
        printf("Creating...");
        fopen(datapoint_ERLM, "w+");
        return DATABASE_NOT_FOUND;
    }
    else
    {
        SetConsoleTitle("LM Enrollment System | Old Student Login");
        system("CLS");
        char *ENRL_Selection_Eng[4] = {"A.) 1st Year College", "B.) 2nd Year College", "C.) 3rd Year College", "D.) 4th Year College"};
        char ENRL_Stats_CurrentLevel = 'N', ENRL_Stats_Eligible = 'N';
        int Counter_For_Selection = 0;
        printf("-----------------------------\n");
        printf("Hello and Welcome, Student Identity: %i\n", OldStudent_Continuation.user_StudentIdentity);
        printf("-----------------------------\n");
        Sleep(2000);
        printf("Name %s | Student Number: %i\n", OldStudent_Continuation.user_UserPersonalName, OldStudent_Continuation.user_StudentIdentity);
        printf("Your Current Level is %c\n", ENRL_Stats_CurrentLevel);
        printf("Enrollment Eligibility %c\n", ENRL_Stats_Eligible);
        for (Counter_For_Selection; Counter_For_Selection < 5; Counter_For_Selection++)
        {
            printf("\n");
            printf(ENRL_Selection_Eng[Counter_For_Selection]);
        }
        Sleep(999);
        printf("Function Undefined... Press any key to continue...");
        getch();
        return FUNCTION_UNFINISHED;
    }
}
