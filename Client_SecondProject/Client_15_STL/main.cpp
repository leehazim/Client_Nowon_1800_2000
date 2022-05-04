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
	
	/*cout << *tmpVec.end() << endl; 마지막 요소가 출력될거 같지만 STL에서 end로 가져오는 반복자는 끝다음점이다. 
	프로그램에서 모든 마지막 인덱스와 크기인 숫자는 같지가 않은 [a,b)방식의 포함관계임을 잊지말자*/
	//for (it = tmpVec.begin(); it != tmpVec.end(); it++) { /* 벡터는 동적배열이기 때문에 시작부의 주소가 end의 주소보다 작다가 성립해서 부등호로 표현할 수도 있다.*/
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