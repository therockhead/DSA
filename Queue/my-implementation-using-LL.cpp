/*--- Queue Implementation from scratch using Linked List by Asif ---*/
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node() {
        next = nullptr;
    }
    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
Node* inputLL(int n) {
    int data; cin >> data;
    Node* temp = new Node(data);
    Node* head = temp;
    if (n == 0) return head;
    for (int i = 1; i < n; i++) {
        cin >> data;
        Node* newNode = new Node(data);
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}
void printLL(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
}
class Queue {
    int capacity = 1000;
    public:
    Node* Enqueue(Node* head, int data) {
        if (capacity > 1000) {
            cout << "No more capacity left. memory overflown. You can't enqueue" << '\n';
            return head;
        }
        if (sizeOfQueue(head) < 0) {
            cout << "Queue Underflow" << '\n';
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        Node* newNode = new Node(data);
        temp->next = newNode;

        return head;
    } 
    Node* Dequeue(Node* head) {
        if (sizeOfQueue(head) == 0) {
            cout << "Underflow. You can't dequeue" << '\n';
        }
        Node* temp = head;
        head = temp->next;
        return head;
    }
    int sizeOfQueue(Node* head) {
        Node* temp = head;
        int cnt = 0;
        while (temp != NULL) {
            temp = temp->next;
            cnt++;
        }
        return cnt; // the size
    }
};
int main() {
    int n;
    cin >> n;
    Node* head = inputLL(n);
    // printLL(head);
    Queue q;
    cout << q.sizeOfQueue(head) << '\n';
    
    
    int data = 5;
    head = q.Enqueue(head, data);
    printLL(head);
    cout << '\n';
    cout << q.sizeOfQueue(head) << '\n'; 
    head = q.Dequeue(head);
    printLL(head); cout << '\n';
    cout << q.sizeOfQueue(head) << '\n';
    head = q.Dequeue(head);
    printLL(head); cout << '\n';
    cout << q.sizeOfQueue(head) << '\n';
    head = q.Dequeue(head);
    printLL(head); cout << '\n';
    cout << q.sizeOfQueue(head) << '\n';
    head = q.Dequeue(head);
    printLL(head); cout << '\n';
    cout << q.sizeOfQueue(head) << '\n';
    head = q.Dequeue(head);
    printLL(head); cout << '\n';
    cout << q.sizeOfQueue(head) << '\n';
    head = q.Dequeue(head);
    printLL(head); cout << '\n';
    cout << q.sizeOfQueue(head) << '\n';
    head = q.Dequeue(head);
    printLL(head); cout << '\n';
    cout << q.sizeOfQueue(head) << '\n';
    printLL(head);
    printLL(head); cout << '\n';

    return 0;
    //------___^___
}//---------/|   |\...../
// DONE //  <|___|>
