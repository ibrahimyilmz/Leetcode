class MinStack {
    stack<int> st;
public:
    MinStack() {
    }
    
    void push(int val) {
        int min = st.empty() ? val : std::min(val, getMin());
        st.push(min);
        st.push(val);
    }
    
    void pop() {
        st.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        if (st.empty()) {
            return 0;
        }
        int val = st.top();
        st.pop();
        int min = st.top();
        st.push(val);
        return min;
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