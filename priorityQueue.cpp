#include<iostream>
#include "minheap.h"
#include<conio.h>

using namespace std;

class PriorityQueue
{
    minHeap h;

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

// void menu()
// {
//     PriorityQueue q;

//     int choice, key;
//     system("CLS");
//     cout<<"*********************************************************************************"<<endl;
//     cout<<"\n\n\t\t\t    <<<<<:: MENU ::>>>>>\n";
//     cout<<"\n\t\t\t    1. Insert in Queue";
//     cout<<"\n\t\t\t    2. Delete Min from Queue";
//     cout<<"\n\t\t\t    3. Top element in Queue";
//     cout<<"\n\t\t\t    4. Display Elements in Queue";
//     cout<<"\n\t\t\t    5. Exit";
//     cout<<"\n\t\t\t    Enter your choice: ";
//     cin>>choice;
//     switch(choice)
//     {
//            case 1:
//             cout<<"Enter a key to insert"<<endl;
//             cin>>key;
//             q.enqueue(key);
//             break;

//            case 2: 
//             q.dequeue();
//             break;

//            case 3: 
//            cout<<q.top();
//             break;

//             case 4: 
//            q.display();
//             break;

//            case 5: break;

//            default: cout<<"\nNo such option...\n\n";
//                     system("PAUSE");
//                     menu();
// 					break;
//     }
//     if(choice!=5)
//        menu();
// }


int main()
{
    PriorityQueue q;

    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(10);
    q.enqueue(16);
    q.enqueue(2);

    cout<<"The size is "<< q.size() <<endl;
    cout<<"The elements in priority Queue are "<<endl;
    q.display();

    cout<<endl;
    cout<<"The top element is "<<q.top()<<endl;
    q.dequeue();

    cout<<"The top element is "<<q.top()<<endl;
    q.dequeue();

    cout<<"The top element is "<<q.top()<<endl;
    q.dequeue();


}