#pragma once
class Creature {
public:
	int weight;
	int height;
	int age;

public:
	// ����Ʈ �����ڸ� �����ε� ���� �ʰ� �⺻ �����Ǵ� �����ڸ� ����� ���
	// �ڵ����� ������� 0���� �ʱ�ȭ ���ִ� ����Ʈ �����ڰ� �����ȴ�.
	void Breath();
	void Grow();
};

