#include "SumFunctions.h"
extern opCount; 
/* �ٸ� �ҽ����Ͽ��� ����� ���������� �� �ҽ����Ͽ��� ����ϰ� ������ ����ϴ� Ű���� extern
������ ������ �ش� �ε��� �̸����� ����� ������ ������ �ش� ������ ����
���� �Ҵ��� �ϴ� �� �ƴ� �ش� ���������� �ּҸ� ��ũ�Ѵٰ� �����ص� ����*/

int sumInt(int a, int b) { opCount++; return a + b; }
double sumDouble(double a, double b) { opCount++; return a + b; }