class MinStack {
public:

    stack<int>st;
    
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
       
    }
    
    void pop() {
        
        st.pop();

        
    }
    
    int top() {
        return st.top();
        
    }
    void findMin(int& ele){
        if(st.empty()){
            return;
        }
        int temp = st.top();
        ele = min(ele,temp);
        st.pop();
        findMin(ele);
        st.push(temp);
        
    }
    int getMin() {
        
        int ele = INT_MAX;
        findMin(ele);

        return ele;
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