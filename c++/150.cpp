/** First time. 4/25/2015
 * 
 * Stack.
 */

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i].size() > 1 || tokens[i][0] >= '0' && tokens[i][0] <= '9') {
                numbers.push(stoi(tokens[i]));
            }
            else {
                int a = numbers.top();
                numbers.pop();
                int b = numbers.top();
                numbers.pop();
                if (tokens[i] == "+") {
                    numbers.push(b+a);
                }
                else if (tokens[i] == "-") {
                    numbers.push(b-a);
                }
                else if (tokens[i] == "*") {
                    numbers.push(b*a);
                }
                else {  // tokens[i] == "/"
                    numbers.push(b/a);
                }
            }
        }
        return numbers.top();
    }
};