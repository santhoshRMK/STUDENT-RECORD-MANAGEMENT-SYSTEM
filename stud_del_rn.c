
#include "student.h"


void Delete_rec(struct student **phead)
{
    char op,ch,dname[20];
    int roll;
    printf(BLUE);
    printf("------------------------------------------------------------------------------------\n");
    printf("***********************  Delete Student Record *************************************\n");
    printf("------------------------------------------------------------------------------------\n");
    printf(RESET);
    do
    {
        printf(GREEN);
        printf("-------------- delete methods ------------\n");
        printf("--          (r) for roll number         --\n");
        printf("--          (n) for name                --\n");
        printf("------------------------------------------\n");
        printf(RESET);

        printf(YELLOW);
        printf("Enter your choice:");
        printf(RESET);
        scanf(" %c",&ch);
        switch(ch)
        {
        case 'r':
            printf(CYAN);
            printf("your choosing roll number based deletion method\n");
            printf("enter the roll number to delete:");
            printf(RESET);
            scanf("%d",&roll);
            broll(phead,roll);
            break;
        case 'n':
            printf(CYAN);
            printf("your choosing  name based deletion method\n");
            printf("enter the name to delete:");
            printf(RESET);
            scanf(" %[^\n]",dname);
            bname(phead,dname);
            break;
        default:
            printf(RED);
            printf("your choosing wrong option\n");
            printf("only roll number and name based deletion are available please press n for name r for roll number\n");
            printf(RESET);
            break;
        }
        printf(YELLOW);
        printf("delete one more record (y/n):");
        printf(RESET);
        scanf(" %c",&op);
    }
    while(op=='y'||op=='Y');
    printf("--------------------------------------------------------------------------------------------------------------------------\n");
}
void broll(struct student **phead, int roll)
{
    printf(BLUE);
    printf("------------------------------------------------------------------------------------\n");
    printf("***********************  Delete Student Record using roll no ***********************\n");
    printf("------------------------------------------------------------------------------------\n");
    printf(RESET);
    struct student *temp = *phead, *prev = NULL;

    if (*phead == NULL)
    {
        printf(RED);
        printf("List is empty\n");
        printf(RESET);
        return;
    }

    while (temp != NULL && temp->roll_no != roll)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf(RED);
        printf("Roll number not found\n");
        printf(RESET);
        return;
    }

    if (prev == NULL)
        *phead = temp->next;
    else
        prev->next = temp->next;

    printf(GREEN);
    printf("Roll no %d deleted successfully\n", temp->roll_no);
    printf(RESET);
    free(temp);

    save(*phead);

    printf("------------------------------------------------------------------------------------------------------------------------\n");

}

void bname(struct student **phead, char *dname)
{
    printf(BLUE);
    printf("------------------------------------------------------------------------------------\n");
    printf("***********************  Delete Student Record using name **************************\n");
    printf("------------------------------------------------------------------------------------\n");
    printf(RESET);
    struct student *temp = *phead, *prev = NULL;

    if (*phead == NULL)
    {
        printf(RED);
        printf("List is empty\n");
        printf(RESET);
        return;
    }

    while (temp != NULL && strcmp(temp->name, dname) != 0)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf(RED);
        printf("Name not found\n");
        printf(RESET);
        return;
    }

    if (prev == NULL)
        *phead = temp->next;
    else
        prev->next = temp->next;

    printf(GREEN);
    printf("Name %s deleted successfully\n", temp->name);
    printf(RESET);
    free(temp);

    save(*phead);

    printf("------------------------------------------------------------------------------------------------------------------------------\n");
}

