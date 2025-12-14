#ifndef MENU_FUNCTIONS_HPP
#define MENU_FUNCTIONS_HPP

#include "menu.hpp"

namespace LJW {
	const MenuItem* show_menu(const MenuItem* current);

	const MenuItem* exit(const MenuItem* current);

	const MenuItem* depart_far_east(const MenuItem* current);
	const MenuItem* depart_altai(const MenuItem* current);
	const MenuItem* depart_goldenRing(const MenuItem* current);
	const MenuItem* depart_go_back(const MenuItem* current);

	const MenuItem* far_east_vladivostok(const MenuItem* current);
	const MenuItem* far_east_sakhalin(const MenuItem* current);
	const MenuItem* far_east_khabarovsk(const MenuItem* current);
	const MenuItem* far_east_come_back(const MenuItem* current);
}

#endif