#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main() {
	long long N;
	cin >> N;
	vector<int> Su;
	int Ar;
	int Arr[6] = { 5,4,3,2,1,0};
	int maximum = 0;
	int memory;
	for (int i = 0; i < 6; i++)
	{
		cin >> Ar;
		Su.push_back(Ar);
		if (maximum < Ar) {
			maximum = Ar;
			memory = i;
		}
	}
	if (N == 1) {
		for (int i = memory + 1; i < 6; i++) {
			Su[i - 1] = Su[i];
		}
		Su.resize(Su.size() - 1);
		int sum = 0;
		for (int i = 0; i < Su.size(); i++) sum += Su[i];
		cout << sum;
		return 0;
	}
	int minimum = 101;
	int minimum2 = 151;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (i == j ||(i == 0 && j == 5) || (i == 5 && j == 0) ||
				(i == 1 && j == 4) || (i == 4 && j == 1) ||
				(i == 2 && j == 3) || (i == 3 && j == 2))
				continue;
			minimum = min(minimum, Su[i] + Su[j]);
		}
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (i==memory||i==Arr[memory]||
				j==memory||j==Arr[memory]||
				i == j || 
				(i == 0 && j == 5) || (i == 5 && j == 0) ||
				(i == 1 && j == 4) || (i == 4 && j == 1) ||
				(i == 2 && j == 3) || (i == 3 && j == 2))
				continue;
			minimum2 = min(minimum2,Su[Arr[memory]]+Su[i]+Su[j]);
		}
	}
	//0번째면 5번째를 1번째면 4번째를 2번째면 3번째를
	long long one = (*min_element(Su.begin(), Su.end())) * ((pow(N - 2, 2) * 5) + ((N - 2) * 4));
	long long two = minimum * ((N - 1) * 4 + (N - 2) * 4);
	long long three = minimum2 * 4;
	cout << one + two + three;
}