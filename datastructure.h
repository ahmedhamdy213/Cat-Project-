#ifndef _DATASTRUCTURE_
#define _DATASTRUCTURE_

#include "student.h"

typedef struct node {
  student std;
  struct node *next;

} Node;

typedef struct Point {
  Node *head;
  int size;
} Point_t;

#endif