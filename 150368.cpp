//150368
//이모티콘 할인행사

#include <string>
#include <vector>

using namespace std;

int emoticonArr[10][2], perc[4] = { 10, 20, 30, 40 }, ansPrice = -1, ansService = -1;

void check(vector<vector<int>>& users, int eSize) {
    int sum = 0, service = 0, totalSum = 0;

    for (int user = 0; user < users.size(); ++user) {
        sum = 0;
        for (int i = 0; i < eSize; ++i) {
            if (users[user][0] > emoticonArr[i][1]) continue;
            //double mul = (100 - emoticonArr[i][1]);
            //mul /= 100;
            //sum +=  mul * emoticonArr[i][0];
            sum+=emoticonArr[i][0] * (100-emoticonArr[i][1]) /100;
        }
        if (sum < users[user][1]) totalSum += sum;
        else service++;
    }
    
    if (ansService < service) {
        ansService = service;
        ansPrice = totalSum;
    }
    else if (ansService == service) ansPrice = max(ansPrice, totalSum);
}

void solv(int level, vector<int>& emoticons, vector<vector<int>>& users) {
    if (level == emoticons.size()) {
        check(users, emoticons.size());
        return;
    }

    for (int i = 0; i < 4; ++i) {
        emoticonArr[level][0] = emoticons[level];
        emoticonArr[level][1] = perc[i];
        solv(level + 1, emoticons, users);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    solv(0, emoticons, users);

    vector<int> ans;
    ans.emplace_back(ansService);
    ans.emplace_back(ansPrice);
    return ans;
}

int main() {
    solution({ {40, 10000}, {25, 10000} }, { 7000, 9000 });
}