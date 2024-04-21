#include <stdio.h>
#include <string.h>
#include "admin.h"


int main(){
    int mode;

    printf("Welcome to Student Record System\n");
    printf("Select mode:\n");
    printf("1.Admin mode\n");
    printf("2.User mode\n");
    scanf("%d", &mode);

    if (mode == 1) {
        adminmode();
    } else if (mode == 2) {

    } else {
        printf("Invalid ' Exit'\n");
    }
    

    return 0;
}