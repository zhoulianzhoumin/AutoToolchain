#include <iostream>

#include "menu.hpp"
#include "menu_functions.hpp"
#include "menu_items.hpp"

/*
Главное меню:
	1 - Путешествовать по России
		1 - Дальний Восток
			1 - Владивосток
			2 - Сахалин
			3 - Хабаровск
			0 - Выйти в предыдущее меню
		2 - Алтай
		3 - Золотое Кольцо России
		0 - Выйти в главное меню
	0 - Закончить путешествия
*/

using namespace LJW;

int main() {
	const MenuItem* current = &MAIN;
	do {
		
		current = current->func(current);
		std::cout << std::endl;
	} while(true);
	return 0;
}