#include <string>
#include <vector>

#define inf 1e9
using namespace std;

int ans = inf, dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };

void turn(int row, int col, vector<vector<int>>& clockHands, int sum) {
    int rowSize = clockHands.size();
    clockHands[row][col] = (clockHands[row][col] + sum) % 4;
    for (int i = 0; i < 4; ++i) {
        int nxR = row + dx[i];
        int nxC = col + dy[i];
        if (nxR < 0 || rowSize <= nxR || nxC < 0 || rowSize <= nxC) continue;
        clockHands[nxR][nxC] = (clockHands[nxR][nxC] + sum) % 4;
    }
}
bool check(vector<vector<int>>& clockHands) {
    for (int i = 0; i < clockHands.size(); ++i) {
        for (int j = 0; j < clockHands.size(); ++j) {
            if (clockHands[i][j] != 0) return false;
        }
    }
    return true;
}

void dfs(int level, int sum, vector<vector<int>>& clockHands) {
    if (level >= clockHands.size() * clockHands[0].size()) {
        if(check(clockHands)) ans = min(ans, sum);
        return;
    }

    int row = level / clockHands[0].size();
    int col = level % clockHands[0].size();
    vector<vector<int>> memo = clockHands;

    if (row == 0) {
        for (int i = 0; i < 4; ++i) {
            if (i != 0) turn(row, col, clockHands, i);
            dfs(level + 1, sum + i, clockHands);
            if(i != 0) clockHands = memo;
        }
    }
    else {
        if (clockHands[row - 1][col] == 0) {
            dfs(level + 1, sum, clockHands);
        }
        else if (clockHands[row - 1][col] == 1) {
            turn(row, col, clockHands, 3);
            dfs(level + 1, sum + 3, clockHands);
            clockHands = memo;
        }
        else if (clockHands[row - 1][col] == 2) {
            turn(row, col, clockHands, 2);
            dfs(level + 1, sum + 2, clockHands);
            clockHands = memo;
        }
        else {
            turn(row, col, clockHands, 1);
            dfs(level + 1, sum + 1, clockHands);
            clockHands = memo;
        }
    }
}

int solution(vector<vector<int>> clockHands) {
    dfs(0, 0, clockHands);
    return ans;
}