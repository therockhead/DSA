#include <bits/stdc++.h>
using namespace std;

template<typename T>

class Stack {
public:
  int top;
  T* arr;
  int size;

  Stack() {
    top = -1;
    size = 1000;
    arr = new T[size];
  }

  Stack(int size) {
    top = -1;
    this->size = size;
    arr = new T[this->size];
  }

  void Push(T val) {
    top++;
    if (top < size-1) {
       arr[top] = val;
    }
    else {
      cout << "Stack Overflow. Can't push values\n";
    }
  }
  void Pop() {
    if (top == -1) {
      cout << "Stack underflow...\n";
    }
    else{
      top--;
    } 
  }
  T Top() {
    if (top >= 0 && top < size) {
      return arr[top];
    }
    else {
      cout << "Stack empty..\n";
      return -1;
    }
  }
  int Size() {
    return top + 1;
  }
  bool isEmpty() {
    if(top == -1) return true;
  }
};

int main() {

  Stack<char> st;
  st.Push('A');
  st.Push('B');

  cout << st.Top();

  return 0;

}