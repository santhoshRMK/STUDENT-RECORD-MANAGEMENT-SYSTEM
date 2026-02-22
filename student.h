#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define EPS 0.01

#define RESET   "\033[0m"

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"

 /// Structure records

struct student
{
    int roll_no;
    char name[20];
    float percentage;
    struct student *next;

};

///function Declaration
void Add_rec(struct student **);
void Show_list();
void save(struct student *);
void Ext(struct student *);
void Delete_all(struct student **);
void Reverse_list(struct student **);
int count_stu(struct student *);
int count_all();

///delete function declaration
void Delete_rec(struct student **);
// delete sub function
void broll(struct student **, int);
void bname(struct student **, char *);

///modification records function call
void Modify_rec(struct student **);
// modify sub function
void modify_rollno(struct student **, int);
void Modify_percentage(struct student **, float);
void Modify_name(struct student **, char *);

/// sorting function declaration
void Sort_list(struct student **);
// sorting sub function
void sort_name(struct student **);
void sort_percentage(struct student **);
void sort_roll(struct student **phead);

/// support function declaration
void load_from_file(struct student **phead);
//int random_roll(struct student *head);
int roll_exists(struct student *head, int roll);
void free_list(struct student **phead);

#endif
