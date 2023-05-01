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
        next = NULL;
    }
    Node<type>* getnext();
    type getinfo();

};
template<class type>
class singleLinkedList
{
public:
    Node<type> * head;
    Node<type> * tail;
    int size;
public:
    singleLinkedList();
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
    int getSize();
    void Combine(singleLinkedList<type>& list);


};
template<class type>
type Node<type> ::getinfo(){
    type s=data;
    return data;

}
template<class type>
Node<type>* Node<type>::getnext(){
    Node<type>* n= next;
    return n;
}
template<class type>
int singleLinkedList<type>::getSize(){
    int sz= size;
    return sz;
}

template<class type>
singleLinkedList<type>::singleLinkedList() {
    head = tail = NULL;
    size = 0;
}

template<class type>
bool singleLinkedList<type>::isEmpty() {
    return head == NULL;
}

template<class type>
void singleLinkedList<type>::insertAtHead(type val) {
    Node<type> * newNode = new Node<type>();
    newNode->data = val;
    size++;
    if (isEmpty())
        head = tail = newNode;
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

template<class type>
void singleLinkedList<type>::insertAtTail(type val) {
    Node<type> * newNode = new Node<type> ();
    newNode->data = val ;
    size++;
    if (isEmpty())
        head = tail = newNode;
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

template<class type>
void singleLinkedList<type>::insertAt(type val, int index) {
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

template<class type>
void singleLinkedList<type>::print() {
    Node<type> *tmp = head;
    while (tmp != NULL)
    {
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}

template<class type>
int singleLinkedList<type>::linkedListSize() {
    return size;
}

template<class type>
void singleLinkedList<type>::removeAtHead() {
    if (isEmpty())
        cout<<"list is empty\n";
    else
    {
        Node<type> * tmp = head;
        head = head->next;
        size--;
        delete tmp;
    }
}

template<class type>
void singleLinkedList<type>::removeAtTail() {
    if (isEmpty())
        cout<<"list is empty\n";
    else
    {
        size--;
        Node<type> * tmp = head;
        while (tmp->next != tail)
        {
            tmp = tmp->next;
        }
        tail = tmp;
        tail->next = NULL;
        delete tmp->next;
    }
}

template<class type>
void singleLinkedList<type>::clear() {
    if (isEmpty())
        cout<<"list is empty\n";
    else
    {
        while (head != NULL)
            removeAtHead();
    }
}

template<class type>
void singleLinkedList<type>::removeAt(int index) {
    if (isEmpty())
        cout<<"list is empty\n";
    else
    {
        size--;
        Node<type> * tmp = head;
        Node<type> * del;
        int i = 1;
        while (i != index-1)
        {
            tmp = tmp->next;
            i++;
        }
        del = tmp->next;
        tmp->next = tmp->next->next;
        delete del;
    }
}

template<class type>
type singleLinkedList<type>::retrieveAt(int index) {
    if (isEmpty() || index < 0 || index > size)
        cout<<"invalid index\n";
    else
    {
        if (index == 1)
            return head->data;
        else
        {
            Node<type> * tmp = head;
            int i = 1;
            while (i != index-1)
            {
                tmp = tmp->next;
                i++;
            }
            return tmp->next->data;
        }

    }
}

template<class type>
void singleLinkedList<type>::replaceAt(type val, int index) {
    if (isEmpty() || index < 0 || index > size)
        cout<<"list is empty\n";
    else
    {
        if (index == 1)
            head->data = val;
        else
        {
            Node<type> * tmp = head;
            int i = 1;
            while (i != index-1)
            {
                tmp = tmp->next;
                i++;
            }
            tmp->next->data = val ;
        }
    }
}

template<class type>
bool singleLinkedList<type>::isExist(type val) {
    bool check = false;
    Node<type> * tmp = head;
    while (tmp != NULL)
    {
        if (tmp->data == val)
        {
            check = true;
            break;
        }
        else
            tmp = tmp->next;
    }
    return check;
}

template<class type>
bool singleLinkedList<type>::isItemAtEqual(type val , int index) {
    if (isEmpty() || index < 0 || index > size)
        return false;
    else
    {
        if (index == 1)
        {
            return head->data == val;
        }
        else
        {
            Node<type> * tmp = head;
            int i = 1;
            while (i != index-1)
            {
                tmp = tmp->next;
                i++;
            }
            return tmp->next->data == val;

        }
    }
}

template<class type>
void singleLinkedList<type>::swap(int firstItemIdx, int secondItemIdx) {
    if (firstItemIdx == secondItemIdx)
    {
        return;
    }
    Node<type>* first = head;
    Node<type>* prevFirst = NULL;
    Node<type>* second = head;
    Node<type>* prevSecond = NULL;
    for (int i = 0; i < firstItemIdx && first != NULL; i++)
    {
        prevFirst = first;
        first = first->next;
    }
    for (int i = 0; i < secondItemIdx && second != NULL; i++)
    {
        prevSecond = second;
        second = second->next;
    }
    if (first == NULL || second == NULL)
    {
        return;
    }
    if (prevFirst != NULL)
    {
        prevFirst->next = second;
    }
    else
    {
        head = second;
    }
    if (prevSecond != NULL)
    {
        prevSecond->next = first;
    }
    else
    {
        head = first;
    }
    Node<type>* temp = first->next;
    first->next = second->next;
    second->next = temp;
}


   
