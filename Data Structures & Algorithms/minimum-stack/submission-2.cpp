class MinStack {
private: 
    stack<int> storage;
    stack<pair<int, int>> min_storage;

public:
    MinStack() {
    }
    
    void push(int val) {
        storage.push(val);

        if(!min_storage.empty())
        {
            if(min_storage.top().first == val)
                min_storage.top().second++;
            else if(min_storage.top().first > val)
                min_storage.push({val, 1});
        }
        else
            min_storage.push({val, 1});
    }
    
    void pop() {
        if(min_storage.top().first == storage.top())
        {
            min_storage.top().second--;

            if(min_storage.top().second == 0)
                min_storage.pop();
        }

        storage.pop();
    }
    
    int top() {
        return storage.top();
    }
    
    int getMin() {
        return min_storage.top().first;
    }
};
