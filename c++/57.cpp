/** First time. 4/19/2015
 * 
 * Watch for corner cases.
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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
        if (intervals.empty()) {
            result.push_back(newInterval);
            return result;
        }
        
        if (newInterval.end < intervals[0].start) {
            result.push_back(newInterval);
        }
        int newStart = newInterval.start;
        int newEnd = newInterval.end;
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i].end < newInterval.start || intervals[i].start > newInterval.end) {
                result.push_back(intervals[i]);
                if (intervals[i].end < newInterval.start && i != intervals.size()-1 && intervals[i+1].start > newInterval.end) {
                    result.push_back(newInterval);
                }
                continue;
            }
            else {
                newStart = min(newStart, intervals[i].start);
                newEnd = max(newEnd, intervals[i].end);
                if (i == intervals.size()-1 || intervals[i+1].start > newInterval.end) {
                    Interval temp (newStart, newEnd);
                    result.push_back(temp);
                }
            }
        }
        if (newInterval.start > intervals.back().end) {
            result.push_back(newInterval);
        }
        
        return result;
    }
};