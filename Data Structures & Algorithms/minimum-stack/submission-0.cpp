class MinStack {
private: 
    stack<pair<int, int>> storage;

public:
    MinStack() {
    }
    
    void push(int val) {
        int last_min = !storage.empty() ? storage.top().second : val;
        storage.push({val, min(last_min, val)});
    }
    
    void pop() {
        storage.pop();
    }
    
    int top() {
        return storage.top().first;
    }
    
    int getMin() {
        return storage.top().second;
    }
};
