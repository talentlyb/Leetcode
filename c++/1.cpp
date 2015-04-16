/** First time. 4/15/2015
 * 
 * Sort the array and start from both ends of the array.
 * Map is not useful because duplicate keys are not allowed.
 */

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        vector<int> copy = numbers;
        int index1, index2, i;
        sort(copy.begin(), copy.end());
        int l = 0;
        int r = copy.size()-1;
        while (true) {
            if (copy[l] + copy[r] > target) {
                --r;
            }
            else if (copy[l] + copy[r] < target) {
                ++l;
            }
            else {
                break;
            }
        }
        for (i = 0; i < numbers.size(); ++i) {
            if (numbers[i] == copy[l]) {
                index1 = i + 1;
                break;
            }
        }
		for (i = 0; i < numbers.size(); ++i) {
			if (numbers[i] == copy[r] && i != index1-1) {
                index2 = i + 1;
                break;
            }
		}
		if (index1 < index2) {
			result.push_back(index1);
			result.push_back(index2);
		}
		else {
			result.push_back(index2);
			result.push_back(index1);
		}
        return result;
    }
};