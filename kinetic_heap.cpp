//implementation of kinetic heap

#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <chrono>
#define len 17

class KHeap
{
    private:
        int arr[len][2];
        int cur;
    public:
        KHeap()
        {
            cur = -1;
        }
        int insert(int);
        int search(int);
        void display();
        int update(int);
        int del();
};

int main()
{
    int choice;
    KHeap h;
    int number;
    while(1)
    {
        printf("\nMenu:\n\t1. Insert\n\t2. Delete\n\t3. Display\n\t4. Search\n\t5. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            {
                printf("Enter number to insert : ");
                scanf("%d",&number);
                int ind=h.search(number);
                if(ind!=-1){
                    if(h.update(ind)){
                        printf("\nUpdation successful");
                    }
                    else{
                        printf("\nUpdation unsuccessful");
                    }
                    break;
                }
                else{
                    if(h.insert(number))
                    {
                        printf("Successfully inserted %d\n",number);
                    }
                    else{
                        printf("Insertion failed.\n");
                    }
                    break;
                }
            }
            case 2:
            {
                int res=h.del();
                if(res!=-1)
                {
                    printf("Successfully deleted %d\n",res);
                }
                else
                {
                    printf("Deletion failed.\n");
                }
                break;
            }
            case 3:
            {
                h.display();
                break;
            }
            case 4:
            {
                printf("Enter number to search : ");
                scanf("%d",&number);
                if(h.search(number)!=-1)
                {
                    printf("%d - Found",number);
                }
                else
                {
                    printf("%d - Not found", number);
                }
                break;
            }
            case 5:
            {
                printf("Program exitted\n");
                exit(0);
            }
            default:
                printf("Enter a valid choice\n");
        }
    }
    return 0;
}

int timestamp()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return now;
}

void convert_epoch_to_time(time_t epoch_time) 
{
    struct tm *local_time;
    char buffer[80];
    local_time = localtime(&epoch_time);
    strftime(buffer, 80, "%c", local_time);
    printf("%s\n",buffer);
}

//Method to insert element
int KHeap::insert(int num)
{
    if(cur==len-1)
    {
        printf("\nHeap is full.");
        return 0;
    }  
    else
    {
        int parent;
        cur+=1;
        int i=cur;
        arr[cur][0]=num;
        arr[cur][1]=timestamp();
        while(1)
        {
            if(i==0)
            {
                return 1;
            }
            if (i%2==0)
            {
                parent=(i-2)/2;
            }
            else
            {
                parent=(i-1)/2;
            }
            if (arr[parent][1]<arr[i][1])
            {
                int temp[2];
                temp[0]=arr[parent][0];
                temp[1]=arr[parent][1];
                arr[parent][0]=arr[i][0];
                arr[parent][1]=arr[i][1];
                arr[i][0]=temp[0];
                arr[i][1]=temp[1];
            }
            else
            {
                return 1;
            }
            i=parent;
        }
    } 
}

//Method to display the elements of the queue
//Time complexity - O(n)
void KHeap::display(void)
{
    int i;
    if (cur==-1)
    {
        printf("\nKinetic Heap is empty");
    }
    else
    {
        printf("\nHeap :\n");
        for(i=0;i<cur+1;i++)
        {
            printf("%d - ",arr[i][0]);
            convert_epoch_to_time(arr[i][1]);
        }
    }
}

int KHeap::search(int num){
    for(int i=0;i<=cur;i++){
        if(arr[i][0]==num){
            return i;
        }
    }
    return -1;
}

int KHeap::update(int ind)
{
    arr[ind][1]=timestamp();
    
    int parent;
    int i=cur;
    while(1)
    {
        if(i==0)
        {
            return 1;
        }
        if (i%2==0)
        {
            parent=(i-2)/2;
        }
        else
        {
            parent=(i-1)/2;
        }
        if (arr[parent][1]<arr[i][1])
        {
            int temp[2];
            temp[0]=arr[parent][0];
            temp[1]=arr[parent][1];
            arr[parent][0]=arr[i][0];
            arr[parent][1]=arr[i][1];
            arr[i][0]=temp[0];
            arr[i][1]=temp[1];
        }
        else
        {
            return 1;
        }
        i=parent;
    }
}

int KHeap::del()
{
    int temp1;
    int temp2;

    if (cur==-1)
    {
        return -1;
    }

    int val=arr[0][0];
    arr[0][0]=arr[cur][0];
    arr[0][1]=arr[cur][1];

    cur--;
    int i = 0;

    while(2*i+1<=cur)
    {
        int left = 2*i+1;
        int right = 2*i+2;
        int max = left;
        if(right <= cur && arr[right][1] > arr[left][1])
        {
            max = right;
        }
        if(arr[max][1] > arr[i][1])
        {
            temp1=arr[i][0];
            temp2=arr[i][1];
            arr[i][0]=arr[max][0];
            arr[i][1]=arr[max][1];
            arr[max][0]=temp1;
            arr[max][1]=temp2;

            i = max;
        }
        else
        {
            break;
        }
    }
    return val;
}
