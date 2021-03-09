#ifndef ALGORITHMS_TUTORIAL_STACK_H
#define ALGORITHMS_TUTORIAL_STACK_H

typedef int ElementType;
#define MAX_SIZE 10000

typedef struct Stack {
  ElementType * array;
  int pointer;
} Stack;

struct Stack* stack_new();
void stack_push(struct Stack* self, ElementType val);
void stack_pop(struct Stack* self);
ElementType stack_top(struct Stack* self);
int stack_size(struct Stack* self);

#endif //ALGORITHMS_TUTORIAL_STACK_H
