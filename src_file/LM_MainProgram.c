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
#include <time.h>    // For Time Display and Such
#include <string.h>  // String Handling for Usage of Structure and Database
#define VERSION_NUMBER "2259-08102018-BETA"
#define PRODUCT_NAME "Group LM | C CLI Enrollment System for TiP Engineering and Architecture"
#define FUNCTION_UNFINISHED 1362565
#define DATABASE_NOT_FOUND 40

struct Old_StudentRecords
{
    int user_StudentIdentity;
    char user_Username[20], user_Password[32], user_UserPersonalName[20];
};
struct New_StudentRecords
{
    char stdnt_FName[30],
        stdnt_MName[30],
        stdnt_LName[30],
        stdnt_Gender[6],
        stdnt_Birthday[30],
        stdnt_Nationality[30],
        stdnt_SpecialBehavioral[50],
        stdnt_Address[MAX_PATH],
        stdnt_Email[40],
        stdnt_POC_Emergency[30];
    int stdnt_PhoneNum, stdnt_MobileNum, stdnt_EmerNum;
};

// Extra and Outside | Additional Function Prototypes
int Function_Management_ERLM();
void gotoxy(int x, int y);

//POST and Critical Component Function Prototypes
char Function_CriticalComp_CheckCreate(); // Checks and Sets Components Before Initializing
char Argument_Initialization(argc, argv); // PASS ARGC AND ARGV To Another Function

void Main_Menu();
int stdnt_DataCheck(struct New_StudentRecords NewData_Receiver);
void Func_NewStdnt_ERLM();
int Func_NewStdnt_ERLM_Step2();
int Func_NewStdnt_Eng_YearSelect(struct New_StudentRecords NewData_Receiver, char *MainCourse_CodeName_Passer, char *MainCourse_FullName_Passer);
int Func_NewStdnt_Arch_YearSelect(struct New_StudentRecords NewData, char *MainCourse_CodeName_Passer);

int Func_NewStdnt_Eng_Subject_Select();

int Func_NewStdnt_Arch_Subject_Select();

//int Func_Stdnt_ScholarshipCheck();
int stdnt_Scholarship_Check();

int Func_AlgoStdnt_NumberCreate(); // Function that creates a number
void PrintDocument_FinalTranscript();

