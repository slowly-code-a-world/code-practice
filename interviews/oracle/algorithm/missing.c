#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int real_find(int array[], int start, int end) {
	assert(start <= end);
	int middle = (start + end)/2;
	if (middle == start) {
		if (array[start] == start + 1) 
			return end + 1;
		return start + 1;
	}	
	if (array[middle] == middle + 1)
		return real_find(array, middle + 1, end);
	if (array[middle-1] == middle)
		return middle + 1;
	return real_find(array, start, middle-1);
}
int find_missing(int array[], int size) {
	return real_find(array, 0, size-1);
}

int main(int argc, char*argv[]) {
	int array[] = {1, 3, 4, 5};
	printf("%d\n", find_missing(array, 4));
}
