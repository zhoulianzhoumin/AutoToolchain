#include "menu_items.hpp"

#include <cstddef>

#include "menu_functions.hpp"

const LJW::MenuItem LJW::FAR_EAST_VLADIVOSTOK = {
	"1 - Владивосток", LJW::far_east_vladivostok, nullptr, 0, &LJW::DEPART_FAR_EAST
};

const LJW::MenuItem LJW::FAR_EAST_SAKHALIN = {
	"2 - Сахалин", LJW::far_east_sakhalin, nullptr, 0, &LJW::DEPART_FAR_EAST
};

const LJW::MenuItem LJW::FAR_EAST_KHABAROVSK = {
	"3 - Хабаровск", LJW::far_east_khabarovsk, nullptr, 0, &LJW::DEPART_FAR_EAST
};

const LJW::MenuItem LJW::FAR_EAST_COME_BACK = {
	"0 - Выйти в предыдущее меню", LJW::far_east_come_back, nullptr, 0, &LJW::DEPART_FAR_EAST
};

namespace {
	const LJW::MenuItem* const far_east_child[] = {
		&LJW::FAR_EAST_COME_BACK,
		&LJW::FAR_EAST_VLADIVOSTOK,
		&LJW::FAR_EAST_SAKHALIN,
		&LJW::FAR_EAST_KHABAROVSK
	};
	const int far_east_child_size = sizeof(far_east_child) / sizeof(far_east_child[0]);
}

const LJW::MenuItem LJW::DEPART_FAR_EAST = {
	"1 - Дальний Восток", LJW::depart_far_east, far_east_child, far_east_child_size, &LJW::DEPART
};

const LJW::MenuItem LJW::DEPART_ALTAI = {
	"2 - Алтай", LJW::depart_altai, nullptr, 0, &LJW::DEPART
};

const LJW::MenuItem LJW::DEPART_GOLDENRING = {
	"3 - Золотое Кольцо России", LJW::depart_goldenRing, nullptr, 0, &LJW::DEPART
};

const LJW::MenuItem LJW::DEPART_GO_BACK = {
	"0 - Выйти в главное меню", LJW::depart_go_back, nullptr, 0, &LJW::DEPART
};


namespace {
	const LJW::MenuItem* const depart_child[] = {
		&LJW::DEPART_GO_BACK,
		&LJW::DEPART_FAR_EAST,
		&LJW::DEPART_ALTAI,
		&LJW::DEPART_GOLDENRING,
	};
	const int depart_size = sizeof(depart_child) /sizeof(depart_child[0]);
}

const LJW::MenuItem LJW::DEPART = {
	"1 - Путешествовать по России", LJW::show_menu, depart_child, depart_size, &LJW::MAIN
};

const LJW::MenuItem LJW::EXIT = {
	"0 - Закончить путешествия", LJW::exit, nullptr, 0, &LJW::MAIN
};

namespace {
	const LJW::MenuItem* const main_child[] = {
		&LJW::EXIT,
		&LJW::DEPART
	};
	const int main_child_size = sizeof(main_child) / sizeof(main_child[0]);
}

const LJW::MenuItem LJW::MAIN = {
	"Главное меню:", LJW::show_menu, main_child, main_child_size, nullptr
};