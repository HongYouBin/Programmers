//68936
//쿼드압축 후 개수 세기

#include <string>
#include <vector>

using namespace std;

vector<int> ans(2);

int check(int row, int col, int size, vector<vector<int>>& arr) {
    int tmp = arr[row][col];
    for (int i = row; i < row + size; ++i) {
        for (int j = col; j < col + size; ++j) {
            if (arr[i][j] != tmp) return -1;
        }
    }
    return tmp;
}

void solv(int row, int col, int size, vector<vector<int>>& arr) {
    int flag = check(row, col, size, arr);
    if (flag == -1) {
        solv(row, col, size / 2, arr);
        solv(row, col + size / 2, size / 2, arr);
        solv(row + size / 2, col, size / 2, arr);
        solv(row + size / 2, col + size / 2, size / 2, arr);
    }
    else {
        ans[flag]++;
        return;
    }
}

vector<int> solution(vector<vector<int>> arr) {
    solv(0, 0, arr.size(), arr);
    return ans;
}