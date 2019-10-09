#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/* Node of a doubly linked list */
struct Node {
	int data;
	char name[25];
	struct Node* next; // Pointer to next node in DLL
	struct Node* prev; // Pointer to previous node in DLL
};

void beginning(struct Node** head_ref, int new_data,char name[])
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;
    strcpy(new_node->name,name);
	new_node->next = (*head_ref);
	new_node->prev = NULL;

	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	(*head_ref) = new_node;
}
/* Given a reference (pointer to pointer) to the head
of a DLL and an int, appends a new node at the end */
void append(struct Node** head_ref, int new_data,char name[])
{
	/* 1. allocate node */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	struct Node* last = *head_ref; /* used in step 5*/

	/* 2. put in the data */
	new_node->data = new_data;
    strcpy(new_node->name,name);
	/* 3. This new node is going to be the last node, so
		make next of it as NULL*/
	new_node->next = NULL;

	/* 4. If the Linked List is empty, then make the new
		node as head */
	if (*head_ref == NULL) {
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	}

	/* 5. Else traverse till the last node */
	while (last->next != NULL)
		last = last->next;

	/* 6. Change the next of last node */
	last->next = new_node;

	/* 7. Make last node as previous of new node */
	new_node->prev = last;

	return;
}
void insertAfter(struct Node** head, int new_data,int pos, char name[])
{
	struct Node *ptr=*head,*new_node=(struct Node *)malloc(1*sizeof(struct Node));
	new_node->data=new_data;
	strcpy(new_node->name,name);
    int i=0;
	for(i=0;i<pos-1 && ptr!=NULL;i++)
    {
        ptr=ptr->next;
    }
    if(ptr==NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }
    new_node->next=ptr->next;
    new_node->prev=ptr;
    ptr->next=new_node;
	return;
}
void display(struct Node* head)
{
    if(head==NULL)
    {
        printf("LINKED LIST IS EMPTY \n");
        return;
    }
    while(head!=NULL)
    {
        printf("\n%d %s ",head->data,head->name);
        head=head->next;
    }

}
void display_reverse(struct Node* head)

{
    if(head==NULL)
    {
        printf("LINKED LIST IS EMPTY \n");
        return;
    }
    while(head->next!=NULL)
    {
       // printf("%d ",head->data);
        head=head->next;
    }
    while(head!=NULL)
    {
        // printf("%d ",head->data);
        printf("\n%d %s ",head->data,head->name);
        head=head->prev;
    }


}
void modify(struct Node ** head,int pos,int data,char name[])
{
    if(*head==NULL)
    {
        printf("LIST IS EMPTY\n");
        return;
    }
    struct Node *ptr=*head;
    int i=0;
    for(i=0;i<pos && ptr!=NULL;i++)
    {

        ptr=ptr->next;
    }
    if(ptr==NULL)
    {
        return;
    }
    ptr->data=data;
    strcpy(ptr->name,name);
}
void deleteNode(struct Node ** head,int pos)
{
    if(*head==NULL)
    {
        printf("LIST IS EMPTY\n");
        return;
    }
    int i=0;
    struct Node *ptr=*head;
    for(i=0;i<pos-1 && ptr!=NULL;i++)
    {
        ptr=ptr->next;
    }
    if(ptr==NULL || ptr->next==NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }
    struct Node * next=ptr->next->next;
    next->prev=ptr;
    free(ptr->next);
    ptr->next=next;
}
int main()
{
    int i=0,choice=1,data,pos;
    struct Node* head = NULL;
    char name[25];
    do
    {
        printf("\n==============MENU========================\n");
        printf("1.Insert in the beginning\n");
        printf("2.Insert at a given position\n");
        printf("3.Insert at the end\n");
        printf("4.Delete a node\n");
        printf("5.Display the list\n");
        printf("6.Display in reverse\n");
        printf("7.Reverse the list\n");
        scanf("%d",&choice);
        switch(choice)
        {

            case 1:printf("Enter the data : ");
                    scanf("%d",&data);
                    printf("Enter Name : ");
                    scanf("%s",&name);
                    beginning(&head, data,name);
                    break;
            case 2:printf("Enter the position : ");
                    scanf("%d",&pos);
                    printf("Enter the data : ");
                    scanf("%d",&data);
                    printf("Enter Name : ");
                    scanf("%s",&name);
                    insertAfter(&head, data,pos,name);
                    break;
            case 3:printf("Enter the data : ");
                    scanf("%d",&data);
                    printf("Enter Name : ");
                    scanf("%s",&name);
                    append(&head, data,name);
                    break;
            case 4:printf("Enter the pos : ");
                    scanf("%d",&pos);
                        deleteNode(&head,pos);
                    break;
            case 5:printf("Displaying the list :  ");
                    display(head);
                    break;
            case 6:printf("Displaying the list in reverse :  ");
                    display_reverse(head);
                    break;
            case 7:printf(" List is Reversed \n ");
                    //reverse(&head);
                    break;
            case 8:printf("Enter the position : ");
                    scanf("%d",&pos);
                    printf("Enter the data : ");
                    scanf("%d",&data);
                    printf("Enter Name : ");
                    scanf("%s",&name);
                    modify(&head, pos,data,name);
        }
    }while(choice!=0);

}

