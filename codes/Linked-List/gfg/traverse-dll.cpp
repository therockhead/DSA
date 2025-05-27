#include<bits/stdc++.h>
using namespace std;
class Node {
    int data;
    Node* prev;
    Node* next;
    
    Node(int d) {
        data = d;
        prev = nullptr;
        next = nullptr;
    }
};

// forward traversal
// Time Complexity: O(n), Space Complexity O(1)
void forwardTraversal(Node* head) {
	Node* curr = head; // initialize at head
	while(curr != NULL) {
		cout << curr->data << " "; // access the data at current node
		curr = curr->next; // move to the next node
	}
	cout << endl;
}

// forward traversal
// recursion approach
// Time Complexity: O(N), Space Complexity O(N)
void forwardTraveralRecursive(Node* head) {
	if (head == nullptr) return;
	cout << head->data << " ";
	forwardTraversalRecursive(head->next);
}

// backward traversal
void backwardTraversal(Node* tail) {
	Node* curr = tail;

	while(curr != nullptr) {
		cout << curr->data << " ";
		curr = curr->prev;
	}
}
int main () {
    

}
