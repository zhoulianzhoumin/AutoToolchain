#include "io.hpp"
#include <iostream>

void miv::render_array(const char* const descript, int* arr, const int arr_length) {
    const char space = ' ';
	std::wcout << descript;
	for (int i = 0; i < arr_length; ++i) {
		std::cout << space << arr[i];
	}
	std::cout << std::endl;
}