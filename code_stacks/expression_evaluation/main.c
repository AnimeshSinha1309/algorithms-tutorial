#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#include "stack.h"


int evaluate(char* eval_string) {
    Stack* st = stack_new();
    int eval_string_len = (int) strlen(eval_string);
    for (int i = 0; i < eval_string_len; i++) {
        if (isdigit(eval_string[i])) {
            // Put the digit on the stack
            int value = eval_string[i] - '0';
            stack_push(st, value);
        } else {
            // Pop 2 values from stack
            assert(stack_size(st) >= 2);
            int val2 = stack_top(st);
            stack_pop(st);
            int val1 = stack_top(st);
            stack_pop(st);
            // Operate and push back result
            int result;
            if (eval_string[i] == '+') {
                result = val1 + val2;
            } else if (eval_string[i] == '-') {
                result = val1 - val2;
            } else if (eval_string[i] == '*') {
                result = val1 * val2;
            } else if (eval_string[i] == '/') {
                result = val1 / val2;
            } else if (eval_string[i] == '%') {
                result = val1 % val2;
            } else {
                assert(0);
            }
            stack_push(st, result);
        }
    }
    // Print the result of evaluation
    int final_result = stack_top(st);
    assert(stack_size(st) == 1);
    return final_result;
}

char* convert_infix_to_postfix(char* infix_string) {
    char* postfix_string = (char*) malloc(sizeof(char) * 1000);
    int eval_string_len = (int) strlen(infix_string);
    Stack* st = stack_new();
    int j = 0;
    for (int i = 0; i < eval_string_len; i++) {
        if (isdigit(infix_string[i])) {
            // Put the digit on the output string
            postfix_string[j++] =  infix_string[i];
        } else {
            if (infix_string[i] == '(') {
                stack_push(st, '(');
            } else if (infix_string[i] == ')') {
                while (stack_size(st) > 0 && stack_top(st) != '(') {
                    postfix_string[j++] = (char)stack_top(st);
                    stack_pop(st);
                }
                stack_pop(st);
            } else if (infix_string[i] == '+' || infix_string[i] == '-') {
                while (stack_size(st) > 0 && (stack_top(st) == '*' || stack_top(st) == '/' || stack_top(st) == '%')) {
                    postfix_string[j++] = (char)stack_top(st);
                    stack_pop(st);
                }
                stack_push(st, infix_string[i]);
            } else if (infix_string[i] == '*' || infix_string[i] == '/' || infix_string[i] == '%') {
                stack_push(st, infix_string[i]);
            } else {
                assert(0);
            }
        }
    }
    while (stack_size(st) > 0 && stack_top(st) != '(') {
        postfix_string[j++] = (char)stack_top(st);
        stack_pop(st);
    }
    postfix_string[j] = '\0';
    return postfix_string;
}

int main() {
    // Take the input
    printf("Please enter the expression to evaluate: ");
    char* input_string = (char*) malloc(sizeof(char) * 1000);
    scanf("%s", input_string);
    char* eval_string = convert_infix_to_postfix(input_string);
    printf("The evaluation is being run on: %s\n",  eval_string);
    // Make a stack and parse the input string
    int final_result = evaluate(eval_string);
    printf("Evaluation result: %d", final_result);
}
