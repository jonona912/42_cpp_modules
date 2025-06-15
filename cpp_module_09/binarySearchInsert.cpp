#include <iostream>
#include <vector>

// Binary search to find the insertion position
unsigned int binarySearch(const std::vector<int>& arr, int item, unsigned int low, unsigned int high) {
    while (low <= high) {
        unsigned int mid = low + (high - low) / 2;
        if (item == arr[mid])
            return mid + 1;
        else if (item > arr[mid])
            low = mid + 1;
        else if (mid > 0)
            high = mid - 1;
        else
            return 0; // Special case when mid is 0 and item is smaller
    }
    return low;
}
void binaryInsertionSort(std::vector<int>& arr) {
	for (int i = 1; i < arr.size(); ++i) {
		int key = arr[i];
		int j = i - 1;
		
		// Find position to insert using binary search
		int pos = binarySearch(arr, key, 0, j);
		
		// Shift all elements from pos to i-1 to the right
		while (j >= pos) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		
		// Optional: Print array after each insertion
		std::cout << "After inserting " << key << ": ";
		for (int num : arr) std::cout << num << " ";
		std::cout << "\n";
	}
}

int main() {
	std::vector<int> arr = {5, 2, 4, 6, 1, 3};
	
	std::cout << "Original array: ";
	for (int num : arr) std::cout << num << " ";
	std::cout << "\n\n";
	
	binaryInsertionSort(arr);
	
	std::cout << "\nSorted array: ";
	for (int num : arr) std::cout << num << " ";
	
	return 0;
}