class MinStack {
    stack<int> values;
    stack<int> minValues;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (values.empty()) {
            values.push(val);
            minValues.push(val);
        } else {
            values.push(val);
            minValues.push(min(minValues.top(), val));
        }
    }
    
    void pop() {
        if (values.empty()) return;
        values.pop();
        minValues.pop();
    }
    
    int top() {
        if (values.empty()) throw std::runtime_error("Underflow");
        return values.top();
    }
    
    int getMin() {
        if (minValues.empty()) throw std::runtime_error("Underflow");
        return minValues.top();
    }
};
