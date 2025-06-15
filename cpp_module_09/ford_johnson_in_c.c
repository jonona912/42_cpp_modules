#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int jacobsthaalNum(int idx) {
	if (idx == 0)
		return 0;
	if (idx == 1)
		return 1;
	int result = 1; // J(1) = 1
	for (int i = 1; i < idx; i++) {
		result = (1 << i) - result;
	}
	return result;
}

// Binary search to find insertion point
int binary_search(int *array, int left, int right, int value) {
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (array[mid] == value) {
			return mid;
		} else if (array[mid] < value) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	return left;
}

// Insert an element into the array at a specific position
void insert(int *array, int *size, int pos, int value) {
	for (int i = *size; i > pos; i--) {
		array[i] = array[i - 1];
	}
	array[pos] = value;
	(*size)++;
}

// order pairs
// send to recursion (what do i mean) but increaase size()
// ford_johnson_sort(array, size, group_size) --> array is sequence after each recursion
// // if you can't make two sets, return
// // now put b1 a1 a2 a3... (in main)
// // now insert using jacobsthaal numbers from pend
// // comparing each max in b2, b3 ... insert them into the sequence

// Ford-Johnson algorithm (Merge-Insertion Sort) with Jacobsthal numbers

// void ford_johnson_sort(int *array, int size) {
//     if (size <= 1) return;

//     // Step 1: Pair elements and sort each pair
//     for (int i = 0; i < size - 1; i += 2) {
//         if (array[i] > array[i + 1]) {
//             int temp = array[i];
//             array[i] = array[i + 1];
//             array[i + 1] = temp;
//         }
//     }

//     // If odd number of elements, leave the last one unpaired
//     int has_stray = (size % 2 != 0);
//     int stray_value = has_stray ? array[size - 1] : INT_MIN;

//     // Step 2: Create main and pend arrays
//     int *main_chain = (int *)malloc(size * sizeof(int));
//     int *pend = (int *)malloc(size * sizeof(int));
//     int main_size = 0, pend_size = 0;

//     // Add the smaller elements of each pair to pend and larger to main
//     for (int i = 0; i < size - has_stray; i += 2) {
//         pend[pend_size++] = array[i];
//         main_chain[main_size++] = array[i + 1];
//     }

//     // Step 3: Recursively sort the main chain (larger elements)
//     ford_johnson_sort(main_chain, main_size);

//     // Step 4: Insert the first pend element (smallest of all pairs)
//     if (pend_size > 0) {
//         insert(main_chain, &main_size, 0, pend[0]);
//     }

//     // Step 5: Calculate Jacobsthal numbers for optimal insertion order
//     int max_jacobsthal_needed = pend_size;
//     int *jacobsthal = (int *)malloc(max_jacobsthal_needed * sizeof(int));
//     calculate_jacobsthal_numbers(jacobsthal, max_jacobsthal_needed);

//     // Insert pend elements in Jacobsthal order
//     int last_pos = 0;
//     for (int k = 0; ; k++) {
//         int j = jacobsthal[k] - 1; // Convert to 0-based index
//         if (j >= pend_size) break;

//         // Insert elements from j down to last_pos + 1
//         for (int i = j; i > last_pos; i--) {
//             // The element to insert is pend[i]
//             // The corresponding main chain element is at position i
//             // We need to find where to insert pend[i] in main_chain[0..i]
//             int pos = binary_search(main_chain, 0, i, pend[i]);
//             insert(main_chain, &main_size, pos, pend[i]);
//         }
//         last_pos = j;
//     }

//     // Step 6: Insert the stray element if it exists
//     if (has_stray) {
//         int pos = binary_search(main_chain, 0, main_size - 1, stray_value);
//         insert(main_chain, &main_size, pos, stray_value);
//     }

//     // Copy the sorted main chain back to the original array
//     for (int i = 0; i < size; i++) {
//         array[i] = main_chain[i];
//     }

//     free(main_chain);
//     free(pend);
//     free(jacobsthal);
// }
// Utility function to print an array

void print_array(int *array, int size, int groupHalf) {
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
	printf("\n");
}


void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap_groups(int *posA, int *posB, int const size) {
	for (int i = 0; i < size; i++) {
		int temp = posA[i];
		posA[i] = posB[i];
		posB[i] = temp;
	}
}

// move until position in amount of times

