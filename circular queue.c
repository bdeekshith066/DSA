#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int queue_array[MAX];
int rear = -1;
int front = -1;

void insert()
{
    int add_item;
    if ((rear == MAX - 1 && front == 0) || (rear == front - 1))
    {
        printf("Queue Overflow \n");
    }
    else
    {
        printf("Insert the element in queue : ");
        scanf("%d", &add_item);

        if (rear == -1)
        {
            front = rear = 0;
        }
        
        else
        {
            rear = (rear + 1)%MAX;
        }

        queue_array[rear] = add_item;
    }
}

void delete()
{
    if (front == -1)
    {
        printf("Queue Underflow \n");
        return;
    }
    else
    {
        printf("Deleted Element is : %d\n", queue_array[front]);

        if (front == rear)
        {
            front = rear = -1;
        }
      
        else
        { 
            front = (front + 1)%MAX;
        }
    }
}

void display()
{
    int i;
    if (front == -1)
    {
        printf("Queue is empty \n");
    }
    else
    {
        printf("Queue is : \n");
        if (rear >= front)
        {
            for (i = front; i <= rear; i++)
            {
                printf("%d ", queue_array[i]);
            }
        }
        else
        {
            for (i = front; i < MAX; i++)
            {
                printf("%d ", queue_array[i]);
            }
            for (i = 0; i <= rear; i++)
            {
                printf("%d ", queue_array[i]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("1.Insert \n");
        printf("2.Delete\n");
        printf("3.Display \n");
        printf("4.Exit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("Invalid choice \n");
        } /*End of switch*/
    }     /*End of while*/
    return 0;
}
 
