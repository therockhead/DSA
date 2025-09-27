string isBalanced(string s) {
    stack<char> st;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == '(' || s[j] == '{' || s[j] == '[') {
        st.push(s[j]);
      }
      else if (s[j] == ')'){
        if (st.empty()) return "NO";
        if (st.top() == '(') {
          st.pop();
        }
        else return "NO";
      }
      else if (s[j] == '}'){
        if (st.empty()) return "NO";
        if (st.top() == '{') {
          st.pop();
        }
        else return "NO";
      }
      else if (s[j] == ']'){
        if (st.empty()) return "NO";
        if (st.top() == '[') {
          st.pop();
        }
        else return "NO";
      }
    }
    // cout << st.size() << '\n';
    if (st.size() == 0 && s.size() > 1) {
        return "YES";  
    } 
    else {
        return "NO";
    }
    return "NO";

}
