#include <stdlib.h>
#include <stdio.h>

void print(int array[], int size) {
	for (int i = 0; i<size; i++) {
		if (array[i] % 2 == 0)
			printf("X");
		else if (array[i] % 5 == 0)
			printf("Y");
		else printf("%d", array[i]);
	}
}
