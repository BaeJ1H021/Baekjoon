#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long dp[110][110];
bool arr[110][110];
const long long MOD = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for(int i=0;i<puddles.size();i++)
    {
        arr[puddles[i][1]][puddles[i][0]] = true;
    }
    // 초기화
    dp[1][0] = 1;
    // 위에서부터 한줄씩 dp
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            // 안잠겼으면
            if(!arr[i][j])
                dp[i][j] = (dp[i][j-1]+dp[i-1][j])%MOD;
        }
    }
    answer = dp[n][m];
    return answer;
}