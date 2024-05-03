#ifndef _DATASTRUCTURE_
#define _DATASTRUCTURE_

#include <stdio.h>
#include <string.h>

typedef struct student_T {
  char name[50];
  float record;
  int id;
  int age;
  char gender[50];
  char pass[50];

} student;

typedef struct node {
  student std;
  struct node *next;

} Node;

typedef struct Point {
  Node *head;
  int size;
} Point_t;

extern Point_t p;

#endif