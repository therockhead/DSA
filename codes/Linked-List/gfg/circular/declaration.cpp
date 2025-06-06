// @uthor: asif

#include<bits/stdc++.h>
using namespace std;

// declaration of node is
// similar to the singly linked list
// So it's basically circular singly linked list

/* If we want to create for other data type as well

    template <typename T>
    class Node {
    public:
        T data;
        Node<T>* next;

        Node(T value) {
            data = value;
            next = nullptr;
        }
    };

    usage: Node<int>* newNode = new Node<int>(5);
*/

// Normal design of a node
// with integer
class Node {
public:
    int data;
    Node* next;
public:
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

Node* input(int n) 
{
    if (n == 0) {
        return nullptr;
    }

    Node *head;
    Node *mover;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
       
        if (i == 0)
        {
             head = new Node(val);
             mover = head;
        }
        else if(i == n-1) {
            Node* temp = new Node(val);
            mover->next = temp;
            mover = temp;
            mover->next = head;
        }
        else
        {
            Node *temp = new Node(val); 
            mover->next = temp;
            mover = temp;                 
        }
    }
   
    return head;
}

void printCLL(Node* head) {
    Node* temp = head;
    
    // using do while
    // because we need to print the temp->data of head once
    if (head != nullptr) {
        do {
            cout << temp->data << ' ';
            temp = temp->next;
        } while (temp != head);
    }
    // disadvantage of using while looop is
    // the print will never gonna happen
    // because it checks first the temp is head or not then 
    // finds the temp is at head, so stops printing

    // while(temp != head) {
    //     cout << temp->data << ' ';
    //     temp = temp->next;
    // }
}
Node* insert(Node* head, int val) {
    if (head == NULL) {
        Node* newNode = new Node(val);
        newNode->next = newNode;
        
        return newNode; // if the head was null initially, then
        // newNode will be the new HEAD
    }
    else {
        Node* newNode = new Node(val);
        Node* temp = head;

        // traversing
        do{
            temp = temp->next;
        } while(temp->next != head);

        // insert the new Node at the end
        temp->next = newNode;
        newNode->next = head;
        return head;
    }
    
}
int main () {
    int n;
    cout << "Number of Nodes: ";
    cin >> n;
    Node* head = input(n);
    head = insert(head, 100);
    printCLL(head);
    return 0;
}