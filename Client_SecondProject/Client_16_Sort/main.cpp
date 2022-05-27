#include <iostream>
#include "SortExamples.h"
/// <summary>
/// 정렬의 종류
/// 1. 버블 정렬 (Bubble Sort) 
/// 2. 선택 정렬 (Selection Sort)
/// 3. 삽입 정렬 (Insertion Sort)
/// 4. 병합 정렬 (Merge Sort)
/// 5. 퀵 정렬   (Quick Sort)
/// </summary>

// 1. Bubble Sort
// - 정렬 될때의 모습이 거품이 물위로 점점 올라오는 거처럼 움직여서 Bubble Sort라는 이름이 지어졌다.
// - 구현하기 편해서 테스트로 정렬된 자료들을 다루는 프로그램을 테스트할때 잠시 정렬이 필요한 경우 잠시 사용 실사용은 잘 안한다.
// - 두 값을 비교해서 큰 숫자를 오른쪽으로 이동 O(n^2)의 시간 복잡도를 가진다.
//

// 2. Selection Sort
// 가장 작은 숫자를 선택해서 올바른 위치에 정렬
// 가장 작은 숫자를 차례대로 탐색
// 가장 왼쪽 자리부터 스왑
// 

// 3. Insertion Sort
// 자기 위치를 찾아서 삽입하기 때문에 삽입정렬
// 배열의 정렬을 유지하면서 전체 정렬을 진행(정렬 안정성을 이야기하는 것)
// 

// 4. Mergy Sort 
// 피벗을 기준으로 배열을 분해해서 정렬하는 방법
// O(N log N)

// 5. Quick Sort
// pivot을 기준으로 pivot보다 크면 오른쪽, 작으면 왼쪽같은 방식으로 보낸후 
// 머지와 마찬가지로 분할
// 그리고 분할을 한뒤 다시 pivot을 기준으로 좌우 정렬
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
	std::cout << std::endl;

	int const mergeSortArrayCount = 10;
	int arr2[mergeSortArrayCount];
	for (int i = 0; i < mergeSortArrayCount; i++) {
		arr2[i] = rand() % 40;
	}
	SortExamples::MergySort(arr2, 0, mergeSortArrayCount-1);

	for (int i = 0; i < mergeSortArrayCount; i++)
		std::cout << arr2[i] << " ";
	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
		arr[i] = rand() % 1000;
	SortExamples::QuickSort(arr, 0, 10);
	for (int i = 0; i < 10; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	return 0;
}