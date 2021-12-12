#include <stdio.h>
#include <stdlib.h>

// Defining the structure of a linked list as : node
struct linkedList
{
	int num;
	struct linkedList *next;
};
typedef struct linkedList node;

node *create(void);
void print(node *list);
void crop(node *list, int lastNode);

int main()
{
	node *listHead;
	int lastNode;
	listHead = create(); // Create a linked list
	print(listHead);	 // Print the elements of the linked list
	printf("\nEnter node index which is to be made the last node : ");
	scanf("%d", &lastNode);
	crop(listHead, lastNode);
	print(listHead);
	return (0);
}

// Function to create a linked list from user given elements and return the head
node *create(void)
{
	node *head, *list;
	int num;

	head = (node *)malloc(sizeof(node)); // Creating the first node
	list = head;						 // To keep head unmodified for returning

	printf("Enter num : ");
	scanf("%d", &list->num); // Saving value of the first node
	while (1)
	{
		printf("Enter num (-999 to stop) : ");
		scanf("%d", &num);
		if (num == -999) // If user inputs -999, the next value of current node is set to NULL and loop exited
		{
			list->next = NULL;
			break;
		}
		else // For any other value, a new node is created at the next of current node, list ptr shifted to next node, and value of the new node is set
		{
			list->next = (node *)malloc(sizeof(node));
			list = list->next;
			list->num = num;
		}
	}
	return (head);
}

//Function to take the head of a linked list and print all its elements
void print(node *list)
{
	printf("Elements : ");
	while (1)
	{
		printf("%d ", list->num);
		if (list->next == NULL) // If next value of current node is NULL, loop is exited
		{
			break;
		}
		else // Otherwise ptr moves to the next node
		{
			list = list->next;
		}
	}
}

void crop(node *list, int lastNode)
{
	int index = 0;
	while (1)
	{
		if (index == lastNode)
		{
			list->next = NULL;
			break;
		}
		else if (list->next == NULL) // If next value of current node is NULL, loop is exited
		{
			break;
		}
		else // Otherwise ptr moves to the next node
		{
			list = list->next;
			index += 1;
		}
	}
}