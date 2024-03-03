/*
Notes:
1. This program implements a stack data structure using an array in C.
2. The stack has a fixed size defined by the STACK_SIZE macro.
3. Stack operations include push, pop, and display.
4. The push function adds an element to the top of the stack.
5. The pop function removes and returns the element at the top of the stack.
6. The display function prints all elements of the stack.
7. The main function provides a menu for interacting with the stack.
8. Input validation is not comprehensive; invalid input may cause unexpected behavior.
9. Stack overflow and underflow conditions are handled with error messages.
10. This implementation uses global variables for simplicity; a more modular design could be considered.
*/

#include <stdio.h>
#define STACK_SIZE 5

int stack[STACK_SIZE];
int top = -1;

void push(int value) {
    if (top == STACK_SIZE - 1) {
        printf("\nStack overflow, cannot push item\n");
    } else {
        stack[++top] = value;
        printf("\n%d pushed to stack successfully\n", value);
    }
}

int pop() {
    if (top == -1) {
        printf("\nStack underflow, cannot pop item\n");
        return -1; // Return a sentinel value indicating an error
    } else {
        int popped = stack[top--];
        printf("\nThe item popped successfully: %d\n", popped);
        return popped; // Return the popped value
    }
}

void display() {
    if (top == -1) {
        printf("\nStack is empty\n");
    } else {
        printf("\nElements in the stack: ");
        for (int i = top; i >= 0; --i) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n\nEnter choice\nPUSH: 1\nPOP: 2\nDISPLAY: 3\nEXIT: 4\n\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter item to be pushed: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nStack implementation stopped\n\n");
                return 0;

            default:
                printf("\nEnter a choice from the menu only\n");
        }
    }

    return 0;
}
