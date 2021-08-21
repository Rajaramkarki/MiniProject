#include <iostream>
#include <vector>
#include <stdexcept>
#include "minheap.h"
using namespace std;
 

int minHeap::PARENT(int i) 
{
    return (i - 1) / 2;
}
 
int minHeap::LEFT(int i) 
{
    return (2*i + 1);
}
 
int minHeap::RIGHT(int i) 
{
    return (2*i + 2);
}

bool minHeap:: empty()
{   
        if(size() == 0)
            return true;

        else
            return false;
}

void minHeap::reheap_down(int i)
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
        swap(A[i], A[smallest]);
        reheap_down(smallest);
    }
}

void minHeap::reheap_up(int i)
{
     
    if (i && A[PARENT(i)] > A[i])
    {
        swap(A[i], A[PARENT(i)]);
        reheap_up(PARENT(i));
    }
}

void minHeap::InsertKey(int key)
{
    A.push_back(key);
 
    int index = size() - 1;
    reheap_up(index);
}

void minHeap::DeleteKey()
{
    try 
    {
        if (size() == 0)
        {
            throw out_of_range("Heap underflow");
        }
 
        A[0] = A.back();
        A.pop_back();
 
        reheap_down(0);
    }
    catch (const out_of_range &oor) {
        cout << endl << oor.what();
    }
}
 
int minHeap::top()
{
    try {
        if (size() == 0)
        {
            throw out_of_range("Heap underflow");
        }
 
            return A.at(0);       
        }
        catch (const out_of_range &oor) {
            cout << endl << oor.what();
        }
        return 0;
}

void minHeap::display()
{
    for(int i=0; i< size(); i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

// int main()
// {
//     ------------------TESTING MINHEAP----------------


//     minHeap pq;
 
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
 
//     cout << endl << boolalpha << pq.empty();
 
//     pq.top();    
//     pq.DeleteKey();   

//     pq.display();
 
//     return 0;

// }