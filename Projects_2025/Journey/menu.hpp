#ifndef MENU_HPP
#define MENU_HPP

namespace LJW {
	struct MenuItem {
		const char* const title;
		const MenuItem* (*func)(const MenuItem* current); //函数指针变量声明，定义符合签名的函数，创建菜单项时绑定函数
		//声明了一个没有参数没有返回值的函数，传递了函数指针
		
		const MenuItem* const *child;
		const int child_count;

		const MenuItem* parent;
	};
}

#endif