#include <iostream>
#include <vector>

using namespace std;

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
Node* insertOneElement()
{

}

Node *inputLL(int n) // array or vector input
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

    while(temp)
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

int main()
{

    // vector<int> arr = {2, 5, 8, 9};
    
    
    // Node* head = convertArr2LL(arr, size); // head

    // cout << head->data << endl;
    
    int n;
    cin >> n; // n elements input

    Node* head = inputLL(n);

    // cout << head-> data << endl;

    printLL(head, n);
    cout << endl;
    printLL_another_way(head);
    cout << endl << "Length: ";
    int len = lengthofLL(head);
    cout << len << endl;

    int value; // the element I want to search
    cout << "Which Value You want to check? ";
    cin >> value;
    if(checkIfPresent(head, value))
    {
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }
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