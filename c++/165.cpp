/** First time. 5/3/2015
 */

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int ver1, ver2;
        string temp1, temp2;
        int i = 0;
        int j = 0;
        
        while (true) {
            temp1.clear();
            temp2.clear();
            while (version1[i] != '.' && version1[i] != '\0') {
                temp1 += version1[i++];
            }
            if (version1[i] == '.') {
                ++i;
            }
            while (version2[j] != '.' && version2[j] != '\0') {
                temp2 += version2[j++];
            }
            if (version2[j] == '.') {
                ++j;
            }
            if (version1.empty()) {
                ver1 = 0;
            }
            else {
                ver1 = stoi(temp1, NULL, 10);
            }
            if (version2.empty()) {
                ver2 = 0;
            }
            else {
                ver2 = stoi(temp2, NULL, 10);
            }
            
            if (ver1 < ver2) {
                return -1;
            }
            else if (ver1 > ver2) {
                return 1;
            }
            else {  // ver1 == ver2
                if (version1[i] == '\0' && version2[j] == '\0') {
                    return 0;
                }
                else {
                    return compareVersion(version1.substr(i, version1.length()-i), version2.substr(j, version2.length()-j));
                }
            }
        }
    }
};