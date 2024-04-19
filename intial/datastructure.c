#include <stdio.h>
#include "datastructure.h"


void display(Point_t *pl)
{
    //void addstudent(Point_t *pl, char name[], float record, int id, int age, char gender[], char pass[]);
    Node *q = pl->head;
    while(q)
    {
        printf("Name is %s\n", q->std.name);
        printf("Gender is %s\n", q->std.gender);
        printf("ID is %i\n", q->std.id);
        printf("Password is %s\n", q->std.pass);
        printf("Age is %i\n", q->std.age);
        printf("Record is %f\n", q->std.record);
        printf("-------------------------------------\n");

        q = q->next;
    }
}