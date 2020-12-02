#include <fstream>
#include <iostream>
#include <string>
#include <regex>

int main() {
	std::smatch m;
	std::regex r("([0-9]+)-([0-9]+) ([a-z]): ([a-z]+)");

	std::ifstream f("input.txt");
	std::string line;

	int valid1 = 0;
	int valid2 = 0;

	while (std::getline(f, line)) {

		if (std::regex_match(line, m, r)) {

			int count = 0;
			std::string s(m[4]);

			for (auto c : s) {
				if (c == m[3]) {
					count++;
				}
			}

			int l = std::stoi(m[1]);
			int h = std::stoi(m[2]);

			if (count >= l && count <= h) {
				valid1++;
			}

			if ((s[l-1] == m[3]) != (s[h-1] == m[3])) {
				valid2++;
			}
			else {
				std::cout << line << '\n';
			}
		}
		else {
			std::cout << "error - unable to parse: " << line << '\n';
		}
	}

	std::cout << valid1 << '\n' << valid2 << '\n';

	return EXIT_SUCCESS;
}
