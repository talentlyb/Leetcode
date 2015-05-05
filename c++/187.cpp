/** First time. 5/4/2015
 * 
 * Use hash table.
 * Hash table of strings consumes too much space, therefore we need to encode strings to integers first.
 * There should be no duplicates in the result.
 */

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> hash;
        vector<string> result;
        for (int i = 9; i < s.length(); ++i) {
            int sequence = 0;
            for (int j = i-9; j <= i; ++j) {
                int temp;
                switch (s[j]) {
                    case 'A' : temp = 1; break;
                    case 'C' : temp = 2; break;
                    case 'G' : temp = 3; break;
                    case 'T' : temp = 4; break;
                }
                sequence = sequence * 10 + temp;
            }
            if (hash.find(sequence) != hash.end()) {
                if (hash[sequence] == 1) {
                    result.push_back(s.substr(i-9,10));
                }
                hash[sequence]++;
            }
            else {
                hash[sequence] = 1;
            }
        }
        return result;
    }
};