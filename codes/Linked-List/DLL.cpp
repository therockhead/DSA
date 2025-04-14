//Double Linked List or DLL
#include <bits/stdc++.h>
using namespace std;
// in Single LL, we had data and next in a node
// in Double LL, we need the previous memory location also
// so we should add a back pointer (extra pointer to a SLL) 

// **Formation**
// we need a head always (like SLL)
// head = new Node(data, nullptr, nullptr)
// first, head has next as null pointer and back as null pointer
/*  for example if we want to create a list manually:
-------------------------------------------------------
    Node* head = new Node(5);
    Node* prev = head;
    // So, here head has been created with data = 5 and,
    // The Node type of pointer prev is storing the address of head;

    Node* node1 = new Node(2, nullptr, prev);
    head->next = node1; // linking this with head
    // in this node the back pointer gets the address of head 
    // previously, the address of head was stored in prev pointer

    Node* node2 = new Node(3, nullptr, node1); // as we can see,
    // here the back pointer is pointing towards node1
    node1->next = node2; // linking this node1


*/
// basic custom DLL Definition
struct Node{
    int data;
    Node* next;
    Node* back;
    Node(int data, Node* next, Node* back) {
        this->data = data;
        this->next = next;
        this->back = back;
    }
    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->back = nullptr;
    }
};

int main() {
    Node* head = new Node(5);
    Node* prev = head;
    Node* node1 = new Node(2, nullptr, prev);
    head->next = node1;
    Node* node2 = new Node(3, nullptr, node1);
    node1->next = node2;

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    return 0;

}