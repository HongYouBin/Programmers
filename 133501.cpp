#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Guard {
public:
    int startArea = -1;
    int endArea = -1;
    int restTime = -1;
    int workTime = -1;
};

vector<Guard> vt;

bool comp(Guard a, Guard b) {
    return a.startArea < b.startArea;
}

int solution(int distance, vector<vector<int>> scope, vector<vector<int>> times) {
    Guard guard;
    for (int i = 0; i < scope.size(); ++i) {
        int startScope = scope[i][0];
        int endScope = scope[i][1];
        int workTime = times[i][0];
        int restTime = times[i][1];
        if (startScope > endScope) swap(startScope, endScope);
        guard.startArea = startScope;
        guard.endArea = endScope;
        guard.restTime = restTime;
        guard.workTime = workTime;
        vt.emplace_back(guard);
    }
    sort(vt.begin(), vt.end(), comp);
    
    int ans = 0;
    for (auto& curGuard : vt) {
        ans = curGuard.startArea - 1;
        for (int pos = curGuard.startArea; pos <= curGuard.endArea; pos++) {
            int guardTime = pos % (curGuard.restTime + curGuard.workTime);
            if (guardTime == 0) guardTime = (curGuard.restTime + curGuard.workTime);
            if (guardTime <= curGuard.workTime) {
                return pos;
            }
            //else return guardTime;
        }
    }
    return distance;
}