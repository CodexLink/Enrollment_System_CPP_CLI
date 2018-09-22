#include <stdio.h>   // Just Basic Input Output Header File
#include <stdlib.h>  // For SYSTEM Command
#include <conio.h>   // For Getch()
#include <windows.h> // Windows Designed Only Header, This Rips Compatibility.
#include <time.h>    // For Time Display and Such
#include <string.h>  // String Handling for Usage of Structure and Database

// Defined STRINGS, Call this and the string will show up or error code
#define VERSION_NUMBER "1530-09172018-CLOSED BETA"
#define PRODUCT_NAME "Team LM | ARiS Alternative Enrollment System for TiP Engineering and Architecture | C CLI Runtime"
#define FUNCTION_UNFINISHED 1362565
#define DATABASE_NOT_FOUND 40
#define FUNCTION_LINEAR_DISCONTINUE 1827090918
#define FUNCTION_STEP1 "Team LM | ARiS Alternative Enrollment System for TiP Engineering and Architecture | C CLI Runtime|D Current Step \xAF 1st Step Filling up Information"
#define FUNCTION_STEP2 "Team LM | ARiS Alternative Enrollment System for TiP Engineering and Architecture | C CLI Runtime | Current Step \xAF 2nd Step \xAF Course Registration"
#define FUNCTION_STEP2_1 "Team LM | ARiS Alternative Enrollment System for TiP Engineering and Architecture | C CLI Runtime | Current Step \xAF 2nd Step | Course Registration \xAF Year Selection"
#define FUNCTION_STEP3 "Team LM | ARiS Alternative Enrollment System for TiP Engineering and Architecture | C CLI Runtime | Current Step \xAF 3rd Step | Subject Enrollment Selection"
#define FUNCTION_STEP4 "Team LM | ARiS Alternative Enrollment System for TiP Engineering and Architecture | C CLI Runtime | Current Step \xAF 4th Step | Slight Overview Data"
#define FUNCTION_STEP5 "Team LM | ARiS Alternative Enrollment System for TiP Engineering and Architecture | C CLI Runtime | Current Step \xAF 5th Step | Scholarship and Mode of Payment"
#define FUNCTION_STEP6 "Team LM | ARiS Alternative Enrollment System for TiP Engineering and Architecture | C CLI Runtime | Current Step \xAF Confirmation | Overall Overview"
#define FUNCTION_STEP7 "Team LM | ARiS Alternative Enrollment System for TiP Engineering and Architecture | C CLI Runtime | Current Step \xAF End of Process"

// Structure Variables for New Student, Used For Filling Information
// After Function Update On Function...
struct OnHold_DataRecords
{
    char stdnt_FName[30],
        stdnt_MName[30],
        stdnt_LName[30],
        stdnt_PhoneNum[11],
        stdnt_MobileNum[11],
        stdnt_EmerNum[11],
        stdnt_MothersName[30],
        stdnt_MothersInfoJob[30],
        stdnt_MothersInfoContact[30],
        stdnt_FathersName[30],
        stdnt_FathersInfoJob[30],
        stdnt_FathersInfoContact[30],
        stdnt_SourceInterest[MAX_PATH],
        stdnt_LastSchoolYear[30],
        stdnt_LastSchoolStrand[30],
        stdnt_Gender[6],
        stdnt_Birthday[30],
        stdnt_Nationality[30],
        stdnt_SpecialBehavioral[50],
        stdnt_Address[MAX_PATH],
        stdnt_Email[40],
        stdnt_POC_Emergency[30],
        stdnt_StudentType[20],
        MainCourse_CodeName_Passer[40],
        MainCourse_FullName_Passer[40],
        Course_YearChoice[20],
        Course_SemSelection[20],
        Generated_stdnt_NewPass[100],
        Generated_stdnt_NewUser[100],
        Granted_ScholarshipStats[16],
        Granted_ScholarshipDetails[65],
        PaymentMethod[12],
        FileName_Coordinate[MAX_PATH];
    int GradeLowest,
        GradeHighest,
        GradeGeneralAverage_LastSem,
        Generated_StudentID;
    long long int stdnt_NumGenerated;
};
// Structure For Old Student Checker Credentials
struct Old_StudentRecords
{
    int stdnt_StudentID;
    char stdnt_Username[20], stdnt_Password[32], stdnt_UserPersonalName[20];
};
// used To Receive Only True
struct Enrollment_InformationReceiver
{
    char *Subject_CodeName_Receiver[12];
    char *Subject_FullName_Receiver[12];
    char *Subject_ScheduleDay_Receiver[12];
    char *Subject_LinearTime_Receiver[12];
    int Subject_Units_Receiver[12];
    int Subject_Candidates;
    int Subjects_Selected;
};

struct OnHold_DataRecords OnProcess_StudentData;
struct Enrollment_InformationReceiver ERLM_DataReceiver;
struct Old_StudentRecords OldDataProcess_StudentData;
void SetCursorCoord_XY(int x, int y); //Custom Function To Call SetCursorCoord_XY. @Conio.h cannot be used for Windows.
int Main_Menu();                      // Call For Main Menu
//void Func_OldStdnt_ERLM();            // Old Student Function Prototype
//int Func_OldStd_ERLM_Menu(struct Old_StudentRecords OldData);

//Function Prototype on Ascending Order
void Func_NewStdnt_FillUp();
int Func_NewStdnt_InfoCheck();
int Func_NewStdnt_CourseReg();
int Func_NewStdnt_YearSemSelect();
int Func_SubjectUnit_Selection(char **Subject_CodeName, char **Subject_FullName, char **Subject_LinearTime, int Subject_Units[12]);
int Func_Stdnt_ScholarshipCheck();
void Func_Mode_Of_Payment();
void GetDataEnrolleeInformation();
void Func_Final_Overview(int Final_Comp_SelectedSubjects, int Subject_ExpectedCandidates);
void Func_PrintDocument_FinalTranscript();

void Func_ERLM_Check();

void GenerateUserPass_withGenerateFileName();
char GenerateFileName();

