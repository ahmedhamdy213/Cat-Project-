
#include "admin.h"
#include "datastructure.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char AdminPassword[MaxLength] = "1234";

void adminmode(Point_t *p) {

  char EnteredPassword[MaxLength];
  char newpass[MaxLength];
  int flags = 3;

  while (flags > 0) {
    printf("enter your admin password:");
    scanf("%s", EnteredPassword);
    if ((strcmp(EnteredPassword, AdminPassword)) == 0) {
      printf("welcome Admin !");
      break;
    } else {
      flags--;
      printf("incorrect, try again\n ");
    }
  }
  if (flags == 0) {
    printf("out of trys, exit");
    return;
  }

  /****************************************************************************************/

  bool systemrun2 = true;
  int choice;

  while (systemrun2) {
    printf("**************************\n");
    printf("*   Admin options:       *\n");
    printf("* 1. Add student record  *\n");
    printf("* 2. Remove student record*\n");
    printf("* 3. View student record *\n");
    printf("* 4. View all records    *\n");
    printf("* 5. Edit admin password *\n");
    printf("* 6. Edit student grade  *\n");
    printf("* 7. Exit                *\n");
    printf("* Enter your choice:     *\n");
    printf("**************************\n");

    scanf("%d", &choice);
    fflush(stdin);
    switch (choice) {
    case 1: { // add student
      student *std = get_data_student();
      addstudent(&p, std->name, std->record, std->id, std->age, std->gender,
                 std->pass);

      break;
    }
    case 2: { // remove student
      int rem;
      printf("enter the Id:");
      scanf("%d", &rem);
      removestudent(&p, rem);

      break;
    }
    case 3: { // data one person
      int OneData;
      printf("enter the Id:");
      scanf("%d", &OneData);
      data_one_student(&p, OneData);
      break;
    }

    case 4: { // all data
      display(&p);
      break;
    }
    case 5: { // edit admin pass

      printf("enter your new pass :");
      scanf("%s", newpass);
      EditAdminPassword(newpass);
      printf("New password set to: %s\n", newpass);
      systemrun2 = false;
      break;
    }
    case 6: { // edit student degree
      int id;
      float grade;

      printf("enter the Id:");
      scanf("%d", &id);
      printf("enter wanted grade :");
      scanf("%f", &grade);
      EditStudenGrade(&p, id, grade);
      break;
    }
    case 7: { // exit
      printf("Exiting.........\n");
      systemrun2 = false;
      break;
    }
    default: {
      printf("Invalid option. Please try again.\n");
    }
    }
  }
}

/****************************************************************************************/

/*******************create node********************/
void createnode(Point_t *pl) {
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

void addstudent(Point_t *pl, char name[], float record, int id, int age,
                char gender[], char pass[]) {
  Node *check = pl->head; // this node to check id that enter is exist or not
  bool flag = false;      // used as pointer that id is exist or not

  /*this while loop to check the id which enter is exist or not*/
  while (check) {
    if (check->std.id == id) {
      flag = true;
      break;
    } else {
      check = check->next;
    }
  }

  /*if flag still false this mean that there is no id such entered */
  if (flag == false) {
    Node *newnode = (Node *)malloc(
        sizeof(Node));   // make newnode to store student data in list
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
      } else {
        Node *q = pl->head; /*if linked list already have elements push
                               newnode in rear*/
        while (q->next != NULL) {
          q = q->next;
        }
        q->next = newnode;
      }
      pl->size++;
    } else {
      printf("NOT BOOKED\n"); /*if space in memory do not booked for newnode*/
    }

    /*write new student entered by admin in outer file*/

    FILE *pf = NULL;
    pf = fopen("Student_Info.txt", "aw");

    if (pf != NULL) {
      fprintf(pf, "%s,%i,%i,%f,%s,%s\n", name, id, age, record, gender, pass);
    } else {
      printf("NOT OPENED!!\n");
    }
    fclose(pf);
  } else {
    printf("This Is Id Already Existe...\n");
  }
}

/* -----------get data student--------------- */

