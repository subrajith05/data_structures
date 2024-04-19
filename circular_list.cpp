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
        int insert(int);
        void display();
};

//Main function with the menu
int main()
{
    int choice,num,pos,val;
    List l1;
    while(1)
    { 
        printf("\nEnter \n1. Insertion at the end\n2. Display\n Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("\nEnter the number to insert: ");
                scanf("%d", &num);
    
                if (l1.insert(num))
                {
                    printf("%d sucessfully inserted. ",num);
                }
                else
                { 
                    printf("\nFailed to insert.");
                }
                break;
    

            case 2:
                l1.display();
                break;
            
            default:
                printf("Enter a valid choice!!!");
                break;
        }  
    }
 return 0;
}

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
