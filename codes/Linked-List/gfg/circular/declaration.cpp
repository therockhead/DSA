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
