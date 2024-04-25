#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "datastructure.h"
#include "user.h"
extern Point_t p;
void usermode() {
  bool systemrun3 = true;
  int choice;

  while (systemrun3) {
    printf("*********************\n");
    printf("*    User options:  *\n");
    printf("* 1. View Your Record *\n");
    printf("* 2. Edit Password    *\n");
    printf("* 3. Edit Name        *\n");
    printf("* 4. Exit             *\n");
    printf("* Enter your choice: *\n");
    printf("*********************\n");
    scanf("%d", &choice);
    fflush(stdin);
    switch (choice) {
    case 1: {
      int id;
      printf("enter you id:");
      scanf("%d", &id);
      char password[50];
      printf("enter your password:");
      scanf("%s", password);
      View_Your_Record(&p, id, password);
      break;
    }
    case 2: {
      int id;
      printf("enter you id:");
      scanf("%d", &id);
      char password[50];
      printf("enter your password:");
      scanf("%s", password);
      fflush(stdin);
      Edit_Password(&p, id, password);
      break;
    }
    case 3: {
      int id;
      printf("enter you id:");
      scanf("%d", &id);
      char password[50];
      printf("enter your password:");
      scanf("%s", password);
      fflush(stdin);
      Edit_Name(&p, id, password);
      break;
    }
    case 4: {
      printf("Exiting.........\n");
      systemrun3 = false;
      break;
    }
    default: {
      printf("Invalid option. Please try again.\n");
    }
    }
  }
}

void View_Your_Record(Point_t *pl, int id, char password[50]) {
  int Try = 3;
  // char cpy_pass[50] = password;

  bool flag = false;
  Node *q = NULL;

  q = pl->head;
  while (q) {
    if (q->std.id == id) {
      flag = true;
      break;
    } else {
      q = q->next;
    }
  }

  if (flag) {
    while (Try) {

      if (strcmp(q->std.pass, password) == 0) {

        printf("Name is %s\n", q->std.name);
        printf("Password is %s\n", q->std.pass);
        printf("Gender is %s\n", q->std.gender);
        printf("ID is %i\n", q->std.id);
        printf("Age is %i\n", q->std.age);
        printf("Record is %0.3f\n", q->std.record);
        printf("****************************************\n");
        break;
      } else {

        printf("Try again....You have %i Tries.\n", Try);
        printf("Enter password again: ");
        scanf("%s", password);
        if (strcmp(q->std.pass, password) != 0)
          Try--;
      }
    }
    if (Try == 0) {
      printf("Your Tries Have been finished!!\n");
    }
  } else {
    printf("NOT FOUND THIS IS ID!!\n");
  }
}

void Edit_Password(Point_t *pl, int id, char password[50]) {
  bool flag = false;
  Node *q = NULL;

  q = pl->head;
  while (q) {
    if (q->std.id == id) {
      flag = true;
      break;
    } else {
      q = q->next;
    }
  }
  int Try = 3;

  if (flag) {
    while (Try) {
      if (strcmp(q->std.pass, password) == 0) {
        char New_Password[50];
        printf("Enter New Password : ");
        gets(New_Password);
        strcpy(q->std.pass, New_Password);
        printf("Your New Password: %s\n", q->std.pass);
        break;
      } else {
        printf("Try again....You have %i Tries.\n", Try);
        printf("Enter password again: ");

        gets(password);
        if (strcmp(q->std.pass, password) != 0)
          Try--;
      }
    }
    if (Try == 0) {
      printf("Your Tries Have been finished!!\n");
    }
  } else {
    printf("NOT FOUND THIS IS ID!!\n");
  }
}

void Edit_Name(Point_t *pl, int id, char password[50]) {
  bool flag = false;
  Node *q = NULL;

  q = pl->head;
  while (q) {
    if (q->std.id == id) {
      flag = true;
      break;
    } else {
      q = q->next;
    }
  }
  int Try = 3;

  if (flag) {
    while (Try) {
      if (strcmp(q->std.pass, password) == 0) {
        printf("Enter New Name: ");
        // getchar();
        gets(q->std.name);
        printf("Your New Name: %s", q->std.name);
        break;
      } else {
        printf("Try again....You have %i Tries.\n", Try);
        printf("Enter password again: ");
        // getchar();
        gets(password);
        if (strcmp(q->std.pass, password) != 0)
          Try--;
      }
    }
    if (Try == 0) {
      printf("Your Tries Have been finished!!\n");
    }
  } else {
    printf("NOT FOUND THIS IS ID!!\n");
  }
  printf("\n");
}