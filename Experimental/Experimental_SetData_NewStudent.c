#include <stdio.h>   // Just Basic Input Output Header File
#include <stdlib.h>  // For SYSTEM Command
#include <conio.h>   // For Getch()
#include <windows.h> // Windows Designed Only Header, This Rips Compatibility.
#include <time.h>    // For Time Display and Such
#include <string.h>  // String Handling for Usage of Structure and Database
#define VERSION_NUMBER "2259-08102018-BETA"
#define PRODUCT_NAME "Group LM | C CLI Enrollment System for TiP Engineering and Architecture"
struct New_StudentRecords
{
    char std_FName[30];
    char std_MName[30];
    char std_LName[30];
    char std_Gender[1];
    char std_Birthday[30];
    char std_Nationality[10];
    char std_SpecialBehavioral[50];
    char std_Address[MAX_PATH];
    int std_PhoneNum; 
    int std_MobileNum; 
    int std_EmerNum;
    char std_stdEmail[40];
    char POC_Emergency[30];
};
int DataReceiver();
int main()
{
    // Init Variable, I cannot assign a string in struct.
    struct New_StudentRecords NewData;
    strcpy(NewData.std_FName, "No First Name Set..."); 
    strcpy(NewData.std_MName, "No Middle Name Set...");
    strcpy(NewData.std_LName, "No Last Name Set...");
    strcpy(NewData.std_Gender, "None...");
    strcpy(NewData.std_Birthday, "No Birthday Set...");
    strcpy(NewData.std_Nationality, "No Nationality Sets...");
    strcpy(NewData.std_SpecialBehavioral, "No Precautions Set...");
    strcpy(NewData.std_Address, "No Address Set...");
    NewData.std_PhoneNum = 0; 
    NewData.std_MobileNum = 0; 
    NewData.std_EmerNum = 0;
    strcpy(NewData.std_stdEmail, "No Email Set...");
    strcpy(NewData.POC_Emergency, "No Point of Contact Set...");

    int DataComplete = 0, Choice_Break = 0, Choice_FillInfo;
    system("CLS");
    while (DataComplete != 1)
    {
        SetConsoleTitle(PRODUCT_NAME);
        puts("---------------------------------------------------------------------------------------------------");
        printf("--! 1st Step - Input your Personal Information | 2nd | 3rd | 4th | Confirm | End\n");
        printf("++ Information: Please provide your information to let us identify you as a future student!\n");
        printf("Fill up the Following by Selecting their numbers assigned to...\n");
        puts("---------------------------------------------------------------------------------------------------");
        // IDENTITY INFORMATION
        printf("\n [1] First Name: %s \t\t", NewData.std_FName);
        printf("\n [2] Middle Name: %s \t\t", NewData.std_MName);
        printf("\n [3] Last Name: %s \t\t\n", NewData.std_LName);
        puts("---------------------------------------------------------------------------------------------------");
        //GENERAL INFORMATION
        printf("\n [4] Gender: %s \t\t", NewData.std_Gender);
        printf("\n [5] Birthday:  %s \t\t", NewData.std_Birthday);
        printf("\n [6] Home (Main) Address: %s \t\t", NewData.std_Address); //Include City and Village, ZIP CODE
        printf("\n [7] Nationality: %s \t\t\n", NewData.std_Nationality);
        puts("---------------------------------------------------------------------------------------------------");
        // TECHNICAL INFORMATION
        printf("\n [8] Mobile Number: %li \t\t", NewData.std_MobileNum);
        printf("\n [9] Phone Number:  %li \t\t", NewData.std_PhoneNum);
        printf("\n [10] Emergency Number and Emergency Point of Contact (Seperated)): %li | %s", NewData.std_EmerNum, NewData.POC_Emergency);
        printf("\n [11] Personal Email: %s \t\t", NewData.std_stdEmail);
        printf("\n [Behavioral Issues]: %s \t\t", NewData.std_SpecialBehavioral);
        printf("\nStopped.");
        getch();
        if (Choice_FillInfo == 0)
        {
            printf("There is no current choice to fill an information!");
        }
        else
        {
            printf("Current Choice to Fill is assigned to #%i", Choice_FillInfo);
        }
        printf("Please enter a desired number to fill up information...");
        scanf("%i", &Choice_FillInfo);
        while (Choice_Break != 1)
        {
            switch (Choice_FillInfo)
            {
            case 1:
                printf("NAN");
            case 2:
                printf("NAN");
            case 3:
                printf("NAN");
            case 4:
                printf("NAN");
            case 5:
                printf("NAN");
            case 6:
                printf("NAN");
            case 7:
                printf("NAN");
            case 8:
                printf("NAN");
            case 9:
                printf("NAN");
            case 10:
                printf("NAN");
            case 11:
                printf("NAN");
            case 12:
                printf("NAN");
            default:
                printf("Input Exceed from the Number Given in the Menu!");
                Sleep(2000);
            }
        }
        continue; // Continue from this Loop Instead from the Inside Loop
    }
}

int DataReceiver(struct New_StudentRecords NewData_Receiver)
{
}
