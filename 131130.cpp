#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int visited[101];

int makeGroup(int card, vector<int>& cards) {
	int cnt = 1;
	visited[card] = 1;
	while (true) {
		int nxtCard = cards[card - 1];
		if (visited[nxtCard]) break;
		cnt++;
		visited[nxtCard] = 1;
		card = nxtCard;
	}
	return cnt;
}

int solution(vector<int> cards) {
	vector<int> vt;
	for (auto& card : cards) {
		if (visited[card]) continue;
		vt.emplace_back(makeGroup(card, cards));
	}
	sort(vt.begin(), vt.end());
	return vt[vt.size() - 1] * vt[vt.size() - 2];
}