
Merge Intervals
Total Accepted: 12154 Total Submissions: 59167

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18]. 

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
    static bool myfunc(Interval a, Interval b) {return a.start < b.start;}
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ret;
        if (0 == intervals.size())
            return ret;
        sort(intervals.begin(), intervals.end(), Solution::myfunc);    
        Interval tmp = intervals[0];
        for (int i = 1; i<intervals.size(); i++) {
            if (intervals[i].start > tmp.end) {
                ret.push_back(tmp);
                tmp = intervals[i];
            } else {
                if (intervals[i].end > tmp.end)
                    tmp.end = intervals[i].end;
            }
        }
        ret.push_back(tmp);
        return ret;
    }
};
