#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>


#include "admin.h"
#include "user.h"
#include "datastructure.h"


int main()
{
    
    Point_t p;
    creatnode(&p);
    addstudent(&p,"ahmed elhosseny", 85, 22, 24, "male", "1102001");
    addstudent(&p,"salma elhosseny", 85, 44, 24, "fmale", "1102001");


   /* student * std = get_data_student();
    printf("----------------------\n");
    addstudent(&p, std->name, std->record, std->id, std->age, std->gender, std->pass);
    display(&p);

    int delet_std;
    printf("Enter id the student You want to delete: ");
    scanf("%i", &delet_std);
    removestudent(&p, delet_std);
    display(&p);*/


    /*int print_data_id;
    printf("Enter ID to print data: ");
    scanf("%i", &print_data_id);
    data_one_student(&p, print_data_id);*/

    int id = 0;
    char pass[20];

    printf("Enter your id: ");
    scanf("%i", &id);
    fflush(stdin);

    printf("Enter Your password: ");
    scanf("%s", pass);
    fflush(stdin);

    Edit_Name(&p, id, pass);





    return 0;
}