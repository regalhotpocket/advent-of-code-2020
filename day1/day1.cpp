#include <fstream>
#include <iostream>
#include <string>
#include <set>

int main() {
	std::ifstream f("input.txt");
	std::string l;
	std::set<int> s;

	while(std::getline(f, l)) {
		int n = std::stoi(l);
		if (s.contains(2020-n)) {
			std::cout << n << ", " << 2020-n << ", " << n*(2020-n) << '\n';
		}
		s.insert(n);
	}

	for (auto i = s.begin(); i != s.end(); i++) {
		for (auto j = std::next(i); j != s.end(); j++) {
			if (s.contains(2020-((*i) + (*j)))) {
				std::cout << *i << ", " << *j << ", " << (2020-((*i)+(*j))) << ", " << (*i) * (*j) * (2020-((*i)+(*j))) << '\n'; 
				return EXIT_SUCCESS;
			}
		}
	}

	return EXIT_FAILURE;
}
