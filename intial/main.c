#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "student.h"
#include "admin.h"
#include "user.h"
#include "datastructure.h"


int main()
{
    FILE *pf = NULL;
    pf = fopen("Student_Info", "w");
    Point_t p;
    creatnode(&p);

    student * std = get_data_student();
    printf("----------------------\n");
    addstudent(&p, std->name, std->record, std->id, std->age, std->gender, std->pass);
    display(&p);


    return 0;
}