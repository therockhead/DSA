#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int d)
    {
        data = d;
        prev = nullptr;
        next = nullptr;
    }
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};
// input
Node *inputdll(int n)
{

    if (n == 0) {
        return nullptr;
    }
    
    Node *head;
    Node *prev;
    

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        if (i == 0)
        {
            head = new Node(val);
            prev = head;
        }
        else
        {
            Node *temp = new Node(val , nullptr, prev);
            prev->next = temp;
            prev = temp;
        }
    }
    return head;
}
// print
void printDLLforward(Node *head)
{
    if (head == nullptr)
        return;
    cout << head->data << " ";
    printDLLforward(head->next); 
}

/*Deletion functions related to Double Linked List*/
// Deletion at the beginning of the list
Node* delHead(Node* head) {
    // when the list is empty
    if (head == nullptr) return head; // or return null pointer
    
    // store the current head node to delete
    Node* temp = head;

    // mode head to the next node
    head = head->next;

    // set the previous pointer of the
    // new head to the null pointer
    if (head != nullptr) {
        head->prev = nullptr;
    }

    // free the memory of the old head node
    delete temp;

    // return the new head
    return head;
}

// delete the node after a given node (key)
Node* deleteAfterNode(Node* head, int key) {
    Node* curr = head;

    // iterate over ll to find the key
    while(curr != nullptr) {
        if (curr->data == key) {
            break;
        }
        curr = curr->next;
    }

    // if curr is NULL or curr->next is NULL
    // there is no node to delete
    if (curr  == nullptr || curr->next == nullptr) {
        return head;
    }
    // this is the node which is being deleted
    // as the key matches with current node,
    // so the curr->next is the node to be deleted
    Node* nodeDelete = curr->next;

    // update the next of the curr node
    // to the next of the node to be deleted
    curr->next = nodeDelete->next;

    // if the node to be deleted's next is not null, then
    // it will have a prev pointer pointing to the node before the deletedNode 
    if(nodeDelete->next != nullptr) {
        nodeDelete->next->prev = curr;
    }

    delete nodeDelete;
    return head;
}
// delete before a given node (key)
Node* deleteBefore(Node* head, int key) {
    Node* curr = head;

    // find the key
    while (curr!=nullptr) {
        if (curr->data == key) {
            break;
        }
        curr = curr->next;
    }

    // if curr is nullptr or curr-prev is nullptr
    // that means, we traversed all the nodes but didn't find the key node
    // so there is no node to be deleted
    if (curr == nullptr || curr->prev == nullptr) {
        return head;
    }

    // Otherwise
    // Node to be deleted
    // the previous of curr means the node before curr
    Node* nodeDelete = curr->prev;
    
    // update the prev of the curr node
    // to the prev  of the node to be deleted
    curr->prev = nodeDelete->prev;

    // if nodeDelete's prev is not nullptr
    // update its next pointer to the current node
    if (nodeDelete->prev != nullptr) {
        nodeDelete->prev->next = curr;
    } else {
        // if nodeDelete is the head node
        head = curr;
    }

    // free the memory space for nodeDelete
    delete nodeDelete;
    return head;
}

// delete at a specific position
// a position parameter needed instead of key
Node* deleteSpecificNode(Node* head, int pos) { 
    if (head == nullptr) {
        return head;
    }
    Node* curr = head;

    // traverse
    for (int i = 1; curr != nullptr && i < pos; i++) {
        curr = curr->next;
    }

    // if the position is out of range
    if (curr == nullptr) {
        return head;
    }

    // update the previous node's next pointer
    if (curr->prev != nullptr) {
        curr->prev->next = curr->next;
    }

    // update the next node's prev pointer
    if (curr->next != nullptr) {
        curr->next->prev = curr->prev;
    }

    // if the node to be deleted is the head itself
    if (head == curr) {
        head  = curr->next;
    }

    // deallocate memory for the deleted node
    delete curr;
    return head;
}

// delete the tail of the dll
Node* deleteTail(Node* head) {
   
    // 2 things can happen,
    // there is no head and no existence of the list
    // another one is the head itself is the tail (one element in the list)
    // in both cases, we will return nullptr
    // if 1 element, why return null?
    //---- it's because we are deleting it and ultimately we have 0 element
    //---- which will be returned
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // initialize curr with head node
    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }

    // saving the tail in nodeDelete node
    Node* nodeDelete = curr;
    
    // if the prev is not null, then only the prev's next should point to null
    // as the prev of tail will be the new tail
    if(nodeDelete->prev != nullptr){
        nodeDelete->prev->next = nullptr;
    }
    
    // free up the memory
    delete nodeDelete;

    // returns the head as it's the return type
    return head;
}
// main function
int main () {
    int n;
    cin >> n;
    Node* head = inputdll(n);
    


    return 0;
}