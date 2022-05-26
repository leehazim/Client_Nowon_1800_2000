#pragma once
#include <iostream>
class SortExamples {
public:
	static void BubbleSort(int* arr, int length);
	static void SelectionSort(int* arr, int length);
	static void InsertionSort(int* arr, int length);
	static void MergySort(int* arr, int start, int end); // MergeSort ÀÇ ºÐÇÒ
	
private:
	static void Mergy(int* arr, int start, int end, int mid);
};

