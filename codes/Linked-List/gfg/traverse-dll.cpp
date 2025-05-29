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
// forward traversal
// Time Complexity: O(n), Space Complexity O(1)
void forwardTraversal(Node *head)
{
    Node *curr = head; // initialize at head
    while (curr != NULL)
    {
        cout << curr->data << " "; // access the data at current node
        curr = curr->next;         // move to the next node
    }
    cout << endl;
}

// forward traversal
// recursion approach
// Time Complexity: O(N), Space Complexity O(N)
void forwardTraversalRecursive(Node *head)
{
    if (head == nullptr)
        return;
    cout << head->data << " ";
    forwardTraversalRecursive(head->next);
}

// backward traversal
void backwardTraversal(Node *tail)
{
    Node *curr = tail;

    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->prev;
    }
}
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
int main()
{
    int n;
    cin >> n;
    Node *head = inputdll(n);
    forwardTraversalRecursive(head);
    cout << "end";
}
