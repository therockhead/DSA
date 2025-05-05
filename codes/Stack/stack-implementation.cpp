#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    stack<int>st;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        st.push(value);
    }
    cout <<"Top of the stack: " << st.top() << endl;


    return 0;
}