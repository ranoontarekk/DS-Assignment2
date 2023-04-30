#include <iostream>
#include <algorithm>
#include "Queue.cpp"
using namespace std;
#define MAX 100
template <class T>

void sortQueue(Queue<T>& q) {
    Queue<T> temp;
    while (!q.isEmpty()) {
        T element = q.dequeue();
        while (!temp.isEmpty() && element > temp.front()) {
            q.enqueue(temp.dequeue());
        }
        temp.enqueue(element);
    }
    while (!temp.isEmpty()) {
        q.enqueue(temp.dequeue());
    }
}





int main()
{
    Queue<int> q;
    q.enqueue(5);
    q.enqueue(3);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(4);
    Sort(q);
    q.print();
cout << "--------------------------------------------------------" << endl;
    Queue<char> q1;
    q1.enqueue('a');
    q1.enqueue('c');
    q1.enqueue('b');
    q1.enqueue('e');
    q1.enqueue('d');
    Sort(q1);
    q1.print();



    return 0;
}