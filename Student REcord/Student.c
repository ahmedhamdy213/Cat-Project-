#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#include"Student.h"
 





 
void View_Your_Record(Point_t *pl,int id ,char password[50])
{
    int Try =3;
    //char cpy_pass[50] = password; 
   
    bool flag = false;
    Node *q = NULL;
     

    q = pl->head;
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
    
    
    if (flag)
    {
        while (Try)
        {
    
            if(strcmp(q->std.password,password) == 0)
            {

                printf("Name is %s\n", q->std.name);
                printf("Password is %s\n", q->std.password);
                printf("Gender is %s\n", q->std.gender);
                printf("ID is %i\n", q->std.id);       
                printf("Age is %i\n", q->std.age);
                printf("Record is %0.3f\n", q->std.gpa);
                printf("****************************************\n");
                break;
            }
            else
            {
                
                printf("Try again....You have %i Tries.\n",Try);
                printf("Enter password again: ");
                scanf("%s", password);
                if(strcmp(q->std.password,password) != 0)
                    Try--;
            }
            
        }
        if(Try == 0)
        {
            printf("Your Tries Have been finished!!\n");
        }
    }
    else
    {
      printf("NOT FOUND THIS IS ID!!\n");
    }
}




void Edit_Password (Point_t *pl,int id,char password [50])
{
    bool flag = false;
    Node *q = NULL;
     

    q = pl->head;
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
    int Try =3;
   
    if (flag)
    {
        while (Try)
        {
            if( strcmp(q->std.password,password) == 0 )
            {
                char New_Password[50];
                printf("Enter New Password : ");
                getchar();
                gets(&New_Password);
                strcpy(q->std.password,New_Password);
                printf("Your New Password: %s\n",q->std.password);
                break;
            }
            else
            {
                printf("Try again....You have %i Tries.\n",Try);
                printf("Enter password again: ");
                scanf("%s", password);
                if(strcmp(q->std.password,password) != 0)
                    Try--;
            }
        }
        if(Try == 0)
        {
            printf("Your Tries Have been finished!!\n");
        }
    }
    else
    {
      printf("NOT FOUND THIS IS ID!!\n");
    }

}




void Edit_Name (Point_t *pl,int id,char password [50])
{
    bool flag = false;
    Node *q = NULL;
     

    q = pl->head;
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

    int Try =3;
   
    if (flag)
    {
        while (Try)
        {
            if(strcmp(q->std.password,password) == 0)
            {
                printf("Enter New Name: ");
                getchar();
                gets(&q->std.name);
                printf("Your New Name: %s",q->std.name);
                break;
            }
            else
            {
                printf("Try again....You have %i Tries.\n",Try);
                printf("Enter password again: ");
                scanf("%s", password);
                if(strcmp(q->std.password,password) != 0)
                    Try--;
            }
        }
        if(Try == 0)
        {
            printf("Your Tries Have been finished!!\n");
        }
    }
    else
    {
      printf("NOT FOUND THIS IS ID!!\n");
    }
    
}