//숫자 타자 대회 136797
//https://school.programmers.co.kr/learn/courses/30/lessons/136797
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define inf 1e9
using namespace std;

string number;
int dp[100001][10][10], arr[5][5], dx[8] = { 0, 0, 1, -1, -1, 1, 1, -1 }, dy[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };

int getDist(int findNum, int curPos) {
    for (int i = 0; i <= 4; ++i) {
        for (int j = 0; j <= 3; ++j) {
            arr[i][j] = inf;
        }
    }
    int curR, curC, findR, findC;
    if (curPos) {
        curR = curPos / 3 + 1;
        curC = curPos % 3;
        if (curC == 0) {
            curC = 3;
            curR--;
        }
    }
    else {
        curR = 4;
        curC = 2;
    }
    if (findNum) {
        findR = findNum / 3 + 1;
        findC = findNum % 3;
        if (findC == 0) {
            findC = 3;
            findR--;
        }
    }
    else {
        findR = 4;
        findC = 2;
    }
    //arr[curR][curC] = 0;
    queue<pair<int, pair<int, int>>> q;
    q.push({ 0, {curR, curC} });
    while (!q.empty()) {
        int cst = q.front().first;
        int row = q.front().second.first;
        int col = q.front().second.second; q.pop();
        if (arr[row][col] <= cst) continue;
        arr[row][col] = cst;
        for (int i = 0; i < 4; ++i) {
            int nxR = row + dx[i];
            int nxC = col + dy[i];
            if (nxR < 1 || 4 < nxR || nxC < 1 || 3 < nxC) continue;
            if (cst + 2 > arr[nxR][nxC]) continue;
            if ((nxR == 4 && nxC == 1) || (nxR == 4 && nxC == 3)) continue;
            q.push({ cst + 2, {nxR, nxC} });
        }
        for (int i = 4; i < 8; ++i) {
            int nxR = row + dx[i];
            int nxC = col + dy[i];
            if (nxR < 1 || 4 < nxR || nxC < 1 || 3 < nxC) continue;
            if (cst + 3 > arr[nxR][nxC]) continue;
            if ((nxR == 4 && nxC == 1) || (nxR == 4 && nxC == 3)) continue;
            q.push({ cst + 3, {nxR, nxC} });
        }
    }
    return arr[findR][findC];
}

int dfs(int level, int lPos, int rPos) {
    if (level == number.size()) return 0;
    int& num = dp[level][lPos][rPos];
    if (num != 0) return num;

    num = inf;
    int findNum = number[level] - '0';
    if (rPos == findNum || lPos == findNum) {
        return num = dfs(level + 1, lPos, rPos) + 1;
    }
    int cst = getDist(findNum, lPos);
    num = dfs(level + 1, findNum, rPos) + cst;
    cst = getDist(findNum, rPos);
    num = min(num, dfs(level + 1, lPos, findNum) + cst);
    return num;
}

int solution(string numbers) {
    number = numbers;
    return dfs(0, 4, 6);
}