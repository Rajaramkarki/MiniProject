#include <iostream>
#include <vector>
#include <stdexcept>
#include "minHeap.h"

 

int MinHeap::PARENT(int i) 
{
    return (i - 1) / 2;
}
 
int MinHeap::LEFT(int i) 
{
    return (2*i + 1);
}
 
int MinHeap::RIGHT(int i) 
{
    return (2*i + 2);
}

bool MinHeap:: empty()
{   
        if(size() == 0)
            return true;

        else
            return false;
}

void MinHeap::reheap_down(int i)
{
    int left = LEFT(i);
    int right = RIGHT(i);
 
    int smallest = i;
 
    if (left < size() && A[left] < A[i]) {
        smallest = left;
    }
 
    if (right < size() && A[right] < A[smallest]) {
        smallest = right;
    }
 
    if (smallest != i)
    {
        std::swap(A[i], A[smallest]);
        reheap_down(smallest);
    }
}

void MinHeap::reheap_up(int i)
{
     
    if (i && A[PARENT(i)] > A[i])
    {
        std::swap(A[i], A[PARENT(i)]);
        reheap_up(PARENT(i));
    }
}

void MinHeap::InsertKey(int key)
{
    A.push_back(key);
 
    int index = size() - 1;
    reheap_up(index);
}

void MinHeap::DeleteKey()
{
    try 
    {
        if (size() == 0)
        {
            throw std::out_of_range("Heap underflow");
        }
 
        A[0] = A.back();
        A.pop_back();
 
        reheap_down(0);
    }
    catch (const std::out_of_range &oor) {
        std::cout << "\n" << oor.what();
    }
}
 
int MinHeap::top()
{
    try {
        if (size() == 0)
        {
            throw std::out_of_range("Heap underflow");
        }
 
            return A.at(0);       
        }
        catch (const std::out_of_range &oor) {
            std::cout << "\n" << oor.what();
        }
        return 0;
}

void MinHeap::display()
{
    for(int i=0; i< size(); i++)
    {
        std::cout<<A[i]<<" ";
    }
    std::cout<<"\n";
}

// int main()
// {
//     ------------------TESTING MinHeap----------------


//     MinHeap pq;
 
//     pq.InsertKey(3);
//     pq.InsertKey(2);
//     pq.InsertKey(15);
 
//     cout << "Size is " << pq.size() << endl;
 
//     cout << pq.top() << " ";
//     pq.DeleteKey();
 
//     cout << pq.top() << " ";
//     pq.DeleteKey();
 
//     pq.InsertKey(5);
//     pq.InsertKey(4);
//     pq.InsertKey(45);
 
//     cout << endl << "Size is " << pq.size() << endl;
 
//     cout << pq.top() << " ";
//     pq.DeleteKey();
 
//     cout << pq.top() << " ";
//     pq.DeleteKey();
 
//     cout << pq.top() << " ";
//     pq.DeleteKey();
 
//     cout << pq.top() << " ";
//     pq.DeleteKey();
  
//     pq.top();    
//     pq.DeleteKey();   

//     pq.display();
 
//     return 0;

// }