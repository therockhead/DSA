#include <iostream>
#include <vector>

using namespace std;

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

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convertArr2LL(int arr[], int size) // array or vector input
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    // shobar first e mover is pointing towards head
    // then eta proti ta element change howar shathe shathe change hbe
    // loop cholar time e

    for (int i = 1; i < size; i++)
    {
        Node *temp = new Node(arr[i]); // prottek ta element er temp Node* create kortesi
        mover->next = temp;            // mover er next e protibar new temp or temp pointer rakha hoitese
        mover = temp;                  // and tarpor mover k temp diye replace
    } // linked list bananor kaj kortese..

    return head;
}
Node *inputLL(int n) // array or vector input
{
    if (n == 0) { // if there is no element in the list
        return nullptr;
    }

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
            Node *temp = new Node(val); // prottek ta element er temp Node* create kortesi
            mover->next = temp;            // mover er next e protibar new temp or temp pointer rakha hoitese
            mover = temp;                  // and tarpor mover k temp diye replace
        }
    }

    // shobar first e mover is pointing towards head
    // then eta proti ta element change howar shathe shathe change hbe
    // loop cholar time e
    return head;
}
void printLL(Node* head, int n)
{
    cout << head->data << " ";
    Node* mover = head->next;
    for(int i = 1; i < n; i++)
    {

        cout << mover->data << " ";
        mover = mover->next;
    }
}
void printLL_another_way(Node* head) // TRAVERSAL
{
     
    Node* temp  = head;

    while(temp!= NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Length of the Linked List
int lengthofLL(Node* head)
{
    int cnt = 0;
    Node* temp = head;

    while(temp)
    {
        temp = temp->next;
        cnt++;
    }

    return cnt;
}
bool checkIfPresent(Node* head, int value)
{

    Node* temp = head;

    while(temp)
    {
        if(temp->data == value){
            return true;
        }
        temp = temp->next;

    }
    return false;
}
Node* removeHead(Node* head)
{
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    free(temp);

    return head;
}
Node* removeTail(Node* head)
{
    if (head == NULL) return head;
    if (head->next == NULL) return NULL; // only one element in the list
    Node* temp = head;
    while (temp->next->next != NULL) // last er age porjonto jabe
    {
        temp = temp->next;
    }
    delete temp->next; // last er next k delete korlam jeta mainly tail
    temp->next = nullptr; // now making the second last one tail by assiging its next to null pointer :)
    
    return head;
}
Node* removeK(Node* head, int k) // for removing k-th element
{
    
    if (head == NULL) return head;
    if (k == 1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    // deleting k-th node means connecting (k-1)th node with (k+1)th node
    // so we need to save the previous nodes.
    // if (count == k), then we just change the prev->next to temp->next by  prev->next = prev->next->next; and delete the temp

    Node* temp = head;
    int count = 0; 
    Node* prev = NULL; // to track previous node
    while (temp != NULL){
        count++;
        if (count == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        
        prev = temp; // saving this to prev to use the previous node in every iteration
        temp = temp->next; // moving forward
    }

    return head;
}
Node* removeElement(Node* head, int element) // for removing k-th element
{
    
    if (head == NULL) return head;
    if (head->data == element){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    // deleting k-th node means connecting (k-1)th node with (k+1)th node
    // so we need to save the previous nodes.
    // if (count == k), then we just change the prev->next to temp->next by  prev->next = prev->next->next; and delete the temp

    Node* temp = head;
    Node* prev = NULL; // to track previous node
    while (temp != NULL){
        if (temp->data == element){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        
        prev = temp; // saving this to prev to use the previous node in every iteration
        temp = temp->next; // moving forward
    }

    return head;
}
Node* newHead(Node* head, int value) {
    Node* temp = new Node(value, head); // new node
    // here the next address of the temp Node* is the address of previous head
    return temp;
}
Node* insertK(Node* head, int element, int k) { //--k-th position
    if (head == NULL) {
        if (k == 1) return new Node(element);
        else return nullptr;
    }
    if (k == 1) {
        Node* temp = new Node(element, head);
        return temp;
    }
    int count = 0;
    Node* temp = head;
    while(temp!= NULL) {
        count++;
        if (count == k-1) {
            Node* newNodeElement = new Node(element);
            newNodeElement->next = temp->next;
            temp->next = newNodeElement;
            break;
        }
        temp = temp->next;
    }
    return head;
}
// USAGE: head = insertElementBeforeValue(head, 40, 3);
// 40 getting inserted before value 3
Node* insertElementBeforeValue (Node* head, int element, int value) {
    if (head == NULL) {
        return NULL;
    }
    if (head->data == value) {
        Node* temp = new Node(element, head);
        return temp;
    }
    bool found = false;
    Node* temp = head;
    while(temp->next != NULL) {
        if (temp->next->data == value) {
            Node* newNodeElement = new Node(element);
            newNodeElement->next = temp->next;
            temp->next = newNodeElement;
            found = true;
            break;
        }
        temp = temp->next;
    }
    if (found == false) {
        cout << value << "Not Found\n";
    } else {
        cout << "SUCCESS. Found and Inserted\n";
    }
    return head;
}
int main()
{
    int n;
    cin >> n;
    Node* head = inputLL(n); // input part
    printLL_another_way(head);

    return 0;
}

// or
/*

Node x = Node(arr[0], nullptr);
Node* y = &x;

cout << x << endl; // would give errors
// as x is an object we can only access the elements inside of it
// like x.data
// so we are taking a pointer y and storing its memory address
*/