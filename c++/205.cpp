/** First time. 5/3/2015
 * 
 * Hash table.
 */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map <char, char> hash1, hash2;
        for (int i = 0; i < s.length(); ++i) {
            if (hash1.find(s[i]) != hash1.end()) {
                if (hash1[s[i]] != t[i]) {
                    return false;
                }
            }
            else {
                hash1[s[i]] = t[i];
            }
            if (hash2.find(t[i]) != hash2.end()) {
                if (hash2[t[i]] != s[i]) {
                    return false;
                }
            }
            else {
                hash2[t[i]] = s[i];
            }
        }
        return true;
    }
};