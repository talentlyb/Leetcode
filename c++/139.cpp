/**
 * First Time. 4/3/2015
 * 
 * Dynamic Programming.
 * Create a vector of boolean values. For each position i, 
 * look up the dictionary for all its heading substrings.
 * If position j is true and a substring (j, i-1) exists 
 * in the dictionary, then mark position i as true.
 */

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (dict.size() == 0) {
            return false;
        }
        vector<bool> table (s.size()+1, false);
        table[0] = true;
        int i, j;
        for (i = 1; i <= s.size(); ++i) {
            for (j = i - 1; j >= 0; --j) {
                if (table[j]) {
                    string word = s.substr(j, i-j);
                    if (dict.find(word) != dict.end()) {
                        table[i] = true;
                        break;
                    }
                }
            }
        }
        return table[s.size()];
    }
};