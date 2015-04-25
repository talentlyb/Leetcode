/** First time. 4/25/2015
 * 
 * Backtracking
 * Each section is within the range[0,255].
 * A number cannot start with a '0'.
 */

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string ipAddr;
        backtracking(s, result, 0, 0, ipAddr);
        return result;
    }
    
    void backtracking(string& s, vector<string>& result, int n, int index, string& ipAddr) {
        if (s.length()-index < (4-n) || s.length()-index > 3*(4-n)) {
			return;
		}
        if (n == 4) {
            result.push_back(ipAddr);
            return;
        }
        string section;
        for (int i = index; i < s.length()-3+n; ++i) {
            section += s[i];
            string temp = ipAddr;
            if (i-index+1 > 3 || stoi(section) > 255) {
                break;
            }
            else {
                if (n > 0) {
                    ipAddr += '.';
                }
                ipAddr += section;
            }
            backtracking(s, result, n+1, i+1, ipAddr);
            if (s[index] == '0') {  // if the section starts with a '0', do not continue
				break;
			}
            ipAddr = temp;
        }
        return;
    }
};