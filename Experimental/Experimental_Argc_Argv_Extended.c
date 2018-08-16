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
int Function(Argument_1_Bool, Argument_2_Bool);
int Function_Start_1();
int Function_Start_2();

int main(int argc, char *argv[]) {
  int a;
  char ArgumentModeReturn;
  printf("Arguments Accounted on EXE Inline is %i\n\n", argc);
  for (a = 0; a < argc; a++) {
    printf("argv[%i]\t", a);
    printf(argv[a]);
    printf("\n");
  }
  if (argc > 1) {
    ArgumentModeReturn = Argument_Initialization(argc, argv);
  }
}

char Argument_Initialization(int argc, char *argv[]) {
  int CheckerFinalArray;
  int Argument_Checker, Argument_Checker_1, Argument_1_Bool, Argument_2_Bool;
  printf("\n @ Function | char Argument_Initialization(int argc, char *argv[])\n");

  while(Argument_Checker != argc) {
      if (strcmp(argv[Argument_Checker], "-fullscreen") == 0 ) {
        Argument_1_Bool = 1;
      }
      if (strcmp(argv[Argument_Checker], "-management") == 0 ) {
        Argument_2_Bool = 1;
      }
      Argument_Checker++;
  }
  Function(Argument_1_Bool, Argument_2_Bool);
}
int Function (int Argument_1_Bool, int Argument_2_Bool) {
    if (Argument_1_Bool == 1) {
      Function_Start_1();
    }
    if (Argument_2_Bool == 1) {
      Function_Start_2();
    }
    printf("Press any key to continue...");
    getch();
    return EXIT_SUCCESS;
  }
int Function_Start_1() {
  printf("Success Start @ Function_Start_1\n");
}
int Function_Start_2() {
  printf("Success Start @ Function_Start_2\n");
}
