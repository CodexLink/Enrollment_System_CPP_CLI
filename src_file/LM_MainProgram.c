/*==============================================================================
Group LM - Enrollment System in C for Preliminary Project in Programming
Enrollment System, Version 1856-08102018 - BETA
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
#define ERROR_1 "WARN.UnableReposition"
#define ERROR_2 "WARN.Win32Disable_Denied"
#define WARN_1 "ERROR.UnableToConnect"
#define WARN_2 "ERROR.UnableToCheckStorage"
#define ACMPLT "Critical Components Checkpoint Completed"

struct StudentRecords {
  int user_StudentIdentity[7];
  char user_Username, user_Password, user_UserPersonalName;
};
struct New_StudentRecords {
  char user_Name;
  char user_Birthday;
  char user_MName, user_FName, user_Nationality;
};
int OldStd_Logon();
char stdnt_NumberCreate(); // Function that creates a number
char CriticalComp_Check(); // Checks and Sets Components Before Initializing
void OldStd_Func();        // Function for Old Student
void NewStd_Func();        // Function for New Student
void NewStd_ContinuationFunc();
void OldStd_Func_Enrollment_Eng(struct StudentRecords UserIdentity);
int main(int argc, char *argv[]) {
  int Selection_1;
  puts("-----------------------------");
  printf("Version " VERSION_NUMBER "\n");
  printf(PRODUCT_NAME "\n");
  puts("-----------------------------");
  CriticalComp_Check();   // Init Function to Check for Critical Components Before Proceeding
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
  case 2:
    NewStd_Func();
  case 3:
    NewStd_ContinuationFunc();
  case 4:
  puts("Terminating Enrollment System...");
  Sleep(3000);
  return EXIT_SUCCESS;
  default:
    printf("Invalid Choice");
    return;
  }
}

void OldStd_Func() {
  int user_StudentIdentity[7];
  char user_Username, user_Password;
  SetConsoleTitle("LM Enrollment System | Old Student Login");
  printf("Please enter your Username: ");
  scanf("%c", &user_Username);
  printf("Please enter your Password: ");
  scanf("%c", &user_Password);
  printf("Please enter your Student Number: ");
  scanf("%i", &user_StudentIdentity);
  // if (insert database here) = TRUE then
  printf("Hello and Welcome %c %i !", user_Username, user_StudentIdentity);
  printf("Loading...");
  OldStd_Func_Enrollment(user_Username, user_StudentIdentity); // else OldStd_Func. No Limit Attempts
}
void OldStd_Func_Enrollment_Eng(struct StudentRecords UserIdentity) {
  SetConsoleTitle("LM Enrollment System | Old Student Login");
  char *ENRL_Selection_Eng[4] = {"1st Year College", "2nd Year College", "3rd Year College", "4th Year College"};
  char ENRL_Stats_CurrentLevel, ENRL_Stats_Eligible;
  int Counter_For_Selection = 0;
  printf("-----------------------------");
  printf("Hello and Welcome %c", UserIdentity.user_Username);
  Sleep(2000);
  printf("-----------------------------");
  printf("Name %s | Student Number: %i", UserIdentity.user_UserPersonalName, UserIdentity.user_StudentIdentity);
  printf("Your Current Level is %c", ENRL_Stats_CurrentLevel);
  printf("Enrollment Eligibility %c", ENRL_Stats_Eligible);
  for (Counter_For_Selection; Counter_For_Selection < 5; Counter_For_Selection++) { 
    printf(ENRL_Selection_Eng[Counter_For_Selection]);
}
Sleep(999);
//Create Selectables Here for Array
void NewStd_Func() {
  SetConsoleTitle("LM Enrollment System | New Student Creation");
  char user_Name;
  char user_Birthday;
  char user_MName, user_FName, user_Nationality;

}
char stdnt_NumberCreate() {

  SetConsoleTitle("LM Enrollment System | Generating Number Identity...");
  SYSTEMTIME Btch_Year;
  char Created_Student_NumData;
  GetLocalTime(&Btch_Year); // Win32 Module Function
  // Get Current Batch and Student Number
  printf("Created Student Number Data(Untouched) %d | ",Btch_Year.wYear); // Another Two Predicted Values are Btch_Num,
                           // Btch_StudentNum.
  return Created_Student_NumData;
}

char CriticalComp_Check() {
  char ModeArgumentSet = 0, ReturnCodeChar = 0;
  SetConsoleTitle("Intializing and Checking Critical Components | LM Enrollment System\n");
  printf("Initializing and Checking Critical Components Before Actual Program Initialization\n");
  printf("COMPONENT #   | TITLE   \t  STATUS\n");
  printf("Init.Component # 1 | Resize and Move the Command Line with Respective Ordered Values\n");
  HWND console = 0;
  RECT ConsoleMainApp;
  MoveWindow(console, ConsoleMainApp.left, ConsoleMainApp.top, 1000, 500, TRUE);
  printf("Init.Component # 2 | Disable Close Button\n");
  HWND hwnd = GetConsoleWindow();
  HMENU hmenu = GetSystemMenu(hwnd, FALSE);
  EnableMenuItem(hmenu, SC_CLOSE, MF_GRAYED);
  EnableMenuItem(hmenu, WS_MAXIMIZEBOX, MF_GRAYED);
  printf("Component # 3 | Checking Local Datbase on Local Storage (Using LibaryXLSWWriter)\n");
  FILE *FileDatabase;
  // fp = fopen ("file.txt", "w+");
  FileDatabase = fopen("data/2018_LM_Database.dat", +r);
  if (FileDatabase = NULL) {
      printf("Local Database wasn't found~! Creating Local Database to Store Enrollment Data...");
        // Insert Frite Here
  } else {
      printf("Local Database Found!");
  }
      printf("");
  }
  // printf("Initializing Mode | %c", ModeArgumentSet);
  if ((strstr(ERROR_1, ReturnCodeChar)) || (strstr(ERROR_2, ReturnCodeChar)) ||
      (strstr(WARN_1, ReturnCodeChar)) || (strstr(WARN_2, ReturnCodeChar))) == TRUE)
    {
      ReturnCodeChar = "ACMPLT";
      printf("%s", ReturnCodeChar);
      Sleep(3000);
    }
    if (PostReturn == ERROR_1 || ERROR_2) {
    printf("Most of the Critical Components where unable to compile. Terminating the program in 3 seconds.");
    Sleep(3000);
    return EXIT_FAILURE;
  } else if (PostReturn == WARN_1 || WARN_2) {
    printf("Few Critical Components where unable to compile. Although it's an optional critical component, Proceeding...");
    Sleep(2500); // Wait Before Continue, Time In milliseconds
  } else {
    printf("One or more critical components has failed to comply! Terminating...\n Exit Code is %d", PostReturn);
    Err_CodeValue = GetLastError(); // A Function Defined in Windows.H to show what error that would be. (Win32API)
    return Err_CodeValue;
  }
}