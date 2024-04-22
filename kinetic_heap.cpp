//implementation of kinetic heap

#include <stdio.h>
#include <stdlib.h>
#define size 

class KHeap
{
  int kheap[size];
  public:
    KHeap()
    {
        
    };
    int ins(int,int);
    int  del();
    int search(int);
    void display(void);
    int isEmpty(void);
    ~KHeap()
    {
      
    };
}
