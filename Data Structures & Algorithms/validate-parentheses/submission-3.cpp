class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> brackets = {
            {'(' ,')'},
            {'{' ,'}'},
            {'[' ,']'}
        };

        stack<char> st;
        for(char& ch : s)
        {
            if(brackets.contains(ch))
                st.push(ch);
            else if(st.empty() || brackets[st.top()] != ch)
                return false;
            else
                st.pop();
        }

        if(!st.empty())
            return false;

        return true;
    }
};
