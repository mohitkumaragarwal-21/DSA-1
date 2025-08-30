class MyQueue {
public:
    stack<int> s1,s2;
    int size=0;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
        size++;
    }
    
    int pop() {
        if(s2.size()==0){
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int temp=s2.top();
        s2.pop();
        size--;
        return temp;

    }
    
    int peek() {
         if(s2.size()==0){
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return !size;
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