#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>


std::string file_to_string(const std::string & filename) {
	std::ifstream text(filename);
	
	std::stringstream strStream;
	if (text.is_open()) {
		strStream << text.rdbuf();
	}

	return strStream.str();
}

std::vector<int> file_to_vector(const std::string & filename) {
	std::ifstream text(filename);
	std::vector<int> out;

	if (text.is_open()) {
		std::istream_iterator<std::string> iter(text);
		while (!text.eof()) {
			//Convert string to int
			int item = stoi(*iter);
			out.push_back(item);
			++iter;
		}
	}

	return out;
} 