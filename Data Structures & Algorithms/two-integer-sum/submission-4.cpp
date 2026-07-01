class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> elems;

        for(int i = 0; i < nums.size(); ++i)
        {
            int current = target - nums[i];

            if(elems.contains(current))
                return {elems[current], i};

            elems[nums[i]] = i;
        }
        return {};
    }
};
