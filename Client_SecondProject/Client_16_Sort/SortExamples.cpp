#include "SortExamples.h"

void SortExamples::BubbleSort(int* arr, int length) {
	std::cout << "���� �� : ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << std::endl;

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				
				std::cout << "���� �� : ";
				for (int i = 0; i < length; i++) {
					std::cout << arr[i] << ", ";
				}
				std::cout << std::endl;
			}
		}
		std::cout << i<< "��° �ݺ���" << std::endl;
	}
}

void SortExamples::SelectionSort(int* arr, int length) {
	int minIdx;
	std::cout << "���� �� : ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << std::endl;

	for (int i = 0; i < length; i++) {
		minIdx = i;
		for (int j = i + 1; j < length; j++) {
			if (arr[minIdx] > arr[j]) minIdx = j;
		}
		if (minIdx == i) continue;
		std::cout << "���� �� : " << arr[minIdx]<< "  :   ";
		int tmp = arr[i];
		arr[i] = arr[minIdx];
		arr[minIdx] = tmp;

		for (int i = 0; i < length; i++) {
			std::cout << arr[i] << ", ";
		}
		std::cout << std::endl;
	}
}

void SortExamples::InsertionSort(int* arr, int length) {
	std::cout << "������ : ";
	for (int i = 0; i < length; i++)std::cout << arr[i] << ", ";
	std::cout << std::endl;
	int key;
	for (int i = 1; i < length; i++) {
		key = arr[i];
		int j = i - 1;
		while (j >= 0 && key < arr[j]) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		std::cout << "���ĵ� : ";
		for (int i = 0; i < length; i++)std::cout << arr[i] << ", ";
		std::cout << std::endl;
	}
}
