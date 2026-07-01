class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> elems = vector<pair<int, int>>(nums.size());

        for (int i = 0; i < nums.size(); ++i)
        {
            elems[i].first = nums[i];
            elems[i].second = i;
        }

        sort(elems.begin(), elems.end());

        int l = 0, r = nums.size() - 1;

        while (r > l)
        {
            int current = elems[l].first + elems[r].first;

            if (current == target)
                return {min(elems[l].second, elems[r].second), max(elems[l].second, elems[r].second)};
            else if (current > target)
                r--;
            else
                l++;
        }

        return {};
    }
};
