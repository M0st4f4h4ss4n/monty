#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef struct Stack {
    int values[MAX_STACK_SIZE];
    int top;
} Stack;

void push(Stack *stack, int value) {
    if (stack->top == MAX_STACK_SIZE - 1) {
        fprintf(stderr, "Error: stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->values[++stack->top] = value;
}

void pall(Stack *stack) {
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->values[i]);
    }
}

int main(int argc, char **argv) {
    // Initialize stack
    Stack stack = { .top = -1 };

    // Parse and execute opcodes
    char *line = NULL;
    size_t line_size = 0;
    while (getline(&line, &line_size, stdin) != -1) {
        char *opcode = strtok(line, " \n");
        if (strcmp(opcode, "push") == 0) {
            char *arg = strtok(NULL, " \n");
            if (arg == NULL) {
                fprintf(stderr, "Error: missing argument for push opcode\n");
                exit(EXIT_FAILURE);
            }
            int value = atoi(arg);
            push(&stack, value);
        } else if (strcmp(opcode, "pall") == 0) {
            pall(&stack);
        }
    }

    // Clean up
    free(line);
        return 0;
}
