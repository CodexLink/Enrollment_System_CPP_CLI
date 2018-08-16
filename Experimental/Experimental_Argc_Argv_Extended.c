#include <stdio.h>   // Just Basic Input Output Header File
#include <stdlib.h>  // For SYSTEM Command
#include <conio.h>   // For Getch()
#include <windows.h> // Windows Designed Only Header, This Rips Compatibility.
#include <string.h>  // String Handling for Usage of Structure and Database
#define VERSION_NUMBER "0853-08142018-BETA"
#define PRODUCT_NAME                                                           \
  "Group LM | C CLI Enrollment System for TiP Engineering and Architecture"
#define ERROR_1 "WARN.UnableReposition"
#define ERROR_2 "WARN.Win32Disable_Denied"
#define WARN_1 "ERROR.UnableToConnect"
#define WARN_2 "ERROR.UnableToCheckStorage"
#define ACMPLT "Critical Components Checkpoint Completed"

char Argument_Initialization(argc, argv);
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
  int Argument_Checker;
  printf("\n @ Function | char Argument_Initialization(int argc, char *argv[])\n");
  // Create a Guard Checker for Exceeding Arguments

  /*if (Argument_DefaultAvailable[2] != argv[2]) {
              printf("Counter Arguments Exceeded the Required One");
      }*/
  // Create a Per Parameter All Size of Argument_DefaultAvailable will be
  // checked.
  // DO NOT Use Size!, Get Literal Function To Check for Same String.
  // NOT YET DONE.
  // Use if and dont compare anymore. It will be more harder than I thought
  for (Argument_Checker = 1; Argument_Checker < argc; Argument_Checker++) {
      if (argv[Argument_Checker] = "-fullscreen") {
        printf("Initializing Mode %s\n", argv[Argument_Checker]);
     }
      if (argv[Argument_Checker] = "-management") {
        printf("Initializing Mode %s\n", argv[Argument_Checker]);      
      }
    }
    //printf("%s == %s\n", Argument_DefaultAvailable[Argument_Checker],argv[Argument_Checker + 1]);
    //CheckerFinalArray = strcmp(Argument_DefaultAvailable[Argument_Checker],argv[Argument_Checker]);

}
