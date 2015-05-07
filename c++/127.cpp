/** First time. 5/6/2015
 * 
 * BFS.
 * Avoid repeat word visits to prevent memory limit exceeded error.
 * Differentiate the situations where endWord is and is not in the dictionary.
 */

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        int n = beginWord.length();
        int len = 1;
        bool last = false;
        queue<string> q;
        unordered_set<string> visited;
        
        q.push(beginWord);
        q.push("|");    // delimiter
        while (!q.empty()) {
            string curr = q.front();
            q.pop();
			if (curr == endWord) {
                return len;
            }
            if (q.front() == "|") {
                q.pop();
				++len;
                last = true;
            }
            else {
                last = false;
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < 26; ++j) {
                    string temp = curr;
                    if (j != temp[i] - 'a') {
                        temp[i] = 'a' + j;
						if (temp == endWord && wordDict.find(temp) == wordDict.end()) {
							return len+1;
						}
                        if (wordDict.find(temp) != wordDict.end() && visited.find(temp) == visited.end()) {
                            q.push(temp);
							visited.insert(temp);
                        }
                    }
                }
            }
            if (last && !q.empty()) {
                q.push("|");
            }
        }
        return 0;
    }
};