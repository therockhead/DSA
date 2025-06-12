#include <iostream>
#include <stack>
#include <string>
#include <bits/stdc++.h>

using namespace std;

string PreToInfix(string s) {
    int n = s.size();
    int i = n-1;
    stack<string>st;
    while(i >= 0 ) {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            string new_str;
            new_str += s[i];
            st.push(new_str);
        }
        else  {
            string top1 = st.top(); st.pop();
            string top2 = st.top(); st.pop();
            string custom_string = '(' + top1 + s[i] + top2 + ')';
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
    string pre = "*+PQ-MN"; // ans would be as ((A-B)/((D+E)*F))
    string infix = PreToInfix(pre);
    cout << infix << '\n';
    
    // Total Time complexity = O(N) + O(N)
    // Space complexity = O(N) [for stack usage]

    return 0;
}