
// The program is designed to handle one linked list
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int size = 0;

struct node
{
	int data;
	struct node * next;	
}*ll_first;

void deleteNode_at(int pos);
void insertNode_after(int pos);
void singlyLL(void);
void displayList(void);
char getChoice(void);
struct node* createNode(void);
struct node * trvl2Parent_of(int pos);

int main(void)
{
	printf("Welcome, this program demonstrates the singly linked list\n");
	singlyLL();
	return 0;
}

char getChoice(void)
{
	printf("----------------------------------------------\n");
	printf("\n   Please choose from the following ::");
	printf("\n\t a. Create a new list");
	printf("\n\t b. Delete a node at a position");
	printf("\n\t c. Insert a node at a position");
	printf("\n\t e. Exit the program");
	printf("\n\nYour preference :: ");
	char op;
	scanf("%c", &op);
	printf("----------------------------------------------\n");
	return op;
}
void displayList(void)
{
	struct node *trvl = ll_first;
	int i = 1;

	printf("----------------------------------------------\n");
	printf("The list is\n");
	while(trvl != NULL )
	{
		printf("\n\t %d. %d",i++,trvl->data);
		trvl = trvl->next;
	}
	printf("\n");
}
struct node* createNode(void)
{
	struct node * tmp = (struct node *)malloc(sizeof(struct node));
	printf("Enter the data for the node \n");
	scanf("%d", &(tmp->data));
	tmp->next = NULL;
	++size;
	return tmp;
}
void deleteNode_at(int pos)
{
	struct node * temp;
	if(pos == 1)
	{
		temp = ll_first;
		ll_first = ll_first->next;
		free(temp);
	}
	else
	{
		struct node * trvl = trvl2Parent_of(pos);
		temp = (trvl->next)->next;
		free(trvl->next);
		trvl->next = temp;
	}
	--size;
}
struct node* trvl2Parent_of(int pos)
{
	int i;
	struct node *trvl = ll_first;
	for(i = 1 ; i < pos - 1; ++i)
		trvl = trvl->next;
	return trvl;
}
void insertNode_after(int pos)
{
	struct node * tmp = createNode();
	if(pos == 0)
	{
		tmp->next = ll_first;
		ll_first = tmp;
	}
	else
	{
		struct node * trvl = trvl2Parent_of(pos+1);
		struct node * temp = trvl->next;
		trvl->next = tmp;
		tmp->next = temp;
	}
	++size;
	return;
}
void singlyLL(void)
{
	char choice = 'z';
	int pos;
	while(choice != 'e')
	{
		switch (choice)
		{
			case 'a':
			{
				ll_first = createNode();
				break;
			}
			case 'b':
			{
				if(ll_first != NULL)
				{
					printf("Enter the position of the node to be deleted\n");
					printf("Position : ");
					scanf("%d",&pos);
					deleteNode_at(pos);
				}
				else
				{
					printf("The list is empty, first create one.\n");
					sleep(3);
				}
				break;
			}
			case 'c':
			{
				printf("Enter the position after which the node is to be inserted\n");
				printf("\tPosition : ");
				scanf("%d",&pos);
				
				insertNode_after(pos);
				break;
			}
			default:
			{
				printf("Please select a valid option\n");
				break;
			}
		}
		system("clear");
		displayList();
		choice = getChoice();
	}
	printf("Exiting...\n");
	return;
}