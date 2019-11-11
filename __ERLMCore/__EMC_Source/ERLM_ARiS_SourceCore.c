/*==============================================================================
Group LM - Enrollment System in C for Preliminary Project in Programming
https://github.com/CodexLink/Project_5MES_C - Project Link managed by Janrey Licas
LM Enrollment System, Version 1748-09302018-STABLE VERSION
==============================================================================
Janrey Tuazon Licas - Initial Work / Project Lead / FrontEnd Design and Backend Programming, Commenter - CodexLink
Charles Ian Mascarenas - Junior Database Programming - ci-mascarenas
Sim Harvey Agustin Marquez - Data Gatherer, Code Analysis and Flow Creator
Julie Ann Luzano - Data Gatherer and Flow Creator
==============================================================================*/
#include <stdio.h>   // Just Basic Input Output Header File
#include <stdlib.h>  // For SYSTEM Command
#include <conio.h>   // For Getch()
#include <windows.h> // Windows Designed Only Header, This Rips Compatibility.
#include <string.h>  // String Handling for Usage of Structure and Database
// Defined STRINGS, Call this and the string will show up or error code
#define VERSION_NUMBER "1748-09302018-STABLE VER."                                                                       // Defines Version of the Program
#define PRODUCT_NAME "Team LM | ARiS Alternative Enrollment System for TiP Engineering and Architecture | C CLI Runtime" // Defines PRODUCT_NAME as the following string in SetTitleConsole();
// #define FUNCTION_UNFINISHED 1362565 == Used for Debugging... Calls when Function is at end of the line with successfull attempts to execute.
#define DATABASE_NOT_FOUND 40                  // Define Return Value for Database Not Found, Basically Deprecated Due to POST Check
#define FUNCTION_LINEAR_DISCONTINUE 1827090918 // Define Call Return Value that is almost impossible to be called, in other words, when data comparison is false that is almost impossible to be, will call this and terminate the program.
// These Defined Macors are being initialized when current certain steps are initialized.
#define FUNCTION_STEP1 "Team LM | ARiS Alternative Enrollment System for TiP Engineering and Architecture | C CLI Runtime|D Current Step \xAF 1st Step Filling up Information"
#define FUNCTION_STEP2 "Team LM | ARiS Alternative Enrollment System for TiP Engineering and Architecture | C CLI Runtime | Current Step \xAF 2nd Step \xAF Course Registration"
#define FUNCTION_STEP2_1 "Team LM | ARiS Alternative Enrollment System for TiP Engineering and Architecture | C CLI Runtime | Current Step \xAF 2nd Step | Course Registration \xAF Year Selection"
#define FUNCTION_STEP3 "Team LM | ARiS Alternative Enrollment System for TiP Engineering and Architecture | C CLI Runtime | Current Step \xAF 3rd Step | Subject Enrollment Selection"
#define FUNCTION_STEP4 "Team LM | ARiS Alternative Enrollment System for TiP Engineering and Architecture | C CLI Runtime | Current Step \xAF 4th Step | Slight Overview Data"
#define FUNCTION_STEP5 "Team LM | ARiS Alternative Enrollment System for TiP Engineering and Architecture | C CLI Runtime | Current Step \xAF 5th Step | Scholarship and Mode of Payment"
#define FUNCTION_STEP6 "Team LM | ARiS Alternative Enrollment System for TiP Engineering and Architecture | C CLI Runtime | Current Step \xAF Confirmation | Overall Overview"
#define FUNCTION_STEP7 "Team LM | ARiS Alternative Enrollment System for TiP Engineering and Architecture | C CLI Runtime | Current Step \xAF End of Process"
#define FUNCTION_SPECIAL "Team LM | ARiS Alternative Enrollment System for TiP Engineering and Architecture | C CLI Runtime | Current Step \xAF MANAGEMENT MODE"

// A Structure that Holds Data Records on the Process of Enrollment
struct OnHold_DataRecords
{
    // MAX_PATH IS A MACRO FROM MINWIN HEADER FILE FROM WINDOWS WHICH IS A SIZE OF 260
    char stdnt_GName[30],
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
        stdnt_LastSchoolYear[MAX_PATH],
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
        Generated_stdnt_NewPass[MAX_PATH],
        Generated_stdnt_NewUser[MAX_PATH],
        Granted_ScholarshipStats[16],
        Granted_ScholarshipDetails[MAX_PATH],
        PaymentMethod[12],
        FileName_Coordinate[MAX_PATH],
        FileName_DataInformation[MAX_PATH];
    int GradeLowest,
        GradeHighest,
        GradeGeneralAverage_LastSem;
    long int stdnt_StudentID;
};

// Struct that receives values of OnHold_DataRecords Struct Members. Specific Parameters are Added to be only passed from this Struct Members.
// TRUE ELements are being stored here...
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

// Database Struct Members that is going to be used for Rewritting, Reading, Receiving, Passing Data from Program to File.
struct Management_Override
{
    char stdnt_GName[30],
        stdnt_MName[30],
        stdnt_LName[30],
        stdnt_Course_Codename[40],
        stdnt_Year_Choice[20],
        stdnt_Course_Semester[20],
        stdnt_Username[100],
        stdnt_Password[100];
    long int Generated_StudentID;
};
// Database Struct that can be used for Managing Master Users espeically witrh File Specific Master Use Only...
struct MasterKey
{
    char Master_User[50],
        Master_Password[50];
};

// Following Defined Structs to these another variables that holds the same copy of the following members.
struct OnHold_DataRecords OnProcess_StudentData;
struct Enrollment_InformationReceiver ERLM_DataReceiver;
struct Management_Override DataChange;
struct MasterKey MasterPoint;

// Global variables to Use On Specific Functions...
int FunctionCount = 0; // Used at
int FillUp_Stage = 0;  // Used at Func_NewStdnt_Fillup() Funciont

// Current Student Functions, Login Functions.
void Func_OldStd_ERLM_Menu();
void Func_OldStdnt_ERLM(); // Menu for Checking Data that is being parsed by the program, asking the user if the data checked reflect to his/her information

// New Student Functions, Current Students will use most of these functions as well. There are at least 2-3 functions that are being skipped.
void Func_NewStdnt_FillUp();        // New Student -> Step One, Part One Function, Asked Information in Three Stages Categorized from Identity, General and Technical
void Func_NewStdnt_InfoCheck();     // New Student ->  Step One, Part Two Function, Displays All Inputted Data and Asks User to if all data is correct from the passed values.
void Func_NewStdnt_CourseReg();     // New Student -> Step Two of Part One and of Part Two Function, User asked to Select Branch Course and Specified Main Course
void Func_NewStdnt_YearSemSelect(); // Student Function (Old and New) -> Step Two of Part Three / Four and Five Function, User Selects Year and Semester and also displays current information before proceeding.
/*
    SPECIAL NOTE: THIS FUNCTION ON TOP ALSO PARSES DATA TO KNOW WHAT TO PASS SUCH AS SUBJECTS, UNITS, TIME, AND DAY.
    PLEASE REFER TO THE FUNCTION TO KNOW WHAT DATA TO PARSES AND DATA TO PASS
*/
void Func_SubjectUnit_Selection(char **Subject_CodeName, char **Subject_FullName, char **Subject_LinearTime, int Subject_Units[12]); //  Step 3, Pass these subject information regarding their titles.
/*
    SPECIAL NOTE @ Func_SubjectUnit_Selection()
    One of the most longest body of function in the Whole System.
    Contains alot of Guard to Fix Entry Holes.
    -----------
    Double Pointer is pretty much unusual specially for people who is beginner.
    To preserve memory after going out to the function, we need to use double pointer.
    To retain the memory even outside the function call. Please refer to this link for more information
    https://stackoverflow.com/questions/5580761/why-use-double-pointer-or-why-use-pointers-to-pointers
*/
void Func_Final_Overview(int Final_Comp_SelectedSubjects, int Subject_ExpectedCandidates); // Step 4 Function, Pass Data without Creating Struct Variables and Parses and shows the only available subjects that user taken.
/*
    Function above uses struct Enrollment_InformationReceiver ERLM_DataReceiver;
*/
void Func_Stdnt_ScholarshipCheck();        // Step 5, Function that almost replicates the standards of checking grade if entrance scholarship is admittable.
void Func_Mode_Of_Payment();               // Step 6, Simple Function that asks for two modes of payment.
void Func_PrintDocument_FinalTranscript(); //Shows Final output of the potential look of a registration form.
/*
The Func_PrintDocument_FinalTranscript is calls dynamic data creation function and those are:
void GetDataEnrolleeInformation();
void Increment_StudentID();
void GenerateUserPass_withGenerateFileName();
Those are used for data-interaction.
*/

// POST and Critical Component Function Prototypes, used for Pre runnning the application
void Function_CriticalComp_CheckCreate();             // Checks Components First Before Actual Initialization
void Argument_Initialization(int argc, char *argv[]); // Program Arguments Checker for Management Mode or Normal Mode or Restrict Window and Button Mode

void Main_Menu(); // Main Menu for Normal Students, Runs without /mgr_md parameter, can be run with /rstrict_wnd

// Functions for Management Mode
void FuncAdmin_Mgr_Login();              // Function for Login Data for Masters / Managements
void FuncAdmin_Mgr_Mode();               // Function for Displaying Management List
void FuncAdmin_Mgr_AddEntry();           // Function for Manual Override / Adding Datas without Prompting on New Enrollment Steps
void FuncAdmin_Mgr_ReadAllEntry();       // Shows Current Entries without any Sort
void FuncAdmin_Mgr_SearchNameEntry();    // Function for Searching by Name of a Student
void FuncAdmin_Mgr_SearchProgramEntry(); // Function for Searching by Program of a Student
void FuncAdmin_Mgr_SearchID();           // Function for Searching by ID of a Student
void FuncAdmin_Mgr_Delete_Entry();       // Function for Deleting Entries for Mistakes and Potential Data Corruption
void FuncAdmin_Mgr_AddMaster();          // Function for Creating a Master Credential
void FuncAdmin_Mgr_ReadMaster();         // Function for Checking Master Credentials
void FuncAdmin_Mgr_DeleteMaster();       // Function for Deleting Master Credentials

// Functions for Dynamic Data Creation
void GetDataEnrolleeInformation();            // Contains Data Printing to File Stream and Contains Database Changing Functions
void Increment_StudentID();                   // Accesses A File that contains number that is non binary and return incremented value of the received value.
void GenerateUserPass_withGenerateFileName(); // Generate Username, Password for Student Based on their Name and Student Number.
void SetCursorCoord_XY(int x, int y);         // gotoxy's linux port to Windows API Function. Renamed to SetCursorCoord for clarification instead of gotoxy.

// End of Dataprototype of Starting Headpoints

