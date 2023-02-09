#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <iostream>
#include <map>

#define pip pair<int, pair<int, int>>
using namespace std;

queue<pair<int, int>> q;
map<int, int> mp;

int dp(int curNum) {
	if (mp.find(curNum) != mp.end()) {
		return mp[curNum];
	}

	int base = 0;
	while (pow(10, base + 1) <= curNum) base++;
	if (pow(10, base) == curNum) {
		mp[curNum] = 1;
		return 1;
	}
	
	mp[curNum] = 1e9;
	if (curNum % 10 == 0) mp[curNum] = curNum / 10;

	int mod = curNum % 10;
	int minNum = min(dp(curNum / 10) + mod, dp(curNum / 10 + 1) + 10 - mod);
	mp[curNum] = min(minNum, mp[curNum]);
	return mp[curNum];
}

int solution(int storey) {
	//dp
	mp[0] = 0;
	return dp(storey);
}