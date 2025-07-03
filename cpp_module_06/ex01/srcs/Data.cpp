#include "Data.hpp"

Data::Data() : _testStr("default") {}

Data::Data(std::string const &testStr) : _testStr(testStr) {}

Data::~Data() {}

Data::Data(const Data &other) {
	*this = other;
}

Data &Data::operator=(const Data &other) {
	if (this != &other) {
		_testStr = other._testStr;
	}
	return *this;
}

std::string Data::getTestStr() const {
	return _testStr;
}

std::ostream &operator<<(std::ostream &os, const Data &data) {
	os << "Data: " << data.getTestStr();
	return os;
}
