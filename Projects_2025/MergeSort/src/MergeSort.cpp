#include "MergeSort.hpp"
#include <algorithm>
#include <iostream>

void miv::sortings::merge_sort(int* const arr, const int arr_length) {
    if (arr_length <= 1) return;

    int* temp = new int[arr_length];
    if (temp) {
        for (int step = 1; step < arr_length; step *= 2) { // Размер подмассива начинается с 1 и удваивается каждый раз
            // Проходим по всему массиву, обрабатывая каждый раз два соседних подмассива (всего 2*step элементов)
            for (int left = 0; left < arr_length; left += 2*step) {
                // Вычислить конечную позицию первого подмассива (начальную позицию второго подмассива)
                int mid = std::min(left + step, arr_length);
                // Вычислить позицию окончания текущего сливаемого сегмента (позицию окончания второго подмассива)
                int right = std::min(left + 2*step, arr_length);

                // Начинается слияние двух подмассивов: arr[left...mid-1] и arr[mid...right-1]
                int i = left;
                int j = mid;
                int k = left;

                while (i < mid && j < right) {
                    if (arr[i] <= arr[j]) {
                        temp[k++] = arr[i++];
                    } else {
                        temp[k++] = arr[j++];
                    }
                }

                // Если в первом подмассиве еще остались элементы
                while (i < mid) {
                    temp[k++] = arr[i++];
                }

                while (j < right) {
                    temp[k++] = arr[j++];
                }
				// Возможно произойдет один из двух вышеуказанных случаев

                // Скопировать текущий сегмент слияния (от left до right-1)
                for (int idx = left; idx < right; idx++) {
                    arr[idx] = temp[idx];
                }
            }
        }
        delete[] temp;
    } else {
        std::cout << "Ошибка выделения памяти!";
    }
}