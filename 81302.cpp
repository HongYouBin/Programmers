// 거리두기 확인하기
// https://school.programmers.co.kr/learn/courses/30/lessons/81302

#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int mapArr[5][5], visited[5][5], dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };

bool solv(vector<pair<int, int>>& pos) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            visited[i][j] = 0;
        }
    }

    for (auto& curPos : pos) {
        queue<pair<int, int>> q;
        q.push({ curPos.first, curPos.second });
        visited[curPos.first][curPos.second] = 1;
        while (!q.empty()) {
            int curR = q.front().first, curC = q.front().second; q.pop();
            if (!(curR==curPos.first && curC==curPos.second) && mapArr[curR][curC] == 1) return false;
            for (int i = 0; i < 4; ++i) {
                int nR = curR + dx[i], nC = curC + dy[i];
                if (nR < 0 || 5 <= nR || nC < 0 || 5 <= nC) continue;
                if (visited[nR][nC] > 0) continue;
                if (mapArr[nR][nC] == -1) continue;
                visited[nR][nC] = visited[curR][curC] + 1;
                if (visited[nR][nC] > 3) continue;
                q.push({ nR, nC });
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> ans;
    for (auto& place : places) {
        vector<pair<int, int>> pos;
        for (int r = 0; r < 5; ++r) {
            for (int c = 0; c < 5; ++c) {
                if (place[r][c] == 'P') {
                    mapArr[r][c] = 1;
                    pos.push_back({ r, c });
                }
                else if (place[r][c] == 'O') {
                    mapArr[r][c] = 0;
                }
                else {
                    mapArr[r][c] = -1;
                }
            }
        }
        if (solv(pos)) ans.emplace_back(1);
        else ans.emplace_back(0);
    }
    return ans;
}