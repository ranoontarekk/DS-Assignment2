#include <iostream>
using namespace std;

template<class type>
class Node
{
public:
    type data;
    Node<type> * next;
    Node()
    {
        next = nullptr;
    }
};

template<class type>
class CircularLinkedList
{
private:
    Node<type> * head;
    Node<type> * tail;
    int size;
public:
    CircularLinkedList();
    void insertAtHead(type val);
    void insertAtTail(type val);
    void insertAt(type val , int index);
    void removeAtHead();
    void removeAtTail();
    void removeAt(int index);
    void replaceAt(type val,int index);
    void swap(int firstItemIdx, int secondItemIdx);
    type retrieveAt(int index);
    void clear();
    int linkedListSize();
    void print();
    bool isEmpty();
    bool isExist(type val);
    bool isItemAtEqual(type val , int index);
    int circularLinkedListSize () ;
};

template<class type>
CircularLinkedList<type>::CircularLinkedList() {
    head = tail =  nullptr;
    size = 0;
}

//Time Complexity O(1)
template<class type>
bool CircularLinkedList<type>::isEmpty() {
    return head == nullptr;
}

//Time Complexity O(1)
template<class type>
void CircularLinkedList<type>::insertAtHead(type val) {
    Node<type> * newNode = new Node<type>();
    newNode->data = val;
    size++;
    if (isEmpty()) {
        head = tail = newNode;
        newNode->next = head;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
}

//Time Complexity O(1)
template<class type>
void CircularLinkedList<type>::insertAtTail(type val) {
    Node<type> * newNode = new Node<type> ();
    newNode->data = val ;
    size++;
    if (isEmpty()) {
        head = tail = newNode;
        newNode->next = head;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
}

//Time Complexity O(n)
template<class type>
void CircularLinkedList<type>::insertAt(type val, int index) {
    if (index > size || index < 0 || index > size)
        cout<<"out of range\n";
    else
    {
        size++;
        Node<type> * newNode = new Node<type> ();
        newNode->data = val;
        Node<type> * tmp = head;
        int i = 1;
        while (i != index-1)
        {
            tmp = tmp->next;
            i++;
        }
        newNode->next = tmp->next;
        tmp->next = newNode;
        tmp = newNode;
    }
}

//Time Complexity O(n)
template<class type>
bool CircularLinkedList<type>::isExist(type val) {
    Node<type> * tmp = head;
    do
    {
        if (tmp->data == val)
            return true;
        tmp = tmp->next;
    } while (tmp != head);
    return false;
}

//Time Complexity O(n)
template<class type>
bool CircularLinkedList<type>::isItemAtEqual(type val, int index) {
    if (isEmpty() || index >= size || index < 0)
    {
        cout << "out of range\n";
        return false;
    }
    else
    {
        Node<type> * tmp = head;
        int i = 0;
        while (i != index)
        {
            tmp = tmp->next;
            i++;
        }
        if (tmp->data == val)
            return true;
        else
            return false;
    }
}

//Time Complexity O(n)
template<class type>
void CircularLinkedList<type>::clear() {
    if (isEmpty())
        cout<<"list is already empty\n";
    else
    {
        Node<type> * tmp = head;
        Node<type> * nextNode = nullptr;
        do
        {
            nextNode = tmp->next;
            delete tmp;
            tmp = nextNode;
        } while (tmp != head);
        head = tail = nullptr;
        size = 0;
    }
}

//Time Complexity O(1)
template<class type>
void CircularLinkedList<type>::removeAtHead() {
    if (isEmpty()) {
        cout << "Circular Linked List is empty\n";
    } else {
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            size = 0;
        } else {
            Node<type> *tmp = head;
            head = head->next;
            tail->next = head;
            delete tmp;
            size--;
        }
    }
}

//Time Complexity O(n)
template<class type>
void CircularLinkedList<type>::removeAtTail() {
    if (isEmpty()) {
        cout << "Circular Linked List is empty\n";
    } else {
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            size = 0;
        } else {
            Node<type> *tmp = head;
            while (tmp->next != tail) {
                tmp = tmp->next;
            }
            tmp->next = head;
            delete tail;
            tail = tmp;
            size--;
        }
    }
}

