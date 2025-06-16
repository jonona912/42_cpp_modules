
#include <stdio.h>
#include <stdlib.h>

long unsigned int jacobsthaalNum(long unsigned int idx) {
	if (idx == 0)
		return 0;
	if (idx == 1)
		return 1;
	long unsigned int result = 1; // J(1) = 1
	for (long unsigned int i = 1; i < idx; i++) {
		result = (1 << i) - result;
	}
	return result;
}

void	shiftArrayLeft(int *arr, int amount, int size) {
	for (int i = 0; i < size - amount; i++) {
		arr[i] = arr[i + amount];
	}
}

void shiftArrayRight(int *arr, int amount, int size) {
	if (amount > size) {
		printf("Amount greater than size\n");
	}
	while(size - amount > 0) {
		arr[size - 1] = arr[size - amount - 1];
		size--;
	}
}

void print_array(int *array, int size, int groupHalf, int new_line) {
	int iterations = size / groupHalf;
	printf("[ ");
	for (int i = 0; i < iterations * groupHalf; i++) {
		if (i > 0 && i % groupHalf == 0)
			printf("] [ ");
		printf("%d ", array[i]);
	}
	printf("] => ");
	int nonParticipating = size - iterations * groupHalf;
	for (int i = 0; i < nonParticipating; i++) {
		printf("%d ", array[iterations * groupHalf + i]);
	}
	if (new_line)
		printf("\n");
}

void swap_groups(int *posA, int *posB, int const size) {
	for (int i = 0; i < size; i++) {
		int temp = posA[i];
		posA[i] = posB[i];
		posB[i] = temp;
	}
}

void insertNumElements(int *dest, int *src, int amount) {
	for (int i = 0; i < amount; i++) {
		dest[i] = src[i];
	}
}

void compareAndInsert(int *pend, int pendSize, int groupHalf, int jNum, int jPrevNum, int *main, int mainSize, int size) {
	// find the starting position of pend: (jNum - jPrevNum - 1) * groupHalf; *should work for all pends
	int	pendIdx = jNum - jPrevNum - 1;
	int	pendStartPos;
	int	mainStartPos = (jNum - 1) * groupHalf;
	while (pendIdx >= 0) {
		pendStartPos = pendIdx * groupHalf;
		// left = 0; right = jNum;
		// binarySearchAndInsert(pend, main, left, right)
		while (mainStartPos >= 0) {
			if ((main[mainStartPos + groupHalf - 1] <= pend[(pendStartPos + groupHalf - 1)] )) {
				// insert grouHalf elements in mainStartPos from pendstartpos
				// pArray(pend + pendStartPos, groupHalf, "pend to insert");
				// printf("main + mainStartPos + 1: %d\n", *(main + mainStartPos));
				// printf("main + mainStartPos + 1: %d %d\n", *(main), mainStartPos);
				shiftArrayRight(main + mainStartPos, groupHalf, size - mainStartPos);  // I stopped here
				// pArray(main, 22, "Main: ");
				insertNumElements(main + mainStartPos + groupHalf, pend + pendStartPos, groupHalf);
				// pArray(main, 22, "Main: ");
				mainStartPos = 0;
			}
			else if (mainStartPos == 0) {
				shiftArrayRight(main, groupHalf, size - mainStartPos);  // I stopped here
				insertNumElements(main, pend + pendStartPos, groupHalf);
			}
			mainStartPos -= groupHalf;
		}
		pendIdx--;
		mainStartPos = (jNum - 1) * groupHalf;
		// shiftArrayLeft(pend + pendStartPos, groupHalf, )
	}
	// find the starting position of main: Pend cmparison always remains jacobsthal number

}

