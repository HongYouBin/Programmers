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
			ll bit = 1;
			while ((number & bit) != 0) bit *= 2;
			number = number | bit;
			number = number ^ (number / 2);
			ans.emplace_back(number);
		}
	}
	return ans;
}

