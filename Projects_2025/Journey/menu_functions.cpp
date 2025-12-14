#include "menu.hpp"
#include "menu_functions.hpp"

#include <cstdlib>
#include <iostream>

namespace LJW {
	const MenuItem* show_menu(const MenuItem* current) {
		std::cout << "Добро пожаловать в туристическую систему" << std::endl;
		for (int i = 1; i < current->child_count; i++) {
			std::cout << current->child[i]->title << std::endl;
		}
		std::cout << current->child[0]->title << std::endl;
		std::cout << "направление";
	
		int user_input;
		std::cin >> user_input;
		std::cout << std::endl;
	
		return current->child[user_input];
	}
	
	const MenuItem* exit(const MenuItem* current) {
		std::exit(0);
	}

	const MenuItem* depart_far_east(const MenuItem* current) {
		return show_menu(current);
	}

	const MenuItem* depart_altai(const MenuItem* current) {
		std::cout << current->title << std::endl;
		return current->parent;
	}
	
	const MenuItem* depart_goldenRing(const MenuItem* current) {
		std::cout << current->title << std::endl;
		return current->parent;
	}
	
	const MenuItem* depart_go_back(const MenuItem* current) {
		std::cout << current->title << std::endl << std::endl;
		return current->parent->parent;
	}
	
	const MenuItem* far_east_vladivostok(const MenuItem* current) {
		std::cout << current->title << std::endl;
		return current->parent;
	}
	
	const MenuItem* far_east_sakhalin(const MenuItem* current) {
		std::cout << current->title << std::endl;
		return current->parent;
	}
	
	const MenuItem* far_east_khabarovsk(const MenuItem* current) {
		std::cout << current->title << std::endl;
		return current->parent;
	}
	
	const MenuItem* far_east_come_back(const MenuItem* current) {
		std::cout << current->title << std::endl;
		return current->parent->parent;
	}
}