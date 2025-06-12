#include <bits/stdc++.h>
using namespace std;

// function to check the priority of an operator (+, -, *, /, ^)
int priority(char ch) {
    if (ch == '^') return 3;
    else if (ch == '*' || ch == '/') return 2;
    else if (ch == '+' || ch == '-') return 1;
    else return -1;
}
// conversion algorithm for infix to postfix notation conversion
string InfixToPostfix(string s) {
    int n = s.size();

   // variables needed
    stack<char>st; 
    string ans;

    int i = 0; // initialize
    while (i < n) {
        // if s[i] is an operand, simply concatenate with the answer string
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            ans = ans + s[i];
        }
        else if (s[i] == '(') {
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            // when we get a closing parentheses, 
            // we would pop every element from the stack 
            // until we find the opening bracket
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop(); // removing the opening parentheses as well after getting out of the loop
        }
        else {
            while (!st.empty() && priority(s[i]) <= priority(st.top())) {
                ans += st.top();
                st.pop();
                
            }
            st.push(s[i]);
        }
        i++;
    }
    // finally
    // adding rest of the operators in the ans string
    while (!st.empty()) {
        ans = ans + st.top();
        st.pop();
    }

    return ans;
}

int main() {
    string infix = "a+b*(c^d-e)";
    string postfix = InfixToPostfix(infix);
    
    cout << postfix << '\n';

    return 0;

}