//Architecture Selection Functions for Enrollment
int Stdnt_1stYear_Arch_FirstSem();
int Stdnt_1stYear_Arch_SecondSem();
int Stdnt_2ndYear_Arch_FirstSem();
int Stdnt_2ndYear_Arch_SecondSem();
int Stdnt_3rdYear_Arch_FirstSem();
int Stdnt_3rdYear_Arch_SecondSem();
int Stdnt_4thYear_Arch_FirstSem();
int Stdnt_4thYear_Arch_SecondSem();
int Stdnt_5thYear_Arch_FirstSem();
int Stdnt_5thYear_Arch_SecondSem();
// Civil Engineer Selection Functions for Enrollment
int Stdnt_1stYear_CE_FirstSem();
int Stdnt_1stYear_CE_SecondSem();
int Stdnt_2ndYear_CE_FirstSem();
int Stdnt_2ndYear_CE_SecondSem();
int Stdnt_3rdYear_CE_FirstSem();
int Stdnt_3rdYear_CE_SecondSem();
int Stdnt_4thYear_CE_FirstSem();
int Stdnt_4thYear_CE_SecondSem();
// Computer Engineer Selection Functions for Enrollment
int Stdnt_1stYear_CpE_FirstSem();
int Stdnt_1stYear_CpE_SecondSem();
int Stdnt_2ndYear_CpE_FirstSem();
int Stdnt_2ndYear_CpE_SecondSem();
int Stdnt_3rdYear_CpE_FirstSem();
int Stdnt_3rdYear_CpE_SecondSem();
int Stdnt_4thYear_CpE_FirstSem();
int Stdnt_4thYear_CpE_SecondSem();
// Electrical Engineer Selection Functions for Enrollment
int Stdnt_1stYear_EE_FirstSem();
int Stdnt_1stYear_EE_SecondSem();
int Stdnt_2ndYear_EE_FirstSem();
int Stdnt_2ndYear_EE_SecondSem();
int Stdnt_3rdYear_EE_FirstSem();
int Stdnt_3rdYear_EE_SecondSem();
int Stdnt_4thYear_EE_FirstSem();
int Stdnt_4thYear_EE_SecondSem();
// Electronics Engineer Selection Functions for Enrollment
int Stdnt_1stYear_ECE_FirstSem();
int Stdnt_1stYear_ECE_SecondSem();
int Stdnt_2ndYear_ECE_FirstSem();
int Stdnt_2ndYear_ECE_SecondSem();
int Stdnt_3rdYear_ECE_FirstSem();
int Stdnt_3rdYear_ECE_SecondSem();
int Stdnt_4thYear_ECE_FirstSem();
int Stdnt_4thYear_ECE_SecondSem();
// Environmental and Sanitary Engineer Selection Functions for Enrollment
int Stdnt_1stYear_EnSE_FirstSem();
int Stdnt_1stYear_EnSE_SecondSem();
int Stdnt_2ndYear_EnSE_FirstSem();
int Stdnt_2ndYear_EnSE_SecondSem();
int Stdnt_3rdYear_EnSE_FirstSem();
int Stdnt_3rdYear_EnSE_SecondSem();
int Stdnt_4thYear_EnSE_FirstSem();
int Stdnt_4thYear_EnSE_SecondSem();
// Industrial Engineer Selection Functions for Enrollment
int Stdnt_1stYear_IE_FirstSem();
int Stdnt_1stYear_IE_SecondSem();
int Stdnt_2ndYear_IE_FirstSem();
int Stdnt_2ndYear_IE_SecondSem();
int Stdnt_3rdYear_IE_FirstSem();
int Stdnt_3rdYear_IE_SecondSem();
int Stdnt_4thYear_IE_FirstSem();
int Stdnt_4thYear_IE_SecondSem();
// Mechanical Engineer Selection Functions for Enrollment
int Stdnt_1stYear_ME_FirstSem();
int Stdnt_1stYear_ME_SecondSem();
int Stdnt_2ndYear_ME_FirstSem();
int Stdnt_2ndYear_ME_SecondSem();
int Stdnt_3rdYear_ME_FirstSem();
int Stdnt_3rdYear_ME_SecondSem();
int Stdnt_4thYear_ME_FirstSem();
int Stdnt_4thYear_ME_SecondSem();

int main(int argc, char *argv[])
{
    HWND consoleWindow = GetConsoleWindow();
    int Argument_Checker = 0;
    printf("  @ Function \t|\t INITIALIZING \t|\t  int main() => Argument_Initialization\n");
    if (argc > 1)
    {
        while (Argument_Checker != argc)
        {
            if (strcmp(argv[Argument_Checker], "/rstrict_wnd") == 0)
            {
                SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
            }
            if (strcmp(argv[Argument_Checker], "/mgr_md") == 0)
            {
                printf("void Function_Mgr_Mode();");
            }
            Argument_Checker++;
        }
    }
    else
    {
        system("CLS");
    }
    Function_CriticalComp_CheckCreate();
}

