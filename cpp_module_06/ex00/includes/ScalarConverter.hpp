#pragma once

#include <string>

typedef enum {
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_CHAR,
	TYPE_INVALID
} str_type;

class ScalarConverter {
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

public:
	static void convert(std::string const &str);
};
