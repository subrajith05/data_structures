//implementation of kinetic heap

#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <chrono>
#define size 17

class KHeap{
    private:
        int arr[size][2];
        int cur;
    public:
        KHeap(){
            cur = -1;
        }
        int insert(int);
        int search(int);
        void display();
        int del();
        void sort();
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
