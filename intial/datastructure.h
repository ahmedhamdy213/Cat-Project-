#ifndef _DATASTRUCTURE_
#define _DATASTRUCTURE_


//#include "student.h"

/*what node consist of*/



typedef struct student_T
{
    char name[30];
    float record;
    int id;
    int age;
    char gender[10];
    char pass[10];
    
}student;



typedef struct node
{
    student std;
    struct node *next;

}Node;


/*list which make node and take first node*/
typedef struct point
{
    Node *head;
    int size;
}Point_t;




//void show_one_student_record(Point_t *pl, int id);

#endif