#include <iostream>
#include <vector>
#include <algorithm>

int BinarySearch(int arr[], int low, int high, int value) {
	if (low > high)
		return -1;

	int mid = low + (high - low) / 2;
	if (arr[mid] == value)
		return mid;
	else if (arr[mid] < value)
		return BinarySearch(arr, mid + 1, high, value);
	else
		return BinarySearch(arr, low, mid - 1, value);
}

int main(void) {
	int i;

	int arr[10] = { 50, 40, 60, 70, 20, 30, 10, 80, 90, 100 };
	std::vector<int> vi;
	for (i = 0; i < 10; i++)
		vi.push_back(arr[i]);

	std::sort(vi.begin(), vi.end());
	std::vector<int>::iterator it;
	for (it = vi.begin(), i = 0; it != vi.end(); it++, i++)
		arr[i] = *it;
	
	int index = BinarySearch(arr, 0, 9, 60);
	bool isIn = binary_search(vi.begin(), vi.end(), 66);

	if (index != -1)
		std::cout << arr[index] << std::endl;
	else
		std::cout << "검색실패" << std::endl;
	if (isIn)
		std::cout << "검색 결과 존재" << std::endl;
	else
		std::cout << "검색 결과 존재 안함" << std::endl;

	return 0;
}