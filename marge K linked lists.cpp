
#include <iostream>
#include "SingleLinkedList.cpp"
using namespace std;

template<class type>
void singleLinkedList<type>::Combine(singleLinkedList& list) {
    for(Node<type>* pt=list.head;pt!=0;pt=pt->getnext()){
        this->insertAtTail((pt->getinfo()));
    }
}

template<class T>
void swapForSort(Node<T>* a, Node<T>* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
template<class T>
void bubbleSort(singleLinkedList<T>& list, int size) {
    if (size <= 1) {
        return;
    }

    Node<T>* current = list.head;
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = 0; i < size - 1; i++) {
            Node<T>* nextNode = current->next;
            if (current->data > nextNode->data) {
                swapForSort(current, nextNode);
                swapped = true;
            }
            current = current->next;
        }
        current = list.head;
        size--;
    }
}
singleLinkedList<int> problem2(singleLinkedList<int> arr[], int size) {
    singleLinkedList<int> ans;
    for (int i = 0; i < size; i++) {
        ans.Combine(arr[i]);
    }
    bubbleSort(ans, ans.getSize());
    cout << "list after merging and sorting: ";
    ans.print();
    return ans;
}


int main ( ) {
     int size=3;
    singleLinkedList<int>l[size];
    singleLinkedList<int>sorted;
    l[0].insertAtTail(1);
    l[0].insertAtTail(4);
    l[0].insertAtTail(5);

    l[1].insertAtTail(1);
    l[1].insertAtTail(3);
    l[1].insertAtTail(4);

    l[2].insertAtTail(2);
    l[2].insertAtTail(6);

    singleLinkedList<int> ans;
    for (int i = 0; i < 3; i++) {
        ans.Combine(l[i]);
    }

    for (int i = 1; i < 8; i++) {
        for (int j = 1; j < 8; j++) {
            if (ans.retrieveAt(j) > ans.retrieveAt(j + 1)) {
                ans.swap(j, j + 1);
            }
        }
    }
     problem2(l, size) ;


};
