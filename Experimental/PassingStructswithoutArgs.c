#include <stdio.h>   // Just Basic Input Output Header File
#include <stdlib.h>  // For SYSTEM Command
#include <conio.h>   // For Getch()
#include <windows.h> // Windows Designed Only Header, This Rips Compatibility.
#include <time.h>    // For Time Display and Such
#include <string.h>  // String Handling for Usage of Structure and Database

struct DataSample
{
    int data1;
    int data2;
    char single;
};

int ActuallyDataToUse();

    struct DataSample Sample1;

int main()
{
    printf("\nData1 \xAF ");
    scanf("%d", &Sample1.data1);
    printf("\nData2 \xAF ");
    scanf("%d", &Sample1.data2);
    fflush(stdin);
    printf("\nSingleChar \xAF ");
    scanf("%c", &Sample1.single);
    //struct DataSample Sample2;
    //Sample2 = Sample1;
    //printf("\nData1 \xAF %d", Sample2.data1);
    //printf("\nData2 \xAF %d", Sample2.data2);
    //printf("\nSingleChar \xAF %c\n", Sample2.single);
    ActuallyDataToUse(&Sample1);
}

int ActuallyDataToUse()
{
    printf("Data1 \xAF %d", Sample1.data1);
    printf("Data2 \xAF %d", Sample1.data2);
    printf("SingleChar \xAF %c", Sample1.single);
    printf("Press any key to continue...");
    getch();
    return EXIT_SUCCESS;
}