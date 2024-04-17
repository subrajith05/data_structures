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
};
