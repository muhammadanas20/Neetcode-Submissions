class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    
    MyStack() {
        
    }
    
    void push(int x) {
        //stack : push to top of stack so 
        q2.push(x);  //push to last of q2
        while (!q1.empty()) {  //check is empty so until all e=elemnt from fronto push to last
            q2.push(q1.front());
            q1.pop(); //pop it after adding from the front
        }
        swap(q1, q2); //swap it to q1 so that q1 becomme origina q2 is now empty can use it again
    }
    
    int pop() {
        int top = q1.front(); //store top of q1
        q1.pop();   //remove it top
        return top; //return it
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
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