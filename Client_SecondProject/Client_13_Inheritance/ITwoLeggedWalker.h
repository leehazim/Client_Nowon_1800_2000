#pragma once
#include<string>
class ITwoLeggedWalker abstract/* 추상클래스로 만들어주는 키워드 불필요해 보이지만 가독성을 위한 건가*/ {
public:
	std::string name;
public:
	virtual void Walk() = 0;
	/*virtual ~ITwoLeggedWalker() {}*/
};

