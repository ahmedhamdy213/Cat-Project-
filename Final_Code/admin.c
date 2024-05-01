#include "admin.h"
#include "datastructure.h"
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char AdminPassword[MaxLength] = "1234";
extern Point_t p;
void adminmode()
{

    char EnteredPassword[MaxLength];
    char newpass[MaxLength];
    int flags = 3;

    while (flags > 0)
    {
        printf("Enter Your Admin Password:");
        scanf("%s", EnteredPassword);
        if ((strcmp(EnteredPassword, AdminPassword)) == 0)
        {
            printf("Welcome Admin !\n");
            break;
        }
        else
        {
            flags--;
            printf("Incorrect, Try Again\n ");
        }
    }
    if (flags == 0)
    {
        printf("Out Of Trys, Exit");
        return;
    }

    /****************************************************************************************/

    bool systemrun2 = true;
    int choice;

    while (systemrun2)
    {
        printf("***************************\n");
        printf("*      Admin options:     *\n");
        printf("* 1. Add student record   *\n");
        printf("* 2. Remove student record*\n");
        printf("* 3. View student record  *\n");
        printf("* 4. View all records     *\n");
        printf("* 5. Edit admin password  *\n");
        printf("* 6. Edit student grade   *\n");
        printf("* 7. Remove All Students  *\n");
        printf("* 8. Exit                 *\n");
        printf("* Enter your choice:      *\n");
        printf("***************************\n");

        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
            case 1: // add student
            {
                student *std = get_data_student();
                if (std != NULL) {
                    addstudent(&p, std->name, std->record, std->id, std->age, std->gender,std->pass);
                }
                break;
            }
            case 2:  // remove student
            {
                int rem;
                printf("Enter The ID:");
                scanf("%d", &rem);
                removestudent(&p, rem);

                break;
            }
            case 3:  // data one person
            {
                int OneData;
                printf("Enter The ID:");
                scanf("%d", &OneData);
                data_one_student(&p, OneData);
                break;
            }

            case 4:  // all data
            {
                display(&p);
                break;
            }
            case 5:  // edit admin pass
            {
                printf("Enter Your New Password :");
                scanf("%s", newpass);
                EditAdminPassword(newpass);
                printf("New Password Set to: %s\n", newpass);
                systemrun2 = false;
                break;
            }
            case 6:  // edit student degree
            {
                int id;
                float grade;

                printf("Enter The ID:");
                scanf("%d", &id);
                printf("Enter New Grade :");
                scanf("%f", &grade);
                EditStudenGrade(&p, id, grade);
                break;
            }
            case 7:  // remove all students
            {
                FreeLinkedList(&p);
                
                break;
            }
            case 8: //exist
                printf("Exiting.........\n");
                systemrun2 = false;
                break;

            default:
            {
                printf("Invalid option. Please try again.\n");
            }
        }
    }
}

/****************************************************************************************/

/*******************create node********************/
void createnode(Point_t *pl)
{
    pl->head = NULL;
    pl->size = 0;
}

/*******************add student********************/

/*
1-this function take list that which push in it
2-stkudent name
3-student record
4-student id
5-student age
6-student gender
7-student pass
*/

void addstudent(Point_t *pl, char name[], float record, int id, int age,char gender[], char pass[])
{
    Node *check = pl->head; // this node to check id that enter is exist or not
    bool flag = false;      // used as pointer that id is exist or not

    /*this while loop to check the id which enter is exist or not*/
    while (check)
    {
        if (check->std.id == id)
        {
            flag = true;
            break;
        }
        else
        {
            check = check->next;
        }
    }

    /*if flag still false this mean that there is no id such entered */
    if (flag == false)
    {
        Node *newnode = (Node *)malloc(sizeof(Node));   // make newnode to store student data in list
        if (newnode != NULL) // check for successfully booked space memory
        {
            printf("Booked Successfully!!\n");
            /*put data entered in node which have data type of type student  */
            strcpy(newnode->std.name, name);
            newnode->std.record = record;
            newnode->std.id = id;
            newnode->std.age = age;
            strcpy(newnode->std.gender, gender);
            strcpy(newnode->std.pass, pass);
            newnode->next = NULL;

            if (pl->head == NULL) /*if newnod is the first node in the linked list*/
            {
                pl->head = newnode;
            }
            else
            {
                Node *q = pl->head; /*if linked list already have elements push newnode in rear*/
                while (q->next != NULL)
                {
                    q = q->next;
                }
                q->next = newnode;
            }
            pl->size++;
        }
        else
        {
            printf("NOT BOOKED\n"); /*if space in memory do not booked for newnode*/
        }

        /*write new student entered by admin in outer file*/

        FILE *pf = NULL;
        pf = fopen("Student_Info.txt", "aw");

        if (pf != NULL)
        {
            fprintf(pf, "%s,%i,%i,%f,%s,%s\n", name, id, age, record, gender, pass);
        }
        else
        {
            printf("NOT OPENED!!\n");
        }
        fclose(pf);
    }
    else
    {
        printf("This Is Id Already Existe...\n");
    }
}

/* -----------get data student--------------- */

