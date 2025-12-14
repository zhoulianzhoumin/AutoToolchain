#include "io.hpp"
#include "MergeSort.hpp"

int main() {
	int arr[] = {1760, 1840, 1870, 1914, 1776, 1929, 1944, 1971, 2008};
	const int arr_length = sizeof(arr) / sizeof(arr[0]);
	
	miv::render_array("Массив до сортировки:", arr, arr_length);
    
    miv::sortings::merge_sort(arr, arr_length);

    miv::render_array("Массив после сортировки:", arr, arr_length);
	
	return 0;
}