/*

this function to get data from admin and
this a function return a pointer student type to pass it int addstudent
function

*/
student *get_data_student() {
  static student std; /*static to be std still exist in memory don't remeove
                         after lifecycle of function*/

  printf("Enter Name: ");
  gets(&std.name);

  printf("Enter Record: ");
  scanf("%f", &std.record);
  fflush(stdin);

  printf("Enter ID: ");
  scanf("%i", &std.id);
  fflush(stdin);

  printf("Enter Age: ");
  scanf("%i", &std.age);
  fflush(stdin);

  printf("Enter Gender: ");
  gets(&std.gender);

  printf("Enter Password: ");
  gets(&std.pass);

  return &std;
}

/*------------------remove student---------------------- */

void removestudent(Point_t *pl, int id) {
  bool flag = false; /*check id for student is exist or not*/
  Node *q = pl->head;
  if (q == NULL) {
    printf("there is no student exist");
    return;
  } /*pointer to move on nodes*/
  Node *temp = NULL;

  if (q->std.id == id) /*if id which i search is existe in first node */
  {
    pl->head = q->next;
    free(q);
    q = NULL;
    pl->size--;
    return;
  }

  while (q) /*to reach the node which have the id which i search */
  {
    if (((q->next != NULL) && (q->next->std.id == id))) {
      /*
      (q->next != NULL) ->> this is to check next not qaul null beacause
      q->next->std.id  if q == null q->next->std.id make segmentation fault
      error
      */
      flag = true; // this mean that i find id
      break;
    } else {
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
  } else {
    printf("No Id Such as You Entered!!\n");
    printf("-------------------------\n");
  }
}

/*-------------------check if ds is empty-----------------*/

int isempty(Point_t *pl) { return !pl->size; }

/*------------------------print all students data-----------------*/

void display(Point_t *pl) {
  // void addstudent(Point_t *pl, char name[], float record, int id, int age,
  // char gender[], char pass[]);
  Node *q = pl->head;
  while (q) {
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

/*------------------------print one students data-----------------*/

void data_one_student(Point_t *pl, int id) {
  bool flag = false;
  Node *q = NULL;
  q = pl->head; // this pointer to move each node
  while (q) {
    if (q->std.id == id) {
      flag = true;
      break;
    } else {
      q = q->next;
    }
  }

  if (flag) {
    printf("------------------------------------\n");
    printf("Student Data Which Has This ID\n");
    printf("Name     : %s\n", q->std.name);
    printf("ID       : %i\n", q->std.id);
    printf("Age      : %i\n", q->std.age);
    printf("Record   : %f\n", q->std.record);
    printf("Geneder  : %s\n", q->std.gender);
    printf("Password : %s\n", q->std.pass);
    printf("------------------------------------\n");
  } else {
    printf("This ID NOT FOUND!!\n");
  }
}

/*******************change admin pass function********************/
void EditAdminPassword(char NewPass[MaxLength]) {
  strcpy(AdminPassword, NewPass);
}
/*******************change student degree function********************/
void EditStudenGrade(Point_t *pl, int id, float grade) {
  Node *check = pl->head;
  bool flag = false;
  /******* id checker if exist ************/
  while (check != NULL) {
    if (check->std.id == id) {
      check->std.record = grade;

      flag = true;
      break;
    }
    check = check->next;
  }
  /******* update it into student_info.txt ************/
  if (flag == true) {
    UpdateStundentInfo(pl);
    printf("grade update sucessfully \n");
  } else {
    printf("id not found\n");
  }
}
/*******************change student degree function in txt********************/

void UpdateStundentInfo(Point_t *pl) {

  FILE *pf = NULL;

  pf = fopen("Student_Info.txt", "w");

  if (pf != NULL) {
    Node *current = pl->head;
    while (current != NULL) {
      fprintf(pf, "%s,%i,%i,%f,%s,%s\n", current->std.name, current->std.id,
              current->std.age, current->std.record, current->std.gender,
              current->std.pass);
      current = current->next;
    }

  } else {
    printf("NOT OPENED!!\n");
  }
  fclose(pf);
  printf("File updated successfully.\n");
}

/*******************free linkedlist function before exit********************/
void FreeLinkedList(Point_t *pl) {
  Node *current = pl->head;
  Node *pfree;
  while (current != NULL) {
    pfree = current->next;
    free(current);
    current = pfree;
  }
}