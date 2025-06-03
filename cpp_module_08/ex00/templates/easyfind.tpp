#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T& intCon, int toFind) {
	typename T::iterator it;
	it = std::find(intCon.begin(), intCon.end(), toFind);
	if (it != intCon.end()) {
		std::cout << "Found: " << *it << std::endl;
		return it;
	} else {
		throw std::runtime_error("Not found");
	}
}
