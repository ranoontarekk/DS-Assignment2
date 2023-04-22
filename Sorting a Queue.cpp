#include <iostream>
#include <algorithm>
#include "Queue.cpp"
using namespace std;
#define MAX 100
template <class T>

void Sort(Queue<T> &q){
    for(int i = 0 ; i < q.QueueSize() ; i++){
        for(int j = i+1 ; j < q.QueueSize() ; j++){
            if(q.queue[i] > q.queue[j]){
               swap (q.queue[i],q.queue[j]);
            }
        }
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