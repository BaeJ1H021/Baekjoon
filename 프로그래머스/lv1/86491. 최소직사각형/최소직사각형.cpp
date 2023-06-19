#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    // 전체 길이 중에 최대값.
    int max_length=0;
    // 가로 세로중에 짧은 길이 저장.
    vector<int> v;
    for(int i=0;i<sizes.size();i++)
    {
        for(int j=0;j<sizes[i].size();j++)
        {
            max_length = max(max_length,sizes[i][j]);
        }
        v.push_back(min(sizes[i][0],sizes[i][1]));
    }
    sort(v.begin(),v.end());
    answer = max_length * v.back();
    return answer;
}