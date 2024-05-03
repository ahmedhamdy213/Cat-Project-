#ifndef _USER_
#define _USER_

#include "datastructure.h"

/*  ahmed */
void usermode();
void View_Your_Record(Point_t *pl, int id, char password[50]);
void Edit_Password(Point_t *pl, int id, char password[50]);
void Edit_Name(Point_t *pl, int id, char password[50]);
void UpdateStundentInfo(Point_t *pl);

#endif