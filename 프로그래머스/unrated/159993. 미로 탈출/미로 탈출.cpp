#include <string>
#include <vector>
#include <iostream>
#include <memory.h>
#include <queue>

using namespace std;

char arr[102][102];
int dist[102][102];

pair<int,int> s;
pair<int,int> l;
pair<int,int> e;

int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

int s_bfs(int n, int m)
{
    memset(dist,-1,sizeof(dist));
    queue<pair<int,int>> q;
    q.push({s.first,s.second});
    dist[s.first][s.second] = 0;
    while(!q.empty())
    {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();
        if(cur_y == l.first && cur_x == l.second)
        {
            return dist[cur_y][cur_x]; 
        }
        for(int i=0;i<4;i++)
        {
            int ny = cur_y + dy[i];
            int nx = cur_x + dx[i];
            if(ny<0 || ny> n-1 || nx<0 || nx>m-1 || arr[ny][nx] == 'X')
                continue;
            if(dist[ny][nx] == -1)
            {
                dist[ny][nx] = dist[cur_y][cur_x] + 1;
                q.push({ny,nx});
            }
            
        }
    }
    return -1;
}
int l_bfs(int n, int m)
{
    memset(dist,-1,sizeof(dist));
    queue<pair<int,int>> q;
    q.push({l.first,l.second});
    dist[l.first][l.second] = 0;
    while(!q.empty())
    {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();
        if(cur_y == e.first && cur_x == e.second)
        {
            return dist[cur_y][cur_x]; 
        }
        for(int i=0;i<4;i++)
        {
            int ny = cur_y + dy[i];
            int nx = cur_x + dx[i];
            if(ny<0 || ny> n-1 || nx<0 || nx>m-1 || arr[ny][nx] == 'X')
                continue;
            if(dist[ny][nx] == -1)
            {
                dist[ny][nx] = dist[cur_y][cur_x] + 1;
                q.push({ny,nx});
            }
            
        }
    }
    return -1;
}


int solution(vector<string> maps) {
    int answer = 0;
    for(int i=0;i<maps.size();i++)
    {
        for(int j=0;j<maps[i].size();j++)
        {
            arr[i][j] = maps[i][j];
            if(arr[i][j] == 'S')
                s = {i,j};
            else if(arr[i][j] == 'L')
                l = {i,j};
            else if(arr[i][j] == 'E')
                e = {i,j};
        }
    }
    int first = s_bfs(maps.size(),maps[0].size());
    int second = l_bfs(maps.size(),maps[0].size());
    // s->l , l->e 둘다 가능하면.
    if(first != -1 && second != -1)
    {
        answer = first+second;
    }
    else
    {
        answer = -1;
    }
    return answer;
}