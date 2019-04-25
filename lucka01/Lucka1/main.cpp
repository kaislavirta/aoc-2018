//
//  main.cpp
//  Lucka1
//
//  Created by danielsavstrom on 2018-12-03.
//  Copyright © 2018 kaislavirta. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <functional>

int main(int argc, const char * argv[]) {
	if(argc < 2) {
		return EXIT_FAILURE;
	}
	
	std::ifstream file(argv[1]);
	std::string line;
	std::vector<int> values;
	while(std::getline(file, line)) {
		int value = std::atoi(line.c_str());
		values.push_back(value);
	}
	
	int sum = std::accumulate(values.begin(), values.end(), 0);
	
	int curFreq = 0;
	std::vector<int> freqs;
	int duplicate = 0;
	do {
		for(int value : values) {
			curFreq += value;
			auto found = std::find(freqs.begin(), freqs.end(), curFreq);
			if(found != freqs.end()) {
				duplicate = curFreq;
				break;
			}
			freqs.push_back(curFreq);
		}
	}
	while(curFreq != duplicate);

	std::cout << "Freq: " << sum << " , first duplicate: " << duplicate << std::endl;

	return EXIT_SUCCESS;
}
