class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> elements;

        for(int i = 0; i < strs.size(); ++i)
        {
            vector<int> key = vector<int>(26);
            for(char &ch : strs[i])
            {
                key[ch - 'a'] += 1;
            }
            elements[key].push_back(strs[i]);
        }

        vector<vector<string>> result = vector<vector<string>>();
        for(auto &[_, strings] : elements)
        {
            result.push_back(strings);
        }

        return result;
    }
};
