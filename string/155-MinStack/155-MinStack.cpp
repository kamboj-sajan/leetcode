// Last updated: 19/08/2026, 16:06:39
// class MinStack {
// public:
// stack<int> st1;
// stack<int> st2;
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         st1.push(val);
//         if(st2.empty() || val <= st2.top()){
//             st2.push(val);
//         }
//     }
//     void pop() {
//        if(st1.top() == st2.top()){
//             st2.pop();
//         }
//         st1.pop();
//     }
    
//     int top() {
//         return st1.top();
//     }
    
//     int getMin() {
//         return st2.top();
//     }
// };

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 class MinStack {
public:
stack<long long> st;
long long mini = LLONG_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        long long v = val;
     if(st.empty()){
        st.push(v);
        mini = v;
     }
     else{
        if(v > mini)st.push(val);
        else{
            st.push(2*v - mini);
            mini = v;
        }
     }
    }
    void pop() {
       if(st.empty())return;
       long long x = st.top();
       st.pop();
       if(x<mini)mini = 2*mini - x;
    }
    
    int top() {
       if(st.empty())return -1;
       long x = st.top();
       if(mini < x)return x;
       return (int)mini;
    }
    
    int getMin() {
       return (int)mini;
    }
};
