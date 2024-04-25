#ifndef _USER_
#define _USER_


#include "datastructure.h"


/*
 typedef struct student_T
{
    char name[50];
    float gpa;
    int id;
    int age;
    char gender[50];
    char password[50];
    
}student;

typedef struct node
{
    student std;
    struct node *next;

}Node;


typedef struct point
{
    Node *head;
    int size;
}Point_t;
*/



void usermode();
void View_Your_Record(Point_t *pl,int id,char password [50]);
void Edit_Password (Point_t *pl,int id,char password [50]);
void Edit_Name (Point_t *pl,int id,char password [50]);

#endif