class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> cnt;

        for(int& num : nums)
        {
            cnt[num]++;
        }

        set<vector<int>> res;
        for(int i = 0; i < nums.size() - 2; ++i)
        {
            cnt[nums[i]]--;
            unordered_map<int, int> mp = cnt;
            for(int j = i + 1; j < nums.size() - 1; ++j)
            {
                mp[nums[j]]--;

                if(mp[-nums[i] - nums[j]])
                {
                    vector<int> triplet = {nums[i], nums[j], -nums[i] - nums[j]};
                    sort(triplet.begin(), triplet.end());
                    res.insert(triplet);
                }
            }
        }

        return vector<vector<int>>(res.begin(), res.end());
    }
};
