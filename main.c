#include "admin.h"
#include "user.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main() {
    int mode;
    bool systemRun = true;  
    Point_t p;
    createnode(&p);

    while (systemRun) {
        printf("Welcome to Student Record System\n");
        printf("Select mode:\n");
        printf("1.Admin mode\n");
        printf("2.User mode\n");
        printf("3.Exit from system\n");
        printf("Enter your choice: ");
        scanf("%d", &mode);
        fflush(stdin);  

        switch (mode) {
        case 1:
            adminmode(&p);
            break;
        case 2:
            usermode(&p);
            break;
        case 3:
            printf("Exiting.........\n");
            sleep(1);  
            printf("\nHave a nice day :>\n");
            FreeLinkedList(&p); 
            systemRun = false;  
            break;
        default:
            printf("Invalid choice, try again.\n");
        }
    }
    return 0;  
}
