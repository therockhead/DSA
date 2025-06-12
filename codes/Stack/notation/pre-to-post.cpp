#include <iostream>
#include <stack>
#include <string>
#include <bits/stdc++.h>

using namespace std;

string PreToPost(string s) {
    int n = s.size();
    int i = n -1; // start reversely
    stack<string>st;
    while(i >= 0) {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            string new_str;
            new_str += s[i]; // making string as s[i] is a char
            st.push(new_str);
        }
        else  {
            string top1 = st.top(); st.pop();
            string top2 = st.top(); st.pop();
            // when we find an operator, "top1 + top2 + operator" then push the new string
            string custom_string = top1 + top2 + s[i];
            //this string making takes time O(n1 + n2)
            // n1 = size of top2 string
            // n2 = size of top1 string
            st.push(custom_string);
        }
        i--;
    }

    return st.top();
}
int main() {
    string prefix = "/-AB*+DEF";
    string post = PreToPost(prefix);
    cout << post << '\n';
    
    // Total Time complexity = O(2N);
    // Space complexity = O(N) [for stack usage]

    return 0;
}