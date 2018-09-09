#include <stdio.h>   // Just Basic Input Output Header File
#include <stdlib.h>  // For SYSTEM Command
#include <conio.h>   // For Getch()
#include <windows.h> // Windows Designed Only Header, This Rips Compatibility.
#include <time.h>    // For Time Display and Such
#include <string.h>  // String Handling for Usage of Structure and Database

// Defined STRINGS, Call this and the string will show up or error code
#define VERSION_NUMBER "0941-09062018-BETA"
#define PRODUCT_NAME "Team LM | Enrollment System for TiP Engineering and Architecture | C CLI Runtime"
#define FUNCTION_UNFINISHED 1362565
#define DATABASE_NOT_FOUND 40
#define FUNCTION_LINEAR_DISCONTINUE 1827090918
#define FUNCTION_STEP1 "Team LM | Enrollment System for TiP Engineering and Architecture | C CLI Runtime \xAF [ \xDD [1st Step \xAF Filling up Information] | 2nd | 3rd | 4th | 5th | Confirm | End]"
#define FUNCTION_STEP2 "Team LM | Enrollment System for TiP Engineering and Architecture | C CLI Runtime \xAF [1st | \xDD [2nd Step \xAF Course Registration] | 3rd | 4th | 5th | Confirm | End]"
#define FUNCTION_STEP2_1 "Team LM | Enrollment System for TiP Engineering and Architecture | C CLI Runtime \xAF [1st | \xDD [2nd Step \xAF Course Registration \xAF Year Selection] | 3rd | 4th | 5th | Confirm | End]"
#define FUNCTION_STEP3 "Team LM | Enrollment System for TiP Engineering and Architecture | C CLI Runtime \xAF [1st | 2nd | \xDD [3rd \xAF Subject Enrollment Selection] | 4th | 5th | Confirm | End]"
#define FUNCTION_STEP4 "Team LM | Enrollment System for TiP Engineering and Architecture | C CLI Runtime \xAF [1st | 2nd | [3rd] | \xDD[4th \xAF] | 5th | Confirm | End]"
#define FUNCTION_STEP5 "Team LM | Enrollment System for TiP Engineering and Architecture | C CLI Runtime \xAF [1st | 2nd | 3rd | 4th | \xDD[5th \xAF] | Confirm | End]"
#define FUNCTION_STEP6 "Team LM | Enrollment System for TiP Engineering and Architecture | C CLI Runtime \xAF [1st | 2nd | 3rd | 4th | 5th | \xDD [Confirmation] | End]"
#define FUNCTION_STEP7 "Team LM | Enrollment System for TiP Engineering and Architecture | C CLI Runtime \xAF [1st | 2nd | 3rd | 4th | 5th | Confirm | \xDD [End Process]"

// Structure Variables for New Student, Used For Filling Information
// After Function Update On Function...
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
        stdnt_POC_Emergency[30],
        MainCourse_CodeName_Passer[40],
        MainCourse_FullName_Passer[40],
        Course_YearChoice[20],
        Course_SemSelection[20];
    long long int stdnt_PhoneNum, stdnt_MobileNum, stdnt_EmerNum;
};
// Structure For Old Student Checker Credentials
struct Old_StudentRecords
{
    int stdnt_old_StudentIdentity;
    char stdnt_old_Username[20], stdnt_old_Password[32], stdnt_old_UserPersonalName[20];
};
// used To Receive Only True
struct Enrollment_InformationReceiver
{
    char *Subject_CodeName_Receiver[12];
    char *Subject_FullName_Receiver[12];
    char *Subject_Include_Receiver[12];
    char *Subject_LinearTime_Receiver[12];
};
/*struct Subject_ContainerData {
    char *Subject_CodeName[12];
    char *Subject_FullName[12];
    char *Subject_Parameters[2];
    char *Subject_LinearTime[12];
    char *SbjSel_Stats[12];
};*/
struct New_StudentRecords NewStudent_Data;
struct Enrollment_InformationReceiver ReceiverData;

void gotoxy(int x, int y); //Custom Function To Call Gotoxy. @Conio.h cannot be used for Windows.
int Main_Menu();           // Call For Main Menu
void Func_OldStdnt_ERLM(); // Old Student Function Prototype
int Func_OldStd_ERLM_Menu(struct Old_StudentRecords OldData);
//Function Prototype on Ascending Order
void Func_NewStdnt_FillUp();
int Func_NewStdnt_InfoCheck();
int Func_NewStdnt_CourseReg();
int Func_NewStdnt_Eng_YearSemSelect();
//int Func_NewStdnt_Arch_YearSemSelect(char *MainCourse_CodeName_Passer);
int Func_NewStdnt_Eng_Subject_Select();  // Seperated To Differentiate it's Options
int Func_NewStdnt_Arch_Subject_Select(); // Seperated To Differentiate it's Options
int Func_SubjectUnit_Selection(char **Subject_CodeName, char **Subject_FullName, char **Subject_LinearTime, int Subject_Units[12], int Subject_WholeSize);
//int Func_Stdnt_ScholarshipCheck(/*struct Enrollment_InformationReceiver Data_Received, int Final_Comp_SelectedSubjects*/);
void Func_Mode_Of_Payment();
void PrintDocument_FinalTranscript(/*struct New_StudentRecords NewData_Receiver*/);
void Func_ERLM_Recheck();

//int ReceiveData();

