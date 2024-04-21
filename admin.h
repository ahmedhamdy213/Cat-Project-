#ifndef _ADMIN_
#define _ADMIN_
#include "datastructure.h"
#include <stdio.h>
#include <string.h>

#define MaxLength 20

/******kareem****/

void createnode(Point_t *pl);
void addstudent(Point_t *pl, char name[], float record, int id, int age,
                char gender[], char pass[]);
student *get_data_student();
int isempty(Point_t *pl);
void removestudent(Point_t *pl, int id);
void display(Point_t *pl);
void data_one_student(Point_t *pl, int id);

/******belal****/
void adminmode();
void EditAdminPassword(char NewPass[MaxLength]);
void EditStudenGrade(Point_t *pl, int id, float grade);
void UpdateStundentInfo(Point_t *pl);
void FreeLinkedList(Point_t *pl);
#endif