#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>
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

	// 벡터등 배열에 들어있는 모든 데이터들의 값을 합산하고 싶을때 사용
	int acc = std::accumulate(arr, arr + 10, 10);
	std::cout << "누적값 : " << acc << std::endl;
	
	// 절대값 변경
	/*int result = abs(-10);
	std::cout << result << std::endl;*/

	int arr2[10];
	for (int i = 0; i < 10; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	std::partial_sum(arr, arr + 10, arr2);
	for(int i = 0; i<10; i++)
		std::cout << arr2[i] << " ";
	std::cout << std::endl;

	std::adjacent_difference(arr, arr + 10, arr2);
	for (int i = 0; i < 10; i++)
		std::cout << arr2[i] << " ";
	std::cout << std::endl;

	// 벡터의 내적
	int coord1[3] = { 1,5,3 };
	int coord2[3] = { 2,5,4 };
	int size = (coord2[0] * coord2[0]) + (coord2[1] * coord2[1]) + (coord2[2] * coord2[2]);
	int dotResult = std::inner_product(coord1, coord1 + 3, coord2, 0);
	for (int i = 0; i < 3; i++)
		coord2[i] /= size;
	
	std::cout << dotResult << std::endl;
	for (int i = 0; i < 3; i++)
		coord2[i] *= dotResult;
	for (int i = 0; i < 3; i++)
		std::cout << coord2[i] << " ";
	std::cout << std::endl;
	return 0; 
}