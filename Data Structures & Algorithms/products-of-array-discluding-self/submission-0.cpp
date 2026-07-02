class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix = vector<int>(nums.size());
        vector<int> sufix = vector<int>(nums.size());
        vector<int> result = vector<int>(nums.size());

        prefix[0] = nums[0];
        sufix[nums.size() - 1] = nums[nums.size() - 1];
        for(int i = 1; i < nums.size(); ++i)
        {
            prefix[i] = prefix[i - 1] * nums[i];
        }

        for(int i = nums.size() - 2; i >= 0; --i)
        {
            sufix[i] = sufix[i + 1] * nums[i];
        }

        result[0] = sufix[1];
        result[nums.size() - 1] = prefix[nums.size() - 2];
        for(int i = 1; i < nums.size() - 1; i++)
        {
            result[i] = prefix[i - 1] * sufix[i + 1];
        }

        return result;
    }
};