/*

this function to get data from admin and
this a function return a pointer student type to pass it int addstudent
function

*/
student *get_data_student()
{

    static student std; // static to be std still exist in memory don't remeove
    // after lifecycle of function/

    printf("Enter Name: ");
    gets(std.name);

    printf("Enter ID: ");
    scanf("%i", &std.id);
    fflush(stdin);

    int checks = 3;
    float var = 0;
    while (checks)
    {
        printf("Enter Record: ");
        scanf("%f", &var);
        while (getchar() != '\n');
        if (var >= 0.0 && var <= 100.0)
        {
            std.record = var;
            break;
        }
        else
        {
            printf("Please Enter again Record between 0 && 100.\n");
            checks--;
        }
    }
    if (checks == 0)
    {
        printf("Your Tries Have Been Ended.\n");
        return NULL;
    }

    printf("Enter Age: ");
    scanf("%i", &std.age);
    fflush(stdin);

    printf("Enter Gender: ");
    gets(std.gender);

    printf("Enter Password: ");
    gets(std.pass);

    return &std;
}

/*------------------remove student---------------------- */

void removestudent(Point_t *pl, int id)
{
    bool flag = false; /*check id for student is exist or not*/
    Node *q = pl->head;
    if (q == NULL)
    {
        printf("There Is No Student!!\n");
        return;
    } /*pointer to move on nodes*/
    Node *temp = NULL;

    if (q->std.id == id) /*if id which i search is existe in first node */
    {
        pl->head = q->next;
        free(q);
        q = NULL;
        pl->size--;
        UpdateStundentInfo(pl);
        return;
    }

    while (q) /*to reach the node which have the id which i search */
    {
        if (((q->next != NULL) && (q->next->std.id == id)))
        {
            /*
            (q->next != NULL) ->> this is to check next not qaul null beacause
            q->next->std.id  if q == null q->next->std.id make segmentation fault
            error
            */
            flag = true; // this mean that i find id
            break;
        }
        else
        {
            q = q->next;
        }
    }

    if (flag) /*flag is true this mean we find id which we search */
    {
        temp = q->next;
        free(temp);
        temp = NULL;
        q->next = q->next->next;
        pl->size--;
        UpdateStundentInfo(pl);
    }
    else
    {
        printf("No Id Such as You Entered!!\n");
        printf("-------------------------\n");
    }
}

/*-------------------check if ds is empty-----------------*/

int isempty(Point_t *pl)
{
    return !pl->size;
}

/*------------------------print all students data-----------------*/

void display(Point_t *pl)
{
    // void addstudent(Point_t *pl, char name[], float record, int id, int age,
    // char gender[], char pass[]);
    {
        // void addstudent(Point_tpl, char name[], float record, int id, int age,
        // char gender[], char pass[]);
        Node *q = pl->head;
        if (q == NULL)
        {
            printf("There Are No Students!!\n");
            return;
        }

        while (q)
        {
            printf("Name is %s\n", q->std.name);
            printf("Gender is %s\n", q->std.gender);
            printf("ID is %i\n", q->std.id);
            printf("Password is %s\n", q->std.pass);
            printf("Age is %i\n", q->std.age);
            printf("Record is %0.3f\n", q->std.record);
            printf("-------------------------------------\n");

            q = q->next;
        }
    }
}

/*------------------------print one students data-----------------*/

void data_one_student(Point_t *pl, int id)
{
    bool flag = false;
    Node *q = NULL;
    q = pl->head; // this pointer to move each node
    while (q) {
        if (q->std.id == id) // check id is found or not
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
        printf("------------------------------------\n");
        printf("Student Data Which Has This ID\n");
        printf("Name     : %s\n", q->std.name);
        printf("ID       : %i\n", q->std.id);
        printf("Age      : %i\n", q->std.age);
        printf("Record   : %0.3f\n", q->std.record);
        printf("Geneder  : %s\n", q->std.gender);
        printf("Password : %s\n", q->std.pass);
        printf("------------------------------------\n");
    }
    else
    {
        printf("This ID NOT FOUND!!\n");
    }
}

/*******************change admin pass function********************/
void EditAdminPassword(char NewPass[MaxLength])
{
    strcpy(AdminPassword, NewPass);
}



/*******************change student degree function********************/
void EditStudenGrade(Point_t *pl, int id, float grade)
{
    Node *check = pl->head;
    bool flag = false;
    /******* id checker if exist ************/
    while (check != NULL)
    {
        if (check->std.id == id)
        {
            flag = true;
            break;
        }
        check = check->next;
    }
    /******* update it into student_info.txt ************/
    if (flag == true)
    {
        if (grade > 100.0 || grade < 0)
        {
            printf("The Grade Must Be Equal or Less Than 100 AND More or Equal 0.\n");
            return;
        }
        else
        {
            check->std.record = grade;
        }
        UpdateStundentInfo(pl);
        printf("Grade Update Successfully \n");
    }
    else
    {
        printf("ID NOT FOUND\n");
    }
}
/*******************change student degree function in txt********************/

void UpdateStundentInfo(Point_t *pl)
{

    FILE *pf = NULL;

    pf = fopen("Student_Info.txt", "w");

    if (pf != NULL)
    {
        Node *current = pl->head;
        
        while (current != NULL)
        {
            fprintf(pf, "%s,%i,%i,%f,%s,%s\n", current->std.name, current->std.id,
                    current->std.age, current->std.record, current->std.gender,
                    current->std.pass);
            current = current->next;
        }

    }
    else
    {
        printf("NOT OPENED!!\n");
    }
    fclose(pf);
    printf("File updated successfully.\n");
}

/*******************free linkedlist function before exit********************/
void FreeLinkedList(Point_t *pl)
{
    Node *current = pl->head;
    if(current == NULL)
    {
        printf("The List Is Empty!!\n");
        return;
    }
    while (current != NULL)
    {
        pl->head = current->next;
        free(current);
        current = pl->head;
    }
    printf("The List Has Been Destroyed And All Student Have Been Removed.\n");
}