// The program is designed to handle one linked list

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void doublyDeleteNode_at(int pos);
void doublyinsertNode_after(int pos);
void singlyLL(void);
void displayList(void);
char getChoice(void);
struct node* createNode(void);
struct node * trvl2Parent_of(int pos);

struct node
{
	int data;
	struct node * next;	
	struct node * prev;
};

struct node *ll_first = NULL;
struct node *ll_last = NULL;
int size;

int main(void)
{
	printf("Welcome, this program demonstrates the doubly linked list\n");
	singlyLL();
	return 0;
}

// returns a pointer to parent node of node at position pos.
struct node* trvl2Parent_of(int pos)
{
	int i;

	struct node *trvl;
	trvl = ll_first;
	if(pos != 1)
	{
		for(i = 1 ; i < pos - 1; ++i)
			trvl = trvl->next;
		return trvl;
	}
	return NULL;
}


struct node * createNode(void)
{
	struct node * new_node = (struct node *)malloc(sizeof(struct node));

	printf("Enter the data for the node \n");
	scanf("%d", &(new_node->data));

	new_node->next = NULL;
	new_node->prev = NULL;

	return new_node;
}

void doublyDeleteNode_at(int pos)
{
	struct node * save;		// saves the pointer to the node to be deleted

	// if the first element of the list is to be deleted
	if( pos == 1 )
	{
		if( size == 1 )
		{
			ll_first = NULL;
			ll_last = NULL;
		}
		else
		{
			save = ll_first;
			ll_first = ll_first->next;
			ll_first->prev = NULL;
			free(save);
		}
	}
	else
	{
		// if last element of the list is to be deleted
		if( pos == size )
		{
			save = ll_last;
			ll_last = ll_last->prev;
			ll_last->next = NULL;
			free(save);
		}
		// if a middle element is to be deleted
		else
		{
			// parent->next is to be removed
			struct node * parent = trvl2Parent_of(pos);
			save = parent->next;

			parent->next->next->prev = parent;
			parent->next = parent->next->next;
			free(save);
		}
	}
	--size;
	return;
}


// Inserts a new node at position pos, 0 for inserting at the beginning of the list
void doublyinsertNode_after(int pos)
{
	struct node * new_node = createNode();
	if (pos == 0)
	{
		new_node->next = ll_first;
		ll_first->prev = new_node;
		ll_first = new_node;
	}
	else
	{
		if(pos == size )
		{
			new_node->prev = ll_last;
			ll_last->next = new_node;
			ll_last = new_node;
		}
		else
		{
			struct node * me = trvl2Parent_of(pos+1);
			struct node * temp = me->next;
			me->next = new_node;
			new_node->next = temp;
			temp->prev = new_node;
			new_node->prev = me;
		}
	}
	++size;
	return;
}
void singlyLL(void)
{
	int pos;
	char choice = 'z';
	while(choice != 'e')
	{
		switch (choice)
		{
			case 'a':
			{
				ll_first = createNode();
				ll_last = ll_first;
				size = 1;
				break;
			}
			case 'b':
			{
				if(ll_first == NULL || ll_last == NULL)
				{
					printf("The list is empty, first create one.\n");
					sleep(2);
				}
				else
				{
					printf("Enter the position of the node to be deleted\n");
					printf("Position : ");
					scanf("%d",&pos);
					doublyDeleteNode_at(pos);
				}
				break;
			}
			case 'c':
			{
				printf("Enter the position after which the node is to be inserted\n");
				printf("\tPosition : ");
				scanf("%d",&pos);
				
				doublyinsertNode_after(pos);
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

// Takes the input from the user about the choice
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

// Displays the linked list 
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
