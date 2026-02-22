
///**************  student Record management System ********************


#include "student.h"

/// function

#include "stud_reverse.c"
#include "stud_save_exit.c"
#include "stud_count.c"
#include "stud_delete_All.c"
#include "stud_del_rn.c"
#include "stud_show.c"
#include "stud_mod.c"
#include "stud_sort.c"
#include "stud_support_fun.c"
#include "std_add.c"


///main function

int main()
{
    struct student *head=0;
    free_list(&head);
    load_from_file(&head);
    char choice,op;

    printf(BLUE);
    printf("---------------------------------------------------------------------------\n");
    printf("**************  student Record management System **************************\n");
    printf("---------------------------------------------------------------------------\n");
    printf(RESET);
    printf("\n");

    do
    {
        printf(GREEN);
        printf("------------------ **** STUDENT RECORD MENU **** --------------------------\n");
        printf("--               (a) for Add a new record                                --\n");
        printf("--               (d) for Delete Records(roll no,name)                    --\n");
        printf("--               (s) for show the list                                   --\n");
        printf("--               (m) for Modify A record                                 --\n");
        printf("--               (v) for save                                            --\n");
        printf("--               (e) for Exit                                            --\n");
        printf("--               (t) for Sort the list                                   --\n");
        printf("--               (l) for Delete All the Records                          --\n");
        printf("--               (r) for Reverse the List                                --\n");
        printf("---------------------------------------------------------------------------\n");
        printf(RESET);

        printf(YELLOW);
        printf("enter  your choice:");
        printf(RESET);
        scanf(" %c",&choice);
        switch(choice)
        {
        case 'a':
            Add_rec(&head);
            Show_list(head);
            break;

        case 'd':
            Delete_rec(&head);
            Show_list(head);
            break;

        case 's':
            Show_list(head);
            break;

        case 'm':
            Modify_rec(&head);
            Show_list(head);
            break;

        case 'v':
            save(head);
            break;

        case 'e':
            Ext(head);
            break;

        case 't':
            Sort_list(&head);
            Show_list(head);
            break;

        case 'l':
            Delete_all(&head);
            Show_list(head);
            break;

        case 'r':
            Reverse_list(&head);
            Show_list(head);
            save(head);
            break;
        default:
            printf(RED);
            printf("Enter the valid options,we have only nine operation are there Available!\n");
            printf(RESET);
            break;
        }

        printf(CYAN);
        printf("\n want to perform one more function(y/n):");
        printf(RESET);
        scanf(" %c",&op);
    }
    while(op=='y' || op=='Y');
}
