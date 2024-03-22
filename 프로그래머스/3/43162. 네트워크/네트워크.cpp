#include <string>
#include <vector>
#include <iostream>

using namespace std;

int parent[210];
bool visited[210];

int Find(int x)
{
    if(parent[x]==x)
        return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x!=y)
    {
        if(x<y)
            parent[y] = x;
        else
            parent[x] = y;
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    // 초기화
    for(int i=0;i<n;i++)
        parent[i] = i;
    // Union
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(computers[i][j] == 1)
            {
                Union(i,j);
            }
        }
    }
    // 정답 출력
    for(int i=0;i<n;i++)
    {
        int root = Find(i);
        if(!visited[root])
        {
            answer++;
            visited[root] = true;
        }
    }
    return answer;
}