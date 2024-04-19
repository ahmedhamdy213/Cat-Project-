#include "admin.h"
#include <stdio.h>
#include <string.h>

#define MaxLength 20
void adminmode() {
  char AdminPassword[MaxLength] = "1234";
  char EnteredPassword[MaxLength];
  int flags = 3;

  while (flags >0) {
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

  /********************************************************************/
  int choice;
  while (1) {
    printf("\nAdmin options:\n");
    printf("1. Add student record\n");
    printf("2. Remove student record\n");
    printf("3. View student record\n");
    printf("4. View all records\n");
    printf("5. Edit admin password\n");
    printf("6. Edit student grade\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      
      break;
    case 2:
      
      break;
    case 3:
      
      break;
    case 4:
      
      break;
    case 5:
    
      break;
    case 6:
      
      break;
    case 7:
      
      break;
    default:
      printf("Invalid option. Please try again.\n");
    }
  }
}

