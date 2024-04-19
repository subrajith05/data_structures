/*Circular doubly linked list ADT with a travelling head*/

#include<stdio.h>
#include<stdlib.h>

class List
{
    struct node
    {
        int data;
        struct node* prev;
        struct node* next;
    };
    struct node* head;
    
    public:
        List()
        {
            head=NULL;
        };
        void display();
};

void List::display()
{
    if(head==NULL)
    {
        printf("\nThe list is empty\n");
    }
    else
    {
        struct node* temp=head;
        printf("\nDisplaying the list\n");
        while(temp->next!=head)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }
}
