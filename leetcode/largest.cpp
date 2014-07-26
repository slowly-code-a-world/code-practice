
Largest Rectangle in Histogram
Total Accepted: 12175 Total Submissions: 58321

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10. 

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if (height.size()<1) return 0;
        if (1 == height.size()) return height[0];
        vector<int> record(height.size(), 0);
        int loop = height.size()-1;
        record[loop] = height[loop];
        int current_min = height[loop]; int ret = height[loop];
        loop --;
        while (loop >=0) {
            if (height[loop]<= current_min) {
                record[loop] = height[loop]*(height.size()-loop);
                if (record[loop] > ret)
                    ret = record[loop];
                current_min = height[loop];    
            } else {
                int max = height[loop]; int new_min = height[loop];
                for (int i = loop + 1; i < height.size(); i++) {
                    new_min = min(new_min, height[i]);
                    int tmp = new_min*(i - loop + 1);
                    if (tmp > max) max = tmp;
                }
                record[loop] = max;
                if (record[loop] > ret)
                    ret = record[loop];
            }
            loop--;
        }
        return ret;
    }
};
