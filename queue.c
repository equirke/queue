#include <stdio.h>
#include <stdlib.h>

struct QueueNode
{
	int data;
	struct QueueNode *next;
};

typedef struct QueueNode Node;

struct QueueHead
{
	Node *head;
	Node *tail;
};

typedef struct QueueHead Queue;

void printMenu(void);
int enqueue(Queue*, int);
int dequeue(Queue*);
void printQueue(Queue*);
void freeQueue(Queue*);


//This is a main comment
int main(void)
{
	Queue queue;
	queue.head = NULL;
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
			if((enqueue(&queue, value)) == -1)
			{
				printf("Failed to enqueue\n");
			}
			break;
			case 2:
			printf("Value dequeued:\t%d\n",dequeue(&queue));
			break;
			case 3:
			printQueue(&queue);
			break;
			
			default:
			printf("Unknown input\n");
			
		}
	
	printf("\n");
	}while(input != 0);
	
	freeQueue(&queue);
	
}

//This prints the menu
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
int enqueue(Queue* queue, int value)
{
	Node* newNode;
	if((newNode = malloc(sizeof(Node))) == NULL)
	{
		return -1;
	}
	newNode->data = value;
	newNode->next = NULL;
	
	if(queue->head == NULL)
	{
		queue->head = newNode;
		queue->tail = newNode;
	}
	else
	{
		queue->tail->next = newNode;
		queue->tail = newNode;
	}
	
	return 0;
	
}

/*Removes a node from the queue
	if the queue is not already
	empty*/
int dequeue(Queue* queue)
{
	int value;
	Node *top;
	
	if(queue->head != NULL)
	{
		top = queue->head;
		queue->head = queue->head->next;
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
void printQueue(Queue* queue)
{	
	printf("H");
	Node *print = queue->head;
	
	while(print != NULL)
	{
		printf("->%d", print->data);
		print = print->next;
	}
	
	printf("<-T\n");
}

/*Frees the queue at the end of the
	program if the queue is not already empty*/
void freeQueue(Queue* queue)
{
	Node *cur;
	while(queue->head != NULL)
	{
		cur = queue->head;
		queue->head = queue->head->next;
		free(cur);
	}
}
