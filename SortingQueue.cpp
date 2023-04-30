#include <iostream>
#include <algorithm>
#include "Queue.cpp"
using namespace std;
template <class T>
void Sort(Queue<T>& q) {
    if (q.QueueSize() <= 1) {
        return;
    }

    Queue<T> left, right;
    int mid = q.QueueSize() / 2;

    for (int i = 0; i < mid; i++) {
        left.enqueue(q.First());
        q.dequeue();
    }

    while (!q.isEmpty()) {
        right.enqueue(q.First());
        q.dequeue();
    }

    Sort(left);
    Sort(right);

    while (!left.isEmpty() && !right.isEmpty()) {
        if (left.First() < right.First()) {
            q.enqueue(left.First());
            left.dequeue();
        } else {
            q.enqueue(right.First());
            right.dequeue();
        }
    }

    while (!left.isEmpty()) {
        q.enqueue(left.First());
        left.dequeue();
    }

    while (!right.isEmpty()) {
        q.enqueue(right.First());
        right.dequeue();
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
    Queue<string> qq;
    qq.enqueue("A");
    qq.enqueue("C");
    qq.enqueue("B");
    qq.enqueue("D");
    qq.enqueue("E");
    Sort(qq);
    qq.print();
   
    return 0;
}