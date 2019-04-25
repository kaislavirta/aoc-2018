//
//  main.cpp
//  Lucka5
//
//  Created by danielsavstrom on 2018-12-05.
//  Copyright © 2018 kaislavirta. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

bool isMatch(char c1, char c2) {
	return std::isupper(c1) && c2 == std::tolower(c1);
}

std::string reactPolymer(const std::string& polymer) {
	std::string reacted(polymer);
	
	bool found = false;
	do {
		found = false;
		for(auto cur = reacted.begin(); cur < reacted.end() - 1;) {
			if(isMatch(*cur, *(cur + 1)) || isMatch(*(cur + 1), *cur)) {
				cur = reacted.erase(cur, cur + 2);
				found = true;
			}
			else {
				++cur;
			}
		}
	}
	while(found);
	
	return reacted;
}

int main(int argc, const char * argv[]) {
	if(argc < 2) {
		return EXIT_FAILURE;
	}
	
	std::ifstream file(argv[1]);
	std::string original;
	std::getline(file, original);
	
	const auto reacted = reactPolymer(original);
	std::cout << "Result1: " << reacted.c_str() << " Size: " << reacted.length() << std::endl;
	
	std::string smallest(original);
	for(char cur = 'a'; cur <= 'z'; ++cur) {
		std::string polymer(original);
		polymer.erase(std::remove_if(polymer.begin(), polymer.end(), [cur](char c){ return c == cur || c == std::toupper(cur); }), polymer.end());
		const auto reacted = reactPolymer(polymer);
		
		if(reacted.length() < smallest.size()) {
			smallest = reacted;
		}
	}
	std::cout << "Result2: " << smallest.c_str() << " Size: " << smallest.length() << std::endl;

	return EXIT_SUCCESS;
}
