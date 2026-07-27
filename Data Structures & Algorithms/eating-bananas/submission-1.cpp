class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end()) + 1;

        int res = INT_MAX;

        while(l < r)
        {
            int m = l + (r - l) / 2, cur = 0;

            for(int& pile : piles)
                cur += (pile + m - 1) / m;

            if(cur <= h)
            {
                res = min(m, res);
                r = m;
            }
            else
                l = m + 1;
        }

        return res;
    }
};
