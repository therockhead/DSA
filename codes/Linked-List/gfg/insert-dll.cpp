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
void printDLLforward(Node *head)
{
    if (head == nullptr)
        return;
    cout << head->data << " ";
    printDLLforward(head->next);
}

/*insertion in a double linked list*/

// insert new head
// time complexity O(1), Space Complexity O(1)
Node *insertHead(Node *head, int val)
{
    Node *newNode = new Node(val);
    newNode->prev = nullptr;
    newNode->next = head;
    if (head != NULL)
    {
        head->prev = newNode;
    }
    return newNode;
}
Node* insertBeforeK(Node* head, int k, int data) {
    Node* curr = head;

    // iterate over linked list to find k-valued element
    while (curr != NULL) {
        if (curr->data == k) break;
        curr = curr->next;
    }

    // if curr becomes null means, given k node is not
    // found in linked list
    // means the curr is in tail->next position and k node is not found
    // and we all know tail->next is null
    if (curr == NULL) {
        return head;
    }

    // Create a new node with the data
    Node* new_node = new Node(data);

    // set prev of new node to prev of given node
    new_node->prev = curr->prev;

    // set the next node of new_node to curr which is k-valued node actually
    new_node->next = curr;

    // update next of given node's prev to new node
    if (curr->prev != NULL) {
        new_node->prev->next = new_node;
    }
    else {
        // if the current node is the head, update the head
        head = new_node;
    }
    // update prev of given node to new node
    curr->prev = new_node;

    return head;
}
int main() {


}