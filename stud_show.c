
#include "student.h"


void Show_list(struct student *p)
{
    printf(GREEN);
    printf("------------------------------------------------------------------------------------\n");
    printf("***********************  Show Entire Student List  *********************************\n");
    printf("------------------------------------------------------------------------------------\n");
    printf(RESET);

    printf(CYAN);
    printf("These are the data available on the file\n");
    printf(RESET);
    char ch;
    FILE *fp = fopen("CPstudent Record.txt", "r");
    if(fp == NULL)
    {
        printf(RED);
        printf("List is empty\n");
        printf(RESET);
        return;
    }

    while((ch=fgetc(fp)) != EOF)
    {
        printf("%c",ch);
    }
    fclose(fp);
    printf(GREEN);
    printf("--------------------------------- All Data are printed successfully  -------------------------------------------\n");
    printf(RESET);
}
