#include <stdio.h>
#include <stdlib.h>

// Structure definition for a node in the linked list
struct node
{
    int data;           // Data stored in the node
    struct node *next;  // Pointer to the next node in the list
};

struct node *head = NULL; // Pointer to the first node in the list, initially set to NULL

// Function to insert a new node at the beginning of the list
void insertatbeginning()
{
    // Allocate memory for a new node
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    // Check if memory allocation was successful
    if(newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    // Prompt user to enter data for the new node
    printf("Enter the data you want to insert: ");
    scanf("%d", &newnode->data);
    // Link the new node to the current head of the list
    newnode->next = head;
    // Update the head pointer to point to the new node
    head = newnode;
}

// Function to insert a new node at the end of the list
void insertatend()
{
    struct node *temp, *newnode;
    // Allocate memory for a new node
    newnode = (struct node*) malloc(sizeof(struct node));
    // Check if memory allocation was successful
    if(newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    // Prompt user to enter data for the new node
    printf("Enter the data you want to insert: ");
    scanf("%d", &newnode->data);
    // Set the next pointer of the new node to NULL, indicating it's the last node
    newnode->next = NULL;
    // If the list is empty, set the new node as the head and return
    if (head == NULL) {
        head = newnode;
        return;
    }
    // Traverse the list to find the last node
    temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    // Link the new node to the last node
    temp->next = newnode;
}

// Function to insert a new node at a specific position in the list
void insertatspecificposition()
{
    int pos, i = 1, count = 0;
    struct node *temp, *newnode;
    // Allocate memory for a new node
    newnode = (struct node*) malloc(sizeof(struct node));
    // Check if memory allocation was successful
    if(newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    // Prompt user to enter the position to insert the new node
    printf("Enter the position: ");
    scanf("%d", &pos);
    // Traverse the list to count the number of nodes
    temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    // If the position is invalid, print an error message and return
    if(pos > count+1 || pos < 1)
    {
        printf("Invalid position\n");
        return;
    }
    // Prompt user to enter data for the new node
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    // If the new node is to be inserted at the beginning of the list
    if(pos == 1) {
        // Link the new node to the current head of the list
        newnode->next = head;
        // Update the head pointer to point to the new node
        head = newnode;
        return;
    }
    // Traverse the list to the node just before the position where the new node will be inserted
    temp = head;
    while(i < pos-1)
    {
        temp = temp->next;
        i++;
    }
    // Link the new node to the node at position 'pos'
    newnode->next = temp->next;
    temp->next = newnode;
}

// Function to display the elements of the linked list
void display() {
    struct node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to control the program flow
int main() {
    int choice;
    // Loop to repeatedly display the menu and execute user-selected actions
    while(1) {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at specific position\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        // Switch statement to execute actions based on user's choice
        switch(choice) {
            case 1:
                insertatbeginning();
                break;
            case 2:
                insertatend();
                break;
            case 3:
                insertatspecificposition();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0); // Exit the program
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    }
    return 0;
}
