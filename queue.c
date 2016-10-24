#include <stdio.h>
#include <stdlib.h>

struct QueueNode
{
	int data;
	struct QueueNode *next;
};

typedef struct QueueNode Node;

void printMenu(void);
int enqueue(Node**, Node**, int);
int dequeue(Node**);
void printQueue(Node**);
void freeQueue(Node**);


int main(void)
{
	Node **tail;
	Node **head;
	Node *t;
	Node *h;
	t = NULL;
	h = NULL;
	tail = &t;
	head = &h;
	
	int input = 0;
	int value;
	do
	{
		printMenu();
		
		scanf("%d", &input);
		fflush(stdin);
		switch(input)
		{
			case 0:
			printf("Exiting\n");
			break;
			case 1:
			printf("Value to enqueue:\t");
			scanf("%d", &value);
			enqueue(head, tail, value);
			break;
			case 2:
			printf("Value dequeued:\t%d\n",dequeue(head));
			break;
			case 3:
			printQueue(head);
			break;
			
			default:
			printf("Unknown input\n");
			
		}
	
	printf("\n");
	}while(input != 0);
	
	freeQueue(head);
	
}

void printMenu(void)
{
	printf("1) Enqueue value\n");
	printf("2) Dequeue value\n");
	printf("3) Print Queue\n");
	printf("0) Exit\n");
}

/*Adds a node to the queue with a value, if
	there are no nodes on the queue, then the
	head and the tail are pointed at the node.*/
int enqueue(Node** head, Node **tail, int value)
{
	Node* newNode = malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = NULL;
	
	if(*head == NULL)
	{
		*head = newNode;
		*tail = newNode;
	}
	else
	{
		(*tail)->next = newNode;
		*tail = newNode;
	}
	
}

/*Removes a node from the queue
	if the queue is not already
	empty*/
int dequeue(Node** head)
{
	int value;
	Node *top;
	
	if(*head != NULL)
	{
		top = *head;
		*head = (*head)->next;
		value = top->data;
		free(top);
		return value;
	}
	else
	{
		return -1;
	}
}

/*Prints the entire queue showing
	the link between the nodes*/
void printQueue(Node** head)
{	
	printf("H");
	Node *print = *head;
	
	while(print != NULL)
	{
		printf("->%d", print->data);
		print = print->next;
	}
	
	printf("<-T\n");
}

/*Frees the queue at the end of the
	program if the queue is not already empty*/
void freeQueue(Node** head)
{
	Node *cur;
	while(*head != NULL)
	{
		cur = *head;
		*head = (*head)->next;
		free(cur);
	}
}