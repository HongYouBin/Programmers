//68645
//삼각 달팽이

#include <string>
#include <vector>

using namespace std;

int arr[1001][1001];

vector<int> solution(int n) {
    vector<int> ans;

    int size = n, row = 0, col = 0, cnt = 1;
    
    while (size>0) {
        for (int r = row; r < row + size; ++r) {
            if (arr[r][col] > 0) continue;
            arr[r][col] = cnt++;
        }
        for (int c = col; c < col + size; ++c) {
            if (arr[row + size - 1][c] > 0) continue;
            arr[row + size - 1][c] = cnt++;
        }
        for (int i = 1; i <= size - 2; ++i) {
            if (arr[row + size - i - 1][col + size - i - 1] > 0) continue;
            arr[row + size - i - 1][col + size - i - 1] = cnt++;
        }

        row += 2;
        col++;
        size -= 3;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            ans.emplace_back(arr[i][j]);
        }
    }

    return ans;
}