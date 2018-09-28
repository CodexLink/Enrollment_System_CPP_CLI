#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define buffer_size 20
struct d1
{
  long int id;
  char first_name[buffer_size];
  char middle_name[buffer_size];
  char last_name[buffer_size];
  char prog[buffer_size];
};
char file[] = "db1.dat";
void add();
void read();
void search_name();
void search_prog();
void search_id();
void del_entry();
int main()
{
  while (1)
  {
    short unsigned int sel;
    char sel1[10];
    printf("1. ADD\n2. READ\n3. SEARCH - NAME\n4. SEARCH - PROGRAM\n5. SEARCH "
           "- ID\n6. DELETE - ID\nEnter number: ");
    scanf("%s", &sel1);
    sel = atoi(sel1);
    switch (sel)
    {
    case 1:
    {
      add();
      break;
    }
    case 2:
    {
      read();
      break;
    }
    case 3:
    {
      search_name();
      break;
    }
    case 4:
    {
      search_prog();
      break;
    }
    case 5:
    {
      search_id();
      break;
    }
    case 6:
    {
      del_entry();
      break;
    }
    default:
    {
      printf("\nInvalid entry.\nPlease try again.");
      _getch();
      system("cls");
      break;
    }
    }
  }
}
void add()
{
  FILE *fp;
  struct d1 d1;
  fp = fopen(file, "a");
  system("cls");
  printf("ADD\n\n");
  printf("Enter first name: ");
  scanf("%s", &d1.first_name);
  printf("Enter middle name: ");
  scanf("%s", &d1.middle_name);
  printf("Enter last name: ");
  scanf("%s", &d1.last_name);
  printf("Enter ID number: ");
  scanf("%ld", &d1.id);
  printf("Enter Program name: ");
  scanf("%s", &d1.prog);
  fwrite(&d1, sizeof(d1), 1, fp);
  printf("\nPress any key to continue . . .");
  _getch();
  system("cls");
  fclose(fp);
}
void read()
{
  system("cls");
  FILE *fp;
  struct d1 d1;
  int a = 0;
  if ((fp = fopen(file, "rb")) != NULL)
  {
    fseek(fp, 0, SEEK_END);
    int size = 0;
    size = ftell(fp);
    if (size == 0)
    {
      printf("FILE IS EMPTY");
      printf("\nPress any key to continue . . .");
      _getch();
      system("cls");
      main();
    }
    rewind(fp);
    printf("List of Students: \n");
    printf("%-12s%-12s%-12s%-12s%-12s", "First name", "Middle name",
           "Last Name", "ID", "Program name\n");
    while (1)
    {
      fread(&d1, sizeof(d1), 1, fp);
      if (feof(fp))
      {
        break;
      }
      printf("%-12s%-12s%-12s%-12d%-12s", d1.first_name, d1.middle_name,
             d1.last_name, d1.id, d1.prog);
      printf("\n");
    }
    fclose(fp);
  }
  else
  {
    printf("FILE DOES NOT EXIST");
  }
  printf("\nPress any key to continue . . .");
  _getch();
  system("cls");
}
void search_name()
{
  FILE *fp;
  struct d1 d1;
  short unsigned int found = 0, end = 0, count = 0;
  char first_name[20], middle_name[20], last_name[20];
  fp = fopen(file, "rb");
  system("cls");
  if ((fp = fopen(file, "rb")) != NULL)
  {
    fseek(fp, 0, SEEK_END);
    int size = 0;
    size = ftell(fp);
    if (size == 0)
    {
      printf("FILE IS EMPTY");
      printf("\nPress any key to continue . . .");
      _getch();
      system("cls");
      main();
    }
    rewind(fp);
    printf("SEARCH - NAME\n\n");
    printf("Enter First name: ");
    scanf("%s", &first_name);
    printf("Enter Middle name: ");
    scanf("%s", &middle_name);
    printf("Enter Last name: ");
    scanf("%s", &last_name);
    while (1)
    {
      fread(&d1, sizeof(d1), 1, fp);
      if (feof(fp))
      {
        break;
      }
      if ((strcmp(first_name, d1.first_name) == 0) &&
          (strcmp(middle_name, d1.middle_name) == 0) &&
          (strcmp(last_name, d1.last_name) == 0))
      {
        if (count == 0 && found == 0)
        {
          system("cls");
          printf("List of Students: \n");
          printf("%-12s%-12s%-12s%-12s%-12s", "First name", "Middle name",
                 "Last Name", "ID", "Program name\n");
          count++;
        }
        found++;
        printf("%-12s%-12s%-12s%-12d%-12s\n", d1.first_name, d1.middle_name,
               d1.last_name, d1.id, d1.prog);
        end++;
      }
    }
  }
  else
  {
    printf("FILE DOES NOT EXIST");
    end++;
  }
  if (end > 0)
  {
    printf("\nPress any key to continue . . .");
    _getch();
    system("cls");
    main();
  }
  if (found == 0)
  {
    system("cls");
    printf("Sorry No Record Found\n");
    printf("Press any key to continue . . .");
    _getch();
    system("cls");
  }
  fclose(fp);
}
void search_prog()
{
  FILE *fp;
  struct d1 d1;
  int found = 0, count = 0, end = 0;
  char prog[20];
  fp = fopen(file, "rb");
  system("cls");
  if ((fp = fopen(file, "rb")) != NULL)
  {
    fseek(fp, 0, SEEK_END);
    int size = 0;
    size = ftell(fp);
    if (size == 0)
    {
      printf("FILE IS EMPTY");
      printf("\nPress any key to continue . . .");
      _getch();
      system("cls");
      main();
    }
    rewind(fp);
    printf("SEARCH - COURSE\n\n");
    printf("Enter course name: ");
    scanf("%s", &prog);
    while (1)
    {
      fread(&d1, sizeof(d1), 1, fp);
      if (feof(fp))
      {
        break;
      }
      if ((strcmp(prog, d1.prog) == 0))
      {
        if (count == 0)
        {
          system("cls");
          printf("List of Students: \n");
          printf("%-12s%-12s%-12s%-12s%-12s", "First name", "Middle name",
                 "Last Name", "ID", "Program name\n");
          count++;
        }
        found = 1;
        printf("%-12s%-12s%-12s%-12d%-12s\n", d1.first_name, d1.middle_name,
               d1.last_name, d1.id, prog);
        end++;
      }
    }
  }
  else
  {
    printf("FILE DOES NOT EXIST");
    end++;
  }
  if (end > 0)
  {
    printf("\nPress any key to continue . . .");
    _getch();
    system("cls");
    main();
  }
  if (found == 0)
  {
    system("cls");
    printf("Sorry No Record Found\n");
    printf("Press any key to continue . . .");
    _getch();
    system("cls");
  }
  fclose(fp);
}
void search_id()
{
  FILE *fp;
  struct d1 d1;
  int found = 0, end = 0, count = 0;
  long int id = 0;
  system("cls");
  if ((fp = fopen(file, "rb")) != NULL)
  {
    fseek(fp, 0, SEEK_END);
    int size = 0;
    size = ftell(fp);
    if (size == 0)
    {
      printf("FILE IS EMPTY");
      printf("\nPress any key to continue . . .");
      _getch();
      system("cls");
      main();
    }
    rewind(fp);
    printf("SEARCH - ID\n\n");
    printf("Enter ID: ");
    scanf("%ld", &id);
    system("cls");
    while (1)
    {
      fread(&d1, sizeof(d1), 1, fp);
      if (feof(fp))
      {
        break;
      }
      if (id == d1.id)
      {
        found = 1;
        if (count == 0)
        {
          system("cls");
          printf("List of Students: \n");
          printf("%-12s%-12s%-12s%-12s%-12s", "First name", "Middle name",
                 "Last Name", "ID", "Program name\n");
          count++;
        }
        printf("%-12s%-12s%-12s%-12d%-12s\n", d1.first_name, d1.middle_name,
               d1.last_name, d1.id, d1.prog);
        end++;
      }
    }
  }
  else
  {
    printf("FILE DOES NOT EXIST");
    end++;
  }
  if (end > 0)
  {
    printf("\nPress any key to continue . . .");
    _getch();
    system("cls");
    main();
  }
  if (found == 0)
  {
    system("cls");
    printf("Sorry No Record Found\n");
    printf("Press any key to continue . . .");
    _getch();
    system("cls");
  }
  fclose(fp);
}
void del_entry()
{
  FILE *fp;
  FILE *fp1;
  struct d1 d1;
  int found = 0, end = 0, count = 0;
  long int id = 0;
  system("cls");
  if ((fp = fopen(file, "rb+")) != NULL &&
      (fp1 = fopen("temp.dat", "wb+")) != NULL)
  {
    fseek(fp, 0, SEEK_END);
    int size = 0;
    size = ftell(fp);
    if (size == 0)
    {
      printf("FILE IS EMPTY");
      printf("\nPress any key to continue . . .");
      _getch();
      system("cls");
      main();
    }
    rewind(fp);
    printf("DELETE - ID\n\n");
    printf("Enter ID: ");
    scanf("%ld", &id);
    system("cls");
    while (1)
    {
      fread(&d1, sizeof(d1), 1, fp);
      if (feof(fp))
      {
        break;
      }
      if (id == d1.id)
      {
        found = 1;
        if (count == 0)
        {
          system("cls");
          printf("List of Students: \n");
          printf("%-12s%-12s%-12s%-12s%-12s", "First name", "Middle name",
                 "Last Name", "ID", "Program name\n");
          count++;
        }
        printf("%-12s%-12s%-12s%-12d%-12s --ENTRY DELETED--\n", d1.first_name,
               d1.middle_name, d1.last_name, d1.id, d1.prog);
        end++;
      }
      else
      {
        fwrite(&d1, sizeof(d1), 1, fp1);
      }
    }
    fclose(fp);
    fclose(fp1);
  }
  else
  {
    printf("FILE DOES NOT EXIST");
    printf("\nPress any key to continue . . .");
    _getch();
    system("cls");
    main();
  }
  if (end > 0)
  {
    printf("\nPress any key to continue . . .");
    _getch();
    system("cls");
  }
  if (found == 0)
  {
    system("cls");
    printf("Sorry No Record Found\n");
    printf("Press any key to continue . . .");
    _getch();
    system("cls");
  }
  else
  {
    fp = fopen(file, "wb+");
    fp1 = fopen("temp.dat", "rb+");
    while (1)
    {
      fread(&d1, sizeof(d1), 1, fp1);
      if (feof(fp1))
      {
        break;
      }
      fwrite(&d1, sizeof(d1), 1, fp);
    }
  }
  fclose(fp);
  fclose(fp1);
}