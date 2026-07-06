class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, bool> operations = {
            {"+", true},
            {"-", true},
            {"*", true},
            {"/", true}
        };

        stack<int> values;

        for(string& token : tokens)
        {
            if(operations.contains(token))
            {
                int second = values.top();
                values.pop();
                int first = values.top();
                values.pop();

                if(token == "*")
                    values.push(first * second);
                else if(token == "/")
                    values.push(first / second);
                else if(token == "-")
                    values.push(first - second);
                else if(token == "+")
                    values.push(first + second);
            }
            else
                values.push(stoi(token));
        }
        
        return values.top();
    }
};
