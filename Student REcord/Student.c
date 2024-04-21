#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"Student.h"


 
void View_Your_Record(Point_t *pl,int id ,char password [50])
{
    int Try =3;
    
   
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
    
   if( strcmp(q->std.password,password) == 0 )
    {
    printf("Name is %s\n", q->std.name[50]);
    printf("Password is %s\n", q->std.password[50]);
    printf("Gender is %s\n", q->std.gender);
    printf("ID is %i\n", q->std.id);       
    printf("Age is %i\n", q->std.age);
    printf("Record is %0.3f\n", q->std.gpa);
    break;
    }else
    {
      Try--;
      printf("Try again uncorrect name or password You Have %d try",Try);
    }
  }
    }else
    {
      printf("Try again uncorrect id");
    }
    
 
}
void edit_password(Point_t *pl,int id,char password [50])
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
  scanf("%s",&New_Password);
  *q->std.password =New_Password;
  printf("Your New Name : %s",q->std.password);
    }else
    {
      Try--;
      printf("Try again uncorrect name or password You Have %d try",Try);
    }
  }
    }else
    {
      printf("Try again uncorrect id");
    }

}
void edit_Name(Point_t *pl,int id,char password [50])
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
  char New_Name[50];
  printf("Enter New Name : ");
  scanf("%s",&New_Name);
  *q->std.name =New_Name;
  printf("Your New Name : %s",q->std.name);
    }else
    {
      Try--;
      printf("Try again uncorrect name or password You Have %d try",Try);
    }
  }
    }else
    {
      printf("Try again uncorrect id");
    }
}
