#include <stdio.h>   // Just Basic Input Output Header File
#include <stdlib.h>  // For SYSTEM Command
#include <conio.h>   // For Getch()
#include <string.h>  // String Handling for Usage of Structure and Database

int Sizeof_YearChoice;
char Course_YearChoice[50];
int Sizeof_FullNamePasser;
char MainCourse_FullName_Passer[50] = "Environmental and Sanitary Engineering";
int Sizeof_SemSelection;
char Course_SemSelection[50];

int main(int argc, char *argv[]) {
    Sizeof_YearChoice = strlen(Course_YearChoice);
    Sizeof_SemSelection = strlen(Course_SemSelection);
    Sizeof_FullNamePasser = strlen(MainCourse_FullName_Passer);

char *check;
check = "\xC9\xCD\xCD \xDD SUBJECT LIST FOR %-*s %-*s \xAF Environmental and Sanitary Engineering \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB";
int length = strlen(check);
printf("Size is %i", length);
}
