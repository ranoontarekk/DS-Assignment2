#include "Queue.cpp"
using namespace std;
template <class T>
class Stack {
public:
    ~Stack() {
        q1.clear();
        q2.clear();
    }
    void push(T element) {
        q1.enqueue(element); // Enqueue the new element to q1
    }

    void pop() {
        if (q1.isEmpty()) return; 
        int size = q1.QueueSize();
       
        for (int i = 0; i < size - 1; i++) {
            // q1: 1 2 3 4 5
            // q2: 1 2 3 4
            q2.enqueue(q1.First()); // adding the first element in the q1 to the end of q2
            q1.dequeue(); // pop first element of q1
        }

        q1.dequeue(); // pop the last element (top of the stack)
        std::swap(q1, q2);
    }

    T top() {
        return q1.top(); 
    }

    bool empty() {
        return q1.isEmpty(); 
    }

    void print() {
        q1.print(); 
    }

private:
    Queue<T> q1; 
    Queue<T> q2; 
};

int main ( ) {
    Queue<int> Q1;
    Q1.enqueue(1);
    Q1.enqueue(2);
    Q1.enqueue(3);
    Q1.enqueue(4);
    Q1.enqueue(5);
    Q1.dequeue();
    cout << "Queue elements are: ";
    Q1.print();
    cout << "--------------------------------------------------------" << endl;
    Stack <int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << "Top element is: " << s.top() << endl;
    s.print();
    s.pop();
    cout << "Top element is: " << s.top() << endl;
    s.print();
    cout << "--------------------------------------------------------" << endl;
    Stack <char> s2;
    s2.push('a');
    s2.push('b');
    s2.push('c');
    s2.push('d');
    s2.push('e');
    cout << "Top element is: " << s2.top() << endl;
    s2.print();
    
}
