#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Student.h"


 
void View_Your_Record(Point_t *pl,char name[50] ,char password [50])
{
    Node *q = pl;
    int Try =3;
  while (Try)
  {
   if(q->std.password == password && q->std.name == name )
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
}
void edit_password(Point_t *pl)
{
  Node *q = pl;
  char New_Password[50];
  printf("Enter New Password : ");
  scanf("%s",&New_Password);
  *q->std.password =New_Password;
  printf("Your New Name : %s",q->std.password);


}
void edit_Name(Point_t *pl)
{
  Node *q = pl;
  char New_Name[50];
  printf("Enter New Name : ");
  scanf("%s",&New_Name);
  *q->std.name =New_Name;
  printf("Your New Name : %s",q->std.name);
}
