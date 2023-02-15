// 76502
// 괄호 회전하기

#include <string>
#include <vector>
#include <stack>

using namespace std;

bool check(int start, string& s) {
	stack<char> st;
	for (int i = 0; i < s.length(); ++i) {
		int idx = (start + i) % s.length();
		if (s[idx] == '[') st.push('[');
		else if (s[idx] == '(') st.push('(');
		else if (s[idx] == '{') st.push('{');
		else if (!st.empty() && st.top() == '[' && s[idx] == ']') st.pop();
		else if (!st.empty() && st.top() == '{' && s[idx] == '}') st.pop();
		else if (!st.empty() && st.top() == '(' && s[idx] == ')') st.pop();
		else return false;
	}
	if (st.empty()) return true;
	return false;
}

int solution(string s) {
	int ans = 0;
	for (int start = 0; start < s.length(); ++start) {
		if (check(start, s)) ans++;
	}
	return ans;
}

int main() {
	solution("[](){}");
}