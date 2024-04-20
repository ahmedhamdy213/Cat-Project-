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
    
    Point_t p;
    creatnode(&p);
    addstudent(&p,"ahmed elhosseny", 85, 22, 24, "male", "1102001");
    addstudent(&p,"salma elhosseny", 85, 44, 24, "fmale", "1102001");

    student * std = get_data_student();
    printf("----------------------\n");
    addstudent(&p, std->name, std->record, std->id, std->age, std->gender, std->pass);
    display(&p);

    int delet_std;
    printf("Enter id the student You want to delete: ");
    scanf("%i", &delet_std);
    removestudent(&p, delet_std);
    display(&p);



    return 0;
}