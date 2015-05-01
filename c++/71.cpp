/** First time. 4/30/2015
 *
 * Stack
 * Watch for corner cases.
 */

class Solution {
public:
    string simplifyPath(string path) {
        string result;
        stack<string> st;
        string temp;
        for (int i = 0; i < path.length(); ++i) {
            if (path[i] == '/') {
                continue;
            }
            temp.clear();
            while (path[i] != '/' && i < path.length()) {
                temp += path[i];
                ++i;
            }
            if (temp == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            }
            else if (temp != ".") {
                st.push(temp);
            }
        }
        if (st.empty()) {
            return "/";
        }
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }
        return result;
    }
};