// Last updated: 19/08/2026, 16:04:32
class MyStack {
public:
queue<int> q;
    MyStack() {
    }
    
    void push(int x) {
        int s = q.size();
        q.push(x);
        for(int i=0; i<s; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int v = q.front();
         q.pop();
         return v;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
       return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */