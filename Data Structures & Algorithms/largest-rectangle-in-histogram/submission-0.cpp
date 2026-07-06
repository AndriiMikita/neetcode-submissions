class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> l = vector<int>(heights.size()), r = vector<int>(heights.size());

        stack<pair<int, int>> st;
        for(int i = 0; i < heights.size(); ++i)
        {
            if(st.empty())
                st.push({heights[i], i});
            
            while(!st.empty() && st.top().first >= heights[i])
                st.pop();

            if(st.empty())
                l[i] = i + 1;
            else
                l[i] = i - st.top().second;

            st.push({heights[i], i});
        }

        stack<pair<int, int>>().swap(st);

        for(int i = heights.size() - 1; i >= 0; --i)
        {
            if(st.empty())
                st.push({heights[i], i});
            
            while(!st.empty() && st.top().first >= heights[i])
                st.pop();

            if(st.empty())
                r[i] = heights.size() - 1 - i;
            else
                r[i] = st.top().second - i - 1;

            st.push({heights[i], i});
        }

        int res = 0;
        for(int i = 0; i < heights.size(); ++i)
        {
            res = max(res, (l[i] + r[i]) * heights[i]);
        }

        return res;
    }
};
