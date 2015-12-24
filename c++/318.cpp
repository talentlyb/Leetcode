// First time. 2015/12/24
// This solution shows a very elegant use of bit manipulation.

class Solution {
public:
    int maxProduct(vector<string>& words) {
        if (words.empty()) {
            return 0;
        }
        
        vector<int> keys(words.size(), 0);
        int i;
        int j;
        int ret = 0;
        
        for (i = 0; i < words.size(); ++i) {
            for (j = 0; j < words[i].size(); ++j) {
                keys[i] |= 1 << (words[i][j] - 'a');
            }
        }
        
        for (i = 0; i < words.size()-1; ++i) {
            for (j = i + 1; j < words.size(); ++j) {
                if ((keys[i] & keys[j]) == 0 && words[i].size() * words[j].size() > ret) {
                    ret = words[i].size() * words[j].size();
                }
            }
        }
        
        return ret;
    }
};
