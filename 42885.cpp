// 구명보트
// https://school.programmers.co.kr/learn/courses/30/lessons/42885

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit) {
    int ans = 0;
    sort(people.begin(), people.end());
    
    int start = 0, end = people.size()-1;
    while(start<=end){
        if(people[start]+people[end]>limit){
            end--;
            ans++;
        }
        else if(people[start]+people[end]<=limit){
            end--;
            start++;
            ans++;
        }
    }
    return ans;
}