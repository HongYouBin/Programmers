//12927 야근지수
#include <string>
#include <vector>
#include <queue>

#define ll long long
using namespace std;

priority_queue<int> pq;

ll solution(int n, vector<int> works) {
	ll ans = 0, sum = 0;

	for (int& w : works) {
		sum += (ll)w;
		pq.push(w);
	}
	if (n >= sum) return 0;
	while (n != 0) {
		int x = pq.top(); pq.pop();
		int y = pq.top();

		if (x == y) {
			pq.push(x - 1);
			n--;
		}
		else {
			if (abs(x - y) <= n) {
				pq.push(y);
				n -= (x - y);
			}
			else {
				pq.push(x - n);
				n = 0;
			}
		}
	}
	while (!pq.empty()) {
		ll tmp = pq.top(); pq.pop();
		ans += tmp * tmp;
	}
	return ans;
}

