#include <string>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

ll ans = -1;
vector<char> ope = { '+', '-', '*' };
vector<ll> nVt;
vector<char> oVt;

void makeNum(string exp) {
	ll num = 0;
	for (int i = 0; i < exp.size(); ++i) {
		if ('0' <= exp[i] && exp[i] <= '9') {
			num *= 10;
			num += exp[i] - '0';
		}
		else {
			nVt.emplace_back(num);
			oVt.emplace_back(exp[i]);
			num = 0;
		}
	}
	nVt.emplace_back(num);
}

ll check() {
	vector<ll> memo = nVt;
	vector<char> memo2 = oVt;

	for (int i = 0; i < 3; ++i) {
		char o = ope[i];
		for (int j = 0; j < memo2.size(); ++j) {
			if (memo2[j] == o) {
				ll num1 = memo[j], num2 = memo[j + 1];
				if (o == '-') memo[j] = num1 - num2;
				else if (o == '+') memo[j] = num1 + num2;
				else memo[j] = num1 * num2;
				memo.erase(memo.begin() + j + 1);
				memo2.erase(memo2.begin() + j);
				j--;
			}
		}
	}
	return memo[0];
}

ll solution(string expression) {
	sort(ope.begin(), ope.end());
	makeNum(expression);

	do {
		ans = max(ans, abs(check()));
	} while (next_permutation(ope.begin(), ope.end()));

	return ans;
}

int main() {
	solution("50*6-3*2");
}