void insertPendArray(int *pend, int pendSize, int groupHalf, int *main, int mainSize, int size) {
	int	jNum;
	int	jPrevNum;
	int	jIdx = 3;
	int	toShift = 0;

	while (pendSize > 0) {
		jNum = jacobsthaalNum(jIdx);
		jPrevNum = jacobsthaalNum(jIdx - 1);
		int jacobDiff = jNum - jPrevNum;
		if (jacobDiff > pendSize / groupHalf) {
			jNum = jPrevNum + pendSize / groupHalf;
			// jacobDiff = pendSize / groupHalf;
		}
		if ((jNum - jPrevNum) * groupHalf <= pendSize) {
			// Limit the range of comparisons. jNum gives the rangeof comparisons to start from in main
			compareAndInsert(pend, pendSize, groupHalf, jNum, jPrevNum, main, mainSize, size); // don't forget to update mainSize
			// printArrayWithSubgroups(pend, pendSize, groupHalf, jNum, jPrevNum);
		}
		else if (jacobDiff > 0) {
			int bNum = jPrevNum + pendSize / groupHalf;
			// printArrayWithSubgroupsAfterJN(pend, pendSize, groupHalf, jacobDiff, bNum);
		}
		jIdx++;
		toShift += groupHalf * (jNum - jPrevNum);
		// printf("toShift: %d\n", toShift);
		shiftArrayLeft(pend, toShift, pendSize);
		// printf("After shifting: ");
		// print_array(pend, pendSize, groupHalf);
		pendSize -= groupHalf * (jNum - jPrevNum);
		toShift = 0;
	}
}

void insertMainPendNP(int *array,  int size, int groupHalf) {
	int *main = (int *)malloc(sizeof(int) * size);
	int *pend = (int *)malloc(sizeof(int) * size);
	int *non_participating = (int *)malloc(sizeof(int) * size);
	int main_size = 0;
	int pend_size = 0;
	int np_size;
	int numSubGroups = size / groupHalf;

	for (int j = 0; j < numSubGroups; j++) {
		if (j == 0) {
			insertNumElements(main, array, groupHalf);
			main_size+= groupHalf;
		}
		else if (j % 2 == 1) {
			insertNumElements(main + main_size, array + (j * groupHalf), groupHalf);
			main_size += groupHalf;
		}
		else {
			insertNumElements(pend + pend_size, array + (j * groupHalf), groupHalf);
			pend_size += groupHalf;
		}
	}
	np_size = size - (main_size + pend_size);
	if (numSubGroups * groupHalf < size) {
		insertNumElements(non_participating, array + main_size + pend_size, np_size);
	}
	// printf("Pend array: ");
	// print_array(pend, pend_size, groupHalf, 0);
	// printf("     |      ");
	// print_array(non_participating, np_size, groupHalf, 0);
	// printf(": non_participating\n");
	// printf("Main array: ");
	// print_array(main, size, groupHalf, 1);
	insertPendArray(pend, pend_size, groupHalf, main, main_size, size);
	insertNumElements(main + main_size + pend_size, non_participating, np_size);
	// printf("Main array: ");
	// print_array(main, size, groupHalf, 1);
	insertNumElements(array, main, size);
	// printf("Arra array: ");
	// print_array(array, size, groupHalf, 1);
	// printf("\n");
}

void	ford_johnson_sort(int *array, int const size, int group_size) {
	int groupHalf = group_size / 2;
	if (group_size > size)
		return ;
	int	num_of_comparisons = size / group_size;
	int i = 0;
	for (int n = 0; n < num_of_comparisons; n++) {
		
		if (array[i + group_size / 2 - 1] > array[i + group_size - 1]) // 
			swap_groups(array + i, array + i + group_size / 2, group_size / 2);
		i += group_size;
	}
	ford_johnson_sort(array, size, group_size * 2);
	// print_array(array, size, groupHalf, 1);
	insertMainPendNP(array, size, groupHalf);
}






int main() {
	int array[] = {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
	// int array[] = {};
	int size = sizeof(array) / sizeof(array[0]);

	printf("Unsorted arr: ");
	print_array(array, size, size, 1);
	ford_johnson_sort(array, size, 2);

	printf("Sorted array: ");
	print_array(array, size, size, 1);

	return 0;
}


// 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7