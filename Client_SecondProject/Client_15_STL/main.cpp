#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "TDArray.h"
using namespace std;

int main(void) {

	vector<int> tmpVec;
	vector<int>::iterator it;
	for (int i = 1; i <= 10; i++)
		tmpVec.push_back(i);
	for (it = tmpVec.begin(); it != tmpVec.end(); it++) {
		
	}
	/*int a = *tmpVec.begin();
	cout << a << endl;*/

	it = tmpVec.end();

	tmpVec.push_back(20);

	tmpVec.push_back(21);
	cout << *it << endl;
	
	/*cout << *tmpVec.end() << endl; ������ ��Ұ� ��µɰ� ������ STL���� end�� �������� �ݺ��ڴ� ���������̴�. 
	���α׷����� ��� ������ �ε����� ũ���� ���ڴ� ������ ���� [a,b)����� ���԰������� ��������*/
	//for (it = tmpVec.begin(); it != tmpVec.end(); it++) { /* ���ʹ� �����迭�̱� ������ ���ۺ��� �ּҰ� end�� �ּҺ��� �۴ٰ� �����ؼ� �ε�ȣ�� ǥ���� ���� �ִ�.*/
	//	cout << *it << " ";
	//}
	//cout << endl;

	/*it = tmpVec.begin() + 1;
	it = tmpVec.erase(it);
	for (it = tmpVec.begin(); it != tmpVec.end(); it++) {
		cout << *it << " ";
	}*/
	cout << endl;

	TDArray<int> arr;
	TDArray<int>::Iterator iter, iter2;
	for (int i = 1; i <= 10; i++) 
		arr.PushBack(i);
	iter = arr.Begin();
	/*cout << *iter << endl;*/
	iter2 = iter++;

	cout << *iter2++ << endl;
	cout << *iter << endl;
	for (iter = arr.Begin(); iter < arr.End(); iter++) {
		cout << *iter << " ";
 	}
	cout << endl;
	
	return 0;
}