void move_and_insert(int *dest, int dest_size, int dest_pos, int n, int *src) { // dest size
	// Ensure that dest has enough space for dest_size + n elements before calling this function!
	// Move elements in dest to the right by n positions starting from dest_pos
	for (int i = dest_size - 1; i >= dest_pos; i--) {
		dest[i + n] = dest[i];
	}
	// Insert n elements from src into dest at dest_pos
	for (int i = 0; i < n; i++) {
		dest[dest_pos + i] = src[i];
	}
}

// void insert(int *desArr, int *srcArr, int destStartPos, int amount, int destSize) {
//     int temp;

//     for (int i = destSize; i > destStartPos; i--) {
//         temp = arr[i];

//     }
// }

void insertNumElements(int *dest, int *src, int amount) {
	for (int i = 0; i < amount; i++) {
		dest[i] = src[i];
	}
}

void printArrayWithSubgroups(int *arr, int size, int groupHalf, int jNum, int JPrevNum) {
	// int jDiff = jNum - JPrevNum;
	while (jNum - JPrevNum > 0) {
		// jDiff = 2, then 1
		// jDiff * groupHalf - 1 => last index of the subgroup
		// (jDiff - 1) * groupHalf => first index of the subgroup
		printf("b%d :", jNum);
		int subGroupPos = (jNum - JPrevNum - 1) * groupHalf;
		print_array(arr + subGroupPos, groupHalf, groupHalf);
		jNum--;
	}
}

