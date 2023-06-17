#include<iostream>
#include<algorithm>
#include<queue>
#include<memory.h>

using namespace std;

int arr[51][51];
int n, m;
int result = 2e9; //최소시간
int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };
// 퍼지는데 걸리는 시간.
int dist[51][51]; 

bool check()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // 빈칸이거나 바이러스를 놓을 수 있는 칸인데, 방문한 적이 없다면 전파 실패.
            if ( (arr[i][j] == 0 || arr[i][j] == 2) && dist[i][j] == -1)
            {
                return false;
            }
        }
    }
    return true;
}

void bfs()
{
    memset(dist, -1, sizeof(dist)); //거리배열 초기화.
    int max_val = 0; // 전체 다 퍼지는데 걸린 시간.
    queue<pair<int, int>> q;
    // 바이러스 큐에 넣어주기.
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j] == 3)
            {
                q.push({ i,j });
                dist[i][j] = 0;
            }
        }
    }
    while (!q.empty())
    {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = cur_y + dy[i];
            int nx = cur_x + dx[i];
            // 범위 out이거나 이미 방문한곳이면 패스.
            if (ny<1 || ny>n || nx<1 || nx>n || dist[ny][nx]!=-1)
                continue;
            // 빈칸이거나, 바이러스를 놓을 수 있는 칸인데 안놓은칸이면.
            if (arr[ny][nx] == 0 || arr[ny][nx]==2)
            {
                q.push({ ny,nx });
                dist[ny][nx] = dist[cur_y][cur_x] + 1;
                max_val = max(max_val, dist[ny][nx]);
            }
        }
    }

    // 바이러스가 다 퍼졌다면.
    if (check())
    {
        result = min(max_val, result);
    }
}

void set_virus(int y, int x,int cnt)
{
    // 바이러스 m개 넣었으면 bfs.
    if (cnt == m)
    {
        bfs();
        return;
    }
    for (int i = y; i <= n; i++)
    {
        for (int j = x; j <= n; j++)
        {
            // 바이러스 놓을 수 있는 칸이면.
            if (arr[i][j] == 2)
            {
                arr[i][j] = 3; //바이러스 놓았다는 표시.
                set_virus(i,j+1,cnt+1);
                arr[i][j] = 2; //백트래킹.
            }
        }
        // 다음줄부터는 1번째 인덱스부터 넣을 수 있도록.
        x = 1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }
    set_virus(1, 1, 0);
    if (result == 2e9)
        cout << -1;
    else
        cout << result;
    return 0;
}