//Time Complexity O(n)
template<class type>
void CircularLinkedList<type>::removeAt(int index) {
    if (isEmpty() || index >= size || index < 0) {
        cout << "out of range\n";
    } else {
        if (index == 0) {
            removeAtHead();
        } else if (index == size - 1) {
            removeAtTail();
        } else {
            Node<type> *tmp = head;
            int i = 0;
            while (i != index - 1) {
                tmp = tmp->next;
                i++;
            }
            Node<type> *nodeToDelete = tmp->next;
            tmp->next = tmp->next->next;
            delete nodeToDelete;
            size--;
        }
    }
}

//Time Complexity O(n)
template<class type>
void CircularLinkedList<type>::replaceAt(type val, int index) {
    if (isEmpty() || index >= size || index < 0) {
        cout << "out of range\n";
    } else {
        Node<type> *tmp = head;
        int i = 0;
        while (i != index) {
            tmp = tmp->next;
            i++;
        }
        tmp->data = val;
    }
}

//Time Complexity O(n)
template<class type>
void CircularLinkedList<type>::swap(int firstItemIdx, int secondItemIdx) {
     if (isEmpty() || firstItemIdx >= size || secondItemIdx >= size || firstItemIdx < 0 || secondItemIdx < 0) {
        cout << "Out of range\n";
        return;
    }
    
    if (firstItemIdx == secondItemIdx) {
        cout << "They are the same index\n";
        return;
    }

    Node<type> *prev1 = nullptr, *prev2 = nullptr;
    Node<type> *node1 = head, *node2 = head;
    //prev1 and prev2 are the nodes before node1 and node2 
    for (int i = 0; i < firstItemIdx; i++) {
        prev1 = node1;
        node1 = node1->next;
    }

    for (int i = 0; i < secondItemIdx; i++) {
        prev2 = node2;
        node2 = node2->next;
    }
    //the next of prev1 and prev2 will be the nodes node1 and node2
    if (prev1 != nullptr) {
        prev1->next = node2;
    } else {
        head = node2;
    }

    if (prev2 != nullptr) {
        prev2->next = node1;
    } else {
        head = node1;
    }
    //swapping the next of node1 and node2
    Node<type> *temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;

}

//Time Complexity O(n)
template<class type>
type CircularLinkedList<type>::retrieveAt(int index) {
    if (isEmpty() || index >= size || index < 0) {
        cout << "out of range\n";
        // Returning a reference to a default-constructed value for error handling
        static type default_val;
        return default_val;
    } else {
        Node<type> *tmp = head;
        int i = 0;
        while (i != index) {
            tmp = tmp->next;
            i++;
        }
        return tmp->data;
    }
}

//Time Complexity O(n)
template<class type>
void CircularLinkedList<type>::print() {
    if (isEmpty())
        cout << "Circular Linked List is empty\n";
    else {
        Node<type> *tmp = head;
        cout << "Circular Linked List: ";
        do {
            cout << tmp->data << " ";
            tmp = tmp->next;
        } while (tmp != head);
        cout << endl;
    }
}

//Time Complexity O(1)
template<class type>
int CircularLinkedList<type>::circularLinkedListSize () {
    return size;
}

int main() {
    // Create an instance of CircularLinkedList
    CircularLinkedList<int> myLinkedList;

    // Append some data to the list
    myLinkedList.insertAtTail(10);
    myLinkedList.insertAtTail(20);
    myLinkedList.insertAtHead(30);
    myLinkedList.insertAt(40 , 1);

    // Display the original list
    cout << "Original list: ";
    myLinkedList.print();

    // Swap nodes at index 1 and index 3
    myLinkedList.swap(1, 3);

    // Display the list after swapping
    cout << "List after swapping: ";
    myLinkedList.print();
    cout << "Size of the list: " << myLinkedList.circularLinkedListSize() << endl;

    return 0;
}
