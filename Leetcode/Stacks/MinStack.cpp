class MinStack {
public:
    stack<int> st;
    stack<int> min_st;
    MinStack() {

    }
    
    void push(int val) {
      if (this->min_st.empty() || (val <= this->min_st.top())) {
        this->min_st.push(val);
      }
      st.push(val);
    }
    
    void pop() {
      if (st.top() == min_st.top()) {
        min_st.pop();
      }
      st.pop();
    }
    
    int top() {
      return this->st.top();
    }
    
    int getMin() {
      return this->min_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */