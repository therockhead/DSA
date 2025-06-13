// Double Linked List or DLL
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
struct Node
{
    int data;
    Node* next;
    Node* back;
    Node(int data, Node *next, Node *back)
    {
        this->data = data;
        this->next = next;
        this->back = back;
    }
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->back = nullptr;
    }
};
// input func
Node *inputDLL(int n)
{
    if (n == 0) {
        return nullptr;
    }
    
    Node *head;
    Node *prev;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        if (i == 0)
        {
            head = new Node(value);
            prev = head;
            // storing head's address in prev
            // prev will be used by the next node as back pointer
        }
        else
        {
            Node *temp = new Node(value, nullptr, prev);
            prev->next = temp; // linking with previous node
            prev = temp;       // updating the prev pointer with the address of temp
            // thus, when we will create the next node,,
            // the back pointer of that node will point to its previous node
        }
    }
    return head;
}
// print func
void printDLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << ' ';
        head = head->next; // moving forward in the LL
    }
    cout << "\n"; // doesn't impact, only for print formatting
}
// deleting the head
Node *deleteHead(Node *head)
{
    if (head == nullptr)
    { // dealing with edge cases
        cout << "Empty List";
        return nullptr; // or return NULL;
    }
    if (head->next == nullptr)
    { // when there is only one element
        return nullptr;
    }
    Node *prev = head;
    head = head->next;    // next node of head will become new head
    head->back = nullptr; // next node which is now the head can't remain linked with the previous head node
    // so we are making the new head's back null pointer
    prev->next = nullptr; // as we stored the previous head's address in prev
    // in the previous line, we remove the backward link of new head and the previous head
    // now we just remove the forward link between new and previous heads
    // we have to do both as it is double linked list.
    // So we have to manually delete it with delete keyword
    return head; // now returning new head actually
}
// deleting the tail func
Node *deleteTail(Node *head)
{
    // tail is the last node of the linked list
    // tail->next points to null pointer
    // it has a back pointer which will point to the previous node
    // now we have to delete the tail.

    // if we want to delete the tail, ultimately we should make the prev node's next null
    //  also, the back of the tail should be null.
    //  to access tail we have to traverse until we find the tail
    //  so HOW TO DETERMINE IT's A TAIL OR NOT?
    //--- It's simple, just traverse until we find node->next == nullptr

    if (head == NULL || head->next == NULL)
    { // dealing with edge cases
        return NULL;
    }
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *newTail = tail->back;
    newTail->next = nullptr; // making newTail the actual tail by assigning nullptr to next
    // it means there will be no node after tail
    tail->back = nullptr; // making previous tail unlinked with the newTail
    // by assigning the back pointer to nullptr;
    delete tail; // delete the tail
    return head;
}
// To delete element from position k (1,2,3,,,,,size of linkedlist)
Node* deleteKth(Node *head, int k)
{
    // need a temp pointer of type Node (Node* temp)
    // while loop needed until (temp != null)
    // count everytime until count = k+1, means stop counting on value k
    if (head == NULL) {
        return NULL;
    }
    Node* kNode = head;
    int count = 0;
    while (kNode != NULL)
    {
        count++;
        if (count == k) break;
        kNode = kNode->next;
    }
    Node *prev = kNode->back;
    Node *front = kNode->next;
    if (prev == NULL && front == NULL)
    { // simply has one element only which is also head
        return NULL;
    }
    else if (prev == NULL)
    { // it means it's the head, but not one element like previous condition
        return deleteHead(head);
    }
    else if (front == NULL)
    { // if it the tail
        return deleteTail(head);
    }
    // linking the (k-1)th element with (k+1)th element
    // prev pointer denotes (k-1)th element
    // front pointer denotes (k+1)th element
    prev->next = front;
    front->back = prev;
    kNode->next = nullptr;
    kNode->back = nullptr;
    delete kNode;
    return head;
}
void deleteNode(Node* temp) {
    Node* prev = temp->back;
    Node* front = temp->next;
    if (front == NULL) {
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return;
    }
    prev->next = front; // front or temp->next
    front->back = prev;
    // making temp node vanish by unlinking
    temp->back = nullptr;
    temp->next = nullptr;
    free(temp);
}
Node* insertBeforeHead(Node* head, int data) {
    Node* newNode = new Node(data, head, nullptr);
    head->back = newNode;
    newNode->next = head;
    return newNode;
}
Node* insertBeforeTail(Node* head, int data) {
    if (head->next == NULL) { // if one element
        return insertBeforeHead(head, data);
    }
    Node* tail = head;
    while(tail->next != nullptr) {
        tail = tail->next;
    }
    Node* prev = tail->back;
    Node* newNode = new Node(data, tail, prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
}
Node* insertBeforeKth(Node* head, int k, int data) {
    if (k == 1) {
        return insertBeforeHead(head, data);
    }
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL) {
        cnt++;
        if (cnt == k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(data, temp, prev);
    
    prev->next = newNode;
    temp->back = newNode;
    return head;
}
void insertBeforeANode(Node* temp, int data) {
    // temp is given node
    Node* prev = temp->back;
    Node* newNode = new Node(data, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return;
}
int main()
{
    int n;
    cin >> n;
    Node *head = inputDLL(n);
    printDLL(head);
    return 0;
}