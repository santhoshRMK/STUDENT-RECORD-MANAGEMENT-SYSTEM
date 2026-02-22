
#include "student.h"

void  Modify_rec(struct student **phead)
{
    printf(BLUE);
    printf("------------------------------------------------------------------------------------\n");
    printf("***********************  Modified Student Record ***********************************\n");
    printf("------------------------------------------------------------------------------------\n");
    printf(RESET);

    int roll;
    float per;
    char n[20],op,option;

    printf(YELLOW);
    printf("****  your entering to the Modified Data section  ****\n");
    printf(RESET);

    do
    {
        printf(GREEN);
        printf("-------------  Modification methods -------------\n");
        printf("--              (r) for roll no                --\n");
        printf("--              (p) for percentage             --\n");
        printf("--              (n) for name                   --\n");
        printf("-------------------------------------------------\n");
        printf(RESET);

        printf(YELLOW);
        printf("Enter the choice:");
        printf(RESET);

        scanf(" %c",&op);
        switch(op)
        {
        case 'r':

            printf(CYAN);
            printf("enter the roll no to modified:");
            printf(RESET);

            scanf("%d",&roll);
            modify_rollno(phead,roll);
            break;

        case 'p':

            printf(CYAN);
            printf("enter the percentage to modified:");
            printf(RESET);

            scanf("%f",&per);
            Modify_percentage(phead,per);
            break;

        case 'n':

            printf(CYAN);
            printf("enter the name to modified:");
            printf(RESET);

            scanf(" %[^\n]",n);
            Modify_name(phead,n);
            break;

        default:
            printf(RED);
            printf("Invalid character press!\n");
            printf(RESET);
            break;
        }
        printf(YELLOW);
        printf("Any other modification is there(y/n):");
        printf(RESET);
        scanf(" %c",&option);
    }
    while(option=='y'||option=='Y');
    printf(GREEN);
    printf("------------------------------------------------------------------------------------\n");
    printf(RESET);
}


void modify_rollno(struct student **phead, int roll)
{
    printf(BLUE);
    printf("------------------------------------------------------------------------------------\n");
    printf("*********************** Modified Student Record using roll no **********************\n");
    printf("------------------------------------------------------------------------------------\n");
    printf(RESET);
    struct student *temp = *phead;

    if (*phead == NULL)
    {
        printf(RED);
        printf("List is empty\n");
        printf(RESET);
        return;
    }

    while (temp != NULL && temp->roll_no != roll)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf(RED);
        printf("Roll number %d not found\n", roll);
        printf(RESET);
        return;
    }

    printf(RED);
    printf("Old Name: %s\n", temp->name);
    printf("Old Percentage: %.2f\n", temp->percentage);

    printf("Enter new name: ");
    scanf(" %19[^\n]", temp->name);

    printf("Enter new percentage: ");
    scanf("%f", &temp->percentage);
    printf(RESET);

    printf(GREEN);
    save(*phead);
    printf("newly modified data:%d,%s,%.2f\n",temp->roll_no,temp->name,temp->percentage);
    printf("------------------------------------  Record modified successfully based on roll number  --------------------------------\n");
    printf(RESET);
}

void Modify_percentage(struct student **phead, float per)
{
    printf(BLUE);
    printf("------------------------------------------------------------------------------------\n");
    printf("***********************  Modified Student Record using percentage ******************\n");
    printf("------------------------------------------------------------------------------------\n");
    printf(RESET);
    if (*phead == NULL)
    {
        printf(RED);
        printf("List is empty\n");
        printf(RESET);
        return;
    }

    struct student *temp = *phead;
    struct student *matches[10];
    int count = 0, choice;

    while (temp != NULL)
    {
        if (fabs(temp->percentage - per) < EPS)
        {
            matches[count] = temp;
            printf("[%d].%d,%s,%.2f\n",count + 1, temp->roll_no, temp->name, temp->percentage);
            count++;
        }
        temp = temp->next;
    }

    if (count == 0)
    {
        printf(RED);
        printf("No record found with percentage %.2f\n", per);
        printf(RESET);
        return;
    }
    printf(YELLOW);
    printf("\nEnter which record you want to modify (1-%d): ", count);
    printf(RESET);
    scanf("%d", &choice);

    if (choice < 1 || choice > count)
    {
        printf(RED);
        printf("Invalid choice\n");
        printf(RESET);
        return;
    }

    temp = matches[choice - 1];

    printf(RED);
    printf("Old Roll No: %d\n", temp->roll_no);
    printf("Old Name: %s\n", temp->name);

    printf("Enter new roll number: ");
    scanf("%d", &temp->roll_no);

    printf("Enter new name: ");
    scanf(" %19[^\n]", temp->name);
    printf(RESET);
    save(*phead);

    printf(GREEN);
    printf("newly modified data:%d,%s,%.2f\n",
           temp->roll_no, temp->name, temp->percentage);
    printf("------------------------------ Record modified successfully based on percentage ---------------------------------\n");
    printf(RESET);
}

void Modify_name(struct student **phead, char *nam)
{
    printf(BLUE);
    printf("------------------------------------------------------------------------------------\n");
    printf("*********************** Modified Student Record using name *************************\n");
    printf("------------------------------------------------------------------------------------\n");
    printf(RESET);
    if (*phead == NULL)
    {
        printf(RED);
        printf("List is empty\n");
        printf(RESET);
        return;
    }

    struct student *temp = *phead;
    struct student *matches[10];
    int count = 0, choice;

    while (temp != NULL)
    {
        if (strcmp(temp->name, nam) == 0)
        {
            matches[count] = temp;
            printf("[%d].%d,%s,%.2f\n",count+1,temp->roll_no, temp->name, temp->percentage);
            count++;
        }
        temp = temp->next;
    }

    if (count == 0)
    {
        printf(RED);
        printf("Name not found\n");
        printf(RESET);
        return;
    }

    printf(YELLOW);
    printf("\nEnter which record you want to modify (1-%d): ", count);
    printf(RESET);
    scanf("%d", &choice);

    if (choice < 1 || choice > count)
    {
        printf(RED);
        printf("Invalid choice\n");
        printf(RESET);
        return;
    }

    temp = matches[choice - 1];

    printf(RED);
    printf("Old Roll No: %d\n", temp->roll_no);
    printf("Old Percentage: %.2f\n", temp->percentage);

    printf("Enter new roll number: ");
    scanf("%d", &temp->roll_no);

    printf("Enter new percentage: ");
    scanf("%f", &temp->percentage);
    printf(RESET);
    save(*phead);

    printf(GREEN);
    printf("newly modified data:%d,%s,%.2f\n",temp->roll_no, temp->name, temp->percentage);
    printf("------------------------------------------  Record modified successfully --------------------------------------------------\n");
    printf(RESET);

}


