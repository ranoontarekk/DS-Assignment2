#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100
template <class T>
class Queue{
public:

    int Rear;
    int front;
    int count;
    T queue[MAX];
    Queue(){
        count = 0 ;
        Rear = -1 , front = -1;
    }
    void enqueue(T data){
        if(count == MAX){
            cout<<"Queue is full"<<endl;
            return;
        }
        Rear = (Rear+1);
        queue[Rear] = data;
        count++;
    }
    void dequeue(){
        if(count == 0){
            cout<<"Queue is empty"<<endl;
            return;
        }
        front = (front+1);
        count--;
    }
    T Frist(){
        if(count == 0){
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        return queue[front+1];
    }
    bool isEmpty(){
        return (count == 0);
    }
    int QueueSize(){
        return count;
    }
    void clear(){
        count = 0;
        Rear = -1 , front = -1;
    }
    void print(){
        for(int i = front+1 ; i <= Rear ; i++){
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }
};
void Sort(Queue<int> &q){
    int temp;
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



    return 0;
}