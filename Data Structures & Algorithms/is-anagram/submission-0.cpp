class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;

        vector<int> alphabet = vector<int>(26);

        for(int i = 0; i < s.length(); ++i)
        {
            alphabet[s[i] - 'a'] += 1;
            alphabet[t[i] - 'a'] -= 1;
        }
        
        return all_of(alphabet.begin(), alphabet.end(), [](int x) {
            return x == 0;
        });
    }
};
