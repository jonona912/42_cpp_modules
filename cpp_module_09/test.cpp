#include <iostream>

void insertionSort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int temp = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > temp) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[++j] = temp;
	}
}

void printArr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	
}

int main(void) {
	int arr[] = {4, 3, 2, 15, 13, 1, 23, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	printArr(arr, n);
	insertionSort(arr, n);
	printArr(arr, n);

	return 0;
}


// 3 4 5 6 1
// temp = 1 (i = 4)
// j = 3