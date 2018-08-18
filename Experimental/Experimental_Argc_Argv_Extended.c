#include <stdio.h>   // Just Basic Input Output Header File
#include <stdlib.h>  // For SYSTEM Command
#include <conio.h>   // For Getch()
#include <windows.h> // Windows Designed Only Header, This Rips Compatibility.
#include <string.h>  // String Handling for Usage of Structure and Database
#define VERSION_NUMBER "0853-08142018-BETA"
#define PRODUCT_NAME "Group LM | C CLI Enrollment System for TiP Engineering and Architecture"
#define ERROR_1 "WARN.UnableReposition"
#define ERROR_2 "WARN.Win32Disable_Denied"
#define WARN_1 "ERROR.UnableToConnect"
#define WARN_2 "ERROR.UnableToCheckStorage"
#define ACMPLT "Critical Components Checkpoint Completed"

char Argument_Initialization(int argc, char *argv[]);
int Function_Start_1();
int Function_Start_2();

int main(int argc, char *argv[])
{
  int Counter_Argument;
  char ArgumentModeReturn;
  printf("Arguments Accounted on EXE Inline is %i\n\n", argc);
  for (Counter_Argument = 0; Counter_Argument < argc; Counter_Argument++)
  {
    printf("argv[%i]\t", Counter_Argument);
    printf(argv[Counter_Argument]);
    printf("\n");
  }
  if (argc > 1)
  {
    ArgumentModeReturn = Argument_Initialization(argc, argv);
  }
}

char Argument_Initialization(int argc, char *argv[]) {
  HWND consoleWindow = GetConsoleWindow();
  int CheckerFinalArray;
  int Argument_Checker;
  printf("\n @ Function | char Argument_Initialization(int argc, char *argv[])\n");
  while(Argument_Checker != argc) {
      if (strcmp(argv[Argument_Checker], "/rstrict_wnd") == 0 ) {
        SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
      }
      if (strcmp(argv[Argument_Checker], "/mgr_md") == 0 ) {
        printf("void Function_Mgr_Mode();");
      }
      Argument_Checker++;
  }
}
