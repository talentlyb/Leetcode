// First time. 2015/12/21

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        vector<int> hash(26, 0);
        int i = 0;
        for (i = 0; i < s.length(); ++i) {
            ++hash[s[i]-'a'];
            --hash[t[i]-'a'];
        }
        
        for (i = 0; i < 26; ++i) {
            if (hash[i]) {
                return false;
            }
        }
        
        return true;
    }
};
