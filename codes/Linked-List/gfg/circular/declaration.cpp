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
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

Node* input(int n) 
{
    Node *head;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        Node *mover;
        if (i == 0)
        {
             head = new Node(val);
             mover = head;
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
int main () {
    int n;
    cout << "Number of Nodes: ";
    cin >> n;
}