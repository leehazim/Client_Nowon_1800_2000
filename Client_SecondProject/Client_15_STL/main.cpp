#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "TDArray.h"
using namespace std;

int main(void) {

	vector<int> tmpVec;
	vector<int>::iterator it;
	for (int i = 1; i <= 10; i++) tmpVec.push_back(i);
	int a = *tmpVec.begin();
	cout << a << endl;
	for (it = tmpVec.begin(); it != tmpVec.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	it = tmpVec.begin() + 1;
	it = tmpVec.erase(it);
	for (it = tmpVec.begin(); it != tmpVec.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	TDArray<int> arr;
	for (int i = 1; i <= 10; i++)
		arr.PushBack(i);
	TDArray<int>::Iterator iter;
	iter.idx = 2;
	iter.p_Data = arr.GetData(0);
	cout << *iter << endl;
	iter = arr.Begin();
	cout << *iter << endl;

	TDArray<int>::Iterator it2 = arr.Begin();
	cout << *it2 << endl;

	return 0;
}