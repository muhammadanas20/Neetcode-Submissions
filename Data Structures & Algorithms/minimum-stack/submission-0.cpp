class MinStack {
    private:
    std::stack <int> stack;
    std::stack <int> min;
public:
    
    MinStack() {
        
    }
    
    void push(int val) {
        stack.push(val);
        val = std::min(val,min.empty() ? val : min.top());
        min.push(val);
    }
    
    void pop() {
        stack.pop();
        min.pop();
    }
    
    int top() {
        return stack.top();
        
    }
    
    int getMin() {
        return min.top();
    }
};
