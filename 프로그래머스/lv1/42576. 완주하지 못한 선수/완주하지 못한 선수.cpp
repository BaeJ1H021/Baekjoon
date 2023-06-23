#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string,int> map;
    for(auto player: participant)
    {
        // 처음 넣은 이름이면 insert.
        if(map.end()==map.find(player))
        {
            map.insert({player,1});
        }
        // 중복이면 +1
        else
        {
            map[player]++;
        }
    }
    for(auto player: completion)
    {
        map[player]--;
    }
    for(auto player: participant)
    {
        if(map[player]>0)
        {
            answer = player;
            break;
        }
    }
    return answer;
}