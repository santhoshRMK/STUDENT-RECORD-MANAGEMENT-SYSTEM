
#include "student.h"


void Delete_all(struct student **phead)
{
    printf(BLUE);
    printf("------------------------------------------------------------------------------------\n");
    printf("********************************  Delete ALL Student Record ************************\n");
    printf("------------------------------------------------------------------------------------\n");
    printf(RESET);

    printf(YELLOW);
    printf("entering to the delete section\n");
    printf(RESET);
    struct student *temp;

    while(*phead!=NULL)
    {
        temp=*phead;
        *phead=(*phead)->next;
        free(temp);
    }
    FILE *fp=fopen("CPstudent Record.txt", "w");
    if (fp!=NULL)

    fclose(fp);

    printf(GREEN);
    printf("****  All records deleted successfully  ****\n");
    printf(RESET);
    printf("-----------------------------------------------------------------------------------------\n");
}
