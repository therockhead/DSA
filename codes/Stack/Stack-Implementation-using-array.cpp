#include <bits/stdc++.h>
using namespace std;

class Stack {
    // properties
    public:
        int size; 
        int* arr;
        int top;
    // constructor
    Stack() { // primary constructor
        top = -1;  // at the beginning
        size = 1000;
        arr = new int[size]; // creating array of the DEFAULT size
    }
    Stack(int size) { // if user gives the size then
        top = -1;
        this -> size = size;
        arr = new int[size]; // creating array of the given size
    }
    void push(int x) {
        top++;
        if (top > size-1) { // size-1 refers to the last element's index
            cout << "Sorry. No Space in the stack!";
        }
        else arr[top] = x;
    }
    void pop() {
        if (top == -1) {
            cout << "Empty Stack. You can't pop.";
        } // top >= 0 means not-empty stack
        else {
            top--;
        }
    }
    int Top() {
        if (top > 0 && top < size) {
            return arr[top];
        }
        else {
            cout << "Stack Empty\n";
            return -1;
        }
        
    }
    int Size() {
        return top+1;
    }
    bool is_empty(Stack s) {
        if (s.Size() == 0) {
            return true;
        }
        else return false;
    }
    bool is_empty() {
        if (top == -1) {
            return true;
        }
        else {
            return false;
        }
    }

};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Stack s(5);

    s.push(5);
    s.push(2);
    cout << s.Top();
    s.pop();
    s.pop();
    cout << s.Top();


    return 0;
}

