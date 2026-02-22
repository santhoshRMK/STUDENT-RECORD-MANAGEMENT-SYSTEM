
#include "student.h"



void Reverse_list(struct student **phead)
{
    printf(BLUE);
    printf("------------------------------------------------------------------------------------\n");
    printf("***********************  Reverse Student Record ************************************\n");
    printf("------------------------------------------------------------------------------------\n");
    printf(RESET);
    struct student *pre_node,*current_node,*next_node;
    pre_node=NULL;
    current_node=*phead;
    next_node=*phead;
    while(current_node!=NULL)
    {
        next_node=current_node->next;
        current_node->next=pre_node;
        pre_node=current_node;
        current_node=next_node;
    }
    *phead = pre_node;
    printf(GREEN);
    printf("----------------------------------- reversed the list successfully  ------------------------------------------\n");
    printf(RESET);

}
