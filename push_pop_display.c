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

int pop(int stack[], int *top) {
    if (*top == -1) {
        printf("\nStack underflow, cannot pop item\n");
        return -1; // Return a sentinel value indicating an error
    } else {
        int popped = stack[*top];
        (*top)--;
        printf("\nThe item popped successfully: %d\n", popped);
        return popped; // Return the popped value
    }
}

void display(int stack[], int *top) {
    if (*top == -1) {
        printf("\nStack is empty\n");
    } else {
        printf("\nElements in the stack: ");
        for (int i = *top; i >= 0; --i) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int stack[stack_size];
    int top = -1;
    int choice, value;

    while (1) {
        printf("\n\nEnter choice\nPUSH: 1\nPOP: 2\nDISPLAY: 3\nEXIT: 4\n\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter item to be pushed: ");
                scanf("%d", &value);
                push(stack, &top, value);
                break;

            case 2:
                pop(stack, &top);
                break;

            case 3:
                display(stack, &top);
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
