#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>


#include "datastructure.h"



void creatnode(Point_t *pl)
{
    pl->head = NULL;
    pl->size = 0;
}


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
}


student * get_data_student()
{
    static student std;
    FILE *pf = NULL;
    pf = fopen("Student_Info.txt", "w");

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


    if(pf != NULL)
    {
        fprintf(pf,"%s,%i,%i,%f,%s,%s", std.name, std.id, std.age, std.record, std.gender, std.pass);
    }
    else
    {
        printf("NOT OPENED!!\n");
    }
    fclose(pf);

    return &std;
}