#ifndef _ADMIN_
#define _ADMIN_

#include "datastructure.h"


void creatnode(Point_t *pl);
void addstudent(Point_t *pl, char name[], float record, int id, int age, char gender[], char pass[]);
student * get_data_student();
int isempty(Point_t *pl);
void removestudent(Point_t *pl, int id);
void display(Point_t *pl);
void data_one_student(Point_t *pl, int id);




#endif