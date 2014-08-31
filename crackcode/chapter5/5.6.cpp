/*
5.6 Write a program to swap odd and even bits in an integer with as few instructions
   as possible (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, and
  soon).
*/

#include <iostream>

class Solution {
public:
	int swap(int target) {
		int orig = target;
		int left = orig << 1;
		int right = orig >> 1;
		
		for (int i = 0; i < 32; i = i + 2) {
			orig = orig & (~(1 << i));
			if ((right & (1 << i)) > 0) 
				orig = orig | (1 << i);
		}

		for (int i = 1; i < 32; i = i + 2) {
			orig = orig & (~(1 << i));
			if ((left & (1 << i)) > 0)
				orig = orig | (1 << i);
		}

		return orig;
	}

	int swap_v2 (int target) {
		return (((target & 0xaaaaaaaa) >> 1) | ((target & 0x55555555) << 1));
	}
};
