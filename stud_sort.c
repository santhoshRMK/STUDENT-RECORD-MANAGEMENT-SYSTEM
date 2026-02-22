
#include "student.h"


void sort_name(struct student **phead);
void Sort_list(struct student **phead);

void Sort_list(struct student **phead)
{
    printf(BLUE);
    printf("------------------------------------------------------------------------------------\n");
    printf("***********************  Sort Student Record ****************************************\n");
    printf("------------------------------------------------------------------------------------\n");
    printf(RESET);
    char option,op;
    do
    {
        printf(GREEN);
        printf("--------------- sorting methods ---------------\n");
        printf("--       (n) for name                        --\n");
        printf("--       (p) for percentage                  --\n");
        printf("--       (r) for roll_no                     --\n");
        printf("-----------------------------------------------\n");
        printf(RESET);

        printf(YELLOW);
        printf("Enter your choice:");
        printf(RESET);
        scanf(" %c",&op);
        switch(op)
        {
        case 'n':
            printf(CYAN);
            printf("sorting based on name\n");
            printf(RESET);
            sort_name(phead);
            break;
        case 'p':
            printf(CYAN);
            printf("sorting based on percentage\n");
            printf(RESET);
            sort_percentage(phead);
            break;
        case 'r':
            printf(CYAN);
            printf("sorting based on roll_no\n");
            printf(RESET);
            sort_roll(phead);
            break;
        default:
            printf(RED);
            printf("only two type of sorting are available.invalid operation character are pressed\n");
            printf(RESET);
            break;
        }
        printf(YELLOW);
        printf("\n do you want to sort again(y/n):");
        printf(RESET);
        scanf(" %c",&option);
    }
    while(option=='y'||option=='Y');
    printf("--------------------------------------------------------------------------------------------------\n");
}

void sort_name(struct student **phead)
{
    printf(BLUE);
    printf("------------------------------------------------------------------------------------\n");
    printf("***********************  Sort Student Record using name ****************************\n");
    printf("------------------------------------------------------------------------------------\n");
    printf(RESET);

    struct student *i,*j;
    struct student temp;

    if(*phead==NULL || (*phead)->next==NULL)
    {
        printf(RED);
        printf("List is empty or has only one node\n");
        printf(RESET);
        return;
    }

    for(i=*phead; i->next!=NULL; i=i->next)
    {
        for(j=i->next; j!=NULL; j=j->next)
        {
            if(strcmp(i->name,j->name) > 0)
            {
                temp = *i;
                *i = *j;
                *j = temp;

                struct student *t =i->next;
                i->next=j->next;
                j->next=t;
            }
        }
    }
    save(*phead);
    printf(GREEN);
    printf("****  successfully sorted Student records by name  **** \n");
    printf(RESET);
}


void sort_percentage(struct student **phead)
{
    printf(BLUE);
    printf("------------------------------------------------------------------------------------\n");
    printf("***********************  Sort Student Record using percentage **********************\n");
    printf("------------------------------------------------------------------------------------\n");
    printf(RESET);
    struct student *i,*j;
    struct student temp;

    if(*phead==NULL)
    {
        printf(RED);
        printf("List is empty\n");
        printf(RESET);
        return;
    }

    if((*phead)->next == NULL)
    {
        printf(RED);
        printf("Only one record present, no need to sort\n");
        printf(RESET);
        return;
    }

    for(i = *phead; i->next != NULL; i = i->next)
    {
        for(j = i->next; j != NULL; j = j->next)
        {
            if(i->percentage > j->percentage)
            {
                temp = *i;
                *i = *j;
                *j = temp;

                struct student *t = i->next;
                i->next = j->next;
                j->next = t;
            }
        }
    }
    save(*phead);
    printf(GREEN);
    printf("****  successfully sorted Student records by percentage  *****\n");
    printf(RESET);
}

void sort_roll(struct student **phead)
{
    printf(BLUE);
    printf("------------------------------------------------------------------------------------\n");
    printf("***********************  Sort Student Record using roll no *************************\n");
    printf("------------------------------------------------------------------------------------\n");
    printf(RESET);
    struct student *i, *j;
    struct student temp;

    if (*phead == NULL)
    {
        printf(RED);
        printf("List is empty\n");
        printf(RESET);
        return;
    }

    if ((*phead)->next == NULL)
    {
        printf(RED);
        printf("Only one record, no need to sort\n");
        printf(RESET);
        return;
    }

    for (i = *phead; i->next != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->roll_no > j->roll_no)
            {
                temp = *i;
                *i = *j;
                *j = temp;

                struct student *t = i->next;
                i->next = j->next;
                j->next = t;
            }
        }
    }

    save(*phead);

    printf(GREEN);
    printf("****  successfully sorted Student records by roll no  ****\n");
    printf(RESET);
}

