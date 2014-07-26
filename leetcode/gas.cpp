
Gas Station
Total Accepted: 15498 Total Submissions: 62473

There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique. 


class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int sum = 0, max = 0, retloc = -1, maxretloc = -1, first = 1;
        
        if (0 == gas.size()) return -1;    
        for (int i = 0; i < gas.size(); i++) {
            if (gas[i] - cost[i] >= 0) {
                sum += gas[i] - cost[i]; 
                if (1 == first) {
                    maxretloc = retloc = i;
                    first = 0;
                }    
            } else {
                if (sum > max) {
                    max = sum;
                    maxretloc = retloc;
                }
                sum = 0;
                first = 1;
            }
        }
        if (-1 == maxretloc) return -1;
        sum = 0;
        for (int i = 0; i < gas.size(); i++) {
            sum += gas[(i + maxretloc) % gas.size()] - cost[(i + maxretloc) % gas.size()];
            if (sum < 0)
                return -1;
        }
        return maxretloc;
    }
};
