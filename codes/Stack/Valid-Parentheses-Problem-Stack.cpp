#include <bits/stdc++.h>
using namespace std;
class Stack {
    int size;
    char* arr;
    int top;
    public:
        Stack() {
            top = -1;
            size = 1000;
            arr = new char[size];
        }
    void push(int x) {
        top++;
        arr[top] = x;
    }
    char pop() {
        char x = arr[top];
        top--;
        return x;
    }
    char Top() {
        return arr[top];
    }
    char Size() {
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

    string s;
    Stack paren;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            paren.push(s[i]);
        }
        else {
            char ch = paren.Top();
            if (s[i] == ')' && ch == '(') {
                paren.pop();
            }
            if (s[i] == ']' && ch == '[') {
                paren.pop();
            }
            if (s[i] == '}' && ch == '{') {
                paren.pop();
            }

        }
    }
    cout << paren.is_empty(paren);
    return 0;
}

