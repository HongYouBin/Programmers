#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

stack<int> velt, tmpVelt;

int solution(vector<int> order) {
	vector<int> ans;
	for (int i = order.size(); 1 <= i; --i) velt.push(i);
	int idx = 0;

	while (true) {
		if (!tmpVelt.empty() && order[idx] == tmpVelt.top()) {
			ans.emplace_back(tmpVelt.top());
			tmpVelt.pop();
			idx++;
		}
		else if (!velt.empty() && order[idx] == velt.top()) {
			ans.emplace_back(velt.top());
			velt.pop();
			idx++;
		}
		else if (!velt.empty() && order[idx] != velt.top()) {
			tmpVelt.push(velt.top());
			velt.pop();
		}
		else if (velt.empty()) break;
	}

	cout << '\n';
	return ans.size();
}