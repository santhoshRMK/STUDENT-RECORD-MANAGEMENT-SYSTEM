
#include "student.h"


int count_stu(struct student *p)
{
    int c = 0;
    while(p != 0)
    {
        c++;
        p = p->next;
    }
    return c;
}


int count_all()
{
    printf("------------------------------------------------------------------------------------\n");
    printf("***********************  Count No of Student Record ********************************\n");
    printf("------------------------------------------------------------------------------------\n");

    FILE *fp = fopen("CPstudent Record.txt", "r");
    int roll, times = 0;
    char name[20];
    float per;

    if(fp == NULL)
    {
        printf("file doesn't exist\n");
        return 0;
    }

    while( fscanf(fp, "%d,%s,%f", &roll, name, &per) == 3 )
    {
        ++times;
    }

    fclose(fp);
    return times;
}


