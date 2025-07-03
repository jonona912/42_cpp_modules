#include <vector>
#include <iostream>


#include <algorithm>
#include <iterator>

template<typename Iterator>
void swap_ranges(Iterator first1, Iterator last1, Iterator first2) {
    std::swap_ranges(first1, last1, first2);
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    std::vector<int> zec;
    std::cout << "vec size: " << vec.size() << " zec size: " << zec.size() << std::endl;
    zec.insert(zec.end(), vec.begin() + 3, vec.begin() + 5);
    std::cout << "vec size: " << vec.size() << " zec size: " << zec.size() << std::endl;
    // Swap range [0,2) with range starting at index 3
    // swap_ranges(vec.begin(), vec.begin() + 2, vec.begin() + 2);

    // Print result
    for (int x : vec) {
        std::cout << x << " "; // Output: 4 5 3 1 2 6
    }
    std::cout << std::endl;
    for (int x : zec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}
