/*==============================================================================
Group LM - Enrollment System in C for Preliminary Project in Programming
Enrollment System, Version 2355-08182018 BETA
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
#define FUNCTION_UNFINISHED 1362565
#define DATABASE_NOT_FOUND 40

struct StudentRecords
{
    int user_StudentIdentity;
    char user_Username[20], user_Password[32], user_UserPersonalName[20];
};
struct New_StudentRecords
{
    char std_FName[30],
    std_MName[30],
    std_LName[30],
    std_Gender[1],
    std_Birthday[30],
    std_Nationality[10],
    std_SpecialBehavioral[50],
    std_Address[MAX_PATH],
    std_stdEmail[40],
    POC_Emergency[30];
    int std_PhoneNum, std_MobileNum,std_EmerNum;
};

int Func_AlgoStdnt_NumberCreate(); // Function that creates a number
int Function_Managament_ERLM();

char Function_CriticalComp_CheckCreate(); // Checks and Sets Components Before Initializing
char Argument_Initialization(argc, argv); // PASS ARGC AND ARGV To Another Function

void PrintTranscript(); // New Function

void Func_OldStd_Logon();        // Function for Old Student
void Func_OldStd_Menu(OldStudent);
void Func_NewStdnt_ERLM();     // Function for New Student


char Argument_Initialization(int argc, char *argv[]);

int main(int argc, char *argv[]) {
    int Counter_Argument;
    char ArgumentModeReturn;
    if (argc > 1) {
        Argument_Initialization(argc, argv);
    }
    //Insert If and Else According to FlowChart
    Sleep(2000);
    while(1) { // This will loop forever because wtf is 1?
        int Selection_1 = 0;
        puts("-----------------------------");
        printf("Version " VERSION_NUMBER "\n");
        printf(PRODUCT_NAME "\n");
        puts("-----------------------------");
        Function_CriticalComp_CheckCreate();   // Init Function to Check for Critical Components Before Proceeding
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

// TECHNICAL COMPONENT CHECKING FUNCTION
char Argument_Initialization(int argc, char *argv[]) {
  HWND consoleWindow = GetConsoleWindow();
  int Argument_Checker = 0;
  printf("  @ Function \t|\t INITIALIZING \t|\t  Argument_Initialization\n");
  while(Argument_Checker != argc) {
      if (strcmp(argv[Argument_Checker], "/rstrict_wnd") == 0 ) {
        SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
      }
      if (strcmp(argv[Argument_Checker], "/mgr_md") == 0 ) {
        printf("void Function_Mgr_Mode();");
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
    char *ACMPLT ="Critical Components Checkpoint Completed";
    char *WARN_1 ="ERROR.UnableToConnect";
    SYSTEMTIME GetDate_Local;
    SetConsoleTitle("Intializing Critical Components | LM Enrollment System\n");
        printf("Initializing and Checking Critical Components Before Actual Program Initialization\n");
        puts("---------------------------------------------------------------------------------------------------");
        printf("COMPONENT MATERIAL\t|\t STATUS\t\t| DESCRIPTION\t\n");
        puts("---------------------------------------------------------------------------------------------------");
        printf("Init.Component # 1 \t|\t COMPLETE \t| Resize and Move the Command Line with Respective Ordered Values\n");
    MoveWindow(console, ConsoleMainApp.left, ConsoleMainApp.top, 1000, 500, TRUE);
        printf("Init.Component # 2 \t|\t COMPLETE \t| Disable Close Button\n");
    EnableMenuItem(hmenu, SC_CLOSE, MF_GRAYED);
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
// Make this function return success in order to start.
// OLD STUDENT FUNCTIONS
void Func_OldStd_Logon() {
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
    Func_OldStd_Enrollment_Menu(OldStudent);
}
void Func_OldStd_Enrollment_Menu(struct StudentRecords OldStudent_Continuation) {
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

//Create Selectables Here for Array
// ALGORITHMS
int Func_AlgoStdnt_NumberCreate() {
    SetConsoleTitle("LM Enrollment System | Generating Number Identity...");
    SYSTEMTIME Btch_Year;
    char Created_Student_NumData;
    GetLocalTime(&Btch_Year); // Win32 Module Function
    // Get Current Batch and Student Number
    printf("Created Student Number Data(Untouched) %d | ",Btch_Year.wYear); // Another Two Predicted Values are Btch_Num,Btch_StudentNum.
    return Created_Student_NumData;
}
void Func_NewStdnt_ERLM () {
    SetConsoleTitle("LM Enrollment System | New Student Creation");
    FILE *Database_ERLM;
        // Init Variable, I cannot assign a string in struct.
    struct New_StudentRecords NewData;
    strcpy(NewData.std_FName, "No First Name Set..."); 
    strcpy(NewData.std_MName, "No Middle Name Set...");
    strcpy(NewData.std_LName, "No Last Name Set...");
    strcpy(NewData.std_Gender, "None...");
    strcpy(NewData.std_Birthday, "No Birthday Set...");
    strcpy(NewData.std_Nationality, "No Nationality Sets...");
    strcpy(NewData.std_SpecialBehavioral, "No Precautions Set...");
    strcpy(NewData.std_Address, "No Address Set...");
    NewData.std_PhoneNum = 0; 
    NewData.std_MobileNum = 0; 
    NewData.std_EmerNum = 0;
    strcpy(NewData.std_stdEmail, "No Email Set...");
    strcpy(NewData.POC_Emergency, "No Point of Contact Set...");

    int DataComplete = 0, Choice_Break = 0, Choice_FillInfo;
    system("CLS");
    while (DataComplete != 1)
    {
        SetConsoleTitle(PRODUCT_NAME);
        puts("---------------------------------------------------------------------------------------------------");
        printf("--! 1st Step - Input your Personal Information | 2nd | 3rd | 4th | Confirm | End\n");
        printf("++ Information: Please provide your information to let us identify you as a future student!\n");
        printf("Fill up the Following by Selecting their numbers assigned to...\n");
        puts("---------------------------------------------------------------------------------------------------");
        // IDENTITY INFORMATION
        printf("\n [1] First Name: %s \t\t", NewData.std_FName);
        printf("\n [2] Middle Name: %s \t\t", NewData.std_MName);
        printf("\n [3] Last Name: %s \t\t\n", NewData.std_LName);
        puts("---------------------------------------------------------------------------------------------------");
        //GENERAL INFORMATION
        printf("\n [4] Gender: %s \t\t", NewData.std_Gender);
        printf("\n [5] Birthday:  %s \t\t", NewData.std_Birthday);
        printf("\n [6] Home (Main) Address: %s \t\t", NewData.std_Address); //Include City and Village, ZIP CODE
        printf("\n [7] Nationality: %s \t\t\n", NewData.std_Nationality);
        puts("---------------------------------------------------------------------------------------------------");
        // TECHNICAL INFORMATION
        printf("\n [8] Mobile Number: %li \t\t", NewData.std_MobileNum);
        printf("\n [9] Phone Number:  %li \t\t", NewData.std_PhoneNum);
        printf("\n [10] Emergency Number and Emergency Point of Contact (Seperated)): %li | %s", NewData.std_EmerNum, NewData.POC_Emergency);
        printf("\n [11] Personal Email: %s \t\t", NewData.std_stdEmail);
        printf("\n [Behavioral Issues]: %s \t\t", NewData.std_SpecialBehavioral);
        printf("\nStopped.");
        getch();
        if (Choice_FillInfo == 0)
        {
            printf("There is no current choice to fill an information!");
        }
        else
        {
            printf("Current Choice to Fill is assigned to #%i", Choice_FillInfo);
        }
        printf("Please enter a desired number to fill up information...");
        scanf("%i", &Choice_FillInfo);
        while (Choice_Break != 1)
        {
            switch (Choice_FillInfo)
            {
            case 1:
                printf("NAN");
            case 2:
                printf("NAN");
            case 3:
                printf("NAN");
            case 4:
                printf("NAN");
            case 5:
                printf("NAN");
            case 6:
                printf("NAN");
            case 7:
                printf("NAN");
            case 8:
                printf("NAN");
            case 9:
                printf("NAN");
            case 10:
                printf("NAN");
            case 11:
                printf("NAN");
            case 12:
                printf("NAN");
            default:
                printf("Input Exceed from the Number Given in the Menu!");
                Sleep(2000);
            }
        }
        continue; // Continue from this Loop Instead from the Inside Loop
    }
}
// SIDE FUNCTIONS
void PrintTranscript() {

}