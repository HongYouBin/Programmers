#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<int, int> mp;

int solution(vector<int> elements) {
    for(int num=1;num<=elements.size();++num){
        for(int start=0;start<elements.size();++start){
            int sum = 0;
            for(int i=start;i<start+num;++i){
                sum+=elements[i%elements.size()];
            }
            mp[sum]++;
        }
    }

    return mp.size();
}