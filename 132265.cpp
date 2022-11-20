#include <string>
#include <vector>

using namespace std;

int bTopping[10001], cTopping[10001];

int solution(vector<int> topping) {
    int answer = 0;

    int bCnt = 0;
    int cCnt = 0;

    for (auto& idx : topping) {
        if (cTopping[idx] == 0) cCnt++;
        cTopping[idx]++;
    }

    for (auto& idx : topping) {
        if (bTopping[idx] == 0) bCnt++;
        bTopping[idx]++;
        cTopping[idx]--;
        if (cTopping[idx] == 0) cCnt--;
        if (bCnt == cCnt) answer++;
    }
    return answer;
}