 //Introduction to Stacks
 //A stack is a data structure that follows the Last In, First Out (LIFO) principle,
 // where the last element added is the first one to be removed.


//Operations on Stacks:
// 1 Push: Adds an element to the top of the stack.
// 2 Pop: Removes the top element from the stack.
// 3 Peek/Top: Returns the top element without removing it.
// 4 IsEmpty: Checks if the stack is empty.
// 5 IsFull: Checks if the stack is full.
// 6 Size: Returns the number of elements in the stack.


#include <stdio.h>
#define MAX_SIZE 10

// Structure to represent a stack
struct Stack {
    int arr[MAX_SIZE];
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
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow: Cannot push %d, the stack is full.\n", value);
        return;
    }
    stack->arr[++stack->top] = value;
    printf("%d pushed to the stack.\n", value);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow: Cannot pop from an empty stack.\n");
        return -1; // Return a sentinel value indicating an error
    }
    return stack->arr[stack->top--];
}

// Function to display the elements in the stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Elements in the stack: ");
    for (int i = 0; i <= stack->top; ++i) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

// Main function for testing the stack
int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack);

    printf("Popped element: %d\n", pop(&stack));

    display(&stack);

    return 0;
}
