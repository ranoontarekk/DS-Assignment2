#include <iostream>
#define MAX 100
using namespace std;
template <class T>
class Stack{
    int size;
    T stack[MAX];
    T top;
public:
    Stack(){
        size = 0;
        top = -1;
    }
    void push(T data){
        if(size == MAX) {
            cout << "Stack is full" << endl;
            return;
        }
        size++;
        stack[++top] = data;

    }
    T pop(){
        if(size == 0){
            cout << "Stack is empty" << endl;
            return -1;
        }
        T data = stack[top--];
        size--;
        return data;
    }

    T Top (){
       return stack[top];
    }
    bool isEmpty(){
        return size == 0 ;
    }
    int stackSize(){
        return  size;
    }
    void clear(){
        size = 0;
        top = -1 ;
    }
    void printFromToptoBottom(){
        for (int i = size -1 ; i >=0; --i) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
    void printFromBottomtoTop(){
        for (int i = 0 ; i < size ; ++i) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};



