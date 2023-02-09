#include <string>
#include <vector>

#define ll long long
using namespace std;

vector<long long> solution(vector<long long> numbers) {
	vector<ll> ans;
	for (auto& number : numbers) {
		if ((number & 1) == 0) {
			ans.emplace_back(number + 1);
		}
		else {
			ll shfCnt = 0;
			while((number & (1 << shfCnt)) != 0) shfCnt++;
			ll tmp = number | (1 << shfCnt);
			tmp = tmp ^ (1 << (shfCnt - 1));
			ll bit = 1;
			
		}
	}
	return ans;
}

