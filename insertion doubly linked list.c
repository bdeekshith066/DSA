#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;

void insertatbeginning()
{
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data: ");
	scanf("%d", &newnode->data);
	newnode->prev = NULL;
	newnode->next = head;
	if (head != NULL)
		head->prev = newnode;
	head = newnode;
	if (tail == NULL)
		tail = newnode;
}

void insertatend()
{
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data: ");
	scanf("%d", &newnode->data);
	newnode->next = NULL;
	newnode->prev = tail;
	if (tail != NULL)
		tail->next = newnode;
	tail = newnode;
	if (head == NULL)
		head = newnode;
}

void insert_at_pos(int pos)
{
    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }

    int count = 0;
    struct node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    if (pos > count + 1)
    {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1)
    {
        insertatbeginning();
        return;
    }

    if (pos == count + 1)
    {
        insertatend();
        return;
    }

    struct node *newnode, *prev_node;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);

    temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    prev_node = temp;
    newnode->next = temp->next;
    newnode->prev = prev_node;
    prev_node->next = newnode;
    newnode->next->prev = newnode;
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    printf("List elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, pos;
    while (1)
    {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at any position\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertatbeginning();
                break;
            case 2:
                insertatend();
                break;
            case 3:
                printf("Enter the position: ");
                scanf("%d", &pos);
                insert_at_pos(pos);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}


