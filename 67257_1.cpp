#include <string>
#include <vector>

#define ll long long
using namespace std;

int permArr[3];
ll ans = -1;
char ope[3] = { '+', '-', '*' };
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

ll check(string exp) {
    vector<ll> memo = nVt;
    vector<char> memo2 = oVt;

    for (int i = 0; i < 3; ++i) {
        char o = ope[permArr[i]];
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

void perm(int level, int bit, string exp) {
    if (level == 3) {
        ans = max(ans, abs(check(exp)));
        return;
    }

    for (int i = 0; i < 3; ++i) {
        if ((bit & (1 << i)) != 0) continue;
        permArr[level] = i;
        perm(level + 1, bit | (1 << i), exp);
    }
}

ll solution(string expression) {
    makeNum(expression);
    perm(0, 0, expression);
    return ans;
}