#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> mp;
vector<int> vt[10001];
int earn[10001];

void makeMap(vector<string>& enroll) {
	int cnt = 1;
	for (auto& e : enroll) {
		mp[e] = cnt;
		cnt++;
	}
}

void makeEdge(vector<string>& enroll, vector<string>& referral) {
	for (int i = 0; i < enroll.size(); ++i) {
		if (referral[i] == "-") vt[mp[enroll[i]]].emplace_back(0);
		else vt[mp[enroll[i]]].emplace_back(mp[referral[i]]);
	}
}

void spread(int num, int money) {
	if (num == 0) return;

	//if (vt[num][0]==-1) return;

	int sendMoney = money * 10 / 100;
	int myMoney = money - sendMoney;
	earn[num] += myMoney;
	spread(vt[num][0], sendMoney);
}

void getEarn(vector<string>& seller, vector<int>& amount) {
	for (int i = 0; i < amount.size(); ++i) {
		spread(mp[seller[i]], amount[i] * 100);
	}
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
	makeMap(enroll);
	makeEdge(enroll, referral);
	getEarn(seller, amount);

	vector<int> ans;
	for (int i = 1; i <= enroll.size(); ++i) {
		ans.emplace_back(earn[i]);
	}
	return ans;
}