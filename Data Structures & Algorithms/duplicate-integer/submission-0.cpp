class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, bool> is;
        for (int &i : nums) {
            if(is.contains(i))
                return 1;
            is[i] = 1;
        }
        return 0;
    }
};