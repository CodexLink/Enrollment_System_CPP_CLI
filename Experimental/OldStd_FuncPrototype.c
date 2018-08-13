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

struct StudentRecords { // SET NG VARIABLES NA GAGAMITIN SA LOGIN CREDENTIALS
    int user_StudentIdentity;
    char user_Username[10], user_Password[32], user_UserPersonalName[20];
};

//FUNCTION DEFINITION PARA MALAMAN NG COMPILER NA MAY GANITONG FUNCTION SA BABA NG INT MAIN()
void Receiver(struct StudentRecords OldStudent_Continuation);

int main() {
	/*
	HWND hwnd = GetConsoleWindow();
	DWORD style = GetWindowLong(hwnd, GWL_STYLE);
	style &= ~WS_MAXIMIZEBOX;
	SetWindowLong(hwnd, GWL_STYLE, style);
	SetWindowPos(hwnd, NULL, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE|SWP_FRAMECHANGED);
	*/
    HWND handle = GetConsoleWindow();
    HMENU hmenu = GetSystemMenu(handle, FALSE);
    EnableMenuItem(hmenu, SC_CLOSE, MF_DISABLED);
    struct StudentRecords OldStudent; // Call Struct StudentRecords pero lagyan natin ng Identity na Oldstudent.
    // Parehas ng set of variables na gagamitin pero ibang identity.
    SetConsoleTitle("LM Enrollment System | Old Student Login");
    printf("Please enter your Username: ");
    scanf("%s", OldStudent.user_Username); // Walang & kasi naka Array Tayo
    printf("Please enter your Password: ");
    scanf("%s", OldStudent.user_Password); // Walang & kasi naka Array Tayo
    printf("Please enter your Student Number: ");
    scanf("%d", &OldStudent.user_StudentIdentity);
    // if (insert database here) = TRUE then
    printf("Hello %s | %d!\n", OldStudent.user_Username, OldStudent.user_StudentIdentity); // Where IdentityStruc.VariableName
    printf("Also your password is %s\n", OldStudent.user_Password);
    Receiver(OldStudent); // else OldStd_Func. No Limit Attempts // Run Muna To
    return ERROR_SUCCESS;
}

void Receiver(struct StudentRecords OldStudent_Continuation) { // Get OldStudent's Content and Create Another Identity to Pass On
	puts("Passed Structure from int main() are the following:");
    printf("%s\n", OldStudent_Continuation.user_Password);
    printf("%s\n", OldStudent_Continuation.user_Username);
    printf("%i\n", OldStudent_Continuation.user_StudentIdentity);
    getch(); // Wait for Input
}
