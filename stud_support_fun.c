
#include "student.h"


void load_from_file(struct student **phead)
{
    FILE *fp = fopen("CPstudent Record.txt", "r");
    if(fp == NULL)
        return;

    struct student *newnode, *temp;

    while(1)
    {
        newnode = malloc(sizeof(struct student));
        if(fscanf(fp, "%d,%19[^,],%f\n",&newnode->roll_no,newnode->name,&newnode->percentage) != 3)
        {
            free(newnode);
            break;
        }

        newnode->next = NULL;

        if(*phead == NULL)
            *phead = newnode;
        else
        {
            temp = *phead;
            while(temp->next)
                temp = temp->next;
            temp->next = newnode;
        }
    }
    fclose(fp);
}

int get_least_roll(struct student *head)
{
    int used[1000] = {0};

    while(head != NULL)
    {
        if(head->roll_no > 0 && head->roll_no < 1000)
            used[head->roll_no] = 1;
        head = head->next;
    }

    for(int i = 1; i < 1000; i++)
    {
        if(!used[i])
            return i;
    }

    return 1;
}

int roll_exists(struct student *head, int roll)
{
    while(head != NULL)
    {
        if(head->roll_no == roll)
            return 1;
        head = head->next;
    }
    return 0;
}

void free_list(struct student **phead)
{
    struct student *temp;
    while(*phead)
    {
        temp = *phead;
        *phead = (*phead)->next;
        free(temp);
    }
}
