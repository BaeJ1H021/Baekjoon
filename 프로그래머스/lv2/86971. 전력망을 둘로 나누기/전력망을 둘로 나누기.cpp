#include <string>
#include <vector>
#include <iostream>
#include <memory.h>
#include <cstdlib>

using namespace std;

// 인접행렬로 그래프 구현.
int adj[102][102];
// 방문 여부 확인.
bool visited[102] = {false};

void dfs(int num ,int len)
{
    visited[num] =true;
    for(int i=1;i<=len;i++)
    {
        // 연결되어있고 방문한적 없으면.
        if(adj[num][i]==1 && !visited[i])
        {
            dfs(i,len);
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 2e9;
    for(int i=0;i<wires.size();i++)
    {
        adj[wires[i][0]][wires[i][1]] = 1;
        adj[wires[i][1]][wires[i][0]] = 1;
    }
    // 하나씩 간선을 끊어보고 dfs
    for(int i=0;i<wires.size();i++)
    {
        adj[wires[i][0]][wires[i][1]] = 0;
        adj[wires[i][1]][wires[i][0]] = 0;
        dfs(1, n); // 1번 노드에서 dfs.
        // 1번으로 묶인 트리 사이즈 계산.
        int cnt = 0;
        for(int i=1;i<=n;i++)
        {
            if(visited[i])
                cnt++;
        }
        answer = min(abs(int((cnt-(n-cnt)))),answer);
        adj[wires[i][0]][wires[i][1]] = 1;
        adj[wires[i][1]][wires[i][0]] = 1;
        // 다음 dfs를 위해 초기화.
        memset(visited,false,sizeof(visited));
    }
    
    return answer;
}