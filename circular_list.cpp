//Circular doubly linked list ADT with a travelling head

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
    int cur;
    
    public:
    List()
    {
        head=NULL;
        cur=0;
    };
    
    int insert(int);
    void display();
    int size();
    void moveHeadForward();
    void moveHeadBack();
    void displayHead();
    int isEmpty();
};

int main()
{
    int choice,num,pos,val;
    List l1;
    
    while(1)
    { 
        printf("\nEnter \n1. Insertion at the end\n2. Display\n3.Size");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1://insertion at the end
            {
                printf("\nEnter the number to insert: ");
                scanf("%d", &num);
    
                if (l1.insert(num))
                {
                    printf("%d is sucessfully inserted. ",num);
                }
                else
                { 
                    printf("\nFailed to insert.");
                }
                break;
            }

            case 2://display
            {
                l1.display();
                break;
            }

            case 3: //displaysize
            {
                printf("\nThe size of the list: %d\n", l1.size());
                break;
            }
            
            default:
            printf("\n<--Enter a valid choice!-->\n");
            break;
        }  
    }
 return 0;
}

//Function Definitions

//Method to insert an element at the end of the circular doubly linked list
//Time complexity-O(1)
int List::insert(int num)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    struct node* temp=head;
    newnode->data=num;

    //if empty
    if(head==NULL)
    {
        head=newnode;
        newnode->next=newnode;
        newnode->prev=newnode;
        cur+=1;
        return 1;
    }

    //if non-empty
    else
    {
        temp=temp->prev;
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=head;
        temp=newnode->next;
        temp->prev=newnode;
        cur+=1;
        return 1;
    }

}

//Method to return the size of the doubly linked list
//Time complexity-O(1)
int List::size()
{
    return cur;
}

//Method to move the head forward
//Time complexity-O(1)
void List::moveHeadForward()
{
    if(head==NULL)
    {
        printf("\nList is empty.");
    }

    else
    {
        struct node* temp=head;
        head=temp->next;
        printf("\nHead is now moved forward.\n");
    }
}

//Method to move the head backwards
//Time complexity-O(1)
void List::moveHeadBack()
{
    if(head==NULL)
    {
        printf("\nList is empty.");
    }

    else
    {
        struct node* temp=head;
        head=temp->prev;
        printf("\nHead is now moved back.\n");
    }
}

//Method to display the value at head
//Time complexity-O(1)
void List::displayHead()
{
    if(head==NULL)
    {
        printf("\nThe list is empty.");
    }

    else
    {
        printf("\nHead: %d", head->data);
    }
}

//Method to display the elements of the doubly linked list
//Time complexity-O(n)
void List::display()
{
    if(head==NULL)
    {
        printf("\nThe list is empty\n");
    }

    else
    {
        struct node* temp=head;

        printf("\n<-The elements of the list->\n");

        while(temp->next!=head)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }

        printf("%d\n",temp->data);
    }
}

//Method to check if the list is empty
//Time complexity-O(1)
int List::isEmpty()
{
    if(head==NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
