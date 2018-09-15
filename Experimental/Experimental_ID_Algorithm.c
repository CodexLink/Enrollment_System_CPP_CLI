#include <stdio.h>   // Just Basic Input Output Header File
#include <stdlib.h>  // For SYSTEM Command
#include <conio.h>   // For Getch()
#include <windows.h> // Windows Designed Only Header, This Rips Compatibility.
#include <time.h>    // For Time Display and Such
#include <string.h>  // String Handling for Usage of Structure and Database

int main()
{
    SYSTEMTIME GetDate_Local;
    int Year, Batch_Num = 00, BaseStart = 000, YearCont, BaseCont, Batch_NumCont, AutoCheck_Year;
    int line, counter;
    int buffer[100];
    FILE *fptr;
    FILE *fptr_open;
    fptr = fopen("IDAlgorithm_CheckFile.lmdat", "wb");

    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    /*else
    {
        printf("Checking for Batch Number Saved Data...");
        while (fgets(line, sizeof(line), fptr))
        {
            counter++;
            if (i == 9)
        }
        printf("Checking for Base Number Saved Data...");
    }*/
    /*printf("Please enter a year");
    scanf("%d", &Year);
    printf("Please enter batch number, two digits");
    scanf("%d", &Batch_Num);
    printf("Please enter base hundreth digits");
    scanf("%d", &BaseStart);
    system("CLS");
    printf("Processing and Display Output...");
    YearCont = Year % 100;
    printf("%02d - %d%d\n\n", YearCont, Batch_Num, BaseStart);
    fclose(fptr); */

    //Dependent Year Checker

    GetLocalTime(&GetDate_Local);
    AutoCheck_Year = GetDate_Local.wYear % 100;
    printf("Checker Year Report : %02d\n", AutoCheck_Year);
    printf("Batch Number Default Number is %02d\n", Batch_Num);
    printf("Base Number Default Number is %03d\n", BaseStart);
    getch();
    while (1)
    {
        if (BaseStart == 999)
        {
            printf("%02d%02d%03d\n", AutoCheck_Year, Batch_Num, BaseStart);
            fwrite(&AutoCheck_Year, sizeof(AutoCheck_Year), 1, fptr);
            fwrite(&Batch_Num, sizeof(Batch_Num), 1, fptr);
            fwrite(&BaseStart, sizeof(BaseStart), 1, fptr);
            fwrite("\n", sizeof(char), 1, fptr);
            //fprintf(fptr, "%02d%02d%03d\n", AutoCheck_Year, Batch_Num, BaseStart); For Normal Mode
            Batch_Num++;
            BaseStart = 000;
        }
        if (Batch_Num == 100)
        {
            break;
        }
        printf("%02d%02d%03d\n", AutoCheck_Year, Batch_Num, BaseStart);
        fwrite(&AutoCheck_Year, sizeof(AutoCheck_Year), 1, fptr);
        fwrite(&Batch_Num, sizeof(Batch_Num), 1, fptr);
        fwrite(&BaseStart, sizeof(BaseStart), 1, fptr);
        //fwrite("\n", sizeof(char), 1, fptr);
        //fprintf(fptr, "%02d%02d%03d\n", AutoCheck_Year, Batch_Num, BaseStart); For Normal Mode
        BaseStart++;
    }
    Sleep(2500);
    fclose(fptr);
    fptr_open = fopen("IDAlgorithm_CheckFile.lmdat", "rb");
    printf("Lets read it from the File!!!");
    system("CLS");
    Sleep(2500);
    Sleep(2500);
    counter = 0;
    Batch_Num = 00;
    BaseStart = 000;
    printf("%02d%02d%03d\n", AutoCheck_Year, Batch_Num, BaseStart);
    fseek( fptr, 1, SEEK_SET );
    while (1)
    {
        if (feof(fptr))
        {
            break;
        }
        fread(&AutoCheck_Year, sizeof(AutoCheck_Year), 1, fptr);
        fread(&Batch_Num, sizeof(Batch_Num), 1, fptr);
        fread(&BaseStart, sizeof(BaseStart), 1, fptr);
        fread(&BaseStart, sizeof(BaseStart), 1, fptr);
        printf("%d %d %d\n", AutoCheck_Year, Batch_Num, BaseStart);
        counter++;
    }
    fclose(fptr_open);
    return 0;
}
