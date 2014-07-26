
Container With Most Water
Total Accepted: 12954 Total Submissions: 42293

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container. 

class Solution {
public:
    int maxArea(vector<int> &height) {
        if (height.size() <=1) return 0;
        int left = 0, right = height.size()-1;
        int max = INT_MIN;
        while (left < right) {
            int contain = (right - left)*min(height[left], height[right]);
            if (contain > max) max = contain;
            if (height[left] < height[right]) 
                left ++;
            else if (height[left] > height[right])
                right--;
            else {
                left++;
                right--;
            }    
        }
        return max;
    }
};
