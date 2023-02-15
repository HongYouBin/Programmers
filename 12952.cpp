//12952
//n queen

#include <string>
#include <vector>

using namespace std;

int ans;

bool visitedCol[20], d1[100], d2[100];

void solv(int row, int n) {
    if (row == n) {
        ans++;
        return;
    }
    for (int col = 0; col < n; ++col) {
        if (visitedCol[col] || d1[row + col] || d2[n - row - 1 + col]) continue;
        visitedCol[col] = 1;
        d1[row + col] = 1;
        d2[n - row - 1 + col] = 1;
        solv(row + 1, n);
        visitedCol[col] = 0;
        d1[row + col] = 0;
        d2[n - row - 1 + col] = 0;
    }
}

int solution(int n) {
    solv(0, n);
    return ans;
}