// two stack implementation using one array
#include <bits/stdc++.h>
#define ll long long
using namespace std;
class TwoStack {
    int *arr;
    int top1;
    int top2;
    int size; //  to understand when overflows
    public:
        // Initialize Two Stack
        TwoStack(int size) {
            this->size = size;
            top1 = -1; // forward stack
            top2 = size; // backward stack
            arr = new int[size];
        }
        // Push in stack 1
        void push1(int num) {
            // at least one empty space present needed, So
            if (top2 - top1 > 1) {
                top1++;
                arr[top1] = num;
            }
            else {
                cout << "Stack Overflown.\n";
            }
        }
        // Push in stack 2
        void push2(int num) {
            if (top2 - top1 > 1) {
                top2--;
                arr[top2] = num;
            }
            else {
                cout << "Stack Overflown.\n";
            }
        }
        // Pop from stack 1 and return popped element
        int pop1() {
            if (top1 >= 0) {
                int popValue = arr[top1];
                top1--; // by popping it's getting decremented
                return popValue;
            }
            else {
                // cout << "Empty Stack\n";
                return -1;
            }
        }
        // Pop from stack 2 and return popped element
        int pop2() {
            if (top2 < size) {
                int popValue = arr[top2];
                top2++; // by popping it is going getting incremented
                return popValue;
            }
            else {
                // cout << "Empty Stack\n";
                return -1;
            }
        }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    return 0;
}