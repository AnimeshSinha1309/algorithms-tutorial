#include "stack.h"
#include <stdlib.h>


struct Stack* stack_new() {
    struct Stack* self = (struct Stack*) malloc(sizeof (struct Stack));
    self->array = (ElementType*) malloc(sizeof(ElementType) * MAX_SIZE);
    self->pointer = 0;
    return self;
}

void stack_push(struct Stack* self, ElementType val) {
    self->array[self->pointer] = val;
    self->pointer++;
}

void stack_pop(struct Stack* self) {
    self->pointer--;
}

ElementType stack_top(struct Stack* self) {
    return self->array[self->pointer - 1];
}

int stack_size(struct Stack* self) {
    return self->pointer;
}
