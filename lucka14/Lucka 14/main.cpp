//
//  main.cpp
//  Lucka 14
//
//  Created by danielsavstrom on 2018-12-14.
//  Copyright © 2018 kaislavirta. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, const char * argv[]) {

	std::vector<int> recipies1{ 3, 7 };
	size_t elf1pos = 0;
	size_t elf2pos = 1;
	
	const size_t puzzle1Input = 556061;
	
	while (recipies1.size() < (puzzle1Input + 10)) {
		assert(elf1pos < recipies1.size());
		assert(elf2pos < recipies1.size());
		
		char newRecipe = recipies1[elf1pos] + recipies1[elf2pos];
		if(newRecipe > 9) {
			recipies1.push_back(1);
			recipies1.push_back(newRecipe - 10);
		}
		else {
			recipies1.push_back(newRecipe);
		}
		
		elf1pos += (recipies1[elf1pos] + 1);
		elf1pos %= recipies1.size();
		elf2pos += (recipies1[elf2pos] + 1);
		elf2pos %= recipies1.size();
	}

	std::cout << "Score:";
	for(auto recipe = recipies1.begin() + puzzle1Input; recipe < recipies1.begin() + puzzle1Input + 10; ++recipe) {
		std::cout << " " << *recipe;
	}
	std::cout << std::endl;
	
	std::vector<int> recipies2{ 3, 7 };
	elf1pos = 0;
	elf2pos = 1;
	const auto puzzle2Input = { 5, 5, 6, 0, 6, 1 };
	// const auto puzzle2Input = { 5, 9, 4, 1, 4 };

	auto pos = recipies2.begin();
	while (recipies2.end() == (pos = std::search(
		recipies2.end() - std::min(static_cast<size_t>(10), recipies2.size()),
		recipies2.end(),
		puzzle2Input.begin(),
		puzzle2Input.end())))
	{
		assert(elf1pos < recipies2.size());
		assert(elf2pos < recipies2.size());
		
		char newRecipe = recipies2[elf1pos] + recipies2[elf2pos];
		if(newRecipe > 9) {
			recipies2.push_back(1);
			recipies2.push_back(newRecipe - 10);
		}
		else {
			recipies2.push_back(newRecipe);
		}
		
		elf1pos += (recipies2[elf1pos] + 1);
		elf1pos %= recipies2.size();
		elf2pos += (recipies2[elf2pos] + 1);
		elf2pos %= recipies2.size();
	}

	std::cout << "Count: " << pos - recipies2.begin() << std::endl;
	return 0;
}
