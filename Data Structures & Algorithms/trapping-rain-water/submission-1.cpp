class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 1)
            return 0;

        int l = 0, r = height.size() - 1;
        int lmx = height[l], rmx = height[r], res = 0;

        while(l < r)
        {
            if(lmx < rmx)
            {
                l++;
                lmx = max(lmx, height[l]);
                res += max(0, lmx - height[l]);
            }
            else
            {
                r--;
                rmx = max(rmx, height[r]);
                res += max(0, rmx - height[r]);
            }
        }

        return res;
    }
};
