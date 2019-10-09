#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int data;
  struct Node *next;
};

void beginning(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(1*sizeof( struct Node));
    new_node->data  = new_data;

    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
/*struct Node**/void insertAfter(struct Node** head, int new_data,int pos)
{
    struct Node* ptr,*qtr;

    int i;
    ptr = (struct Node*)malloc(1*sizeof( struct Node));
    ptr->data=new_data;
    ptr->next=NULL;
    if(pos==1)
    {

        ptr->next=*head;
        *head=ptr;
        return;// head;
    }
    qtr=*head;
    for(i=0;i<pos-1;i++)
    {
        printf("*");
        if(qtr!=NULL)
        {
            qtr=qtr->next;
        }
        else
        {
            printf("UNDERFLOW\n");
            return ;//head;
        }
    }
    ptr->next=qtr->next;
    qtr->next=ptr;
    //return head;

}
void append(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(1*sizeof( struct Node));

    struct Node *last = *head_ref;

    new_node->data  = new_data;

    new_node->next = NULL;

    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }
    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

void deleteNode(struct Node **head_ref, int position)
{
   if (*head_ref == NULL)
      return;
   struct Node* temp = *head_ref;
    if (position == 0)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    for (int i=0; temp!=NULL && i<position-1; i++)
         temp = temp->next;

    if (temp == NULL || temp->next == NULL)
         return;
    struct Node *next = temp->next->next;
    free(temp->next);

    temp->next = next;
}
void display(struct Node *head)
{
    if(head==NULL)
    {
        printf("LINKED LIST IS EMPTY\n");
        return ;
    }
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
}
void display_reverse(struct Node *head)
{
    if(head==NULL)
    {
        printf("LINKED LIST IS EMPTY\n");
        return ;
    }
    int arr[100],k=0,i=0;
    while(head!=NULL)
    {
        arr[k]=head->data;
        head=head->next;
        k++;
    }
    k--;
    while(k>=0)
    {
        printf("%d ",arr[k]);
        k--;
    }
}
void reverse(struct Node ** head)
    {

        struct Node* current = *head;
        struct Node *prev = NULL, *next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        *head = prev;
    }
int main()
{
    int i=0,choice=1,data,pos;
    struct Node* head = NULL;

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
                    beginning(&head, data);
                    break;
            case 2:printf("Enter the position : ");
                    scanf("%d",&pos);
                    printf("Enter the data : ");
                    scanf("%d",&data);
                    insertAfter(&head, data,pos);
                    break;
            case 3:printf("Enter the data : ");
                    scanf("%d",&data);
                    append(&head, data);
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
                    reverse(&head);
                    break;
        }
    }while(choice!=0);

}
