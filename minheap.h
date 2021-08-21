#include <iostream>
#include <vector>

class MinHeap
{
private:
    std::vector<int> A;
 
    int PARENT(int i);
    int LEFT(int i);
    int RIGHT(int i);
    void reheap_down(int i);
    void reheap_up(int i);
 
public:
    int size() {return A.size();}
 
    bool empty();
    void InsertKey(int key);
    void DeleteKey();
    int top();
    void display();
};