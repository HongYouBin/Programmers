//시소 짝꿍
//152996

#include <string>
#include <vector>
#include <map>

#define ll long long
using namespace std;

map<ll, ll> mp;
float arr[] = { 1, 2, 3, 4, 3 / 2, 4 / 3 };

long long solution(vector<int> weights) {
	ll ans = 0;

	for (auto& w : weights) mp[w]++;
	
	for (auto iter = mp.begin(); iter != mp.end(); ++iter) {
		ll num = iter->first, cnt = iter->second;
		if (cnt > 1) {
			ans += (cnt) * (cnt - 1) / 2;
		}
		if (mp.find(num * 2) != mp.end()) ans += (cnt * (ll)mp[num * 2]);
		if ((num % 2) == 0) {
			if (mp.find(num * 3 / 2) != mp.end()) ans += (cnt * (ll)mp[num * 3 / 2]);
		}
		if ((num % 3) == 0) {
			if (mp.find(num * 4 / 3) != mp.end()) ans += (cnt * (ll)mp[num * 4 / 3]);
		}
	}
	return ans;
}
