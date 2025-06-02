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
Node* insertBeforeSpecificPosition(Node* head, int pos, int data) {
    // creating node with new data
    Node* new_node = new Node(data);

    // if the position is 1, then
    // it means the new_node is the new_head;
    if (pos == 1) {
        new_node->next = head;
        // if head is not null, then 
        // it's prev should point to the new_node (new_head)
        // otherwise it only stays NULL
        if (head != NULL) {
            head->prev = new_node;
        }
        // head will be replaced with new_node
        head = new_node;
        return head; 
        // or we can easily return new_node only
    }
    // now, if the pos in not 1
    Node* curr = head;
    int cnt = 0;
    while (curr != NULL) {
        if (cnt == pos-2) { // indexes: 0, 1, 2, 3
            // if the pos is 3, it means index 2
            // then curr should stop at index 1
            // then break
            break;
        }
        cnt++;
        curr = curr->next; // iterating
    }
    if (curr == NULL) { // if curr reaches at the tail->next
        // while loop stops
        // that means the position is out of bound;
        cout << "Position out of bounds.\n";
        delete new_node;
        return head;
        // stops
    }
    new_node->next = curr->next;
    curr->next = new_node;
    new_node->prev = curr;

    if (new_node->next != NULL) { // if the next node of new node is not NULL
        new_node->next->prev = new_node; // then the prev of next node of new_node will be new_node
    }
    return head;
}
Node* insertTail(Node* head, int data) {
    Node* new_node = new Node(data);

    
    if (head == NULL) head = new_node; // if the linked list is empty
    else {
        Node* curr = head;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_node;
        new_node->prev = curr;
        new_node->next = NULL;
    }

    return head;
}

int main() {
    int n;
    cin >> n;
    Node* head = inputdll(n);
    printDLLforward(head);
    cout << "end\n"; 
    head = insertBeforeSpecificPosition(head, 3, -1); // add -1 before 3
    printDLLforward(head);
    cout << "end\n";
    head = insertTail(head, 100);
    printDLLforward(head);
    cout << "end\n";
    return 0;
}