void printArrayWithSubgroupsAfterJN(int *arr, int size, int groupHalf, int jDiff, int jNum) {
	// int jDiff = jNum - JPrevNum;
	while (jDiff > 0) {
		// jDiff = 2, then 1
		// jDiff * groupHalf - 1 => last index of the subgroup
		// (jDiff - 1) * groupHalf => first index of the subgroup
		printf("b%d :", jNum);
		int subGroupPos = (jDiff - 1) * groupHalf;
		print_array(arr + subGroupPos, groupHalf, groupHalf);
		jDiff--;
		jNum--;
	}
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


void	printPendWithAnnotations(int *arr, int size, int groupHalf) {
	int	jNum;
	int	jPrevNum;
	int	jIdx = 3;
	int	toShift = 0;
	// jacobDiff
	// if pend size is less than jaccobDiff, set jaccobDiff to the new difference
	jNum = jacobsthaalNum(jIdx);
	jPrevNum = jacobsthaalNum(jIdx - 1);
	int	jacobDiff = jNum - jPrevNum;
	// go over the first jacob number, and only than recalculat the jacobDiff
	// while there is a number in pend, con
	int	sizeCpy = size;
	while (size > 0) {
		jNum = jacobsthaalNum(jIdx);
		jPrevNum = jacobsthaalNum(jIdx - 1);
		int jacobDiff = jNum - jPrevNum;
		if (jacobDiff > size / groupHalf)
			jacobDiff = size / groupHalf;
		if ((jNum - jPrevNum) * groupHalf <= size) {
			printArrayWithSubgroups(arr, size, groupHalf, jNum, jPrevNum);
		}
		else if (jacobDiff > 0) {
			int bNum = jPrevNum + size / groupHalf;
			printArrayWithSubgroupsAfterJN(arr, size, groupHalf, jacobDiff, bNum);
		}
		jIdx++;
		toShift += groupHalf * (jNum - jPrevNum);
		printf("toShift: %d\n", toShift);
		shiftArrayLeft(arr, toShift, size);
		printf("After shifting: ");
		print_array(arr, size, groupHalf);
		size -= groupHalf * (jNum - jPrevNum);
		toShift = 0;
	}
	// printf("toShift: %d\n", toShift);
	// shiftArrayLeft(arr, toShift, size);

	// shift n ellements left from pos; shiftArrayLeft(arr, amount, arrSize);
}


void pArray(int *arr, int num, char *str) {
	printf("%s ", str);
	for (int i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void compareAndInsert(int *pend, int pendSize, int groupHalf, int jNum, int jPrevNum, int *main, int mainSize) {
	// find the starting position of pend: (jNum - jPrevNum - 1) * groupHalf; *should work for all pends
	int	pendIdx = jNum - jPrevNum - 1;
	int	pendStartPos;
	int	mainStartPos = (jNum - 1) * groupHalf;
	while (pendIdx >= 0) {
		pendStartPos = pendIdx * groupHalf;
		while (mainStartPos >= 0) {
			if (main[mainStartPos + groupHalf - 1] <= pend[(pendStartPos + groupHalf - 1)]) {
				// insert grouHalf elements in mainStartPos from pendstartpos
				pArray(pend + pendStartPos, groupHalf, "pend to insert");
				// printf("main + mainStartPos + 1: %d\n", *(main + mainStartPos));
				// printf("main + mainStartPos + 1: %d %d\n", *(main), mainStartPos);
				shiftArrayRight(main + mainStartPos, groupHalf, 22 - mainStartPos);  // I stopped here
				pArray(main, 22, "Main: ");
				insertNumElements(main + mainStartPos + groupHalf, pend + pendStartPos, groupHalf);
				pArray(main, 22, "Main: ");
				mainStartPos = 0;
			}
			mainStartPos -= groupHalf;
		}
		pendIdx--;
		mainStartPos = (jNum - 1) * groupHalf;
		// shiftArrayLeft(pend + pendStartPos, groupHalf, )
	}
	// find the starting position of main: Pend cmparison always remains jacobsthal number

}

void insertPendArray(int *pend, int pendSize, int groupHalf, int *main, int mainSize) {
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
			compareAndInsert(pend, pendSize, groupHalf, jNum, jPrevNum, main, mainSize); // don't forget to update mainSize
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



void	ford_johnson_sort(int *array, int const size, int group_size) {
	int	num_of_comparisons;
	int groupHalf = group_size / 2;
	if (group_size > size)
		return ;
	num_of_comparisons = size / group_size;
	// printf("group size: %d total size: %d\n", group_size, size);
	// printf("Before Swap: ");
	// print_array(array, size, group_size);
	int i = 0;
	for (int n = 0; n < num_of_comparisons; n++) { 
		if (array[i + group_size / 2 - 1] > array[i + group_size - 1]) // 
			swap_groups(array + i, array + i + group_size / 2, group_size / 2);
		i += group_size;
	}

	// printf("After Swap : ");
	// print_array(array, size, group_size);
	ford_johnson_sort(array, size, group_size * 2);
	printf("=======================================================================> Recursions done for group_size: %d\n", group_size);
	print_array(array, size, group_size);
	// assign b1, a1, a2, b2 etc. - to main
	int *main = (int *)malloc(sizeof(int) * size);
	int *pend = (int *)malloc(sizeof(int) * size);
	int *non_participating = (int *)malloc(sizeof(int) * size);
	int main_size = 0;
	int pend_size = 0;
	// int np = 0;
	// int ctr = 0;
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
	int currJN = jacobsthaalNum(3);
	int prevJN = jacobsthaalNum(2);
	// send the rest to subgroups
	if (numSubGroups * groupHalf < size) {
		insertNumElements(non_participating, array + (size - numSubGroups * groupHalf), (size - numSubGroups * groupHalf));
		printf("non-participating\n");
		print_array(non_participating, (size - numSubGroups * groupHalf), (size - numSubGroups * groupHalf));
	}
	printf("Pend array\n");
	int npSize = size - (main_size + pend_size);
	print_array(pend, pend_size, groupHalf);
	// printPendWithAnnotations(pend, pend_size, groupHalf);
	printf("main before: ");
	print_array(main, size, groupHalf);
	insertPendArray(pend, pend_size, groupHalf, main, main_size);
	printf("main after : ");
	print_array(main, size, groupHalf);
	insertNumElements(main + main_size + pend_size, non_participating, npSize);
	printf("main after2: ");
	print_array(main, size, groupHalf);
	printf("level: %d <=========================\n", group_size);
	// copy main to array now
	insertNumElements(array, main, size);
	// 
	// array is sequence to start from
	// free main, pend, non_participating
}


int main() {

	// Example usage of Ford-Johnson sort
	// Uncomment the following lines to test the sorting algorithm
	/*
	int array[] = {5, 2, 9, 1, 5, 6, 3, 8, 4, 7, 0};
	int size = sizeof(array) / sizeof(array[0]);

	printf("Original array: ");
	print_array(array, size);

	ford_johnson_sort(array, size);

	printf("Sorted array: ");
	print_array(array, size);
	*/

	// Example array for testing
	
	// int array[] = {5, 2, 9, 1, 5, 6, 3, 8, 4, 7, 0};
	// int array[] = {5, 2, 9, 1, 5, 8, 3, 6, 4, 7, 0}; // 11 (5 comparisons) 5 2, 9 1, 5 6
	int array[] = {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
	// int array[] = {11};
	int size = sizeof(array) / sizeof(array[0]);

	// printf("Original array: ");
	// print_array(array, size);
	printf("Unsorted arr: ");
	print_array(array, size, size);
	ford_johnson_sort(array, size, 2);

	printf("Sorted array: ");
	print_array(array, size, size);

	return 0;
}