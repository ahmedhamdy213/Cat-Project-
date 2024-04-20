#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>


#include "datastructure.h"



void creatnode(Point_t *pl)
{
    pl->head = NULL;
    pl->size = 0;
}

/*  -------------add student-------------- */


void addstudent(Point_t *pl, char name[], float record, int id, int age, char gender[], char pass[])
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    if(newnode != NULL)
    {
        printf("Booked Successfully!!\n");
        strcpy(newnode->std.name, name);
        newnode->std.record = record;
        newnode->std.id = id;
        newnode->std.age = age;
        strcpy(newnode->std.gender, gender);
        strcpy(newnode->std.pass, pass);

        newnode->next = NULL;

        if(pl->head == NULL)
        {
            pl->head = newnode;
        } 
        else
        {
            Node *q = pl->head;
            while(q->next != NULL)
            {
                q = q->next;
            }
            q->next = newnode;
        }
        pl->size++;
    }
    else
    {
        printf("NOT BOOKED\n");
    }

    FILE *pf = NULL;
    pf = fopen("Student_Info.txt", "aw");

    if(pf != NULL)
    {
        fprintf(pf,"%s,%i,%i,%f,%s,%s\n", name, id, age, record, gender, pass);
    }
    else
    {
        printf("NOT OPENED!!\n");
    }
    fclose(pf);

}


/* -----------get data student--------------- */


student * get_data_student()
{
    static student std;
   

    printf("Enter Name: ");
    gets(&std.name);

    printf("Enter Record: ");
    scanf("%f", &std.record);
    fflush(stdin);

    printf("Enter ID: ");
    scanf("%i", &std.id);
    fflush(stdin);

    printf("Enter Age: ");
    scanf("%i", &std.age);
    fflush(stdin);

    printf("Enter Gender: ");
    gets(&std.gender);

    
    printf("Enter Password: ");
    gets(&std.pass);


    return &std;
}

/*------------------remove student---------------------- */


void removestudent(Point_t *pl, int id)
{
    bool flag = false;
    Node *q = pl->head;
    Node *temp = NULL;

    if(q->std.id == id)
    {
        pl->head = q->next;
        free(q);
        pl->size--;
        return;
    }

    while(q)
    {
        if(((q->next != NULL) && (q->next->std.id ==  id)))
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
        temp = q->next;
        free(temp);
        q->next = q->next->next;
        pl->size--;
    }
    else
    {
        printf("No Id Such as You Entered!!\n");
        printf("-------------------------\n");
    }
}

/*-------------------check if ds is empty-----------------*/

int isempty(Point_t *pl)
{
    return !pl->size;
}
