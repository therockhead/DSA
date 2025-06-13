#include <bits/stdc++.h>
using namespace std;
bool isValid(string s) {
        stack<char>paren;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            paren.push(s[i]);
            } else {
                if (paren.empty()) return false;
                char ch = paren.top();
                paren.pop();
                if ((s[i] == ')' && ch == '(') || (s[i] == ']' && ch == '[') || (s[i] == '}' && ch == '{')) {
                continue;
                } else return false;
            }
        }
        if (paren.empty()) return true;
        return false;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    if(isValid(s)) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

