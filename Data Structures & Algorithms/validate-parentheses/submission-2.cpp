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
            else if(!st.empty())
            {
                if(brackets[st.top()] == ch)
                    st.pop();
                else
                    return false;
            }
            else
                return false;
        }

        if(!st.empty())
            return false;

        return true;
    }
};