// int Main -> Argument Checker
int main(int argc, char *argv[])
{
    HWND consoleWindow = GetConsoleWindow();
    int Argument_Checker = 0;
    printf("@ Function \t|\t INITIALIZING \t|\t  int main() => Argument_Initialization\n"); // Placeholder Debugging Print Output. When program is stucked after outputting this string, there is something wrong.
    if (argc > 1)                                                                           // When Program detects that parameter count is one and obove, initialize this function for initiating the parameters passed. Cannot be 'ARGC == 1' due to one ARGV[1] is directory that program resides.
    {
        while (Argument_Checker < argc) // Using =< will result to a segmentation fault.
        {
            if (strcmp(argv[Argument_Checker], "/rstrict_wnd") == 0) // Restrict Window Parameter Check
            {
                // SetWindowLong sets a 32-bit value constituting the information about a window. consists of the following contents: (consoleWindow is a Handle that gets GetConsoleWindowInfo, GWL_STYLE - Retrieve the window styles of the window.)
                // GetWindowLong retrives information of the window.
                SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
            }
            if (strcmp(argv[Argument_Checker], "/mgr_md") == 0) // Management Mode Parameter Check
            {
                FunctionCount = 1; // Technically Sends Function Count Value to 1 which runs functions to ManagerMode.
            }
            Argument_Checker++; // Increments When First Check is done, and so on...
        }
    }
    system("CLS");                       // Clears Screen to show that functions runs succesfully.
    Function_CriticalComp_CheckCreate(); // If the parameters are being called or not, program will run POST / Critical Components Checker to sure program runs successfully.
}
// Function_CriticalComp_CheckCreate -> Function that is replicates POST Screens. Initiates before actual initialization of main program.
void Function_CriticalComp_CheckCreate()
{
    HWND hwnd = GetConsoleWindow();           // Get Console Window Properties
    HMENU hmenu = GetSystemMenu(hwnd, FALSE); // Gets Exact copy of System Menu for Modification...
    FILE *FileDatabase_Check;                 // Pointer for FileDataBase
    SYSTEMTIME GetDate_Local;                 // WINDOWS.H Specific Header for Time Check. This removes time.h
    // Set Char Pointer of Strings with Directories to Execute and Check
    char *datapoint_filelist[3] = {"LM KeyDatabase//LM_CEA_Enrollment.lmdat", "LM KeyDatabase//LM_CEA_MasterKey.lmdat", "LM KeyDatabase//LM_CEA_CurrentStudentID.lmdat"};
    // char pointer of array is a set of setences per block array.
    int Counter_DataPoint_Check;
    int SetCursorCounter = 3, SizeCheck = 0, SizeCheck_1 = 0; // Inits SetCursorCounter for Dynamic Change
    SetConsoleTitle("Intializing Critical Components | LM Enrollment System");
    SetCursorCoord_XY(30, SetCursorCounter); // SetCursorConuner Value is 3
    SetCursorCounter++;                      // SetCursorConuner Value is now 4. This Will repeat depends on the current code structure given.
    printf(VERSION_NUMBER "\n");             // Calls DEFINE Macros
    SetCursorCoord_XY(30, SetCursorCounter);
    SetCursorCounter++;
    printf(PRODUCT_NAME "\n"); // Calls DEFINE Macros
    SetCursorCoord_XY(30, SetCursorCounter);
    SetCursorCounter++;
    Sleep(2500);
    SetCursorCoord_XY(30, SetCursorCounter);
    SetCursorCounter++;
    printf("\xAF\xDD INITIALIZATION  #1 \xDD\xAF Initializing and Checking Critical Components Before Actual Program Initialization");
    SetCursorCoord_XY(30, SetCursorCounter);
    SetCursorCounter++;
    SetCursorCoord_XY(30, SetCursorCounter);
    SetCursorCounter++;
    SetCursorCoord_XY(30, SetCursorCounter);
    SetCursorCounter++;
    printf("COMPONENT MATERIAL\t\xDD\t STATUS\t\t\xDD DESCRIPTION\t");
    SetCursorCoord_XY(30, SetCursorCounter);
    SetCursorCounter++;
    SetCursorCoord_XY(30, SetCursorCounter);
    SetCursorCounter++;
    printf("\xDD\xAF Init.Component # 1 \t\xDD\t COMPLETE \t\xDD Set Command Line to Full Screen");
    ShowWindow(hwnd, SW_MAXIMIZE);
    SetCursorCoord_XY(30, SetCursorCounter);
    SetCursorCounter++;
    printf("\xDD\xAF Init.Component # 2 \t\xDD\t COMPLETE \t\xDD Disable Close Button");
    EnableMenuItem(hmenu, SC_CLOSE, MF_GRAYED);
    SetCursorCoord_XY(30, SetCursorCounter);
    SetCursorCounter++;
    printf("\xDD\xAF Init.Component # 3.1 \t\xDD\t CHECKING \t\xDD Checking Local Database on Local Storage (Using .lmdat File)");
    for (Counter_DataPoint_Check = 0; Counter_DataPoint_Check < 3; Counter_DataPoint_Check++)
    {
        FileDatabase_Check = fopen(datapoint_filelist[Counter_DataPoint_Check], "r");
        if (FileDatabase_Check == NULL)
        {
            mkdir("LM KeyDatabase");          // Calls to create a folder dynamically. Never checks errors because we never need it.
            mkdir("Student_RegForm");         // Calls to create a folder dynamically. Never checks errors because we never need it.
            mkdir("DataInformation_Student"); // Calls to create a folder dynamically. Never checks errors because we never need it.
            SetCursorCounter++;
            SetCursorCoord_XY(30, SetCursorCounter);
            printf("\xDD\xAF Init.Components \t\xDD\t ERROR \t\t\xDD File Database not found! Creating File...");
            FileDatabase_Check = fopen(datapoint_filelist[Counter_DataPoint_Check], "w"); // Set Mode to Written After FileDatabase_Check is NULL

            if (strcmp(datapoint_filelist[Counter_DataPoint_Check], "LM KeyDatabase//LM_CEA_CurrentStudentID.lmdat") == 0)
            {                                           // At some cases, specific files needs to write specific data hence, have to create an if and else structure.
                fprintf(FileDatabase_Check, "1800000"); // Starting Point of Student Number, Changeable Default as File Holder for this Value has been deleted...
                SetCursorCounter++;
                SetCursorCoord_XY(30, SetCursorCounter);
                printf("\xDD\xAF Init.Components \t\xDD\t COMPLETE \t\xDD Database Now Found!"); // Prints that it was successfully written.
            }
            else if (strcmp(datapoint_filelist[Counter_DataPoint_Check], "LM KeyDatabase//LM_CEA_MasterKey.lmdat") == 0)
            {
                FileDatabase_Check = fopen(datapoint_filelist[Counter_DataPoint_Check], "wb"); // Writes in binary as per security
                strcpy(MasterPoint.Master_User, "ADMIN");                                      // These sends data to be passed on File, no need to create local variable.
                strcpy(MasterPoint.Master_Password, "LM123");                                  // These sends data to be passed on File, no need to create local variable.
                fwrite(&MasterPoint, sizeof(MasterPoint), 1, FileDatabase_Check);              // This was used to use two strcpy from above to copy from file.
                SetCursorCounter++;
                SetCursorCoord_XY(30, SetCursorCounter);
                printf("\xDD\xAF Init.Components \t\xDD\t COMPLETE \t\xDD Database Now Found!");
                continue;
            }
            else if (FileDatabase_Check == NULL) // Added for double check if file really creates...
            {
                SetCursorCounter++;
                SetCursorCoord_XY(30, SetCursorCounter);
                printf("\xDD\xAF Init.Components \t\xDD\t ERROR \t\t\xDD I cannot create the file, give me a adminstrative priviledge or move me somewhere???");
                fclose(FileDatabase_Check);
                Sleep(1500);
                exit(FUNCTION_LINEAR_DISCONTINUE); // Exits and gives static random value to tell it looks like a segmentation fault but disk written fault.
            }
            else
            {
                SetCursorCounter++;
                SetCursorCoord_XY(30, SetCursorCounter);
                printf("\xDD\xAF Init.Components \t\xDD\t COMPLETE \t\xDD Database Now Found!"); // Runs on Specific File Check....
            }
        }
        else
        {
            SetCursorCounter++;
            SetCursorCoord_XY(30, SetCursorCounter);
            printf("\xDD\xAF Init.Components \t\xDD\t VERIFIED \t\xDD Database File Found!");
        }
        fclose(FileDatabase_Check);
    }
    fclose(FileDatabase_Check);
    SetCursorCounter++;
    SetCursorCounter++;
    SetCursorCoord_XY(30, SetCursorCounter);
    SetCursorCounter++;
    /*
    INITIALIZATION #2 CHECKING CONTENTS BEFORE CONTINUING....
    Two Files are being checked if the files have size or content. This is mandatory due to the fact it plays a major role and cannot run without
    having blank content. The only cons here is that, it never checks if the file is valid, hence known one of our limitations to do so.
    */
    printf("\xAF\xDD INITIALIZATION #2 \xDD\xAF Checking Two Special File Contents...");
    FileDatabase_Check = fopen("LM KeyDatabase//LM_CEA_CurrentStudentID.lmdat", "r");
    fseek(FileDatabase_Check, 0, SEEK_END); // Make File Pointer at the last point
    SizeCheck = ftell(FileDatabase_Check);  // Checks Current Position Pointer
    fclose(FileDatabase_Check);
    if (SizeCheck == 0) // if pointer is still at 0 this proves that the file has no size.
    {
        fseek(FileDatabase_Check, 0, SEEK_SET);                                           // Resets back at the beginning to ensure file write.
        FileDatabase_Check = fopen("LM KeyDatabase//LM_CEA_CurrentStudentID.lmdat", "w"); // Change Mode
        SetCursorCounter++;
        SetCursorCoord_XY(30, SetCursorCounter);
        printf("\xDD\xAF Init.Components \t\xDD\t ERROR \t\t\xDD File Found, But File is blank...");
        fprintf(FileDatabase_Check, "1800000"); // Starting Point of Student Number, Changeable Default as File Holder for this Value has been deleted...
        SetCursorCounter++;
        SetCursorCoord_XY(30, SetCursorCounter);
        printf("\xDD\xAF Init.Components \t\xDD\t SUCCESS \t\xDD File Content Added...");
        fclose(FileDatabase_Check);
    }
    else
    {
        SetCursorCounter++;
        SetCursorCoord_XY(30, SetCursorCounter);
        printf("\xDD\xAF Init.Components \t\xDD\t VERIFIED \t\xDD File Has Size and Content");
        fclose(FileDatabase_Check);
    }
    FileDatabase_Check = fopen("LM KeyDatabase//LM_CEA_MasterKey.lmdat", "rb");
    fseek(FileDatabase_Check, 0, SEEK_END); // Resets back at the beginning to ensure file write.
    SizeCheck_1 = ftell(FileDatabase_Check);
    fclose(FileDatabase_Check);
    if (SizeCheck_1 == 0) // if pointer is still at 0 this proves that the file has no size.
    {
        fseek(FileDatabase_Check, 0, SEEK_SET);
        SetCursorCounter++;
        SetCursorCoord_XY(30, SetCursorCounter);
        printf("\xDD\xAF Init.Components \t\xDD\t ERROR \t\t\xDD File Found, But File is blank. Data Added");
        FileDatabase_Check = fopen("LM KeyDatabase//LM_CEA_MasterKey.lmdat", "wb");
        strcpy(MasterPoint.Master_User, "ADMIN");     // Same Scenario in Initialization #1 where it has to be created...
        strcpy(MasterPoint.Master_Password, "LM123"); // Same Scenario in Initialization #1 where it has to be created...
        fwrite(&MasterPoint, sizeof(MasterPoint), 1, FileDatabase_Check);
        SetCursorCounter++;
        SetCursorCoord_XY(30, SetCursorCounter);
        printf("\xDD\xAF Init.Components \t\xDD\t SUCCESS \t\xDD File Content Added...");
        fclose(FileDatabase_Check);
    }
    else
    {
        SetCursorCounter++;
        SetCursorCoord_XY(30, SetCursorCounter);
        printf("\xDD\xAF Init.Components \t\xDD\t VERIFIED \t\xDD File Has Size and Content");
        fclose(FileDatabase_Check);
    }
    // This FunctionCount Variable is a Global Variable, this helps to differentiate what mode to launch.
    if (FunctionCount == 1)
    {
        SetCursorCounter++;
        SetCursorCounter++;
        SetCursorCoord_XY(30, SetCursorCounter);
        printf("\xAF \xDD INFO \xDD \xAF End of Check File, and Launching Management Mode...");
        Sleep(2500);
        FuncAdmin_Mgr_Login();
    }
    else
    {
        SetCursorCounter++;
        SetCursorCounter++;
        SetCursorCoord_XY(30, SetCursorCounter);
        printf("\xAF \xDD INFO \xDD \xAF End of Check File, and Launching Normal Mode...");
        Sleep(2500);
        Main_Menu();
    }
}
void Main_Menu()
{
    SetConsoleTitle(PRODUCT_NAME); // Set Title with DEFINED Macro
    system("CLS");
    while (1)
    {                     // This will loop forever because wtf is 1?
        FillUp_Stage = 0; // Set FillUp_Stage Variable as a Reset of Values After Enrollment Process
        system("CLS");
        SetCursorCoord_XY(30, 3);
        // \x is a Format Specifier for Hexadecimal, There are two characters to be inputed to complete an \x format specifier.
        // CD is one of the ASCII Characters that can be seen on the ASCII Table provided by Programmers of this Program.
        // At some point, Direct Encoding ASCII Characters by Copy Pasting or Special Command can sometimes be confusing especially when Editor has different Enconding Mode.
        // Some editors need to encoding mode to UTF-8. When you set to different, there is a one function that is directly encoded to a symbol without adding this parameter.
        // The function referenced is GetDataEnrolleeInformation();
        printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        SetCursorCoord_XY(30, 4);
        // Lucky Based Point For Manipulating Spaces with Tab Space with \t
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        SetCursorCoord_XY(30, 5); //SetCursorCoord_XY is the same as gotoxy. 30 is X, and 5 is Y.
        printf("\xBA \xDD Version " VERSION_NUMBER "\t\t\t\t\t\t\t\t       \xBA");
        SetCursorCoord_XY(30, 6);
        printf("\xBA \xDD " PRODUCT_NAME "    \xBA");
        SetCursorCoord_XY(30, 7);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        SetCursorCoord_XY(30, 8);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        SetCursorCoord_XY(30, 10);
        printf("\xFE\xCD\xCD \xDD Main Menu \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
        SetCursorCoord_XY(30, 12);
        printf("\xAF [1] \xDD Enroll as a Current Student");
        SetCursorCoord_XY(30, 14);
        printf("\xAF [2] \xDD Enroll as a New Student");
        SetCursorCoord_XY(30, 16);
        printf("\xAF [3] \xDD Gracefully Exit / Terminate / End Application");
        SetCursorCoord_XY(30, 18);
        printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
        SetCursorCoord_XY(30, 20);
        printf("\xC8\xAF Press a key that corresponds your decision [1 - 3] \xDD\xAF ");
        switch (getche()) // Used getche to receive single character.
        {
        case '1': // here getche outputs char instead of int. To receive literal one, it has to be single quoted as char
            Func_OldStdnt_ERLM();
            break;
        case '2':
            Func_NewStdnt_FillUp();
            break;
        case '3':
            SetConsoleTitle("Terminating Enrollment System | LM Enrollment System");
            SetCursorCoord_XY(30, 22);
            printf("\xC9\xCD\xCD \xDD INFORMATION \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
            SetCursorCoord_XY(30, 23);
            printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
            SetCursorCoord_XY(30, 24);
            printf("\xBA \xAF LM Enrollment System => Terminated... Have A Nice Day...\t\t\t\t\t       \xBA");
            SetCursorCoord_XY(30, 25);
            printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
            SetCursorCoord_XY(30, 26);
            printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
            Sleep(2500);
            exit(EXIT_SUCCESS); // Return Exit Code to 0 has per macro defined as 0.
            case '6':
            Func_Stdnt_ScholarshipCheck();
        default:                // If none of it is true to the above said case, hence it will go back to the menu once again.
            SetCursorCoord_XY(30, 22);
            printf("\xC9\xCD\xCD \xDD Warning! \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
            SetCursorCoord_XY(30, 23);
            printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
            SetCursorCoord_XY(30, 24);
            puts("\xBA \xAF Unrecognized Input!\t\t\t\t\t\t\t\t\t\t       \xBA");
            SetCursorCoord_XY(30, 25);
            printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
            SetCursorCoord_XY(30, 26);
            printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
            Sleep(1500);
            continue;
        }
    }
}

void Func_OldStdnt_ERLM()
{
    SetConsoleTitle("LM Enrollment System | Current Student Login");
    FILE *FileDatabase_Enrollment;
    FileDatabase_Enrollment = fopen("LM KeyDatabase//LM_CEA_Enrollment.lmdat", "rb");
    char stdnt_Username_Placeholder[100];
    char stdnt_Password_Placeholder[100];
    long long int stdnt_GeneratedID_Placeholder;
    while (1)
    {
        rewind(FileDatabase_Enrollment);
        system("CLS");
        SetCursorCoord_XY(30, 3);
        printf("\xC9\xCD\xCD \xDD CURRENT PROGRESS \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        SetCursorCoord_XY(30, 4);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, 5);
        printf("\xBA [ \xDD\xAF [1st Step \xAF Student Login] \xAF 2nd \xAF 3rd \xAF 4th \xAF 5th \xAF Confirm \xAF End]\t\t\t\t   \xBA\n");
        SetCursorCoord_XY(30, 6);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, 7);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        SetCursorCoord_XY(30, 9);
        printf("\xFE\xCD\xCD \xDD USER INPUT CREDENTIALS \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
        SetCursorCoord_XY(30, 11);
        printf("Enter your Username \xAF [ \xDD NOTE \xAF If you want to go back to main menutype 'RBF-0'] \xAF ");
        scanf("%30s", &stdnt_Username_Placeholder);
        if (strcmp(stdnt_Username_Placeholder, "RBF-0") == 0) // Created STRCMP for Getting out of the Login Menu. There are no ways to insert it somewhere so to make it quick, we added it in front.
        {
            SetCursorCoord_XY(30, 13);
            printf("\xAF \xDD INFO \xDD \xAF Returning to Main Menu...");
            Sleep(2000);
            Main_Menu();
        }
        SetCursorCoord_XY(30, 13);
        printf("Enter your Password \xAF ");
        scanf("%30s", &stdnt_Password_Placeholder);
        fflush(stdin);
        /*
        This part has controversy where scanf has field limit where it only takes 30 characters. But this does not avoid
        buffer overflow. So to fix it, we added fflush(stdin); To clear any unnecessary data.
        We are aware that fflush has undefined behavior due to the fact that it was specially used for output streams.
        Refer to https://stackoverflow.com/questions/2979209/using-fflushstdin
        */
        SetCursorCoord_XY(30, 15);
        printf("Enter Student ID \xAF ");
        scanf("%10lld", &stdnt_GeneratedID_Placeholder);
        fflush(stdin);
        while (1)
        {
            fread(&DataChange, sizeof(DataChange), 1, FileDatabase_Enrollment); // Reads One Line in the size of DataChange -> Bytes to the File
            if (feof(FileDatabase_Enrollment))                                  // if end of the line then check if the following is still correct to display errors.
            {
                if ((strcmp(stdnt_Username_Placeholder, DataChange.stdnt_Username) != 0) || (strcmp(stdnt_Password_Placeholder, DataChange.stdnt_Password) != 0) || (stdnt_GeneratedID_Placeholder == DataChange.Generated_StudentID) != 0)
                { // Added if the read data still may validate at some point, hence not.
                    SetCursorCoord_XY(30, 17);
                    printf("\xAF\xDD FAILED \xDD Login Failed! One of the following inputs are incorrect!");
                    Sleep(2000);
                    rewind(FileDatabase_Enrollment);
                    break;
                }
            }
            else if ((strcmp(stdnt_Username_Placeholder, DataChange.stdnt_Username) == 0) && (strcmp(stdnt_Password_Placeholder, DataChange.stdnt_Password) == 0) && (stdnt_GeneratedID_Placeholder == DataChange.Generated_StudentID) == 1)
            {                                    // At this point, the data is valid. There will be a loop that might parse the data into the program.
                rewind(FileDatabase_Enrollment); // Rewind to reset to beginning because the credentials doesnt match to the input given.
                while (1)
                {
                    /*
                    This was intended because the file has to loop to find the exact data and get it
                    // If we don't have loop, assume that there are two identical datas. The first will be used if the second one has been used.
                    */
                    fread(&DataChange, sizeof(DataChange), 1, FileDatabase_Enrollment);
                    if (feof(FileDatabase_Enrollment))
                    {
                        break;
                    }
                    else if ((strcmp(stdnt_Username_Placeholder, DataChange.stdnt_Username) == 0) && (strcmp(stdnt_Password_Placeholder, DataChange.stdnt_Password) == 0) && (stdnt_GeneratedID_Placeholder == DataChange.Generated_StudentID) == 1)
                    {
                        // Get the data onboard to the program to use for enrollment.
                        strcpy(OnProcess_StudentData.stdnt_GName, DataChange.stdnt_GName);
                        strcpy(OnProcess_StudentData.stdnt_MName, DataChange.stdnt_MName);
                        strcpy(OnProcess_StudentData.stdnt_LName, DataChange.stdnt_LName);
                        strcpy(OnProcess_StudentData.MainCourse_CodeName_Passer, DataChange.stdnt_Course_Codename);
                        OnProcess_StudentData.stdnt_StudentID = DataChange.Generated_StudentID;
                        strcpy(OnProcess_StudentData.Course_YearChoice, DataChange.stdnt_Year_Choice);
                        strcpy(OnProcess_StudentData.Course_SemSelection, DataChange.stdnt_Course_Semester);
                        // Parse the data for data that has been manually encoded.
                        // If any by chance it hasn't been parsed, the program won't handle hit due to the fact that
                        // It is already unknown even when converted to Unknown Type...
                        if (strcmp(OnProcess_StudentData.MainCourse_CodeName_Passer, "BSCE") == 0)
                        {
                            strcpy(OnProcess_StudentData.MainCourse_FullName_Passer, "Civil Engineering");
                        }
                        else if (strcmp(OnProcess_StudentData.MainCourse_CodeName_Passer, "BSCpE") == 0)
                        {
                            strcpy(OnProcess_StudentData.MainCourse_FullName_Passer, "Computer Engineering");
                        }
                        else if (strcmp(OnProcess_StudentData.MainCourse_CodeName_Passer, "BSEE") == 0)
                        {
                            strcpy(OnProcess_StudentData.MainCourse_FullName_Passer, "Electronics Engineering");
                        }
                        else if (strcmp(OnProcess_StudentData.MainCourse_CodeName_Passer, "BSECE") == 0)
                        {
                            strcpy(OnProcess_StudentData.MainCourse_FullName_Passer, "Electronics Engineering");
                        }
                        else if (strcmp(OnProcess_StudentData.MainCourse_CodeName_Passer, "BSEnSE") == 0)
                        {
                            strcpy(OnProcess_StudentData.MainCourse_FullName_Passer, "Environmental and Sanitary Engineering");
                        }
                        else if (strcmp(OnProcess_StudentData.MainCourse_CodeName_Passer, "BSIE") == 0)
                        {
                            strcpy(OnProcess_StudentData.MainCourse_FullName_Passer, "Industrial Engineering");
                        }
                        else if (strcmp(OnProcess_StudentData.MainCourse_CodeName_Passer, "BSME") == 0)
                        {
                            strcpy(OnProcess_StudentData.MainCourse_FullName_Passer, "Mechanical Engineering");
                        }
                        else if (strcmp(OnProcess_StudentData.MainCourse_CodeName_Passer, "Arch") == 0)
                        {
                            strcpy(OnProcess_StudentData.MainCourse_FullName_Passer, "Architecture");
                        }
                        if (strcmp(OnProcess_StudentData.Course_YearChoice, "1st") == 0)
                        {
                            strcpy(OnProcess_StudentData.Course_YearChoice, "First Year College");
                        }
                        else if (strcmp(OnProcess_StudentData.Course_YearChoice, "2nd") == 0)
                        {
                            strcpy(OnProcess_StudentData.Course_YearChoice, "Second Year College");
                        }
                        else if (strcmp(OnProcess_StudentData.Course_YearChoice, "3rd") == 0)
                        {
                            strcpy(OnProcess_StudentData.Course_YearChoice, "Third Year College");
                        }
                        else if (strcmp(OnProcess_StudentData.Course_YearChoice, "4th") == 0)
                        {
                            strcpy(OnProcess_StudentData.Course_YearChoice, "Four Year College");
                        }
                        else if (strcmp(OnProcess_StudentData.Course_YearChoice, "5th") == 0)
                        {
                            strcpy(OnProcess_StudentData.Course_YearChoice, "Fifth Year College");
                        }
                        if (strcmp(OnProcess_StudentData.Course_SemSelection, "First") == 0)
                        {
                            strcpy(OnProcess_StudentData.Course_SemSelection, "First Semester");
                        }
                        else if (strcmp(OnProcess_StudentData.Course_SemSelection, "Second") == 0)
                        {
                            strcpy(OnProcess_StudentData.Course_SemSelection, "Second Semester");
                        }
                    }
                }
                fclose(FileDatabase_Enrollment);
                SetCursorCoord_XY(30, 17);
                printf("\xC8\xDD INFO \xDD Login Success!");
                Sleep(2000);
                Func_OldStd_ERLM_Menu(); // Caliing this function will skip two function because those are already defined.
                break;
                // Get Information of Student
            }
            else
            {
                // Continue Through until data valid.
                continue;
            }
        }
    }
}
// Func_OldStd_ERLM_Menu -> Function of Data Validity of Existing Student Account
/*
NOTE: We cannot create a menu here, it only signifies data check if the given data is correct.
*/
void Func_OldStd_ERLM_Menu()
{
    SetConsoleTitle("LM Enrollment System | Current Student Login");
    int Counter_For_Selection = 0;
    while (1)
    {
        int SetCursorCounter = 3; // Set Starting Point
        system("CLS");
        SetCursorCoord_XY(30, SetCursorCounter);
        SetCursorCounter++;
        printf("\xC9\xCD\xCD \xDD CURRENT PROGRESS \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        SetCursorCoord_XY(30, SetCursorCounter);
        SetCursorCounter++;
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, SetCursorCounter);
        SetCursorCounter++;
        printf("\xBA [ \xDD\xAF 1st \xAF [2nd - Student Semester Selection] \xAF 3rd \xAF 4th \xAF 5th \xAF Confirm \xAF End]\t\t\t   \xBA\n");
        SetCursorCoord_XY(30, SetCursorCounter);
        SetCursorCounter++;
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, SetCursorCounter);
        SetCursorCounter++;
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        SetCursorCoord_XY(30, SetCursorCounter);
        SetCursorCounter++;
        SetCursorCoord_XY(30, SetCursorCounter);
        SetCursorCounter++;
        SetCursorCounter++;
        printf("\xFE\xCD\xCD \xDD STUDENT INFORMATION \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
        SetCursorCoord_XY(30, SetCursorCounter);
        SetCursorCounter++;
        printf("\xDD\xAF Hello and Welcome %s, %s %s!\n", OnProcess_StudentData.stdnt_LName, OnProcess_StudentData.stdnt_GName, OnProcess_StudentData.stdnt_MName);
        SetCursorCoord_XY(30, SetCursorCounter);
        SetCursorCounter++;
        printf("\xDD\xAF Current Course \xAF %s \xAF %s", OnProcess_StudentData.MainCourse_CodeName_Passer, OnProcess_StudentData.MainCourse_FullName_Passer);
        SetCursorCoord_XY(30, SetCursorCounter);
        SetCursorCounter++;
        printf("\xDD\xAF Student ID \xAF %ld\n", OnProcess_StudentData.stdnt_StudentID);
        SetCursorCoord_XY(30, SetCursorCounter);
        SetCursorCounter++;
        printf("\xDD\xAF Current Level \xAF %s | %s\n", OnProcess_StudentData.Course_YearChoice, OnProcess_StudentData.Course_SemSelection);
        SetCursorCoord_XY(30, SetCursorCounter);
        SetCursorCounter++;
        printf("\xDD \xAF\xDD NOTE \xDD Please enroll to your respective next level based from your current level!!!\n");
        SetCursorCounter++;
        SetCursorCoord_XY(30, SetCursorCounter);
        SetCursorCounter++;
        SetCursorCounter++;
        printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
        SetCursorCoord_XY(30, SetCursorCounter);
        SetCursorCounter++;
        SetCursorCounter++;
        printf("Are the following details reflects on you? [Y/N]\xAF ");
        switch (getche())
        {
        case 'Y':
        case 'y':
            SetCursorCoord_XY(30, SetCursorCounter);
            SetCursorCounter++;
            printf("\xAF \xDD INFO \xDD Proceeding To Second Step of Part 3...");
            Sleep(1500);
            Func_NewStdnt_YearSemSelect();
        case 'N':
        case 'n':
            SetCursorCoord_XY(30, SetCursorCounter);
            SetCursorCounter++;
            printf("\xAF \xDD INFO \xDD Returning To Main Menu...");
            Sleep(1500);
            Main_Menu();
        default:
            SetCursorCoord_XY(30, SetCursorCounter);
            SetCursorCounter++;
            printf("\xAF \xDD ERROR \xAF Sorry, I don't understand that...");
            Sleep(1500);
            continue;
        }
    }
}
//Func_NewStdnt_FillUp -> Data Filling Student Information
/*
NOTE: Contains FGETS and STRTOK to handle strings properly.
Without strtok, the strings will technically broke the interface because \n was there.
fgets, sizeof(MaxCount) is a size or number characters to be passed to the struct variables.
There are three stages, those are identity, general and technical. Each stages is managed at FillUp_Stage Variable set within values to proceed.
*/
void Func_NewStdnt_FillUp()
{
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
            printf("\xAF [1] Enrollee's First Name [If Secondary Given Name Exist, Concatenate with '-', Ex: Lily-Ann]");
            SetCursorCoord_XY(30, 20);
            printf("\xC8\xAF INPUT \xDD\xAF ");
            //fgets instead of scanf to reduced the difficulty of dealing with whitespaces
            fgets(OnProcess_StudentData.stdnt_GName, sizeof(OnProcess_StudentData.stdnt_GName), stdin);
            //strtok trims new line on the data
            strtok(OnProcess_StudentData.stdnt_GName, "\n");
            SetCursorCoord_XY(30, 22);
            printf("\xAF [2] Enrollee's Middle Name");
            SetCursorCoord_XY(30, 24);
            printf("\xC8\xAF INPUT \xDD\xAF ");
            fgets(OnProcess_StudentData.stdnt_MName, sizeof(OnProcess_StudentData.stdnt_MName), stdin);
            strtok(OnProcess_StudentData.stdnt_MName, "\n");
            fflush(stdin);
            SetCursorCoord_XY(30, 26);
            printf("\xAF [3] Enrollee's Last Name ");
            SetCursorCoord_XY(30, 28);
            printf("\xC8\xAF INPUT \xDD\xAF ");
            fgets(OnProcess_StudentData.stdnt_LName, sizeof(OnProcess_StudentData.stdnt_LName), stdin);
            strtok(OnProcess_StudentData.stdnt_LName, "\n");
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
            //This printf data checker, checks string lengths if characters are below 2 or above 2.
            //printf(" %d | %d | %d | %d | %d | %d | %d | %d | %d", Test_2, Test_3, Test_4, Test_5, Test_6, Test_7, Test_9, Test_10, Test_11);
            // To avoid getting manipulated by \n only and to above interface break. We have to set up and restrict characters to be 2 and above to proceed on the next stage.
            if ((strlen(OnProcess_StudentData.stdnt_GName) <= 2) || (strlen(OnProcess_StudentData.stdnt_MName) <= 2) || (strlen(OnProcess_StudentData.stdnt_LName) <= 2) || (strlen(OnProcess_StudentData.stdnt_FathersName) <= 2) || (strlen(OnProcess_StudentData.stdnt_FathersInfoJob) <= 2) || (strlen(OnProcess_StudentData.stdnt_FathersInfoContact) <= 2) || (strlen(OnProcess_StudentData.stdnt_MothersName) <= 2) || (strlen(OnProcess_StudentData.stdnt_MothersInfoJob) <= 2) || (strlen(OnProcess_StudentData.stdnt_MothersInfoContact) <= 2))
            {
                SetCursorCoord_XY(30, 54);
                printf("\xAF \xDD ERROR \xDD One of the required input must contain 3 characters in order to continue...");
                getch();
                continue;
            }
            else
            {
                SetCursorCoord_XY(30, 54);
                printf("\xFE\xCD\xCD USER INPUT DONE FOR IDENTITY INFORMATION \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
                FillUp_Stage++; // Increments Varaible
                Sleep(1500);
                Func_NewStdnt_FillUp(); // When called, it will proceed to the next stage.
            }
        }
        else if (FillUp_Stage == 1) // Next Stage
        /*
        Comments from the above is the same from these stages. Refer to FillUp_Stage == 0 Contents
        */
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
            // ADDRESS IS MAX PATH SIZE DUE TO LONG STRING NEEDED
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
            fflush(stdin); // Flushes \n on ScanF to prevent fgets to be skipped, on new versions, it is now handled as string
            // Due to limitations... As per now it is still needed because it is limited to 11 characters only. Going beyond causes overflow.
            SetCursorCoord_XY(30, 39);
            printf("\xAF [6] House Telephone Number");
            SetCursorCoord_XY(30, 41);
            printf("\xC8\xAF INPUT \xDD\xAF ");
            fgets(OnProcess_StudentData.stdnt_PhoneNum, sizeof(OnProcess_StudentData.stdnt_PhoneNum), stdin);
            strtok(OnProcess_StudentData.stdnt_PhoneNum, "\n");
            fflush(stdin); // Flushes \n on ScanF to prevent fgets to be skipped, on new versions, it is now handled as string
            // Due to limitations... As per now it is still needed because it is limited to 11 characters only. Going beyond causes overflow.
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
            if ((strlen(OnProcess_StudentData.stdnt_Gender) <= 2) || (strlen(OnProcess_StudentData.stdnt_Birthday) <= 2) || (strlen(OnProcess_StudentData.stdnt_Address) <= 2) || (strlen(OnProcess_StudentData.stdnt_Nationality) <= 2) || (strlen(OnProcess_StudentData.stdnt_MobileNum) <= 2) || (strlen(OnProcess_StudentData.stdnt_PhoneNum) <= 2) || (strlen(OnProcess_StudentData.stdnt_EmerNum) <= 2) || (strlen(OnProcess_StudentData.stdnt_POC_Emergency) <= 2))
            {
                SetCursorCoord_XY(30, 53);
                printf("\xAF \xDD ERROR \xDD One of the required input must contain 3 characters in order to continue...");
                getch();
                continue;
            }
            else
            {
                SetCursorCoord_XY(30, 53);
                printf("\xFE\xCD\xCD USER INPUT DONE FOR GENERAL INFORMATION \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
                FillUp_Stage++;
                Sleep(1500);
                Func_NewStdnt_FillUp();
            }
        }
        else if (FillUp_Stage == 2)
        /*
        Comments from the above is the same from these stages. Refer to FillUp_Stage == 0 Contents
        */
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
            if ((strlen(OnProcess_StudentData.stdnt_SourceInterest) <= 2) || (strlen(OnProcess_StudentData.stdnt_LastSchoolYear) <= 2) || (strlen(OnProcess_StudentData.stdnt_LastSchoolStrand) <= 2) || (strlen(OnProcess_StudentData.stdnt_Email) <= 2) || (strlen(OnProcess_StudentData.stdnt_SpecialBehavioral) <= 2))
            {
                SetCursorCoord_XY(30, 38);
                printf("\xAF \xDD ERROR \xDD One of the required input must contain 3 characters in order to continue...");
                getch();
                continue;
            }
            else
            {
                SetCursorCoord_XY(30, 38);
                printf("\xFE\xCD\xCD USER INPUT DONE \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
                FillUp_Stage = 0;
                Sleep(1500);
                Func_NewStdnt_InfoCheck();
            }
        }
        else
        {
            // These was intentional incase if the program is bugged at some point and the variable gets incremented than expected
            // it will still fall  to Func_NewStdnt_InfoCheck Function.
            Func_NewStdnt_InfoCheck();
        }
    }
}
// Func_NewStdnt_InfoCheck -> Data Validity
/*
NOTE: This was needed to make sure that future student knows what data to input.
CONS: Goes back to beginning of stages when one mistake found.
The flow of this kind of design can be changed, but as per time goes by. The developers intended to make it like this
due to the heavy workflow. Flow can be revisable which results to long code.
*/
void Func_NewStdnt_InfoCheck()
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
    printf("\xFE\xCD\xCD IDENTITY INFORMATION \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetCursorCoord_XY(30, 11);
    printf("\xAF [1] Enrollee's Name \xDD\xAF %s, %s %s", OnProcess_StudentData.stdnt_LName, OnProcess_StudentData.stdnt_GName, OnProcess_StudentData.stdnt_MName);
    SetCursorCoord_XY(30, 13);
    printf("\xAF [2] [ Parent ] Mother's Information \xAF %s \xDD %s \xDD %s", OnProcess_StudentData.stdnt_MothersName, OnProcess_StudentData.stdnt_MothersInfoJob, OnProcess_StudentData.stdnt_MothersInfoContact);
    SetCursorCoord_XY(30, 15);
    printf("\xAF [3] [ Parent ] Father's Information \xAF %s \xDD %s \xDD %s", OnProcess_StudentData.stdnt_FathersName, OnProcess_StudentData.stdnt_FathersInfoJob, OnProcess_StudentData.stdnt_FathersInfoContact);
    SetCursorCoord_XY(30, 17);
    printf("\xFE\xCD\xCD GENERAL INFORMATION \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetCursorCoord_XY(30, 19);
    printf("\xAF [4] Gender \xDD\xAF %s", OnProcess_StudentData.stdnt_Gender);
    SetCursorCoord_XY(30, 21);
    printf("\xAF [5] Birthday \xDD\xAF %s", OnProcess_StudentData.stdnt_Birthday);
    SetCursorCoord_XY(30, 23);
    printf("\xAF [6] Permanent Address");
    SetCursorCoord_XY(30, 25);
    printf("\xC8\xAF %s", OnProcess_StudentData.stdnt_Address);
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
    printf("\xC8\xAF Press a key that corresponds to your decision [|Y|es or |N|o] \xDD\xAF ");
    switch (getche())
    {
    case 'Y': // case Y will fall to case 'y' this method is somewhat makes the flow cleaner to look at.
    case 'y':
        SetCursorCoord_XY(30, 54);
        // Set Student Id as 0 already to let developers know that it is definitely a new student..
        OnProcess_StudentData.stdnt_StudentID = 0;
        printf("\xAF \xDD INFO \xDD Data Received, Proceeding to Step 2 \xDD Course Registration...");
        Sleep(1500);
        Func_NewStdnt_CourseReg();
    case 'N':
    case 'n':
        SetCursorCoord_XY(30, 54);
        printf("\xAF \xDD INFO \xDD Returning To Step 1 \xDD Filling up Personal Information...");
        Sleep(1500);
        Func_NewStdnt_FillUp();
    default:
        SetCursorCoord_XY(30, 54);
        printf("\xAF \xDD ERROR \xAF Sorry, I don't understand that...");
        Sleep(1500);
        Func_NewStdnt_InfoCheck();
    }
}

//Func_NewStdnt_CourseReg - Branch Course Selectors and Main Course Selectors
/*
NOTE: Old Student Skips this function...
On this function it introduces the char pointer of arrays which is a pointer of strings in defined size.
*/

void Func_NewStdnt_CourseReg()
{
    system("CLS");
    SetConsoleTitle(FUNCTION_STEP2);
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
    switch (getche())
    {
    case '1':
        SetCursorCoord_XY(30, 24);
        printf("\xAF \xDD INFO \xDD You have chosen 'College of Engineering' as a branch base course...");
        Sleep(1500);
        while (1)
        {
            // Menu for College of Engineering
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
            switch (getche())
            {
            case '1':
                SetCursorCoord_XY(30, 29);
                printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding To Step 2 of Part 3...", MainCourse_FullName[0]);
                Sleep(1500);
                // This Data Transport is one of the potential use of struct members.
                // Syntax: strcpy (Destination, Source) both char pointer
                strcpy(OnProcess_StudentData.MainCourse_CodeName_Passer, MainCourse_CodeName[0]);
                strcpy(OnProcess_StudentData.MainCourse_FullName_Passer, MainCourse_FullName[0]);
                Func_NewStdnt_YearSemSelect();
                break;
            case '2':
                SetCursorCoord_XY(30, 29);
                printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding To Step 2 of Part 3...", MainCourse_FullName[1]);
                Sleep(1500);
                // This Data Transport is one of the potential use of struct members.
                // Syntax: strcpy (Destination, Source) both char pointer
                strcpy(OnProcess_StudentData.MainCourse_CodeName_Passer, MainCourse_CodeName[1]);
                strcpy(OnProcess_StudentData.MainCourse_FullName_Passer, MainCourse_FullName[1]);
                Func_NewStdnt_YearSemSelect();
                break;
            case '3':
                SetCursorCoord_XY(30, 29);
                printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding To Step 2 of Part 3...", MainCourse_FullName[2]);
                Sleep(1500);
                // This Data Transport is one of the potential use of struct members.
                // Syntax: strcpy (Destination, Source) both char pointer
                strcpy(OnProcess_StudentData.MainCourse_CodeName_Passer, MainCourse_CodeName[2]);
                strcpy(OnProcess_StudentData.MainCourse_FullName_Passer, MainCourse_FullName[2]);
                Func_NewStdnt_YearSemSelect();
                break;
            case '4':
                SetCursorCoord_XY(30, 29);
                printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding To Step 2 of Part 3...", MainCourse_FullName[3]);
                Sleep(1500);
                // This Data Transport is one of the potential use of struct members.
                // Syntax: strcpy (Destination, Source) both char pointer
                strcpy(OnProcess_StudentData.MainCourse_CodeName_Passer, MainCourse_CodeName[3]);
                strcpy(OnProcess_StudentData.MainCourse_FullName_Passer, MainCourse_FullName[3]);
                Func_NewStdnt_YearSemSelect();
                break;
            case '5':
                SetCursorCoord_XY(30, 29);
                printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding To Step 2 of Part 3...", MainCourse_FullName[4]);
                Sleep(1500);
                // This Data Transport is one of the potential use of struct members.
                // Syntax: strcpy (Destination, Source) both char pointer
                strcpy(OnProcess_StudentData.MainCourse_CodeName_Passer, MainCourse_CodeName[4]);
                strcpy(OnProcess_StudentData.MainCourse_FullName_Passer, MainCourse_FullName[4]);
                Func_NewStdnt_YearSemSelect();
                break;
            case '6':
                SetCursorCoord_XY(30, 29);
                printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding To Step 2 of Part 3...", MainCourse_FullName[5]);
                Sleep(1500);
                // This Data Transport is one of the potential use of struct members.
                // Syntax: strcpy (Destination, Source) both char pointer
                strcpy(OnProcess_StudentData.MainCourse_CodeName_Passer, MainCourse_CodeName[5]);
                strcpy(OnProcess_StudentData.MainCourse_FullName_Passer, MainCourse_FullName[5]);
                Func_NewStdnt_YearSemSelect();
                break;
            case '7':
                SetCursorCoord_XY(30, 29);
                printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding To Step 2 of Part 3...", MainCourse_FullName[6]);
                Sleep(1500);
                // This Data Transport is one of the potential use of struct members.
                // Syntax: strcpy (Destination, Source) both char pointer
                strcpy(OnProcess_StudentData.MainCourse_CodeName_Passer, MainCourse_CodeName[6]);
                strcpy(OnProcess_StudentData.MainCourse_FullName_Passer, MainCourse_FullName[6]);
                Func_NewStdnt_YearSemSelect();
                break;
            default:
                SetCursorCoord_XY(30, 29);
                printf("\xAF \xDD ERROR \xAF Sorry, I don't understand that...");
                Sleep(1500);
                continue;
            }
        }
    case '2':
        SetCursorCoord_XY(30, 24);
        printf("\xAF \xDD INFO \xDD Architecture is basically indentified as a main course. Proceeding To Part 3 of Step 2...");
        Sleep(1500);
        // In Architecture, there are no main courses or sub. But the actual is the Architecture itself.
        strcpy(OnProcess_StudentData.MainCourse_CodeName_Passer, MainCourse_CodeName[7]);
        strcpy(OnProcess_StudentData.MainCourse_FullName_Passer, MainCourse_FullName[7]);
        Func_NewStdnt_YearSemSelect();
    default:
        SetCursorCoord_XY(30, 24);
        printf("\xAF \xDD ERROR \xAF Sorry, I don't understand that...");
        Sleep(1500);
        Func_NewStdnt_CourseReg();
    }
}
// Func_NewStdnt_YearSemSelect -> Same Scenario as Func_NewStdnt_CourseReg but Year Level and  Semester are being selected.
void Func_NewStdnt_YearSemSelect()
{
    system("CLS");
    SetConsoleTitle(FUNCTION_STEP2_1);
    int YearSelection_Accepter = 0,
        YearSelection_Accepter_Sem = 0;
    //Define Following to be dynamic data for transport.
    char *ERLM_Selection[5] = {"1st Year College", "2nd Year College", "3rd Year College", "4th Year College", "5th Year College"},
         *ERLM_Selection_Sem[2] = {"First Semester", "Second Semester"};
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
        printf(" \xDD\xAF Student Name \xAF %s, %s %s", OnProcess_StudentData.stdnt_LName, OnProcess_StudentData.stdnt_GName, OnProcess_StudentData.stdnt_MName);
        SetCursorCoord_XY(30, 13);
        printf(" \xDD\xAF Student Number \xAF %ld", OnProcess_StudentData.stdnt_StudentID);
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
        switch (getche())
        {
        case '1':
            YearSelection_Accepter = 0;
            SetCursorCoord_XY(30, 33);
            printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding to Step 2 of Part 4...", ERLM_Selection[YearSelection_Accepter]);
            Sleep(1500);
            break;
        case '2':
            YearSelection_Accepter = 1;
            SetCursorCoord_XY(30, 33);
            printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding to Step 2 of Part 4...", ERLM_Selection[YearSelection_Accepter]);
            Sleep(1500);
            break;
        case '3':
            YearSelection_Accepter = 2;
            SetCursorCoord_XY(30, 33);
            printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding to Step 2 of Part 4...", ERLM_Selection[YearSelection_Accepter]);
            Sleep(1500);
            break;
        case '4':
            YearSelection_Accepter = 3;
            SetCursorCoord_XY(30, 33);
            printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding to Step 2 of Part 4...", ERLM_Selection[YearSelection_Accepter]);
            Sleep(1500);
            break;
        case '5':
            YearSelection_Accepter = 4;
            SetCursorCoord_XY(30, 33);
            printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding to Step 2 of Part 4...", ERLM_Selection[YearSelection_Accepter]);
            Sleep(1500);
            break;
        default:
            SetCursorCoord_XY(30, 33);
            printf("\xAF \xDD ERROR \xDD Sorry, I don't understand that...");
            Sleep(1500);
            continue;
        }
        break;
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
        printf(" \xDD\xAF Student Name \xAF %s, %s %s", OnProcess_StudentData.stdnt_LName, OnProcess_StudentData.stdnt_GName, OnProcess_StudentData.stdnt_MName);
        SetCursorCoord_XY(30, 14);
        printf(" \xDD\xAF Student Number \xAF %ld", OnProcess_StudentData.stdnt_StudentID);
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
        switch (getche())
        {
        case '1':
            // At this point, Selections or Number that is being pressed should be taken. But since getche is string and developers
            // Have never checked the function called atoi or itoa. It was keeped like this.
            // It has been proposed before because array starts at 0 and so that is why when following numbers are pressed
            //  It will be - 1 to a variable received.
            YearSelection_Accepter_Sem = 0;
            SetCursorCoord_XY(30, 29);
            printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding to Step 2 of Part 5...", ERLM_Selection_Sem[YearSelection_Accepter_Sem]);
            Sleep(1500);
            break;
        case '2':
            SetCursorCoord_XY(30, 30);
            YearSelection_Accepter_Sem = 1;
            printf("\xAF \xDD INFO \xDD You have selected %s. Proceeding to Step 2 of Part 5...", ERLM_Selection_Sem[YearSelection_Accepter_Sem]);
            Sleep(1500);
            break;
        default:
            SetCursorCoord_XY(30, 30);
            printf("\xAF \xDD ERROR \xDD Sorry, I don't understand that...");
            Sleep(1500);
            continue;
        }
        break;
    }

    system("CLS");
    /*
This while loop part, loops only within when user input is invalid to the question.
It is another part of data check to avoid mistakes being corrected after enrollment process.
*/
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
        printf(" \xDD\xAF Student Name \xAF %s, %s %s", OnProcess_StudentData.stdnt_LName, OnProcess_StudentData.stdnt_GName, OnProcess_StudentData.stdnt_MName);
        SetCursorCoord_XY(30, 14);
        printf(" \xDD\xAF Student Number \xAF %ld", OnProcess_StudentData.stdnt_StudentID);
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
        printf("\xBA \xDD NOTE #1  \xDD If you are a newcoming student, default value of new students is zero\t\t\t   \xBA");
        SetCursorCoord_XY(30, 23);
        printf("\xBA \xDD NOTE #2  \xDD If you have mistakes, then you will have to reselect courses, year, semester again.\t   \xBA");
        SetCursorCoord_XY(30, 24);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        SetCursorCoord_XY(30, 25);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        SetCursorCoord_XY(30, 27);
        printf("\xC8\xAF Press a key that corresponds your decision [|Y|es or |N|o] \xDD\xAF ");
        switch (getche())
        {
        case 'Y': // case 'Y' falls to case 'y'
        case 'y':
            SetCursorCoord_XY(30, 29);
            printf("\xDD INFO \xDD Data Temporarily Recorded \xAF Processing Data..."); // Pass This Already in Struct to lessen the difficutly to check what to pass when User Press 3 on Subject Unit Selection Function
            SetCursorCoord_XY(30, 30);
            printf("\xDD SUCCESS \xDD Data Processed. Proceeding to Step 3 \xAF Subject Enrollment Selection");
            /*
            This two is being transported too eraly than transporting at the final steps.
            This was meant to avoid confusion if the data is being transported in a proper way.
            */
            strcpy(OnProcess_StudentData.Course_YearChoice, ERLM_Selection[YearSelection_Accepter]);
            strcpy(OnProcess_StudentData.Course_SemSelection, ERLM_Selection_Sem[YearSelection_Accepter_Sem]);
            Sleep(1800);

            /*
            THIS PART INCLUDES MORE THAN 64 COMPARISONS FOR WHICH TO KNOW WHAT DATA TO BE SENT
            THIS PART WAS KNOWN TO BE EFFECTIVE THAN STATIC ONE AS IT DECREASE THE CODE TO 80%. IN THE TIME OF CREATION FOR EACH
            THE TOTAL LINES WAS UP TO 6000+++ LINE OF CODE...

           For readibility, there are identions to which part of the code is intended to be part of.
           First step, it checks the course codename passed
                Second Step is the year college to be checked
                    Third Part is Semester to be checked

            NOTE: THE FOLLOWING CHAR POINTTER ARRAY
            -- AS OBSERVERS (YOU) NOTICED, WE ARE GIVING DATA THAT IS NOT EXACTLY AS IT MEANT TO BE
            For Example: Give 8 datas while char is usually at 12 size
            The remaining four is being treated as unknown to the next function. Refer to the next function for more information....

           */
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
                        // Function was called with parameters to be delivered, all is double pointer when passed and units are passes to 12 datas only...
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
                        Func_SubjectUnit_Selection(Subject_CodeName, Subject_FullName, Subject_LinearTime, Subject_Units);
                    }
                }
            }
            else
            {
                /*
                LEAD DEVELOPER'S NOTE: THIS WAS MEANT TO BE JOKE OR SOMEWHAT Unexpectating Result.
                The only cause of this one is from the Data that is added manually from the Management Mode...
                If syntax wasnt followed, then there is a probably that it wasn't parsed to the list of if and else conditions.
                Hence it will unknown for the program or doesnt understand what it was.
                Displaying this will result into a problem and cause termination of a program.
                It will never be going back to Main Menu just to make sure that managers of this program would resolve it.
                This would be impossible to happen when New Student Process was being taken.
                */
                system("CLS");
                printf("Houston! We have a problem!\n");
                printf("There is no way that this system returns false for each comparision for more than 64+!\n This is a bug! Please report to the developer immediately!!!\n");
                printf("For Manual Override of Data, Please Delete and Redo with Proper Naming of Course Code Again!!!\n");
                exit(FUNCTION_LINEAR_DISCONTINUE); // Calls Exit Code When More than 64+ Comparison returns false.
            }
        case 'N':
        case 'n':
            SetCursorCoord_XY(30, 29);
            printf("\xAF \xDD INFO \xDD Reinitializing function to go back...");
            Sleep(1500);
            Func_NewStdnt_YearSemSelect();
            break;
        default:
            SetCursorCoord_XY(30, 29);
            printf("\xAF \xDD ERROR \xDD Sorry, I don't understand that...");
            Sleep(1500);
            continue;
        }
        break;
    }
}
/*
WARNING: CONTAINS ALOT OF FUNCTIONS WITH MINIMAL COMMENT TO AVOID OVERFLOW
THIS WAS THE PURE AND ALMOST SECURED FUNCTION WHEN IN THE PROCESS OF DEVELOPING THE SYSTEM.
CERTAIN INFORMATION ARE COMMENTED FOR REASONS, PLEASE REFER TO THOSE BELOW.
*/
void Func_SubjectUnit_Selection(char **Subject_CodeName, char **Subject_FullName, char **Subject_LinearTime, int Subject_Units[12])
{
    system("CLS");
    SetConsoleTitle(FUNCTION_STEP3);
    int Subject_Selector = 0,                               // Used for choosing subjects
        Option_Selector = 0,                                // Used for selecting options indicated from 1 to 6
        Final_Comp_SelectedSubjects = 0,                    // Shows Current Selected Subject
        Final_Comp_SemUnits = 0,                            // Shows All Units Computed
        Subject_Selection_Checker,                          // Used as a Value of Array to Process Subjects that are Included, Excluded and Unknown
        Transport_Element = 0,                              // A Variable that is used to as a array element for passing data to struct containing 12 elements for each
        Subject_UnitsGuard_AntiDuplicate_Include[12] = {0}, // Initialized for Assurance of Not Getting Corrupted... Used for Anti Selecting when it was already selected
        Subject_UnitsGuard_AntiDuplicate_Exclude[12] = {0}, // Initialized for Assurance of Not Getting Corrupted... Used for Anti Selecting when it was already selected
        Nullifier_Parameter[12] = {0},                      // It is a set that contains only value of 0 or 1, it is a blocker used for selecting NULL contents which is not really recommended to select into.
        Setup_Counter = 0,                                  // Used as an Array Element to Setup Elements that are NULL.
        Subject_ExpectedCandidates = 0,                     // Used as a counter for counting subjects passed by the previous function.
        Subject_ExpectedSemUnits = 0,// Used as a counter for counting semester passed by the previous function.
        Sizeof_SemSelection = strlen(OnProcess_StudentData.Course_SemSelection),// These checks character count and it was being pass to the pointer of printf width limiter.
        Sizeof_YearChoice = strlen(OnProcess_StudentData.Course_YearChoice),// These checks character count and it was being pass to the pointer of printf width limiter.
        Sizeof_FullNamePasser = strlen(OnProcess_StudentData.MainCourse_FullName_Passer); // These checks character count and it was being pass to the pointer of printf width limiter.
    char Final_Decision_Selector;                                                         // Variable that is responsible for confirmation for leaving the function. Used traditional conditional than case scenario.
    /*
    The Four Char Pointer Array is a set of placeholders that are not being passed by the previous function. Hence those are static and does not change the value no matter what selections are passed.
    */
    char *Subject_Parameters[2] = {"Include", "Exclude"};
    char *Subject_Status[12] = {"Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown"};
    char *Subject_Include[12] = {"Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown"};
    // Subject_ScheduleDay is based on Project Leader's Schedule
    char *Subject_ScheduleDay[12] = {"MoWeFr", "Tu", "MoSat", "MoWeFr", "We", "Th", "MoweFr", "TuTh", "TuTh", "FrSat", "We", "Sat"};
    // For command that assigns NULL Pointer Elements to the following strings.
    for (Setup_Counter = 0; Setup_Counter <= 11; Setup_Counter++)
    { // Setup_Counter cannot be at 12 because it is already set for null terminating character hence data starts at 0 and ends at 11
        if ((Subject_CodeName[Setup_Counter] == NULL) || (Subject_FullName[Setup_Counter] == NULL))
        {
            Subject_CodeName[Setup_Counter] = "NONE";
            Subject_FullName[Setup_Counter] = "NOT AVAILABLE";
            Subject_LinearTime[Setup_Counter] = "N/A - N/A";
            Subject_ScheduleDay[Setup_Counter] = "N/A";
            Subject_Units[Setup_Counter] = 0;
            Nullifier_Parameter[Setup_Counter] = 1; // Nulifier sets 1 as true to be not allowed to use
        }
        // Let program calculate non-null element arrays to count for subject_whole size.
        else if ((Subject_CodeName[Setup_Counter] != NULL) || (Subject_FullName[Setup_Counter] != NULL))
        {
            Nullifier_Parameter[Setup_Counter] = 0; // Selectable as it was false.
            Subject_ExpectedCandidates += 1;
            Subject_ExpectedSemUnits += Subject_Units[Setup_Counter]; // Calculate Semester Units
        }
    }

    /*
Show Interface
%-[Value][Format] - Left to Right Alignment - ALlocates expected space by the value
%[Value][Format] - Right to Left Alignment - ALlocates expected space by the value
*/
    while (1)
    {
        //Looping Variables Will Be Reinitialized Here
        int Sbj_Stats_Increment = 0,           // Used To Increment Variables When Selecting "Include All Subjects", Goes back to zero for reusing the function as it also binds as an array element.
            Sbj_Stats_Decrement = 0,           // Used To Decrement Variables When Selecting "Exclude All Subjects", Goes back to zero for reusing the function as it also binds as an array element.
            Subject_Receive_Exclude_Count = 0, // Used to Count Exclude and Unknown Selections, there are limitations passed when all is indicated as excluded or unknonwn, it prohibits the user.
            Subject_Receive_Unknown_Count = 0; // Used to Count Exclude and Unknown Selections, there are limitations passed when all is indicated as excluded or unknonwn, it prohibits the user.
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
                // Checks if Nulifier_Parameter is set to 1. If it was set, it was not available. Nullifier_Parameter is already set at Setup Part. So it cannot be changed when output shows up.
                //NOTE: Array -1 because Subject_Selector is part of the choice as it being taken as well. Ex. If pressed 1, the result would be 0 which takes 0th element of the array.
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    Sleep(1000);
                    continue;
                }
                else
                { // Checks Anti Duplicated Guard, it's purpose was to block if it was already included, it will be available if excluded or unknown.
                    if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0; // Set Exclude To Be Available To Use from this element.
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1; // Set Include To Be Disabled after it allows, one time.
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[0];       // Set Status of the Element In Line to Include.
                        Final_Comp_SelectedSubjects += 1;                                   // Increment as Included by Adding One to Selected Subjects.
                        Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];         // Add Value Corresponding to Array in this variable.
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 2)
            {
                // Checks if Nulifier_Parameter is set to 1. If it was set, it was not available. Nullifier_Parameter is already set at Setup Part. So it cannot be changed when output shows up.
                //NOTE: Array -1 because Subject_Selector is part of the choice as it being taken as well. Ex. If pressed 1, the result would be 0 which takes 0th element of the array.
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    Sleep(1000);
                    continue;
                }
                else
                { // Checks Anti Duplicated Guard, it's purpose was to block if it was already included, it will be available if excluded or unknown.
                    if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0; // Set Exclude To Be Available To Use from this element.
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1; // Set Include To Be Disabled after it allows, one time.
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[0];       // Set Status of the Element In Line to Include.
                        Final_Comp_SelectedSubjects += 1;                                   // Increment as Included by Adding One to Selected Subjects.
                        Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];         // Add Value Corresponding to Array in this variable.
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 3)
            {
                // Checks if Nulifier_Parameter is set to 1. If it was set, it was not available. Nullifier_Parameter is already set at Setup Part. So it cannot be changed when output shows up.
                //NOTE: Array -1 because Subject_Selector is part of the choice as it being taken as well. Ex. If pressed 1, the result would be 0 which takes 0th element of the array.
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    Sleep(1000);
                    continue;
                }
                else
                { // Checks Anti Duplicated Guard, it's purpose was to block if it was already included, it will be available if excluded or unknown.
                    if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0; // Set Exclude To Be Available To Use from this element.
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1; // Set Include To Be Disabled after it allows, one time.
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[0];       // Set Status of the Element In Line to Include.
                        Final_Comp_SelectedSubjects += 1;                                   // Increment as Included by Adding One to Selected Subjects.
                        Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];         // Add Value Corresponding to Array in this variable.
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 4)
            {
                // Checks if Nulifier_Parameter is set to 1. If it was set, it was not available. Nullifier_Parameter is already set at Setup Part. So it cannot be changed when output shows up.
                //NOTE: Array -1 because Subject_Selector is part of the choice as it being taken as well. Ex. If pressed 1, the result would be 0 which takes 0th element of the array.
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    Sleep(1000);
                    continue;
                }
                else
                { // Checks Anti Duplicated Guard, it's purpose was to block if it was already included, it will be available if excluded or unknown.
                    if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0; // Set Exclude To Be Available To Use from this element.
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1; // Set Include To Be Disabled after it allows, one time.
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[0];       // Set Status of the Element In Line to Include.
                        Final_Comp_SelectedSubjects += 1;                                   // Increment as Included by Adding One to Selected Subjects.
                        Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];         // Add Value Corresponding to Array in this variable.
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 5)
            {
                // Checks if Nulifier_Parameter is set to 1. If it was set, it was not available. Nullifier_Parameter is already set at Setup Part. So it cannot be changed when output shows up.
                //NOTE: Array -1 because Subject_Selector is part of the choice as it being taken as well. Ex. If pressed 1, the result would be 0 which takes 0th element of the array.
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    Sleep(1000);
                    continue;
                }
                else
                { // Checks Anti Duplicated Guard, it's purpose was to block if it was already included, it will be available if excluded or unknown.
                    if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0; // Set Exclude To Be Available To Use from this element.
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1; // Set Include To Be Disabled after it allows, one time.
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[0];       // Set Status of the Element In Line to Include.
                        Final_Comp_SelectedSubjects += 1;                                   // Increment as Included by Adding One to Selected Subjects.
                        Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];         // Add Value Corresponding to Array in this variable.
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 6)
            {
                // Checks if Nulifier_Parameter is set to 1. If it was set, it was not available. Nullifier_Parameter is already set at Setup Part. So it cannot be changed when output shows up.
                //NOTE: Array -1 because Subject_Selector is part of the choice as it being taken as well. Ex. If pressed 1, the result would be 0 which takes 0th element of the array.
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    Sleep(1000);
                    continue;
                }
                else
                { // Checks Anti Duplicated Guard, it's purpose was to block if it was already included, it will be available if excluded or unknown.
                    if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0; // Set Exclude To Be Available To Use from this element.
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1; // Set Include To Be Disabled after it allows, one time.
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[0];       // Set Status of the Element In Line to Include.
                        Final_Comp_SelectedSubjects += 1;                                   // Increment as Included by Adding One to Selected Subjects.
                        Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];         // Add Value Corresponding to Array in this variable.
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 7)
            {
                // Checks if Nulifier_Parameter is set to 1. If it was set, it was not available. Nullifier_Parameter is already set at Setup Part. So it cannot be changed when output shows up.
                //NOTE: Array -1 because Subject_Selector is part of the choice as it being taken as well. Ex. If pressed 1, the result would be 0 which takes 0th element of the array.
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    Sleep(1000);
                    continue;
                }
                else
                { // Checks Anti Duplicated Guard, it's purpose was to block if it was already included, it will be available if excluded or unknown.
                    if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0; // Set Exclude To Be Available To Use from this element.
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1; // Set Include To Be Disabled after it allows, one time.
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[0];       // Set Status of the Element In Line to Include.
                        Final_Comp_SelectedSubjects += 1;                                   // Increment as Included by Adding One to Selected Subjects.
                        Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];         // Add Value Corresponding to Array in this variable.
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 8)
            {
                // Checks if Nulifier_Parameter is set to 1. If it was set, it was not available. Nullifier_Parameter is already set at Setup Part. So it cannot be changed when output shows up.
                //NOTE: Array -1 because Subject_Selector is part of the choice as it being taken as well. Ex. If pressed 1, the result would be 0 which takes 0th element of the array.
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    Sleep(1000);
                    continue;
                }
                else
                { // Checks Anti Duplicated Guard, it's purpose was to block if it was already included, it will be available if excluded or unknown.
                    if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0; // Set Exclude To Be Available To Use from this element.
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1; // Set Include To Be Disabled after it allows, one time.
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[0];       // Set Status of the Element In Line to Include.
                        Final_Comp_SelectedSubjects += 1;                                   // Increment as Included by Adding One to Selected Subjects.
                        Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];         // Add Value Corresponding to Array in this variable.
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 9)
            {
                // Checks if Nulifier_Parameter is set to 1. If it was set, it was not available. Nullifier_Parameter is already set at Setup Part. So it cannot be changed when output shows up.
                //NOTE: Array -1 because Subject_Selector is part of the choice as it being taken as well. Ex. If pressed 1, the result would be 0 which takes 0th element of the array.
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    Sleep(1000);
                    continue;
                }
                else
                { // Checks Anti Duplicated Guard, it's purpose was to block if it was already included, it will be available if excluded or unknown.
                    if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0; // Set Exclude To Be Available To Use from this element.
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1; // Set Include To Be Disabled after it allows, one time.
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[0];       // Set Status of the Element In Line to Include.
                        Final_Comp_SelectedSubjects += 1;                                   // Increment as Included by Adding One to Selected Subjects.
                        Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];         // Add Value Corresponding to Array in this variable.
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 10)
            {
                // Checks if Nulifier_Parameter is set to 1. If it was set, it was not available. Nullifier_Parameter is already set at Setup Part. So it cannot be changed when output shows up.
                //NOTE: Array -1 because Subject_Selector is part of the choice as it being taken as well. Ex. If pressed 1, the result would be 0 which takes 0th element of the array.
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    Sleep(1000);
                    continue;
                }
                else
                { // Checks Anti Duplicated Guard, it's purpose was to block if it was already included, it will be available if excluded or unknown.
                    if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0; // Set Exclude To Be Available To Use from this element.
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1; // Set Include To Be Disabled after it allows, one time.
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[0];       // Set Status of the Element In Line to Include.
                        Final_Comp_SelectedSubjects += 1;                                   // Increment as Included by Adding One to Selected Subjects.
                        Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];         // Add Value Corresponding to Array in this variable.
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 11)
            {
                // Checks if Nulifier_Parameter is set to 1. If it was set, it was not available. Nullifier_Parameter is already set at Setup Part. So it cannot be changed when output shows up.
                //NOTE: Array -1 because Subject_Selector is part of the choice as it being taken as well. Ex. If pressed 1, the result would be 0 which takes 0th element of the array.
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    Sleep(1000);
                    continue;
                }
                else
                { // Checks Anti Duplicated Guard, it's purpose was to block if it was already included, it will be available if excluded or unknown.
                    if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0; // Set Exclude To Be Available To Use from this element.
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1; // Set Include To Be Disabled after it allows, one time.
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[0];       // Set Status of the Element In Line to Include.
                        Final_Comp_SelectedSubjects += 1;                                   // Increment as Included by Adding One to Selected Subjects.
                        Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];         // Add Value Corresponding to Array in this variable.
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 12)
            {
                // Checks if Nulifier_Parameter is set to 1. If it was set, it was not available. Nullifier_Parameter is already set at Setup Part. So it cannot be changed when output shows up.
                //NOTE: Array -1 because Subject_Selector is part of the choice as it being taken as well. Ex. If pressed 1, the result would be 0 which takes 0th element of the array.
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    Sleep(1000);
                    continue;
                }
                else
                { // Checks Anti Duplicated Guard, it's purpose was to block if it was already included, it will be available if excluded or unknown.
                    if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0; // Set Exclude To Be Available To Use from this element.
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1; // Set Include To Be Disabled after it allows, one time.
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[0];       // Set Status of the Element In Line to Include.
                        Final_Comp_SelectedSubjects += 1;                                   // Increment as Included by Adding One to Selected Subjects.
                        Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];         // Add Value Corresponding to Array in this variable.
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                    else
                    {
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                }
            }
            else
            {
                SetCursorCoord_XY(20, 48);
                printf("\xDD WARNING \xAF You have inputted a wrong number! Out of Choice.Bonds! Reinitialing Function...");
                Sleep(1500);
                continue;
            }
        }
        else if (Option_Selector == 2)
        {
            //Part of Opposite of Included. Excluded Functions
            SetCursorCoord_XY(20, 47);
            printf("\xC8\xAF \xDD QUESTION \xDDPlease select the subject number to be excluded \xAF ");
            scanf("%d", &Subject_Selector);
            if (Subject_Selector == 1)
            { // Same Scenario, Check if Nulifier, Nulifies this option, if it is we are unable to select this one.
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    Sleep(1000);
                    continue;
                }
                else
                { // Checks if AntiDuplicate_Exclude has been set to 0, if it is we are allowed to exclude, else not.
                    if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1; // Set Exclude to be Disabled to use.
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0; // Set Include to be Used again.
                        if (Final_Comp_SelectedSubjects == 0)
                        {
                            //Conditional Note: This Variable Below is not unsigned, in any case, it will probably go to -1. to fix this, we added if it was already zero then make it really zero without decrementing but declare it as zero.
                            Final_Comp_SelectedSubjects = 0;
                        }
                        else
                        {
                            // If it wasn't zero then we are allowed to Decrement it by 1.
                            Final_Comp_SelectedSubjects -= 1;
                        }
                        if (Final_Comp_SemUnits == 0)
                        {
                            //Same Conditionals Note as Selected Subjects
                            Final_Comp_SemUnits = 0;
                        }
                        else
                        {
                            Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                        }
                        //Set Status to Excluded as it was excluded
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i \xDD '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                    else
                    {
                        // Effected when AntiGuard_Exclude was set to 1
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i \xDD '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 2)
            { // Same Scenario, Check if Nulifier, Nulifies this option, if it is we are unable to select this one.
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    Sleep(1000);
                    continue;
                }
                else
                { // Checks if AntiDuplicate_Exclude has been set to 0, if it is we are allowed to exclude, else not.
                    if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1; // Set Exclude to be Disabled to use.
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0; // Set Include to be Used again.
                        if (Final_Comp_SelectedSubjects == 0)
                        {
                            //Conditional Note: This Variable Below is not unsigned, in any case, it will probably go to -1. to fix this, we added if it was already zero then make it really zero without decrementing but declare it as zero.
                            Final_Comp_SelectedSubjects = 0;
                        }
                        else
                        {
                            // If it wasn't zero then we are allowed to Decrement it by 1.
                            Final_Comp_SelectedSubjects -= 1;
                        }
                        if (Final_Comp_SemUnits == 0)
                        {
                            //Same Conditionals Note as Selected Subjects
                            Final_Comp_SemUnits = 0;
                        }
                        else
                        {
                            Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                        }
                        //Set Status to Excluded as it was excluded
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i \xDD '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                    else
                    {
                        // Effected when AntiGuard_Exclude was set to 1
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i \xDD '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 3)
            { // Same Scenario, Check if Nulifier, Nulifies this option, if it is we are unable to select this one.
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    Sleep(1000);
                    continue;
                }
                else
                { // Checks if AntiDuplicate_Exclude has been set to 0, if it is we are allowed to exclude, else not.
                    if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1; // Set Exclude to be Disabled to use.
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0; // Set Include to be Used again.
                        if (Final_Comp_SelectedSubjects == 0)
                        {
                            //Conditional Note: This Variable Below is not unsigned, in any case, it will probably go to -1. to fix this, we added if it was already zero then make it really zero without decrementing but declare it as zero.
                            Final_Comp_SelectedSubjects = 0;
                        }
                        else
                        {
                            // If it wasn't zero then we are allowed to Decrement it by 1.
                            Final_Comp_SelectedSubjects -= 1;
                        }
                        if (Final_Comp_SemUnits == 0)
                        {
                            //Same Conditionals Note as Selected Subjects
                            Final_Comp_SemUnits = 0;
                        }
                        else
                        {
                            Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                        }
                        //Set Status to Excluded as it was excluded
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i \xDD '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                    else
                    {
                        // Effected when AntiGuard_Exclude was set to 1
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i \xDD '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 4)
            { // Same Scenario, Check if Nulifier, Nulifies this option, if it is we are unable to select this one.
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    Sleep(1000);
                    continue;
                }
                else
                { // Checks if AntiDuplicate_Exclude has been set to 0, if it is we are allowed to exclude, else not.
                    if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1; // Set Exclude to be Disabled to use.
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0; // Set Include to be Used again.
                        if (Final_Comp_SelectedSubjects == 0)
                        {
                            //Conditional Note: This Variable Below is not unsigned, in any case, it will probably go to -1. to fix this, we added if it was already zero then make it really zero without decrementing but declare it as zero.
                            Final_Comp_SelectedSubjects = 0;
                        }
                        else
                        {
                            // If it wasn't zero then we are allowed to Decrement it by 1.
                            Final_Comp_SelectedSubjects -= 1;
                        }
                        if (Final_Comp_SemUnits == 0)
                        {
                            //Same Conditionals Note as Selected Subjects
                            Final_Comp_SemUnits = 0;
                        }
                        else
                        {
                            Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                        }
                        //Set Status to Excluded as it was excluded
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i \xDD '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                    else
                    {
                        // Effected when AntiGuard_Exclude was set to 1
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i \xDD '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 5)
            { // Same Scenario, Check if Nulifier, Nulifies this option, if it is we are unable to select this one.
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    Sleep(1000);
                    continue;
                }
                else
                { // Checks if AntiDuplicate_Exclude has been set to 0, if it is we are allowed to exclude, else not.
                    if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1; // Set Exclude to be Disabled to use.
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0; // Set Include to be Used again.
                        if (Final_Comp_SelectedSubjects == 0)
                        {
                            //Conditional Note: This Variable Below is not unsigned, in any case, it will probably go to -1. to fix this, we added if it was already zero then make it really zero without decrementing but declare it as zero.
                            Final_Comp_SelectedSubjects = 0;
                        }
                        else
                        {
                            // If it wasn't zero then we are allowed to Decrement it by 1.
                            Final_Comp_SelectedSubjects -= 1;
                        }
                        if (Final_Comp_SemUnits == 0)
                        {
                            //Same Conditionals Note as Selected Subjects
                            Final_Comp_SemUnits = 0;
                        }
                        else
                        {
                            Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                        }
                        //Set Status to Excluded as it was excluded
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i \xDD '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                    else
                    {
                        // Effected when AntiGuard_Exclude was set to 1
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i \xDD '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 6)
            { // Same Scenario, Check if Nulifier, Nulifies this option, if it is we are unable to select this one.
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    Sleep(1000);
                    continue;
                }
                else
                { // Checks if AntiDuplicate_Exclude has been set to 0, if it is we are allowed to exclude, else not.
                    if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1; // Set Exclude to be Disabled to use.
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0; // Set Include to be Used again.
                        if (Final_Comp_SelectedSubjects == 0)
                        {
                            //Conditional Note: This Variable Below is not unsigned, in any case, it will probably go to -1. to fix this, we added if it was already zero then make it really zero without decrementing but declare it as zero.
                            Final_Comp_SelectedSubjects = 0;
                        }
                        else
                        {
                            // If it wasn't zero then we are allowed to Decrement it by 1.
                            Final_Comp_SelectedSubjects -= 1;
                        }
                        if (Final_Comp_SemUnits == 0)
                        {
                            //Same Conditionals Note as Selected Subjects
                            Final_Comp_SemUnits = 0;
                        }
                        else
                        {
                            Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                        }
                        //Set Status to Excluded as it was excluded
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i \xDD '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                    else
                    {
                        // Effected when AntiGuard_Exclude was set to 1
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i \xDD '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 7)
            { // Same Scenario, Check if Nulifier, Nulifies this option, if it is we are unable to select this one.
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    Sleep(1000);
                    continue;
                }
                else
                { // Checks if AntiDuplicate_Exclude has been set to 0, if it is we are allowed to exclude, else not.
                    if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1; // Set Exclude to be Disabled to use.
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0; // Set Include to be Used again.
                        if (Final_Comp_SelectedSubjects == 0)
                        {
                            //Conditional Note: This Variable Below is not unsigned, in any case, it will probably go to -1. to fix this, we added if it was already zero then make it really zero without decrementing but declare it as zero.
                            Final_Comp_SelectedSubjects = 0;
                        }
                        else
                        {
                            // If it wasn't zero then we are allowed to Decrement it by 1.
                            Final_Comp_SelectedSubjects -= 1;
                        }
                        if (Final_Comp_SemUnits == 0)
                        {
                            //Same Conditionals Note as Selected Subjects
                            Final_Comp_SemUnits = 0;
                        }
                        else
                        {
                            Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                        }
                        //Set Status to Excluded as it was excluded
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i \xDD '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                    else
                    {
                        // Effected when AntiGuard_Exclude was set to 1
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i \xDD '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 8)
            { // Same Scenario, Check if Nulifier, Nulifies this option, if it is we are unable to select this one.
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    Sleep(1000);
                    continue;
                }
                else
                { // Checks if AntiDuplicate_Exclude has been set to 0, if it is we are allowed to exclude, else not.
                    if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1; // Set Exclude to be Disabled to use.
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0; // Set Include to be Used again.
                        if (Final_Comp_SelectedSubjects == 0)
                        {
                            //Conditional Note: This Variable Below is not unsigned, in any case, it will probably go to -1. to fix this, we added if it was already zero then make it really zero without decrementing but declare it as zero.
                            Final_Comp_SelectedSubjects = 0;
                        }
                        else
                        {
                            // If it wasn't zero then we are allowed to Decrement it by 1.
                            Final_Comp_SelectedSubjects -= 1;
                        }
                        if (Final_Comp_SemUnits == 0)
                        {
                            //Same Conditionals Note as Selected Subjects
                            Final_Comp_SemUnits = 0;
                        }
                        else
                        {
                            Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                        }
                        //Set Status to Excluded as it was excluded
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i \xDD '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                    else
                    {
                        // Effected when AntiGuard_Exclude was set to 1
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i \xDD '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 9)
            { // Same Scenario, Check if Nulifier, Nulifies this option, if it is we are unable to select this one.
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    Sleep(1000);
                    continue;
                }
                else
                { // Checks if AntiDuplicate_Exclude has been set to 0, if it is we are allowed to exclude, else not.
                    if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1; // Set Exclude to be Disabled to use.
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0; // Set Include to be Used again.
                        if (Final_Comp_SelectedSubjects == 0)
                        {
                            //Conditional Note: This Variable Below is not unsigned, in any case, it will probably go to -1. to fix this, we added if it was already zero then make it really zero without decrementing but declare it as zero.
                            Final_Comp_SelectedSubjects = 0;
                        }
                        else
                        {
                            // If it wasn't zero then we are allowed to Decrement it by 1.
                            Final_Comp_SelectedSubjects -= 1;
                        }
                        if (Final_Comp_SemUnits == 0)
                        {
                            //Same Conditionals Note as Selected Subjects
                            Final_Comp_SemUnits = 0;
                        }
                        else
                        {
                            Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                        }
                        //Set Status to Excluded as it was excluded
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i \xDD '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                    else
                    {
                        // Effected when AntiGuard_Exclude was set to 1
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i \xDD '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 10)
            { // Same Scenario, Check if Nulifier, Nulifies this option, if it is we are unable to select this one.
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    Sleep(1000);
                    continue;
                }
                else
                { // Checks if AntiDuplicate_Exclude has been set to 0, if it is we are allowed to exclude, else not.
                    if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1; // Set Exclude to be Disabled to use.
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0; // Set Include to be Used again.
                        if (Final_Comp_SelectedSubjects == 0)
                        {
                            //Conditional Note: This Variable Below is not unsigned, in any case, it will probably go to -1. to fix this, we added if it was already zero then make it really zero without decrementing but declare it as zero.
                            Final_Comp_SelectedSubjects = 0;
                        }
                        else
                        {
                            // If it wasn't zero then we are allowed to Decrement it by 1.
                            Final_Comp_SelectedSubjects -= 1;
                        }
                        if (Final_Comp_SemUnits == 0)
                        {
                            //Same Conditionals Note as Selected Subjects
                            Final_Comp_SemUnits = 0;
                        }
                        else
                        {
                            Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                        }
                        //Set Status to Excluded as it was excluded
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i \xDD '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                    else
                    {
                        // Effected when AntiGuard_Exclude was set to 1
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i \xDD '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 11)
            { // Same Scenario, Check if Nulifier, Nulifies this option, if it is we are unable to select this one.
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    Sleep(1000);
                    continue;
                }
                else
                { // Checks if AntiDuplicate_Exclude has been set to 0, if it is we are allowed to exclude, else not.
                    if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1; // Set Exclude to be Disabled to use.
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0; // Set Include to be Used again.
                        if (Final_Comp_SelectedSubjects == 0)
                        {
                            //Conditional Note: This Variable Below is not unsigned, in any case, it will probably go to -1. to fix this, we added if it was already zero then make it really zero without decrementing but declare it as zero.
                            Final_Comp_SelectedSubjects = 0;
                        }
                        else
                        {
                            // If it wasn't zero then we are allowed to Decrement it by 1.
                            Final_Comp_SelectedSubjects -= 1;
                        }
                        if (Final_Comp_SemUnits == 0)
                        {
                            //Same Conditionals Note as Selected Subjects
                            Final_Comp_SemUnits = 0;
                        }
                        else
                        {
                            Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                        }
                        //Set Status to Excluded as it was excluded
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i \xDD '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                    else
                    {
                        // Effected when AntiGuard_Exclude was set to 1
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i \xDD '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                }
            }
            else if (Subject_Selector == 12)
            { // Same Scenario, Check if Nulifier, Nulifies this option, if it is we are unable to select this one.
                if (Nullifier_Parameter[Subject_Selector - 1] == 1)
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xC8\xAF \xDD QUESTION \xDD You cannot select this option!");
                    Sleep(1000);
                    continue;
                }
                else
                { // Checks if AntiDuplicate_Exclude has been set to 0, if it is we are allowed to exclude, else not.
                    if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                    {
                        Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1; // Set Exclude to be Disabled to use.
                        Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0; // Set Include to be Used again.
                        if (Final_Comp_SelectedSubjects == 0)
                        {
                            //Conditional Note: This Variable Below is not unsigned, in any case, it will probably go to -1. to fix this, we added if it was already zero then make it really zero without decrementing but declare it as zero.
                            Final_Comp_SelectedSubjects = 0;
                        }
                        else
                        {
                            // If it wasn't zero then we are allowed to Decrement it by 1.
                            Final_Comp_SelectedSubjects -= 1;
                        }
                        if (Final_Comp_SemUnits == 0)
                        {
                            //Same Conditionals Note as Selected Subjects
                            Final_Comp_SemUnits = 0;
                        }
                        else
                        {
                            Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                        }
                        //Set Status to Excluded as it was excluded
                        Subject_Status[Subject_Selector - 1] = Subject_Parameters[1];
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD SUCCESS \xDD Subject #%i \xDD '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                    else
                    {
                        // Effected when AntiGuard_Exclude was set to 1
                        SetCursorCoord_XY(20, 48);
                        printf("\xC8\xAF \xDD ERROR \xDD Subject #%i \xDD '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                        Sleep(500);
                        continue;
                    }
                }
            }
        }
        else if (Option_Selector == 3)
        {
            fflush(stdin);
            // Final Stage Part...
            while (1)
            {
                SetCursorCoord_XY(20, 47);
                printf("\xDD QUESTION \xAF Are you sure that you picked the subjects that you wanted to take???");
                SetCursorCoord_XY(20, 48);
                printf("\xDD Pick your choice \xAF [Y]es or [N]o \xAF ");
                // We never used switch case here, there are lots of conditional to be checkd as it was not meant for checking if value is 'y' or not.
                Final_Decision_Selector = getche();
                if ((Final_Decision_Selector == 'Y') || (Final_Decision_Selector == 'y'))
                {
                    // If user wants to process the data then check for Subject_Status by incrementing elements if some parts are valid to Exclude and Unknown
                    // They are going to be used for comparison if those meet the requirements.
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
                    // If Subjects are all excluded and equal to ExpectedCandidates, show an error.
                    if (Subject_Receive_Exclude_Count == Subject_ExpectedCandidates)
                    {
                        SetCursorCoord_XY(20, 48);
                        // Definitely not allowed, as you are not trying to enroll at this point...
                        printf("\xDD ERROR \xAF You cannot set all subject/s to be 'Exclude'. Are you trying to enroll without subjects!?");
                        Sleep(5000);
                        break;
                    }
                    // This concludes that Unknown Count was higher and as per said, They are not allowed to enroll with Unknown Status, except for Nulified Status.
                    else if (Subject_Receive_Exclude_Count < Subject_Receive_Unknown_Count)
                    {

                        SetCursorCoord_XY(20, 48);
                        printf("\xDD ERROR \xAF You cannot leave subject/s to be 'Unknown'. Set them to exclude if you don't want to include it.");
                        Sleep(1500);
                        break;
                    }
                    // Multiple Checks, If Exclude or Unknown is not equal to Expected Candidates, it is then valid pr Exc;ude and Unknown is Zero
                    else if ((Subject_Receive_Exclude_Count || Subject_Receive_Unknown_Count != Subject_ExpectedCandidates) || (Subject_Receive_Exclude_Count || Subject_Receive_Unknown_Count == 0))
                    {
                        SetCursorCoord_XY(20, 50);
                        printf("\xDD INFO \xAF Processing Data...");
                        // Transport Data by Using another Array Element Size Place holder...
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
                            }
                        }
                        SetCursorCoord_XY(20, 51);
                        printf("\xDD PROCESS \xAF Moving Foward in the Next Step...");
                        Sleep(1500);
                        Func_Final_Overview(Final_Comp_SelectedSubjects, Subject_ExpectedCandidates);
                        break;
                    }
                }
                // When going back, data is still binded...
                else if ((Final_Decision_Selector == 'N') || (Final_Decision_Selector == 'n'))
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xDD PROCESS \xAF Going back to Subject Selection...");
                    Sleep(1500);
                    break;
                }
                else
                {
                    SetCursorCoord_XY(20, 48);
                    printf("\xDD ERROR \xAF Sorry, I don't understand that...");
                    Sleep(1500);
                    break;
                }
            }
            continue;
        }
        else if (Option_Selector == 4)
        {
            SetCursorCoord_XY(20, 47);
            printf("\xDD PROCESS \xAF Including All Available Subjects...");
            Final_Comp_SelectedSubjects = 0;
            Final_Comp_SemUnits = 0;
            // Use Another Array Element Holder and Read and Write from 0 to 11th Element
            while (Sbj_Stats_Increment < Subject_ExpectedCandidates)
            {
                Subject_Status[Sbj_Stats_Increment] = Subject_Parameters[0];       // Set All to Include
                Final_Comp_SelectedSubjects += 1;                                  // Set All as Included, excluding nulified
                Final_Comp_SemUnits += Subject_Units[Sbj_Stats_Increment];         // Calculate all units
                Subject_UnitsGuard_AntiDuplicate_Include[Sbj_Stats_Increment] = 1; // Set Include Disabled to NonNulfied Elements
                Subject_UnitsGuard_AntiDuplicate_Exclude[Sbj_Stats_Increment] = 0; // Set Excluded Enabled to All
                Sbj_Stats_Increment++;                                             // Increase Per Loop
            }
            Sleep(1500);
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
                Subject_Status[Sbj_Stats_Decrement] = Subject_Parameters[1];       // Set All to Exclude
                Subject_UnitsGuard_AntiDuplicate_Include[Sbj_Stats_Decrement] = 0; // Set Include Disabled to NonNulfied Elements
                Subject_UnitsGuard_AntiDuplicate_Exclude[Sbj_Stats_Decrement] = 0; // Set Excluded Enabled to All
                Sbj_Stats_Decrement++;                                             // Increase Per Loop
            }
            Sleep(1500);
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
                Subject_Status[Sbj_Stats_Decrement] = "Unknown";                   // Restore the following values by Iteration
                Subject_UnitsGuard_AntiDuplicate_Include[Sbj_Stats_Decrement] = 0; // Restore the following values by Iteration
                Subject_UnitsGuard_AntiDuplicate_Exclude[Sbj_Stats_Decrement] = 0; // Restore the following values by Iteration
                Sbj_Stats_Decrement++;
            }
            Sleep(1500);
            continue;
        }
        else
        {
            SetCursorCoord_XY(20, 47);
            printf("\xDD WARNING \xAF The button you pressed might be wrong. We can't go non-linear!");
            Sleep(1500);
            fflush(stdin);
            continue;
        }
    }
}

/*
Func_Final_Overview, Passed with Two Variables Containing Total of Subjects Passed with INCLUDE Status
*/
void Func_Final_Overview(int Final_Comp_SelectedSubjects, int Subject_ExpectedCandidates)
{
    SetConsoleTitle(FUNCTION_STEP4);
    char *StudentType;
    char *StatusTake;
    int Subject_Pass_Reader = 0, Subject_Pass_Reader_Counter = 1, SetCoordinates_Dependent = 13;
    // Set Status of a Student and Take Type by Calculating Passed Array Values.
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
    // Using <= Would result to checking 11 or more or max array size which results to Segmentation Fault
    while (Subject_Pass_Reader < Subject_ExpectedCandidates)
    {
        // Subject Contains at Max 12, there are parts that are null midway of 0-11 element, it was being skipped when values are NULL.
        if ((ERLM_DataReceiver.Subject_CodeName_Receiver[Subject_Pass_Reader] == NULL) || (ERLM_DataReceiver.Subject_FullName_Receiver[Subject_Pass_Reader] == NULL) || (ERLM_DataReceiver.Subject_LinearTime_Receiver[Subject_Pass_Reader] == NULL))
        {
            Subject_Pass_Reader++; // Increments To Increase the Array Element Size
            continue;
        }
        else
        {
            SetCursorCoord_XY(30, SetCoordinates_Dependent); // SetCoordinates_Dependent contains Y Values, it was intended to be like this for dynamic graphics incrementation.
            if (Subject_Pass_Reader_Counter >= 10)
            { // There are nothing special in this case, except for formatting, it breaks design with space.
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
    //Shows Status
    printf("\xDD Student Type \xAF %s\t\xDD\t Subjects Enrolled \xAF %d / %d => %-28s", StudentType, Subject_Pass_Reader, Subject_ExpectedCandidates, StatusTake);
    SetCoordinates_Dependent++;
    SetCoordinates_Dependent++;
    SetCursorCoord_XY(30, SetCoordinates_Dependent);
    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetCoordinates_Dependent++;
    SetCoordinates_Dependent++;
    SetCursorCoord_XY(30, SetCoordinates_Dependent);
    printf("\xAF \xDD TAKE NOTE \xDD Here are the last information to be reviewed, press any key to continue.");
    getch(); // No actions needed except press any key, it was just an overview...
    SetCoordinates_Dependent++;
    SetCoordinates_Dependent++;
    SetCursorCoord_XY(30, SetCoordinates_Dependent);
    printf("\xAF \xDD PROCESS \xDD Proceeding to Scholarship Prompt and Mode of Payment...");
    Sleep(1500);
    Func_Stdnt_ScholarshipCheck();
}
/*
Func_Stdnt_ScholarshipCheck -> Checks Grades for posibility of admitting in a scholarship
*/
void Func_Stdnt_ScholarshipCheck()
{
    // Initialize Struct Members that is Integer to avoid Garble Data to Be Added On Potential User Value to be Input.
    OnProcess_StudentData.GradeLowest = 0, OnProcess_StudentData.GradeHighest = 0, OnProcess_StudentData.GradeGeneralAverage_LastSem = 0;
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
    printf("\xBA To get a scholarship discount, your grades must meet the following\t\t\t\t\t   \xBA");
    SetCursorCoord_XY(30, 12);
    printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
    SetCursorCoord_XY(30, 13);
    printf("\xBA \xAF 84.00%% - 85.00%% General Avg with Subject Minimum Grade of 83%% \t\t\t\t\t   \xBA");
    SetCursorCoord_XY(30, 14);
    printf("\xBA \xAF 85.00%% - 86.00%% General Avg with Subject Minimum Grade of 85%% \t\t\t\t\t   \xBA");
    SetCursorCoord_XY(30, 15);
    printf("\xBA \xAF 86.00%% - 87.00%% General Avg with Subject Minimum Grade of 87%% \t\t\t\t\t   \xBA");
    SetCursorCoord_XY(30, 16);
    printf("\xBA \xAF 87.00%% - 99.00%% General Avg with Subject Minimum Grade of 88%% \t\t\t\t\t   \xBA");
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
    // here, checks scanf if data given is valid from the format specifier except with limiter.
    // This is a work around when user attempts to add a letter.
    if (scanf("%3d", &OnProcess_StudentData.GradeGeneralAverage_LastSem) != 1)
    {
        SetCursorCoord_XY(30, 25);
        printf("\xAF \xDD ERROR \xDD You attempted to add letter! Reinitializing...");
        Sleep(1500);
        fflush(stdin); // Added Stream Input Flush to Avoid Unexpectional Looping due to Letters are being converted to Number
        Func_Stdnt_ScholarshipCheck();
    }
    fflush(stdin);
    SetCursorCoord_XY(30, 25);
    printf("\xAF \xDD QUESTION #2 \xDD What is your lowest grade on any subject?");
    SetCursorCoord_XY(30, 26);
    printf("[No Decimal Places, Round Off when the first decimal is only .9] \xAF ");
    // here, checks scanf if data given is valid from the format specifier except with limiter.
    // This is a work around when user attempts to add a letter.
    if (scanf("%3d", &OnProcess_StudentData.GradeLowest) != 1)
    {
        SetCursorCoord_XY(30, 28);
        printf("\xAF \xDD ERROR \xDD You attempted to add letter! Reinitializing...");
        Sleep(1500);
        fflush(stdin); // Added Stream Input Flush to Avoid Unexpectional Looping due to Letters are being converted to Number
        Func_Stdnt_ScholarshipCheck();
    }
    fflush(stdin); // Added Stream Input Flush to Avoid Unexpectional Looping due to Letters are being converted to Number
    SetCursorCoord_XY(30, 28);
    printf("\xAF \xDD QUESTION #3 \xDD What is your highest grade on any subject?");
    SetCursorCoord_XY(30, 29);
    printf("[No Decimal Places, Round Off when the first decimal is only .9] \xAF ");
    // here, checks scanf if data given is valid from the format specifier except with limiter.
    // This is a work around when user attempts to add a letter.
    if (scanf("%d", &OnProcess_StudentData.GradeHighest) != 1)
    {
        SetCursorCoord_XY(30, 31);
        printf("\xAF \xDD ERROR \xDD You attempted to add letter! Reinitializing...");
        Sleep(1500);
        fflush(stdin); // Added Stream Input Flush to Avoid Unexpectional Looping due to Letters are being converted to Number
        Func_Stdnt_ScholarshipCheck();
    }
    fflush(stdin); // Added Stream Input Flush to Avoid Unexpectional Looping due to Letters are being converted to Number

    if (OnProcess_StudentData.GradeLowest >= 82 && OnProcess_StudentData.GradeGeneralAverage_LastSem >= 84)
    {
        SetCursorCoord_XY(30, 31);
        printf("\xAF \xDD INFO \xDD Congratulations! You are eligible for scholarship!");
        Sleep(1500);
        /*
        Unresolvable Bug: When Lower Grade is Higher and Gen Avg is Lower, Prompt oF Scholarship ecist but does not display of eligibility.
        */
        if ((OnProcess_StudentData.GradeLowest >= 82) && (OnProcess_StudentData.GradeGeneralAverage_LastSem >= 84))
        {
            strcpy(OnProcess_StudentData.Granted_ScholarshipStats, "50%% Discount");
            strcpy(OnProcess_StudentData.Granted_ScholarshipDetails, "50%% Discount on Tuition Fee for one (1) semester | Entrance Scholarship");
            SetCursorCoord_XY(30, 32);
            printf("\xAF \xDD ELIGIBILITY \xDD You are eligible for %s", OnProcess_StudentData.Granted_ScholarshipDetails);
        }
        if ((OnProcess_StudentData.GradeLowest >= 84) && (OnProcess_StudentData.GradeGeneralAverage_LastSem >= 85))
        {
            SetCursorCoord_XY(30, 32);
            strcpy(OnProcess_StudentData.Granted_ScholarshipStats, "75%% Discount");
            strcpy(OnProcess_StudentData.Granted_ScholarshipDetails, "75%% Discount on Tuition Fee for one (1) semester | Entrance Scholarship");
            printf("\xA7 \xDD ELIGIBILITY \xDD You are eligible for %s", OnProcess_StudentData.Granted_ScholarshipDetails);
        }
        if ((OnProcess_StudentData.GradeLowest >= 86) && (OnProcess_StudentData.GradeGeneralAverage_LastSem >= 86))
        {
            SetCursorCoord_XY(30, 32);
            strcpy(OnProcess_StudentData.Granted_ScholarshipStats, "100%% Discount");
            strcpy(OnProcess_StudentData.Granted_ScholarshipDetails, "Free tuition fee for one (1) semester | Entrance Scholarship");
            printf("\xAF \xDD ELIGIBILITY \xDD You are eligible for %s", OnProcess_StudentData.Granted_ScholarshipDetails);
        }
        if ((OnProcess_StudentData.GradeLowest >= 88) && (OnProcess_StudentData.GradeGeneralAverage_LastSem >= 87))
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
        Sleep(1500);
        Func_Mode_Of_Payment();
    }
    Sleep(1000);
    while (1)
    {
        /*
        In this case, no strcpy is being attempted to do so except for case 'n' which sets to NULL for declining scholarship status.
        OnProcess_StudentData.Granted_ScholarshipDetails will then be parsed when user selects yes.
        */
        SetCursorCoord_XY(30, 34);
        printf("\xAF \xDD FINAL QUESTION \xDD Do you want to apply for a scholarship? [Y or N] \xAF ");
        switch (getche())
        {
        case 'Y':
        case 'y': //Falls Through
            SetCursorCoord_XY(30, 35);
            printf("\xDD INFO \xAF Data Acquired. Good to know :). Proceeding to Mode of Payment...");
            Sleep(1500);
            Func_Mode_Of_Payment();
        case 'N':
        case 'n': // Falls Through
            SetCursorCoord_XY(30, 35);
            printf("\xDD INFO \xAF Scholarship Grant Aborted :(. Proceeding to Mode of Payment...");
            strcpy(OnProcess_StudentData.Granted_ScholarshipStats, "NULL");
            Sleep(1500);
            Func_Stdnt_ScholarshipCheck();
            break;
        default:
            SetCursorCoord_XY(30, 35);
            printf("\xDD ERROR \xAF Sorry, I don't understand that...");
            Sleep(1500);
            continue;
        }
    }
}

/*
Func_Mode_Of_Payment -> Nothing Special in this Function
*/
void Func_Mode_Of_Payment()
{
    while (1)
    {
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
        switch (getche())
        {
        case '1':
            strcpy(OnProcess_StudentData.PaymentMethod, "Cash");
            SetCursorCoord_XY(30, 19);
            printf("\xAF \xDD SUCCESS \xAF Selected %s as a Mode of Payment. Proceeding to Final Overview...", OnProcess_StudentData.PaymentMethod);
            Sleep(1500);
            Func_PrintDocument_FinalTranscript();
        case '2':
            strcpy(OnProcess_StudentData.PaymentMethod, "Installment");
            SetCursorCoord_XY(30, 19);
            printf("\xAF \xDD SUCCESS \xAF Selected %s as a Mode of Payment. Proceeding to Final Overview...", OnProcess_StudentData.PaymentMethod);
            Sleep(1500);
            Func_PrintDocument_FinalTranscript();
        default:
            SetCursorCoord_XY(30, 19);
            printf("\xAF \xDD ERROR \xAF Sorry, I don't understand that...");
            Sleep(1500);
            continue;
        }
    }
}
/*
Func_PrintDocument_FinalTranscript -> Shows Final Output...
Also runs Dynamic Data Creation Cateogry Function
*/
void Func_PrintDocument_FinalTranscript()
{
    //Create an Student ID for New People
    int SetCoordinates_Dependent = 22, SubjectCount = 0, SubjectNumber = 1, TotalCreditUnits = 0, Reprint_SubjectCount = 0, Reprint_SubjectNumber = 1;
    short unsigned int exist = 0;
    // Set Static Fees, Based from Project Leader's Registration Form
    float TuitionFee, LaboratoryFee = 7225.85, AthleticsFee = 761.20,
                      AudioVisualFee = 133.60, ClassroomEnergyFee = 1100, ComputerFee = 2650.75,
                      CulturalnActivityFee = 48.30, DevFee = 830.45, EnergExtFee = 890.63,
                      GuidancenCounselFee = 520.17, HandbookFee = 153.35, IDFee = 487.10,
                      InsuranceFee = 12.00, InternetFee = 105.30, LibraryFee = 1520.35,
                      MedicalFee = 510.20, RedCrossFee = 1, StudentCouncilFee = 60,
                      TestPaperFee = 266, ScholarshipDiscount = 0, TotalFee = 0;
    SYSTEMTIME GetTimePrinted;                      // Create SPECIAL Variable to Print from the Enrollment Form of Date of Enrolled Process
    GetLocalTime(&GetTimePrinted);                  // Reference to SYSTEMTIME
    FILE *FileCreation_StudentCopy;                 // Create FILE Pointer to use for File Execution
    if (OnProcess_StudentData.stdnt_StudentID == 0) // If student is a new student, this was already set to 0 hence, will run this function...
    {
        Increment_StudentID();
    }
    else
    {
        // REFERENCE FUNCTION TO DELETE ENTRY AT MANAGEMENT MODE
        FILE *Database_Enrollment, *Database_Enrollment_Temporary;
        Database_Enrollment = fopen("LM KeyDatabase//LM_CEA_Enrollment.lmdat", "rb+");
        Database_Enrollment_Temporary = fopen("LM KeyDatabase//TempMaster.lmdat", "wb+");
        //The data that exist from the old student will be then override, hence it will be excluded from the temporary file
        while (1)
        {
            // Read Elements by Line
            fread(&DataChange, sizeof(DataChange), 1, Database_Enrollment);
            if (feof(Database_Enrollment)) // If file reach at end of line, break the loop
            {
                break;
            }
            if (OnProcess_StudentData.stdnt_StudentID == DataChange.Generated_StudentID) // If Old Student is exact to the Database then Increment Value of Exist.
            {
                exist++;
            }
            else
            {
                fwrite(&DataChange, 1, sizeof(DataChange), Database_Enrollment_Temporary); // Write data to temporary for non-equal values to Student ID.
            }
        }
        fclose(Database_Enrollment_Temporary); // Close DataPointers and run next process.
        fclose(Database_Enrollment);           // Close DataPointers and run next process.
        if (exist >= 1)
        {
            Database_Enrollment = fopen("LM KeyDatabase//LM_CEA_Enrollment.lmdat", "wb+");
            Database_Enrollment_Temporary = fopen("LM KeyDatabase//TempMaster.lmdat", "rb+");
            while (1)
            { // Read Temporary File and Overwrite Main File
                fread(&DataChange, sizeof(DataChange), 1, Database_Enrollment_Temporary);
                if (feof(Database_Enrollment_Temporary))
                {
                    break;
                }
                fwrite(&DataChange, sizeof(DataChange), 1, Database_Enrollment);
            }
            fclose(Database_Enrollment);
            fclose(Database_Enrollment_Temporary);
        }
    }
    GenerateUserPass_withGenerateFileName(); // GenerateUser Pass and File Name Stored in TWO Folders
    FileCreation_StudentCopy = fopen(OnProcess_StudentData.FileName_Coordinate, "w+");
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
    printf(" \xDD %-18s \xAF %-50ld", "Student Number", OnProcess_StudentData.stdnt_StudentID);
    SetCursorCoord_XY(20, 12);
    printf(" \xDD %-18s \xAF %-10s", "Program", OnProcess_StudentData.MainCourse_CodeName_Passer);
    SetCursorCoord_XY(20, 13);
    printf(" \xDD %-18s \xAF %-s, %s %-30s", "Name of Student", OnProcess_StudentData.stdnt_LName, OnProcess_StudentData.stdnt_GName, OnProcess_StudentData.stdnt_MName);
    SetCursorCoord_XY(20, 14);
    printf(" \xDD %-10s \xAF %-15s \xAF %-10s", "Year Level and Semester", OnProcess_StudentData.Course_YearChoice, OnProcess_StudentData.Course_SemSelection);
    SetCursorCoord_XY(20, 15);
    printf(" \xDD %-18s \xAF %-70s", "Permanent Address", OnProcess_StudentData.stdnt_Address);
    SetCursorCoord_XY(20, 16);
    printf(" \xDD %-18s \xAF %-50s", "Student Type", OnProcess_StudentData.stdnt_StudentType);
    SetCursorCoord_XY(20, 18);
    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetCursorCoord_XY(20, 20);
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

    TuitionFee = SubjectCount * 200 + 21500; // Set Base of Tuition Fee Starting Point
    // Conditions that parse given by the system.
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
    // Add All Values when Parsing is Done.
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
    Sleep(5000);
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
    printf("\xFE\xCD\xCD \xDD PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetCursorCoord_XY(30, 11);
    printf("\xAF \xDD PROCESS FILE #1 \xDD Saving Data for Enrollee's Completed Registration Form...");
    //Process File to Enrollee Registration Form
    setbuf(FileCreation_StudentCopy, NULL); // setbuf use to set how data is being buffered
    /*
    The following example below shows an encoded special characters without needing \xAF, this will be garblish on non-UTF-8.
    */
    fprintf(FileCreation_StudentCopy, "■══  STUDENTS REGISTRATION FORM - STUDENTS COPY ▌ ══════════════════════■\n\n");
    fprintf(FileCreation_StudentCopy, "▌ %-10s » %-10ld ▌ %-7s » %-5s\n", "Student Number", OnProcess_StudentData.stdnt_StudentID, "Program", OnProcess_StudentData.MainCourse_CodeName_Passer, OnProcess_StudentData.MainCourse_CodeName_Passer);
    fprintf(FileCreation_StudentCopy, "▌ %-10s » %-s, %s %-50s ▌ %-10s » %-5s, %-5s\n", "Name of Student", OnProcess_StudentData.stdnt_LName, OnProcess_StudentData.stdnt_GName, OnProcess_StudentData.stdnt_MName, "Year Level and Semester", OnProcess_StudentData.Course_YearChoice, OnProcess_StudentData.Course_SemSelection);
    fprintf(FileCreation_StudentCopy, "▌ %-10s » %-15s\n", "Permanent Address", OnProcess_StudentData.stdnt_Address);
    fprintf(FileCreation_StudentCopy, "▌ %-10s » %-15s\n\n", "Student Type", OnProcess_StudentData.stdnt_StudentType);
    fprintf(FileCreation_StudentCopy, "■══ ▌ SUBJECT INFORMATION ▌ ════════════════════════════════════════════■\n\n");
    SubjectCount = 0;
    SubjectNumber = 1;
    // Encode ALl Subjects, referenced to this same function to OverView Function.
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
    fprintf(FileCreation_StudentCopy, "▌ » Printed on %02d/%02d/%d - %02d:%02d:%02d\n\n", GetTimePrinted.wMonth, GetTimePrinted.wDay, GetTimePrinted.wYear, GetTimePrinted.wHour, GetTimePrinted.wMinute, GetTimePrinted.wSecond);
    fprintf(FileCreation_StudentCopy, "■═══════════════════════════════════════════════════════════════════════■");
    fclose(FileCreation_StudentCopy);
    GetDataEnrolleeInformation(); // Check Comment on the function from the side.
    SetCursorCoord_XY(30, 12);
    printf("\xAF \xDD SAVED \xAF FILENAME %s\n", OnProcess_StudentData.FileName_Coordinate);
    SetCursorCoord_XY(30, 14);
    printf("\xAF \xDD PROCESS FILE #2 \xDD Saving Data for Enrollee's Information...");
    SetCursorCoord_XY(30, 16);
    printf("\xAF \xDD SAVED \xAF FILENAME %s\n", OnProcess_StudentData.FileName_DataInformation);
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
{ // This Function was created for transfering data to another file that contains student information. Those informations that are filled in step 1 is being taken at this point.
    FILE *FileCreation_StudentInformation;
    FileCreation_StudentInformation = fopen(OnProcess_StudentData.FileName_DataInformation, "w+");
    fprintf(FileCreation_StudentInformation, "Student Information of %s, %s %s\n", OnProcess_StudentData.stdnt_LName, OnProcess_StudentData.stdnt_MName, OnProcess_StudentData.stdnt_GName);
    fprintf(FileCreation_StudentInformation, "Enrollee's Name » %s, %s %s\n", OnProcess_StudentData.stdnt_LName, OnProcess_StudentData.stdnt_MName, OnProcess_StudentData.stdnt_GName);
    fprintf(FileCreation_StudentInformation, "Enrollee's Name of Father » %s\n", OnProcess_StudentData.stdnt_FathersName);
    fprintf(FileCreation_StudentInformation, "Enrollee's Current Occupation of Father » %s\n", OnProcess_StudentData.stdnt_FathersInfoJob);
    fprintf(FileCreation_StudentInformation, "Enrollee's Contact Number of Father » %s\n", OnProcess_StudentData.stdnt_FathersInfoContact);
    fprintf(FileCreation_StudentInformation, "Enrollee's Name of Mother » %s\n", OnProcess_StudentData.stdnt_MothersName);
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
    FILE *Database_Enrollment;
    Database_Enrollment = fopen("LM KeyDatabase//LM_CEA_Enrollment.lmdat", "ab");
    // Did strcpy to add the following below in struct and save to a file containing login credientials
    // This Was included to this function even the function is misleading... To sort out that this one will be on database...
    strcpy(DataChange.stdnt_GName, OnProcess_StudentData.stdnt_GName);
    strcpy(DataChange.stdnt_MName, OnProcess_StudentData.stdnt_MName);
    strcpy(DataChange.stdnt_LName, OnProcess_StudentData.stdnt_LName);
    strcpy(DataChange.stdnt_Username, OnProcess_StudentData.Generated_stdnt_NewUser);
    strcpy(DataChange.stdnt_Password, OnProcess_StudentData.Generated_stdnt_NewPass);
    strcpy(DataChange.stdnt_Course_Codename, OnProcess_StudentData.MainCourse_CodeName_Passer);
    strcpy(DataChange.stdnt_Year_Choice, OnProcess_StudentData.Course_YearChoice);
    strcpy(DataChange.stdnt_Course_Semester, OnProcess_StudentData.Course_SemSelection);
    DataChange.Generated_StudentID = OnProcess_StudentData.stdnt_StudentID;
    fwrite(&DataChange, 1, sizeof(DataChange), Database_Enrollment);
    fclose(FileCreation_StudentInformation);
    fclose(Database_Enrollment);
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
    char UserGenerate_Container[MAX_PATH] = {0},    // Initialize Array to Zero or Empty
        PasswordGenerate_Container[MAX_PATH] = {0}, // Initialize Array to Zero or Empty
        FileName_Container[MAX_PATH] = {0},         // Initialize Array to Zero or Empty
        Acquired_String_StudentID[MAX_PATH] = {0},  // Initialize Array to Zero or Empty
        DataInfo_Container[MAX_PATH] = {0};         // Initialize Array to Zero or Empty
    //Generate Username from BaseBranch + 2 Letters of GivenName + Surname
    // On This Function, Use STRNCAT To UserGenerate_Container for BaseBranch, means concatenate BaseBranch Value to UserGenerate_Container
    strncat(UserGenerate_Container, BaseBranch, sizeof(BaseBranch));
    // On This Function, Use STRNCAT To UserGenerate_Container for stdnt_GName, means concatenate stdnt_GName of 3 first letters to UserGenerate_Container
    strncat(UserGenerate_Container, OnProcess_StudentData.stdnt_GName, 3);
    strncat(UserGenerate_Container, OnProcess_StudentData.stdnt_LName, sizeof(OnProcess_StudentData.stdnt_LName));
    strncpy(OnProcess_StudentData.Generated_stdnt_NewUser, UserGenerate_Container, sizeof(OnProcess_StudentData.Generated_stdnt_NewUser));

    GetLocalTime(&PasswordBaseDate); // Initialize Time

    itoa(OnProcess_StudentData.stdnt_StudentID, Acquired_String_StudentID, 10); // Convert int OnProcess_StudentData.stdnt_StudentID to Char for concatenation...
    strncat(PasswordGenerate_Container, Acquired_String_StudentID, sizeof(Acquired_String_StudentID));
    strncat(PasswordGenerate_Container, PasswordSeperate, 1);
    //Concatenate the following data with data size set
    strncat(PasswordGenerate_Container, OnProcess_StudentData.stdnt_MName, sizeof(OnProcess_StudentData.stdnt_MName));
    strncat(PasswordGenerate_Container, OnProcess_StudentData.stdnt_GName, 3);
    strncat(PasswordGenerate_Container, OnProcess_StudentData.stdnt_LName, 3);
    // After concatenation, transport data to OnProcess_StudentData.Generated_stdnt_NewPass
    strncpy(OnProcess_StudentData.Generated_stdnt_NewPass, PasswordGenerate_Container, sizeof(OnProcess_StudentData.Generated_stdnt_NewPass));

    //Create a File Name for Registration Form
    // We have to concatenate the directory first to seperate files of output
    strncat(FileName_Container, "Student_RegForm//", sizeof("Student_RegForm//"));
    // Concatenate following data with the size of corresponding characters
    strncat(FileName_Container, Acquired_String_StudentID, sizeof(Acquired_String_StudentID));
    strncat(FileName_Container, FileNameSeperate, sizeof(FileNameSeperate));
    strncat(FileName_Container, OnProcess_StudentData.stdnt_GName, sizeof(OnProcess_StudentData.stdnt_GName));
    strncat(FileName_Container, OnProcess_StudentData.stdnt_LName, sizeof(OnProcess_StudentData.stdnt_LName));
    //Save File Name with Default Name Identifier with Extension of RTF
    strncat(FileName_Container, "RegistrationForm.rtf", sizeof("RegistrationForm.rtf"));
    // After concatenation, transport data to OnProcess_StudentData.FileName_Coordinate
    strncpy(OnProcess_StudentData.FileName_Coordinate, FileName_Container, sizeof(OnProcess_StudentData.FileName_Coordinate));

    // For File
    // We have to concatenate the directory first to seperate files of output
    // Concatenate following data with the size of corresponding characters
    strncat(DataInfo_Container, "DataInformation_Student//", sizeof("DataInformation_Student//"));
    strncat(DataInfo_Container, Acquired_String_StudentID, sizeof(Acquired_String_StudentID));
    strncat(DataInfo_Container, FileNameSeperate, sizeof(FileNameSeperate));
    strncat(DataInfo_Container, OnProcess_StudentData.stdnt_LName, sizeof(OnProcess_StudentData.stdnt_LName));
    strncat(DataInfo_Container, OnProcess_StudentData.stdnt_GName, sizeof(OnProcess_StudentData.stdnt_GName));
    strncat(DataInfo_Container, OnProcess_StudentData.stdnt_LName, sizeof(OnProcess_StudentData.stdnt_LName));
    strncat(DataInfo_Container, "DataInformation.rtf", sizeof("DataInformation.rtf"));
    // After concatenation, transport data to OnProcess_StudentData.FileName_DataInformation
    strncpy(OnProcess_StudentData.FileName_DataInformation, DataInfo_Container, sizeof(OnProcess_StudentData.FileName_DataInformation));
}

void Increment_StudentID() //Gets Current Student ID Number on a File that is Non-Binary
{
    FILE *IncrementationDynamic;
    long long int StudentID_OnHold;
    IncrementationDynamic = fopen("LM KeyDatabase//LM_CEA_CurrentStudentID.lmdat", "r"); // Read Data File
    fscanf(IncrementationDynamic, "%ld", &StudentID_OnHold);
    fclose(IncrementationDynamic);
    IncrementationDynamic = fopen("LM KeyDatabase//LM_CEA_CurrentStudentID.lmdat", "w"); // Change Mode To Write For Overwritting with Incremented Value
    StudentID_OnHold++;                                                                  // Increment
    OnProcess_StudentData.stdnt_StudentID = StudentID_OnHold;                            // Bind Data
    fprintf(IncrementationDynamic, "%ld", StudentID_OnHold);
    fclose(IncrementationDynamic);
}
// MANAGEMENT MODE FUNCTIONS
void FuncAdmin_Mgr_Login()
{ // Starting Point of Management Mode
    system("CLS");
    FILE *Database_MasterKey;
    Database_MasterKey = fopen("LM KeyDatabase//LM_CEA_MasterKey.lmdat", "rb+");
    char MasterUserCheck[50],
        MasterPasswordCheck[50];
    int SetConsoleCounter = 3;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("Master Credentials Login");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("Enter your Master Username \xAF ");
    scanf("%30s", &MasterUserCheck);
    fflush(stdin); // flush for exceeding data
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("Enter your Master Password \xAF ");
    scanf("%30s", &MasterPasswordCheck);
    fflush(stdin); // flush for exceeding data
    while (1)
    {
        // Read File By Line
        fread(&MasterPoint, sizeof(MasterPoint), 1, Database_MasterKey);
        if (feof(Database_MasterKey))
        {
            // Checks if one of the parameters are still true and the rest is incorrect.
            if ((strcmp(MasterUserCheck, MasterPoint.Master_User) != 0) || (strcmp(MasterPasswordCheck, MasterPoint.Master_Password) != 0))
            {
                SetConsoleCounter++;
                SetConsoleCounter++;
                SetCursorCoord_XY(30, SetConsoleCounter);
                printf("\xAF\xDD FAILED \xDD Login Failed! One of the following inputs are incorrect!");
                Sleep(2000);
                rewind(Database_MasterKey); // rewind for checking at the beginning again.
                FuncAdmin_Mgr_Login();
            }
        }
        else if ((strcmp(MasterUserCheck, MasterPoint.Master_User) == 0) && (strcmp(MasterPasswordCheck, MasterPoint.Master_Password) == 0))
        {                               // If data is valid from the input given
            rewind(Database_MasterKey); // Rewind the file and read if the the same data is still present. This was done to check if there are duplicates
            while (1)
            {
                fread(&DataChange, sizeof(DataChange), 1, Database_MasterKey);
                if (feof(Database_MasterKey))
                {
                    break;
                }
            }
            fclose(Database_MasterKey);
            SetConsoleCounter++;
            SetConsoleCounter++;
            SetCursorCoord_XY(30, SetConsoleCounter);
            printf("\xDD\xAF INFO \xDD\xAF Login Success!");
            Sleep(2000);
            FuncAdmin_Mgr_Mode();
            break;
        }
        else
        {
            continue; // Continue until data was valid
        }
    }
}

void FuncAdmin_Mgr_Mode() // Shows Full of Choices. Please refer to the header file what does the function do in the following of each case
{
    while (1)
    {
        int SetConsoleCounter = 3;
        system("CLS");
        SetCursorCoord_XY(30, SetConsoleCounter);
        printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
        SetConsoleCounter++;
        SetConsoleCounter++;
        SetCursorCoord_XY(30, SetConsoleCounter);
        printf("\xB2 Enrollment Management Mode \xDD\xAF Login as %s", MasterPoint.Master_User);
        SetConsoleCounter++;
        SetConsoleCounter++;
        SetCursorCoord_XY(30, SetConsoleCounter);
        printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
        SetConsoleCounter++;
        SetConsoleCounter++;
        SetCursorCoord_XY(30, SetConsoleCounter);
        printf("[1] \xDD\xAF Manually Add Student Data");
        SetConsoleCounter++;
        SetConsoleCounter++;
        SetCursorCoord_XY(30, SetConsoleCounter);
        printf("[2] \xDD\xAF Read All Encoded Student Data");
        SetConsoleCounter++;
        SetConsoleCounter++;
        SetCursorCoord_XY(30, SetConsoleCounter);
        printf("[3] \xDD\xAF Search Data of Student by Student Name");
        SetConsoleCounter++;
        SetConsoleCounter++;
        SetCursorCoord_XY(30, SetConsoleCounter);
        printf("[4] \xDD\xAF Search Data of Student by Current Program");
        SetConsoleCounter++;
        SetConsoleCounter++;
        SetCursorCoord_XY(30, SetConsoleCounter);
        printf("[5] \xDD\xAF Search Data of Student by ID");
        SetConsoleCounter++;
        SetConsoleCounter++;
        SetCursorCoord_XY(30, SetConsoleCounter);
        printf("[6] \xDD\xAF Delete Data of Student by Specific Data Requirement");
        SetConsoleCounter++;
        SetConsoleCounter++;
        SetCursorCoord_XY(30, SetConsoleCounter);
        printf("[7] \xDD\xAF Create a Master Admin Credentials");
        SetConsoleCounter++;
        SetConsoleCounter++;
        SetCursorCoord_XY(30, SetConsoleCounter);
        printf("[8] \xDD\xAF Read All Encoded Master Admin Credentials");
        SetConsoleCounter++;
        SetConsoleCounter++;
        SetCursorCoord_XY(30, SetConsoleCounter);
        printf("[9] \xDD\xAF Delete A Specific Master Admin Credentials by Username");
        SetConsoleCounter++;
        SetConsoleCounter++;
        SetCursorCoord_XY(30, SetConsoleCounter);
        printf("[E] \xDD\xAF Exit");
        SetConsoleCounter++;
        SetConsoleCounter++;
        SetCursorCoord_XY(30, SetConsoleCounter);
        printf("[M] \xDD\xAF Go To Normal Mode \xAF LM Enrollment Main Menu");
        SetConsoleCounter++;
        SetConsoleCounter++;
        SetCursorCoord_XY(30, SetConsoleCounter);
        printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
        SetConsoleCounter++;
        SetConsoleCounter++;
        SetCursorCoord_XY(30, SetConsoleCounter);
        printf("\xDD\xAF \xDD INPUT \xDD Press a number that corresponds to your desired decision \xAF ");
        switch (getche())
        {
        case '1':
            FuncAdmin_Mgr_AddEntry();
            break;
        case '2':
            FuncAdmin_Mgr_ReadAllEntry();
            break;
        case '3':
            FuncAdmin_Mgr_SearchNameEntry();
            break;
        case '4':
            FuncAdmin_Mgr_SearchProgramEntry();
            break;
        case '5':
            FuncAdmin_Mgr_SearchID();
            break;
        case '6':
            FuncAdmin_Mgr_Delete_Entry();
            break;
        case '7':
            FuncAdmin_Mgr_AddMaster();
            break;
        case '8':
            FuncAdmin_Mgr_ReadMaster();
            break;
        case '9':
            FuncAdmin_Mgr_DeleteMaster();
            break;
        case 'E':
            exit(EXIT_SUCCESS);
        case 'M':
            Main_Menu();
            break;
        default:
            SetConsoleCounter++;
            SetConsoleCounter++;
            SetCursorCoord_XY(30, SetConsoleCounter);
            printf("\xAF \xDD ERROR \xAF Sorry, I don't understand that...");
            getch();
            system("CLS");
            break;
        }
    }
}
void FuncAdmin_Mgr_AddEntry()
{
    /*
    This program gets data with scanf. The only reason we didn't use fgets because of the data corruption that would result to or garblish data.
    fflush(stdin) is mostly like present after scanf to clear buffer even the buffer is not exceeding to the required...
    */
    int SetConsoleCounter = 3;
    system("CLS");
    FILE *Database_Enrollment;
    Database_Enrollment = fopen("LM KeyDatabase//LM_CEA_Enrollment.lmdat", "ab");
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xB2 Enrollment Management Mode \xDD\xAF Manual Student Data Input");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xB2 \xDD WARNING \xDD Please be mindful about adding data.");
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xC8\xDD\xAF Adding data that doesn't any follow syntax that has been prescribe may result in error when enrolling or even data corruption.");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("[1] Enter first name \xAF [Syntax \xAF When Secondary Given Name Exist, Put '-' between the first given name] ");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xAF\xDD INPUT \xDD\xAF ");
    scanf("%30s", &DataChange.stdnt_GName);
    fflush(stdin);
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("[2] Enter middle name \xAF [Syntax \xAF Complete Middle Name, No Initial Letter Allowed] ");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xAF\xDD INPUT \xDD\xAF ");
    scanf("%30s", &DataChange.stdnt_MName);
    fflush(stdin);
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("[3] Enter last name \xAF [Syntax \xAF None] ");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xAF\xDD INPUT \xDD\xAF ");
    scanf("%30s", &DataChange.stdnt_LName);
    fflush(stdin);
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("[4] Enter ID number \xAF [Syntax \xAF Last 2 # of Year, 2 # of Batch Num, 3# of Stdnt # Ex, 1810386] ");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xAF\xDD INPUT \xDD\xAF ");
    if (scanf("%7ld", &DataChange.Generated_StudentID) != 1) // Check if data given is valid that corresponds to the format specifier...
    {
        SetConsoleCounter++;
        SetConsoleCounter++;
        SetCursorCoord_XY(30, SetConsoleCounter);
        printf("\xAF \xDD ERROR \xDD You attempted to add letter! Reinitializing...");
        Sleep(1500);
        fflush(stdin);
        FuncAdmin_Mgr_AddEntry();
    }
    fflush(stdin);
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("[5] Enter Program name \xAF [Syntax \xAF BS<ProgramCodeName>] ");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xAF\xDD INPUT \xDD\xAF ");
    scanf("%6s", &DataChange.stdnt_Course_Codename);
    fflush(stdin);
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("[6] Enter Year Level \xAF [Syntax \xAF Ordinal Numbers Only, e.g 1st, 2nd, 3rd] ");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xAF\xDD INPUT \xDD\xAF ");
    scanf("%20s", &DataChange.stdnt_Year_Choice);
    fflush(stdin);
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("[7] Enter Semester \xAF [Syntax \xAF Input 'First' or 'Second' Only!] ");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xAF\xDD INPUT \xDD\xAF ");
    scanf("%20s", &DataChange.stdnt_Course_Semester);
    fflush(stdin);
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("[8] Enter Username \xAF [Syntax \xAF Any, Do not include space!] ");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xAF\xDD INPUT \xDD\xAF ");
    scanf("%30s", &DataChange.stdnt_Username);
    fflush(stdin);
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("[9] Enter Password");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xAF\xDD INPUT \xDD\xAF ");
    scanf("%30s", &DataChange.stdnt_Password);
    fflush(stdin);
    fwrite(&DataChange, 1, sizeof(DataChange), Database_Enrollment);
    fclose(Database_Enrollment);
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xAF \xDD INFO-SUCCESS \xDD Manual Student Data Input is Done!");
    Sleep(2000);
    FuncAdmin_Mgr_Mode(); // Return Back
}
void FuncAdmin_Mgr_ReadAllEntry()
{
    /*
    Reads File and Outputs Available Data
    */
    system("CLS");
    FILE *Database_Enrollment;
    int SetConsoleCounter = 5, SizeCheck = 0;
    Database_Enrollment = fopen("LM KeyDatabase//LM_CEA_Enrollment.lmdat", "rb"); // Read in binary because data is written in binary.
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xB2 Enrollment Management Mode \xDD\xAF Read All List of Students That is Encoded in Database");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xB2 \xAF \xDD NOTE \xDD \xAF Keep in mind that data will be set out from the window. Please scroll right to view more info.");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetConsoleCounter++;
    fseek(Database_Enrollment, 0, SEEK_END); // Make Pointer Location put until the end of the file
    SizeCheck = ftell(Database_Enrollment);  // ftell tells is the pointer is.
    if (SizeCheck == 0)                      // Data that has no size is already set to zero as we logically think about it.
    {
        SetConsoleCounter++;
        SetCursorCoord_XY(30, SetConsoleCounter);
        printf("\xAF\xDD INFO - FILE \xDD\xAF No Data Found To Display...");
        SetConsoleCounter++;
        SetConsoleCounter++;
        SetCursorCoord_XY(30, SetConsoleCounter);
        printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
        fclose(Database_Enrollment);
        getch();
        FuncAdmin_Mgr_Mode();
    }
    else
    { // In any case that the file is not blank, reset the cursor or pointer to beginning of the file
        fseek(Database_Enrollment, 0, SEEK_SET);
        SetConsoleCounter++;
        SetCursorCoord_XY(1, SetConsoleCounter);
        printf("%-20s%-20s%-20s %-20s%-20s%-20s%-20s%-20s%-20s", "Student ID", "First name", "Middle name", "Last Name", "Program Name", "Year Level", "Semester", "Stdnt UserName", "Stdnt Password");
        SetConsoleCounter++;
        while (1)
        { // Start Reading and Outputting Available Data
            fread(&DataChange, sizeof(DataChange), 1, Database_Enrollment);
            if (feof(Database_Enrollment)) // Will stop at this point and tell to the manager that is already in the ond of line of the database file.
            {
                SetConsoleCounter++;
                SetConsoleCounter++;
                SetCursorCoord_XY(30, SetConsoleCounter);
                printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
                SetConsoleCounter++;
                SetConsoleCounter++;
                SetCursorCoord_XY(30, SetConsoleCounter);
                printf("\xAF\xDD INFO - FILE \xDD\xAF Data Reading Reached the End of Line of the Database File...");
                break;
            }
            else
            {
                SetConsoleCounter++;
                SetCursorCoord_XY(1, SetConsoleCounter); // Displays at X at 1 due to long data as it sets of the window
                printf("%-20d%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s", DataChange.Generated_StudentID, DataChange.stdnt_GName, DataChange.stdnt_MName, DataChange.stdnt_LName, DataChange.stdnt_Course_Codename, DataChange.stdnt_Year_Choice, DataChange.stdnt_Course_Semester, DataChange.stdnt_Username, DataChange.stdnt_Password);
            }
        }
        fclose(Database_Enrollment);
        getch();
        FuncAdmin_Mgr_Mode();
    }
}
void FuncAdmin_Mgr_SearchNameEntry()
{
    system("CLS");
    FILE *Database_Enrollment;
    Database_Enrollment = fopen("LM KeyDatabase//LM_CEA_Enrollment.lmdat", "rb");
    int SetConsoleCounter = 5, DataReadCounter = 0;
    char stdnt_GName_Placeholder[30];
    char stdnt_MName_Placeholder[30];
    char stdnt_LName_Placeholder[30];
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xB2 Enrollment Management Mode \xDD\xAF Search Student Data by Name Entry");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xB2 \xAF \xDD NOTE \xDD \xAF Keep in mind that data will be set out from the window. Please scroll right to view more info.");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xAF\xDD INPUT #1 \xDD\xAF Enter First Name To Search \xAF ");
    scanf("%30s", &stdnt_GName_Placeholder);
    fflush(stdin);
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xAF\xDD INPUT #2 \xDD\xAF Enter Middle Name To Search \xAF ");
    scanf("%30s", &stdnt_MName_Placeholder);
    fflush(stdin);
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xAF\xDD INPUT #3 \xDD\xAF Enter Last Name To Search \xAF ");
    scanf("%30s", &stdnt_LName_Placeholder);
    fflush(stdin);
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    while (1)
    { // Check Data
        fread(&DataChange, sizeof(DataChange), 1, Database_Enrollment);
        if (feof(Database_Enrollment))
        { // The Difference of DataReadCounter IF and ELSE is that in If, it display no data found while on else statement it only display end of line file.
            if (DataReadCounter == 0)
            {
                SetConsoleCounter++;
                SetConsoleCounter++;
                SetCursorCoord_XY(30, SetConsoleCounter);
                printf("\xAF\xDD INFO - FILE \xDD\xAF No Data Found...");
                SetConsoleCounter++;
                SetConsoleCounter++;
                SetCursorCoord_XY(30, SetConsoleCounter);
                printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
                SetConsoleCounter++;
                SetConsoleCounter++;
                SetCursorCoord_XY(30, SetConsoleCounter);
                printf("\xAF\xDD INFO - FILE \xDD\xAF Data Reading Reached the End of Line of the Database File...");
                getch();
                rewind(Database_Enrollment);
                break;
            }
            else
            {
                SetConsoleCounter++;
                SetConsoleCounter++;
                SetCursorCoord_XY(30, SetConsoleCounter);
                printf("\xAF\xDD INFO - FILE \xDD\xAF Data Reading Reached the End of Line of the Database File...");
                getch();
                rewind(Database_Enrollment);
                break;
            }
        }
        else if ((strcmp(stdnt_GName_Placeholder, DataChange.stdnt_GName) == 0) && (strcmp(stdnt_MName_Placeholder, DataChange.stdnt_MName) == 0) && (strcmp(stdnt_LName_Placeholder, DataChange.stdnt_LName) == 0))
        { // If found one it will first display the first data
            SetConsoleCounter++;
            SetConsoleCounter++;
            SetCursorCoord_XY(1, SetConsoleCounter);
            printf("%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s", "Student ID", "First name", "Middle name", "Last Name", "Program Name", "Year Level", "Semester", "Stdnt UserName", "Stdnt Password");
            DataReadCounter++; // Incremented for different output check nested if and else of feof() function;
            SetConsoleCounter++;
            SetConsoleCounter++;
            SetCursorCoord_XY(1, SetConsoleCounter);
            printf("%-20d%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s", DataChange.Generated_StudentID, DataChange.stdnt_GName, DataChange.stdnt_MName, DataChange.stdnt_LName, DataChange.stdnt_Course_Codename, DataChange.stdnt_Year_Choice, DataChange.stdnt_Course_Semester, DataChange.stdnt_Username, DataChange.stdnt_Password);
            while (1)
            { // And it will iterate inside of this function with the same conditions
                fread(&DataChange, sizeof(DataChange), 1, Database_Enrollment);
                if (feof(Database_Enrollment))
                {
                    SetConsoleCounter++;
                    SetConsoleCounter++;
                    SetCursorCoord_XY(30, SetConsoleCounter);
                    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
                    SetConsoleCounter++;
                    SetConsoleCounter++;
                    SetCursorCoord_XY(30, SetConsoleCounter);
                    printf("\xAF\xDD INFO - FILE \xDD\xAF Data Reading Reached the End of Line of the Database File...");
                    rewind(Database_Enrollment);
                    getch();
                    FuncAdmin_Mgr_Mode();
                }
                else if ((strcmp(stdnt_GName_Placeholder, DataChange.stdnt_GName) == 0) && (strcmp(stdnt_MName_Placeholder, DataChange.stdnt_MName) == 0) && (strcmp(stdnt_LName_Placeholder, DataChange.stdnt_LName) == 0))
                {
                    SetConsoleCounter++;
                    SetCursorCoord_XY(1, SetConsoleCounter);
                    printf("%-20d%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s", DataChange.Generated_StudentID, DataChange.stdnt_GName, DataChange.stdnt_MName, DataChange.stdnt_LName, DataChange.stdnt_Course_Codename, DataChange.stdnt_Year_Choice, DataChange.stdnt_Course_Semester, DataChange.stdnt_Username, DataChange.stdnt_Password);
                }
            } // This while loop was created to loop inside without looping outside of this while loop as it takes one output only when there are alot to input.
        }
        else
        {
            continue; // Continue until data is valid
        }
    }
}
void FuncAdmin_Mgr_SearchProgramEntry()
{
    system("CLS");
    FILE *Database_Enrollment;
    char stdnt_ActiveCourseCodeName[100];
    int SetConsoleCounter = 5, DataReadCounter = 0;
    Database_Enrollment = fopen("LM KeyDatabase//LM_CEA_Enrollment.lmdat", "rb");
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xB2 Enrollment Management Mode \xDD\xAF Search Student Data by Program Entry");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xB2 \xAF \xDD NOTE \xDD \xAF Please keep in mind that the data will display exceeded out of the window. Please scroll right to view more info.");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xAF \xDD Enter course name \xDD \xAF Current Program Only! \xDD [Syntax \xAF BS<ProgramCodeName>] \xAF ");
    scanf("%s", &stdnt_ActiveCourseCodeName);
    fflush(stdin);
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    while (1)
    { // After Input, Read and check for data validity in Database
        fread(&DataChange, sizeof(DataChange), 1, Database_Enrollment);
        if (feof(Database_Enrollment))
        {
            if (DataReadCounter == 0)
            { // The Difference of DataReadCounter IF and ELSE is that in If, it display no data found while on else statement it only display end of line file.
                SetConsoleCounter++;
                SetConsoleCounter++;
                SetCursorCoord_XY(30, SetConsoleCounter);
                printf("\xAF\xDD INFO - FILE \xDD\xAF No Data Found...");
                SetConsoleCounter++;
                SetConsoleCounter++;
                SetCursorCoord_XY(30, SetConsoleCounter);
                printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
                SetConsoleCounter++;
                SetConsoleCounter++;
                SetCursorCoord_XY(30, SetConsoleCounter);
                printf("\xAF\xDD INFO - FILE \xDD\xAF Data Reading Reached the End of Line of the Database File...");
                getch();
                rewind(Database_Enrollment); // Assurance of Going to the beginning of the file
                break;
            }
            else
            {
                SetConsoleCounter++;
                SetConsoleCounter++;
                SetCursorCoord_XY(30, SetConsoleCounter);
                printf("\xAF\xDD INFO - FILE \xDD\xAF Data Reading Reached the End of Line of the Database File...");
                getch();
                rewind(Database_Enrollment); // Assurance of Going to the beginning of the file
                break;
            }
        }
        else if ((strcmp(stdnt_ActiveCourseCodeName, DataChange.stdnt_Course_Codename) == 0))
        { // If Data found, it will display its first search data
            SetConsoleCounter++;
            SetConsoleCounter++;
            SetCursorCoord_XY(1, SetConsoleCounter);
            printf("%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s", "Student ID", "First name", "Middle name", "Last Name", "Program Name", "Year Level", "Semester", "Stdnt UserName", "Stdnt Password");
            DataReadCounter++;
            SetConsoleCounter++;
            SetConsoleCounter++;
            SetCursorCoord_XY(1, SetConsoleCounter);
            printf("%-20d%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s\n", DataChange.Generated_StudentID, DataChange.stdnt_GName, DataChange.stdnt_MName, DataChange.stdnt_LName, DataChange.stdnt_Course_Codename, DataChange.stdnt_Year_Choice, DataChange.stdnt_Course_Semester, DataChange.stdnt_Username, DataChange.stdnt_Password);
            while (1)
            { // And loop to look for the others
                fread(&DataChange, sizeof(DataChange), 1, Database_Enrollment);
                if (feof(Database_Enrollment))
                {
                    SetConsoleCounter++;
                    SetConsoleCounter++;
                    SetCursorCoord_XY(30, SetConsoleCounter);
                    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
                    SetConsoleCounter++;
                    SetConsoleCounter++;
                    SetCursorCoord_XY(30, SetConsoleCounter);
                    printf("\xAF\xDD INFO - FILE \xDD\xAF Data Reading Reached the End of Line of the Database File...");
                    rewind(Database_Enrollment);
                    getch();
                    FuncAdmin_Mgr_Mode();
                }
                else if ((strcmp(stdnt_ActiveCourseCodeName, DataChange.stdnt_Course_Codename) == 0))
                {
                    SetConsoleCounter++;
                    SetCursorCoord_XY(1, SetConsoleCounter);
                    printf("%-20d%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s", DataChange.Generated_StudentID, DataChange.stdnt_GName, DataChange.stdnt_MName, DataChange.stdnt_LName, DataChange.stdnt_Course_Codename, DataChange.stdnt_Year_Choice, DataChange.stdnt_Course_Semester, DataChange.stdnt_Username, DataChange.stdnt_Password);
                }
            } // This while loop was created to loop inside without looping outside of this while loop as it takes one output only when there are alot to input.
        }
        else
        {
            continue;
        }
    }
}
/*
    IMPORTANT NOTICE, PLEASE REFER TO THE ABOVE FUNCTION AS IT WAS THE SAME FUNCTION FOR SEARCH AND ADD, THE ONLY DIFFERENCE IS THAT IT CHECKS FOR DIFFERENT DATA
*/
void FuncAdmin_Mgr_SearchID()
{
    system("CLS");
    FILE *Database_Enrollment;
    long int stdnt_ActiveID = 0;
    int SetConsoleCounter = 5, DataReadCounter = 0;
    Database_Enrollment = fopen("LM KeyDatabase//LM_CEA_Enrollment.lmdat", "rb");
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xB2 Enrollment Management Mode \xDD\xAF Search Student Data by Student ID");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xB2 \xAF \xDD NOTE \xDD \xAF Keep in mind that data will be set out from the window. Please scroll right to view more info.");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xAF \xDD INPUT #1 \xDD \xAF Enter Student ID \xAF ");
    scanf("%ld", &stdnt_ActiveID);
    fflush(stdin);
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");

    while (1)
    {
        fread(&DataChange, sizeof(DataChange), 1, Database_Enrollment);
        if (feof(Database_Enrollment))
        {
            if (DataReadCounter == 0)
            { // The Difference of DataReadCounter IF and ELSE is that in If, it display no data found while on else statement it only display end of line file.
                SetConsoleCounter++;
                SetConsoleCounter++;
                SetCursorCoord_XY(30, SetConsoleCounter);
                printf("\xAF\xDD INFO - FILE \xDD\xAF No Data Found...");
                SetConsoleCounter++;
                SetConsoleCounter++;
                SetCursorCoord_XY(30, SetConsoleCounter);
                printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
                SetConsoleCounter++;
                SetConsoleCounter++;
                SetCursorCoord_XY(30, SetConsoleCounter);
                printf("\xAF\xDD INFO - FILE \xDD\xAF Data Reading Reached the End of Line of the Database File...");
                getch();
                rewind(Database_Enrollment);
                break;
            }
            else
            {
                SetConsoleCounter++;
                SetConsoleCounter++;
                SetCursorCoord_XY(30, SetConsoleCounter);
                printf("\xAF\xDD INFO - FILE \xDD\xAF Data Reading Reached the End of Line of the Database File...");
                getch();
                rewind(Database_Enrollment);
                break;
            }
        }
        else if (stdnt_ActiveID == DataChange.Generated_StudentID)
        {
            SetConsoleCounter++;
            SetConsoleCounter++;
            SetCursorCoord_XY(1, SetConsoleCounter);
            printf("%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s", "Student ID", "First name", "Middle name", "Last Name", "Program Name", "Year Level", "Semester", "Stdnt UserName", "Stdnt Password");
            DataReadCounter++;
            SetConsoleCounter++;
            SetConsoleCounter++;
            SetCursorCoord_XY(1, SetConsoleCounter);
            printf("%-20d%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s", DataChange.Generated_StudentID, DataChange.stdnt_GName, DataChange.stdnt_MName, DataChange.stdnt_LName, DataChange.stdnt_Course_Codename, DataChange.stdnt_Year_Choice, DataChange.stdnt_Course_Semester, DataChange.stdnt_Username, DataChange.stdnt_Password);
            while (1)
            {
                fread(&DataChange, sizeof(DataChange), 1, Database_Enrollment);
                if (feof(Database_Enrollment))
                {
                    SetConsoleCounter++;
                    SetConsoleCounter++;
                    SetCursorCoord_XY(30, SetConsoleCounter);
                    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
                    SetConsoleCounter++;
                    SetConsoleCounter++;
                    SetCursorCoord_XY(30, SetConsoleCounter);
                    printf("\xAF\xDD INFO - FILE \xDD\xAF Data Reading Reached the End of Line of the Database File...");
                    rewind(Database_Enrollment);
                    getch();
                    FuncAdmin_Mgr_Mode();
                }
                else if (stdnt_ActiveID == DataChange.Generated_StudentID)
                {
                    SetConsoleCounter++;
                    SetCursorCoord_XY(1, SetConsoleCounter);
                    printf("%-20d%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s", DataChange.Generated_StudentID, DataChange.stdnt_GName, DataChange.stdnt_MName, DataChange.stdnt_LName, DataChange.stdnt_Course_Codename, DataChange.stdnt_Year_Choice, DataChange.stdnt_Course_Semester, DataChange.stdnt_Username, DataChange.stdnt_Password);
                }
            }
        }
        else
        {
            continue;
        }
    }
}
/*
THERE ARE AT LEAST TWO PROCESS, ONE IS AVOIDING THE VALID DATA AND COPY DATA TO TEMPORARY, AND LASTLY TEMPORARY OVERWRITES CURRENT FILE
*/
void FuncAdmin_Mgr_Delete_Entry()
{
    system("CLS");
    FILE *Database_Enrollment, *Database_Enrollment_Temporary;
    Database_Enrollment = fopen("LM KeyDatabase//LM_CEA_Enrollment.lmdat", "rb+");
    Database_Enrollment_Temporary = fopen("LM KeyDatabase//TempMaster.lmdat", "wb+");
    long int DataEntryBase_ID = 0;
    int SetConsoleCounter = 5, DataReadCounter = 0;
    char stdnt_Year_Placeholder[20], stdnt_Semester_Placeholder[20];
    short unsigned int exist = 0;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xB2 Enrollment Management Mode \xDD\xAF Delete Student Data from the Database");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xB2 \xAF \xDD NOTE \xDD \xAF Keep in mind that data will be set out from the window. Please scroll right to view more info.");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xB2 \xAF \xDD WARNING \xDD \xAF Duplicates of data with same information from the given input will also be deleted...");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xAF\xDD INPUT #1 \xDD\xAF Enter Student ID \xAF [Syntax \xAF Last 2 # of Year, 2 # of Batch Num, 3# of Stdnt # Ex, 1810386] ");
    scanf("%ld", &DataEntryBase_ID);
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xAF\xDD INPUT #2 \xDD\xAF Enter Year Level \xAF ");
    scanf("%20s", &stdnt_Year_Placeholder);
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xAF\xDD INPUT #3 \xDD\xAF Enter Semester \xAF ");
    scanf("%20s", &stdnt_Semester_Placeholder);
    fflush(stdin);
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    while (1)
    { // Read Data
        fread(&DataChange, sizeof(DataChange), 1, Database_Enrollment);
        if (feof(Database_Enrollment))
        {
            if (DataReadCounter == 0)
            { // The Difference of DataReadCounter IF and ELSE is that in If, it display no data found while on else statement it only display end of line file.
                SetConsoleCounter++;
                SetConsoleCounter++;
                SetCursorCoord_XY(30, SetConsoleCounter);
                printf("\xAF\xDD INFO - FILE \xDD\xAF No Data Found...");
                SetConsoleCounter++;
                SetConsoleCounter++;
                SetCursorCoord_XY(30, SetConsoleCounter);
                printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
                SetConsoleCounter++;
                SetConsoleCounter++;
                SetCursorCoord_XY(30, SetConsoleCounter);
                printf("\xAF\xDD INFO - FILE \xDD\xAF Data Reading Reached the End of Line of the Database File...");
                getch();
                rewind(Database_Enrollment); // Assurance
                break;
            }
            else
            {
                SetConsoleCounter++;
                SetConsoleCounter++;
                SetCursorCoord_XY(30, SetConsoleCounter);
                printf("\xAF\xDD INFO - FILE \xDD\xAF Data Reading Reached the End of Line of the Database File...");
                rewind(Database_Enrollment); // Assurance
                break;
            }
        }
        if ((DataEntryBase_ID == DataChange.Generated_StudentID) && (strcmp(stdnt_Year_Placeholder, DataChange.stdnt_Year_Choice) == 0) && (strcmp(stdnt_Semester_Placeholder, DataChange.stdnt_Course_Semester) == 0))
        {
            exist++;           // Increment Value to Let Function know that something exist and its valid. This one is used on the other process
            DataReadCounter++; // DataCounter Reason is the same as for exist. This one only checks at FEOP()
            SetConsoleCounter++;
            SetConsoleCounter++;
            SetCursorCoord_XY(1, SetConsoleCounter);
            printf("%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s", "Student ID", "First name", "Middle name", "Last Name", "Program Name", "Year Level", "Semester", "Stdnt UserName", "Stdnt Password");
            SetConsoleCounter++;
            SetConsoleCounter++;
            SetCursorCoord_XY(1, SetConsoleCounter);
            printf("%-20d%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s --ENTRY DELETED--", DataChange.Generated_StudentID, DataChange.stdnt_GName, DataChange.stdnt_MName, DataChange.stdnt_LName, DataChange.stdnt_Course_Codename, DataChange.stdnt_Year_Choice, DataChange.stdnt_Course_Semester, DataChange.stdnt_Username, DataChange.stdnt_Password);
            // DataValid shows here
            while (1)
            { // Loop to look some more valid date
                fread(&DataChange, sizeof(DataChange), 1, Database_Enrollment);
                if (feof(Database_Enrollment))
                {
                    break;
                }
                else if ((DataEntryBase_ID == DataChange.Generated_StudentID) && (strcmp(stdnt_Year_Placeholder, DataChange.stdnt_Year_Choice) == 0) && (strcmp(stdnt_Semester_Placeholder, DataChange.stdnt_Course_Semester) == 0))
                {
                    DataReadCounter++;
                    SetConsoleCounter++;
                    SetConsoleCounter++;
                    SetCursorCoord_XY(1, SetConsoleCounter);
                    printf("%-20d%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s --ENTRY DELETED--", DataChange.Generated_StudentID, DataChange.stdnt_GName, DataChange.stdnt_MName, DataChange.stdnt_LName, DataChange.stdnt_Course_Codename, DataChange.stdnt_Year_Choice, DataChange.stdnt_Course_Semester, DataChange.stdnt_Username, DataChange.stdnt_Password);
                    // Data Found which cannot be fwrite to the Temporary File
                }
                else
                {
                    fwrite(&DataChange, 1, sizeof(DataChange), Database_Enrollment_Temporary);
                    // Write that is non-valid to the Inputs.
                }
            }
            SetConsoleCounter++;
            SetConsoleCounter++;
            SetCursorCoord_XY(30, SetConsoleCounter);
            printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
            SetConsoleCounter++;
            SetConsoleCounter++;
            SetCursorCoord_XY(30, SetConsoleCounter);
            printf("The Following List of Student Data Entries will be deleted...");
            SetConsoleCounter++;
            SetConsoleCounter++;
            SetCursorCoord_XY(30, SetConsoleCounter);
            printf("Press Any Key To Continue...");
            getch();
        }
        else
        {
            fwrite(&DataChange, 1, sizeof(DataChange), Database_Enrollment_Temporary);
            // Write that is non-valid to the Inputs.
        }
    }
    fclose(Database_Enrollment_Temporary);
    fclose(Database_Enrollment);
    // PROCESS NUMBER 2

    if (exist >= 1)
    {
        Database_Enrollment = fopen("LM KeyDatabase//LM_CEA_Enrollment.lmdat", "wb+");
        Database_Enrollment_Temporary = fopen("LM KeyDatabase//TempMaster.lmdat", "rb+");
        SetConsoleCounter++;
        SetConsoleCounter++;
        SetCursorCoord_XY(30, SetConsoleCounter);
        printf("\xAF\xDD FILE #1 -> FILE#2 \xDD\xAF Data Read Completed! Preparing for Data Transport...");
        while (1)
        { // START READING AT TEMPORARY FILE AND OVERRIDE MAIN DATABASE FILE
            fread(&DataChange, sizeof(DataChange), 1, Database_Enrollment_Temporary);
            if (feof(Database_Enrollment_Temporary))
            {
                break;
            }
            fwrite(&DataChange, sizeof(DataChange), 1, Database_Enrollment);
        }
        SetConsoleCounter++;
        SetConsoleCounter++;
        SetCursorCoord_XY(30, SetConsoleCounter);
        printf("\xAF\xDD FILE #1 == FILE#2 \xDD\xAF Data Transfer Complete!");
        fclose(Database_Enrollment);
        fclose(Database_Enrollment_Temporary);
        remove("LM KeyDatabase//TempMaster.lmdat"); // Remove Temporary File
        getch();
        FuncAdmin_Mgr_Mode();
    }
    else
    {
        FuncAdmin_Mgr_Mode();
    }
}
void FuncAdmin_Mgr_AddMaster()
{
    int SetConsoleCounter = 3;
    system("CLS");
    FILE *Database_MasterKey;
    Database_MasterKey = fopen("LM KeyDatabase//LM_CEA_MasterKey.lmdat", "ab");
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xB2 Enrollment Management Mode \xDD\xAF Add Master User / Credentials");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("[1] Enter Username \xDD\xAF ");
    scanf("%30s", &MasterPoint.Master_User);
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("[2] Enter Password \xDD\xAF ");
    scanf("%30s", &MasterPoint.Master_Password);
    fwrite(&MasterPoint, 1, sizeof(MasterPoint), Database_MasterKey);
    fclose(Database_MasterKey);
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xAF\xDD INFO \xDD Manual Data Input is Done!!!");
    Sleep(2000);
    FuncAdmin_Mgr_Mode();
}
void FuncAdmin_Mgr_ReadMaster()
{
    system("CLS");
    FILE *Database_MasterKey;
    int SetConsoleCounter = 5, SizeCheck = 0;
    Database_MasterKey = fopen("LM KeyDatabase//LM_CEA_MasterKey.lmdat", "rb");
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xB2 Enrollment Management Mode \xDD\xAF Read All List of Master Users");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetConsoleCounter++;
    fseek(Database_MasterKey, 0, SEEK_END);
    SizeCheck = ftell(Database_MasterKey);
    if (SizeCheck == 0)
    {
        SetConsoleCounter++;
        SetCursorCoord_XY(30, SetConsoleCounter);
        fclose(Database_MasterKey);
        printf("\xAF\xDD WARNING - FILE \xDD\xAF No Data Found! Creating Default Master User!!!!");
        Database_MasterKey = fopen("LM KeyDatabase//LM_CEA_MasterKey.lmdat", "wb");
        strcpy(MasterPoint.Master_User, "ADMIN");
        strcpy(MasterPoint.Master_Password, "LM123");
        fwrite(&MasterPoint, sizeof(MasterPoint), 1, Database_MasterKey);
        fclose(Database_MasterKey);
        SetConsoleCounter++;
        SetConsoleCounter++;
        SetCursorCoord_XY(30, SetConsoleCounter);
        printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
        getch();
        FuncAdmin_Mgr_Mode();
    }
    else
    {
        fseek(Database_MasterKey, 0, SEEK_SET);
        SetConsoleCounter++;
        SetCursorCoord_XY(30, SetConsoleCounter);
        printf("%-20s%-20s", "Master Username", "Master Password");
        SetConsoleCounter++;
        while (1)
        {
            fread(&MasterPoint, sizeof(MasterPoint), 1, Database_MasterKey);
            if (feof(Database_MasterKey))
            {
                SetConsoleCounter++;
                SetConsoleCounter++;
                SetCursorCoord_XY(30, SetConsoleCounter);
                printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
                SetConsoleCounter++;
                SetConsoleCounter++;
                SetCursorCoord_XY(30, SetConsoleCounter);
                printf("\xAF\xDD INFO - FILE \xDD\xAF Data Reading Reached the End of Line of the Database File...");
                break;
            }
            else
            {
                SetConsoleCounter++;
                SetCursorCoord_XY(30, SetConsoleCounter);
                printf("%-20s%-20s", MasterPoint.Master_User, MasterPoint.Master_Password);
            }
        }
        fclose(Database_MasterKey);
        getch();
        FuncAdmin_Mgr_Mode();
    }
}
/*Please Refer to FuncAdmin_Mgr_Delete_Entry Function as it has the same function but different data to check */
void FuncAdmin_Mgr_DeleteMaster()
{
    system("CLS");
    FILE *Database_MasterKey, *Database_MasterKey_Temporary;
    Database_MasterKey = fopen("LM KeyDatabase//LM_CEA_MasterKey.lmdat", "rb+");
    Database_MasterKey_Temporary = fopen("LM KeyDatabase//TempMaster.lmdat", "wb+");
    short unsigned int exist = 0;
    int SetConsoleCounter = 3, DataReadCounter = 0;
    char DataMaster_Username[50];
    char DataMaster_Password[50];
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xB2 Enrollment Management Mode \xDD\xAF Delete Master Data from the Database");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xB2 \xAF \xDD WARNING \xDD \xAF DO NOT DELETE ALL MASTER DATA, MAKE ONE ATLEAST MASTER ACCOUNT, REMOVING ALL WILL LOAD DEFAULT SET MASTER USER");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xAF\xDD INPUT #1 \xDD\xAF Enter Master Username \xAF ");
    scanf("%s", &DataMaster_Username);
    SetConsoleCounter++;
    SetConsoleCounter++;
    SetCursorCoord_XY(30, SetConsoleCounter);
    printf("\xAF\xDD INPUT #2 \xDD\xAF Enter Master Password \xAF ");
    scanf("%s", &DataMaster_Password);
    while (1)
    {
        fread(&MasterPoint, sizeof(MasterPoint), 1, Database_MasterKey);
        if (feof(Database_MasterKey))
        {
            if (DataReadCounter == 0)
            {
                SetConsoleCounter++;
                SetConsoleCounter++;
                SetCursorCoord_XY(30, SetConsoleCounter);
                printf("\xAF\xDD INFO - FILE \xDD\xAF No Data Found Matching To Delete...");
                SetConsoleCounter++;
                SetConsoleCounter++;
                SetCursorCoord_XY(30, SetConsoleCounter);
                printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
                SetConsoleCounter++;
                SetConsoleCounter++;
                SetCursorCoord_XY(30, SetConsoleCounter);
                printf("\xAF\xDD INFO - FILE \xDD\xAF Data Reading Reached the End of Line of the Database File...");
                getch();
                rewind(Database_MasterKey);
                break;
            }
            else
            {
                SetConsoleCounter++;
                SetConsoleCounter++;
                SetCursorCoord_XY(30, SetConsoleCounter);
                printf("\xAF\xDD INFO - FILE \xDD\xAF Data Reading Reached the End of Line of the Database File...");
                rewind(Database_MasterKey);
                break;
            }
        }
        if ((strcmp(DataMaster_Username, MasterPoint.Master_User) == 0) && (strcmp(DataMaster_Password, MasterPoint.Master_Password) == 0))
        {
            exist++;
            DataReadCounter++;
            SetConsoleCounter++;
            SetConsoleCounter++;
            SetCursorCoord_XY(30, SetConsoleCounter);
            printf("%-20s%-20s", "Master Username", "Master Password");
            SetConsoleCounter++;
            SetConsoleCounter++;
            SetCursorCoord_XY(30, SetConsoleCounter);
            printf("%-20s%-20s -- ENTRY DELETED -- ", MasterPoint.Master_User, MasterPoint.Master_Password);
            while (1)
            {
                fread(&MasterPoint, sizeof(MasterPoint), 1, Database_MasterKey);
                if (feof(Database_MasterKey))
                {
                    break;
                }
                else if ((strcmp(DataMaster_Username, MasterPoint.Master_User) == 0) && (strcmp(DataMaster_Password, MasterPoint.Master_Password) == 0))
                {
                    exist++;
                    DataReadCounter++;
                    SetConsoleCounter++;
                    SetConsoleCounter++;
                    SetCursorCoord_XY(30, SetConsoleCounter);
                    printf("%-20d%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s --ENTRY DELETED--", DataChange.Generated_StudentID, DataChange.stdnt_GName, DataChange.stdnt_MName, DataChange.stdnt_LName, DataChange.stdnt_Course_Codename, DataChange.stdnt_Year_Choice, DataChange.stdnt_Course_Semester, DataChange.stdnt_Username, DataChange.stdnt_Password);
                }
                else
                {
                    fwrite(&MasterPoint, 1, sizeof(MasterPoint), Database_MasterKey_Temporary);
                }
            }
            SetConsoleCounter++;
            SetConsoleCounter++;
            SetCursorCoord_XY(30, SetConsoleCounter);
            printf("\xFE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xFE");
            SetConsoleCounter++;
            SetConsoleCounter++;
            SetCursorCoord_XY(30, SetConsoleCounter);
            printf("The following Master Entries will be deleted...");
            SetConsoleCounter++;
            SetConsoleCounter++;
            SetCursorCoord_XY(30, SetConsoleCounter);
            printf("Press Any Key To Continue...");
            getch();
        }
        else
        {
            fwrite(&MasterPoint, 1, sizeof(MasterPoint), Database_MasterKey_Temporary);
        }
    }
    fclose(Database_MasterKey_Temporary);
    fclose(Database_MasterKey);
    if (exist >= 1)
    {
        Database_MasterKey = fopen("LM KeyDatabase//LM_CEA_MasterKey.lmdat", "wb+");
        Database_MasterKey_Temporary = fopen("LM KeyDatabase//TempMaster.lmdat", "rb+");
        SetConsoleCounter++;
        SetConsoleCounter++;
        SetCursorCoord_XY(30, SetConsoleCounter);
        printf("\xAF\xDD FILE #1 -> FILE#2 \xDD\xAF Data Read Completed! Preparing for Data Transport...");
        while (1)
        {
            fread(&MasterPoint, sizeof(MasterPoint), 1, Database_MasterKey_Temporary);
            if (feof(Database_MasterKey_Temporary))
            {
                break;
            }
            fwrite(&MasterPoint, 1, sizeof(MasterPoint), Database_MasterKey);
        }
        SetConsoleCounter++;
        SetConsoleCounter++;
        SetCursorCoord_XY(30, SetConsoleCounter);
        printf("\xAF\xDD FILE #1 == FILE#2 \xDD\xAF Data Transfer Complete!");
        fclose(Database_MasterKey);
        fclose(Database_MasterKey_Temporary);
        remove("LM KeyDatabase//TempMaster.lmdat");
        getch();
        FuncAdmin_Mgr_Mode();
    }
    else
    {
        FuncAdmin_Mgr_Mode();
    }
}
// MINIMAL COMMENTS ENDED AT 09/30/2018 10:55 PM
