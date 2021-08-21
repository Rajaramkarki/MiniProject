#include<iostream>
#include "MinHeap.h"
#include<conio.h>
 #include <iostream>
#include <vector>
#include <algorithm>


class PriorityQueue
{
    MinHeap h;

    public:
        void enqueue(int key);
        void dequeue();
        int top();
        void display();
        int size();
};

int PriorityQueue:: size()
{
    return h.size();
}

void PriorityQueue:: enqueue(int key)
{
    h.InsertKey(key);
}

void PriorityQueue:: dequeue()
{
    h.DeleteKey();
}

int PriorityQueue:: top()
{
    return h.top();
}

void PriorityQueue:: display()
{
    h.display();
}

int main()
{
    PriorityQueue q;

    std::cout<<"Inserting 5,4,10,16,2,11,1 to the priority Queue\n";

    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(10);
    q.enqueue(16);
    q.enqueue(2);
    q.enqueue(11);
    q.enqueue(1);

    std::cout<<"The size is "<< q.size() <<"\n";
    std::cout<<"The elements in priority Queue are "<<"\n";
    q.display();

    std::cout<<"\n";
    std::cout<<"The top element is "<<q.top()<<"\n";
    std::cout<<"Deleting ROOT"<<"\n";
    q.dequeue();

    std::cout<<"\n";
    std::cout<<"The top element is "<<q.top()<<"\n";
    std::cout<<"Deleting ROOT"<<"\n";
    q.dequeue();

    std::cout<<"\n";
    std::cout<<"The top element is "<<q.top()<<"\n";
    std::cout<<"Deleting ROOT"<<"\n";
    q.dequeue();

    std::cout<<"\n";
    std::cout<<"The top element is "<<q.top()<<"\n";

}