int main()
{
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SHOW_FULLSCREEN); // Temporarily Commented due to Terminal Shows CMD but Small Font
    Main_Menu();
}
int Main_Menu()
{
    SetConsoleTitle(PRODUCT_NAME);
    system("CLS");
    while (1)
    { // This will loop forever because wtf is 1?
        int Selection_1 = 0;
        system("CLS");
        gotoxy(30, 3);
        printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        gotoxy(30, 4);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        gotoxy(30, 5);
        printf("\xBA \xDD Version " VERSION_NUMBER "\t\t\t\t\t\t\t\t\t       \xBA");
        gotoxy(30, 6);
        printf("\xBA \xDD " PRODUCT_NAME "\t\t       \xBA");
        gotoxy(30, 7);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        gotoxy(30, 8);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        gotoxy(30, 10);
        printf("\xC9\xCD\xCD \xDD Main Menu \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        gotoxy(30, 11);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        gotoxy(30, 12);
        printf("\xBA [1] \xDD Old Student\t\t\t\t\t\t\t\t\t\t       \xBA");
        gotoxy(30, 13);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        gotoxy(30, 14);
        printf("\xBA [2] \xDD New Student\t\t\t\t\t\t\t\t\t\t       \xBA");
        gotoxy(30, 15);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        gotoxy(30, 16);
        printf("\xBA [3] \xDD Reprint Enrollment Student Form | Registration Form\t\t\t\t\t       \xBA");
        gotoxy(30, 17);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        gotoxy(30, 18);
        printf("\xBA [4] \xDD Manage Enrollment\t\t\t\t\t\t\t\t\t\t       \xBA");
        gotoxy(30, 19);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        gotoxy(30, 20);
        printf("\xBA [5] \xDD Exit Application\t\t\t\t\t\t\t\t\t\t       \xBA");
        gotoxy(30, 21);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        gotoxy(30, 22);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        gotoxy(30, 24);
        printf("\xC8\xAF Please enter your decision [1 - 5] \xDD\xAF ");
        switch (Selection_1 = getche())
        {
        case '1':
            Func_OldStdnt_ERLM();
            break;
        case '2':
            Func_NewStdnt_FillUp();
            break;
        case '3':
            Func_ERLM_Recheck();
            break;
        case '4':
            gotoxy(30, 26);
            printf("\xC9\xCD\xCD \xDD Warning! \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
            gotoxy(30, 27);
            printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
            gotoxy(30, 28);
            printf("\xBA Access Denied! Please rerun the program with '/mgr_md' in order to access this function!\t       \xBA");
            gotoxy(30, 29);
            printf("\xBA Press any key to terminate the program...\t\t\t\t\t\t\t       \xBA");
            gotoxy(30, 30);
            printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
            gotoxy(30, 31);
            printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
            getch();
            exit(0); // Gracefully Terminate A Program / Process
        case '5':
            SetConsoleTitle("Terminating Enrollment System | LM Enrollment System");
            gotoxy(30, 26);
            printf("\xC9\xCD\xCD \xDD Information \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
            gotoxy(30, 27);
            printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
            gotoxy(30, 28);
            printf("\xBA \xAF Terminating LM Enrollment System...\t\t\t\t\t\t\t\t       \xBA");
            gotoxy(30, 29);
            printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
            gotoxy(30, 30);
            printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
            Sleep(2500);
            return EXIT_SUCCESS;
        case '6':
            //Func_SubjectUnit_Selection();
        default:
            gotoxy(30, 26);
            printf("\xC9\xCD\xCD \xDD Warning! \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
            gotoxy(30, 27);
            printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
            gotoxy(30, 28);
            puts("\xBA \xAF Unrecognized Input!\t\t\t\t\t\t\t\t\t\t       \xBA");
            gotoxy(30, 29);
            printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
            gotoxy(30, 30);
            printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
            Sleep(1500);
            continue;
        }
    }
}
void Func_OldStdnt_ERLM()
{
    struct Old_StudentRecords OldData;
    FILE *FileDatabase_ERLM;
    char datapoint_ERLM[] = "data/2018_LM_Database_Enrollment.dat";
    while (1)
    {
        system("CLS");
        SetConsoleTitle("LM Enrollment System | Old Student Login");
        printf("Please enter your Username: ");
        scanf("%s", OldData.stdnt_old_Username);
        printf("Please enter your Password: ");
        scanf("%s", OldData.stdnt_old_Password);
        printf("Please enter your Student Number: ");
        scanf("%d", &OldData.stdnt_old_StudentIdentity);
        //if (//strcmp() == 0)
        //)
        //{

        //} else {
        Func_OldStdnt_ERLM();
        //}
        //printf("Hello %s | %d!\n", OldStudent.user_Username, OldStudent.user_StudentIdentity);
        //printf("Also your password is %s\n", OldStudent.user_Password);
        Func_OldStd_ERLM_Menu(OldData);
    }
}

int Func_OldStd_ERLM_Menu(struct Old_StudentRecords OldStudent_Continuation)
{
    FILE *FileDatabase_ERLM;
    char datapoint_ERLM[] = "data/2018_LM_Database_Enrollment.dat";
    FileDatabase_ERLM = fopen(datapoint_ERLM, "rb");
    if (FileDatabase_ERLM == NULL)
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
        printf("Hello and Welcome %c", OldStudent_Continuation.stdnt_old_StudentIdentity);
        printf("-----------------------------");
        Sleep(2000);
        printf("Name %s | Student Number: %i", OldStudent_Continuation.stdnt_old_UserPersonalName, OldStudent_Continuation.stdnt_old_StudentIdentity);
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

/////////////////////////////////////////////////////////////////////////////////////
void Func_NewStdnt_FillUp()
{
    // Initialize This From Struct Variable
    NewStudent_Data.stdnt_PhoneNum = 0;
    NewStudent_Data.stdnt_MobileNum = 0;
    NewStudent_Data.stdnt_EmerNum = 0;
    system("CLS");
    SetConsoleTitle(FUNCTION_STEP1);
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
    gotoxy(30, 4);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    gotoxy(30, 5);
    printf("\xBA [ \xDD [1st Step \xAF Filling up Information] | 2nd | 3rd | 4th | 5th | Confirm | End]\t\t           \xBA\n");
    gotoxy(30, 6);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    gotoxy(30, 7);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
    gotoxy(30, 9);
    printf("\xC9\xCD\xCD \xDD Information \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
    gotoxy(30, 10);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    gotoxy(30, 11);
    printf("\xBA \xAF Please provide your information to let us identify you as a future student!\t\t\t\t   \xBA");
    gotoxy(30, 12);
    printf("\xBA \xDD NOTE \xDD \xAF Please input your information accurately!\t\t\t\t\t\t\t   \xBA");
    gotoxy(30, 13);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    gotoxy(30, 14);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
    gotoxy(30, 16);
    printf("\xFE\xCD\xCD IDENTITY INFORMATION \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    gotoxy(30, 18);
    printf("  [1] First Name \xDD\xAF ");
    fgets(NewStudent_Data.stdnt_FName, sizeof(NewStudent_Data.stdnt_FName), stdin);
    strtok(NewStudent_Data.stdnt_FName, "\n");
    gotoxy(30, 20);
    printf("  [2] Middle Name \xDD\xAF ");
    fgets(NewStudent_Data.stdnt_MName, sizeof(NewStudent_Data.stdnt_MName), stdin);
    strtok(NewStudent_Data.stdnt_MName, "\n");
    gotoxy(30, 22);
    printf("  [3] Last Name \xDD\xAF ");
    fgets(NewStudent_Data.stdnt_LName, sizeof(NewStudent_Data.stdnt_LName), stdin);
    strtok(NewStudent_Data.stdnt_LName, "\n");
    gotoxy(30, 24);
    printf("\xFE\xCD\xCD GENERAL INFORMATION \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    gotoxy(30, 26);
    printf("  [4] Gender \xDD\xAF ");
    fgets(NewStudent_Data.stdnt_Gender, sizeof(NewStudent_Data.stdnt_Gender), stdin);
    strtok(NewStudent_Data.stdnt_Gender, "\n");
    gotoxy(30, 28);
    printf("  [5] Birthday \xDD\xAF ");
    fgets(NewStudent_Data.stdnt_Birthday, sizeof(NewStudent_Data.stdnt_Birthday), stdin);
    strtok(NewStudent_Data.stdnt_Birthday, "\n");
    gotoxy(30, 30);
    printf("  [6] Home (Main) Address \xDD\xAF "); //Include City and Village, ZIP CODE
    fgets(NewStudent_Data.stdnt_Address, sizeof(NewStudent_Data.stdnt_Address), stdin);
    strtok(NewStudent_Data.stdnt_Address, "\n");
    gotoxy(30, 32);
    printf("  [7] Nationality \xDD\xAF ");
    fgets(NewStudent_Data.stdnt_Nationality, sizeof(NewStudent_Data.stdnt_Nationality), stdin);
    strtok(NewStudent_Data.stdnt_Nationality, "\n");
    printf("\n");
    gotoxy(30, 34);
    printf("\xFE\xCD\xCD TECHNICAL INFORMATION \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    gotoxy(30, 36);
    printf("  [8] Mobile Number \xDD\xAF ");
    scanf("%lld", &NewStudent_Data.stdnt_MobileNum);
    gotoxy(30, 38);
    printf("  [9] Phone Number \xDD\xAF ");
    scanf("%lld", &NewStudent_Data.stdnt_PhoneNum);
    gotoxy(30, 40);
    printf("  [10] Emergency Number and Emergency Point of Contact (Seperated)");
    gotoxy(30, 42);
    printf("  [10.1] Input Emergency Number \xDD\xAF ");
    scanf("%lld", &NewStudent_Data.stdnt_EmerNum);
    gotoxy(30, 44);
    fflush(stdin); // UNDEFINED BEHAVIOR BUT NEEDED TO REMOVE \0 AT THE END OF THE SCANF INPUT
    printf("  [10.2] Input Name Emergency Point of Contact \xDD\xAF ");
    fgets(NewStudent_Data.stdnt_POC_Emergency, sizeof(NewStudent_Data.stdnt_POC_Emergency), stdin);
    strtok(NewStudent_Data.stdnt_POC_Emergency, "\n");
    gotoxy(30, 46);
    printf("  [11] Personal Email \xDD\xAF ");
    fgets(NewStudent_Data.stdnt_Email, sizeof(NewStudent_Data.stdnt_Email), stdin);
    strtok(NewStudent_Data.stdnt_Email, "\n");
    gotoxy(30, 48);
    printf("  [12] Behavioral Issues \xDD\xAF ");
    fgets(NewStudent_Data.stdnt_SpecialBehavioral, sizeof(NewStudent_Data.stdnt_SpecialBehavioral), stdin);
    strtok(NewStudent_Data.stdnt_SpecialBehavioral, "\n");
    gotoxy(30, 50);
    printf("\xFE\xCD\xCD USER INPUT DONE \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    Sleep(2000);
    Func_NewStdnt_InfoCheck();
}

int Func_NewStdnt_InfoCheck()
{
    char Data_Confirmation;
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
    gotoxy(30, 4);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    gotoxy(30, 5);
    printf("\xBA [ \xDD [1st Step \xAF Student Data Information Check] | 2nd | 3rd | 4th | 5th | Confirm | End]\t\t   \xBA\n");
    gotoxy(30, 6);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    gotoxy(30, 7);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
    gotoxy(30, 9);
    printf("\xFE\xCD\xCD GENERAL INFORMATION \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    gotoxy(30, 11);
    printf("\xBA [1] First Name \xDD\xAF %s", NewStudent_Data.stdnt_FName);
    gotoxy(30, 13);
    printf("\xBA [2] Middle Name \xDD\xAF %s", NewStudent_Data.stdnt_MName);
    gotoxy(30, 15);
    printf("\xBA [3] Last Name \xDD\xAF %s", NewStudent_Data.stdnt_LName);
    gotoxy(30, 17);
    printf("\xFE\xCD\xCD IDENTITY INFORMATION \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    gotoxy(30, 19);
    printf("\xBA [4] Gender \xDD\xAF %s", NewStudent_Data.stdnt_Gender);
    gotoxy(30, 21);
    printf("\xBA [5] Birthday \xDD\xAF %s", NewStudent_Data.stdnt_Birthday);
    gotoxy(30, 23);
    printf("\xBA [6] Home (Main) Address \xDD\xAF %s", NewStudent_Data.stdnt_Address); //Include City and Village, ZIP CODE
    gotoxy(30, 25);
    printf("\xBA [7] Nationality \xDD\xAF %s", NewStudent_Data.stdnt_Nationality);
    gotoxy(30, 27);
    printf("\xFE\xCD\xCD TECHNICAL INFORMATION \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    gotoxy(30, 29);
    printf("\xBA [8] Mobile Number \xDD\xAF %lld", NewStudent_Data.stdnt_MobileNum);
    gotoxy(30, 31);
    printf("\xBA [9] Phone Number \xDD\xAF %lld", NewStudent_Data.stdnt_PhoneNum);
    gotoxy(30, 33);
    printf("\xBA [10] Emergency Number and Emergency Point of Contact \xDD\xAF %lld \xDD %s", NewStudent_Data.stdnt_EmerNum, NewStudent_Data.stdnt_POC_Emergency);
    gotoxy(30, 35);
    printf("\xBA [11] Personal Email \xDD\xAF %s", NewStudent_Data.stdnt_Email);
    gotoxy(30, 37);
    printf("\xBA [12] Behavioral Issues \xDD\xAF %s", NewStudent_Data.stdnt_SpecialBehavioral);
    gotoxy(30, 39);
    printf("\xC9\xCD\xCD \xDD Question \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
    gotoxy(30, 40);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    gotoxy(30, 41);
    printf("\xBA \xAF Are the sure the following encoded data is correct and accurate?\t\t\t\t\t   \xBA");
    gotoxy(30, 42);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    gotoxy(30, 43);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
    gotoxy(30, 45);
    printf("\xC8\xAF Press a key for your desired decision [|Y|es or |N|o] \xDD\xAF ");
    Data_Confirmation = getche();
    if (Data_Confirmation == 'Y' || Data_Confirmation == 'y')
    {
        gotoxy(30, 45);
        printf("\xAF \xDD INFO \xDD Data Received, Proceeding to Step 2 \xDD Course Registration...");
        Sleep(2000);
        Func_NewStdnt_CourseReg();
    }
    else if (Data_Confirmation == 'N' || Data_Confirmation == 'n')
    {
        gotoxy(30, 45);
        printf("\xAF \xDD INFO \xDD Returning To Step 1 \xDD Filling up Personal Information...");
        Sleep(3000);
        Func_NewStdnt_FillUp();
    }
    else
    {
        gotoxy(30, 47);
        printf("\xAF \xDD ERROR \xDD Unrecognized Input!");
        Sleep(2000);
        Func_NewStdnt_InfoCheck();
    }
}

int Func_NewStdnt_CourseReg()
{
    SetConsoleTitle(FUNCTION_STEP2);
    system("CLS");
    int BranchBase_Accepter = 0, MainCourse_Accepter = 0;
    char *MainCourse_CodeName[8] = {"BSCE", "BSCpE", "BSEE", "BSECE", "BSEnSE", "BSIE", "BSME", "Arch"};
    char *MainCourse_FullName[8] = {"Civil Engineering", "Computer Engineering", "Electrical Engineering", "Electronics Engineering", "Environmental and Sanitary Engineering", "Industrial Engineering", "Mechanical Engineering", "Architecture"};
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
    gotoxy(30, 4);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    gotoxy(30, 5);
    printf("\xBA \xDD [2nd Step \xAF Course Registration] | 3rd | 4th | 5th | Confirm | End]\t\t\t\t\t   \xBA"); //3RD IS SCHOLARSHIP, 4TH IS MODE OF PAYMENT
    gotoxy(30, 6);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    gotoxy(30, 7);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
    gotoxy(30, 9);
    printf("\xC9\xCD\xCD \xDD Information \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
    gotoxy(30, 10);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    gotoxy(30, 11);
    printf("\xBA Please fill up your course to take and year that you want to take into.\t\t\t\t           \xBA");
    gotoxy(30, 12);
    printf("\xBA \xDD NOTE \xDD \xAF Please choose your course wisely, there is no going back!\t\t\t\t\t   \xBA");
    gotoxy(30, 13);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    gotoxy(30, 14);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
    gotoxy(30, 16);
    printf("\xC9\xCD\xCD \xDD PLEASE CHOOSE A BRANCH BASE COURSE \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
    gotoxy(30, 17);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    gotoxy(30, 18);
    printf("\xBA \t[1] \xDD College of Engineering \t\t       \xDD\t [2] \xDD College of Architecture\t\t   \xBA");
    gotoxy(30, 19);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    gotoxy(30, 20);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
    gotoxy(30, 22);
    printf("\xC8\xAF Press a key for your desired decision [1 - 2] \xDD\xAF ");
    switch (BranchBase_Accepter = getche())
    {
    case '1':
        system("CLS");
        gotoxy(30, 3);
        printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        gotoxy(30, 4);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 5);
        printf("\xBA \xDD [2nd Step \xAF Course Registration] | 3rd | 4th | 5th | Confirm | End]\t\t\t\t\t   \xBA"); //3RD IS SCHOLARSHIP, 4TH IS MODE OF PAYMENT
        gotoxy(30, 6);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 7);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        gotoxy(30, 9);
        printf("\xC9\xCD\xCD CHOICE YOUR MAIN / DESIRED COURSE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        gotoxy(30, 10);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 11);
        printf("\xBA \xAF [1] \xDD %s \xDD %s\t\t\t\t\t\t\t\t\t   \xBA", MainCourse_FullName[0], MainCourse_CodeName[0]);
        gotoxy(30, 12);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 13);
        printf("\xBA \xAF [2] \xDD %s \xDD %s\t\t\t\t\t\t\t\t\t   \xBA", MainCourse_FullName[1], MainCourse_CodeName[1]);
        gotoxy(30, 14);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 15);
        printf("\xBA \xAF [3] \xDD %s \xDD %s\t\t\t\t\t\t\t\t\t   \xBA", MainCourse_FullName[2], MainCourse_CodeName[2]);
        gotoxy(30, 16);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 17);
        printf("\xBA \xAF [4] \xDD %s \xDD %s\t\t\t\t\t\t\t\t\t   \xBA", MainCourse_FullName[3], MainCourse_CodeName[3]);
        gotoxy(30, 18);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 19);
        printf("\xBA \xAF [5] \xDD %s \xDD %s\t\t\t\t\t\t\t   \xBA", MainCourse_FullName[4], MainCourse_CodeName[4]);
        gotoxy(30, 20);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 21);
        printf("\xBA \xAF [6] \xDD %s \xDD %s\t\t\t\t\t\t\t\t\t   \xBA", MainCourse_FullName[5], MainCourse_CodeName[5]);
        gotoxy(30, 22);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 23);
        printf("\xBA \xAF [7] \xDD %s \xDD %s\t\t\t\t\t\t\t\t\t   \xBA", MainCourse_FullName[6], MainCourse_CodeName[6]);
        gotoxy(30, 24);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 25);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        gotoxy(30, 27);
        printf("\xC8\xAF Press a key for your desired decision [1 - 7] \xDD\xAF "); // Fix this also
        switch (MainCourse_Accepter = getche())
        {
        case '1':
            gotoxy(30, 27);
            printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding to Year Selection...", MainCourse_FullName[0]);
            Sleep(2000);
            strcpy(NewStudent_Data.MainCourse_CodeName_Passer, MainCourse_CodeName[0]);
            strcpy(NewStudent_Data.MainCourse_FullName_Passer, MainCourse_FullName[0]);
            Func_NewStdnt_Eng_YearSemSelect();
        case '2':
            gotoxy(30, 27);
            printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding to Year Selection...", MainCourse_FullName[1]);
            Sleep(2000);
            strcpy(NewStudent_Data.MainCourse_CodeName_Passer, MainCourse_CodeName[1]);
            strcpy(NewStudent_Data.MainCourse_FullName_Passer, MainCourse_FullName[1]);
            Func_NewStdnt_Eng_YearSemSelect();
        case '3':
            gotoxy(30, 27);
            printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding to Year Selection...", MainCourse_FullName[2]);
            Sleep(2000);
            strcpy(NewStudent_Data.MainCourse_CodeName_Passer, MainCourse_CodeName[2]);
            strcpy(NewStudent_Data.MainCourse_FullName_Passer, MainCourse_FullName[2]);
            Func_NewStdnt_Eng_YearSemSelect();
        case '4':
            gotoxy(30, 27);
            printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding to Year Selection...", MainCourse_FullName[3]);
            Sleep(2000);
            strcpy(NewStudent_Data.MainCourse_CodeName_Passer, MainCourse_CodeName[3]);
            strcpy(NewStudent_Data.MainCourse_FullName_Passer, MainCourse_FullName[3]);
            Func_NewStdnt_Eng_YearSemSelect();
        case '5':
            gotoxy(30, 27);
            printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding to Year Selection...", MainCourse_FullName[4]);
            Sleep(2000);
            strcpy(NewStudent_Data.MainCourse_CodeName_Passer, MainCourse_CodeName[4]);
            strcpy(NewStudent_Data.MainCourse_FullName_Passer, MainCourse_FullName[4]);
            Func_NewStdnt_Eng_YearSemSelect();
        case '6':
            gotoxy(30, 27);
            printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding to Year Selection...", MainCourse_FullName[5]);
            Sleep(2000);
            strcpy(NewStudent_Data.MainCourse_CodeName_Passer, MainCourse_CodeName[5]);
            strcpy(NewStudent_Data.MainCourse_FullName_Passer, MainCourse_FullName[5]);
            Func_NewStdnt_Eng_YearSemSelect();
        case '7':
            gotoxy(30, 27);
            printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding to Year Selection...", MainCourse_FullName[6]);
            Sleep(2000);
            strcpy(NewStudent_Data.MainCourse_CodeName_Passer, MainCourse_CodeName[6]);
            strcpy(NewStudent_Data.MainCourse_FullName_Passer, MainCourse_FullName[6]);
            Func_NewStdnt_Eng_YearSemSelect();
        }
    case '2':
        gotoxy(30, 27);
        printf("\xAF \xDD INFO \xDD Architecture is already declared as main course. Proceeding to Year Selection!");
        Sleep(2000);
        strcpy(NewStudent_Data.MainCourse_CodeName_Passer, MainCourse_CodeName[7]);
        strcpy(NewStudent_Data.MainCourse_FullName_Passer, MainCourse_FullName[7]);
        //Func_NewStdnt_Arch_YearSemSelect();
    default:
        gotoxy(30, 27);
        printf("\xAF \xDD ERROR \xDD Unrecognized Input!"); //FIX THE OUTPUT OF THIS ONE
        Sleep(2000);
        Func_NewStdnt_CourseReg();
    }
}
// Engineering Subject Set Functions
int Func_NewStdnt_Eng_YearSemSelect()
{
    SetConsoleTitle(FUNCTION_STEP2_1);
    system("CLS");
    int YearSelection_Accepter = 0, YearSelection_Accepter_Sem = 0, OldStudentParameter = 0;
    static long long int Old_StudentID = 0;
    char DataCheck;
    char *ERLM_Selection[5] = {"1st Year College", "2nd Year College", "3rd Year College", "4th Year College", "Architecture"};
    char *ERLM_Selection_Sem[2] = {"First Semester", "Second Semester"};
    if (OldStudentParameter == 1)
    {
        // Insert Check Database Here
    }
    else
    {
        if (Old_StudentID == 0)
        {
            Old_StudentID = 2018000;
        }
    }
    //Check At User.
    while (1)
    {
        fflush(stdin);
        gotoxy(30, 3);
        printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        gotoxy(30, 4);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 5);
        printf("\xBA [1st | \xDD [2nd Step \xAF Course Registration \xAF Year Selection] | 3rd | 4th | 5th | Confirm | End]\t           \xBA\n");
        gotoxy(30, 6);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 7);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        gotoxy(30, 9);
        printf("\xFE\xCD\xCD \xDD Current Choices \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
        gotoxy(30, 11);
        printf(" \xAF Course Name and Course Code \xAF %s \xDD %s", NewStudent_Data.MainCourse_CodeName_Passer, NewStudent_Data.MainCourse_FullName_Passer);
        gotoxy(30, 12);
        printf(" \xAF Student Name \xAF  %s, %s %s", NewStudent_Data.stdnt_LName, NewStudent_Data.stdnt_FName, NewStudent_Data.stdnt_MName);
        gotoxy(30, 13);
        printf(" \xAF Student Number \xAF %ld", Old_StudentID);
        gotoxy(30, 15);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        gotoxy(30, 17);
        printf("\xFF\xCD\xCD Selections \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFF");
        gotoxy(30, 18);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 19);
        printf("\xBA \xAF [1] 1st Year College \t\t\t\t \xBA");
        gotoxy(30, 20);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 21);
        printf("\xBA \xAF [2] 2nd Year College \t\t\t\t \xBA");
        gotoxy(30, 22);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 23);
        printf("\xBA \xAF [3] 3rd Year College \t\t\t\t \xBA");
        gotoxy(30, 24);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 25);
        printf("\xBA \xAF [4] 4th Year College \t\t\t\t \xBA");
        gotoxy(30, 26);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 27);
        printf("\xBA \xAF [5] 5th Year College \t\t\t\t \xBA");
        gotoxy(30, 28);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 29);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        gotoxy(30, 30);
        printf("\xC8\xAF Press a key for your Desired College Year Level [1 - 5] \xAF ");
        switch (YearSelection_Accepter = getche())
        {
        case '1':
            YearSelection_Accepter = 0;
            gotoxy(30, 32);
            printf("You have selected %s", ERLM_Selection[YearSelection_Accepter]);
            break;
        case '2':
            //(int)YearSelection_Accepter_Eng;
            YearSelection_Accepter = 1;
            gotoxy(30, 32);
            printf("You have selected %s", ERLM_Selection[YearSelection_Accepter]);
            break;
        case '3':
            //(int)YearSelection_Accepter_Eng;
            YearSelection_Accepter = 2;
            gotoxy(30, 32);
            printf("You have selected %s", ERLM_Selection[YearSelection_Accepter]);
            break;
        case '4':
            //(int)YearSelection_Accepter_Eng;
            YearSelection_Accepter = 3;
            gotoxy(30, 32);
            printf("You have selected %s", ERLM_Selection[YearSelection_Accepter]);
            break;
        case '5':
            //(int)YearSelection_Accepter_Eng;
            YearSelection_Accepter = 4;
            gotoxy(30, 32);
            printf("You have selected %s", ERLM_Selection[YearSelection_Accepter]);
            break;
        default:
            gotoxy(30, 32);
            printf("Your input is invalid from the choices...");
            Sleep(2000);
            break;
        }
        if (YearSelection_Accepter == 0 || YearSelection_Accepter == 1 || YearSelection_Accepter == 2 || YearSelection_Accepter == 3)
        {
            break;
        }
        else
        {
            continue;
        }
    }

    Sleep(2000);
    system("CLS");
    fflush(stdin);

    while (1)
    {
        system("CLS");
        printf("--! 1st | [2nd Step - Course Registration | Year Select] | 3rd | 4th | 5th | Confirm | End --!\n\n");
        printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n");
        printf("\tCODENAME\t|\tNAME\t");
        printf("%s\t | \t%s,%s %s\t\t", NewStudent_Data.MainCourse_CodeName_Passer, NewStudent_Data.stdnt_LName, NewStudent_Data.stdnt_FName, NewStudent_Data.stdnt_MName);
        printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n\n");
        fflush(stdin);
        printf("[1] | First Semester\n");
        printf("[2] | Second Semester\n");
        printf("Please choose your Desired Semester [1 - 2] \xAF ");
        switch (YearSelection_Accepter_Sem = getche())
        {
        case '1':
            YearSelection_Accepter_Sem = 0;
            printf("You have selected %s", ERLM_Selection_Sem[YearSelection_Accepter_Sem]);
            break;
        case '2':
            YearSelection_Accepter_Sem = 1;
            printf("You have selected %s", ERLM_Selection_Sem[YearSelection_Accepter_Sem]);
            break;
        default:
            printf("Your input is invalid from the choices...");
            Sleep(2000);
            break;
        }
        if (YearSelection_Accepter_Sem == 0 || YearSelection_Accepter_Sem == 1)
        {
            break;
        }
        else
        {
            continue;
        }
    }

    Sleep(2000);
    system("CLS");

    while (1)
    {
        printf("\xCD\xCD\xCD CONFIRMATION \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n\n");
        printf("Are you sure is this correct?\n\n");
        printf("\xCD\xCD COURSE NAME \t\t|\t\t YEAR LEVEL && SEMESTER \t\t|\t\t COURSE CODE \n");
        printf("%s \t\t|\t\t %s | %s \t\t|\t\t %s\n", NewStudent_Data.MainCourse_FullName_Passer, ERLM_Selection[YearSelection_Accepter], ERLM_Selection_Sem[YearSelection_Accepter_Sem], NewStudent_Data.MainCourse_CodeName_Passer);
        switch (DataCheck = getche())
        {
        case 'Y':
        case 'y':
            printf("Data Inputted | Yes. -> Going To The Next Step");
            // Pass This Already in Struct to lessen the difficutly to check what to pass when User Press 3 on Subject Unit Selection Function
            strcpy(NewStudent_Data.Course_YearChoice, ERLM_Selection[YearSelection_Accepter]);
            strcpy(NewStudent_Data.Course_SemSelection, ERLM_Selection_Sem[YearSelection_Accepter_Sem]);

            if (strcmp(NewStudent_Data.MainCourse_CodeName_Passer, "BSCE") == 0)
            {
                if (strcmp(NewStudent_Data.Course_YearChoice, "1st Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"ENGL 001", "FIL 001", "MATH 001", "MATH 002", "COE 001", "CHEM 001", " AR 001 ", " PE 001 ", " NSTP 001 ", " ----", " ----", " ----"};
                        char *Subject_FullName[12] = {"---------", "---------", "---------", "---------", "---------", "---------", "---------", "---------", "---------", "---------", "---------", "---------"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 1:30PM", "1:30PM - 2:30PM", "2:30PM - 3:30PM", "1:30PM - 4:30PM", "7:30AM - 9:30AM", "9:30AM - 12:00PM", "4:30PM - :5:30PM", "4:30PM - 6:30PM", "5:30PM - 6:30PM"};
                        int Subject_Units[12] = {3, 3, 3, 3, 1, 3, 0, 2, 3};
                        int Subject_WholeSize = 12;
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"ENGL 001", "FIL 001", "MATH 001", "MATH 002", "COE 001", "CHEM 001", " AR 001 ", " PE 001 ", " NSTP 001 ", " ----", " ----", " ----"};
                        char *Subject_FullName[12] = {"---------", "---------", "---------", "---------", "---------", "---------", "---------", "---------", "---------", "---------", "---------", "---------"};
                        char *Subject_LinearTime[12] = {"9:00AM - 9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 1:30PM", "1:30PM - 2:30PM", "2:30PM - 3:30PM", "1:30PM - 4:30PM", "7:30AM - 9:30AM", "9:30AM - 12:00PM", "4:30PM - :5:30PM", "4:30PM - 6:30PM", "5:30PM - 6:30PM"};
                        int Subject_Units[12] = {3, 3, 3, 3, 1, 3, 0, 2, 3};
                        int Subject_WholeSize = 12;
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
                else if (strcmp(NewStudent_Data.Course_YearChoice, "2nd Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {};
                        //char *Subject_FullName[12] = {};
                        //char *Subject_LinearTime[12] = {};
                        //int Subject_Units[12] = {};
                        //int Subject_WholeSize = ;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {};
                        //char *Subject_FullName[12] = {};
                        //char *Subject_LinearTime[12] = {};
                        //int Subject_Units[12] = {};
                        //int Subject_WholeSize = ;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
                else if (strcmp(NewStudent_Data.Course_YearChoice, "3rd Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {};
                        //char *Subject_FullName[12] = {};
                        //char *Subject_LinearTime[12] = {};
                        //int Subject_Units[12] = {};
                        //int Subject_WholeSize = ;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {};
                        //char *Subject_FullName[12] = {};
                        //char *Subject_LinearTime[12] = {};
                        //int Subject_Units[12] = {};
                        //int Subject_WholeSize = ;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
                else if (strcmp(NewStudent_Data.Course_YearChoice, "4th Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {};
                        //char *Subject_FullName[12] = {};
                        //char *Subject_LinearTime[12] = {};
                        //int Subject_Units[12] = {};
                        //int Subject_WholeSize = ;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {};
                        //char *Subject_FullName[12] = {};
                        //char *Subject_LinearTime[12] = {};
                        //int Subject_Units[12] = {};
                        //int Subject_WholeSize = ;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
            }
            else if (strcmp(NewStudent_Data.MainCourse_CodeName_Passer, "BSCpE") == 0)
            {
                if (strcmp(NewStudent_Data.Course_YearChoice, "1st Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {};
                        //char *Subject_FullName[12] = {};
                        //char *Subject_LinearTime[12] = {};
                        //int Subject_Units[12] = {};
                        //int Subject_WholeSize = ;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {};
                        //char *Subject_FullName[12] = {};
                        //char *Subject_LinearTime[12] = {};
                        //int Subject_Units[12] = {};
                        //int Subject_WholeSize = ;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize)
                    }
                }
                else if (strcmp(NewStudent_Data.Course_YearChoice, "2nd Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {};
                        //char *Subject_FullName[12] = {};
                        //char *Subject_LinearTime[12] = {};
                        //int Subject_Units[12] = {};
                        //int Subject_WholeSize = ;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {};
                        //char *Subject_FullName[12] = {};
                        //char *Subject_LinearTime[12] = {};
                        //int Subject_Units[12] = {};
                        //int Subject_WholeSize = ;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
                else if (strcmp(NewStudent_Data.Course_YearChoice, "3rd Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {};
                        //char *Subject_FullName[12] = {};
                        //char *Subject_LinearTime[12] = {};
                        //int Subject_Units[12] = {};
                        //int Subject_WholeSize = ;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {};
                        //char *Subject_FullName[12] = {};
                        //char *Subject_LinearTime[12] = {};
                        //int Subject_Units[12] = {};
                        //int Subject_WholeSize = ;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
                else if (strcmp(NewStudent_Data.Course_YearChoice, "4th Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {};
                        //char *Subject_FullName[12] = {};
                        //char *Subject_LinearTime[12] = {};
                        //int Subject_Units[12] = {};
                        //int Subject_WholeSize = ;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {};
                        //char *Subject_FullName[12] = {};
                        //char *Subject_LinearTime[12] = {};
                        //int Subject_Units[12] = {};
                        //int Subject_WholeSize = ;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
            }
            else if (strcmp(NewStudent_Data.MainCourse_CodeName_Passer, "BSEE") == 0)
            {
                if (strcmp(NewStudent_Data.Course_YearChoice, "1st Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"CHEM 001", "COE 001", "CPE 001", "ENGL 001", "FIL 001", "MATH 001", "MATH 002", "PE 001", "NSTP 001"};
                        //char *Subject_FullName[12] = {"GENERAL CHEMISTRY", "ENGINEERING ORIENTATION", "COMPUTER FUNDAMENTALS", "COMMUNICATION ARTS 1", "KOMUNIKASYON SA AKADEMIKONG FILIPINO", "COLLEGE ALGEBRA", "PLANE AND SPHERICAL TRIGONOMETRY", "PHYSICAL FITNESS", "NATIONAL SERVICE TRAINING PROGRAM 1"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM"};
                        //int Subject_Units[12] = {4, 1, 1, 3, 3, 3, 3, 2, 3};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"AR 001", "ENGL 002", "FIL 002", "HUM 001", "HUM 002", "MATH 003", "MATH 004", "MATH 005", "PE 002", "NSTP 002"};
                        //char *Subject_FullName[12] = {"ENGINEERING DRAWING", "COMMUNICATION ARTS 2", "PAGBASA AT PAGSULAT TUNGO SA PANANALIKSIK", "INTRODUCTION TO PHILOSOPHY", "LOGIC", "ADVANCED ALGEBRA", "ANALYTIC GEOMETRY", "SOLID MENSURATION", "RHYTHMIC ACTIVITIES", "NATIONAL SERVICE TRAINING PROGRAM 2"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM", "6:00PM - 7:00PM"};
                        //int Subject_Units[12] = {1, 3, 3, 3, 3, 2, 3, 2, 2, 3};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
                else if (strcmp(NewStudent_Data.Course_YearChoice, "2nd Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"CHEM 002", "CS 100A", "ENGL 003", "MATH 006", "MATH 007", " SOCSC 001", "SOCSC 002", "PE 003"};
                        //char *Subject_FullName[12] = {"ENVIRONMENTAL ENGINEERING", "FUNDAMENTALS OF PROGRAMMING AND ALGORITHM", "TECHNICAL COMMUNICATIONS", "DISCRETE MATHEMATICS", "DIFFERENTIAL CALCULUS", "ECONOMICS, AGRARIAN REFORM AND TAXATIONS", "SOCIETY AND CULTURE WITH FAMILY PLANNING", "INDIVIDUAL/DUAL SPORTS"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        //int Subject_Units[12] = {3, 2, 3, 3, 4, 3, 3, 2};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"HUM 003", "MATH 008", "MATH 009", "PHYS 001", "SOCSC 003", "SOCSC 004", "PE 004"};
                        //char *Subject_FullName[12] = {"ETHICS", "INTEGRAL CALCULUS", "PROBABILITY AND STATISTICS", "CALCULUS-BASED PHYSICS 1", "PHILIPPINES HISTORY WITH POLITICS AND GOVERNANCE", "GENERAL PSYCHOLOGY", "SPORTS AND GAMES"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        //int Subject_Units[12] = {3, 4, 3, 4, 3, 3, 2};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
                else if (strcmp(NewStudent_Data.Course_YearChoice, "3rd Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"CE 001", "CPE 003", "1E 001", "1E 002", "MATH 010", "ME 005", "PHYS 002", "SOCSC 005", "EE 300"};
                        //char *Subject_FullName[12] = {"STATICS OF RIGID BODIES", "COMPUTER-AIDED DRAFTING", "SAFETY MANAGEMENT", "DIFFERENTIAL EQUATIONS", "ENGINEERING ECONOMY", "CALCULUS-BASED PHYSICS 2", "LIFE AND WORKS OF RIZAL", "RESEARCH METHODS"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM"};
                        //int Subject_Units[12] = {3, 1, 3, 2, 3, 3, 4, 3, 1};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"EE 002", "EE 301", "EE 302", "ECE 001", "ECE 302", "CE 002", "CE 003A", "MATH 011", "ME 004"};
                        //char *Subject_FullName[12] = {"ELECTRICAL CIRCUITS 1", "INTEGRATION COURSE FOR MATHEMATICS", "ELECTRICAL ENGINEERING SAFETY", "ELECTRONIC DEVICES AND CIRCUITS", "ELECTROMAGNETICS", "DYNAMICS OF RIGID BODIES", "MECHANICS OF DEFORMABLE BODIES", "ADVANCED ENGINEERING MATHEMATICS", "THERMODYNAMICS 1"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM"};
                        //int Subject_Units[12] = {4, 2, 1, 4, 3, 3, 3, 3, 3};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
                else if (strcmp(NewStudent_Data.Course_YearChoice, "4th Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"EE 003", "EE 401", "ECE 402", "CE 402A", "CHEM 004", " CPE 004", "MATH 012", "1E 301A"};
                        //char *Subject_FullName[12] = {"ELECTRICAL CIRCUITS 2", "DC MACHINERY", "ELECTRONIC CIRCUIT ANALYSIS AND DESIGN", "FLUID MECHANICS", "MATERIALS SCIENCE AND ENGINEERING", "LOGIC CIRCUITS AND SWITCHING THEORY", "NUMERICAL METHODS", "APPLIED STATISTICS"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        //int Subject_Units[12] = {4, 4, 4, 3, 3, 4, 4, 1};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"EE 402", "EE 403", "EE 404", "EE 405", "EE 406", "ECE 004", "ECE 006", "CPE 006", "EE 407"};
                        //char *Subject_FullName[12] = {"EE LAWS, ETHICS, CODES AND STANDARDS", "AC MACHINERY", "INTEGRATION COURSE FOR ENGINNERING SCIENCES", "TRANSFORMER AND AC APPARATUSES", "ELECTRICAL CIRCUITS 3", "PRINCIPLES OF COMMUNICATION", "FEEDBACK AND CONTROL SYSTEMS", "MICROPROCESSOR SYSTEMS", "EE RESEARCH 2 (RESEARCH PROJECT)"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM"};
                        //int Subject_Units[12] = {2, 4, 2, 3, 3, 4, 4, 4, 1};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
                else if (strcmp(NewStudent_Data.Course_YearChoice, "5th Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"EE 501", "EE 502", "EE 503", "EE 504", "--", "--", "ECE 003", "EE 505"};
                        //char *Subject_FullName[12] = {"POWER SYSTEM ANALYSIS AND DESIGN", "ILLUMINATION ENGINEERING DESIGN", "ELECTRICAL SYSTEM DESIGN", "ELECTRICAL EQUIPMENT OPERATION MAINTENANCE", "EE ELECTIVE 1", "EE ELECTIVE 2", "INDUSTRIAL ELECTRONICS", "DESIGN PROJECT 1"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        //int Subject_Units[12] = {4, 3, 4, 3, 3, 3, 4, 1};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"EE 506", "EE 507", "EE 508", "EE 509", "EE 510", "--", "--", "ITE 002A", "EE 511"};
                        //char *Subject_FullName[12] = {"ELECTRICAL TRANSPORTATION AND DISTRIBUTION SYSTEM AND DESIGN", "PLANT VISITS AND SEMINARS FOR EE", "POWER PLANT ENGINEERING AND SUBSTATION DESIGN", "INTEGRATION COURSE FOR EE 3", "INSTRUMENTATION AND CONTROL", "EE ELECTIVE 3", "EE ELECTIVE 4", "INFORMATION TECHNOLOGY", "DESIGN PROJECT 2"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM"};
                        //int Subject_Units[12] = {4, 1, 3, 2, 3, 3, 3, 3, 2};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
            }
            else if (strcmp(NewStudent_Data.MainCourse_CodeName_Passer, "BSECE") == 0)
            {
                if (strcmp(NewStudent_Data.Course_YearChoice, "1st Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"MATH 001", "MATH 002", "CHEM 001", "CPE 001", "ENGL 001", "FIL 001", "COE 001", "PE 001", "NSTP 001"};
                        //char *Subject_FullName[12] = {"PLANE AND SPHERICAL TROGONOMETRY", "GENERAL CHEMISTRY", "COMPUTER FUNDAMENTALS", "COMMUNICATION ARTS 001", "KOMUNIKASYON SA AKADEMIKONG FILIPINO", "ENGINEERING ORIENTATION", "PHYSICAL FITNESS", "NATIONAL SERVICE TRAINING PROGRAM 1"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM"};
                        //int Subject_Units[12] = {3, 3, 4, 1, 3, 3, 1, 2, 3};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"MATH 003", "MATH 004", "MATH 005", "AR 001", "CS 100A", "HUM 001", "HUM 002", "ENGL 002", "FIL 002", "PE 002", "NSTP 001"};
                        //char *Subject_FullName[12] = {"ADVANCED ALGEBRA", "ANALYTICAL GEOMETRY", "SOLID MEASURATION", "ENGINEERING DRAWING", "FUNDAMENTALS OF PROGRAMMING AND ALGORITHM", "INTRODUCTION TO PHILOSOPHY", "LOGIC", "COMMUNICATION ARTS 2", "PAGBASA AT PAGSULAT TINGO SA PANANALIKSIK", "RHYTHMIC ACTIVITIES", "NATIONAL SERVICE TRAINING PROGRAM 2"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM", "6:00PM - 7:00PM", "7:00PM - 8:00PM"};
                        //int Subject_Units[12] = {2, 3, 2, 1, 2, 3, 3, 3, 3, 2, 3};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
                else if (strcmp(NewStudent_Data.Course_YearChoice, "2nd Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"MATH 006", "MATH 007", "MATH 014", "CHEM 002", "CPE 003", "SOCSC 001", "SOCSC 002", "SOCSC 003", "PE 003"};
                        //char *Subject_FullName[12] = {"DISCRETE MATHEMATICS", "DIFFERENTIAL CALCULUS", "FUNDAMENTALS OF MATLAB PROGRAMMING", "ENVIRONMENTAL ENGINEERING", "COMPUTER-AIDED DRAFTING", "ECONOMICS, AGRARIAN REFORM AND TAXATION", "SOCIETY AND CULTURE WITH FAMILY PLANNING", "PHILIPPINE HISTORY WITH POLITICS AND GOVERNANCE", "INDIVIDUAL/DUAL SPORTS"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM"};
                        //int Subject_Units[12] = {3, 4, 1, 3, 1, 3, 3, 3, 2};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"ECE 100", "MATH 008", "MATH 009", "PHYS 001", "HUM 003", "SOCSC 004", "SOCSC 005", "ENGL 003", "PE 004"};
                        //char *Subject_FullName[12] = {"FUNDAMENTALS OF LABVIEW PROGRAMMING", "INTEGRAL CALCULUS", "PROBABILITY AND STATISTICS", "CALCULUS-BASED PHYSICS 1", "ETHICS", "GENERAL PSYCHOLOGY", "LIFE AND WORKS OF RIZAL", "TECHNICAL COMMUNICATION", "SPORTS AND GAMES"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM"};
                        //int Subject_Units[12] = {1, 4, 3, 4, 3, 3, 3, 3, 2};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
                else if (strcmp(NewStudent_Data.Course_YearChoice, "3rd Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"ECE 301", "CPE 005B", "CE 001", "IE 001", "IE 002", "ME 005", "MATH 010", "PHYS 002"};
                        //char *Subject_FullName[12] = {"VECTOR ANALYSIS", "COMPUTER ORGANIZATION AND ARCHITECTURE", "STATICS OF RIGID BODIES", "ENGINEERING MANAGEMENT", "SAFETY MANAGEMENT", "ENGINEERING ECONOMY", "DIFFERENTIAL EQUATIONS", "CALCULUS-BASED PHYSICS 2"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        //int Subject_Units[12] = {3, 4, 3, 3, 2, 3, 3, 4};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"ECE 001", "ECE 302", "ECE 303", "EE 002", "CE 002", "CE 003A", "CHEM 004", "MATH 011"};
                        //char *Subject_FullName[12] = {"ELECTRONIC DEVICES AND CIRCUITS", "ELECTROMAGNETICS", "INTEGRATION COURSE 1 FOR ECE", "ELECTRICAL CIRCUITS 1", "DYANMICS OF RIGID BODIES", "MECHANICS OF DEFORMABLE BODIES", "MATERIALS SCIENCE AND ENGINEERING", "ADVANCE ENGINEERING MATHEMATICS"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        //int Subject_Units[12] = {4, 3, 2, 4, 3, 3, 3, 3};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
                else if (strcmp(NewStudent_Data.Course_YearChoice, "4th Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"--", "ECE 402", "ECE 401", "EE 003", "CPE 004", "MATH 012", "ME 004"};
                        //char *Subject_FullName[12] = {"ECE ELECTIVE 1", "ELECTRONIC CIRCUIT ANALYSIS AND DESIGN", "SIGNALS, SPECTRA, SIGNAL PROCESSING", "ELECTRICAL CIRCUITS 2", "LOGIC CIRCUITS AND SWITCHING THEORY", "NUMERICAL METHODS", "THERMODYNAMICS 1"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        //int Subject_Units[12] = {3, 4, 4, 4, 4, 4, 3};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"--", "ECE 003", "ECE 004", "ECE 006", "ECE 403", "EE 408", "CPE 006"};
                        //char *Subject_FullName[12] = {"ECE ELECTIVE 2", "INDUSTRIAL ELECTRONICS", "PRINCIPLES OF COMMUNICATIONS", "FEEDBACK AND CONTROL SYSTEMS", "INTEGRATION COURSE 2 FOR ECE", "ENERGY CONVERSION", "MICROPROCESSOR SYSTEMS"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        //int Subject_Units[12] = {3, 4, 4, 4, 2, 4, 4};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
                else if (strcmp(NewStudent_Data.Course_YearChoice, "5th Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"--", "ECE 501", "ECE 502", "ECE 503", "ECE 504", "ECE 505", "COE 002"};
                        //char *Subject_FullName[12] = {"ECE ELECTIVE 3", "DESIGN PROJECT 1", "DIGITAL COMMUNICATIONS", "TRANSMISSION MIDIA AND ANTENNA SYSTEMS", "DATA COMMUNICATIONS", "ECE LAWS,  ETHICS, CODES AND STANDARDS", "FUNDAMENTALS OF INTELLECTUAL PROPERTY"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        //int Subject_Units[12] = {3, 1, 4, 4, 4, 3, 2};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"--", "ECE 506", "ECE 507", "ECE 508", "ECE 509"};
                        //char *Subject_FullName[12] = {"ECE ELECTIVE 4", "DESIGN PROJECT 2", "INTEGRATION COURSE 3 FOR ECE", "PLANT VISITS AND SEMINARS FOR ECE", "WIRELESS COMMUNICATIONS"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM"};
                        //int Subject_Units[12] = {3, 4, 4, 4, 2, 4, 4};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
            }
            else if (strcmp(NewStudent_Data.MainCourse_CodeName_Passer, "BSEnSE") == 0)
            {
                if (strcmp(NewStudent_Data.Course_YearChoice, "1st Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {};
                        //char *Subject_FullName[12] = {};
                        //char *Subject_LinearTime[12] = {};
                        //int Subject_Units[12] = {};
                        //int Subject_WholeSize = ;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {};
                        //char *Subject_FullName[12] = {};
                        //char *Subject_LinearTime[12] = {};
                        //int Subject_Units[12] = {};
                        //int Subject_WholeSize = ;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
                else if (strcmp(NewStudent_Data.Course_YearChoice, "2nd Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {};
                        //char *Subject_FullName[12] = {};
                        //char *Subject_LinearTime[12] = {};
                        //int Subject_Units[12] = {};
                        //int Subject_WholeSize = ;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {};
                        //char *Subject_FullName[12] = {};
                        //char *Subject_LinearTime[12] = {};
                        //int Subject_Units[12] = {};
                        //int Subject_WholeSize = ;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
                else if (strcmp(NewStudent_Data.Course_YearChoice, "3rd Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {};
                        //char *Subject_FullName[12] = {};
                        //char *Subject_LinearTime[12] = {};
                        //int Subject_Units[12] = {};
                        //int Subject_WholeSize = ;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {};
                        //char *Subject_FullName[12] = {};
                        //char *Subject_LinearTime[12] = {};
                        //int Subject_Units[12] = {};
                        //int Subject_WholeSize = ;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
                else if (strcmp(NewStudent_Data.Course_YearChoice, "4th Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {};
                        //char *Subject_FullName[12] = {};
                        //char *Subject_LinearTime[12] = {};
                        //int Subject_Units[12] = {};
                        //int Subject_WholeSize = ;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {};
                        //char *Subject_FullName[12] = {};
                        //char *Subject_LinearTime[12] = {};
                        //int Subject_Units[12] = {};
                        //int Subject_WholeSize = ;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
                else if (strcmp(NewStudent_Data.Course_YearChoice, "5th Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {};
                        //char *Subject_FullName[12] = {};
                        //char *Subject_LinearTime[12] = {};
                        //int Subject_Units[12] = {};
                        //int Subject_WholeSize = ;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {};
                        //char *Subject_FullName[12] = {};
                        //char *Subject_LinearTime[12] = {};
                        //int Subject_Units[12] = {};
                        //int Subject_WholeSize = ;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
            }
            else if (strcmp(NewStudent_Data.MainCourse_CodeName_Passer, "BSIE") == 0)
            {
                if (strcmp(NewStudent_Data.Course_YearChoice, "1st Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"CHEM 001", "COE 001", "CPE 001", "ENGL 001", "FIL 001", "MATH 001", "MATH 002", "PE 001", "NSTP 001"};
                        //char *Subject_FullName[12] = {"GENERAL CHEMISTRY", "ENGINEERING ORIENTATION", "COMPUTER FUNDAMENTALS", "COMMUNICATION ARTS 1", "KOMUNIKASYON SA AKADEMIKONG FILIPINO", " COLLEGE ALGREBRA", "PLANE AND SPHERICAL TRIGONOMETRY", "PHYSICAL FITNES", "NATIONAL SERVICE TRAINING PROGRAM 1"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM"};
                        //int Subject_Units[12] = {4, 1, 1, 3, 3, 3, 3, 2, 3};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"AR 001", "ENGL 002", "FIL 002", "HUM 001", "HUM 002", "MATH 003", "MATH 004", "MATH 005", "PE 002", "NSTP 002"};
                        //char *Subject_FullName[12] = {"ENGINEERING DRAWING", "COMMJUNICATION ARTS 2", "PAGBASA AT PAGSULAT TUNGO SA PANANALIKSIK", "INTRODUCTION TO PHILOSOPHY", "LOGIC", "ADVANCED ALGEBRA", "ANALYTIC GEOMETRY", "SOLID MENSURATION", "RHYTHMIC ACTIVITIES", "NATIONAL SERVICE TRAINING PROGRAM 2"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM", "6:00PM - 7:00PM"};
                        //int Subject_Units[12] = {1, 3, 3, 3, 3, 2, 3, 2, 2, 3};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
                else if (strcmp(NewStudent_Data.Course_YearChoice, "2nd Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"CS 100A", "ENGL 003", "MATH 006", "MATH 007", "MATH 013", "PE 003", "SOCSC 001", "SOSCS 001"};
                        //char *Subject_FullName[12] = {"FUNDAMENTALS OF PROGRAMMING AND ALGORITHM", "TECHINICAL COMMUNICATIONS", "DISCRETE MATHEMATICS", "DIFFERENTIAL CALCULUS", "LINEAR ALGEBRA WITH MATLAB", "INDIVIDUAL/DUAL SPORTS", "ECONOMICS, AGRARIAN REFORM AND TAXATION", "SOCIETY AND CULTURE WITH FAMILY PLANNING"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        //int Subject_Units[12] = {2, 3, 3, 4, 3, 2, 3, 3};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"CPE 003", "HUM 003", "MATH 008", "MATH 009", "PE 004", "PHYS 001", "SOCSC 003", "SOSCS 004"};
                        //char *Subject_FullName[12] = {"COMPUTER-AIDED DRAFTING", "ETHICS", "INTEGRA; CALCULUS", "PROBABILITY AND STATISTICS", "SPORTS AND GAMES", "CALCULUS-BASED PHYSICS 1", "PHILIPPINE HISTORY WITH POLITICS AND GOVERNANCE", "GENERAL PSYCHOLOGY"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        //int Subject_Units[12] = {1, 3, 4, 3, 2, 4, 3, 3};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
                else if (strcmp(NewStudent_Data.Course_YearChoice, "3rd Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"CE 001", "IE 001", "IE 300", "IE 301", "IE 302", "PHYS 002", "MATH 010", "SOCSC 006"};
                        //char *Subject_FullName[12] = {"STATICS OF RIGID BODIES", "ENGINEERING MANAGEMENT", "INDUSTRIAL PSYCHOLOGY", "ADVANCED STATISTICS FOR INDUSTRIAL ENGINEERING", "INDUSTRILA MATERIALS AND PROCESSES", "CALCULUS-BASED PHYSICS 2", "DIFFERENTIAL EQUATIONS", "PRINCIPLES OF ECONOMICS"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        //int Subject_Units[12] = {3, 3, 3, 3, 3, 4, 3, 3};
                        //int Subject_WholeSize = ;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"AC 004", "CE 002", "CE 003A", "IE 002", "IE 303", "IE 304", "MATH 011", "ME 005"};
                        //char *Subject_FullName[12] = {"FINANCIAL ACCOUNTING", "DYNAMICS OF RIGID BODIES", "MECHANICS OF FORMIDABLE BODIES", "SAFETY MANAGEMENT", "METHODS ENGENNERING", "QUALITY MANAGEMENT SYSTEMS", "ADVANCED ENGINEERING MATHEMATICS", "ENGINEERING ECONOMY"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        //int Subject_Units[12] = {3, 3, 3, 2, 5, 3, 3, 3};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
                else if (strcmp(NewStudent_Data.Course_YearChoice, "4th Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"AC 005", "IE 003", "IE 004", "IE 401", "IE 402", "IE 403", "ME 004"};
                        //char *Subject_FullName[12] = {"MANAGERIAL ACCOUNTING", "OPERATIONS RESEARCH 1", "ENGINEERING ENTREPRENEURSHIP", "ERGONOMICS", "INDUSTRIAL QUALITY CONTROL", "STRATEGIC PLANNING", "THERMODYNAMICS 1"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        //int Subject_Units[12] = {3, 3, 3, 3, 3, 3, 3};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"CHEM 002", "EE 001", "IE 404", "IE 405", "IE 406", "IE 407", "IE 408", "SOSCS 005"};
                        //char *Subject_FullName[12] = {"ENVIRONMENTAL ENGINEERING", "BASIC ELECTRICAL ENGINEERING", "OPERATIONS RESEARCH 2", "PROJECT FEASIBILITY", "PRODUCTION SYSTEMS", "PRODUCTION SYSTEMS", "PRINCIPLES OF LOGISTICS", "PROJECT MANAGEMENT", " LIFE AND WORKS RIZAL"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        //int Subject_Units[12] = {3, 3, 3, 3, 3, 3, 3, 3};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
                else if (strcmp(NewStudent_Data.Course_YearChoice, "5th Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"IE 501", "IE 502", "IE 503", "IE 504", "IE 505", "IS 001"};
                        //char *Subject_FullName[12] = {"UNDERGRADUATE RESEARCH FOR INDUSTRAIL ENGINEERING", "IE DESIGN PROJECT 1", "PLANT VISITS AND SEMINARS FOR INDUSTRIAL ENGINEERING", "MULTI-CRITERIA DECISON MAKING", "SYSTEMS ENGINEERING", "INFORMATION SYSTEMS"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM"};
                        //int Subject_Units[12] = {3, 3, 1, 3, 3, 3};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"IE 500", "IE  506", "IE 507", "IE 508"};
                        //char *Subject_FullName[12] = {"ON-THE-JOB TRAINING FOR INDUSTRIAL ENGINEERING", "IE DESIGN PROJECT 2", "FACILITIES DESIGN", "ENGINEERING VALUES AND ETHICS"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM"};
                        //int Subject_Units[12] = {5, 2, 3, 3};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
            }
            else if (strcmp(NewStudent_Data.MainCourse_CodeName_Passer, "BSME") == 0)
            {
                if (strcmp(NewStudent_Data.Course_YearChoice, "1st Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"ENGL 001", "FIL 001", "MATH 001", "MATH 002", "CHEM 001", "COE 001", "CPE 001", "PE 001", "NSTP 001"};
                        //char *Subject_FullName[12] = {"COMMUNICATION ARTS 1", "KOMUNIKASYON SA AKADEMIKONG FILIPINO", "COLLEGE ALGEBRA", "PLANE AND SPHERICAL TRIGONOMETRY", "GENERAL CHEMISTRY", "ENGINEERING ORIENTATION", "COMPUTER FUNDAMENTALS", "PHYSICAL FITNESS", "NATIONAL SERVICE TRAINING PROGRAM 1"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM"};
                        //int Subject_Units[12] = {3, 3, 3, 3, 4, 1, 1, 2, 3};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"ENGL 002", "FIL 002", "AR 001", "CHEM 101", "MATH 003", "MATH 004", "MATH 005", "HUM 001", "PE 001", "NSTP 002"};
                        //char *Subject_FullName[12] = {"COMMUNICATION ARTS 002", "PAGBASA AT PAGSULAT TUNGO SA PANANALIKSIK", "ENGINEERING DRAWING", "GENERAL CHEMISTRY CALCULATIONS", "ADVANCED ALGEBRA", "ANALYTICAL GEOMETRY", "SOLID MENSURATION", "INTRODUCTION TO PHILOSOPHY", "RHYTHMIC ACTIVITIES", "NATIONAL SERVICE TRAINING 2"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM", "6:00PM - 7:00PM"};
                        //int Subject_Units[12] = {3, 3, 1, 3, 2, 3, 2, 3, 2, 3};
                        //int Subject_WholeSize = 11;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
                else if (strcmp(NewStudent_Data.Course_YearChoice, "2nd Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"CHEM 002", "CS 100A", "ENGL 003", "HUM 002", "MATH 007", "MATH 013", "SOCSC 001", "SOCSC 002", "PE 003"};
                        //char *Subject_FullName[12] = {"ENVIRONMENTAL ENGINEERING", "FUNDAMENTALS OF PROGRAMMING AND ALGORITHM", "TECHNICAL COMMUNICATION", "LOGIC", "DIFFERENTIAL CALCULUS", "LINEAR ALGEBRA WITH MATLAB", "ECONOMICS, AGRARIAN AND REFORM AND TAXATION", "SOCIETY AND CULTURE WITH FAMILY PLANNING", "INDIVIDUAL/DUAL SPORTS"};
                        //char *Subject_LinearTime[12] = {3, 2, 3, 3, 4, 3, 3, 3, 2};
                        //int Subject_Units[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM"};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"CHEM 201", "HUM 003", "MATH 008", "MATH 009", "PHYS 001", "SOCSC 003", "PE 004"};
                        //char *Subject_FullName[12] = {"ANALYTICAL CHEMISTRY", "ETHICS", "INTEGRAL CALCULUS", "PROBABILITY AND STATISTICS", "CALCULUS-BASED PHYSICS 001", "PHILIPPINE HISTORY WITH POLITICS GOVERNANCE", "SPORTS AND GAMES"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        //int Subject_Units[12] = {5, 3, 4, 3, 4, 3, 2};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
                else if (strcmp(NewStudent_Data.Course_YearChoice, "3rd Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"CHEM 301", "CHEM 003", "CE 001", "CPE 003", "IE 001", "MATH 010", "PHYS 002", "CHE 303"};
                        //char *Subject_FullName[12] = {"PHYSICAL CHEMISTRY", "ORGANIC CHEMISTRY", "STATICS OF RIGID BODIES", "COMPUTER-AIDED DRAFTING", "ENGINEERING MANAGEMENT", "DIFFERENTIAL EQUATIONS", "CALCULUS-BASED PHYSICS 2", "CHE CALCULATIONS 1"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM"};
                        //int Subject_Units[12] = {4, 5, 3, 1, 3, 3, 4, 3};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"CHEM 302", "CHEM 322", "CE 002", "CE 003A", "EE 005", "CHEM 004", "MATH 011", "CHE 304"};
                        //char *Subject_FullName[12] = {"PHYSICAL CHEMISTRY FOR ENGINEERS 2", "CHE CALCULATIONS 2", "DYNAMICS OF RIGID BODIES", "MECHANICS OF DEFORMABLE BODIES", "BASIC ELECTRICAL AND ELECTRONICS ENGINEERNG", "MATERIALS SCIENCE AND ENGINEERING", "ADVANCED ENGINEERING MATHEMATICS", "INTEGRATION COURSE 1 FOR CHE"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        //int Subject_Units[12] = {4, 3, 3, 3, 3, 3, 3, 2};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
                else if (strcmp(NewStudent_Data.Course_YearChoice, "4th Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"CHEM 005", "IE 002", "CHE 402", "CHE 403", "CHE 404", "CHE 405", "MATH 012", "ME 005", "SOCSC 004"};
                        //char *Subject_FullName[12] = {"INDUSTRIAL CHEMISTRY FOR CHE", "SAFETY MANAGEMENT", "INTRODUCTION TO BIOTECHNOLOGY", "PRINCIPLES OF TRANSPORT PROCESSES", "CHE RESEARCH 1", "CHE THERMODYNAMICS 1", "NUMERICAL METHODS", "ENGINEERING ECONOMY", "GENERAL PSYCHOLOGY"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM"};
                        //int Subject_Units[12] = {3, 2, 3, 3, 2, 3, 4, 3, 3};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"CHE 406", "CHE 407", "CHE 408", "CHE 409", "CHE 410", "CHE 411", "CHE 412", "ECE 006", "CHE 413"};
                        //char *Subject_FullName[12] = {"MOMENTUM TRANSFER", "CHE THEMODYNAMICS 2", "HEAT AND MASS TRANSFER", "UNIT OPERATIONS LABORATORY 1", "CHEMICAL PROCESS INDUTRIES", "CHEMICAL REACTION ENGINEERING", "CHE RESEARCH 2", "FEEDBACK AND CONTROL SYSTEMS", "INTEGRATION COURSE 2 FOR CHE"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM"};
                        //int Subject_Units[12] = {3, 3, 3, 1, 3, 4, 1, 4, 2};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
                else if (strcmp(NewStudent_Data.Course_YearChoice, "5th Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {3, 1, 3, 2, 2, 3, 2, 1, 2, 3};
                        //char *Subject_FullName[12] = {"CHE 501", "CHE 502", "CHE 503", "CHE 504", "CHE 505", "CHE 506", "CHE 507", "CHE 508", "CHE 509", "SOCSC 005"};
                        //char *Subject_LinearTime[12] = {"SEPARATION PROCESSES", "UNIT OPERATIONS LABORATORY 2", "BIOCHEMICAL ENGINEERING", "SAFETY IN THE PROCESS INDUSTRY", "EQUIPMENT DESIGN", "INTRODUCTION TO POLYMER ENGINEERING", "CHE LAWS, ETHICS, CODES AND STANDARDS", "COMPUTER APPLICATIONS IN CHE", "INTRODUCTION TO PARTICLE TECHNOLOGY", "LIFE AND WORKS OF RIZAL"};
                        //int Subject_Units[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM", "6:00PM - 7:00PM"};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"CHE 510", "CHE 511", "CHE 512", "CHE 513", "CHE 514", "CHE 515", "IE 003"};
                        //char *Subject_FullName[12] = {"INDUSTRIAL WASTE MANAGEMENT AND CONTROL", "CHE PLANT DESIGN", "PLASTICS TECHNOLOGY", "MOLECULAR BIOLOGY", "INTEGRATION COURSE 3 FOR CHE", "PLANT VISITS AND SEMINARS FOR CHE", "OPERATIONS RESEARCH 1"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        //int Subject_Units[12] = {3, 3, 3, 3, 2, 1, 3};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
            }
            else if (strcmp(NewStudent_Data.MainCourse_CodeName_Passer, "Arch") == 0)
            {
                if (strcmp(NewStudent_Data.Course_YearChoice, "1st Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"MATH 001", "MATH 002", "ENGL 001", "FIL 001", "ARCH 005", "ARCH 007", "ARCH 003", "PE 001", "NSTP 001", "NONE", "NONE", "NONE"};
                        //char *Subject_FullName[12] = {"COLLEGE ALGEBRA", "PLANE AND SPHERICAL TRIGONOMETRY", "COMMUNICATION ARTS 1", "KOMUNIKASYON SA AKADEMIKONG FILIPINO 1", "ARCHITURAL DESIGN 1", "ARCHITECTURAL VISUAL COMMUNICATIONS 1", "THEORY OF ARCHITECTURE 1", "PHYSICAL FITNESS 1", "NATIONAL SERVICE TRAINING PROGRAM 1", "NOT AVAILABLE", "NOT AVAILABLE", "NOT AVAILABLE"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM", "6:00PM - 7:00PM", "N/A - N/A"};
                        //int Subject_Units[12] = {3, 3, 3, 3, 2, 3, 2, 2, 2, 3, 0, 0};
                        //int Subject_WholeSize = 8;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"MATH 004", "MATH 005", "PHYS 001", "ENGL 002", "FIL 002", "ARCH 005-1", "ARCH 007-1", "ARCH 003-1", "PE 002", "NSTP 002", "NONE", "NONE", "NONE"};
                        //char *Subject_FullName[12] = {"ANALYTIC GEOMETRY", "SOLID MENSURATION", "PHYSICS 1", "COMMUNICATION ARTS 2", "KOMUNIKASYON SA AKADEMIKONG FIIPINO 2", "ARCHITECTURAL DESIGN 2", "ARCHITECTURAL VISUAL COMMUNICATIONS 3", "ARCHITECTURAL VISUAL COMMUNICATIONS 4", "THEORY OF ARCHITECTURE 2", "RHYTHMIC ACTIVITIES", "NATIONAL SERVCE TRAINING PROGRAM 2"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM", "6:00PM - 7:00PM", "7:00PM - 8:00PM"};
                        //int Subject_Units[12] = {2, 2, 3, 3, 3, 2, 3, 2, 3, 2, 3};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
                else if (strcmp(NewStudent_Data.Course_YearChoice, "2nd Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"MATH 007", "PHYS 002", "SOCSC 002", "ARCH 005-2", "ARCH 001", "ARCH 003-2", "ARCH 002", "ARCH 009", "PE 003"};
                        //char *Subject_FullName[12] = {"DIFFERENTIAL CALCULUS", "PHYSICS 2", "SOCIETY AND CULTURE WITH FAMILY PLANNING", "ARCHITECTURAL DESIGN 3", "BUILDING TECHNOLOGY 1", "ARCHITECTURAL VISUAL COMMUNICATIONS 5", "ARCHITECTURAL INTERIORS", "HISTORY OF ARCHITECTURE ", "INDIVIDUALDUAL SPORTS"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM"};
                        //int Subject_Units[12] = {3, 3, 3, 3, 3, 2, 3, 3, 2};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"CE 001", "ARCH 011", "PSYH 001", "ARCH 005-3", "ARCH 001-1", "ARCH 015", "ARCH 010", "ARCH 009-1", "PE 004"};
                        //char *Subject_FullName[12] = {"STATICS OF RIGID BODIES", "SURVEYING", "GENERAL PSYCHOLOGY", "ARCHITECTURAL DESIGN 4", "BUILDING TECHNOLOGY 2", "BUILDING UTILITIES 1", "TROPICAL DESIGN", "HISTORY OF ARCHITECTURE 2", "SPORTS AND GAMES"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM"};
                        //int Subject_Units[12] = {3, 3, 3, 3, 3, 3, 3, 3, 3};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
                else if (strcmp(NewStudent_Data.Course_YearChoice, "3rd Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"ARCH 013", "CPE 003", "ARCH 005-4", "ARCH 001-2", "ARCH 015-1", "ARCH 009-2", "ARCH 014"};
                        //char *Subject_FullName[12] = {"STRENGTH OF MATERIALS", "COMPUTER-AIDED DRAFTING", "ARCHITECTURAL DESIGN 5", "BUILDING TECHNOLOGY 3", "BUILDING UTILITIES 3", "HISTORY OF ARCHITECTURE 3", "PROFESSIONAL PRACTICE 1"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        //int Subject_Units[12] = {3, 3, 4, 3, 3, 3, 3};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"ARCH 005-5", "ARCH 016", "ARCH 017", "ARCH 001-2", "ARCH 015-2", "ARCH 009-3", "ARCH 014-1", "ARCH 007"};
                        //char *Subject_FullName[12] = {"ARCHITECTURAL DESIGN 6", "BUILDING INFORMATION MODELLING", "THEORY OF STRUCTURE", "BUILDING TECHNOLOGY 4", "BUILDING UTILITIES 3", "HISTORY OF ARCHITECTURE 4", "PROFESSIONAL PRACTICE 2", "PLANNING 1"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        //int Subject_Units[12] = {4, 3, 3, 3, 3, 2, 3, 3};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
                else if (strcmp(NewStudent_Data.Course_YearChoice, "4th Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"ENGL 003", "LIT 001", "ARCH 020", "ARCH 005-6", "ARCH 001-3", "ARCH 007-1"};
                        //char *Subject_FullName[12] = {"COMMUNICATION ARTS 3", "LITERATURE 1", "STEEL AND TIMBER DESIGN", "ARCHITECTURAL DESIGN 7", "BUILDING TECHONOLOGY 5", "PLANNING 2"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM"};
                        //int Subject_Units[12] = {3, 3, 3, 5, 3, 3};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"ARCH 005-7", "ARCH 018", "ARCH 007-2", "ARCH 014-2", "ARCH 021", "ARCH 100A", "--"};
                        //char *Subject_FullName[12] = {"ARCHITECTURAL DESIGN 8", "HOUSING", "PLANNING 3", "PROFESSIONAL PRACTICE 3", "ARCHITETURAL STRUCTURES", "RESEARCH METHODS FOR ARCHITECTURE", "SPECIALIZATION 1"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        //int Subject_Units[12] = {5, 3, 3, 3, 5, 3, 3};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
                else if (strcmp(NewStudent_Data.Course_YearChoice, "5th Year College") == 0)
                {
                    if (strcmp(NewStudent_Data.Course_SemSelection, "First Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"PHILO 001", "HUM 001", "HUM 002", "ARCH 005-8", "--", "--"};
                        //char *Subject_FullName[12] = {"PHILOSOPHY", "HUMANITIES", "SOCIOLOGY OF ANTHROPOLOGY", "ARCHITECTURAL DESIGN 9", "SPECIALIZATION 2", "ARCHITECTURE COMPREHENSIVE COURSE"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM"};
                        //int Subject_Units[12] = {3, 3, 3, 5, 3, 3};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                    if (strcmp(NewStudent_Data.Course_SemSelection, "Second Semester") == 0)
                    {
                        //char *Subject_CodeName[12] = {"SOSCS 005", "SOCSC 002", "SOCSC 003", "ARCH 005-9", "--"};
                        //char *Subject_FullName[12] = {"LIFE AND WORKS OF RIZAL", "TAXATION AND AGRARIAN REFORM", "POLITICS AND GOVERNANCE WITH NEW CONSTITUTION", "ARCHITECTURAL DESIGN 10", "SPECIALIZATION 3"};
                        //char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM- 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM"};
                        //int Subject_Units[12] = {3, 3, 3, 5, 3};
                        //int Subject_WholeSize = 1;
                        //Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units, Subject_WholeSize);
                    }
                }
            }
            else
            {
                system("CLS");
                printf("Houston! We have a problem!");
                printf("There is no way that this system return false for each comparision for more than 64+!\n This is a bug! Please report to the developer immediately!!!");
                exit(FUNCTION_LINEAR_DISCONTINUE);
            }
        case 'N':
        case 'n':
            printf("Going back...");
            Sleep(2000);
            continue;
            //Func_NewStdnt_Eng_YearSelect(NewData, MainCourse_CodeName_Passer, MainCourse_FullName_Passer);
        default:
            printf("Your input is 'Out of Range' from the Choices!");
            Sleep(2000);
            continue;
        }
        break;
    }
}

int Func_SubjectUnit_Selection(char **Subject_CodeName, char **Subject_FullName, char **Subject_LinearTime, int Subject_Units[12], int Subject_WholeSize)
{
    system("CLS");
    SetConsoleTitle(FUNCTION_STEP3);
    int Subject_Selector,
        Option_Selector,
        Final_Comp_SelectedSubjects = 0,
        Final_Comp_SemUnits = 0,
        Subject_Counter = 0,
        SbjSel_Checker = 1,
        FinalizeChecker,
        Subject_UnitsGuard_AntiDuplicate_Include[12] = {0},
        Subject_UnitsGuard_AntiDuplicate_Exclude[12] = {0},
        Counter = 0;
    int Test_1, Test_2, Test_3;
    char Final_Decision_Selector;
    char *Subject_Parameters[2] = {"Include", "Exclude"};
    char *SbjSel_Stats[12] = {"Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown"};
    char *Subject_Include[12] = {"Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown"};

    //char *Subject_CodeName[12] = {"MATH 001", "MATH 002", "CHEM 001", "AR 001", "COE 001", "ENGL 001", "FIL 001", "PE 001", "NSTP 001", "MATH 004", "CPE 001", "HUMMS 001"};
    //char *Subject_FullName[12] = {"---------", "---------", "---------", "---------", "---------", "---------", "---------", "---------", "---------", "---------", "---------", "---------"};
    //char *Subject_Include[12] = {"Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown"};
    //char *Subject_LinearTime[12] = {"8:00AM - 9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 1:30PM", "1:30PM - 2:30PM", "2:30PM - 3:30PM", "1:30PM - 4:30PM", "7:30AM - 9:30AM", "9:30AM - 12:00PM", "4:30PM - :5:30PM", "4:30PM - 6:30PM", "5:30PM - 6:30PM"};
    //char *Subject_Parameters[2] = {"Include", "Exclude"};
    //int Subject_Units[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    //char *SbjSel_Stats[12] = {"Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown"};
    //Receiver For The Next Function
    while (1)
    {
        int Sbj_Stats_Increment = 0, Sbj_Stats_Decrement = 0, SbjSel_Stats_Exceptions = 0;
        system("CLS");
        gotoxy(30, 3);
        printf("\xC9\xCD\xCD \xDD CURRENT PROGRESS \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        gotoxy(30, 4);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 5);
        printf("\xBA 1st | 2nd | \xDD [3rd \xAF Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t                   \xBA");
        gotoxy(30, 6);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 7);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        gotoxy(30, 8);
        printf("\xC9\xCD\xCD \xDD SUBJECT LIST FOR 4TH YEAR MECHANICAL ENGINEERING \xAF SECOND SEMESTER \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        gotoxy(30, 10);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 11);
        printf("\xBA #    \xDD  STATUS  \xDD\tSUBJECT CODE - SUBJECT NAME\t  \xDD \tLINEAR TIME(START - END)    \xDD\t UNITS \t   \xBA\n");
        gotoxy(30, 12);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 13);
        printf("\xCC\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xB9");
        gotoxy(30, 14);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 15);
        printf("\xBA [1]  \xAF %s\t\xDD %s - %s \t\xDD\t %s \t\xDD\t %i\xBA", SbjSel_Stats[0], Subject_CodeName[0], Subject_FullName[0], Subject_LinearTime[0], Subject_Units[0]);
        gotoxy(30, 16);
        printf("\xBA [2]  \xAF %s\t\xDD %s - %s \t\xDD\t %s \t\xDD\t %i\xBA", SbjSel_Stats[1], Subject_CodeName[1], Subject_FullName[1], Subject_LinearTime[1], Subject_Units[1]);
        gotoxy(30, 17);
        printf("\xBA [3]  \xAF %s\t\xDD %s - %s \t\xDD\t %s \t\xDD\t %i\xBA", SbjSel_Stats[2], Subject_CodeName[2], Subject_FullName[2], Subject_LinearTime[2], Subject_Units[2]);
        gotoxy(30, 18);
        printf("\xBA [4]  \xAF %s\t\xDD %s - %s \t\xDD\t %s \t\xDD\t %i\xBA \t ", SbjSel_Stats[3], Subject_CodeName[3], Subject_FullName[3], Subject_LinearTime[3], Subject_Units[3]);
        gotoxy(30, 19);
        printf("\xBA [5]  \xAF %s\t\xDD %s - %s \t\xDD\t %s \t\xDD\t %i\xBA \t ", SbjSel_Stats[4], Subject_CodeName[4], Subject_FullName[4], Subject_LinearTime[4], Subject_Units[4]);
        gotoxy(30, 20);
        printf("\xBA [6]  \xAF %s\t\xDD %s - %s \t\xDD\t %s \t\xDD\t %i\xBA \t ", SbjSel_Stats[5], Subject_CodeName[5], Subject_FullName[5], Subject_LinearTime[5], Subject_Units[5]);
        gotoxy(30, 21);
        printf("\xBA [7]  \xAF %s\t\xDD %s - %s \t\xDD\t %s \t\xDD\t %i\xBA \t ", SbjSel_Stats[6], Subject_CodeName[6], Subject_FullName[6], Subject_LinearTime[6], Subject_Units[6]);
        gotoxy(30, 22);
        printf("\xBA [8]  \xAF %s\t\xDD %s - %s \t\xDD\t %s \t\xDD\t %i\xBA \t ", SbjSel_Stats[7], Subject_CodeName[7], Subject_FullName[7], Subject_LinearTime[7], Subject_Units[7]);
        gotoxy(30, 23);
        printf("\xBA [9]  \xAF %s\t\xDD %s - %s \t\xDD\t %s \t\xDD\t %i\xBA \t ", SbjSel_Stats[8], Subject_CodeName[8], Subject_FullName[8], Subject_LinearTime[8], Subject_Units[8]);
        gotoxy(30, 24);
        printf("\xBA [10] \xAF %s\t\xDD %s - %s \t\xDD\t %s \t\xDD\t %i\xBA \t ", SbjSel_Stats[9], Subject_CodeName[9], Subject_FullName[9], Subject_LinearTime[9], Subject_Units[9]);
        gotoxy(30, 25);
        printf("\xBA [11] \xAF %s\t\xDD %s - %s \t\xDD\t %s \t\xDD\t %i\xBA \t ", SbjSel_Stats[10], Subject_CodeName[10], Subject_FullName[10], Subject_LinearTime[10], Subject_Units[10]);
        gotoxy(30, 26);
        printf("\xBA [12] \xAF %s\t\xDD %s - %s \t\xDD\t %s \t\xDD\t %i\xBA \t ", SbjSel_Stats[11], Subject_CodeName[11], Subject_FullName[11], Subject_LinearTime[11], Subject_Units[11]);
        gotoxy(30, 27);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 28);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        gotoxy(30, 30);
        printf("\xC9\xCD\xCD STATISTICS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        gotoxy(30, 31);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 32);
        printf("\xBA \xDD Total Included Subject/s \xAF %d \t \xDD Total Included Units \xAF %d", Final_Comp_SelectedSubjects, Final_Comp_SemUnits);
        gotoxy(30, 33);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 34);
        printf("\xCC\xCD\xCD OPTIONS FOR INPUT \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xB9");
        gotoxy(30, 35);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 36);
        printf("\xBA Input '1' To Include Subject/s     \t\xDD      Input '-1' To Include All Subject/s                         \xBA");
        gotoxy(30, 37);
        printf("\xBA Input '2' To Withdraw Subject/s \t\xDD      Input '-2' To Exclude All Subject/s                         \xBA");
        gotoxy(30, 38);
        printf("\xBA Input '3' to process the data. \t\t\t\t\t\t\t\t\t\t   \xBA");
        gotoxy(30, 39);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 40);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        gotoxy(30, 42);
        printf("\xC8\xDD INPUT \xDD Please input your desired option and press ENTER \xAF ");
        scanf("%d", &Option_Selector);
        if (Option_Selector == 1)
        {
            gotoxy(30, 44);
            printf("Please select the subject number to be included \xAF ");
            scanf("%d", &Subject_Selector);
            if (Subject_Selector == 1)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[0];
                    Final_Comp_SelectedSubjects += 1;
                    Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 2)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[0];
                    Final_Comp_SelectedSubjects += 1;
                    Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 3)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[0];
                    Final_Comp_SelectedSubjects += 1;
                    Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 4)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[0];
                    Final_Comp_SelectedSubjects += 1;
                    Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 5)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[0];
                    Final_Comp_SelectedSubjects += 1;
                    Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 6)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[0];
                    Final_Comp_SelectedSubjects += 1;
                    Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 7)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[0];
                    Final_Comp_SelectedSubjects += 1;
                    Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 8)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[0];
                    Final_Comp_SelectedSubjects += 1;
                    Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 9)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[0];
                    Final_Comp_SelectedSubjects += 1;
                    Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 10)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[0];
                    Final_Comp_SelectedSubjects += 1;
                    Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 11)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[0];
                    Final_Comp_SelectedSubjects += 1;
                    Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 12)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[0];
                    Final_Comp_SelectedSubjects += 1;
                    Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else
            {
                gotoxy(30, 45);
                printf("\xDD WARNING \xAF You have inputted a wrong number! Out of Choice.Bonds! Reinitialing Function...");
                Sleep(2000);
                continue;
            }
        }
        else if (Option_Selector == 2)
        {
            gotoxy(30, 44);
            printf("\xDD INPUT \xAF Please select the subject number to be excluded \xAF ");
            scanf("%d", &Subject_Selector);
            if (Subject_Selector == 1)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0;
                    if (Final_Comp_SelectedSubjects == 0)
                    {
                        Final_Comp_SelectedSubjects = 0;
                    }
                    else
                    {
                        Final_Comp_SelectedSubjects -= 1;
                    }
                    if (Final_Comp_SemUnits == 0)
                    {
                        Final_Comp_SemUnits = 0;
                    }
                    else
                    {
                        Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                    }
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 2)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0;
                    if (Final_Comp_SelectedSubjects == 0)
                    {
                        Final_Comp_SelectedSubjects = 0;
                    }
                    else
                    {
                        Final_Comp_SelectedSubjects -= 1;
                    }
                    if (Final_Comp_SemUnits == 0)
                    {
                        Final_Comp_SemUnits = 0;
                    }
                    else
                    {
                        Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                    }
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 3)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0;
                    if (Final_Comp_SelectedSubjects == 0)
                    {
                        Final_Comp_SelectedSubjects = 0;
                    }
                    else
                    {
                        Final_Comp_SelectedSubjects -= 1;
                    }
                    if (Final_Comp_SemUnits == 0)
                    {
                        Final_Comp_SemUnits = 0;
                    }
                    else
                    {
                        Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                    }
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 4)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0;
                    if (Final_Comp_SelectedSubjects == 0)
                    {
                        Final_Comp_SelectedSubjects = 0;
                    }
                    else
                    {
                        Final_Comp_SelectedSubjects -= 1;
                    }
                    if (Final_Comp_SemUnits == 0)
                    {
                        Final_Comp_SemUnits = 0;
                    }
                    else
                    {
                        Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                    }
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 5)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0;
                    if (Final_Comp_SelectedSubjects == 0)
                    {
                        Final_Comp_SelectedSubjects = 0;
                    }
                    else
                    {
                        Final_Comp_SelectedSubjects -= 1;
                    }
                    if (Final_Comp_SemUnits == 0)
                    {
                        Final_Comp_SemUnits = 0;
                    }
                    else
                    {
                        Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                    }
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 6)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0;
                    if (Final_Comp_SelectedSubjects == 0)
                    {
                        Final_Comp_SelectedSubjects = 0;
                    }
                    else
                    {
                        Final_Comp_SelectedSubjects -= 1;
                    }
                    if (Final_Comp_SemUnits == 0)
                    {
                        Final_Comp_SemUnits = 0;
                    }
                    else
                    {
                        Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                    }
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 7)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0;
                    if (Final_Comp_SelectedSubjects == 0)
                    {
                        Final_Comp_SelectedSubjects = 0;
                    }
                    else
                    {
                        Final_Comp_SelectedSubjects -= 1;
                    }
                    if (Final_Comp_SemUnits == 0)
                    {
                        Final_Comp_SemUnits = 0;
                    }
                    else
                    {
                        Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                    }
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 8)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0;
                    if (Final_Comp_SelectedSubjects == 0)
                    {
                        Final_Comp_SelectedSubjects = 0;
                    }
                    else
                    {
                        Final_Comp_SelectedSubjects -= 1;
                    }
                    if (Final_Comp_SemUnits == 0)
                    {
                        Final_Comp_SemUnits = 0;
                    }
                    else
                    {
                        Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                    }
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 9)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0;
                    if (Final_Comp_SelectedSubjects == 0)
                    {
                        Final_Comp_SelectedSubjects = 0;
                    }
                    else
                    {
                        Final_Comp_SelectedSubjects -= 1;
                    }
                    if (Final_Comp_SemUnits == 0)
                    {
                        Final_Comp_SemUnits = 0;
                    }
                    else
                    {
                        Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                    }
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 10)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0;
                    if (Final_Comp_SelectedSubjects == 0)
                    {
                        Final_Comp_SelectedSubjects = 0;
                    }
                    else
                    {
                        Final_Comp_SelectedSubjects -= 1;
                    }
                    if (Final_Comp_SemUnits == 0)
                    {
                        Final_Comp_SemUnits = 0;
                    }
                    else
                    {
                        Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                    }
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 11)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0;
                    if (Final_Comp_SelectedSubjects == 0)
                    {
                        Final_Comp_SelectedSubjects = 0;
                    }
                    else
                    {
                        Final_Comp_SelectedSubjects -= 1;
                    }
                    if (Final_Comp_SemUnits == 0)
                    {
                        Final_Comp_SemUnits = 0;
                    }
                    else
                    {
                        Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                    }
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 12)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0;
                    if (Final_Comp_SelectedSubjects == 0)
                    {
                        Final_Comp_SelectedSubjects = 0;
                    }
                    else
                    {
                        Final_Comp_SelectedSubjects -= 1;
                    }
                    if (Final_Comp_SemUnits == 0)
                    {
                        Final_Comp_SemUnits = 0;
                    }
                    else
                    {
                        Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                    }
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
        }
        else if (Option_Selector == 3)
        {
            fflush(stdin);
            while (1)
            {
                gotoxy(30, 44);
                printf("\xDD QUESTION \xAF Are you sure you picked the subjects that you wanted to take???");
                gotoxy(30, 45);
                printf("\xDD Choices \xAF [Y]es or [N]o \xAF");
                scanf("%c", &Final_Decision_Selector);
                if (Final_Decision_Selector == 'Y' || Final_Decision_Selector == 'y')
                {
                    while (SbjSel_Checker != 11)
                    {
                        if (SbjSel_Stats_Exceptions == Subject_WholeSize)
                        {
                            gotoxy(30, 46);
                            printf("\xDD CRITICAL ERROR \xAF Are you even trying to enroll without any subjects!?");
                            Sleep(5000);
                            break;
                        }
                        else if (SbjSel_Stats[SbjSel_Checker - 1] == "Unknown")
                        {
                            gotoxy(30, 46);
                            printf("\xDD ERROR \xAF You cannot leave subject/s to be 'Unknown'. Set them to exclude if you don't want to include it.");
                            Sleep(3000);
                            break;
                        }
                        else if (SbjSel_Stats[SbjSel_Checker - 1] == "Exclude")
                        {
                            SbjSel_Stats_Exceptions++;
                        }
                        else
                        {
                            gotoxy(30, 46);
                            printf("\xDD PROCESS \xAF Copying Information....");
                            for (FinalizeChecker = 0; FinalizeChecker <= Final_Comp_SelectedSubjects; FinalizeChecker++)
                            {
                                if (strcmp(SbjSel_Stats[FinalizeChecker], Subject_Parameters[0]) == 0)
                                {
                                    ReceiverData.Subject_CodeName_Receiver[FinalizeChecker] = Subject_CodeName[FinalizeChecker];
                                    ReceiverData.Subject_FullName_Receiver[FinalizeChecker] = Subject_FullName[FinalizeChecker];
                                    ReceiverData.Subject_LinearTime_Receiver[FinalizeChecker] = Subject_LinearTime[FinalizeChecker];
                                }
                            }
                            //Func_Stdnt_ScholarshipCheck(/*Final_Comp_SelectedSubjects*/);
                            //Func_Stdnt_ScholarshipCheck(ReceiverData, Final_Comp_SelectedSubjects);
                            gotoxy(30, 47);
                            printf("\xDD PROCESS \xAF Moving Foward to \xDD [ 4th ] Scholarship Check...");
                            break;
                        }
                    }
                    continue; // Trick to go back to the Main Loop While(1) at the top...
                }
                else
                {
                    gotoxy(30, 46);
                    printf("\xDD PROCESS \xAF Going back...");
                    break;
                }
            }
            continue;
        }
        else if (Option_Selector == -1)
        {
            gotoxy(30, 44);
            printf("\xDD PROCESS \xAF Including All Available Subjects...");
            Final_Comp_SelectedSubjects = 0;
            Final_Comp_SemUnits = 0;
            while (Sbj_Stats_Increment <= Subject_WholeSize)
            {
                SbjSel_Stats[Sbj_Stats_Increment - 1] = Subject_Parameters[0];
                Final_Comp_SelectedSubjects += 1;
                Final_Comp_SemUnits += Subject_Units[Sbj_Stats_Increment - 1];
                Subject_UnitsGuard_AntiDuplicate_Include[Sbj_Stats_Increment - 1] = 1;
                Subject_UnitsGuard_AntiDuplicate_Exclude[Sbj_Stats_Increment - 1] = 0;
                Sbj_Stats_Increment++;
            }
            Sleep(1500);
            continue;
        }
        else if (Option_Selector == -2)
        {
            gotoxy(30, 44);
            printf("\xDD PROCESS \xAF Excluding All Available Subjects...");
            Final_Comp_SelectedSubjects = 0;
            Final_Comp_SemUnits = 0;
            while (Sbj_Stats_Decrement <= Subject_WholeSize)
            {
                SbjSel_Stats[Sbj_Stats_Decrement - 1] = Subject_Parameters[1];
                Subject_UnitsGuard_AntiDuplicate_Include[Sbj_Stats_Decrement - 1] = 0;
                Subject_UnitsGuard_AntiDuplicate_Exclude[Sbj_Stats_Decrement - 1] = 0;
                Sbj_Stats_Decrement++;
            }
            Sleep(1500);
            continue;
        }
        else
        {
            gotoxy(30, 44);
            printf("\xDD WARNING \xAF You have inputted a wrong number! Out of Choice.Bonds! Reinitialing Function...");
            Sleep(2000);
            continue;
        }
    }
}
//Continue Function...

int Func_Stdnt_ScholarshipCheck()
//struct Enrollment_InformationReceiver Data_Received, int Selected_CandiateSubjects
{
    // Displays Current Status
    char Confirmation;
    float GradeLowCheck = 0, GradeHighCheck = 0, GradeAverageCheck_1stSem = 0, GradeAverageCheck_2ndSem = 0;
    printf("Do you want to apply for a scholarship?");
    switch (Confirmation = getche())
    {
    case 'y': //Falls Through
    case 'Y':
        printf("What is your lowest grade?");
        scanf("%f", &GradeLowCheck);
        printf("What is your highest grade?");
        scanf("%f", &GradeHighCheck);
        printf("What is your average grade on 1st Semester");
        scanf("%f", &GradeAverageCheck_1stSem);
        printf("What is your average grade on 2nd Semester");
        scanf("%f", &GradeAverageCheck_2ndSem);
        // Checker
        //printf("Grade Received. You have %i Percent Discount Scholarship! Proceeding...");
        PrintDocument_FinalTranscript();
    case 'n': // Falls Through
    case 'N':
        printf("Okay. Proceeding....");
    default:
        printf("Unrecognized Input!");
    }
    /*
    system("CLS");
    int Parameters = 0;
    printf("\xDD INFO \xAF We on the 4th Step of this!");
    while (Parameters != Selected_CandiateSubjects)
    {
        printf("%s | %s | %s\n", Data_Received.Subject_CodeName_Receiver[Parameters], Data_Received.Subject_FullName_Receiver[Parameters], Data_Received.Subject_LinearTime_Receiver[Parameters]);
        Parameters++;
    }
    getch();
    return ERROR_SUCCESS;
    */
}

void Func_Mode_Of_Payment()
{
}
void PrintDocument_FinalTranscript()
{
}

void Func_ERLM_Recheck()
{
}

// Uncategoterized Function
void gotoxy(int x, int y)
{
    COORD ConsoleXY = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ConsoleXY);
}
