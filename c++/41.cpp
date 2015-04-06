/** First time. 4/5/2015
 * 
 * If A[i] != A[A[i]-1], then swap the two.
 * For example, if 5 is not place at A[4], then swap A[4] and the element 5.
 */

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int i = 0;
        for (i = 0; i < n; ++i) {
            while (A[i] > 0 && A[i] <= n && A[i] != A[A[i]-1]) {
                int temp = A[A[i]-1];
                A[A[i]-1] = A[i];
                A[i] = temp;
            }
        }
        for (i = 0; i < n; ++i) {
            if (A[i] != i + 1) {
                return i+1;
            }
        }
        return n+1;
    }
};