//132266 ºÎ´ëº¹±Í
#include <string>
#include <vector>
#include <queue>
#define inf 1e9
#define pip pair<int, pair<int, int>>
#define pii pair<int, int>
using namespace std;

int dist[100005];
vector<int> vt[100005];
priority_queue<pii> pq;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
	for (int i = 1; i <= n; ++i) dist[i] = inf;
	dist[destination] = 0;

	for (auto& road : roads) {
		vt[road[0]].emplace_back(road[1]);
		vt[road[1]].emplace_back(road[0]);
	}
	for (auto& road : vt[destination]) {
		pq.push({ -1, road });
	}

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int pos = pq.top().second; pq.pop();
		if (dist[pos] < cost) continue;
		dist[pos] = cost;
		for (int& nxt : vt[pos]) {
			if (dist[nxt] < cost + 1) continue;
			pq.push({ -cost - 1, nxt });
		}
	}
	vector<int> ans;
	for (int& s : sources) {
		if (dist[s] == inf) ans.emplace_back(-1);
		else ans.emplace_back(dist[s]);
	}
	return ans;
}