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

/*
1-this function take list that which push in it
2-stkudent name
3-student record
4-student id
5-student age
6-student gender
7-student pass
*/

void addstudent(Point_t *pl, char name[], float record, int id, int age, char gender[], char pass[])
{
    Node *check = pl->head;             //this node to check id that enter is exist or not 
    bool flag = false;                 //used as pointer that id is exist or not

    /*this while loop to check the id which enter is exist or not*/
    while(check)
    {
        if(check->std.id == id)
        {
            flag = true;
            break;
        }
        else
        {
            check = check->next;
        }

    }


    /*if flag still false this mean that there is no id such entered */
    if(flag == false)
    {
        Node *newnode = (Node *)malloc(sizeof(Node));           // make newnode to store student data in list
        if(newnode != NULL)                                     // check for successfully booked space memory
        {
            printf("Booked Successfully!!\n");
            /*put data entered in node which have data type of type student  */
            strcpy(newnode->std.name, name);
            newnode->std.record = record;
            newnode->std.id = id;
            newnode->std.age = age;
            strcpy(newnode->std.gender, gender);
            strcpy(newnode->std.pass, pass);
            newnode->next = NULL;

            if(pl->head == NULL)        /*if newnod is the first node in the linked list*/
            {
                pl->head = newnode;
            } 
            else
            {
                Node *q = pl->head;         /*if linked list already have elements push newnode in rear*/
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
            printf("NOT BOOKED\n");     /*if space in memory do not booked for newnode*/
        }

        /*write new student entered by admin in outer file*/

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
    else
    {
        printf("This Is Id Already Existe...\n");
    }

}


/* -----------get data student--------------- */

/*

this function to get data from admin and 
this a function return a pointer student type to pass it int addstudent function

*/
student * get_data_student()
{
    static student std;    /*static to be std still exist in memory don't remeove after lifecycle of function*/
   

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
    bool flag = false;     /*check id for student is exist or not*/
    Node *q = pl->head;     /*pointer to move on nodes*/
    Node *temp = NULL;      

    if(q->std.id == id)         /*if id which i search is existe in first node */
    {
        pl->head = q->next;     
        free(q);
        q = NULL;
        pl->size--;
        return;
    }

    while(q)  /*to reach the node which have the id which i search */
    {
        if(((q->next != NULL)  && (q->next->std.id ==  id)))
        {
            /*
            (q->next != NULL) ->> this is to check next not qaul null beacause q->next->std.id  if q == null 
            q->next->std.id make segmentation fault error
            */
            flag = true;   //this mean that i find id 
            break;
        }
        else
        {
            q = q->next;
        }
    }

    if(flag) /*flag is true this mean we find id which we search */
    {
        temp = q->next;
        free(temp);
        temp = NULL;
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


/*------------------------print all students data-----------------*/
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
        printf("Record is %0.3f\n", q->std.record);
        printf("-------------------------------------\n");

        q = q->next;
    }
}
