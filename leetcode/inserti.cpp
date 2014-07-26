
Insert Interval
Total Accepted: 11658 Total Submissions: 57940

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10]. 

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
        vector<Interval> ret;
        if (0 == intervals.size())  {
            ret.push_back(newInterval);
            return ret;
        }    
        int b, e, i;
        if (newInterval.start < intervals[0].start) {
            b = -1;
            if (newInterval.end < intervals[0].start) {
                ret.push_back(newInterval);
                ret.insert(ret.end(), intervals.begin(), intervals.end());
                return ret;
            } else {
                int at = 0;
                e = -1;
                for (i = 0; i < intervals.size(); i++) {
                    if (newInterval.end >=intervals[i].start && newInterval.end <= intervals[i].end) {
                        at = 1;
                        e = i;
                        break;
                    } else if (newInterval.end < intervals[i].start) {
                        e = i;
                        break;
                    }
                }
                if (-1 == e) { 
                    ret.push_back(newInterval);
                    return ret;
                } else {
                    if (1 == at) {
                        ret.push_back(Interval(newInterval.start, intervals[e].end));
                        for (i = e+1; i < intervals.size(); i++)
                            ret.push_back(intervals[i]);                       
                    } else {
                        ret.push_back(newInterval);
                        for (i = e; i < intervals.size(); i++)
                            ret.push_back(intervals[i]);
                    }
                    return ret;    
                }
            }
        } else {
            if (newInterval.start > intervals[intervals.size()-1].end) {
                ret.insert(ret.begin(), intervals.begin(), intervals.end());
                ret.push_back(newInterval);
                return ret;
            }
            b = e = -1;
            int at = 0;
            for (i = 0; i<intervals.size(); i++) {
                if (newInterval.start >= intervals[i].start && newInterval.start <= intervals[i].end) {
                    at = 1;
                    b = i;
                    break;
                } else if (newInterval.start < intervals[i].start) {
                    b = i;
                    break;
                }
            }
            
            int ate = 0;
            for (int j = b; j<intervals.size(); j++) {
                if (newInterval.end >= intervals[j].start && newInterval.end <= intervals[j].end) {
                    ate = 1;
                    e = j;
                    break;
                } else if (newInterval.end < intervals[j].start) {
                    e = j;
                    break;
                }
            }
            
            for (int i = 0; i<b; i++) 
                    ret.push_back(intervals[i]);
            if (-1 == e) {
                if (1 == at)
                    ret.push_back(Interval(intervals[b].start, newInterval.end));
                else ret.push_back(newInterval);    
                return ret;
            } else {
                if (1 == at && 1 == ate) {
                    ret.push_back(Interval(intervals[b].start, intervals[e].end));
                    for (i = e+1; i<intervals.size(); i++)
                        ret.push_back(intervals[i]);
                    return ret;   
                } else if (1 == at && 0 == ate) {
                    ret.push_back(Interval(intervals[b].start, newInterval.end));
                    for (i = e; i<intervals.size(); i++)
                        ret.push_back(intervals[i]);
                    return ret;    
                } else if (0 == at && 1 == ate) {
                    ret.push_back(Interval(newInterval.start, intervals[e].end));
                    for (i = e+1; i<intervals.size(); i++)
                        ret.push_back(intervals[i]);
                    return ret;    
                } else {
                    ret.push_back(newInterval);
                    for (i = e; i<intervals.size(); i++)
                        ret.push_back(intervals[i]);
                    return ret;
                }
            }
        }
    }
};
