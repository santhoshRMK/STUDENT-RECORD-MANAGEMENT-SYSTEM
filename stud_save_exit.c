
#include "student.h"


void Ext(struct student *phead)
{
    printf(BLUE);
    printf("------------------------------------------------------------------------------------\n");
    printf("*************************************  EXIT ****************************************\n");
    printf("------------------------------------------------------------------------------------\n");
    printf(RESET);

    printf(RED);
    printf(" warning! you should save the data and  exit  or without saving and exit\n");
    printf(RESET);

    char op;

    printf(GREEN);
    printf("-----------------------------------\n");
    printf("--      (s)for save and exit     --\n");
    printf("--      (e) for without saving   --\n");
    printf("-----------------------------------\n");
    printf(RESET);

    printf(YELLOW);
    printf("enter your choice:");
    printf(RESET);
    scanf(" %c",&op);
    switch(op)
    {
    case 's':
        save(phead);
        exit(0);
        break;
    case 'e':
        printf(RED);
        printf("exit without saving the data\n");
        printf(RESET);
        exit(0);
        break;
    default:
        printf(RED);
        printf("choose:(s)or (e) no other option are available\n");
        printf(RESET);
        break;
    }
}

void save(struct student *p)
{
    printf(BLUE);
    printf("------------------------------------------------------------------------------------\n");
    printf("*************************************  SAVE ****************************************\n");
    printf("------------------------------------------------------------------------------------\n");
    printf(RESET);
    FILE *fp = fopen("CPstudent Record.txt","w");
    if(fp==NULL)
    {
        printf(RED);
        printf("File doest exist\n");
        printf(RESET);
    }
    while(p!=NULL)
    {
        fprintf(fp, "%d,%s,%.2f\n",p->roll_no,p->name,p->percentage);
        p=p->next;
    }
    fclose(fp);
    printf(GREEN);
    printf("****  data saved and exit  ****\n");
    printf(RESET);
}

