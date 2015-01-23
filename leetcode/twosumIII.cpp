/*
Two Sum III - Data structure design
Total Accepted: 311 Total Submissions: 1345

Design and implement a TwoSum class. It should support the following operations:add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

For example,

add(1); add(3); add(5);
find(4) -> true
find(7) -> false
*/
class Solution {
private:
        unordered_map<int, int> record;
public:
        void add(int val) {
                record[val] += 1;
        }

        bool find(int sum) {
                if (record.size() <= 1) return false;
		for (auto it = record.begin(); it!=record.end(); it++) {
                        if (record[sum - it->first]) {
                                if (sum - it->first != it->first) return true;
                                if (it->second > 1) return true;
                        }
                }
		return false;
        }
};
