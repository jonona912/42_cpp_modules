#include <iostream>
#include <fstream>

std::string replaceOldWithNew(std::string text, std::string oldStr, std::string newStr) {
	std::string result;
	size_t start = 0;
    size_t pos;
	while ((pos = text.find(oldStr, start)) != std::string::npos) {
		std::cout << "pos: " << pos << "start: " << start << std::endl;
		result += text.substr(start, pos - start);
		result += newStr;
		start = pos + oldStr.length();
	}
    result += text.substr(start);
	return result;
}

int	copyFileContent(std::string filename, std::string &destination) {
	std::ifstream ifs(filename.c_str());
	if (!ifs.is_open()) {
		std::cout << "Invalid file" << std::endl;
		return 0;
	}
	std::string line;
	while (std::getline(ifs, line)) {
		destination += (line + "\n");
	}
	if (!destination.empty()) {
		destination.erase(destination.size() - 1);
	}
	ifs.close();
	return 1;
}

int writeToFile(const std::string &filename, const std::string &content) {
	std::ofstream ofs(filename.c_str());
	if (!ofs.is_open()) {
		std::cout << "Error creating output file" << std::endl;
		return 0;
	}
	ofs << content;
	ofs.close();
	std::cout << "Replacement completed. Check " << filename << std::endl;
	return 1;
}

int main(int argc, char *argv[]) {
	if (argc != 4) {
		std::cout << "Invalid input. Usage: filename oldtext newtext" << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::string oldStr = argv[2];
	std::string newStr = argv[3];
	if (oldStr.empty()) {
		std::cout << "Error: oldtext cannot be empty" << std::endl;
		return 1;
	}
	std::string fileContent;
	if (!copyFileContent(filename, fileContent))
		return 2;
	std::string result = replaceOldWithNew(fileContent, oldStr, newStr);
	std::string outFilename = filename + ".replace";
	if (!writeToFile(outFilename, result))
		return 3;
	return 0;
}
