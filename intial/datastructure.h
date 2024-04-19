#ifndef _DATASTRUCTURE_
#define _DATASTRUCTURE_


#include "student.h"


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


void creatnode(Point_t *pl);
void display(Point_t *pl);

#endif