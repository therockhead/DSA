#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
  queue<int> q;

  bool push(int val) {
    q.push(val);
    return true;
  }
  int top() {
    return q.front()
  }
  bool pop() {
    q.pop()
  }

};

int main() {

}