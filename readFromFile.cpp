#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

// std::string file_to_string(const std::string & filename) {
// 	std::ifstream text(filename);
	
// 	std::stringstream strStream;
// 	if (text.is_open()) {
// 		strStream << text.rdbuf();
// 	}

// 	return strStream.str();
// }

std::vector<std::int> file_to_vector(const std::string & filename) {
	std::ifstream text(filename);
	std::vector<std::int> out;

	if (text.is_open()) {
		std::istream_iterator<std::string> iter(text);
		while (!text.eof()) {
			int a, b;
			file >> a >> b;
			
			out.push_back(*iter);
			++iter;
		}
	}

	return out;
} 
