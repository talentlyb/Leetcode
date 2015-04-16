/** First time. 4/15/2015
 * 
 * Hash table. Use unordered_map
 */

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> mp;
        vector<int> result;
        int num;
        for (int i = 0; i < numbers.size(); ++i) {
            num = target - numbers[i];
            if (mp.find(num) != mp.end()) {
                result.push_back(mp[num] + 1);
                result.push_back(i + 1);
                break;
            }
            else {
                mp[numbers[i]] = i;
            }
        }
        return result;
    }
};