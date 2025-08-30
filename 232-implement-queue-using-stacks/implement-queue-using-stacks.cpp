class MyQueue {
public: 
queue<int>q;
    MyQueue() {
        
    }
    
    void push(int x) {
      q.push(x);
    }
    
    int pop() {
        int f = q.front();
        q.pop();
        return f;
    }
    
    int peek() {
        int f =  q.front();
        return f;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */