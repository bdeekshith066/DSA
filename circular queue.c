#include <stdio.h>
#define size 3

int items[size];
int front = -1, rear = -1;

int isFull() {
    if ((front == 0 && rear == size - 1) || (front == rear + 1))
        return 1;
    return 0;
}

int isEmpty() {
    if (front == -1)
        return 1;
    return 0;
}

void enQueue(int element) {
    if (isFull())
        printf("\n Queue is full !! \n");
    else {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % size;
        items[rear] = element;
        printf("\n Inserted %d", element);
    }
}

int deQueue() {
    int element;
    if (isEmpty()) {
        printf("\n Queue is empty!! \n");
        return (-1);
    } else {
        element = items[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size;
        }
        printf("\n Deleted element %d \n", element);
        return (element);
    }
}

void Display() {
    int i;
    if (isEmpty())
        printf("\n Empty Queue\n");
    else {
        printf("\n Front %d", front);
        printf("\n Items ");
        for (i = front; i != rear; i = (i + 1) % size) {
            printf("%d ", items[i]);
        }
        printf("%d", items[i]);
        printf(" \n Rear %d \n", rear);
    }
}

int main() {
    int choice, value;

    do {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the value to enqueue: ");
                scanf("%d", &value);
                enQueue(value);
                break;

            case 2:
                deQueue();
                break;

            case 3:
                Display();
                break;

            case 4:
                printf("\nExiting the program.\n");
                break;

            default:
                printf("\nInvalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}
