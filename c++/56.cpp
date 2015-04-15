/** First time. 4/14/2015
 * 
 * Store start and end values in two separate vectors, and sort them.
 * Then process the two vectors in a way similar to "merging two sorted arrays".
 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<int> s;
        vector<int> e;
        int i, j;
        int size = intervals.size();
        vector<Interval> result;
        
        for (i = 0; i < size; ++i) {
            s.push_back(intervals[i].start);
            e.push_back(intervals[i].end);
        }
        sort(s.begin(), s.end());
        sort(e.begin(), e.end());
        
        i = 0;
        j = 0;
        int l = 0;
        int st, ed;
        while (i < s.size()) {
            if (s[i] <= e[j]) {
                if (l == 0) {
                    st = s[i];
                }
                ++l;
                ++i;
            }
            else {
                --l;
                if (l == 0) {
                    ed = e[j];
                    Interval temp (st, ed);
                    result.push_back(temp);
                }
                ++j;
            }
        }
        if (j < e.size()) {
            ed = e.back();
            Interval temp (st, ed);
            result.push_back(temp);
        }
        
        return result;
    }
};