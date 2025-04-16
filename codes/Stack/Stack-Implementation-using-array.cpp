#include <bits/stdc++.h>
using namespace std;

class Stack {
    int size;
    int* arr;
    int top;
    public:
        Stack() {
            top = -1;
            size = 1000;
            arr = new int[size];
        }
    void push(int x) {
        top++;
        arr[top] = x;
    }
    int pop() {
        int x = arr[top];
        top--;
        return x;
    }
    int Top() {
        return arr[top];
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

};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Stack s;
    s.push(6);
    s.push(3);
    s.push(7);

    cout << "First Top: " << s.Top() << '\n';
    s.pop();
    cout <<"After first pop(), empty? " << s.is_empty(s) << '\n';

    cout << "2nd Top: " << s.Top() << '\n';
    s.pop();
    cout <<"After second pop(), empty? " << s.is_empty(s) << '\n';

    cout << "3rd Top: " << s.Top() << '\n';
    s.pop();
    cout <<"After third pop(), empty? " << s.is_empty(s) << '\n';

    return 0;
}

