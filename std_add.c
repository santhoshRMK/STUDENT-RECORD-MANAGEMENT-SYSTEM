
#include "student.h"


void Add_rec(struct student **phead)
{
    printf(BLUE);
    printf("------------------------------------------------------------------------------------\n");
    printf("***********************  Add Student Record ****************************************\n");
    printf("------------------------------------------------------------------------------------\n");
    printf(RESET);
    char ch;
    FILE *fp = fopen("CPstudent Record.txt", "a");

    if(fp==NULL)
    {
        printf(RED);
        printf("file doesn't exist\n");
        printf(RESET);
        return;
    }

    do
    {
        struct student *newnode, *temp;
        int input_roll;

        newnode = malloc(sizeof(struct student));
        if(newnode == NULL)
        {
            printf(RED);
            printf("memory allocation failed\n");
            printf(RESET);
            fclose(fp);
            return;
        }
        printf(CYAN);
        printf("Enter roll number(0 = auto assign): ");
        printf(RESET);
        scanf("%d", &input_roll);

        if(input_roll == 0 || roll_exists(*phead, input_roll))
        {
            newnode->roll_no = get_least_roll(*phead);
            printf(YELLOW);
            printf("In this roll number already present so Auto-assigned roll number: %d\n", newnode->roll_no);
            printf(RESET);
        }
        else
        {
            newnode->roll_no = input_roll;
        }
        printf(WHITE);
        printf("name: ");
        scanf(" %19[^\n]", newnode->name);

        printf("percentage: ");
        scanf("%f", &newnode->percentage);
        printf(RESET);
        newnode->next = NULL;

        if(*phead == NULL)
        {
            *phead = newnode;
        }
        else
        {
            temp = *phead;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
         printf(GREEN);
        fprintf(fp, "%d,%s,%.2f\n",newnode->roll_no,newnode->name,newnode->percentage);
        printf(RESET);
        printf(YELLOW);
        printf("Add one more student record?(y/n): ");
        printf(RESET);
        scanf(" %c", &ch);
    }
    while(ch == 'y' || ch == 'Y');
    printf(GREEN);
    printf("-------------------------------------- Student record added successfully ---------------------------------------\n");
    printf(RESET);
    fclose(fp);
}


