#include <iostream>
#include "SortExamples.h"
/// <summary>
/// ������ ����
/// 1. ���� ���� (Bubble Sort) 
/// 2. ���� ���� (Selection Sort)
/// 3. ���� ���� (Insertion Sort)
/// 4. ���� ���� (Merge Sort)
/// 5. �� ����   (Quick Sort)
/// </summary>

// 1. Bubble Sort
// - ���� �ɶ��� ����� ��ǰ�� ������ ���� �ö���� ��ó�� �������� Bubble Sort��� �̸��� ��������.
// - �����ϱ� ���ؼ� �׽�Ʈ�� ���ĵ� �ڷ���� �ٷ�� ���α׷��� �׽�Ʈ�Ҷ� ��� ������ �ʿ��� ��� ��� ��� �ǻ���� �� ���Ѵ�.
// - �� ���� ���ؼ� ū ���ڸ� ���������� �̵� O(n^2)�� �ð� ���⵵�� ������.
//

// 2. Selection Sort
// ���� ���� ���ڸ� �����ؼ� �ùٸ� ��ġ�� ����
// ���� ���� ���ڸ� ���ʴ�� Ž��
// ���� ���� �ڸ����� ����
// 

// 3. Insertion Sort
// �ڱ� ��ġ�� ã�Ƽ� �����ϱ� ������ ��������
// �迭�� ������ �����ϸ鼭 ��ü ������ ����(���� �������� �̾߱��ϴ� ��)
// 
int main(void) {
	
	int arr[10];
	srand(time(nullptr));

	for (int i = 0; i < 10; i++) 
		arr[i] = rand() % 1000;
	SortExamples::BubbleSort(arr, sizeof(arr)/ sizeof(arr[0]));
	
	for (int i = 0; i < 10; i++) 
		arr[i] = rand() % 1000;
	SortExamples::SelectionSort(arr, sizeof(arr) / sizeof(arr[0]));

	for (int i = 0; i < 10; i++)
		arr[i] = rand() % 1000;
	SortExamples::InsertionSort(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < 10; i++) std::cout << arr[i] << " ";
	
	return 0;
}