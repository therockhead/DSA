// NOT VERY EFFICIENT
#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
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
// input
Node *inputDLL(int n)
{
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
// output
void printDLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << ' ';
        head = head->next; // moving forward in the LL
    }
    cout << "\n"; // doesn't impact, only for print formatting
}
Node* reverseDLL(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* prev = NULL;
    Node* current = head;
    while (current != NULL) {
        // swapping back and next pointers
        prev = current->back; // storing current node's back in prev
        current->back = current->next; // turning current's back into its next
        current->next = prev; // current's next will be current's previous
        current = current->back; // current's back will become new current
    }
    // reversing done
    return prev->back; // returning new head
}
int main() {
    int n;
    cin >> n;
    Node* head = inputDLL(n);
    printDLL(head);
    head = reverseDLL(head);
    cout << "\nAfter Reversing: \n"; 
    printDLL(head);
    cout << '\n';
    return 0;
}
// Time-Complexity: Big-O (2*n) // 2 times loop until n
// Space-Complexity: Big-O(n) // as we are using a stack
// NOT VERY EFFICIENT