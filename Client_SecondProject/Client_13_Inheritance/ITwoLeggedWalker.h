#pragma once
#include<string>
class ITwoLeggedWalker abstract/* �߻�Ŭ������ ������ִ� Ű���� ���ʿ��� �������� �������� ���� �ǰ�*/ {
public:
	std::string name;
public:
	virtual void Walk() = 0;
	/*virtual ~ITwoLeggedWalker() {}*/
};

