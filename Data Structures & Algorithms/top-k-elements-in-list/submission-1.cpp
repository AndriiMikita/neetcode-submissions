class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        for (int& num : nums)
            mp[num]++;

        priority_queue<pair<int, int>> q;

        for(auto& [n, fr] : mp)
            q.push({fr, n});

        vector<int> res;
        while(k--)
        {
            res.push_back(q.top().second);
            q.pop();
        }

        return res;
    }
};
