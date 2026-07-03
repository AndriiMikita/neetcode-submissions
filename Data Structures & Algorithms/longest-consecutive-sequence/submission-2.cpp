class Solution {
public:

    int find(int x, unordered_map<int, int>& parent) {
        if(parent[x] != x)
            parent[x] = find(parent[x], parent);
        return parent[x];
    }

    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;

        unordered_map<int, int> parent;
        unordered_map<int, int> result;

        int mx_res = 1;

        for(int& num : nums)
        {
            if(parent.contains(num))
                continue;

            parent[num] = num;
            result[num] = 1;

            if(parent.contains(num - 1))
            {
                int prev_parent = find(num - 1, parent);
                parent[prev_parent] = num;
                result[num] += result[prev_parent];
                mx_res = max(mx_res, result[num]);
            }

            if(parent.contains(num + 1))
            {
                int next_parent = find(num + 1, parent);
                parent[next_parent] = num;
                result[num] += result[next_parent];
                mx_res = max(mx_res, result[num]);
            }
        }

        return mx_res;
    }
};
