#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Player {
public:
	std::string m_nickName;
	int m_score;

	Player(std::string name, int score) {
		m_nickName = name;
		m_score = score;
	}

	bool operator <(Player& player) {
		return m_score < player.m_score;
	}
	bool operator >(Player& player) {
		return m_score > player.m_score;
	}
	bool operator ==(Player& player) {
		return m_score == player.m_score;
	}
};

int main(void) {

	srand(time(nullptr));
	int arr[10] = { 7, 6, 2, 4, 5, 1, 3, 9, 8, 0 };
	std::sort(arr, arr + 10); 
	// algorithm에서 정의된 sort등의 함수들은 모두 끝다음점 개념으로 접근해야 해서 end주소를 마지막 인덱스 다음의 주소를 넘겨야한다.
	for (int i = 0; i < 10; i++) std::cout << arr[i] << " ";
	std::cout << std::endl;

	std::vector<int> vec1;
	std::vector<int>::iterator it1;
	
	for (int i = 0; i < 10; i++) 
		vec1.push_back(rand() % 100);
	
	std::sort(vec1.begin(), vec1.end());

	for (it1 = vec1.begin(); it1 != vec1.end(); it1++)
		std::cout << *it1 << " ";
	std::cout << std::endl;

	/*std::vector<std::pair<std::string, int> > ranking;
	std::vector<std::pair<std::string, int> >::iterator it;
	ranking.push_back(std::pair<std::string, int>("joshua", rand() % 100));
	ranking.push_back(std::pair<std::string, int>("jungmin", rand() % 100));
	ranking.push_back(std::pair<std::string, int>("julia", rand() % 100));
	ranking.push_back(std::pair<std::string, int>("Mike", rand() % 100));
	for (it = ranking.begin(); it != ranking.end(); it++)
		std::cout << it->second << std::endl;
	std::cout << std::endl;
	std::sort(ranking.begin(), ranking.end());
	for (it = ranking.begin(); it != ranking.end(); it++)
		std::cout << it->second << std::endl;*/

	std::vector<Player> rank;
	std::vector<Player>::iterator it;
	rank.push_back(Player("joshua", rand() % 100));
	rank.push_back(Player("jungmin", rand() % 100));
	rank.push_back(Player("julia", rand() % 100));
	rank.push_back(Player("Mike", rand() % 100));
	for (it = rank.begin(); it != rank.end(); it++) {
		std::cout << it->m_nickName << ": " << it->m_score;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::sort(rank.begin(), rank.end());
	for (it = rank.begin(); it != rank.end(); it++) {
		std::cout << it->m_nickName << ": " << it->m_score;
		std::cout << std::endl;
	}
	return 0; 
}