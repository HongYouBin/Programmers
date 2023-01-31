//148652_2
//유사 칸토어 비트

#include <string>
#include <vector>
#include <math.h>

#define ll long long
using namespace std;

ll rec(ll num, int level) {
    if (level == 1) {
        ll cnt = 0;
        string s = "11011";
        for (int i = 0; i < num; ++i) {
            if (s[i] == '1') cnt++;
        }
        return cnt;
    }

    ll sum = 0;
    ll base = 1;
    while (pow(5, base + 1) < num) base++;

    ll sector = num / pow(5, base);
    int tmp = pow(5, base);
    ll mod = num % tmp;

    for (int i = 0; i < sector; ++i) {
        if (i == 2) continue;
        sum += pow(4, base);
    }

    if (sector == 2) return sum;
    return sum + rec(mod, level - 1);
}

int solution(int n, long long l, long long r) {
    ll R = rec(r, n);
    ll L = rec(l - 1, n);

    ll res = R - L;
    return (int)res;
}