char Function_CriticalComp_CheckCreate()
{
    int Counter_DataPoint_Check;
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
    char *WARN_2 = "ERROR.UnableToCheckStorage";
    char *ACMPLT = "Critical Components Checkpoint Completed";
    char *WARN_1 = "ERROR.UnableToConnect";
    SYSTEMTIME GetDate_Local;
    SetConsoleTitle("Intializing Critical Components | LM Enrollment System\n");
    printf("Initializing and Checking Critical Components Before Actual Program Initialization\n");
    puts("---------------------------------------------------------------------------------------------------");
    printf("COMPONENT MATERIAL\t|\t STATUS\t\t| DESCRIPTION\t\n");
    puts("---------------------------------------------------------------------------------------------------");
    printf("Init.Component # 1 \t|\t COMPLETE \t| Set Command Line to Full Screen\n");
    ShowWindow(hwnd, SW_MAXIMIZE);
    printf("Init.Component # 2 \t|\t COMPLETE \t| Disable Close Button\n");
    EnableMenuItem(hmenu, SC_CLOSE, MF_GRAYED);
    printf("Init.Component # 3.1 \t|\t CHECKING \t| Checking Local Database on Local Storage (Using .Dat File)\n");
    for (Counter_DataPoint_Check = 1; Counter_DataPoint_Check <= 3; Counter_DataPoint_Check++)
    {
        if (Counter_DataPoint_Check == 1)
        {
            FileDatabase_ERLM = fopen(datapoint_ERLM, "r");
            if (FileDatabase_ERLM == NULL)
            {
                printf("Init.Component # 3.1 \t|\t ERROR \t\t| Database for Enrollment was not found! Creating Database Point...\n");
                //fwrite(datapoint_ERLM, 1, sizeof(datapoint_ERLM), FileDatabase_ERLM);
                FileDatabase_ERLM = fopen(datapoint_ERLM, "w+");
                fclose(FileDatabase_ERLM);
            }
            else
            {
                printf("Init.Component # 3.1 \t|\t VERIFIED \t| Local Database Found for Enrollment!\n");
                fclose(FileDatabase_ERLM);
            }
        }
        else if (Counter_DataPoint_Check == 2)
        {
            printf("Init.Component # 3.2 \t|\t CHECKING \t| Checking for DataPoint User Data...\n");
            FileDatabase_User = fopen(datapoint_User, "r");
            if (FileDatabase_User == NULL)
            {
                printf("Init.Component # 3.2 \t|\t ERROR \t\t| Database for User was not found! Creating Database Point...\n");
                //fwrite(datapoint_ERLM, 1, sizeof(datapoint_ERLM), FileDatabase_ERLM);
                FileDatabase_User = fopen(datapoint_User, "w+");
                fclose(FileDatabase_User);
            }
            else
            {
                printf("Init.Component # 3.2 \t|\t VERIFIED \t| Local Database Found for Student User!\n");
                fclose(FileDatabase_User);
            }
        }
        else if (Counter_DataPoint_Check == 3)
        {
            printf("Init.Component # 3.3 \t|\t CHECKING \t| Checking for DataPoint Admin Data...\n");
            FileDatabase_Admin = fopen(datapoint_Admin, "r");
            if (FileDatabase_Admin == NULL)
            {
                printf("Init.Component # 3.3 \t|\t ERROR \t\t| Database for Admin was not found! Creating Database Point...\n");
                //fwrite(datapoint_Admin, 1, sizeof(datapoint_Admin), FileDatabase_Admin);
                FileDatabase_Admin = fopen(datapoint_Admin, "w+");
                fclose(FileDatabase_Admin);
            }
            else
            {
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

void Main_Menu()
{
    system("CLS");
    while (1)
    { // This will loop forever because wtf is 1?
        int Selection_1 = 0;
        system("CLS");
        puts("-----------------------------");
        printf("Version " VERSION_NUMBER "\n");
        printf(PRODUCT_NAME "\n");
        puts("-----------------------------");
        puts("Main Menu");
        printf("[1] | Old Student\n");
        printf("[2] | New Student\n");
        printf("[3] | Reprint Enrollment Student Form | Registration Form\n");
        printf("[4] | Exit Application\n");
        printf("Please enter your decision [1 - 4] | ");
        scanf("%i", &Selection_1);
        switch (Selection_1)
        {
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

// OLD STUDENT FUNCTIONS
void Func_OldStd_Logon()
{
    struct StudentRecords OldStudent;
    while (1)
    {
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
void Func_OldStd_Enrollment_Menu(struct StudentRecords OldStudent_Continuation)
{
    FILE *FileDatabase_ERLM;
    char datapoint_ERLM[] = "data/2018_LM_Database_Enrollment.dat";
    int Database_Check;
    Database_Check = fopen(datapoint_ERLM, "rb");
    if (Database_Check = NULL)
    {
        printf("Database Not Found, Terminating Program...");
        printf("Exit Code is %i", DATABASE_NOT_FOUND);
        return DATABASE_NOT_FOUND;
    }
    else
    {
        SetConsoleTitle("LM Enrollment System | Old Student Login");
        char *ENRL_Selection_Eng[4] = {"1st Year College", "2nd Year College", "3rd Year College", "4th Year College"};
        char ENRL_Stats_CurrentLevel, ENRL_Stats_Eligible;
        int Counter_For_Selection = 0;
        printf("-----------------------------");
        printf("Hello and Welcome %c", OldStudent_Continuation.user_StudentIdentity);
        printf("-----------------------------");
        Sleep(2000);
        printf("Name %s | Student Number: %i", OldStudent_Continuation.user_UserPersonalName, OldStudent_Continuation.user_StudentIdentity);
        printf("Your Current Level is %c", ENRL_Stats_CurrentLevel);
        printf("Enrollment Eligibility %c", ENRL_Stats_Eligible);
        for (Counter_For_Selection; Counter_For_Selection < 5; Counter_For_Selection++)
        {
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
int Func_AlgoStdnt_NumberCreate()
{
    SetConsoleTitle("LM Enrollment System | Generating Number Identity...");
    SYSTEMTIME Btch_Year;
    char Created_Student_NumData;
    GetLocalTime(&Btch_Year); // Win32 Module Function
    // Get Current Batch and Student Number
    printf("Created Student Number Data(Untouched) %d | ", Btch_Year.wYear); // Another Two Predicted Values are Btch_Num,Btch_StudentNum.
    return Created_Student_NumData;
}
void Func_NewStdnt_ERLM()
{
    struct New_StudentRecords NewData;
    int DataComplete = 0, Choice_Break = 0, Choice_FillInfo = 0;

    char Confirmation_Exit;

    long int std_PhoneNum = 0;
    long int std_MobileNum = 0;
    long int std_EmerNum = 0;

    system("CLS");
    SetConsoleTitle("New Student: Filling up Information | LM Enrollment System");
    puts("---------------------------------------------------------------------------------------------------");
    printf("--! 1st Step - Input your Personal Information | 2nd | 3rd | 4th | Confirm | End\n");
    printf("++ Information: Please provide your information to let us identify you as a future student!\n\n");
    printf("NOTE: Please input your information accurately!\n\n");
    puts("--- IDENTITY INFORMATION --------------------------------------------------------------------------");
    printf("\n [1] First Name |> ");
    fgets(NewData.stdnt_FName, sizeof(NewData.stdnt_FName), stdin);
    printf("\n [2] Middle Name |> ");
    fgets(NewData.stdnt_MName, sizeof(NewData.stdnt_MName), stdin);
    printf("\n [3] Last Name |> ");
    fgets(NewData.stdnt_LName, sizeof(NewData.stdnt_LName), stdin);
    printf("\n");
    puts("--- GENERAL INFORMATION ---------------------------------------------------------------------------");
    printf("\n [4] Gender |> ");
    fgets(NewData.stdnt_Gender, sizeof(NewData.stdnt_Gender), stdin);
    printf("\n [5] Birthday |> ");
    fgets(NewData.stdnt_Birthday, sizeof(NewData.stdnt_Birthday), stdin);
    printf("\n [6] Home (Main) Address |> "); //Include City and Village, ZIP CODE
    fgets(NewData.stdnt_Address, sizeof(NewData.stdnt_Address), stdin);
    printf("\n [7] Nationality |> ");
    fgets(NewData.stdnt_Nationality, sizeof(NewData.stdnt_Nationality), stdin);

    printf("\n");
    puts("--- TECHNICAL INFORMATION -------------------------------------------------------------------------");
    printf("\n [8] Mobile Number |> ");
    scanf("%11ld", &NewData.stdnt_MobileNum);
    printf("\n [9] Phone Number |> ");
    scanf("%11ld", &NewData.stdnt_PhoneNum);
    printf("\n [10] Emergency Number and Emergency Point of Contact (Seperated)\n");
    printf("\n [10.1] Input Emergency Number |> ");
    scanf("%11ld", &NewData.stdnt_EmerNum);
    fflush(stdin);
    printf("\n [10.2] Input Name Emergency Point of Contact |> ");
    fgets(NewData.stdnt_POC_Emergency, sizeof(NewData.stdnt_POC_Emergency), stdin);
    printf("\n [11] Personal Email |> ");
    fgets(NewData.stdnt_Email, sizeof(NewData.stdnt_Email), stdin);
    printf("\n [12] Behavioral Issues |> ");
    fgets(NewData.stdnt_SpecialBehavioral, sizeof(NewData.stdnt_SpecialBehavioral), stdin);
    printf("\n");
    puts("--- USER INPUT DONE ------------------------------------------------------------------------------------");
    Sleep(2000);
    DataReceiver(NewData);
}

int DataReceiver(struct New_StudentRecords NewData_Receiver)
{
    char Data_Confirmation;
    system("CLS");
    puts("--- USER INPUT CHECKPOINT ------------------------------------------------------------------------------------");
    printf("\n");
    printf("Is the following data inputted is correct?\n");
    printf("\n [1] First Name: %s", NewData_Receiver.stdnt_FName);
    printf(" [2] Middle Name: %s", NewData_Receiver.stdnt_MName);
    printf(" [3] Last Name: %s", NewData_Receiver.stdnt_LName);
    printf("\n");
    puts("--- GENERAL INFORMATION ---------------------------------------------------------------------------");
    printf("\n");
    printf(" [4] Gender: %s", NewData_Receiver.stdnt_Gender);
    printf(" [5] Birthday: %s", NewData_Receiver.stdnt_Birthday);
    printf(" [6] Home (Main) Address: %s", NewData_Receiver.stdnt_Address); //Include City and Village, ZIP CODE
    printf(" [7] Nationality: %s", NewData_Receiver.stdnt_Nationality);
    printf("\n");
    puts("--- TECHNICAL INFORMATION -------------------------------------------------------------------------");
    printf("\n");
    printf(" [8] Mobile Number: %ld", NewData_Receiver.stdnt_MobileNum);
    printf(" [9] Phone Number: %ld\n", NewData_Receiver.stdnt_PhoneNum);
    printf(" [10] Emergency Number and Emergency Point of Contact (Seperated)): %ld | %s", NewData_Receiver.stdnt_EmerNum, NewData_Receiver.stdnt_POC_Emergency);
    printf(" [11] Personal Email: %s", NewData_Receiver.stdnt_Email);
    printf(" [12] Behavioral Issues: %s\n\n", NewData_Receiver.stdnt_SpecialBehavioral);
    puts("--- USER INPUT CHECKPOINT ------------------------------------------------------------------------------------");
    Data_Confirmation = getchar();
    if (Data_Confirmation == 'Y' || Data_Confirmation == 'y')
    {
        return EXIT_SUCCESS;
    }
    else if (Data_Confirmation == 'N' || Data_Confirmation == 'n')
    {
        fflush(stdin); // To Avoid \n to be fed in fgets;
        printf("Returning To Step 1: Filling up Personal Information");
        Sleep(3000);
        Func_NewStdnt_ERLM();
    }
    else
    {
        printf("ERROR: Invalid Character...");
        Sleep(2000);
        DataReceiver(NewData_Receiver);
    }
