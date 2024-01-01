// Function to push an element onto the stack
// Checks if the stack is full before attempting to push.
// If the stack is full, displays a stack overflow message.
// If there is space in the stack:
//   - Increments the top pointer to make room for the new element.
//   - Adds the value to the stack at the updated top position.
// Displays a success message indicating the element has been pushed.


#include <stdio.h>
#define stack_size 5

void push(int stack[], int *top, int value) {
    if (*top == stack_size - 1) {
        printf("\nStack overflow, cannot push item\n");
    } else {
        (*top)++;
        stack[*top] = value;
        printf("\n%d pushed to stack successfully\n", value);
    }
}

int main() {
    int stack[stack_size];
    int top = -1;
    int value;

    while (1) {
        printf("\nEnter item to be pushed (Enter -1 to exit): ");
        scanf("%d", &value);

        if (value == -1) {
            printf("\nPush operation stopped\n\n");
            break;
        }

        push(stack, &top, value);
    }

    return 0;
}
