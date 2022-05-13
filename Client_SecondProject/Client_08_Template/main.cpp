#include <iostream>
using namespace std;

template<typename T>
void Swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

int main(void) {

	int a = 3, b = 4;
	Swap(a, b);
	cout << a << ","<< b << endl;
	
	double c = 1.2, d = 3.4;
	Swap(c, d);
	cout << c << "," << d << endl;
	
	float e = 1.4f, f = 3.1f; 
	Swap<float>(e, f); cout << e << "," << f << endl; 
	return 0;
}