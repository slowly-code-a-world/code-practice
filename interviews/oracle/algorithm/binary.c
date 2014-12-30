#include <stdlib.h>
#include <stdio.h>

int binary_search(int array[], int left, int right, int target) {
	if (left > right) return;
	if (left == right) { 
		if (array[left] == target) return left;
		return -1;
	}
	int middle = (left + right)/2;
	if (array[middle] == target) return middle;
	if (array[middle] > target) 
		return binary_search(array, left, middle - 1);
	return binary_search(array, middle + 1, right);
}
