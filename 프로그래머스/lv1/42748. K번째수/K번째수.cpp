#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0;i<commands.size();i++)
    {
        int start = commands[i][0];
        int end = commands[i][1];
        int idx = commands[i][2];
        vector<int> v = vector<int>(array.begin()+start-1,array.begin()+end);
        sort(v.begin(),v.end());
        answer.push_back(v[idx-1]);
    }
    return answer;
}