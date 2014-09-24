/*
You are given an array of integers (both positive and negative). Find the contig-
uous sequence with the largest sum. Return the sum.
EXAMPLE
Input: 2, -8, 3, -2, 4, -10
Outputs (i.e., {3, -2, 4})
*/

int maxsum(vector<int> array) {
	if (0 == array.size()) return 0;
	if (1 == array.size()) return array[0];
	vector<int> record = array;
	int max = record[0];	
	for (int i = 1; i < record.size(); i++) {
		record[i] = (record[i-1] + array[i] > array[i])? record[i-1] + array[i] : array[i];
		if (record[i] > max) 
			max = record[i];
	}

	return max;	
}
