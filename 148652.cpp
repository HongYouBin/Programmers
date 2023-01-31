//148652
//유사칸토어 비트열

#include <string>
#include <vector>

#define ll long long
using namespace std;

ll rec(ll num, int level) {
    if (level == 0) return 0;

    ll sum = 0;
    ll mul = 1;
    for (int i = 0; i < level - 1; ++i) mul *= 4;
    
    ll di = 1;
    for (int i = 0; i < level - 1; ++i) di *= 5;
    
    ll j = 0;
    for (; j < (num / di); ++j) {
        if (j == 2) continue;
        sum += mul;
    }
    num = num - j * di;

    if (j == 2) return sum;
    return sum + rec(num, level - 1);
}

int solution(int n, long long l, long long r) {
    ll R = rec(r, n);
    ll L = rec(l - 1, n);

    ll res = R - L;
    return (int)res;
}

