#include <iostream>
#include <vector>

using namespace std;

class Node 
{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1)
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

Node* convertArr2LL(int arr[], int size) // array or vector input
{
    Node* head = new Node(arr[0]);
    Node* mover = head;
    // shobar first e mover is pointing towards head
    // then eta proti ta element change howar shathe shathe change hbe
    // loop cholar time e
    
    
    for(int i = 1; i < size; i++){
        Node* temp = new Node(arr[i]); // prottek ta element er temp Node* create kortesi
        mover->next = temp; // mover er next e protibar new temp or temp pointer rakha hoitese
        mover = temp; // and tarpor mover k temp diye replace
    } // linked list bananor kaj kortese..
    return head;
}

int main()
{
    
    //vector<int> arr = {2, 5, 8, 9}; 
    int arr[] = {2, 1, 3, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    Node* head = convertArr2LL(arr, size); // head
   
    cout << head->data << endl;

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