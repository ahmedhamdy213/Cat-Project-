/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>


#include "General.h"


void data_one_student(Point_t *pl, int id)
{
    bool flag = false;
    Node *q = NULL;
    q = pl->head;   //this pointer to move each node
    while(q)
    {
        if(q->std.id == id)
        {                   
            flag = true;
            break;
        }
        else
        {
            q = q->next;
        }
    }
    
    if(flag)
    {
        printf("------------------------------------\n");
        printf("Student Data Which Has This ID\n");
        printf("Name     : %s\n", q->std.name);
        printf("ID       : %i\n", q->std.id);
        printf("Age      : %i\n", q->std.age);
        printf("Record   : %f\n", q->std.record);
        printf("Geneder  : %s\n", q->std.gender);
        printf("Password : %s\n", q->std.pass);
        printf("------------------------------------\n");
    }
    else
    {
        printf("This ID NOT FOUND!!\n");
    }
    
}*/