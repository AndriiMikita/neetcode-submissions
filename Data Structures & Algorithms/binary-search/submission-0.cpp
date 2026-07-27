class Solution {
public:
    int search(vector<int>& nums, int target) {
        return *lower_bound(nums.begin(), nums.end(), target) == target ? (lower_bound(nums.begin(), nums.end(), target) - nums.begin()) : -1;
    }
};
