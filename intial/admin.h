#ifndef _ADMIN_
#define _ADMIN_

#include "datastructure.h"

void addstudent(Point_t *pl, char name[], float record, int id, int age, char gender[], char pass[]);
student * get_data_student();
int isempty(Point_t *pl);
void removestudent(Point_t *pl, int id);


#endif