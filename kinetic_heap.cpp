//implementation of kinetic heap

#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <chrono>
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

int timestamp()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return now;
}

int ins(int num, int time)
{
       
}
