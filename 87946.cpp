#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool visited[10];
int ans = 0;

int solution(int k, vector<vector<int>> dungeons) {
	vector<int> bin(dungeons.size());
	for (int i = 0; i < dungeons.size(); ++i) bin[i] = i;
	do {
		int order = 0;
		int curK = k;
		int cnt = 0;
		for (int order = 0; order < dungeons.size();++order) {
			for (int i = 0; i < dungeons.size(); ++i) {
				if (bin[i] != order) continue;
				if (curK < dungeons[i][0]) break;
				curK -= dungeons[i][1];
				cnt++;
				ans = max(ans, cnt);
			}
		}
	} while (next_permutation(bin.begin(), bin.end()));
	
	return ans;
}

