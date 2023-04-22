#include <iostream>
#define MAX 100
using namespace std;
template <class T>
#define MAX 100
class Queue{
    int Rear;
    int front;
    int count;
    T queue[MAX];
public:
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
    T First(){
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
        //clear the queue
        count = 0;
        Rear = -1 , front = -1 ;
    }
    void print(){
        for(int i = front+1 ; i <= Rear ; i++){
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }
    T top(){
        return queue[Rear];
    }
};