int main()
{
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SHOW_FULLSCREEN); // Temporarily Commented due to Terminal Shows CMD but Small Font
    Main_Menu();
}
int Main_Menu()
{
    char *Subject_CodeName[12] = {"PHILO 001", "HUM 001", "HUM 002", "ARCH 005-8"};
    char *Subject_FullName[12] = {"PHILOSOPHY", "HUMANITIES", "SOCIOLOGY OF ANTHROPOLOGY", "ARCHITECTURAL DESIGN 9", "SPECIALIZATION 2", "ARCHITECTURE COMPREHENSIVE COURSE"};
    char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM"};
    int Subject_Units[12] = {3, 3, 3, 5, 3, 3};
    SetConsoleTitle(PRODUCT_NAME);
    system("CLS");
    while (1)
    { // This will loop forever because wtf is 1?
        int Selection_1 = 0;
        system("CLS");
        SetCursorCoord_XY(30, 3);
        printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        SetCursorCoord_XY(30, 4);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        SetCursorCoord_XY(30, 5);
        printf("\xBA \xDD Version " VERSION_NUMBER "\t\t\t\t\t\t\t\t       \xBA");
        SetCursorCoord_XY(30, 6);
        printf("\xBA \xDD " PRODUCT_NAME "    \xBA");
        SetCursorCoord_XY(30, 7);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        SetCursorCoord_XY(30, 8);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        SetCursorCoord_XY(30, 10);
        printf("\xC9\xCD\xCD \xDD Main Menu \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        SetCursorCoord_XY(30, 11);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        SetCursorCoord_XY(30, 12);
        printf("\xBA [1] \xDD Old Student\t\t\t\t\t\t\t\t\t\t       \xBA");
        SetCursorCoord_XY(30, 13);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        SetCursorCoord_XY(30, 14);
        printf("\xBA [2] \xDD New Student\t\t\t\t\t\t\t\t\t\t       \xBA");
        SetCursorCoord_XY(30, 15);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        SetCursorCoord_XY(30, 16);
        printf("\xBA [3] \xDD Reprint Enrollment Student Form | Registration Form\t\t\t\t\t       \xBA");
        SetCursorCoord_XY(30, 17);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        SetCursorCoord_XY(30, 18);
        printf("\xBA [4] \xDD Manage Enrollment\t\t\t\t\t\t\t\t\t\t       \xBA");
        SetCursorCoord_XY(30, 19);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        SetCursorCoord_XY(30, 20);
        printf("\xBA [5] \xDD Exit Application\t\t\t\t\t\t\t\t\t\t       \xBA");
        SetCursorCoord_XY(30, 21);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        SetCursorCoord_XY(30, 22);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        SetCursorCoord_XY(30, 24);
        printf("\xC8\xAF Press a key that corresponds your decision [1 - 5] \xDD\xAF ");
        switch (Selection_1 = getche())
        {
        case '1':
            Func_OldStdnt_ERLM();
            break;
        case '2':
            Func_NewStdnt_FillUp();
            break;
        case '3':
            Func_ERLM_Check();
            break;
        case '4':
            SetCursorCoord_XY(30, 26);
            printf("\xC9\xCD\xCD \xDD Warning! \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
            SetCursorCoord_XY(30, 27);
            printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
            SetCursorCoord_XY(30, 28);
            printf("\xBA Access Denied! Please rerun the program with '/mgr_md' in order to access this function!\t       \xBA");
            SetCursorCoord_XY(30, 29);
            printf("\xBA Press any keyboard key to terminate the program...\t\t\t\t\t\t\t       \xBA");
            SetCursorCoord_XY(30, 30);
            printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
            SetCursorCoord_XY(30, 31);
            printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
            getch();
            exit(0); // Gracefully Terminate A Program / Process
        case '5':
            SetConsoleTitle("Terminating Enrollment System | LM Enrollment System");
            SetCursorCoord_XY(30, 26);
            printf("\xC9\xCD\xCD \xDD INFORMATION \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
            SetCursorCoord_XY(30, 27);
            printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
            SetCursorCoord_XY(30, 28);
            printf("\xBA \xAF Terminating LM Enrollment System...\t\t\t\t\t\t\t\t       \xBA");
            SetCursorCoord_XY(30, 29);
            printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
            SetCursorCoord_XY(30, 30);
            printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
            //Sleep(2500);
            return EXIT_SUCCESS;
        case '6':
            //Func_PrintDocument_FinalTranscript();
            Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
        default:
            SetCursorCoord_XY(30, 26);
            printf("\xC9\xCD\xCD \xDD Warning! \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
            SetCursorCoord_XY(30, 27);
            printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
            SetCursorCoord_XY(30, 28);
            puts("\xBA \xAF Unrecognized Input!\t\t\t\t\t\t\t\t\t\t       \xBA");
            SetCursorCoord_XY(30, 29);
            printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
            SetCursorCoord_XY(30, 30);
            printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
            //Sleep(1500);
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
        //Sleep(1750);
        printf("Name %s | Student Number: %i", OldStudent_Continuation.stdnt_old_UserPersonalName, OldStudent_Continuation.stdnt_old_StudentIdentity);
        printf("Your Current Level is %c", ENRL_Stats_CurrentLevel);
        printf("Enrollment Eligibility %c", ENRL_Stats_Eligible);
        for (Counter_For_Selection; Counter_For_Selection < 5; Counter_For_Selection++)
        {
            printf(ENRL_Selection_Eng[Counter_For_Selection]);
        }
        //Sleep(999);
        printf("Function Undefined... Press any key to continue...");
        getch();
        return FUNCTION_UNFINISHED;
    }
}

/////////////////////////////////////////////////////////////////////////////////////
void Func_NewStdnt_FillUp()
{
    // Initialize This From Struct Variable
    int FillUp_Stage = 0;
    system("CLS");
    SetConsoleTitle(FUNCTION_STEP1);
    while (1)
    {
        system("CLS");
        SetCursorCoord_XY(30, 3);
        printf("\xC9\xCD\xCD \xDD CURRENT PROGRESS \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        SetCursorCoord_XY(30, 4);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, 5);
        printf("\xBA [ \xDD\xAF [1st Step of Part 1 \xAF Filling up Student Information] \xAF 2nd \xAF 3rd \xAF 4th \xAF 5th \xAF Confirm \xAF End]\t   \xBA\n");
        SetCursorCoord_XY(30, 6);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, 7);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        SetCursorCoord_XY(30, 9);
        printf("\xC9\xCD\xCD \xDD Information \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        SetCursorCoord_XY(30, 10);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, 11);
        printf("\xBA \xAF Please provide your information to let us identify you as a future student!\t\t\t\t   \xBA");
        SetCursorCoord_XY(30, 12);
        printf("\xBA \xDD NOTE \xDD \xAF Please input your information accurately before pressing enter!\t\t\t\t   \xBA");
        SetCursorCoord_XY(30, 13);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, 14);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        if (FillUp_Stage == 0)
        {
            SetCursorCoord_XY(30, 16);
            printf("\xFE\xCD\xCD IDENTITY INFORMATION \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
            SetCursorCoord_XY(30, 18);
            printf("\xAF [1] Enrollee's First Name");
            SetCursorCoord_XY(30, 20);
            printf("\xC8\xAF INPUT \xDD\xAF ");
            fgets(OnProcess_StudentData.stdnt_FName, sizeof(OnProcess_StudentData.stdnt_FName), stdin);
            strtok(OnProcess_StudentData.stdnt_FName, "\n");
            SetCursorCoord_XY(30, 22);
            printf("\xAF [2] Enrollee's Middle Name");
            SetCursorCoord_XY(30, 24);
            printf("\xC8\xAF INPUT \xDD\xAF ");
            fgets(OnProcess_StudentData.stdnt_MName, sizeof(OnProcess_StudentData.stdnt_MName), stdin);
            strtok(OnProcess_StudentData.stdnt_MName, "\n");
            SetCursorCoord_XY(30, 26);
            printf("\xAF [3] Enrollee's Last Name ");
            SetCursorCoord_XY(30, 28);
            printf("\xC8\xAF INPUT \xDD\xAF ");
            fgets(OnProcess_StudentData.stdnt_LName, sizeof(OnProcess_StudentData.stdnt_LName), stdin);
            strtok(OnProcess_StudentData.stdnt_LName, "\n");
            //Func_PrintDocument_FinalTranscript();
            //Func_EndofProcess();
            SetCursorCoord_XY(30, 30);
            printf("\xAF [4] Father's Name \xDD [Surname, First Name]");
            SetCursorCoord_XY(30, 32);
            printf("\xC8\xAF INPUT \xDD\xAF ");
            fgets(OnProcess_StudentData.stdnt_FathersName, sizeof(OnProcess_StudentData.stdnt_FathersName), stdin);
            strtok(OnProcess_StudentData.stdnt_FathersName, "\n");
            SetCursorCoord_XY(30, 34);
            printf("\xAF [5] Father's Current Occupation");
            SetCursorCoord_XY(30, 36);
            printf("\xC8\xAF INPUT \xDD\xAF ");
            fgets(OnProcess_StudentData.stdnt_FathersInfoJob, sizeof(OnProcess_StudentData.stdnt_FathersInfoJob), stdin);
            strtok(OnProcess_StudentData.stdnt_FathersInfoJob, "\n");
            SetCursorCoord_XY(30, 38);
            printf("\xAF [6] Father's Contact Number \xDD [Telephone is Applicable, Mobile # Preferred]");
            SetCursorCoord_XY(30, 40);
            printf("\xC8\xAF INPUT \xDD\xAF ");
            fgets(OnProcess_StudentData.stdnt_FathersInfoContact, sizeof(OnProcess_StudentData.stdnt_FathersInfoContact), stdin);
            strtok(OnProcess_StudentData.stdnt_FathersInfoContact, "\n");
            SetCursorCoord_XY(30, 42);
            printf("\xAF [7] Mother's Name \xDD [Surname, FirstName]");
            SetCursorCoord_XY(30, 44);
            printf("\xC8\xAF INPUT \xDD\xAF ");
            fgets(OnProcess_StudentData.stdnt_MothersName, sizeof(OnProcess_StudentData.stdnt_MothersName), stdin);
            strtok(OnProcess_StudentData.stdnt_MothersName, "\n");
            SetCursorCoord_XY(30, 46);
            printf("\xAF [8] Mother's Current Occupation");
            SetCursorCoord_XY(30, 48);
            printf("\xC8\xAF INPUT \xDD\xAF ");
            fgets(OnProcess_StudentData.stdnt_MothersInfoJob, sizeof(OnProcess_StudentData.stdnt_MothersInfoJob), stdin);
            strtok(OnProcess_StudentData.stdnt_MothersInfoJob, "\n");
            SetCursorCoord_XY(30, 50);
            printf("\xAF [9] Mother's Contact Number \xDD [Telephone is Applicable, Mobile # Preferred]");
            SetCursorCoord_XY(30, 52);
            printf("\xC8\xAF INPUT \xDD\xAF ");
            fgets(OnProcess_StudentData.stdnt_MothersInfoContact, sizeof(OnProcess_StudentData.stdnt_MothersInfoContact), stdin);
            strtok(OnProcess_StudentData.stdnt_MothersInfoContact, "\n");
            SetCursorCoord_XY(30, 54);
            printf("\xFE\xCD\xCD USER INPUT DONE FOR IDENTITY INFORMATION \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
            //Sleep(3000);
            FillUp_Stage++;
            continue;
        }
        else if (FillUp_Stage == 1)
        {
            SetCursorCoord_XY(30, 16);
            printf("\xFE\xCD\xCD GENERAL INFORMATION \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
            SetCursorCoord_XY(30, 18);
            printf("\xAF [1] Gender \xDD [Male or Female]");
            SetCursorCoord_XY(30, 20);
            printf("\xC8\xAF INPUT \xDD\xAF ");
            fgets(OnProcess_StudentData.stdnt_Gender, sizeof(OnProcess_StudentData.stdnt_Gender), stdin);
            strtok(OnProcess_StudentData.stdnt_Gender, "\n");
            SetCursorCoord_XY(30, 22);
            printf("\xAF [2] Birthday \xDD [Month | Day, Year IN Word]");
            SetCursorCoord_XY(30, 24);
            printf("\xC8\xAF INPUT \xDD\xAF ");
            fgets(OnProcess_StudentData.stdnt_Birthday, sizeof(OnProcess_StudentData.stdnt_Birthday), stdin);
            strtok(OnProcess_StudentData.stdnt_Birthday, "\n");
            SetCursorCoord_XY(30, 26);
            printf("\xAF [3] Permanent Address");
            SetCursorCoord_XY(30, 27);
            printf("Syntax \xDD\xAF [House #, Residential Name, Strt #, Brgy Name, City, ZIP Code, Metro Manila or Any Province Name]"); //Include City and Village, ZIP CODE
            SetCursorCoord_XY(30, 29);
            printf("\xC8\xAF INPUT \xDD\xAF ");
            fgets(OnProcess_StudentData.stdnt_Address, sizeof(OnProcess_StudentData.stdnt_Address), stdin);
            strtok(OnProcess_StudentData.stdnt_Address, "\n");
            SetCursorCoord_XY(30, 31);
            printf("\xAF [4] Nationality");
            SetCursorCoord_XY(30, 33);
            printf("\xC8\xAF INPUT \xDD\xAF ");
            fgets(OnProcess_StudentData.stdnt_Nationality, sizeof(OnProcess_StudentData.stdnt_Nationality), stdin);
            strtok(OnProcess_StudentData.stdnt_Nationality, "\n");
            SetCursorCoord_XY(30, 35);
            printf("\xAF [5] Mobile Number");
            SetCursorCoord_XY(30, 37);
            printf("\xAF INPUT \xDD\xAF ");
            fgets(OnProcess_StudentData.stdnt_MobileNum, sizeof(OnProcess_StudentData.stdnt_MobileNum), stdin);
            strtok(OnProcess_StudentData.stdnt_MobileNum, "\n");
            fflush(stdin); // Flushes \n on ScanF to prevent fgets to be skipped
            SetCursorCoord_XY(30, 39);
            printf("\xAF [6] House Telephone Number");
            SetCursorCoord_XY(30, 41);
            printf("\xC8\xAF INPUT \xDD\xAF ");
            fgets(OnProcess_StudentData.stdnt_PhoneNum, sizeof(OnProcess_StudentData.stdnt_PhoneNum), stdin);
            strtok(OnProcess_StudentData.stdnt_PhoneNum, "\n");
            fflush(stdin); // Flushes \n on ScanF to prevent fgets to be skipped
            SetCursorCoord_XY(30, 43);
            printf("\xAF [7] Emergency Number and Emergency Point of Contact (Seperated)");
            SetCursorCoord_XY(30, 45);
            printf("\xAF [7.1] Input Emergency Number");
            SetCursorCoord_XY(30, 47);
            printf("\xC8\xAF INPUT \xDD\xAF ");
            fgets(OnProcess_StudentData.stdnt_EmerNum, sizeof(OnProcess_StudentData.stdnt_EmerNum), stdin);
            strtok(OnProcess_StudentData.stdnt_EmerNum, "\n");
            fflush(stdin); // Flushes \n on ScanF to prevent fgets to be skipped
            SetCursorCoord_XY(30, 49);
            printf("\xAF [7.2] Input Name Emergency Point of Contact");
            SetCursorCoord_XY(30, 51);
            printf("\xC8\xAF INPUT \xDD\xAF ");
            fgets(OnProcess_StudentData.stdnt_POC_Emergency, sizeof(OnProcess_StudentData.stdnt_POC_Emergency), stdin);
            strtok(OnProcess_StudentData.stdnt_POC_Emergency, "\n");
            SetCursorCoord_XY(30, 53);
            printf("\xFE\xCD\xCD USER INPUT DONE FOR GENERAL INFORMATION \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
            //Sleep(3000);
            FillUp_Stage++;
            continue;
        }
        else if (FillUp_Stage == 2)
        {
            SetCursorCoord_XY(30, 16);
            printf("\xFE\xCD\xCD TECHNICAL INFORMATION \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
            SetCursorCoord_XY(30, 18);
            printf("\xAF [1] Source of Interest in this Institution \xDD [Any Reason]");
            SetCursorCoord_XY(30, 20);
            printf("\xC8\xAF INPUT \xDD\xAF ");
            fgets(OnProcess_StudentData.stdnt_SourceInterest, sizeof(OnProcess_StudentData.stdnt_SourceInterest), stdin);
            strtok(OnProcess_StudentData.stdnt_SourceInterest, "\n");
            SetCursorCoord_XY(30, 22);
            printf("\xAF [2] Last School Year Attended \xDD [School Name (Abbrv. Acceptable), SchoolYear, Level. Add Comma as Seperator]");
            SetCursorCoord_XY(30, 24);
            printf("\xC8\xAF INPUT \xDD\xAF ");
            fgets(OnProcess_StudentData.stdnt_LastSchoolYear, sizeof(OnProcess_StudentData.stdnt_LastSchoolYear), stdin);
            strtok(OnProcess_StudentData.stdnt_LastSchoolYear, "\n");
            SetCursorCoord_XY(30, 26);
            printf("\xAF [3] For Senior High School Student, Strand Taken [Put None, if not a SHS Student.]");
            SetCursorCoord_XY(30, 28);
            printf("\xC8\xAF INPUT \xDD\xAF ");
            fgets(OnProcess_StudentData.stdnt_LastSchoolStrand, sizeof(OnProcess_StudentData.stdnt_LastSchoolStrand), stdin);
            strtok(OnProcess_StudentData.stdnt_LastSchoolStrand, "\n");
            SetCursorCoord_XY(30, 30);
            printf("\xAF [4] Personal Email");
            SetCursorCoord_XY(30, 32);
            printf("\xC8\xAF INPUT \xDD\xAF ");
            fgets(OnProcess_StudentData.stdnt_Email, sizeof(OnProcess_StudentData.stdnt_Email), stdin);
            strtok(OnProcess_StudentData.stdnt_Email, "\n");
            SetCursorCoord_XY(30, 34);
            printf("\xAF [5] Behavioral Issues");
            SetCursorCoord_XY(30, 36);
            printf("\xC8\xAF INPUT \xDD\xAF ");
            fgets(OnProcess_StudentData.stdnt_SpecialBehavioral, sizeof(OnProcess_StudentData.stdnt_SpecialBehavioral), stdin);
            strtok(OnProcess_StudentData.stdnt_SpecialBehavioral, "\n");
            FillUp_Stage++;
            break;
        }
        else
        {
            break;
        }
    }
    SetCursorCoord_XY(30, 38);
    printf("\xFE\xCD\xCD USER INPUT DONE \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    //Sleep(1750);
    Func_NewStdnt_InfoCheck();
}

int Func_NewStdnt_InfoCheck()
{
    char Data_Confirmation;
    system("CLS");
    SetCursorCoord_XY(30, 3);
    printf("\xC9\xCD\xCD \xDD CURRENT PROGRESS \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
    SetCursorCoord_XY(30, 4);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    SetCursorCoord_XY(30, 5);
    printf("\xBA [ \xDD\xAF [1st Step of Part 2 \xAF Student Data Information Check] \xAF 2nd \xAF 3rd \xAF 4th \xAF 5th \xAF Confirm \xAF End]\t   \xBA\n");
    SetCursorCoord_XY(30, 6);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    SetCursorCoord_XY(30, 7);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
    SetCursorCoord_XY(30, 9);
    printf("\xFE\xCD\xCD IDENTITY INFORMATION \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetCursorCoord_XY(30, 11);
    printf("\xAF [1] Enrollee's Name \xDD\xAF %s, %s %s", OnProcess_StudentData.stdnt_LName, OnProcess_StudentData.stdnt_FName, OnProcess_StudentData.stdnt_MName);
    SetCursorCoord_XY(30, 13);
    printf("\xAF [2] [ Parent ] Mother's Information \xAF %s \xDD %s \xDD %s", OnProcess_StudentData.stdnt_MothersName, OnProcess_StudentData.stdnt_MothersInfoJob, OnProcess_StudentData.stdnt_MothersInfoContact);
    SetCursorCoord_XY(30, 15);
    printf("\xAF [3] [ Parent ] Father's Information \xAF %s \xDD %s \xDD %s", OnProcess_StudentData.stdnt_FathersName, OnProcess_StudentData.stdnt_FathersInfoJob, OnProcess_StudentData.stdnt_FathersInfoContact);
    SetCursorCoord_XY(30, 17);
    printf("\xFE\xCD\xCD GENERAL INFORMATION \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetCursorCoord_XY(30, 19);
    printf("\xAF [4] Gender \xDD\xAF %s", OnProcess_StudentData.stdnt_Gender);
    SetCursorCoord_XY(30, 21);
    printf("\xAF [5] Birthday \xDD\xAF %s", OnProcess_StudentData.stdnt_Birthday);
    SetCursorCoord_XY(30, 23);
    printf("\xAF [6] Permanent Address");
    SetCursorCoord_XY(30, 25);
    printf("\xC8\xAF %s", OnProcess_StudentData.stdnt_Address); //Include City and Village, ZIP CODE
    SetCursorCoord_XY(30, 27);
    printf("\xAF [7] Nationality \xDD\xAF %s", OnProcess_StudentData.stdnt_Nationality);
    SetCursorCoord_XY(30, 29);
    printf("\xAF [8] Mobile Number \xDD\xAF %s", OnProcess_StudentData.stdnt_MobileNum);
    SetCursorCoord_XY(30, 31);
    printf("\xAF [9] Phone Number \xDD\xAF %s", OnProcess_StudentData.stdnt_PhoneNum);
    SetCursorCoord_XY(30, 33);
    printf("\xAF [10] Emergency Number and Emergency Point of Contact \xDD\xAF %s \xDD %s", OnProcess_StudentData.stdnt_EmerNum, OnProcess_StudentData.stdnt_POC_Emergency);
    SetCursorCoord_XY(30, 35);
    printf("\xFE\xCD\xCD TECHNICAL INFORMATION \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetCursorCoord_XY(30, 37);
    printf("\xAF [11] Source of Interest in this Institution \xDD\xAF %s", OnProcess_StudentData.stdnt_SourceInterest);
    SetCursorCoord_XY(30, 39);
    printf("\xAF [12] Last School Year Attended \xDD\xAF %s", OnProcess_StudentData.stdnt_LastSchoolYear);
    SetCursorCoord_XY(30, 41);
    printf("\xAF [13] For Senior High School Student, Strand Taken \xDD\xAF %s", OnProcess_StudentData.stdnt_LastSchoolStrand);
    SetCursorCoord_XY(30, 43);
    printf("\xAF [14] Personal Email \xDD\xAF %s", OnProcess_StudentData.stdnt_Email);
    SetCursorCoord_XY(30, 45);
    printf("\xAF [15] Behavioral Issues \xDD\xAF %s", OnProcess_StudentData.stdnt_SpecialBehavioral);
    SetCursorCoord_XY(30, 47);
    printf("\xC9\xCD\xCD \xDD Question \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
    SetCursorCoord_XY(30, 48);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    SetCursorCoord_XY(30, 49);
    printf("\xBA \xAF Are the sure the following encoded data is correct and accurate?\t\t\t\t\t   \xBA");
    SetCursorCoord_XY(30, 50);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    SetCursorCoord_XY(30, 51);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
    SetCursorCoord_XY(30, 52);
    printf("\xC8\xAF Press a key that corresponds your decision [|Y|es or |N|o] \xDD\xAF ");
    Data_Confirmation = getche();
    if (Data_Confirmation == 'Y' || Data_Confirmation == 'y')
    {
        SetCursorCoord_XY(30, 54);
        printf("\xAF \xDD INFO \xDD Data Received, Proceeding to Step 2 \xDD Course Registration...");
        //Sleep(1750);
        Func_NewStdnt_CourseReg();
    }
    else if (Data_Confirmation == 'N' || Data_Confirmation == 'n')
    {
        SetCursorCoord_XY(30, 54);
        printf("\xAF \xDD INFO \xDD Returning To Step 1 \xDD Filling up Personal Information...");
        //Sleep(3000);
        Func_NewStdnt_FillUp();
    }
    else
    {
        SetCursorCoord_XY(30, 54);
        printf("\xAF \xDD ERROR \xAF Sorry, I don't understand that...");
        //Sleep(1750);
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
    SetCursorCoord_XY(30, 3);
    printf("\xC9\xCD\xCD \xDD CURRENT PROGRESS \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
    SetCursorCoord_XY(30, 4);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    SetCursorCoord_XY(30, 5);
    printf("\xBA [1st \xAF \xDD\xAF [2nd Step of Part 1 \xAF Branch Course Selection] \xAF 3rd \xAF 4th \xAF 5th \xAF Confirm \xAF End]\t\t   \xBA");
    SetCursorCoord_XY(30, 6);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    SetCursorCoord_XY(30, 7);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
    SetCursorCoord_XY(30, 9);
    printf("\xC9\xCD\xCD \xDD Take This Note \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
    SetCursorCoord_XY(30, 10);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    SetCursorCoord_XY(30, 11);
    printf("\xBA Please choose your branch course that you want to get into / take into.\t\t\t\t           \xBA");
    SetCursorCoord_XY(30, 12);
    printf("\xBA \xDD WARN \xDD \xAF Please choose your branch course wisely, there is no going back when you enroll successfully!   \xBA");
    SetCursorCoord_XY(30, 13);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    SetCursorCoord_XY(30, 14);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
    SetCursorCoord_XY(30, 16);
    printf("\xC9\xCD\xCD \xDD PLEASE CHOOSE A BRANCH BASE COURSE \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
    SetCursorCoord_XY(30, 17);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    SetCursorCoord_XY(30, 18);
    printf("\xBA \t[1] \xDD College of Engineering \t\t       \xDD\t [2] \xDD College of Architecture\t\t   \xBA");
    SetCursorCoord_XY(30, 19);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    SetCursorCoord_XY(30, 20);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
    SetCursorCoord_XY(30, 22);
    printf("\xC8\xAF Press a key that corresponds your decision [1 - 2] \xDD\xAF ");
    switch (BranchBase_Accepter = getche())
    {
    case '1':
        SetCursorCoord_XY(30, 24);
        printf("\xAF \xDD INFO \xDD You have chosen 'College of Engineering' as a branch base course...");
        //Sleep(1750);
        while (1)
        {
            system("CLS");
            SetCursorCoord_XY(30, 3);
            printf("\xC9\xCD\xCD \xDD CURRENT PROGRESS \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
            SetCursorCoord_XY(30, 4);
            printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
            SetCursorCoord_XY(30, 5);
            printf("\xBA [1st \xAF \xDD\xAF [2nd Step of Part 2 \xAF Main Course Selection] \xAF 3rd \xAF 4th \xAF 5th \xAF Confirm \xAF End]\t\t   \xBA");
            SetCursorCoord_XY(30, 6);
            printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
            SetCursorCoord_XY(30, 7);
            printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
            SetCursorCoord_XY(30, 9);
            printf("\xC9\xCD\xCD \xDD CHOICE YOUR MAIN / DESIRED COURSE \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
            SetCursorCoord_XY(30, 10);
            printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
            SetCursorCoord_XY(30, 11);
            printf("\xBA \xAF [1] \xDD %s \xDD %s\t\t\t\t\t\t\t\t\t   \xBA", MainCourse_FullName[0], MainCourse_CodeName[0]);
            SetCursorCoord_XY(30, 12);
            printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
            SetCursorCoord_XY(30, 13);
            printf("\xBA \xAF [2] \xDD %s \xDD %s\t\t\t\t\t\t\t\t\t   \xBA", MainCourse_FullName[1], MainCourse_CodeName[1]);
            SetCursorCoord_XY(30, 14);
            printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
            SetCursorCoord_XY(30, 15);
            printf("\xBA \xAF [3] \xDD %s \xDD %s\t\t\t\t\t\t\t\t\t   \xBA", MainCourse_FullName[2], MainCourse_CodeName[2]);
            SetCursorCoord_XY(30, 16);
            printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
            SetCursorCoord_XY(30, 17);
            printf("\xBA \xAF [4] \xDD %s \xDD %s\t\t\t\t\t\t\t\t\t   \xBA", MainCourse_FullName[3], MainCourse_CodeName[3]);
            SetCursorCoord_XY(30, 18);
            printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
            SetCursorCoord_XY(30, 19);
            printf("\xBA \xAF [5] \xDD %s \xDD %s\t\t\t\t\t\t\t   \xBA", MainCourse_FullName[4], MainCourse_CodeName[4]);
            SetCursorCoord_XY(30, 20);
            printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
            SetCursorCoord_XY(30, 21);
            printf("\xBA \xAF [6] \xDD %s \xDD %s\t\t\t\t\t\t\t\t\t   \xBA", MainCourse_FullName[5], MainCourse_CodeName[5]);
            SetCursorCoord_XY(30, 22);
            printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
            SetCursorCoord_XY(30, 23);
            printf("\xBA \xAF [7] \xDD %s \xDD %s\t\t\t\t\t\t\t\t\t   \xBA", MainCourse_FullName[6], MainCourse_CodeName[6]);
            SetCursorCoord_XY(30, 24);
            printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
            SetCursorCoord_XY(30, 25);
            printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
            SetCursorCoord_XY(30, 27);
            printf("\xC8\xAF Press a key that corresponds your decision [1 - 7] \xDD\xAF "); // Fix this also
            switch (MainCourse_Accepter = getche())
            {
            case '1':
                SetCursorCoord_XY(30, 29);
                printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding To Step 2 of Part 3...", MainCourse_FullName[0]);
                //Sleep(1750);
                strcpy(OnProcess_StudentData.MainCourse_CodeName_Passer, MainCourse_CodeName[0]);
                strcpy(OnProcess_StudentData.MainCourse_FullName_Passer, MainCourse_FullName[0]);
                Func_NewStdnt_YearSemSelect();
                break;
            case '2':
                SetCursorCoord_XY(30, 29);
                printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding To Step 2 of Part 3...", MainCourse_FullName[1]);
                //Sleep(1750);
                strcpy(OnProcess_StudentData.MainCourse_CodeName_Passer, MainCourse_CodeName[1]);
                strcpy(OnProcess_StudentData.MainCourse_FullName_Passer, MainCourse_FullName[1]);
                Func_NewStdnt_YearSemSelect();
                break;
            case '3':
                SetCursorCoord_XY(30, 29);
                printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding To Step 2 of Part 3...", MainCourse_FullName[2]);
                //Sleep(1750);
                strcpy(OnProcess_StudentData.MainCourse_CodeName_Passer, MainCourse_CodeName[2]);
                strcpy(OnProcess_StudentData.MainCourse_FullName_Passer, MainCourse_FullName[2]);
                Func_NewStdnt_YearSemSelect();
                break;
            case '4':
                SetCursorCoord_XY(30, 29);
                printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding To Step 2 of Part 3...", MainCourse_FullName[3]);
                //Sleep(1750);
                strcpy(OnProcess_StudentData.MainCourse_CodeName_Passer, MainCourse_CodeName[3]);
                strcpy(OnProcess_StudentData.MainCourse_FullName_Passer, MainCourse_FullName[3]);
                Func_NewStdnt_YearSemSelect();
                break;
            case '5':
                SetCursorCoord_XY(30, 29);
                printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding To Step 2 of Part 3...", MainCourse_FullName[4]);
                //Sleep(1750);
                strcpy(OnProcess_StudentData.MainCourse_CodeName_Passer, MainCourse_CodeName[4]);
                strcpy(OnProcess_StudentData.MainCourse_FullName_Passer, MainCourse_FullName[4]);
                Func_NewStdnt_YearSemSelect();
                break;
            case '6':
                SetCursorCoord_XY(30, 29);
                printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding To Step 2 of Part 3...", MainCourse_FullName[5]);
                //Sleep(1750);
                strcpy(OnProcess_StudentData.MainCourse_CodeName_Passer, MainCourse_CodeName[5]);
                strcpy(OnProcess_StudentData.MainCourse_FullName_Passer, MainCourse_FullName[5]);
                Func_NewStdnt_YearSemSelect();
                break;
            case '7':
                SetCursorCoord_XY(30, 29);
                printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding To Step 2 of Part 3...", MainCourse_FullName[6]);
                //Sleep(1750);
                strcpy(OnProcess_StudentData.MainCourse_CodeName_Passer, MainCourse_CodeName[6]);
                strcpy(OnProcess_StudentData.MainCourse_FullName_Passer, MainCourse_FullName[6]);
                Func_NewStdnt_YearSemSelect();
                break;
            default:
                SetCursorCoord_XY(30, 29);
                printf("\xAF \xDD ERROR \xAF Sorry, I don't understand that...");
                //Sleep(1750);
                continue;
            }
        }
    case '2':
        SetCursorCoord_XY(30, 24);
        printf("\xAF \xDD INFO \xDD Architecture is basically indentified as a main course. Proceeding To Part 3 of Step 2...");
        //Sleep(1750);
        strcpy(OnProcess_StudentData.MainCourse_CodeName_Passer, MainCourse_CodeName[7]);
        strcpy(OnProcess_StudentData.MainCourse_FullName_Passer, MainCourse_FullName[7]);
        Func_NewStdnt_YearSemSelect();
    default:
        SetCursorCoord_XY(30, 24);
        printf("\xAF \xDD ERROR \xAF Sorry, I don't understand that...");
        //Sleep(1750);
        Func_NewStdnt_CourseReg();
    }
}
int Func_NewStdnt_YearSemSelect()
{
    system("CLS");
    SetConsoleTitle(FUNCTION_STEP2_1);
    int YearSelection_Accepter = 0,
        YearSelection_Accepter_Sem = 0,
        OldStudentParameter = 0;
    static long long int Old_StudentID = 0;
    char DataCheck;
    char *ERLM_Selection[5] = {"1st Year College", "2nd Year College", "3rd Year College", "4th Year College", "5th Year College"},
         *ERLM_Selection_Sem[2] = {"First Semester", "Second Semester"};

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
        system("CLS");
        SetCursorCoord_XY(30, 3);
        printf("\xC9\xCD\xCD \xDD CURRENT PROGRESS \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        SetCursorCoord_XY(30, 4);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, 5);
        printf("\xBA [1st \xAF \xDD\xAF [2nd Step of Part 3 \xAF Course Level Selection] \xAF 3rd \xAF 4th \xAF 5th \xAF Confirm \xAF End]\t\t   \xBA");
        SetCursorCoord_XY(30, 6);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, 7);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        SetCursorCoord_XY(30, 9);
        printf("\xFE\xCD\xCD \xDD Current Choices \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
        SetCursorCoord_XY(30, 11);
        printf(" \xDD\xAF Course Name and Course Code \xAF %s \xDD %s", OnProcess_StudentData.MainCourse_CodeName_Passer, OnProcess_StudentData.MainCourse_FullName_Passer);
        SetCursorCoord_XY(30, 12);
        printf(" \xDD\xAF Student Name \xAF %s, %s %s", OnProcess_StudentData.stdnt_LName, OnProcess_StudentData.stdnt_FName, OnProcess_StudentData.stdnt_MName);
        SetCursorCoord_XY(30, 13);
        printf(" \xDD\xAF Student Number \xAF %ld", Old_StudentID);
        SetCursorCoord_XY(30, 15);
        printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
        SetCursorCoord_XY(30, 17);
        printf("\xC9\xCD\xCD \xDD SELECTIONS \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        SetCursorCoord_XY(30, 18);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, 19);
        printf("\xBA \xAF [1] 1st Year College \t\t\t\t\t\t\t\t\t\t\t   \xBA");
        SetCursorCoord_XY(30, 20);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, 21);
        printf("\xBA \xAF [2] 2nd Year College \t\t\t\t\t\t\t\t\t\t\t   \xBA");
        SetCursorCoord_XY(30, 22);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, 23);
        printf("\xBA \xAF [3] 3rd Year College \t\t\t\t\t\t\t\t\t\t\t   \xBA");
        SetCursorCoord_XY(30, 24);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, 25);
        printf("\xBA \xAF [4] 4th Year College \t\t\t\t\t\t\t\t\t\t\t   \xBA");
        SetCursorCoord_XY(30, 26);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, 27);
        printf("\xBA \xAF [5] 5th Year College \t\t\t\t\t\t\t\t\t\t\t   \xBA");
        SetCursorCoord_XY(30, 28);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, 29);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        SetCursorCoord_XY(30, 31);
        printf("\xC8\xAF Press a key that corresponds your Desired College Year Level [1 - 5] \xAF ");
        switch (YearSelection_Accepter = getche())
        {
        case '1':
            YearSelection_Accepter = 0;
            SetCursorCoord_XY(30, 33);
            printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding to Step 2 of Part 4...", ERLM_Selection[YearSelection_Accepter]);
            //Sleep(1750);
            break;
        case '2':
            YearSelection_Accepter = 1;
            SetCursorCoord_XY(30, 33);
            printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding to Step 2 of Part 4...", ERLM_Selection[YearSelection_Accepter]);
            //Sleep(1750);
            break;
        case '3':
            YearSelection_Accepter = 2;
            SetCursorCoord_XY(30, 33);
            printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding to Step 2 of Part 4...", ERLM_Selection[YearSelection_Accepter]);
            //Sleep(1750);
            break;
        case '4':
            YearSelection_Accepter = 3;
            SetCursorCoord_XY(30, 33);
            printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding to Step 2 of Part 4...", ERLM_Selection[YearSelection_Accepter]);
            //Sleep(1750);
            break;
        case '5':
            YearSelection_Accepter = 4;
            SetCursorCoord_XY(30, 33);
            printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding to Step 2 of Part 4...", ERLM_Selection[YearSelection_Accepter]);
            //Sleep(1750);
            break;
        default:
            SetCursorCoord_XY(30, 33);
            printf("\xAF \xDD ERROR \xDD Sorry, I don't understand that...");
            //Sleep(1750);
            break;
        }
        if (YearSelection_Accepter >= 0 && YearSelection_Accepter <= 5)
        {
            break;
        }
        else
        {
            continue;
        }
    }
    system("CLS");
    while (1)
    {
        system("CLS");
        SetCursorCoord_XY(30, 3);
        printf("\xC9\xCD\xCD \xDD CURRENT PROGRESS \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        SetCursorCoord_XY(30, 4);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, 5);
        printf("\xBA [1st \xAF \xDD\xAF [2nd Step of Part 4 \xAF Semester Selection] \xAF 3rd \xAF 4th \xAF 5th \xAF Confirm \xAF End]\t\t           \xBA");
        SetCursorCoord_XY(30, 6);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, 7);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        SetCursorCoord_XY(30, 9);
        printf("\xFE\xCD\xCD \xDD Current Choices \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
        SetCursorCoord_XY(30, 11);
        printf(" \xDD\xAF Course Name and Course Code \xAF %s \xDD %s", OnProcess_StudentData.MainCourse_CodeName_Passer, OnProcess_StudentData.MainCourse_FullName_Passer);
        SetCursorCoord_XY(30, 12);
        printf(" \xDD\xAF Desired Year and Desired Semester \xAF %s \xDD %s", ERLM_Selection[YearSelection_Accepter], "Not Yet Selected");
        SetCursorCoord_XY(30, 13);
        printf(" \xDD\xAF Student Name \xAF %s, %s %s", OnProcess_StudentData.stdnt_LName, OnProcess_StudentData.stdnt_FName, OnProcess_StudentData.stdnt_MName);
        SetCursorCoord_XY(30, 14);
        printf(" \xDD\xAF Student Number \xAF %ld", Old_StudentID);
        SetCursorCoord_XY(30, 16);
        printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
        SetCursorCoord_XY(30, 18);
        printf("\xC9\xCD\xCD \xDD SELECTIONS \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        SetCursorCoord_XY(30, 19);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, 20);
        printf("\xBA \xAF [1] \xAF First Semester \t\t\t\t\t\t\t\t\t\t\t   \xBA");
        SetCursorCoord_XY(30, 21);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, 22);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, 23);
        printf("\xBA \xAF [2] \xAF Second Semester \t\t\t\t\t\t\t\t\t\t   \xBA");
        SetCursorCoord_XY(30, 24);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, 25);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        SetCursorCoord_XY(30, 27);
        printf(" \xAF Please choose your Desired Semester [1 - 2] \xAF ");
        switch (YearSelection_Accepter_Sem = getche())
        {
        case '1':
            YearSelection_Accepter_Sem = 0;
            SetCursorCoord_XY(30, 29);
            printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding to Step 2 of Part 5...", ERLM_Selection_Sem[YearSelection_Accepter_Sem]);
            //Sleep(1750);
            break;
        case '2':
            SetCursorCoord_XY(30, 30);
            YearSelection_Accepter_Sem = 1;
            printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding to Step 2 of Part 5...", ERLM_Selection_Sem[YearSelection_Accepter_Sem]);
            //Sleep(1750);
            break;
        default:
            SetCursorCoord_XY(30, 30);
            printf("\xAF \xDD ERROR \xDD Sorry, I don't understand that...");
            //Sleep(1750);
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

    system("CLS");

    while (1)
    {
        system("CLS");
        SetCursorCoord_XY(30, 3);
        printf("\xC9\xCD\xCD \xDD CURRENT PROGRESS \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        SetCursorCoord_XY(30, 4);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, 5);
        printf("\xBA [1st \xAF \xDD\xAF [2nd Step of Part 5 \xAF Data Finalization Checkpoint] \xAF 3rd \xAF 4th \xAF 5th \xAF Confirm \xAF End]\t   \xBA");
        SetCursorCoord_XY(30, 6);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, 7);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        SetCursorCoord_XY(30, 9);
        printf("\xFE\xCD\xCD \xDD Current Choices \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
        SetCursorCoord_XY(30, 11);
        printf(" \xDD\xAF Course Name and Course Code \xAF %s \xDD %s", OnProcess_StudentData.MainCourse_CodeName_Passer, OnProcess_StudentData.MainCourse_FullName_Passer);
        SetCursorCoord_XY(30, 12);
        printf(" \xDD\xAF Desired Year and Desired Semester \xAF %s \xDD %s", ERLM_Selection[YearSelection_Accepter], ERLM_Selection_Sem[YearSelection_Accepter_Sem]);
        SetCursorCoord_XY(30, 13);
        printf(" \xDD\xAF Student Name \xAF %s, %s %s", OnProcess_StudentData.stdnt_LName, OnProcess_StudentData.stdnt_FName, OnProcess_StudentData.stdnt_MName);
        SetCursorCoord_XY(30, 14);
        printf(" \xDD\xAF Student Number \xAF %ld", Old_StudentID);
        SetCursorCoord_XY(30, 16);
        printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
        SetCursorCoord_XY(30, 18);
        printf("\xC9\xCD\xCD \xDD CONFIRMATION AND FEW NOTES TO KNOW \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        SetCursorCoord_XY(30, 19);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, 20);
        printf("\xBA \xDD QUESTION \xDD Are you sure you have picked the right options?\t\t\t\t\t\t   \xBA");
        SetCursorCoord_XY(30, 21);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, 22);
        printf("\xBA \xDD NOTE #1  \xDD If you are a newcoming student, default value of new students is 2018000.\t\t\t   \xBA");
        SetCursorCoord_XY(30, 23);
        printf("\xBA \xDD NOTE #2  \xDD If you have mistakes, then you will have to reselect courses, year, semester again.\t   \xBA");
        SetCursorCoord_XY(30, 24);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, 25);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        SetCursorCoord_XY(30, 27);
        printf("\xC8\xAF Press a key that corresponds your decision [|Y|es or |N|o] \xDD\xAF ");
        switch (DataCheck = getche())
        {
        case 'Y':
        case 'y':
            SetCursorCoord_XY(30, 29);
            printf("\xDD INFO \xDD Data Temporarily Recorded \xAF Processing Data..."); // Pass This Already in Struct to lessen the difficutly to check what to pass when User Press 3 on Subject Unit Selection Function
            SetCursorCoord_XY(30, 30);
            printf("\xDD SUCCESS \xDD Data Processed. Proceeding to Step 3 \xAF Subject Enrollment Selection");
            strcpy(OnProcess_StudentData.Course_YearChoice, ERLM_Selection[YearSelection_Accepter]);
            strcpy(OnProcess_StudentData.Course_SemSelection, ERLM_Selection_Sem[YearSelection_Accepter_Sem]);
            //Sleep(1800);
            if (strcmp(OnProcess_StudentData.MainCourse_CodeName_Passer, "BSCE") == 0)
            {
                if (strcmp(OnProcess_StudentData.Course_YearChoice, "1st Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"ENGL 001", "FIL 001", "MATH 001", "MATH 002", "COE 001", "CHEM 001", "AR 001", "PE 001", "NSTP 001"};
                        char *Subject_FullName[12] = {"COMMUNICATION ARTS 1", "KOMUNIKASYON SA AKADEMIKONG FILIPINO", "COLLEGE ALGEBRA", "PLANE AND SPHERICAL TRIGONOMETRY", "ENGINEERING ORIENTATION", "GENERAL CHEMISTRY", "ENGINEERING DRAWING 1", "PHYSICAL FITNESS", "NATIONAL SERVICE TRAINING PROGRAM 1"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 1:30PM", "1:30PM - 2:30PM", "2:30PM - 3:30PM", "1:30PM - 4:30PM", "7:30AM - 9:30AM", "9:30AM - 12:00PM"};
                        int Subject_Units[12] = {3, 3, 3, 3, 1, 3, 0, 2, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"ENGL 001", "FIL 001", "MATH 001", "MATH 002", "COE 001", "CHEM 001", "AR 001", "PE 001", "NSTP 001"};
                        char *Subject_FullName[12] = {"COMMUNICATION ARTS 2", "PAGBASA AT PAGSULAT TUNGO SA PANANALIKSIK", "COMPUTER FUNDAMENTALS", "ADVANCED ALGEBRA", "ANALYTIC GEOMETRY", "SOLID MENSURATION", "INTRODUCTION TO PHILOSOPHY", "RHYTHMIC ACTIVITIES", "NATIONAL SERVICE TRAINING PROGRAM 2"};
                        char *Subject_LinearTime[12] = {"7:30AM - 8:30AM", "8:30AM - 9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 12:30PM", "12:30PM - 1:30PM", "1:30PM - 2:30PM", "2:30PM - 3:30PM", "3:30PM - 4:30PM"};
                        int Subject_Units[12] = {3, 3, 3, 3, 1, 3, 0, 2, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
                else if (strcmp(OnProcess_StudentData.Course_YearChoice, "2nd Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"ENGL 003", "HUM 002", "SOCSC 001", "MATH 007", "CHEM 002", "SOCSC 002", "SOCSC 003", "PE 003"};
                        char *Subject_FullName[12] = {"TECHNICAL COMMUNICATION", "LOGIC", "ECONOMICS", "AGRARIAN REFORM AND TAXATION", "DIFFERENTIAL CALCULUS", "ENVIRONMENTAL ENGINEERING", "SOCIETY AND CULTURE W/ FAMILY PLANNING", "PHILIPPINES HISTORY W/ POLITICS & GOVERNANCE", "INDIVIDUAL / DUAL SPORTS"};
                        char *Subject_LinearTime[12] = {"7:30AM - 8:30AM", "8:30AM - 9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 12:30PM", "12:30PM - 1:30PM", "1:30PM - 2:30PM", "2:30PM - 3:30PM", "3:30PM - 4:30PM"};
                        int Subject_Units[12] = {3, 3, 3, 4, 3, 3, 3, 2};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"SOCSC 005", "HUM 003", "SOCSC 004", "MATH 008", "PHYS 001", "CS 100 A", "MATH 009", "PE 004"};
                        char *Subject_FullName[12] = {"LIFE AND WORKS OF RIZAL", "ETHICS", "GENERAL PSYCHOLOGY", "INTEGRAL CALCULUS", "CALCULUS-BASED PHYSICS 1", "FUNDAMENTALS OF PROGRAMMING AND ALGORITHM", "PROBABILITY AND STATISTICS", "SPORTS AND GAMES"};
                        char *Subject_LinearTime[12] = {"7:30AM - 8:30AM", "8:30AM - 9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 12:30PM", "12:30PM - 1:30PM", "1:30PM - 2:30PM", "2:30PM - 3:30PM", "3:30PM - 4:30PM"};
                        int Subject_Units[12] = {3, 3, 3, 4, 3, 1, 3, 2};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
                else if (strcmp(OnProcess_StudentData.Course_YearChoice, "3rd Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"PHYS 002", "CPE 003", "MATH 010", "CE 301", "IE 002", "CE 001", "ME 005", "MATH 013", "CE 300"};
                        char *Subject_FullName[12] = {"CALCULUS-BASED PHYSICS 2", "COMPUTER-AIDED DRAFTING", "DIFFERENTIAL EQUATIONS", "ENGINEERING GEOLOGY", "SAFETY MANAGEMENT", "STATICS OF RIGID BODIES", "ENGINEERING ECONOMY", "LINEAR ALGEBRA W/ MATLAB", "ELEMENTARY SURVEYING"};
                        char *Subject_LinearTime[12] = {"7:30AM - 8:30AM", "8:30AM - 9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 12:30PM", "12:30PM - 1:30PM", "1:30PM - 2:30PM", "2:30PM - 3:30PM", "3:30PM - 4:30PM"};
                        int Subject_Units[12] = {3, 0, 3, 3, 2, 3, 3, 2, 2};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"MATH 011 A", "CE 002", "CE 003", "ME 004", "EE 006", "IE 001", "CE 303", "CE 304"};
                        char *Subject_FullName[12] = {"ADV. ENGRG. MATH W/ NUM METHODS", "DYNAMICS OF RIGID BODIES", "MECHANICS OF DEFORMABLE BODIES", "THERMODYNAMICS", "BASIC ELECTRICAL ENGINEERING", "ENGINEERING MANAGEMENT", "HIGHER SURVEYING", "INTEGRATION COURSE FOR CE 1"};
                        char *Subject_LinearTime[12] = {"7:30AM - 8:30AM", "8:30AM - 9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 12:30PM", "12:30AM - 1:30PM", "1:30PM - 2:30PM", "2:30PM - 3:30PM", "3:30PM - 4:30PM"};
                        int Subject_Units[12] = {3, 3, 5, 3, 3, 3, 2, 2};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
                else if (strcmp(OnProcess_StudentData.Course_YearChoice, "4th Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"CE 400", "CE 401", "CE 402", "CE 403", "CE 404", "CE 405", "CE 406"};
                        char *Subject_FullName[12] = {"HIGHWAY ENGINEERING", "SOIL MECHANICS", "FLUID MECHANICS", "ENGINEERING SURVEYS", "STRUCTURAL THEORY 1", "CONSTRUCTION MATERIALS AND TESTING", "BUILDING DESIGN 1"};
                        char *Subject_LinearTime[12] = {"7:30AM - 8:30AM", "8:30AM - 9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 12:30PM", "12:30AM - 1:30PM", "1:30PM - 2:30PM", "2:30PM - 3:30PM", "3:30PM - 4:30PM"};
                        int Subject_Units[12] = {3, 3, 3, 3, 3, 2, 1};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"CE 407", "CE 408", "CE 409", "CE 410", "CE 411", "CE 412", "CE 413", "CE 414"};
                        char *Subject_FullName[12] = {"EARTHQUAKE ENGINEERING", "TRANSPORTATION ENGINEERING", "STRUCTURAL THEORY 2", "HYDROLOGY", "HYDRAULICS ENGINEERING", "TIMBER DESIGN", "BUILDING DESIGN 2", "INTEGRATION COURSE FOR CE 2"};
                        char *Subject_LinearTime[12] = {"7:30AM - 8:30AM", "8:30AM - 9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 12:30PM", "12:30AM - 1:30PM", "1:30PM - 2:30PM", "2:30PM - 3:30PM", "3:30PM - 4:30PM"};
                        int Subject_Units[12] = {3, 3, 3, 3, 3, 3, 1, 2};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
                else if (strcmp(OnProcess_StudentData.Course_YearChoice, "5th Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"CE 407", "CE 408", "CE 409", "CE 410", "CE 411", "CE 412", "CE 413", "CE 414"};
                        char *Subject_FullName[12] = {"EARTHQUAKE ENGINEERING", "TRANSPORTATION ENGINEERING", "STRUCTURAL THEORY 2", "HYDROLOGY", "HYDRAULICS ENGINEERING", "TIMBER DESIGN", "BUILDING DESIGN 2", "INTEGRATION COURSE FOR CE 2"};
                        char *Subject_LinearTime[12] = {"7:30 - 8:30AM", "8:30AM - 9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 12:30PM", "12:30PM - 1:30PM", "1:30PM-  2:30PM", "2:30PM - 3:30PM", "3:30PM - 4:30PM"};
                        int Subject_Units[12] = {3, 3, 3, 3, 3, 3, 1, 2};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"CE 501", "CE 502", "CE 503", "CE 504", "CE 505", "CE 506", "CE 507"};
                        char *Subject_FullName[12] = {"PLANT VISITS & SEMINARS FOR CE", "REINFORCED CONCRETE DESIGN", "WATER & WASTE WATER ENGINEERING", "STRUCTURAL MATRIX ANALYSIS", "CONSTRUCTION METHODS & PROJECT MANAGEMENT", "CE DESIGN PROJECTS 1", "WATER RESOURCES ENGINEERING"};
                        char *Subject_LinearTime[12] = {"7:30 - 8:30AM", "8:30AM - 9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 12:30 PM", "12:30PM - 1:30PM", "1:30PM-2:30PM", "2:30PM - 3:30PM", "3:30PM - 4:30PM"};
                        int Subject_Units[12] = {1, 6, 3, 3, 4, 3, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
            }
            else if (strcmp(OnProcess_StudentData.MainCourse_CodeName_Passer, "BSCpE") == 0)
            {
                if (strcmp(OnProcess_StudentData.Course_YearChoice, "1st Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"MATH 001", "MATH 002", "CHEM 001", "CPE 001", "COE 001", "ENGL 001", "FIL 001", "PE 001", "NSTP 001"};
                        char *Subject_FullName[12] = {"COLLEGE ALGEBRA", "PLANE AND SPHERICAL TRIGONOMETRY", "GENERAL CHEMISTRY", "COMPUTER FUNDAMENTALS", "ENGINEERING ORIENTATION", "COMMUNICATION ARTS 1", "KOMUNIKASYON SA AKADEMIKONG FILIPINO", "PHYSICAL FITNESS", "NATIONAL SERVICE TRAINING PROGRAM 1"};
                        char *Subject_LinearTime[12] = {"7:30AM - 8:30AM", "8:30 - 9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 12:30PM", "12:30AM - 1:30PM", "1:30PM - 2:30PM", "2:30PM - 3:30PM", "3:30PM - 4:30PM"};
                        int Subject_Units[12] = {3, 3, 4, 1, 1, 3, 3, 2, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"MATH 003", "MATH 004", "MATH 005", "AR 001", "CS 100A", "HUM 001", "ENGL 002", "FIL 002", "PE 002", "NSTP 002"};
                        char *Subject_FullName[12] = {"ADVANCED ALGEBRA", "ANALYTIC GEOMETRY", "SOLID MENSURATION", "ENGINEERING DRAWING", "FUNDAMENTALS OF PROGRAMMING AND ALGORITHM", "INTRODUCTION TO PHILOSOPHY", "COMMUNICATION ARTS 2", "PAGBASA AT PAGSULAT TUNGO SA PANANALIKSIK", "RHYTHMIC ACTIVITIES", "NATIONAL SERVICE TRAINING PROGRAM 2"};
                        char *Subject_LinearTime[12] = {"7:30AM - 8:30AM", "8:30 - 9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 12:30PM", "12:30AM - 1:30PM", "1:30PM - 2:30PM", "2:30PM - 3:30PM", "3:30PM - 4:30PM"};
                        int Subject_Units[12] = {2, 3, 2, 1, 2, 3, 3, 3, 2, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
                else if (strcmp(OnProcess_StudentData.Course_YearChoice, "2nd Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"MATH 001", "MATH 002", "CHEM 001", "CPE 001", "COE 001", "ENGL 001", "FIL 001", "PE 001", "NSTP 001"};
                        char *Subject_FullName[12] = {"COLLEGE ALGEBRA", "PLANE AND SPHERICAL TRIGO..", "GENERAL CHEMISTRY", "COMPUTER FUNDAMENTALS", "ENGINEERING ORIENTATION", "COMMUNICATION ARTS 1", "KOMUNIKASYON SA AKADEMIKONG FILIPINO", "PHYSICAL FITNESS", "NATIONAL SERVICE TRAINING PROGRAM 1"};
                        char *Subject_LinearTime[12] = {"7:30AM - 8:30AM", "8:30 - 9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 12:30PM", "12:30AM - 1:30PM", "1:30PM - 2:30PM", "2:30PM - 3:30PM", "3:30PM - 4:30PM"};
                        int Subject_Units[12] = {3, 3, 4, 1, 1, 3, 3, 2, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"MATH 008", "MATH 009", "PHYS 001", "CS 201A", "CPE 201", "SOCSC 003", "HUM 002", "PE 004"};
                        char *Subject_FullName[12] = {"INTEGRAL CALCULUS", "PROBABILITY AND STATISTICS", "CALCULUS-BASED PHYSICS 1", "DATA STRUCTURES AND ALGORITHM ANALYSIS", "COMPUTER SYSTEMS ADMIN. AND TROUBLESHOOTING", "PHILIPPINES HISTORY W/ POLITICS & GOVERNANCE", "LOGIC", "SPORTS AND GAMES"};
                        char *Subject_LinearTime[12] = {"7:30AM - 8:30AM", "8:30 - 9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 12:30PM", "12:30AM - 1:30PM", "1:30PM - 2:30PM", "2:30PM - 3:30PM", "3:30PM - 4:30PM"};
                        int Subject_Units[12] = {4, 3, 4, 4, 2, 3, 3, 2};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
                else if (strcmp(OnProcess_StudentData.Course_YearChoice, "3rd Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"MATH 010", "PHYS 002", "CE 001", "CHEM 002", "IE 002", "ME 005", "HUM 003", "SOCSC 004", "CPE 301", "CPE 304"};
                        char *Subject_FullName[12] = {"DIFFERENTIAL EQUATIONS", "CALCULUS-BASED PHYSICS 2", "STATICS OF RIGID BODIES", "ENVIRONMENTAL ENGINEERING", "SAFETY MANAGEMENT", "ENGINEERING ECONOMY", "ETHICS", "GENERAL PSYCHOLOGY", "DATABASE MANAGEMENT SYSTEMS 1", "COMPUTER ENGINEERING DRAFTING & DESIGN"};
                        char *Subject_LinearTime[12] = {"7:30AM - 8:30AM", "8:30 - 9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 12:30PM", "12:30AM - 1:30PM", "1:30PM - 2:30PM", "2:30PM - 3:30PM", "3:30PM - 4:30PM"};
                        int Subject_Units[12] = {3, 4, 3, 3, 2, 3, 3, 3, 1, 1};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"MATH 011", "SOCSC 005", "CE 002", "CE 003A", "IE 001", "ECE 001", "EE 002", "CPE 302", "CPE 303"};
                        char *Subject_FullName[12] = {"ADVANCED ENGINEERING MATHEMATICS", "LIFE AND WORKS OF RIZAL", "DYNAMICS OF RIGID BODIES", "MECHANICS OF DEFORMABLE BODIES", "ENGINEERING MANAGEMENT", "ELECTRONIC DEVICES AND CIRCUITS", "ELECTRICAL CIRCUITS 1", "COMPUTER NETWORKS 1", "DATABASE MANAGEMENT SYSTEMS 2"};
                        char *Subject_LinearTime[12] = {"7:30AM - 8:30AM", "8:30AM - 9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 12:30PM", "12:30AM - 1:30PM", "1:30PM - 2:30PM", "2:30PM - 3:30PM", "3:30PM - 4:30PM"};
                        int Subject_Units[12] = {3, 3, 3, 3, 3, 4, 4, 3, 1};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
                else if (strcmp(OnProcess_StudentData.Course_YearChoice, "4th Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"CPE 411", "EE 003", "ECE 401", "ECE 402", "CPE 004", "CPE 401", "CPE ELEC 1"};
                        char *Subject_FullName[12] = {"SYSTEMS ANALYSIS AND DESIGN", "ELECTRICAL CIRCUITS 2", "SIGNALS, SPECTRA, SIGNAL PROCESSING", "ELECTRONIC CIRCUIT ANALYSIS AND DESIGN", "LOGIC CIRCUITS AND SWITCHING THEORY", "COMPUTER NETWORKS 2", "CPE ELECTIVE 1"};
                        char *Subject_LinearTime[12] = {"7:30AM - 8:30AM", "8:30AM - 9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 12:30PM", "12:30AM - 1:30PM", "1:30PM - 2:30PM", "2:30PM - 3:30PM", "3:30PM - 4:30PM"};
                        int Subject_Units[12] = {3, 4, 4, 4, 4, 3, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"COE 002A", "ECE 004A", "ECE 006", "CPE 005", "CPE 402", "CPE 404", "CPE ELEC 2"};
                        char *Subject_FullName[12] = {"INTRODUCTION TO INTELLECTUAL PROPERTY", "PRINCIPLES OF COMMUNICATIONS", "FEEDBACK AND CONTROL SYSTEMS", "COMP. SYSTEM ORG W/ ASSEMBLY LANGUAGE", "ADVANCED LOGIC CIRCUITS", "COMPUTER NETWORKS 3", "CPE ELECTIVE 2"};
                        char *Subject_LinearTime[12] = {"7:30AM - 8:30AM", "8:30AM - 9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 12:30PM", "12:30AM - 1:30PM", "1:30PM - 2:30PM", "2:30PM - 3:30PM", "3:30PM - 4:30PM"};
                        int Subject_Units[12] = {1, 3, 4, 4, 4, 3, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
                else if (strcmp(OnProcess_StudentData.Course_YearChoice, "5th Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"CPE 506", "IE 004", "ECE 504A", "CPE 006", "CPE 501", "CPE 502", "CPE 503", "CPE ELEC 3"};
                        char *Subject_FullName[12] = {"SOFTWARE ENGINEERING", "ENGINEERING ENTREPRENEURSHIP", "DATA COMMUNICATIONS", "MICROPROCESSOR SYSTEMS", "COMPUTER NETWORKS DESIGN", "PLANT VISITS AND SEMINARS FOR CPE", "DESIGN PROJECT 1", "CPE ELECTIVE 3"};
                        char *Subject_LinearTime[12] = {"7:30AM -8:30AM", "8:30-9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 12:30PM", "12:30PM- 1:30PM", "1:30-2:30 PM", "2:30PM-3:30 PM", "3:30PM-4:30 PM"};
                        int Subject_Units[12] = {3, 3, 3, 4, 3, 1, 2, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"CPE 507", "CPE 504", "CPE 505", "CPE 508", "CPE 500"};
                        char *Subject_FullName[12] = {"OPERATING SYSTEMS", "COMPUTER SYSTEMS ARCHITECTURE", "ENGINEERING ETHICS AND COMPUTER LAWS", "DESIGN PROJECT 2", "ON-THE-JOB TRAINING"};
                        char *Subject_LinearTime[12] = {"7:30-8:30AM", "8:30-9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 12:30PM", "12:30PM- 1:30PM"};
                        int Subject_Units[12] = {4, 4, 2, 2, 5};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
            }
            else if (strcmp(OnProcess_StudentData.MainCourse_CodeName_Passer, "BSEE") == 0)
            {
                if (strcmp(OnProcess_StudentData.Course_YearChoice, "1st Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"CHEM 001", "COE 001", "CPE 001", "ENGL 001", "FIL 001", "MATH 001", "MATH 002", "PE 001", "NSTP 001"};
                        char *Subject_FullName[12] = {"GENERAL CHEMISTRY", "ENGINEERING ORIENTATION", "COMPUTER FUNDAMENTALS", "COMMUNICATION ARTS 1", "KOMUNIKASYON SA AKADEMIKONG FILIPINO", "COLLEGE ALGEBRA", "PLANE AND SPHERICAL TRIGO", "PHYSICAL FITNESS", "NATIONAL SERVICE TRAINING PROGRAM 1"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM"};
                        int Subject_Units[12] = {4, 1, 1, 3, 3, 3, 3, 2, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"AR 001", "ENGL 002", "FIL 002", "HUM 001", "HUM 002", "MATH 003", "MATH 004", "MATH 005", "PE 002", "NSTP 002"};
                        char *Subject_FullName[12] = {"ENGINEERING DRAWING", "COMMUNICATION ARTS 2", "PAGBASA AT PAGSULAT TUNGO SA PANANALIKSIK", "INTRODUCTION TO PHILOSOPHY", "LOGIC", "ADVANCED ALGEBRA", "ANALYTIC GEOMETRY", "SOLID MENSURATION", "RHYTHMIC ACTIVITIES", "NATIONAL SERVICE TRAINING PROGRAM 2"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM", "6:00PM - 7:00PM"};
                        int Subject_Units[12] = {1, 3, 3, 3, 3, 2, 3, 2, 2, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
                else if (strcmp(OnProcess_StudentData.Course_YearChoice, "2nd Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"CHEM 002", "CS 100A", "ENGL 003", "MATH 006", "MATH 007", " SOCSC 001", "SOCSC 002", "PE 003"};
                        char *Subject_FullName[12] = {"ENVIRONMENTAL ENGINEERING", "FUNDAMENTALS OF PROGRAMMING AND ALGORITHM", "TECHNICAL COMMUNICATIONS", "DISCRETE MATHEMATICS", "DIFFERENTIAL CALCULUS", "ECONOMICS, AGRARIAN REFORM AND TAXATIONS", "SOCIETY AND CULTURE W/ FAMILY PLANNING", "INDIVIDUAL / DUAL SPORTS"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        int Subject_Units[12] = {3, 2, 3, 3, 4, 3, 3, 2};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"HUM 003", "MATH 008", "MATH 009", "PHYS 001", "SOCSC 003", "SOCSC 004", "PE 004"};
                        char *Subject_FullName[12] = {"ETHICS", "INTEGRAL CALCULUS", "PROBABILITY AND STATISTICS", "CALCULUS-BASED PHYSICS 1", "PHILIPPINES HISTORY W/ POLITICS & GOVERNANCE", "GENERAL PSYCHOLOGY", "SPORTS AND GAMES"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        int Subject_Units[12] = {3, 4, 3, 4, 3, 3, 2};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
                else if (strcmp(OnProcess_StudentData.Course_YearChoice, "3rd Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"CE 001", "CPE 003", "1E 001", "1E 002", "MATH 010", "ME 005", "PHYS 002", "SOCSC 005", "EE 300"};
                        char *Subject_FullName[12] = {"STATICS OF RIGID BODIES", "COMPUTER-AIDED DRAFTING", "SAFETY MANAGEMENT", "DIFFERENTIAL EQUATIONS", "ENGINEERING ECONOMY", "CALCULUS-BASED PHYSICS 2", "LIFE AND WORKS OF RIZAL", "RESEARCH METHODS"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM"};
                        int Subject_Units[12] = {3, 1, 3, 2, 3, 3, 4, 3, 1};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"EE 002", "EE 301", "EE 302", "ECE 001", "ECE 302", "CE 002", "CE 003A", "MATH 011", "ME 004"};
                        char *Subject_FullName[12] = {"ELECTRICAL CIRCUITS 1", "INTEGRATION COURSE FOR MATHEMATICS", "ELECTRICAL ENGINEERING SAFETY", "ELECTRONIC DEVICES AND CIRCUITS", "ELECTROMAGNETICS", "DYNAMICS OF RIGID BODIES", "MECHANICS OF DEFORMABLE BODIES", "ADVANCED ENGINEERING MATHEMATICS", "THERMODYNAMICS 1"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM"};
                        int Subject_Units[12] = {4, 2, 1, 4, 3, 3, 3, 3, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
                else if (strcmp(OnProcess_StudentData.Course_YearChoice, "4th Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"EE 003", "EE 401", "ECE 402", "CE 402A", "CHEM 004", " CPE 004", "MATH 012", "1E 301A"};
                        char *Subject_FullName[12] = {"ELECTRICAL CIRCUITS 2", "DC MACHINERY", "ELECTRONIC CIRCUIT ANALYSIS AND DESIGN", "FLUID MECHANICS", "MATERIALS SCIENCE AND ENGINEERING", "LOGIC CIRCUITS AND SWITCHING THEORY", "NUMERICAL METHODS", "APPLIED STATISTICS"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        int Subject_Units[12] = {4, 4, 4, 3, 3, 4, 4, 1};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"EE 402", "EE 403", "EE 404", "EE 405", "EE 406", "ECE 004", "ECE 006", "CPE 006", "EE 407"};
                        char *Subject_FullName[12] = {"EE LAWS, ETHICS, CODES AND STANDARDS", "AC MACHINERY", "INTEGRATION COURSE FOR ENGINNERING SCIENCES", "TRANSFORMER AND AC APPARATUSES", "ELECTRICAL CIRCUITS 3", "PRINCIPLES OF COMMUNICATION", "FEEDBACK AND CONTROL SYSTEMS", "MICROPROCESSOR SYSTEMS", "EE RESEARCH 2 (RESEARCH PROJECT)"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM"};
                        int Subject_Units[12] = {2, 4, 2, 3, 3, 4, 4, 4, 1};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
                else if (strcmp(OnProcess_StudentData.Course_YearChoice, "5th Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"EE 501", "EE 502", "EE 503", "EE 504", "???", "???", "ECE 003", "EE 505"};
                        char *Subject_FullName[12] = {"POWER SYSTEM ANALYSIS AND DESIGN", "ILLUMINATION ENGINEERING DESIGN", "ELECTRICAL SYSTEM DESIGN", "ELECTRICAL EQUIPMENT OPERATION MAINTENANCE", "EE ELECTIVE 1", "EE ELECTIVE 2", "INDUSTRIAL ELECTRONICS", "DESIGN PROJECT 1"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        int Subject_Units[12] = {4, 3, 4, 3, 3, 3, 4, 1};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"EE 506", "EE 507", "EE 508", "EE 509", "EE 510", "???", "???", "ITE 002A", "EE 511"};
                        char *Subject_FullName[12] = {"ELECTRICAL TRANSPORTATION AND DISTRIBUTION SYSTEM AND DESIGN", "PLANT VISITS AND SEMINARS FOR EE", "POWER PLANT ENGINEERING AND SUBSTATION DESIGN", "INTEGRATION COURSE FOR EE 3", "INSTRUMENTATION AND CONTROL", "EE ELECTIVE 3", "EE ELECTIVE 4", "INFORMATION TECHNOLOGY", "DESIGN PROJECT 2"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM"};
                        int Subject_Units[12] = {4, 1, 3, 2, 3, 3, 3, 3, 2};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
            }
            else if (strcmp(OnProcess_StudentData.MainCourse_CodeName_Passer, "BSECE") == 0)
            {
                if (strcmp(OnProcess_StudentData.Course_YearChoice, "1st Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"MATH 001", "MATH 002", "CHEM 001", "CPE 001", "ENGL 001", "FIL 001", "COE 001", "PE 001", "NSTP 001"};
                        char *Subject_FullName[12] = {"PLANE AND SPHERICAL TRIGONOMETRY", "GENERAL CHEMISTRY", "COMPUTER FUNDAMENTALS", "COMMUNICATION ARTS 001", "KOMUNIKASYON SA AKADEMIKONG FILIPINO", "ENGINEERING ORIENTATION", "PHYSICAL FITNESS", "NATIONAL SERVICE TRAINING PROGRAM 1"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM"};
                        int Subject_Units[12] = {3, 3, 4, 1, 3, 3, 1, 2, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"MATH 003", "MATH 004", "MATH 005", "AR 001", "CS 100A", "HUM 001", "HUM 002", "ENGL 002", "FIL 002", "PE 002", "NSTP 001"};
                        char *Subject_FullName[12] = {"ADVANCED ALGEBRA", "ANALYTICAL GEOMETRY", "SOLID MEASURATION", "ENGINEERING DRAWING", "FUNDAMENTALS OF PROGRAMMING AND ALGORITHM", "INTRODUCTION TO PHILOSOPHY", "LOGIC", "COMMUNICATION ARTS 2", "PAGBASA AT PAGSULAT TINGO SA PANANALIKSIK", "RHYTHMIC ACTIVITIES", "NATIONAL SERVICE TRAINING PROGRAM 2"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM", "6:00PM - 7:00PM", "7:00PM - 8:00PM"};
                        int Subject_Units[12] = {2, 3, 2, 1, 2, 3, 3, 3, 3, 2, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
                else if (strcmp(OnProcess_StudentData.Course_YearChoice, "2nd Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"MATH 006", "MATH 007", "MATH 014", "CHEM 002", "CPE 003", "SOCSC 001", "SOCSC 002", "SOCSC 003", "PE 003"};
                        char *Subject_FullName[12] = {"DISCRETE MATHEMATICS", "DIFFERENTIAL CALCULUS", "FUNDAMENTALS OF MATLAB PROGRAMMING", "ENVIRONMENTAL ENGINEERING", "COMPUTER-AIDED DRAFTING", "ECONOMICS, AGRARIAN REFORM AND TAXATION", "SOCIETY AND CULTURE W/ FAMILY PLANNING", "PHILIPPINES HISTORY W/ POLITICS & GOVERNANCE", "INDIVIDUAL / DUAL SPORTS"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM"};
                        int Subject_Units[12] = {3, 4, 1, 3, 1, 3, 3, 3, 2};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"ECE 100", "MATH 008", "MATH 009", "PHYS 001", "HUM 003", "SOCSC 004", "SOCSC 005", "ENGL 003", "PE 004"};
                        char *Subject_FullName[12] = {"FUNDAMENTALS OF LABVIEW PROGRAMMING", "INTEGRAL CALCULUS", "PROBABILITY AND STATISTICS", "CALCULUS-BASED PHYSICS 1", "ETHICS", "GENERAL PSYCHOLOGY", "LIFE AND WORKS OF RIZAL", "TECHNICAL COMMUNICATION", "SPORTS AND GAMES"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM"};
                        int Subject_Units[12] = {1, 4, 3, 4, 3, 3, 3, 3, 2};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
                else if (strcmp(OnProcess_StudentData.Course_YearChoice, "3rd Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"ECE 301", "CPE 005B", "CE 001", "IE 001", "IE 002", "ME 005", "MATH 010", "PHYS 002"};
                        char *Subject_FullName[12] = {"VECTOR ANALYSIS", "COMPUTER ORGANIZATION AND ARCHITECTURE", "STATICS OF RIGID BODIES", "ENGINEERING MANAGEMENT", "SAFETY MANAGEMENT", "ENGINEERING ECONOMY", "DIFFERENTIAL EQUATIONS", "CALCULUS-BASED PHYSICS 2"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        int Subject_Units[12] = {3, 4, 3, 3, 2, 3, 3, 4};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"ECE 001", "ECE 302", "ECE 303", "EE 002", "CE 002", "CE 003A", "CHEM 004", "MATH 011"};
                        char *Subject_FullName[12] = {"ELECTRONIC DEVICES AND CIRCUITS", "ELECTROMAGNETICS", "INTEGRATION COURSE 1 FOR ECE", "ELECTRICAL CIRCUITS 1", "DYANMICS OF RIGID BODIES", "MECHANICS OF DEFORMABLE BODIES", "MATERIALS SCIENCE AND ENGINEERING", "ADVANCE ENGINEERING MATHEMATICS"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        int Subject_Units[12] = {4, 3, 2, 4, 3, 3, 3, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
                else if (strcmp(OnProcess_StudentData.Course_YearChoice, "4th Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"???", "ECE 402", "ECE 401", "EE 003", "CPE 004", "MATH 012", "ME 004"};
                        char *Subject_FullName[12] = {"ECE ELECTIVE 1", "ELECTRONIC CIRCUIT ANALYSIS AND DESIGN", "SIGNALS, SPECTRA, SIGNAL PROCESSING", "ELECTRICAL CIRCUITS 2", "LOGIC CIRCUITS AND SWITCHING THEORY", "NUMERICAL METHODS", "THERMODYNAMICS 1"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        int Subject_Units[12] = {3, 4, 4, 4, 4, 4, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"???", "ECE 003", "ECE 004", "ECE 006", "ECE 403", "EE 408", "CPE 006"};
                        char *Subject_FullName[12] = {"ECE ELECTIVE 2", "INDUSTRIAL ELECTRONICS", "PRINCIPLES OF COMMUNICATIONS", "FEEDBACK AND CONTROL SYSTEMS", "INTEGRATION COURSE 2 FOR ECE", "ENERGY CONVERSION", "MICROPROCESSOR SYSTEMS"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        int Subject_Units[12] = {3, 4, 4, 4, 2, 4, 4};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
                else if (strcmp(OnProcess_StudentData.Course_YearChoice, "5th Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"???", "ECE 501", "ECE 502", "ECE 503", "ECE 504", "ECE 505", "COE 002"};
                        char *Subject_FullName[12] = {"ECE ELECTIVE 3", "DESIGN PROJECT 1", "DIGITAL COMMUNICATIONS", "TRANSMISSION MIDIA AND ANTENNA SYSTEMS", "DATA COMMUNICATIONS", "ECE LAWS,  ETHICS, CODES AND STANDARDS", "FUNDAMENTALS OF INTELLECTUAL PROPERTY"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        int Subject_Units[12] = {3, 1, 4, 4, 4, 3, 2};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"???", "ECE 506", "ECE 507", "ECE 508", "ECE 509"};
                        char *Subject_FullName[12] = {"ECE ELECTIVE 4", "DESIGN PROJECT 2", "INTEGRATION COURSE 3 FOR ECE", "PLANT VISITS AND SEMINARS FOR ECE", "WIRELESS COMMUNICATIONS"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM"};
                        int Subject_Units[12] = {3, 4, 4, 4, 2, 4, 4};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
            }
            else if (strcmp(OnProcess_StudentData.MainCourse_CodeName_Passer, "BSEnSE") == 0)
            {
                if (strcmp(OnProcess_StudentData.Course_YearChoice, "1st Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"MATH 001", "MATH 002", "CHEM 001", "AR 001", "COE 001", "ENGL 001", "FIL 001", "PE 001", "NSTP 001"};
                        char *Subject_FullName[12] = {"COLLEGE ALGEBRA", "PLANE AND SPHERICAL TRIGONOMETRY", "GENERAL CHEMISTRY", "ENGINEERING DRAWING", "ENGINEERING ORIENTATION", "COMMUNICATION ARTS 1", "KOMUNIKASYON SA AKADEMIKONG FILIPINO", "PHYSICAL FITNESS", "NATIONAL SERVICE TRAINING PROGRAM 1"};
                        char *Subject_LinearTime[12] = {"7:30AM - 8:30AM", "8:30AM - 9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 12:30PM", "12:30AM - 1:30PM", "1:30PM - 2:30PM", "2:30PM - 3:30PM", "3:30PM - 4:30PM"};
                        int Subject_Units[12] = {3, 3, 3, 0, 1, 3, 3, 2, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"MATH 003", "MATH 004", "MATH 005", "CPE 001", "ENGL 002", "FIL 002", "HUM 001", "PE 002", "NSTP 002"};
                        char *Subject_FullName[12] = {"ADVANCED ALGEBRA", "ANALYTIC GEOMETRY", "SOLID MENSURATION", "COMPUTER FUNDAMENTALS", "COMMUNICATION ARTS 2", "PAGBASA AT PAGSULAT TUNGO SA PANANALIKSIK", "INTRODUCTION TO PHILOSOPHY", "RHYTHMIC ACTIVITIES", "NATIONAL SERVICE TRAINING PROGRAM 2"};
                        char *Subject_LinearTime[12] = {"7:30AM - 8:30AM", "8:30AM - 9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 12:30PM", "12:30AM - 1:30PM", "1:30PM - 2:30PM", "2:30PM - 3:30PM", "3:30PM - 4:30PM"};
                        int Subject_Units[12] = {2, 3, 2, 0, 3, 3, 3, 2, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
                else if (strcmp(OnProcess_StudentData.Course_YearChoice, "2nd Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"MATH 007", "CHEM 002", "ENGL 003", "HUM 002", "SOCSC 001", "SOCSC 002", "SOCSC 003", "PE 003"};
                        char *Subject_FullName[12] = {"DIFFERENTIAL CALCULUS", "PRINCIPLES OF ORGANIC AND INORGANIC CHEMISTRY", "TECHNICAL COMMUNICATION", "LOGIC", "ECONOMICS", "AGRARIAN REFORM AND TAXATION", "SOCIETY AND CULTURE W/ FAMILY PLANNING", "PHILIPPINES HISTORY W/ POLITICS & GOVERNANCE", "INDIVIDUAL / DUAL SPORTS"};
                        char *Subject_LinearTime[12] = {"7:30AM - 8:30AM", "8:30AM - 9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 12:30PM", "12:30AM - 1:30PM", "1:30PM - 2:30PM", "2:30PM - 3:30PM", "3:30PM - 4:30PM"};
                        int Subject_Units[12] = {4, 3, 3, 3, 3, 3, 3, 2};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"MATH 008", "MATH 009", "PHYS 001", "CS 100A,", "HUM 003", "SOCSC 004", "SOCSC 005", "PE 004"};
                        char *Subject_FullName[12] = {"INTEGRAL CALCULUS", "PROBABILITY AND STATISTIS", "CALCULUS-BASED PHYSICS 1", "FUNDAMENTALS OF PROGRAMMING AND ALGORITHM", "ETHICS", "GENERAL PSYCHOLOGY", "LIFE AND WORKS OF RIZAL", "SPORTS AND GAMES"};
                        char *Subject_LinearTime[12] = {"7:30AM - 8:30AM", "8:30AM - 9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 12:30PM", "12:30AM - 1:30PM", "1:30PM - 2:30PM", "2:30PM - 3:30PM", "3:30PM - 4:30PM"};
                        int Subject_Units[12] = {4, 3, 3, 1, 3, 3, 3, 2};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
                else if (strcmp(OnProcess_StudentData.Course_YearChoice, "3rd Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"MATH 010", "PHYS 002", "CPE 003", "CE 001", "IE 002", "ME 005", "CE 300", "CE 301", "CHEM 003A"};
                        char *Subject_FullName[12] = {"DIFFERENTIAL EQUATIONS", "CALCULUS-BASED PHYSICS 2", "COMPUTER-AIDED DRAFTING", "STATICS OF RIGID BODIES", "SAFETY MANAGEMENT", "ENGINEERING ECONOMY", "ELEMENTARY SURVEYING", "ENGINEERING GEOLOGY", "ENVIRONMENTAL AND SANITARY CHEMISTRY"};
                        char *Subject_LinearTime[12] = {"7:30AM - 8:30AM", "8:30AM - 9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 12:30PM", "12:30AM - 1:30PM", "1:30PM - 2:30PM", "2:30PM - 3:30PM", "3:30PM - 4:30PM"};
                        int Subject_Units[12] = {3, 4, 1, 3, 2, 3, 3, 3, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"MATH 011A", "CE 002", "CE 003", "CE 303", "IE 001", "CHEM 006", "ME 004", "ENSE 300"};
                        char *Subject_FullName[12] = {"ADV. ENGRG. MATH W/ NUM METHODS", "DYNAMICS OF RIGID BODIES", "MECHANICS OF DEFORMABLE BODIES", "HIGHER SURVEYING", "ENGINEERING MANAGEMENT", "ENVIRONMENTAL ENGINEERING", "THERMODYNAMICS", "MICROBIOLOGY AND PARASITOLOGY FOR ENSE"};
                        char *Subject_LinearTime[12] = {"7:30AM - 8:30AM", "8:30AM - 9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 12:30PM", "12:30AM - 1:30PM", "1:30PM - 2:30PM", "2:30PM - 3:30PM", "3:30PM - 4:30PM"};
                        int Subject_Units[12] = {3, 3, 3, 3, 3, 3, 3, 4};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
                else if (strcmp(OnProcess_StudentData.Course_YearChoice, "4th Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"CE 401", "CE 402", "CE 403", "CE 404", "EE 001A", "ENSE 400", "ENSE 401", "ENSE 411"};
                        char *Subject_FullName[12] = {"GEOTECHNICAL ENGINEERING (SOIL MECHANICS)", "FLUID MECHANICS", "ENGINEERING SURVEYING", "STRUCTURAL THEORY 1", "BASIC ELECTRICAL ENGINEERING", "PUBLIC HEALTH ENGINEERING", "ECOLOGY AND ENVIRONMENTAL POLLUTION", "SPECIAL TOPICS 1 ENSE"};
                        char *Subject_LinearTime[12] = {"7:30AM - 8:30AM", "8:30AM - 9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 12:30PM", "12:30AM - 1:30PM", "1:30PM - 2:30PM", "2:30PM - 3:30PM", "3:30PM - 4:30PM"};
                        int Subject_Units[12] = {4, 3, 4, 4, 3, 3, 2, 1};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"CE 405", "CE 411", "ENSE 402", "ENSE 403", "ENSE 404", "ENSE 405", "ENSE 406", "ENSE 410"};
                        char *Subject_FullName[12] = {"CONSTRUCTION MATERIALS AND TESTING", "HYDRAULICS ENGINEERING", "AIR POLLUTION FUNDAMENTALS", "SOLID WASTE MANAGEMENT", "ENVIRONMENTAL PLANNING", "LAWS AND IMPACT ASSESSMENT", "DESIGN OF SANITARY ENGINEERING STRUCTURES", "OCCUPATIONAL SAFETY AND HEALTH,HYDROLOGY"};
                        char *Subject_LinearTime[12] = {"7:30AM - 8:30AM", "8:30AM - 9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 12:30PM", "12:30AM - 1:30PM", "1:30PM - 2:30PM", "2:30PM - 3:30PM", "3:30PM - 4:30PM"};
                        int Subject_Units[12] = {3, 3, 3, 2, 3, 2, 2, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
                else if (strcmp(OnProcess_StudentData.Course_YearChoice, "5th Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"ENSE 501", "ENSE 502", "ENSE 503", "ENSE 504", "ENSE 505", "ENSE 506", "ENSE 507", "ENSE 508"};
                        char *Subject_FullName[12] = {"PLANT VISITS & SEMINARS FOR ENSE", "SEWERAGE & DRAINAGE ENGINEERING", "ENSE LAWS, ETHICS, CODES, AND STANDARDS", "ENVIRONMENTAL ENGINEERING LABORATORY", "SANITARY SCIENCE, FIRE PROTECTION AND PLUMBING", "RESEARCH IN A.W.N.S POLLUTIONS", "CONSTRUCTION METHODS & PROJECT MANAGEMENT", "WATER SUPPLY ENGINEERING"};
                        char *Subject_LinearTime[12] = {"7:30AM - 8:30AM", "8:30AM - 9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 12:30 PM", "12:30PM - 1:30PM", "1:30PM - 2:30PM", "2:30PM - 3:30PM", "3:30PM - 4:30PM"};
                        int Subject_Units[12] = {1, 3, 3, 1, 4, 3, 4, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"ENSE 509", "ENSE 510", "ENSE 511", "ENSE 512", "ENSE 513", "ENSE 514"};
                        char *Subject_FullName[12] = {"WATER PURIFICATION PROCESS DESIGN", "SEWAGE & INDUSTRIAL WASTEWATER TREATMENT DESG", "RISK & BENEFIT ANALYSIS IN ENSE", "ENSE PLANNING AND DESIGN", "GROUND WATER AND SOIL POLLUTION REMEDIATION", "SPECIAL TOPICS 2 ENSE"};
                        char *Subject_LinearTime[12] = {"7:30AM - 8:30AM", "8:30AM - 9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 12:30 PM", "12:30PM - 1:30PM", "1:30 PM- 2:30PM", "2:30PM - 3:30PM", "3:30PM - 4:30PM"};
                        int Subject_Units[12] = {4, 5, 3, 3, 3, 1};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
            }
            else if (strcmp(OnProcess_StudentData.MainCourse_CodeName_Passer, "BSIE") == 0)
            {
                if (strcmp(OnProcess_StudentData.Course_YearChoice, "1st Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"CHEM 001", "COE 001", "CPE 001", "ENGL 001", "FIL 001", "MATH 001", "MATH 002", "PE 001", "NSTP 001"};
                        char *Subject_FullName[12] = {"GENERAL CHEMISTRY", "ENGINEERING ORIENTATION", "COMPUTER FUNDAMENTALS", "COMMUNICATION ARTS 1", "KOMUNIKASYON SA AKADEMIKONG FILIPINO", " COLLEGE ALGREBRA", "PLANE AND SPHERICAL TRIGONOMETRY", "PHYSICAL FITNES", "NATIONAL SERVICE TRAINING PROGRAM 1"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM"};
                        int Subject_Units[12] = {4, 1, 1, 3, 3, 3, 3, 2, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"AR 001", "ENGL 002", "FIL 002", "HUM 001", "HUM 002", "MATH 003", "MATH 004", "MATH 005", "PE 002", "NSTP 002"};
                        char *Subject_FullName[12] = {"ENGINEERING DRAWING", "COMMJUNICATION ARTS 2", "PAGBASA AT PAGSULAT TUNGO SA PANANALIKSIK", "INTRODUCTION TO PHILOSOPHY", "LOGIC", "ADVANCED ALGEBRA", "ANALYTIC GEOMETRY", "SOLID MENSURATION", "RHYTHMIC ACTIVITIES", "NATIONAL SERVICE TRAINING PROGRAM 2"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM", "6:00PM - 7:00PM"};
                        int Subject_Units[12] = {1, 3, 3, 3, 3, 2, 3, 2, 2, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
                else if (strcmp(OnProcess_StudentData.Course_YearChoice, "2nd Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"CS 100A", "ENGL 003", "MATH 006", "MATH 007", "MATH 013", "PE 003", "SOCSC 001", "SOSCS 001"};
                        char *Subject_FullName[12] = {"FUNDAMENTALS OF PROGRAMMING AND ALGORITHM", "TECHINICAL COMMUNICATIONS", "DISCRETE MATHEMATICS", "DIFFERENTIAL CALCULUS", "LINEAR ALGEBRA W/ MATLAB", "INDIVIDUAL / DUAL SPORTS", "ECONOMICS, AGRARIAN REFORM AND TAXATION", "SOCIETY AND CULTURE W/ FAMILY PLANNING"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        int Subject_Units[12] = {2, 3, 3, 4, 3, 2, 3, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"CPE 003", "HUM 003", "MATH 008", "MATH 009", "PE 004", "PHYS 001", "SOCSC 003", "SOSCS 004"};
                        char *Subject_FullName[12] = {"COMPUTER-AIDED DRAFTING", "ETHICS", "INTEGRA; CALCULUS", "PROBABILITY AND STATISTICS", "SPORTS AND GAMES", "CALCULUS-BASED PHYSICS 1", "PHILIPPINES HISTORY W/ POLITICS & GOVERNANCE", "GENERAL PSYCHOLOGY"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        int Subject_Units[12] = {1, 3, 4, 3, 2, 4, 3, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
                else if (strcmp(OnProcess_StudentData.Course_YearChoice, "3rd Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"CE 001", "IE 001", "IE 300", "IE 301", "IE 302", "PHYS 002", "MATH 010", "SOCSC 006"};
                        char *Subject_FullName[12] = {"STATICS OF RIGID BODIES", "ENGINEERING MANAGEMENT", "INDUSTRIAL PSYCHOLOGY", "ADVANCED STATISTICS FOR INDUSTRIAL ENGINEERING", "INDUSTRILA MATERIALS AND PROCESSES", "CALCULUS-BASED PHYSICS 2", "DIFFERENTIAL EQUATIONS", "PRINCIPLES OF ECONOMICS"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        int Subject_Units[12] = {3, 3, 3, 3, 3, 4, 3, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"AC 004", "CE 002", "CE 003A", "IE 002", "IE 303", "IE 304", "MATH 011", "ME 005"};
                        char *Subject_FullName[12] = {"FINANCIAL ACCOUNTING", "DYNAMICS OF RIGID BODIES", "MECHANICS OF FORMIDABLE BODIES", "SAFETY MANAGEMENT", "METHODS ENGENNERING", "QUALITY MANAGEMENT SYSTEMS", "ADVANCED ENGINEERING MATHEMATICS", "ENGINEERING ECONOMY"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        int Subject_Units[12] = {3, 3, 3, 2, 5, 3, 3, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
                else if (strcmp(OnProcess_StudentData.Course_YearChoice, "4th Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"AC 005", "IE 003", "IE 004", "IE 401", "IE 402", "IE 403", "ME 004"};
                        char *Subject_FullName[12] = {"MANAGERIAL ACCOUNTING", "OPERATIONS RESEARCH 1", "ENGINEERING ENTREPRENEURSHIP", "ERGONOMICS", "INDUSTRIAL QUALITY CONTROL", "STRATEGIC PLANNING", "THERMODYNAMICS 1"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        int Subject_Units[12] = {3, 3, 3, 3, 3, 3, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"CHEM 002", "EE 001", "IE 404", "IE 405", "IE 406", "IE 407", "IE 408", "SOSCS 005"};
                        char *Subject_FullName[12] = {"ENVIRONMENTAL ENGINEERING", "BASIC ELECTRICAL ENGINEERING", "OPERATIONS RESEARCH 2", "PROJECT FEASIBILITY", "PRODUCTION SYSTEMS", "PRODUCTION SYSTEMS", "PRINCIPLES OF LOGISTICS", "PROJECT MANAGEMENT", " LIFE AND WORKS RIZAL"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        int Subject_Units[12] = {3, 3, 3, 3, 3, 3, 3, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
                else if (strcmp(OnProcess_StudentData.Course_YearChoice, "5th Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"IE 501", "IE 502", "IE 503", "IE 504", "IE 505", "IS 001"};
                        char *Subject_FullName[12] = {"UNDERGRADUATE RESEARCH FOR INDUSTRAIL ENGINEERING", "IE DESIGN PROJECT 1", "PLANT VISITS AND SEMINARS FOR INDUSTRIAL ENGINEERING", "MULTI-CRITERIA DECISON MAKING", "SYSTEMS ENGINEERING", "INFORMATION SYSTEMS"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM"};
                        int Subject_Units[12] = {3, 3, 1, 3, 3, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"IE 500", "IE  506", "IE 507", "IE 508"};
                        char *Subject_FullName[12] = {"ON-THE-JOB TRAINING FOR INDUSTRIAL ENGINEERING", "IE DESIGN PROJECT 2", "FACILITIES DESIGN", "ENGINEERING VALUES AND ETHICS"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM"};
                        int Subject_Units[12] = {5, 2, 3, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
            }
            else if (strcmp(OnProcess_StudentData.MainCourse_CodeName_Passer, "BSME") == 0)
            {
                if (strcmp(OnProcess_StudentData.Course_YearChoice, "1st Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"ENGL 001", "FIL 001", "MATH 001", "MATH 002", "CHEM 001", "COE 001", "CPE 001", "PE 001", "NSTP 001"};
                        char *Subject_FullName[12] = {"COMMUNICATION ARTS 1", "KOMUNIKASYON SA AKADEMIKONG FILIPINO", "COLLEGE ALGEBRA", "PLANE AND SPHERICAL TRIGONOMETRY", "GENERAL CHEMISTRY", "ENGINEERING ORIENTATION", "COMPUTER FUNDAMENTALS", "PHYSICAL FITNESS", "NATIONAL SERVICE TRAINING PROGRAM 1"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM"};
                        int Subject_Units[12] = {3, 3, 3, 3, 4, 1, 1, 2, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"ENGL 002", "FIL 002", "AR 001", "CHEM 101", "MATH 003", "MATH 004", "MATH 005", "HUM 001", "PE 001", "NSTP 002"};
                        char *Subject_FullName[12] = {"COMMUNICATION ARTS 002", "PAGBASA AT PAGSULAT TUNGO SA PANANALIKSIK", "ENGINEERING DRAWING", "GENERAL CHEMISTRY CALCULATIONS", "ADVANCED ALGEBRA", "ANALYTICAL GEOMETRY", "SOLID MENSURATION", "INTRODUCTION TO PHILOSOPHY", "RHYTHMIC ACTIVITIES", "NATIONAL SERVICE TRAINING 2"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM", "6:00PM - 7:00PM"};
                        int Subject_Units[12] = {3, 3, 1, 3, 2, 3, 2, 3, 2, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
                else if (strcmp(OnProcess_StudentData.Course_YearChoice, "2nd Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"CHEM 002", "CS 100A", "ENGL 003", "HUM 002", "MATH 007", "MATH 013", "SOCSC 001", "SOCSC 002", "PE 003"};
                        char *Subject_FullName[12] = {"ENVIRONMENTAL ENGINEERING", "FUNDAMENTALS OF PROGRAMMING AND ALGORITHM", "TECHNICAL COMMUNICATION", "LOGIC", "DIFFERENTIAL CALCULUS", "LINEAR ALGEBRA W/ MATLAB", "ECONOMICS, AGRARIAN AND REFORM AND TAXATION", "SOCIETY AND CULTURE W/ FAMILY PLANNING", "INDIVIDUAL / DUAL SPORTS"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM"};
                        int Subject_Units[12] = {3, 2, 3, 3, 4, 3, 3, 3, 2};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"CHEM 201", "HUM 003", "MATH 008", "MATH 009", "PHYS 001", "SOCSC 003", "PE 004"};
                        char *Subject_FullName[12] = {"ANALYTICAL CHEMISTRY", "ETHICS", "INTEGRAL CALCULUS", "PROBABILITY AND STATISTICS", "CALCULUS-BASED PHYSICS 001", "PHILIPPINE HISTORY W/ POLITICS GOVERNANCE", "SPORTS AND GAMES"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        int Subject_Units[12] = {5, 3, 4, 3, 4, 3, 2};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
                else if (strcmp(OnProcess_StudentData.Course_YearChoice, "3rd Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"CHEM 301", "CHEM 003", "CE 001", "CPE 003", "IE 001", "MATH 010", "PHYS 002", "CHE 303"};
                        char *Subject_FullName[12] = {"PHYSICAL CHEMISTRY", "ORGANIC CHEMISTRY", "STATICS OF RIGID BODIES", "COMPUTER-AIDED DRAFTING", "ENGINEERING MANAGEMENT", "DIFFERENTIAL EQUATIONS", "CALCULUS-BASED PHYSICS 2", "CHE CALCULATIONS 1"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM"};
                        int Subject_Units[12] = {4, 5, 3, 1, 3, 3, 4, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"CHEM 302", "CHEM 322", "CE 002", "CE 003A", "EE 005", "CHEM 004", "MATH 011", "CHE 304"};
                        char *Subject_FullName[12] = {"PHYSICAL CHEMISTRY FOR ENGINEERS 2", "CHE CALCULATIONS 2", "DYNAMICS OF RIGID BODIES", "MECHANICS OF DEFORMABLE BODIES", "BASIC ELECTRICAL AND ELECTRONICS ENGINEERNG", "MATERIALS SCIENCE AND ENGINEERING", "ADVANCED ENGINEERING MATHEMATICS", "INTEGRATION COURSE 1 FOR CHE"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        int Subject_Units[12] = {4, 3, 3, 3, 3, 3, 3, 2};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
                else if (strcmp(OnProcess_StudentData.Course_YearChoice, "4th Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"CHEM 005", "IE 002", "CHE 402", "CHE 403", "CHE 404", "CHE 405", "MATH 012", "ME 005", "SOCSC 004"};
                        char *Subject_FullName[12] = {"INDUSTRIAL CHEMISTRY FOR CHE", "SAFETY MANAGEMENT", "INTRODUCTION TO BIOTECHNOLOGY", "PRINCIPLES OF TRANSPORT PROCESSES", "CHE RESEARCH 1", "CHE THERMODYNAMICS 1", "NUMERICAL METHODS", "ENGINEERING ECONOMY", "GENERAL PSYCHOLOGY"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM"};
                        int Subject_Units[12] = {3, 2, 3, 3, 2, 3, 4, 3, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"CHE 406", "CHE 407", "CHE 408", "CHE 409", "CHE 410", "CHE 411", "CHE 412", "ECE 006", "CHE 413"};
                        char *Subject_FullName[12] = {"MOMENTUM TRANSFER", "CHE THEMODYNAMICS 2", "HEAT AND MASS TRANSFER", "UNIT OPERATIONS LABORATORY 1", "CHEMICAL PROCESS INDUTRIES", "CHEMICAL REACTION ENGINEERING", "CHE RESEARCH 2", "FEEDBACK AND CONTROL SYSTEMS", "INTEGRATION COURSE 2 FOR CHE"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM"};
                        int Subject_Units[12] = {3, 3, 3, 1, 3, 4, 1, 4, 2};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
                else if (strcmp(OnProcess_StudentData.Course_YearChoice, "5th Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"CHE 501", "CHE 502", "CHE 503", "CHE 504", "CHE 505", "CHE 506", "CHE 507", "CHE 508", "CHE 509", "SOCSC 005"};
                        char *Subject_FullName[12] = {"SEPARATION PROCESSES", "UNIT OPERATIONS LABORATORY 2", "BIOCHEMICAL ENGINEERING", "SAFETY IN THE PROCESS INDUSTRY", "EQUIPMENT DESIGN", "INTRODUCTION TO POLYMER ENGINEERING", "CHE LAWS, ETHICS, CODES AND STANDARDS", "COMPUTER APPLICATIONS IN CHE", "INTRODUCTION TO PARTICLE TECHNOLOGY", "LIFE AND WORKS OF RIZAL"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM", "6:00PM - 7:00PM"};
                        int Subject_Units[12] = {3, 1, 3, 2, 2, 3, 2, 1, 2, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"CHE 510", "CHE 511", "CHE 512", "CHE 513", "CHE 514", "CHE 515", "IE 003"};
                        char *Subject_FullName[12] = {"INDUSTRIAL WASTE MANAGEMENT AND CONTROL", "CHE PLANT DESIGN", "PLASTICS TECHNOLOGY", "MOLECULAR BIOLOGY", "INTEGRATION COURSE 3 FOR CHE", "PLANT VISITS AND SEMINARS FOR CHE", "OPERATIONS RESEARCH 1"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        int Subject_Units[12] = {3, 3, 3, 3, 2, 1, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
            }
            else if (strcmp(OnProcess_StudentData.MainCourse_CodeName_Passer, "Arch") == 0)
            {
                if (strcmp(OnProcess_StudentData.Course_YearChoice, "1st Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"MATH 001", "MATH 002", "ENGL 001", "FIL 001", "ARCH 005", "ARCH 007", "ARCH 003", "PE 001", "NSTP 001"};
                        char *Subject_FullName[12] = {"COLLEGE ALGEBRA", "PLANE AND SPHERICAL TRIGONOMETRY", "COMMUNICATION ARTS 1", "KOMUNIKASYON SA AKADEMIKONG FILIPINO 1", "ARCHITURAL DESIGN 1", "ARCHITECTURAL VISUAL COMMUNICATIONS 1", "THEORY OF ARCHITECTURE 1", "PHYSICAL FITNESS 1", "NATIONAL SERVICE TRAINING PROGRAM 1"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM"};
                        int Subject_Units[12] = {3, 3, 3, 3, 2, 3, 2, 2, 2, 3, 0, 0};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"MATH 004", "MATH 005", "PHYS 001", "ENGL 002", "FIL 002", "ARCH 005-1", "ARCH 007-1", "ARCH 003-1", "PE 002", "NSTP 002"};
                        char *Subject_FullName[12] = {"ANALYTIC GEOMETRY", "SOLID MENSURATION", "PHYSICS 1", "COMMUNICATION ARTS 2", "KOMUNIKASYON SA AKADEMIKONG FIIPINO 2", "ARCHITECTURAL DESIGN 2", "ARCHITECTURAL VISUAL COMMUNICATIONS 3", "ARCHITECTURAL VISUAL COMMUNICATIONS 4", "THEORY OF ARCHITECTURE 2", "RHYTHMIC ACTIVITIES", "NATIONAL SERVCE TRAINING PROGRAM 2"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM", "6:00PM - 7:00PM", "7:00PM - 8:00PM"};
                        int Subject_Units[12] = {2, 2, 3, 3, 3, 2, 3, 2, 3, 2, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
                else if (strcmp(OnProcess_StudentData.Course_YearChoice, "2nd Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"MATH 007", "PHYS 002", "SOCSC 002", "ARCH 005-2", "ARCH 001", "ARCH 003-2", "ARCH 002", "ARCH 009", "PE 003"};
                        char *Subject_FullName[12] = {"DIFFERENTIAL CALCULUS", "PHYSICS 2", "SOCIETY AND CULTURE W/ FAMILY PLANNING", "ARCHITECTURAL DESIGN 3", "BUILDING TECHNOLOGY 1", "ARCHITECTURAL VISUAL COMMUNICATIONS 5", "ARCHITECTURAL INTERIORS", "HISTORY OF ARCHITECTURE ", "INDIVIDUALDUAL SPORTS"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM"};
                        int Subject_Units[12] = {3, 3, 3, 3, 3, 2, 3, 3, 2};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"CE 001", "ARCH 011", "PSYH 001", "ARCH 005-3", "ARCH 001-1", "ARCH 015", "ARCH 010", "ARCH 009-1", "PE 004"};
                        char *Subject_FullName[12] = {"STATICS OF RIGID BODIES", "SURVEYING", "GENERAL PSYCHOLOGY", "ARCHITECTURAL DESIGN 4", "BUILDING TECHNOLOGY 2", "BUILDING UTILITIES 1", "TROPICAL DESIGN", "HISTORY OF ARCHITECTURE 2", "SPORTS AND GAMES"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM", "4:00PM - 5:00PM", "5:00PM - 6:00PM"};
                        int Subject_Units[12] = {3, 3, 3, 3, 3, 3, 3, 3, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
                else if (strcmp(OnProcess_StudentData.Course_YearChoice, "3rd Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"ARCH 013", "CPE 003", "ARCH 005-4", "ARCH 001-2", "ARCH 015-1", "ARCH 009-2", "ARCH 014"};
                        char *Subject_FullName[12] = {"STRENGTH OF MATERIALS", "COMPUTER-AIDED DRAFTING", "ARCHITECTURAL DESIGN 5", "BUILDING TECHNOLOGY 3", "BUILDING UTILITIES 3", "HISTORY OF ARCHITECTURE 3", "PROFESSIONAL PRACTICE 1"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        int Subject_Units[12] = {3, 3, 4, 3, 3, 3, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"ARCH 005-5", "ARCH 016", "ARCH 017", "ARCH 001-2", "ARCH 015-2", "ARCH 009-3", "ARCH 014-1", "ARCH 007"};
                        char *Subject_FullName[12] = {"ARCHITECTURAL DESIGN 6", "BUILDING INFORMATION MODELLING", "THEORY OF STRUCTURE", "BUILDING TECHNOLOGY 4", "BUILDING UTILITIES 3", "HISTORY OF ARCHITECTURE 4", "PROFESSIONAL PRACTICE 2", "PLANNING 1"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        int Subject_Units[12] = {4, 3, 3, 3, 3, 2, 3, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
                else if (strcmp(OnProcess_StudentData.Course_YearChoice, "4th Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"ENGL 003", "LIT 001", "ARCH 020", "ARCH 005-6", "ARCH 001-3", "ARCH 007-1"};
                        char *Subject_FullName[12] = {"COMMUNICATION ARTS 3", "LITERATURE 1", "STEEL AND TIMBER DESIGN", "ARCHITECTURAL DESIGN 7", "BUILDING TECHONOLOGY 5", "PLANNING 2"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM"};
                        int Subject_Units[12] = {3, 3, 3, 5, 3, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"ARCH 005-7", "ARCH 018", "ARCH 007-2", "ARCH 014-2", "ARCH 021", "ARCH 100A", "???"};
                        char *Subject_FullName[12] = {"ARCHITECTURAL DESIGN 8", "HOUSING", "PLANNING 3", "PROFESSIONAL PRACTICE 3", "ARCHITETURAL STRUCTURES", "RESEARCH METHODS FOR ARCHITECTURE", "SPECIALIZATION 1"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM", "3:00PM - 4:00PM"};
                        int Subject_Units[12] = {5, 3, 3, 3, 5, 3, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
                else if (strcmp(OnProcess_StudentData.Course_YearChoice, "5th Year College") == 0)
                {
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "First Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"PHILO 001", "HUM 001", "HUM 002", "ARCH 005-8"};
                        char *Subject_FullName[12] = {"PHILOSOPHY", "HUMANITIES", "SOCIOLOGY OF ANTHROPOLOGY", "ARCHITECTURAL DESIGN 9", "SPECIALIZATION 2", "ARCHITECTURE COMPREHENSIVE COURSE"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM"};
                        int Subject_Units[12] = {3, 3, 3, 5, 3, 3};
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                    if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second Semester") == 0)
                    {
                        char *Subject_CodeName[12] = {"SOSCS 005", "SOCSC 002", "SOCSC 003", "ARCH 005-9", "???"};
                        char *Subject_FullName[12] = {"LIFE AND WORKS OF RIZAL", "TAXATION AND AGRARIAN REFORM", "POLITICS AND GOVERNANCE W/ NEW CONSTITUTION", "ARCHITECTURAL DESIGN 10", "SPECIALIZATION 3"};
                        char *Subject_LinearTime[12] = {"8:00AM - 9:00AM", "9:00AM - 10:00AM", "10:00AM - 11:00AM", "11:00AM - 12:00PM", "12:00PM - 1:00PM", "2:00PM - 3:00PM"};
                        int Subject_Units[12] = {3, 3, 3, 5, 3};
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
            SetCursorCoord_XY(30, 29);
            printf("\xAF \xDD INFO \xDD Reinitializing function to go back...");
            //Sleep(1750);
            Func_NewStdnt_YearSemSelect();
            break;
        default:
            SetCursorCoord_XY(30, 29);
            printf("\xAF \xDD ERROR \xDD Sorry, I don't understand that...");
            //Sleep(1750);
            continue;
        }
        break;
    }
}

int Func_SubjectUnit_Selection(char **Subject_CodeName, char **Subject_FullName, char **Subject_LinearTime, int Subject_Units[12])
{
    system("CLS");
    SetConsoleTitle(FUNCTION_STEP3);
    int Subject_Selector = 0,
        Option_Selector = 0,
        Final_Comp_SelectedSubjects = 0,
        Final_Comp_SemUnits = 0,
        Subject_Counter = 0,
        Subject_Selection_Checker,
        Transport_Element = 0,
        Transport_PassElementTrue = 0,
        Subject_UnitsGuard_AntiDuplicate_Include[12] = {0},
        Subject_UnitsGuard_AntiDuplicate_Exclude[12] = {0},
        Nullifier_Parameter[12] = {0},
        Counter = 0,
        Setup_Counter = 0,
        Subject_ExpectedCandidates = 0,
        Subject_ExpectedSemUnits = 0,
        Sizeof_SemSelection = strlen(OnProcess_StudentData.Course_SemSelection),
        Sizeof_YearChoice = strlen(OnProcess_StudentData.Course_YearChoice),
        Sizeof_FullNamePasser = strlen(OnProcess_StudentData.MainCourse_FullName_Passer);
    char Final_Decision_Selector;
    // Default Placeholder for Selection
    char *Subject_Parameters[2] = {"Include", "Exclude"};
    char *Subject_Status[12] = {"Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown"};
    char *Subject_Include[12] = {"Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown"};
    char *Subject_ScheduleDay[12] = {"MoWeFr", "Tu", "MoSat", "MoWeFr", "We", "Th", "MoweFr", "TuTh", "TuTh", "FrSat", "We", "Sat"};
    // Assign Null Pointer Elements to the following strings.
    for (Setup_Counter = 0; Setup_Counter <= 11; Setup_Counter++)
    {
        if ((Subject_CodeName[Setup_Counter] == NULL) || (Subject_FullName[Setup_Counter] == NULL))
        {
            Subject_CodeName[Setup_Counter] = "NONE";
            Subject_FullName[Setup_Counter] = "NOT AVAILABLE";
            Subject_LinearTime[Setup_Counter] = "N/A - N/A";
            Subject_ScheduleDay[Setup_Counter] = "N/A";
            Subject_Units[Setup_Counter] = 0;
            Nullifier_Parameter[Setup_Counter] = 1;
        }
        else if ((Subject_CodeName[Setup_Counter] != NULL) || (Subject_FullName[Setup_Counter] != NULL))
        {
            Nullifier_Parameter[Setup_Counter] = 0;
            Subject_ExpectedCandidates += 1;
            Subject_ExpectedSemUnits += Subject_Units[Setup_Counter];
        }
    }
    // Let program calculate non-null element arrays to count for subject_whole size.

    while (1)
    {
        //Looping Variables Will Be Reinitialized Here
        int Sbj_Stats_Increment = 0, Sbj_Stats_Decrement = 0, Subject_Receive_Exclude_Count = 0, Subject_Receive_Unknown_Count = 0;
        system("CLS");
        SetCursorCoord_XY(20, 3);
        printf("\xC9\xCD\xCD \xDD CURRENT PROGRESS \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        SetCursorCoord_XY(20, 4);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        SetCursorCoord_XY(20, 5);
        printf("\xBA [1st \xAF 2nd \xAF \xDD\xAF [3rd Step \xAF Subject Enrollment Selection] \xAF 3rd \xAF 4th \xAF 5th \xAF Confirm \xAF End]\t\t\t\t       \xBA");
        SetCursorCoord_XY(20, 6);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        SetCursorCoord_XY(20, 7);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        SetCursorCoord_XY(20, 9);
        printf("\xC9\xCD\xCD \xDD SEPERATOR INDICATORS \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        SetCursorCoord_XY(20, 10);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        SetCursorCoord_XY(20, 11);
        printf("\xBA%6s   \xDD%7s  \xDE  %-63s\xDD%6s    \xDD%16s     \xDD%7s    \xBA", "[ # ]", "STATUS", "SUBJECT CODE - SUBJECT PRIMARY FULLNAME", "DAY", "LINEAR TIME", "UNITS");
        SetCursorCoord_XY(20, 12);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        SetCursorCoord_XY(20, 13);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        SetCursorCoord_XY(20, 13);
        printf("\xCC\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xB9");
        SetCursorCoord_XY(20, 14);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        SetCursorCoord_XY(20, 15);
        printf("\xBA [ 1 ]   \xDD %-8s\xDE    %-10s -  %-46s \xDD  %-8s\xDD  %-19s\xDD%5i      \xBA", Subject_Status[0], Subject_CodeName[0], Subject_FullName[0], Subject_ScheduleDay[0], Subject_LinearTime[0], Subject_Units[0]);
        SetCursorCoord_XY(20, 16);
        printf("\xBA [ 2 ]   \xDD %-8s\xDE    %-10s -  %-46s \xDD  %-8s\xDD  %-19s\xDD%5i      \xBA", Subject_Status[1], Subject_CodeName[1], Subject_FullName[1], Subject_ScheduleDay[1], Subject_LinearTime[1], Subject_Units[1]);
        SetCursorCoord_XY(20, 17);
        printf("\xBA [ 3 ]   \xDD %-8s\xDE    %-10s -  %-46s \xDD  %-8s\xDD  %-19s\xDD%5i      \xBA", Subject_Status[2], Subject_CodeName[2], Subject_FullName[2], Subject_ScheduleDay[2], Subject_LinearTime[2], Subject_Units[2]);
        SetCursorCoord_XY(20, 18);
        printf("\xBA [ 4 ]   \xDD %-8s\xDE    %-10s -  %-46s \xDD  %-8s\xDD  %-19s\xDD%5i      \xBA", Subject_Status[3], Subject_CodeName[3], Subject_FullName[3], Subject_ScheduleDay[3], Subject_LinearTime[3], Subject_Units[3]);
        SetCursorCoord_XY(20, 19);
        printf("\xBA [ 5 ]   \xDD %-8s\xDE    %-10s -  %-46s \xDD  %-8s\xDD  %-19s\xDD%5i      \xBA", Subject_Status[4], Subject_CodeName[4], Subject_FullName[4], Subject_ScheduleDay[4], Subject_LinearTime[4], Subject_Units[4]);
        SetCursorCoord_XY(20, 20);
        printf("\xBA [ 6 ]   \xDD %-8s\xDE    %-10s -  %-46s \xDD  %-8s\xDD  %-19s\xDD%5i      \xBA", Subject_Status[5], Subject_CodeName[5], Subject_FullName[5], Subject_ScheduleDay[5], Subject_LinearTime[5], Subject_Units[5]);
        SetCursorCoord_XY(20, 21);
        printf("\xBA [ 7 ]   \xDD %-8s\xDE    %-10s -  %-46s \xDD  %-8s\xDD  %-19s\xDD%5i      \xBA", Subject_Status[6], Subject_CodeName[6], Subject_FullName[6], Subject_ScheduleDay[6], Subject_LinearTime[6], Subject_Units[6]);
        SetCursorCoord_XY(20, 22);
        printf("\xBA [ 8 ]   \xDD %-8s\xDE    %-10s -  %-46s \xDD  %-8s\xDD  %-19s\xDD%5i      \xBA", Subject_Status[7], Subject_CodeName[7], Subject_FullName[7], Subject_ScheduleDay[7], Subject_LinearTime[7], Subject_Units[7]);
        SetCursorCoord_XY(20, 23);
        printf("\xBA [ 9 ]   \xDD %-8s\xDE    %-10s -  %-46s \xDD  %-8s\xDD  %-19s\xDD%5i      \xBA", Subject_Status[8], Subject_CodeName[8], Subject_FullName[8], Subject_ScheduleDay[8], Subject_LinearTime[8], Subject_Units[8]);
        SetCursorCoord_XY(20, 24);
        printf("\xBA [ 10 ]  \xDD %-8s\xDE    %-10s -  %-46s \xDD  %-8s\xDD  %-19s\xDD%5i      \xBA", Subject_Status[9], Subject_CodeName[9], Subject_FullName[9], Subject_ScheduleDay[9], Subject_LinearTime[9], Subject_Units[9]);
        SetCursorCoord_XY(20, 25);
        printf("\xBA [ 11 ]  \xDD %-8s\xDE    %-10s -  %-46s \xDD  %-8s\xDD  %-19s\xDD%5i      \xBA", Subject_Status[10], Subject_CodeName[10], Subject_FullName[10], Subject_ScheduleDay[10], Subject_LinearTime[10], Subject_Units[10]);
        SetCursorCoord_XY(20, 26);
        printf("\xBA [ 12 ]  \xDD %-8s\xDE    %-10s -  %-46s \xDD  %-8s\xDD  %-19s\xDD%5i      \xBA", Subject_Status[11], Subject_CodeName[11], Subject_FullName[11], Subject_ScheduleDay[11], Subject_LinearTime[11], Subject_Units[11]);
        SetCursorCoord_XY(20, 27);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        SetCursorCoord_XY(20, 28);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        SetCursorCoord_XY(20, 30);
        printf("\xFE\xCD\xCD \xDD SELECTION STATISTICS \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
        SetCursorCoord_XY(20, 32);
        printf("          %-40s \xAF %d / %d  \xDD %28s \xAF %d / %-2d", "Total Included Subject/s", Final_Comp_SelectedSubjects, Subject_ExpectedCandidates, "Total Included Units", Final_Comp_SemUnits, Subject_ExpectedSemUnits);
        SetCursorCoord_XY(20, 33);
        SetCursorCoord_XY(20, 33);
        printf("          %-40s \xAF %-*s, %-*s \xDD %-*s", "Current list of subjects is only for", Sizeof_YearChoice, OnProcess_StudentData.Course_YearChoice, Sizeof_FullNamePasser, OnProcess_StudentData.MainCourse_FullName_Passer, Sizeof_SemSelection, OnProcess_StudentData.Course_SemSelection);
        SetCursorCoord_XY(20, 35);
        printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
        SetCursorCoord_XY(20, 37);
        printf("\xC9\xCD\xCD \xDD OPTIONS FOR INPUT \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        SetCursorCoord_XY(20, 38);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        SetCursorCoord_XY(20, 39);
        printf("\xBA         %-50s\xDD  %41s\t\t\t       \xBA", "Input '1' To Include Subject/s", "Input '4' To Include All Subject/s");
        SetCursorCoord_XY(20, 40);
        printf("\xBA         %-50s\xDD  %41s\t\t\t       \xBA", "Input '2' To Exclude Subject/s", "Input '5' To Exclude All Subject/s");
        SetCursorCoord_XY(20, 41);
        printf("\xBA         %-50s\xDD  %50s\t\t       \xBA", "Input '3' to process your encoded data.", "Input '6' To Reset Back To Default Settings");
        SetCursorCoord_XY(20, 42);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        SetCursorCoord_XY(20, 43);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        SetCursorCoord_XY(20, 45);
        printf("\xC8\xAF \xDD INPUT \xDD Please input your desired option and press ENTER \xDD\xAF ");
        scanf("%d", &Option_Selector);
        if (Option_Selector == 1)
        {
            SetCursorCoord_XY(20, 47);
            printf("\xC8\xAF \xDD QUESTION \xDD Please select the subject number to be included \xDD\xAF ");
            scanf("%d", &Subject_Selector);
            if (Subject_Selector == 1)
            {
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    //Sleep(1000);
                    continue;
                }
                else
                {
                    if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[0];
                        Final_Comp_SelectedSubjects += 1;
                        Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 2)
            {
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    //Sleep(1000);
                    continue;
                }
                else
                {
                    if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[0];
                        Final_Comp_SelectedSubjects += 1;
                        Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 3)
            {
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    //Sleep(1000);
                    continue;
                }
                else
                {
                    if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[0];
                        Final_Comp_SelectedSubjects += 1;
                        Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 4)
            {
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    //Sleep(1000);
                    continue;
                }
                else
                {
                    if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[0];
                        Final_Comp_SelectedSubjects += 1;
                        Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 5)
            {
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    //Sleep(1000);
                    continue;
                }
                else
                {
                    if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[0];
                        Final_Comp_SelectedSubjects += 1;
                        Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 6)
            {
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    //Sleep(1000);
                    continue;
                }
                else
                {
                    if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[0];
                        Final_Comp_SelectedSubjects += 1;
                        Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 7)
            {
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    //Sleep(1000);
                    continue;
                }
                else
                {
                    if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[0];
                        Final_Comp_SelectedSubjects += 1;
                        Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 8)
            {
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    //Sleep(1000);
                    continue;
                }
                else
                {
                    if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[0];
                        Final_Comp_SelectedSubjects += 1;
                        Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 9)
            {
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    //Sleep(1000);
                    continue;
                }
                else
                {
                    if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[0];
                        Final_Comp_SelectedSubjects += 1;
                        Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 10)
            {
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    //Sleep(1000);
                    continue;
                }
                else
                {
                    if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[0];
                        Final_Comp_SelectedSubjects += 1;
                        Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 11)
            {
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    //Sleep(1000);
                    continue;
                }
                else
                {
                    if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[0];
                        Final_Comp_SelectedSubjects += 1;
                        Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 12)
            {
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    //Sleep(1000);
                    continue;
                }
                else
                {
                    if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[0];
                        Final_Comp_SelectedSubjects += 1;
                        Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                }
            }
            else
            {
                SetCursorCoord_XY(20, 48);
                printf("\xDD WARNING \xAF You have inputted a wrong number! Out of Choice.Bonds! Reinitialing Function...");
                //Sleep(1750);
                continue;
            }
        }
        else if (Option_Selector == 2)
        {
            SetCursorCoord_XY(20, 47);
            printf("\xC8\xAF \xDD QUESTION \xDDPlease select the subject number to be excluded \xAF ");
            scanf("%d", &Subject_Selector);
            if (Subject_Selector == 1)
            {
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    //Sleep(1000);
                    continue;
                }
                else
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
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i \xDD '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i \xDD '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 2)
            {
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    //Sleep(1000);
                    continue;
                }
                else
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
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i \xDD '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i \xDD '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 3)
            {
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    //Sleep(1000);
                    continue;
                }
                else
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
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i \xDD '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i \xDD '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 4)
            {
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    //Sleep(1000);
                    continue;
                }
                else
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
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i \xDD '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i \xDD '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 5)
            {
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    //Sleep(1000);
                    continue;
                }
                else
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
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i \xDD '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i \xDD '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 6)
            {
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    //Sleep(1000);
                    continue;
                }
                else
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
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i \xDD '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i \xDD '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 7)
            {
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    //Sleep(1000);
                    continue;
                }
                else
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
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i \xDD '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i \xDD '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 8)
            {
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    //Sleep(1000);
                    continue;
                }
                else
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
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i \xDD '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i \xDD '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 9)
            {
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    //Sleep(1000);
                    continue;
                }
                else
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
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i \xDD '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i \xDD '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 10)
            {
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    //Sleep(1000);
                    continue;
                }
                else
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
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i \xDD '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i \xDD '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 11)
            {
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    //Sleep(1000);
                    continue;
                }
                else
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
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i \xDD '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i \xDD '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 12)
            {
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    //Sleep(1000);
                    continue;
                }
                else
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
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i \xDD '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i \xDD '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        //Sleep(500);
                        continue;
                    }
                }
            }
        }
        else if (Option_Selector == 3)
        {
            fflush(stdin);
            while (1)
            {
                SetCursorCoord_XY(20, 47);
                printf("\xDD QUESTION \xAF Are you sure that you picked the subjects that you wanted to take???");
                SetCursorCoord_XY(20, 48);
                printf("\xDD Pick your choice \xAF [Y]es or [N]o \xAF ");
                Final_Decision_Selector = getche();
                if ((Final_Decision_Selector == 'Y') || (Final_Decision_Selector == 'y'))
                {
                    for (Subject_Selection_Checker = 0; Subject_Selection_Checker < Subject_ExpectedCandidates; Subject_Selection_Checker++)
                    {
                        if (Subject_Status[Subject_Selection_Checker] == "Unknown")
                        {
                            Subject_Receive_Unknown_Count += 1;
                        }
                        else if (Subject_Status[Subject_Selection_Checker] == "Exclude")
                        {
                            Subject_Receive_Exclude_Count += 1;
                        }
                    }
                    if (Subject_Receive_Exclude_Count == Subject_ExpectedCandidates)
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xDD ERROR \xAF You cannot set all subject/s to be 'Exclude'. Are you trying to enroll without subjects!?");
                        //Sleep(5000);
                        break;
                    }
                    else if (Subject_Receive_Exclude_Count < Subject_Receive_Unknown_Count)
                    {

                        SetCursorCoord_XY(20, 48);
                        printf("\xDD ERROR \xAF You cannot leave subject/s to be 'Unknown'. Set them to exclude if you don't want to include it.");
                        //Sleep(3000);
                        break;
                    }
                    else if ((Subject_Receive_Exclude_Count || Subject_Receive_Unknown_Count != Subject_ExpectedCandidates) || (Subject_Receive_Exclude_Count || Subject_Receive_Unknown_Count == 0))
                    {
                        SetCursorCoord_XY(20, 50);
                        printf("\xDD INFO \xAF Processing Data...");
                        //Transport_PassElementTrue = 0;
                        for (Transport_Element = 0; Transport_Element <= Subject_ExpectedCandidates; Transport_Element++)
                        {
                            if (strcmp(Subject_Status[Transport_Element], Subject_Parameters[0]) == 0)
                            {
                                ERLM_DataReceiver.Subject_CodeName_Receiver[Transport_Element] = Subject_CodeName[Transport_Element];
                                ERLM_DataReceiver.Subject_FullName_Receiver[Transport_Element] = Subject_FullName[Transport_Element];
                                ERLM_DataReceiver.Subject_LinearTime_Receiver[Transport_Element] = Subject_LinearTime[Transport_Element];
                                ERLM_DataReceiver.Subject_ScheduleDay_Receiver[Transport_Element] = Subject_ScheduleDay[Transport_Element];
                                ERLM_DataReceiver.Subject_Units_Receiver[Transport_Element] = Subject_Units[Transport_Element];
                                ERLM_DataReceiver.Subject_Candidates = Subject_ExpectedCandidates;
                                ERLM_DataReceiver.Subjects_Selected = Final_Comp_SelectedSubjects;
                                //Transport_PassElementTrue++;
                            }
                        }
                        SetCursorCoord_XY(20, 51);
                        printf("\xDD PROCESS \xAF Moving Foward in the Next Step...");
                        //Sleep(3000);
                        Func_Final_Overview(Final_Comp_SelectedSubjects, Subject_ExpectedCandidates);
                        break;
                    }
                }
                else if ((Final_Decision_Selector == 'N') || (Final_Decision_Selector == 'n'))
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xDD PROCESS \xAF Going back to Subject Selection...");
                    //Sleep(1500);
                    break;
                }
                else
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xDD ERROR \xAF Sorry, I don't understand that...");
                    //Sleep(1500);
                    break;
                }
            }
            continue;
        }
        else if (Option_Selector == 7)
        {
            Func_NewStdnt_CourseReg();
        }
        else if (Option_Selector == 4)
        {
            SetCursorCoord_XY(20, 47);
            printf("\xDD PROCESS \xAF Including All Available Subjects...");
            Final_Comp_SelectedSubjects = 0;
            Final_Comp_SemUnits = 0;
            while (Sbj_Stats_Increment < Subject_ExpectedCandidates)
            {
                Subject_Status[Sbj_Stats_Increment] = Subject_Parameters[0];
                Final_Comp_SelectedSubjects += 1;
                Final_Comp_SemUnits += Subject_Units[Sbj_Stats_Increment];
                Subject_UnitsGuard_AntiDuplicate_Include[Sbj_Stats_Increment] = 1;
                Subject_UnitsGuard_AntiDuplicate_Exclude[Sbj_Stats_Increment] = 0;
                Sbj_Stats_Increment++;
            }
            //Sleep(1500);
            continue;
        }
        else if (Option_Selector == 5)
        {
            SetCursorCoord_XY(20, 47);
            printf("\xDD PROCESS \xAF Excluding All Available Subjects...");
            Final_Comp_SelectedSubjects = 0;
            Final_Comp_SemUnits = 0;
            while (Sbj_Stats_Decrement < Subject_ExpectedCandidates)
            {
                Subject_Status[Sbj_Stats_Decrement] = Subject_Parameters[1];
                Subject_UnitsGuard_AntiDuplicate_Include[Sbj_Stats_Decrement] = 0;
                Subject_UnitsGuard_AntiDuplicate_Exclude[Sbj_Stats_Decrement] = 0;
                Sbj_Stats_Decrement++;
            }
            //Sleep(1500);
            continue;
        }
        else if (Option_Selector == 6)
        {
            SetCursorCoord_XY(20, 47);
            printf("\xDD PROCESS \xAF Resetting Values Back to Default...");
            Final_Comp_SelectedSubjects = 0;
            Final_Comp_SemUnits = 0;
            while (Sbj_Stats_Decrement < Subject_ExpectedCandidates)
            {
                Subject_Status[Sbj_Stats_Decrement] = "Unknown";
                Subject_UnitsGuard_AntiDuplicate_Include[Sbj_Stats_Decrement] = 0;
                Subject_UnitsGuard_AntiDuplicate_Exclude[Sbj_Stats_Decrement] = 0;
                Sbj_Stats_Decrement++;
            }
            //Sleep(1500);
            continue;
        }
        else
        {
            SetCursorCoord_XY(20, 47);
            printf("\xDD WARNING \xAF The button you pressed might be wrong. We can't go non-linear!");
            //Sleep(1750);
            continue;
        }
    }
}
//Continue Function...

void Func_Final_Overview(int Final_Comp_SelectedSubjects, int Subject_ExpectedCandidates)
{
    SetConsoleTitle(FUNCTION_STEP4);
    char *StudentType;
    char *StatusTake;
    int Subject_Pass_Reader = 0, Subject_Pass_Reader_Counter = 1, SetCoordinates_Dependent = 13;
    if (Final_Comp_SelectedSubjects < Subject_ExpectedCandidates)
    {
        StudentType = "Irregular Student";
        StatusTake = "Incomplete Take";
        strcpy(OnProcess_StudentData.stdnt_StudentType, StudentType);
    }
    else
    {
        StudentType = "Regular Student";
        StatusTake = "Complete Take";
        strcpy(OnProcess_StudentData.stdnt_StudentType, StudentType);
    }
    system("CLS");
    SetCursorCoord_XY(30, 3);
    printf("\xC9\xCD\xCD \xDD CURRENT PROGRESS \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
    SetCursorCoord_XY(30, 4);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    SetCursorCoord_XY(30, 5);
    printf("\xBA [1st \xAF 2nd \xAF 3rd \xAF \xDD\xAF [4th Step \xAF Slight Overview Data] \xAF 5th \xAF Confirm \xAF End]\t\t\t\t   \xBA");
    SetCursorCoord_XY(30, 6);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    SetCursorCoord_XY(30, 7);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
    SetCursorCoord_XY(30, 9);
    printf("\xC9\xCD\xCD \xDD INFORMATION SUMMARY \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
    SetCursorCoord_XY(30, 10);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    SetCursorCoord_XY(30, 11);
    printf("\xBA \xAF Here are the list of your subjects that you will be taking with.\t\t\t\t           \xBA");
    SetCursorCoord_XY(30, 12);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    while (Subject_Pass_Reader < Subject_ExpectedCandidates)
    {
        if ((ERLM_DataReceiver.Subject_CodeName_Receiver[Subject_Pass_Reader] == NULL) || (ERLM_DataReceiver.Subject_FullName_Receiver[Subject_Pass_Reader] == NULL) || (ERLM_DataReceiver.Subject_LinearTime_Receiver[Subject_Pass_Reader] == NULL))
        {
            Subject_Pass_Reader++;
            continue;
        }
        else
        {
            SetCursorCoord_XY(30, SetCoordinates_Dependent);
            if (Subject_Pass_Reader_Counter >= 10)
            {
                printf("\xBA  [ %d ]   %-10s -  %-51s \xDD %-18s\xDD     %-5i\xBA", Subject_Pass_Reader_Counter, ERLM_DataReceiver.Subject_CodeName_Receiver[Subject_Pass_Reader], ERLM_DataReceiver.Subject_FullName_Receiver[Subject_Pass_Reader], ERLM_DataReceiver.Subject_LinearTime_Receiver[Subject_Pass_Reader], ERLM_DataReceiver.Subject_Units_Receiver[Subject_Pass_Reader]);
                Subject_Pass_Reader++;
                Subject_Pass_Reader_Counter++;
                SetCoordinates_Dependent++;
            }
            else
            {
                printf("\xBA  [ %d ]    %-10s -  %-51s \xDD %-18s\xDD     %-5i\xBA", Subject_Pass_Reader_Counter, ERLM_DataReceiver.Subject_CodeName_Receiver[Subject_Pass_Reader], ERLM_DataReceiver.Subject_FullName_Receiver[Subject_Pass_Reader], ERLM_DataReceiver.Subject_LinearTime_Receiver[Subject_Pass_Reader], ERLM_DataReceiver.Subject_Units_Receiver[Subject_Pass_Reader]);
                Subject_Pass_Reader++;
                Subject_Pass_Reader_Counter++;
                SetCoordinates_Dependent++;
                continue;
            }
        }
    }
    SetCursorCoord_XY(30, SetCoordinates_Dependent);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    SetCoordinates_Dependent++;
    SetCursorCoord_XY(30, SetCoordinates_Dependent);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
    SetCoordinates_Dependent++;
    SetCoordinates_Dependent++;
    SetCursorCoord_XY(30, SetCoordinates_Dependent);
    printf("\xFE\xCD\xCD \xDD ADDITIONALS \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetCoordinates_Dependent++;
    SetCoordinates_Dependent++;
    SetCursorCoord_XY(30, SetCoordinates_Dependent);
    printf("\xDD Student Type \xAF %s\t\xDD\t Subjects Enrolled \xAF %d / %d => %-28s", StudentType, Subject_Pass_Reader_Counter - 1, Subject_ExpectedCandidates, StatusTake);
    SetCoordinates_Dependent++;
    SetCoordinates_Dependent++;
    SetCursorCoord_XY(30, SetCoordinates_Dependent);
    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetCoordinates_Dependent++;
    SetCoordinates_Dependent++;
    SetCursorCoord_XY(30, SetCoordinates_Dependent);
    printf("\xAF \xDD TAKE NOTE \xDD Here are the last information to be reviewed, press any key to continue.");
    getch();
    SetCoordinates_Dependent++;
    SetCoordinates_Dependent++;
    SetCursorCoord_XY(30, SetCoordinates_Dependent);
    printf("\xAF \xDD PROCESS \xDD Proceeding to Scholarship Prompt and Mode of Payment...");
    //Sleep(1750);
    Func_Stdnt_ScholarshipCheck();
}
int Func_Stdnt_ScholarshipCheck()
{
    char Confirmation;
    OnProcess_StudentData.GradeLowest = 0, OnProcess_StudentData.GradeHighest, OnProcess_StudentData.GradeGeneralAverage_LastSem = 0;
    //char *OnProcess_StudentData.Granted_ScholarshipStats[0], *Granted_ScholarshipStats;
    system("CLS");
    SetCursorCoord_XY(30, 3);
    printf("\xC9\xCD\xCD \xDD CURRENT PROGRESS \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
    SetCursorCoord_XY(30, 4);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    SetCursorCoord_XY(30, 5);
    printf("\xBA [1st \xAF 2nd \xAF 3rd \xAF 4th \xDD\xAF [5th Step of Part 1 \xAF Scholarship Prompt] \xAF Confirm \xAF End]\t\t\t   \xBA");
    SetCursorCoord_XY(30, 6);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    SetCursorCoord_XY(30, 7);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
    SetCursorCoord_XY(30, 9);
    printf("\xC9\xCD\xCD \xDD INFORMATION \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
    SetCursorCoord_XY(30, 10);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    SetCursorCoord_XY(30, 11);
    printf("\xBA To get a scholarship discount, your grades must met the following\t\t\t\t\t   \xBA");
    SetCursorCoord_XY(30, 12);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    SetCursorCoord_XY(30, 13);
    printf("\xBA \xAF 84.00%% - 85.99%% General Avg with Subject Minimum Grade of 82%% \t\t\t\t\t   \xBA");
    SetCursorCoord_XY(30, 14);
    printf("\xBA \xAF 86.00%% - 87.99%% General Avg with Subject Minimum Grade of 84%% \t\t\t\t\t   \xBA");
    SetCursorCoord_XY(30, 15);
    printf("\xBA \xAF 88.00%% - 88.99%% General Avg with Subject Minimum Grade of 86%% \t\t\t\t\t   \xBA");
    SetCursorCoord_XY(30, 16);
    printf("\xBA \xAF 89.00%% - 89.99%% General Avg with Subject Minimum Grade of 88%% \t\t\t\t\t   \xBA");
    SetCursorCoord_XY(30, 17);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    SetCursorCoord_XY(30, 18);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
    SetCursorCoord_XY(30, 20);
    printf("\xFE\xCD\xCD \xDD QUESTIONS \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetCursorCoord_XY(30, 22);
    printf("\xAF \xDD QUESTION #1 \xDD What is your general average grade from your last semester?");
    SetCursorCoord_XY(30, 23);
    printf("[No Decimal Places, Round Off when the first decimal is only .9] \xAF ");
    scanf("%d", &OnProcess_StudentData.GradeGeneralAverage_LastSem);
    fflush(stdin);
    SetCursorCoord_XY(30, 25);
    printf("\xAF \xDD QUESTION #2 \xDD What is your lowest grade on any subject?");
    SetCursorCoord_XY(30, 26);
    printf("[No Decimal Places, Round Off when the first decimal is only .9] \xAF ");
    scanf("%d", &OnProcess_StudentData.GradeLowest);
    fflush(stdin);
    SetCursorCoord_XY(30, 28);
    printf("\xAF \xDD QUESTION #3 \xDD What is your highest grade on any subject?");
    SetCursorCoord_XY(30, 29);
    printf("[No Decimal Places, Round Off when the first decimal is only .9] \xAF ");
    scanf("%d", &OnProcess_StudentData.GradeHighest);
    fflush(stdin);
    if (OnProcess_StudentData.GradeLowest >= 82 && OnProcess_StudentData.GradeGeneralAverage_LastSem >= 84)
    {
        SetCursorCoord_XY(30, 31);
        printf("\xAF \xDD INFO \xDD Congratulations! You are eligible for scholarship!");
        //Sleep(1500);
        if ((OnProcess_StudentData.GradeLowest >= 82) && (OnProcess_StudentData.GradeGeneralAverage_LastSem >= 84 && OnProcess_StudentData.GradeGeneralAverage_LastSem <= 86))
        {
            strcpy(OnProcess_StudentData.Granted_ScholarshipStats, "50%% Discount");
            strcpy(OnProcess_StudentData.Granted_ScholarshipDetails, "50%% Discount on Tuition Fee for one (1) semester | Entrance Scholarship");
            SetCursorCoord_XY(30, 32);
            printf("\xAF \xDD ELIGIBILITY \xDD You are eligible for %s", OnProcess_StudentData.Granted_ScholarshipDetails);
        }
        else if ((OnProcess_StudentData.GradeLowest >= 84) && (OnProcess_StudentData.GradeGeneralAverage_LastSem >= 86 && OnProcess_StudentData.GradeGeneralAverage_LastSem <= 88))
        {
            SetCursorCoord_XY(30, 32);
            strcpy(OnProcess_StudentData.Granted_ScholarshipStats, "75%% Discount");
            strcpy(OnProcess_StudentData.Granted_ScholarshipDetails, "75%% Discount on Tuition Fee for one (1) semester | Entrance Scholarship");
            printf("\xA7 \xDD ELIGIBILITY \xDD You are eligible for %s", OnProcess_StudentData.Granted_ScholarshipDetails);
        }
        else if ((OnProcess_StudentData.GradeLowest >= 86) && (OnProcess_StudentData.GradeGeneralAverage_LastSem >= 88 && OnProcess_StudentData.GradeGeneralAverage_LastSem <= 89))
        {
            SetCursorCoord_XY(30, 32);
            strcpy(OnProcess_StudentData.Granted_ScholarshipStats, "100%% Discount");
            strcpy(OnProcess_StudentData.Granted_ScholarshipDetails, "Free tuition fee for one (1) semester | Entrance Scholarship");
            printf("\xAF \xDD ELIGIBILITY \xDD You are eligible for %s", OnProcess_StudentData.Granted_ScholarshipDetails);
        }
        else if ((OnProcess_StudentData.GradeLowest >= 88) && (OnProcess_StudentData.GradeGeneralAverage_LastSem >= 89))
        {
            SetCursorCoord_XY(30, 32);
            strcpy(OnProcess_StudentData.Granted_ScholarshipStats, "100%% + MISC.");
            strcpy(OnProcess_StudentData.Granted_ScholarshipDetails, "Free tuition and basic miscellaneous fees for one (1) semester | Entrance Scholarship");
            printf("\xAF \xDD ELIGIBILITY \xDD You are eligible for %s", OnProcess_StudentData.Granted_ScholarshipDetails);
        }
    }
    else
    {
        SetCursorCoord_XY(30, 32);
        printf("\xDD INFO \xAF Sorry, you are not allowed to take scholarship... But your encoded grade is still recorded...");
        SetCursorCoord_XY(30, 34);
        printf("\xDD INFO \xAF Proceeding to Mode of Payment...");
        //Sleep(1750);
        Func_Mode_Of_Payment();
    }
    //Sleep(1000);
    while (1)
    {
        SetCursorCoord_XY(30, 34);
        printf("\xAF \xDD FINAL QUESTION \xDD Do you want to apply for a scholarship? [Y or N] \xAF ");
        switch (Confirmation = getche())
        {
        case 'Y':
        case 'y': //Falls Through
            SetCursorCoord_XY(30, 35);
            printf("\xDD INFO \xAF Data Acquired. Good to know :). Proceeding to Mode of Payment...");
            //Sleep(1500);
            //Func_Stdnt_ScholarshipCheck();
            Func_Mode_Of_Payment();
        case 'N':
        case 'n': // Falls Through
            SetCursorCoord_XY(30, 35);
            printf("\xDD INFO \xAF Scholarship Grant Aborted :(. Proceeding to Mode of Payment...");
            strcpy(OnProcess_StudentData.Granted_ScholarshipStats, "NULL");
            //Sleep(1500);
            Func_Mode_Of_Payment();
            break;
        default:
            SetCursorCoord_XY(30, 35);
            printf("\xDD ERROR \xAF Sorry, I don't understand that...");
            //Sleep(1500);
            continue;
        }
    }
}

void Func_Mode_Of_Payment()
{
    while (1)
    {
        char Selection;
        system("CLS");
        SetCursorCoord_XY(30, 3);
        printf("\xC9\xCD\xCD \xDD CURRENT PROGRESS \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        SetCursorCoord_XY(30, 4);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, 5);
        printf("\xBA [1st \xAF 2nd \xAF 3rd \xAF 4th \xAF \xDD\xAF [5th Step of Part 2 \xAF Mode of Payment] \xAF Confirm \xAF End]\t\t\t   \xBA");
        SetCursorCoord_XY(30, 6);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, 7);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        SetCursorCoord_XY(30, 9);
        printf("\xC9\xCD\xCD \xDD SELECTIONS \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        SetCursorCoord_XY(30, 10);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, 11);
        printf("\xBA \xAF [1] Cash \t\t\t\t\t\t\t\t\t\t\t\t   \xBA");
        SetCursorCoord_XY(30, 12);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, 13);
        printf("\xBA \xAF [2] Installment \t\t\t\t\t\t\t\t\t\t\t   \xBA");
        SetCursorCoord_XY(30, 14);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, 15);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        SetCursorCoord_XY(30, 17);
        printf("\xC8\xAF \xDD INFO \xDD Press a key that corresponds your decision \xAF ");
        switch (Selection = getche())
        {
        case '1':
            strcpy(OnProcess_StudentData.PaymentMethod, "Cash");
            SetCursorCoord_XY(30, 19);
            printf("\xAF \xDD SUCCESS \xAF Selected %s as a Mode of Payment. Proceeding to Final Overview...", OnProcess_StudentData.PaymentMethod);
            //Sleep(1750);
            Func_PrintDocument_FinalTranscript();
        case '2':
            strcpy(OnProcess_StudentData.PaymentMethod, "Installment");
            SetCursorCoord_XY(30, 19);
            printf("\xAF \xDD SUCCESS \xAF Selected %s as a Mode of Payment. Proceeding to Final Overview...", OnProcess_StudentData.PaymentMethod);
            //Sleep(1750);
            Func_PrintDocument_FinalTranscript();
        default:
            SetCursorCoord_XY(30, 19);
            printf("\xAF \xDD ERROR \xAF Sorry, I don't understand that...");
            //Sleep(1750);
            continue;
        }
    }
}
void Func_PrintDocument_FinalTranscript()
{
    //Create an Student ID for New People
    long long int stdnt_NumGenerated;
    int SetCoordinates_Dependent = 20, SubjectCount = 0, SubjectNumber = 1, TotalCreditUnits = 0, Reprint_SubjectCount = 0, Reprint_SubjectNumber = 1;
    float TuitionFee, LaboratoryFee = 7225.85, AthleticsFee = 761.20,
                      AudioVisualFee = 133.60, ClassroomEnergyFee = 1100, ComputerFee = 2650.75,
                      CulturalnActivityFee = 48.30, DevFee = 830.45, EnergExtFee = 890.63,
                      GuidancenCounselFee = 520.17, HandbookFee = 153.35, IDFee = 487.10,
                      InsuranceFee = 12.00, InternetFee = 105.30, LibraryFee = 1520.35,
                      MedicalFee = 510.20, RedCrossFee = 1, StudentCouncilFee = 60,
                      TestPaperFee = 266, ScholarshipDiscount = 0, TotalFee = 0;
    SYSTEMTIME GetTimePrinted;
    GetLocalTime(&GetTimePrinted);
    FILE *FileCreation_StudentCopy;
    GenerateUserPass_withGenerateFileName();
    FileCreation_StudentCopy = fopen(OnProcess_StudentData.FileName_Coordinate, "w+");

    if (OldDataProcess_StudentData.stdnt_StudentID == 0)
    {
        //Create Algorithm here
        stdnt_NumGenerated = 2018000;
    }
    else
    {
        stdnt_NumGenerated = OldDataProcess_StudentData.stdnt_StudentID;
    }
    system("CLS");
    SetCursorCoord_XY(20, 3);
    printf("\xC9\xCD\xCD \xDD CURRENT PROGRESS \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
    SetCursorCoord_XY(20, 4);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
    SetCursorCoord_XY(20, 5);
    printf("\xBA [1st \xAF 2nd \xAF 3rd \xAF 3rd \xAF 4th \xAF 5th \xAF \xDD\xAF [Confirm - Overall Overview] \xAF End]\t\t\t\t\t\t       \xBA");
    SetCursorCoord_XY(20, 6);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
    SetCursorCoord_XY(20, 7);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
    SetCursorCoord_XY(20, 9);
    printf("\xFE\xCD\xCD \xDD STUDENTS REGISTRATION FORM - STUDENTS COPY \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetCursorCoord_XY(20, 11);
    printf(" \xDD %-18s \xAF %-50ld \xDD %-10s \xAF %-10s", "Student Number", stdnt_NumGenerated, "Program", OnProcess_StudentData.MainCourse_CodeName_Passer, OnProcess_StudentData.MainCourse_CodeName_Passer);
    SetCursorCoord_XY(20, 12);
    printf(" \xDD %-18s \xAF %-s, %s %-30s \xDD%-10s \xAF %-20s ", "Name of Student", OnProcess_StudentData.stdnt_LName, OnProcess_StudentData.stdnt_FName, OnProcess_StudentData.stdnt_MName, "Year Level", OnProcess_StudentData.Course_YearChoice);
    SetCursorCoord_XY(20, 13);
    printf(" \xDD %-18s \xAF %-50s", "Permanent Address", OnProcess_StudentData.stdnt_Address);
    SetCursorCoord_XY(20, 14);
    printf(" \xDD %-18s \xAF %-50s", "Student Type", OnProcess_StudentData.stdnt_StudentType);
    SetCursorCoord_XY(20, 16);
    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetCursorCoord_XY(20, 18);
    printf("\xFE\xCD\xCD \xDD SUBJECT INFORMATION \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SubjectCount = 0;
    SubjectNumber = 1;
    while (SubjectCount < ERLM_DataReceiver.Subject_Candidates)
    {
        if ((ERLM_DataReceiver.Subject_CodeName_Receiver[SubjectCount] == NULL) || (ERLM_DataReceiver.Subject_FullName_Receiver[SubjectCount] == NULL) || (ERLM_DataReceiver.Subject_LinearTime_Receiver[SubjectCount] == NULL))
        {
            SubjectCount++;
            continue;
        }
        else
        {

            SetCursorCoord_XY(20, SetCoordinates_Dependent);
            if (SubjectNumber >= 10)
            {
                printf("      [ %d ]  \xDD    %-10s -  %-46s \xDD  %-8s\xDD  %-19s\xDD%5i", SubjectNumber, ERLM_DataReceiver.Subject_CodeName_Receiver[SubjectCount], ERLM_DataReceiver.Subject_FullName_Receiver[SubjectCount], ERLM_DataReceiver.Subject_ScheduleDay_Receiver[SubjectCount], ERLM_DataReceiver.Subject_LinearTime_Receiver[SubjectCount], ERLM_DataReceiver.Subject_Units_Receiver[SubjectCount]);
                TotalCreditUnits += ERLM_DataReceiver.Subject_Units_Receiver[SubjectCount];
                SetCoordinates_Dependent++;
                SubjectCount++;
                SubjectNumber++;
            }
            else
            {
                printf("      [ %d ]   \xDD    %-10s -  %-46s \xDD  %-8s\xDD  %-19s\xDD%5i", SubjectNumber, ERLM_DataReceiver.Subject_CodeName_Receiver[SubjectCount], ERLM_DataReceiver.Subject_FullName_Receiver[SubjectCount], ERLM_DataReceiver.Subject_ScheduleDay_Receiver[SubjectCount], ERLM_DataReceiver.Subject_LinearTime_Receiver[SubjectCount], ERLM_DataReceiver.Subject_Units_Receiver[SubjectCount]);
                TotalCreditUnits += ERLM_DataReceiver.Subject_Units_Receiver[SubjectCount];
                SetCoordinates_Dependent++;
                SubjectCount++;
                SubjectNumber++;
            }
        }
    }

    TuitionFee = SubjectCount * 200 + 21500;
    if (strcmp(OnProcess_StudentData.Granted_ScholarshipStats, "50%% Discount") == 0)
    {
        ScholarshipDiscount = TuitionFee * 0.5;
    }
    else if (strcmp(OnProcess_StudentData.Granted_ScholarshipStats, "75%% Discount") == 0)
    {
        ScholarshipDiscount = TuitionFee * 0.75;
    }
    else if (strcmp(OnProcess_StudentData.Granted_ScholarshipStats, "100%% Discount") == 0)
    {
        TuitionFee = 0;
        ScholarshipDiscount = TuitionFee * 0.100;
    }
    else if (strcmp(OnProcess_StudentData.Granted_ScholarshipStats, "100%% + MISC.") == 0)
    {
        TuitionFee = 0;
        ScholarshipDiscount = 0;
        LaboratoryFee = 0;
        AthleticsFee = 0;
        AudioVisualFee = 0;
        ClassroomEnergyFee = 0;
        ComputerFee = 0;
        CulturalnActivityFee = 0;
        DevFee = 0;
        EnergExtFee = 0;
        GuidancenCounselFee = 0;
        HandbookFee = 0;
        IDFee = 0;
        InsuranceFee = 0;
        InternetFee = 0;
        LibraryFee = 0;
        MedicalFee = 0;
        RedCrossFee = 0;
        StudentCouncilFee = 0;
        TestPaperFee = 0;
    }
    else
    {
        ScholarshipDiscount = 0;
    }
    TotalFee = (TuitionFee + LaboratoryFee + AthleticsFee +
                AudioVisualFee + ClassroomEnergyFee + ComputerFee +
                CulturalnActivityFee + DevFee + EnergExtFee +
                GuidancenCounselFee + HandbookFee + IDFee +
                InsuranceFee + InternetFee + LibraryFee +
                MedicalFee + RedCrossFee + StudentCouncilFee +
                TestPaperFee) -
               ScholarshipDiscount;
    SetCoordinates_Dependent++;
    SetCursorCoord_XY(20, SetCoordinates_Dependent);
    printf("      Total Subjects To Take \xAF %d / %- 20d\xAF Total Credit Units To Take \xAF %d", ERLM_DataReceiver.Subjects_Selected, ERLM_DataReceiver.Subject_Candidates, TotalCreditUnits);
    SetCoordinates_Dependent++;
    SetCoordinates_Dependent++;
    SetCursorCoord_XY(20, SetCoordinates_Dependent);
    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetCoordinates_Dependent++;
    SetCoordinates_Dependent++;
    SetCursorCoord_XY(20, SetCoordinates_Dependent);
    printf("\xFE\xCD\xCD \xDD FEES AND IT'S AMOUNTS \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetCoordinates_Dependent++;
    SetCoordinates_Dependent++;
    SetCursorCoord_XY(20, SetCoordinates_Dependent);
    printf("  %-20s \xAF %-20.2f \xDD %-20s \xAF %-20.2f \xDD %-20s \xAF %-20.2f", "TUITION FEE", TuitionFee, "Laboratory Fee", LaboratoryFee, "Athletics Fee", AthleticsFee);
    SetCoordinates_Dependent++;
    SetCursorCoord_XY(20, SetCoordinates_Dependent);
    printf("  %-20s \xAF %-20.2f \xDD %-20s \xAF %-20.2f \xDD %-20s \xAF %-20.2f", "Audio Visual Fee", AudioVisualFee, "Classroom Energy Fee", ClassroomEnergyFee, "Computer Fee", ComputerFee);
    SetCoordinates_Dependent++;
    SetCursorCoord_XY(20, SetCoordinates_Dependent);
    printf("  %-20s \xAF %-20.2f \xDD %-20s \xAF %-20.2f \xDD %-20s \xAF %-20.2f", "Cultural & Act. Fee", CulturalnActivityFee, "Development Fee", DevFee, "Energy Fee", EnergExtFee);
    SetCoordinates_Dependent++;
    SetCursorCoord_XY(20, SetCoordinates_Dependent);
    printf("  %-20s \xAF %-14.2f \xDD %-20s \xAF %-20.2f \xDD %-20s \xAF %-20.2f", "Guidance & Counselling Fee", GuidancenCounselFee, "Handbook Fee", HandbookFee, "ID Fee", IDFee);
    SetCoordinates_Dependent++;
    SetCursorCoord_XY(20, SetCoordinates_Dependent);
    printf("  %-20s \xAF %-20.2f \xDD %-20s \xAF %-20.2f \xDD %-20s \xAF %-20.2f", "Insurance Fee", InsuranceFee, "Internet Fee", InternetFee, "Library Fee", LibraryFee);
    SetCoordinates_Dependent++;
    SetCursorCoord_XY(20, SetCoordinates_Dependent);
    printf("  %-20s \xAF %-20.2f \xDD %-20s \xAF %-20.2f \xDD %-20s \xAF %-20.2f", "Medical Fee", MedicalFee, "Red Cross Fee", RedCrossFee, "Student Council Fee", StudentCouncilFee);
    SetCoordinates_Dependent++;
    SetCursorCoord_XY(20, SetCoordinates_Dependent);
    printf("  %-20s \xAF %-20.2f \xDD %-19s \xAF -%-19.2f\xDD %-20s \xAF %-20.2f", "Test Paper Fee", TestPaperFee, "Scholarship Reduction", ScholarshipDiscount, "TOTAL FEE", TotalFee);
    SetCoordinates_Dependent++;
    SetCoordinates_Dependent++;
    SetCursorCoord_XY(20, SetCoordinates_Dependent);
    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetCoordinates_Dependent++;
    SetCoordinates_Dependent++;
    SetCursorCoord_XY(20, SetCoordinates_Dependent);
    printf("\xFE\xCD\xCD \xDD SCHOLARSHIP, SCHEDULE OF PAYMENT AND STUDENT PORTAL INFO \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetCoordinates_Dependent++;
    SetCoordinates_Dependent++;
    SetCursorCoord_XY(20, SetCoordinates_Dependent);
    printf("\xDD Scholarship Taken \xAF %s", OnProcess_StudentData.Granted_ScholarshipDetails);
    SetCoordinates_Dependent++;
    SetCursorCoord_XY(20, SetCoordinates_Dependent);
    printf("\xDD Payment Selected \xAF %s", OnProcess_StudentData.PaymentMethod);
    SetCoordinates_Dependent++;
    SetCursorCoord_XY(20, SetCoordinates_Dependent);
    printf("\xDD Student Portal Account");
    SetCoordinates_Dependent++;
    SetCursorCoord_XY(20, SetCoordinates_Dependent);
    printf("\xDD \xAF User ID \xAF %s", OnProcess_StudentData.Generated_stdnt_NewUser);
    SetCoordinates_Dependent++;
    SetCursorCoord_XY(20, SetCoordinates_Dependent);
    printf("\xDD \xAF Temporary Password \xAF %s", OnProcess_StudentData.Generated_stdnt_NewPass);
    SetCoordinates_Dependent++;
    SetCursorCoord_XY(20, SetCoordinates_Dependent);
    printf("\xDD You can access it after this enrollment!");
    SetCoordinates_Dependent++;
    SetCoordinates_Dependent++;
    SetCursorCoord_XY(20, SetCoordinates_Dependent);
    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetCoordinates_Dependent++;
    SetCoordinates_Dependent++;
    SetCursorCoord_XY(20, SetCoordinates_Dependent);
    printf("\xAF \xDD INFO \xDD Here's the full overview of your registration form containing everything you need to enroll...");
    //Sleep(5000);
    SetCoordinates_Dependent++;
    SetCursorCoord_XY(20, SetCoordinates_Dependent);
    SetCoordinates_Dependent++;
    SetCursorCoord_XY(20, SetCoordinates_Dependent);
    printf("\xAF \xDD WARNING \xDD THIS IS NOT the design for the final printed registration form...");
    SetCoordinates_Dependent++;
    SetCursorCoord_XY(20, SetCoordinates_Dependent);
    printf("\xAF \xDD CONFIMRATION \xDD If you are done viewing this, press any key to continue...");
    getch();

    system("CLS");
    SetCursorCoord_XY(30, 3);
    printf("\xC9\xCD\xCD \xDD CURRENT PROGRESS \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
    SetCursorCoord_XY(30, 4);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    SetCursorCoord_XY(30, 5);
    printf("\xBA [1st \xAF 2nd \xAF 3rd \xAF 4th \xAF 5th \xAF Confirm \xAF \xDD\xAF [End \xAF Processing of Files]\t\t\t\t\t   \xBA");
    SetCursorCoord_XY(30, 6);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    SetCursorCoord_XY(30, 7);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");

    SetCursorCoord_XY(30, 9);
    printf("\xFE\xCD\xCD \xDD PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetCursorCoord_XY(30, 11);
    printf("\xAF \xDD PROCESS FILE #1 \xDD Saving Data for Enrollee's Completed Registration Form...");
    //Progress File to Enrollee Registration Form
    setbuf(FileCreation_StudentCopy, NULL);
    fprintf(FileCreation_StudentCopy, "■══  STUDENTS REGISTRATION FORM - STUDENTS COPY ▌ ══════════════════════■\n\n");
    fprintf(FileCreation_StudentCopy, "▌ %-10s » %-10ld ▌ %-10s » %-5s\n", "Student Number", stdnt_NumGenerated, "Program", OnProcess_StudentData.MainCourse_CodeName_Passer, OnProcess_StudentData.MainCourse_CodeName_Passer);
    fprintf(FileCreation_StudentCopy, "▌ %-10s » %-s, %s %-50s ▌ %-10s » %-5s \n", "Name of Student", OnProcess_StudentData.stdnt_LName, OnProcess_StudentData.stdnt_FName, OnProcess_StudentData.stdnt_MName, "Year Level", OnProcess_StudentData.Course_YearChoice);
    fprintf(FileCreation_StudentCopy, "▌ %-10s » %-15s\n", "Permanent Address", OnProcess_StudentData.stdnt_Address);
    fprintf(FileCreation_StudentCopy, "▌ %-10s » %-15s\n\n", "Student Type", OnProcess_StudentData.stdnt_StudentType);
    fprintf(FileCreation_StudentCopy, "■══ ▌ SUBJECT INFORMATION ▌ ════════════════════════════════════════════■\n\n");
    SubjectCount = 0;
    SubjectNumber = 1;
    while (SubjectCount < ERLM_DataReceiver.Subject_Candidates)
    {
        if ((ERLM_DataReceiver.Subject_CodeName_Receiver[SubjectCount] == NULL) || (ERLM_DataReceiver.Subject_FullName_Receiver[SubjectCount] == NULL) || (ERLM_DataReceiver.Subject_LinearTime_Receiver[SubjectCount] == NULL))
        {
            SubjectCount++;
            continue;
        }
        else
        {
            if (SubjectNumber >= 10)
            {
                fprintf(FileCreation_StudentCopy, "%d ▌ %s - %s ▌ %s ▌ %s ▌ %i\n", SubjectNumber, ERLM_DataReceiver.Subject_CodeName_Receiver[SubjectCount], ERLM_DataReceiver.Subject_FullName_Receiver[SubjectCount], ERLM_DataReceiver.Subject_ScheduleDay_Receiver[SubjectCount], ERLM_DataReceiver.Subject_LinearTime_Receiver[SubjectCount], ERLM_DataReceiver.Subject_Units_Receiver[SubjectCount]);
                SetCoordinates_Dependent++;
                SubjectCount++;
                SubjectNumber++;
            }
            else
            {
                fprintf(FileCreation_StudentCopy, "%d ▌ %s - %s ▌ %s ▌ %s ▌ %i\n", SubjectNumber, ERLM_DataReceiver.Subject_CodeName_Receiver[SubjectCount], ERLM_DataReceiver.Subject_FullName_Receiver[SubjectCount], ERLM_DataReceiver.Subject_ScheduleDay_Receiver[SubjectCount], ERLM_DataReceiver.Subject_LinearTime_Receiver[SubjectCount], ERLM_DataReceiver.Subject_Units_Receiver[SubjectCount]);
                SetCoordinates_Dependent++;
                SubjectCount++;
                SubjectNumber++;
            }
        }
    }
    fprintf(FileCreation_StudentCopy, "\nTotal Subjects To Take » %d / %d, Total Credit Units To Take » %d\n\n", ERLM_DataReceiver.Subjects_Selected, ERLM_DataReceiver.Subject_Candidates, TotalCreditUnits);
    fprintf(FileCreation_StudentCopy, "■══ ▌ FEES AND IT'S AMOUNTS ▌ ══════════════════════════════════════════■\n\n");
    fprintf(FileCreation_StudentCopy, " %s » %.2f | %s » %.2f \n %s » %.2f ", "TUITION FEE", TuitionFee, "Laboratory Fee", LaboratoryFee, "Athletics Fee", AthleticsFee);
    fprintf(FileCreation_StudentCopy, " | %s » %.2f\n %s » %.2f | %s » %.2f \n", "Audio Visual Fee", AudioVisualFee, "Classroom Energy Fee", ClassroomEnergyFee, "Computer Fee", ComputerFee);
    fprintf(FileCreation_StudentCopy, " %s » %.2f | %s » %.2f \n %s » %.2f ", "Cultural & Act. Fee", CulturalnActivityFee, "Development Fee", DevFee, "Energy Fee", EnergExtFee);
    fprintf(FileCreation_StudentCopy, " | %s » %.2f\n %s » %.2f | %s » %.2f \n", "Guidance & Counselling Fee", GuidancenCounselFee, "Handbook Fee", HandbookFee, "ID Fee", IDFee);
    fprintf(FileCreation_StudentCopy, " %s » %.2f | %s » %.2f \n %s » %.2f ", "Insurance Fee", InsuranceFee, "Internet Fee", InternetFee, "Library Fee", LibraryFee);
    fprintf(FileCreation_StudentCopy, " | %s » %.2f\n %s » %.2f | %s » %.2f \n", "Medical Fee", MedicalFee, "Red Cross Fee", RedCrossFee, "Student Council Fee", StudentCouncilFee);
    fprintf(FileCreation_StudentCopy, " %s » %.2f | %s » -%.2f \n%s » %.2f \n\n", "Test Paper Fee", TestPaperFee, "Scholarship Reduction", ScholarshipDiscount, "TOTAL FEE", TotalFee);
    fprintf(FileCreation_StudentCopy, "■══ ▌ SCHOLARSHIP, SCHEDULE OF PAYMENT AND STUDENT PORTAL INFO ▌ ═══════■\n\n");
    fprintf(FileCreation_StudentCopy, "▌ Scholarship Taken » %s\n\n", OnProcess_StudentData.Granted_ScholarshipDetails);
    fprintf(FileCreation_StudentCopy, "▌ Payment Selected » %s\n\n", OnProcess_StudentData.PaymentMethod);
    fprintf(FileCreation_StudentCopy, "▌ Student Portal Account\n");
    fprintf(FileCreation_StudentCopy, "▌ » User ID » %s\n", OnProcess_StudentData.Generated_stdnt_NewUser);
    fprintf(FileCreation_StudentCopy, "▌ » Temporary Password » %s\n", OnProcess_StudentData.Generated_stdnt_NewPass);
    fprintf(FileCreation_StudentCopy, "▌ » Printed on %02d/%02d/%d\n\n", GetTimePrinted.wMonth, GetTimePrinted.wDay, GetTimePrinted.wYear);
    fprintf(FileCreation_StudentCopy, "■═══════════════════════════════════════════════════════════════════════■");
    fclose(FileCreation_StudentCopy);
    GetDataEnrolleeInformation();
    SetCursorCoord_XY(30, 12);
    printf("\xAF \xDD SAVED \xAF FILENAME %s\n", OnProcess_StudentData.FileName_Coordinate);
    SetCursorCoord_XY(30, 14);
    printf("\xAF \xDD PROCESS FILE #2 \xDD Saving Data for Enrollee's Information...");
    SetCursorCoord_XY(30, 16);
    printf("\xAF \xDD SAVED \xAF FILENAME %s\n", OnProcess_StudentData.FileName_Coordinate);
    SetCursorCoord_XY(30, 18);
    printf("\xAF \xDD ENROLLMENT SUCCESS \xAF You are all set! Please get assistance for printing of your registration form!");
    SetCursorCoord_XY(30, 20);
    printf("Thank you for enrolling!");
    SetCursorCoord_XY(30, 22);
    printf("Returning to Main Menu in 10 Seconds...");
    Sleep(10000);
    Main_Menu();
}

void GetDataEnrolleeInformation()
{
    FILE *FileCreation_StudentInformation;
    FileCreation_StudentInformation = fopen("test.rtf", "w+");
    fprintf(FileCreation_StudentInformation, "Student Information of %s, %s %s\n", OnProcess_StudentData.stdnt_LName, OnProcess_StudentData.stdnt_MName, OnProcess_StudentData.stdnt_FName);
    fprintf(FileCreation_StudentInformation, "Enrollee's Name » %s, %s %s\n", OnProcess_StudentData.stdnt_LName, OnProcess_StudentData.stdnt_MName, OnProcess_StudentData.stdnt_FName);
    fprintf(FileCreation_StudentInformation, "Enrollee's Name of Father » %s\n", OnProcess_StudentData.stdnt_FathersName);
    fprintf(FileCreation_StudentInformation, "Enrollee's Current Occupation of Father » %s\n", OnProcess_StudentData.stdnt_FathersInfoJob);
    fprintf(FileCreation_StudentInformation, "Enrollee's Contact Number of Father » %s", OnProcess_StudentData.stdnt_FathersInfoContact);
    fprintf(FileCreation_StudentInformation, "Enrollee's Name of Mother » %s", OnProcess_StudentData.stdnt_MothersName);
    fprintf(FileCreation_StudentInformation, "Enrollee's Current Occupation of Mother » %s\n", OnProcess_StudentData.stdnt_MothersInfoJob);
    fprintf(FileCreation_StudentInformation, "Enrollee's Contact Number of Mother » %s\n", OnProcess_StudentData.stdnt_MothersInfoContact);
    fprintf(FileCreation_StudentInformation, "Enrollee's Gender » %s\n", OnProcess_StudentData.stdnt_Gender);
    fprintf(FileCreation_StudentInformation, "Enrollee's Birthday » %s\n", OnProcess_StudentData.stdnt_Birthday);
    fprintf(FileCreation_StudentInformation, "Enrollee's Address » %s\n", OnProcess_StudentData.stdnt_Address);
    fprintf(FileCreation_StudentInformation, "Enrollee's Nationality » %s\n", OnProcess_StudentData.stdnt_Nationality);
    fprintf(FileCreation_StudentInformation, "Enrollee's Mobile Number » %s\n", OnProcess_StudentData.stdnt_MobileNum);
    fprintf(FileCreation_StudentInformation, "Enrollee's Telephone Number » %s\n", OnProcess_StudentData.stdnt_PhoneNum);
    fprintf(FileCreation_StudentInformation, "Enrollee's Emergency Number » %s\n", OnProcess_StudentData.stdnt_EmerNum);
    fprintf(FileCreation_StudentInformation, "Enrollee's Emergency Point of Contact » %s\n", OnProcess_StudentData.stdnt_POC_Emergency);
    fprintf(FileCreation_StudentInformation, "Enrollee's Source of Interest » %s\n", OnProcess_StudentData.stdnt_SourceInterest);
    fprintf(FileCreation_StudentInformation, "Enrollee's Last School Year Attended » %s\n", OnProcess_StudentData.stdnt_LastSchoolYear);
    fprintf(FileCreation_StudentInformation, "Enrollee's Senior High, Strand Taken » %s\n", OnProcess_StudentData.stdnt_LastSchoolStrand);
    fprintf(FileCreation_StudentInformation, "Enrollee's Personal Email » %s\n", OnProcess_StudentData.stdnt_Email);
    fprintf(FileCreation_StudentInformation, "Enrollee's Behavioral Issue » %s\n", OnProcess_StudentData.stdnt_SpecialBehavioral);
    fprintf(FileCreation_StudentInformation, "...End of Line...");
    fclose(FileCreation_StudentInformation);
}
void Func_ERLM_Check()
{
}

// Uncategoterized Function
void SetCursorCoord_XY(int x, int y)
{
    COORD ConsoleXY = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ConsoleXY);
}

void GenerateUserPass_withGenerateFileName()
{
    SYSTEMTIME PasswordBaseDate;
    char *BaseBranch = "qc_";
    char *PasswordSeperate = "_";
    char *FileNameSeperate = "-";
    // Code for Generating UserName
    char UserGenerate_Container[50],
        PasswordGenerate_Container[100],
        FileName_Container[MAX_PATH],
        PasswordGenerate_Year[10],
        PasswordGenerate_Hour[10],
        PasswordGenerate_Second[10];

    strncat(UserGenerate_Container, BaseBranch, sizeof(BaseBranch));
    strncat(UserGenerate_Container, OnProcess_StudentData.stdnt_FName, 1);
    strncat(UserGenerate_Container, OnProcess_StudentData.stdnt_LName, sizeof(OnProcess_StudentData.stdnt_LName));

    strncpy(OnProcess_StudentData.Generated_stdnt_NewUser, UserGenerate_Container, sizeof(OnProcess_StudentData.Generated_stdnt_NewUser));

    GetLocalTime(&PasswordBaseDate);

    sprintf(PasswordGenerate_Year, "%d", PasswordBaseDate.wYear);
    sprintf(PasswordGenerate_Hour, "%02d", PasswordBaseDate.wHour);
    sprintf(PasswordGenerate_Second, "%02d", PasswordBaseDate.wSecond);

    strncat(PasswordGenerate_Container, PasswordGenerate_Year, sizeof(PasswordGenerate_Year));
    strncat(PasswordGenerate_Container, PasswordGenerate_Hour, sizeof(PasswordGenerate_Hour));
    strncat(PasswordGenerate_Container, PasswordGenerate_Second, sizeof(PasswordGenerate_Second));
    strncat(PasswordGenerate_Container, PasswordSeperate, 1);
    strncat(PasswordGenerate_Container, OnProcess_StudentData.stdnt_MName, sizeof(OnProcess_StudentData.stdnt_MName));
    strncat(PasswordGenerate_Container, OnProcess_StudentData.stdnt_FName, 1);
    strncat(PasswordGenerate_Container, OnProcess_StudentData.stdnt_LName, 1);

    strncpy(OnProcess_StudentData.Generated_stdnt_NewPass, PasswordGenerate_Container, sizeof(OnProcess_StudentData.Generated_stdnt_NewPass));

    strncat(FileName_Container, PasswordGenerate_Year, sizeof(PasswordGenerate_Year));
    strncat(FileName_Container, PasswordGenerate_Hour, sizeof(PasswordGenerate_Hour));
    strncat(FileName_Container, PasswordGenerate_Second, sizeof(PasswordGenerate_Second));
    strncat(FileName_Container, FileNameSeperate, sizeof(FileNameSeperate));
    strncat(FileName_Container, OnProcess_StudentData.stdnt_FName, sizeof(OnProcess_StudentData.stdnt_FName));
    strncat(FileName_Container, OnProcess_StudentData.stdnt_LName, sizeof(OnProcess_StudentData.stdnt_LName));
    strncat(FileName_Container, "RegistrationForm.rtf", sizeof("RegistrationForm.rtf"));

    strncpy(OnProcess_StudentData.FileName_Coordinate, FileName_Container, sizeof(OnProcess_StudentData.FileName_Coordinate));

    //printf("%d | %d | %d \n", PasswordBaseDate.wYear, PasswordBaseDate.wHour, PasswordBaseDate.wSecond);
    //strncat(PasswordGenerate_Container, PasswordBaseDate.wYear, sizeof(PasswordBaseDate.wYear));
    //strncat(PasswordGenerate_Container, PasswordBaseDate.wHour, sizeof(PasswordBaseDate.wHour));
    //printf(" Password is %s", PasswordGenerate_Container);
    //getch();
}
/*char GenerateFileName()
{
}*/
