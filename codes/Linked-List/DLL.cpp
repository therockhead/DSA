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
// input func
Node* inputDLL(int n) {
    Node* head;
    Node* prev;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        if (i == 0) {
            head = new Node(value);
            prev = head; 
            // storing head's address in prev
            // prev will be used by the next node as back pointer
        } else {
            Node* temp = new Node(value, nullptr, prev);
            prev->next = temp; // linking with previous node
            prev = temp; // updating the prev pointer with the address of temp
            // thus, when we will create the next node,,
            // the back pointer of that node will point to its previous node
        }
    }
    return head;
}
// print func
void printDLL(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next; // moving forward in the LL
    }
    free(temp);
    cout << "\n"; // doesn't impact, only for print formatting
}
// deleting the head
Node* deleteHead(Node* head) {
    if (head == NULL) { // dealing with edge cases
        cout << "Empty List";
        return head;
    }
    Node* prev = head;
    head = head->next; // next node of head will become new head
    head->back = nullptr; // next node which is now the head can't remain linked with the previous head node
    // so we are making the new head's back null pointer
    prev->next = nullptr; // as we stored the previous head's address in prev
    // in the previous line, we remove the backward link of new head and the previous head
    // now we just remove the forward link between new and previous heads
    // we have to do both as it is double linked list.
    delete prev; // C++ doesn't automatically clear garbages like Java
    // So we have to manually delete it with delete keyword
    return head; // now returning new head actually
}
// deleting the tail func
Node* deleteTail(Node* head) {
    //Complete
    /*

    */
    return head;
}
int main() {
    int n; cin >> n;
    Node* head = inputDLL(n);
    printDLL(head); 
    return 0;

}