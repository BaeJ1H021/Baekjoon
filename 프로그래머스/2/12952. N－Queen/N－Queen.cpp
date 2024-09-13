#include <string>
#include <vector>

using namespace std;

bool visited[13];
int arr[13];
int ans = 0;

void dfs(int n, int y)
{
    // 대각선
    for(int i=0;i<y-1;i++)
    {
        if(abs(arr[y-1]-arr[i]) == y-1-i)
        {
            return;
        }
    }
    // 기저 사례
    if(y == n)
    {
        ans++;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            arr[y] = i; // y번째 세로줄에 가로 번호
            dfs(n, y+1);
            visited[i] = false;
        }
    }
}

int solution(int n) {
    int answer = 0;
    dfs(n, 0);
    answer = ans;
    return answer;
}