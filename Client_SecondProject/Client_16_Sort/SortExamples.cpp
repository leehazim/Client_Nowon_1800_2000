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

void SortExamples::MergySort(int* arr, int start, int end) {
	if (start < end)
	{
		int mid = (start + end) / 2;

		MergySort(arr, start, mid);
		MergySort(arr, mid + 1, end);
		Mergy(arr, start, end, mid);
	}
}

void SortExamples::QuickSort(int* arr, int start, int end) {
	if (start >= end) return;
	int pivot = Partition(arr, start, end);
	QuickSort(arr, start, pivot);
	QuickSort(arr, pivot + 1, end);	
}

void SortExamples::HeapSort(int arr[], int length) {
	// Heapify 
	Heapify_TopDown(arr, length);
	int end = length - 1;
	while (end > 0) {
		int tmp = arr[0];
		arr[0] = arr[end];
		arr[end] = tmp;
		end--;
		SIFT_Down(arr, end, 1);
	}
}

void SortExamples::Mergy(int* arr, int start, int end, int mid) {
	int* tmp = new int[end + 1];
	for (int i = start; i <= end; i++) {
		tmp[i] = arr[i];
	}
	int part1 = start;
	int part2 = mid + 1;
	int index = start;

	while (part1 <= mid &&
		   part2 <= end) {
		if (tmp[part1] <= tmp[part2]) {
			arr[index++] = tmp[part1++];
		}
		else {
			arr[index++] = tmp[part2++];
		}
	}

	for (int i = 0; i <= mid - part1; i++) {
		arr[index + i] = tmp[part1 + i];
	}

	for (int i = 0; i < end; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	delete tmp;
}

int SortExamples::Partition(int* arr, int start, int end) {
	int pivot = arr[(start + end) / 2];
	
	while (true) { 
		while (arr[start] < pivot) start++;
		while (arr[end] > pivot) end--;

		Swap(arr[start], arr[end]);
		if (start == end) 
			return end;
	}
	return 0;
}

void SortExamples::Swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void SortExamples::Heapify_TopDown(int* arr, int length) {
	//Top-Down ������� ����
	int end = 1;
	while (end < length) {
		SIFT_Up(arr, 0, end++);
	}
}

void SortExamples::SIFT_Up(int* arr, int root, int current) {
	int parent = current / 2;
	while (current > root) {
		if (arr[parent] < arr[current]) {
			int tmp = arr[parent];
			arr[parent] = arr[current];
			arr[current] = tmp;

			current = parent;
			parent = current / 2;
		}
		else {
			break;
		}
	}
}

void SortExamples::SIFT_Down(int* arr, int end, int current) {
	bool doSwap = false;
	int parent = 0;
	/*if (end < 2) {
		if (arr[0] < arr[1]) {
			int tmp = arr[0];
			arr[0] = arr[1];
			arr[1] = tmp;
			return;
		}
	}*/
	while (current <= end) {
		if ((current + 1) <= end &&
			arr[current] < arr[current + 1])
			current++;
		if (arr[parent] < arr[current])
			doSwap = true;

		if (doSwap) {
			int tmp = arr[parent];
			arr[parent] = arr[current];
			arr[current] = tmp;
			doSwap = false;
			parent = current;
			current = parent * 2 + 1;
		}
		else {
			break;
		}

	}
}
