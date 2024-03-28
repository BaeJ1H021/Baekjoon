#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <sstream>

using namespace std;

unordered_map<string, int> m; 
int id = 0;
int arr[55][55]; // arr[1][3] : 1번이 3번에게 준 선물의 개수.
int max_ans = 0;
int gift_score[55]; // 선물지수

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    for(int i=0;i<friends.size();i++)
    {
        m[friends[i]] = id++;
    }
    for(int i=0;i<gifts.size();i++)
    {
        istringstream ss(gifts[i]);
        string stringBuffer;
        vector<string> gift;
        while (getline(ss, stringBuffer, ' '))
        {
            gift.push_back(stringBuffer);
        }
        arr[m[gift[0]]][m[gift[1]]]++;
        // 선물지수
        gift_score[m[gift[0]]]++;
        gift_score[m[gift[1]]]--;
    }
    for(int i=0;i<friends.size();i++)
    {
        int cnt = 0;
        for(int j=0;j<friends.size();j++)
        {
            if(i==j)
                continue;
            // 내가 더 많이 줬으면.
            if(arr[i][j]>arr[j][i])
                cnt++;
            // 준 횟수 같고 선물 지수 내가 더 크다면.
            else if(arr[i][j]==arr[j][i] && gift_score[i]>gift_score[j])
                cnt++;
        }
        max_ans = max(cnt, max_ans);
    }
    answer= max_ans;
    return answer;
}