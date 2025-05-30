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

int main () {
    int n;
    cin >> n;
    Node* head = inputdll(n);
    


    return 0;
}