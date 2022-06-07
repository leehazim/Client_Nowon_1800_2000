#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#pragma warning(disable : 4996)

class Player {
public:
	std::string m_nickName;
	int m_score;

	Player(std::string name, int score) {
		m_nickName = name;
		m_score = score;
	}

	bool operator <(const Player& player) const {
		return m_score < player.m_score;
	}
	bool operator >(const Player& player) const {
		return m_score > player.m_score;
	}
	bool operator ==(Player& player) {
		return m_score == player.m_score;
	}
};
 
bool IsABeatB(Player& player1,Player& player2) {
	return player1 > player2;
}

int main(void) {

	srand(time(nullptr));
	int arr[10] = { 7, 6, 2, 4, 5, 1, 3, 9, 8, 0 };
	std::sort(arr, arr + 10); 
	// algorithm���� ���ǵ� sort���� �Լ����� ��� �������� �������� �����ؾ� �ؼ� end�ּҸ� ������ �ε��� ������ �ּҸ� �Ѱܾ��Ѵ�.
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
	/*rank.push_back(Player("joshua", rand() % 100));
	rank.push_back(Player("jungmin", rand() % 100));
	rank.push_back(Player("julia", rand() % 100));
	rank.push_back(Player("Mike", rand() % 100));
	rank.push_back(Player("SU", rand() % 100));
	rank.push_back(Player("john", rand() % 100));
	rank.push_back(Player("komi", rand() % 100));*/
	char str[128] = "";
	for (int i = 0; i <10; i++) {
		strcat(str, "a");
		rank.push_back(Player(str, rand() % 100));
	}
	for (it = rank.begin(); it != rank.end(); it++) {
		std::cout <<  " : " << it->m_score << " ";
		/*std::cout << std::endl;*/
	}
	std::cout << std::endl;
	//std::sort(rank.begin(), rank.end());

	/*partial_sort(rank.begin(), rank.begin() + 3, rank.end(), IsABeatB);*/
	/*partial_sort(rank.begin(), rank.begin() + 3, rank.end(), std::greater<>());*/
	//partial_sort(rank.begin(), rank.begin() + 3, rank.end(), std::less<>());

 	/*nth_element(rank.begin(), rank.begin() + 3, rank.end());*/
	//sort(rank.begin(), rank.end(), std::less<>());
	stable_sort(rank.begin(),rank.end(), std::less<>());
	for (it = rank.begin(); it != rank.end(); it++) {
		std::cout << " : " << it->m_score << " ";
	}
	std::cout << std::endl;
	return 0; 
}