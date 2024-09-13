#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 2e9;

vector<pair<int,int>> vec[52];
int d[2002];

void djkstra()
{
    
    priority_queue<pair<int,int>> pq;
    pq.push({0, 1});
    d[1] = 0;

    while(!pq.empty())
    {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        for(int i=0;i<vec[now].size();i++)
        {
            int next = vec[now][i].first;
            int ndist = vec[now][i].second;
            
            if(d[next]>dist+ndist)
            {
                d[next] = dist+ndist;
                pq.push({-d[next], next});
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    // 초기화
    for(int i=0;i<2002;i++)
    {
        d[i] = INF;
    }
    
    for(int i=0;i<road.size();i++)
    {
        int A = road[i][0];
        int B = road[i][1];
        int cost = road[i][2];
        vec[A].push_back({B,cost});
        vec[B].push_back({A,cost});
    }
    
    djkstra();

    for(int i=1;i<=N;i++)
    {
        if(d[i]<=K)
            answer++;
    }
    
    return answer;
}