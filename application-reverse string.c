#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

// Stack structure
struct Stack {
    char items[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, char value) {
    if (isFull(stack)) {
        printf("Stack Overflow: Cannot push %c, the stack is full.\n", value);
        return;
    }
    stack->items[++stack->top] = value;
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow: Cannot pop from an empty stack.\n");
        return '\0';
    }
    return stack->items[stack->top--];
}

// Function to reverse a string using a stack
void reverseString(char* str) {
    int length = strlen(str);

    // Create a stack
    struct Stack stack;
    initialize(&stack);

    // Push each character onto the stack
    for (int i = 0; i < length; i++) {
        push(&stack, str[i]);
    }

    // Pop each character from the stack to reverse the string
    for (int i = 0; i < length; i++) {
        str[i] = pop(&stack);
    }
}

int main() {
    char input[MAX_SIZE];

    // Get input from the user
    printf("Enter a string: ");
    fgets(input, MAX_SIZE, stdin);

    // Remove the newline character from the input
    input[strcspn(input, "\n")] = '\0';

    // Reverse the string
    reverseString(input);

    // Display the reversed string
    printf("Reversed string: %s\n", input);

    return 0;
}
