#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int maxA, maxB, ans;

int solv(int a, int b) {
	if (a == 0) return b;
	else if (b == 0) return a;
	int maxValue = max(a, b);
	int minValue = min(a, b);
	return solv(minValue, maxValue%minValue);
}

vector<int> getVector(int num) {
	vector<int> candid;
	for (int i = 1; i <= num; ++i) {
		if ((num%i) == 0) candid.emplace_back(i);
	}
	return candid;
}

void devide(vector<int>& array, vector<int>& candid) {
	for (int i = 0; i < candid.size(); ++i) {
		bool flag = true;
		for (int j = 0; j < array.size(); ++j) {
			if ((array[j] % candid[i]) == 0) flag = false;
			if (flag && (j == array.size() - 1)) ans = max(ans, candid[i]);
		}
	}
}

int solution(vector<int> arrayA, vector<int> arrayB) {
	int a = arrayA[0];
	int b = arrayB[0];

	for (auto& i : arrayA) a = solv(a, i);
	for (auto& i : arrayB) b = solv(b, i);
	cout << b << '\n';
	vector<int> aCandid = getVector(a);
	vector<int> bCandid = getVector(b);

	cout << '\n';

	devide(arrayB, aCandid);
	devide(arrayA, bCandid);
	return ans;
}