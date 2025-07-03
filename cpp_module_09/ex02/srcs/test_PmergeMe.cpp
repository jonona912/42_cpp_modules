// filepath: /home/zkhojazo/Documents/rank_04_prjs/cpp_modules_circle_4/cpp_modules_circle_4/cpp_module_09/ex02_2/srcs/test_PmergeMe.cpp
#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <cassert>

void testBinaryInsertJacobtaalNums() {
	PmergeMe pmm;
	
	// Test case 1: Basic vector test with simple sorted array
	{
		std::vector<int> main = {1, 3, 5, 7, 9, 11, 13};
		long unsigned int groupHalf = 1;
		long unsigned int pendValue = 6; // We want to find where 6 belongs
		long unsigned int mainStartIdx = 6; // Check the entire array
		
		long unsigned int result = pmm.binaryInsertJacobtaalNums(main, groupHalf, pendValue, mainStartIdx);
		std::cout << "Test 1 - Expected position for value 6: 3, Actual: " << result << std::endl;
		assert(result == 3);
	}
	
	// Test case 2: Value at the beginning
	{
		std::vector<int> main = {5, 10, 15, 20, 25};
		long unsigned int groupHalf = 1;
		long unsigned int pendValue = 2; // Should go at the beginning
		long unsigned int mainStartIdx = 4;
		
		long unsigned int result = pmm.binaryInsertJacobtaalNums(main, groupHalf, pendValue, mainStartIdx);
		std::cout << "Test 2 - Expected position for value 2: 0, Actual: " << result << std::endl;
		assert(result == 0);
	}
	
	// Test case 3: Value at the end
	{
		std::vector<int> main = {5, 10, 15, 20, 25};
		long unsigned int groupHalf = 1;
		long unsigned int pendValue = 30; // Should go at the end
		long unsigned int mainStartIdx = 4;
		
		long unsigned int result = pmm.binaryInsertJacobtaalNums(main, groupHalf, pendValue, mainStartIdx);
		std::cout << "Test 3 - Expected position for value 30: 5, Actual: " << result << std::endl;
		assert(result == 5);
	}
	
	// Test case 4: With groupHalf > 1
	{
		std::vector<int> main = {1, 2, 5, 6, 9, 10, 13, 14}; // Grouped as: [1,2], [5,6], [9,10], [13,14]
		long unsigned int groupHalf = 2;
		long unsigned int pendValue = 7; // Should go between [5,6] and [9,10]
		long unsigned int mainStartIdx = 3; // 4 groups, zero-indexed: 0,1,2,3
		
		long unsigned int result = pmm.binaryInsertJacobtaalNums(main, groupHalf, pendValue, mainStartIdx);
		std::cout << "Test 4 - Expected position for value 7 with groupHalf=2: 2, Actual: " << result << std::endl;
		assert(result == 2);
	}
	
	// Test case 5: Test with deque
	{
		std::deque<int> main = {3, 6, 9, 12, 15};
		long unsigned int groupHalf = 1;
		long unsigned int pendValue = 10;
		long unsigned int mainStartIdx = 4;
		
		long unsigned int result = pmm.binaryInsertJacobtaalNums(main, groupHalf, pendValue, mainStartIdx);
		std::cout << "Test 5 - Expected position for value 10 in deque: 3, Actual: " << result << std::endl;
		assert(result == 3);
	}

	// Test case 6: Exact match
	{
		std::vector<int> main = {5, 10, 15, 20, 25};
		long unsigned int groupHalf = 1;
		long unsigned int pendValue = 15; // Exact match in the array
		long unsigned int mainStartIdx = 4;
		
		long unsigned int result = pmm.binaryInsertJacobtaalNums(main, groupHalf, pendValue, mainStartIdx);
		std::cout << "Test 6 - Expected position for exact match value 15: 3, Actual: " << result << std::endl;
		assert(result == 3);
	}

	std::cout << "All binaryInsertJacobtaalNums tests passed successfully!" << std::endl;
}

int main() {
	testBinaryInsertJacobtaalNums();
	return 0;
}