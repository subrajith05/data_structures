//implementation of kinetic heap

#include <stdio.h>
#include <stdlib.h>
#define size 17

class KHeap
{
    struct node
    {
      int data;
      int timestamp;
      struct node *left;
      struct node *right
    };
  
    public:
        KHeap()
        {
            
        };
        int ins(int,int);
        int  del(void);
        void heapify(void);

        int search(int);
        void display(void);
        int isEmpty(void);
        ~KHeap()
        {
        
        };
};

int ins(int num, int time)
{
       
}
