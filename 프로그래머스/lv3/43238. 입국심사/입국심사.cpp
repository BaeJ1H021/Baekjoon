#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    // 조건을 만족 시키는 시간을 이분탐색으로 최솟값을 리턴.
    long long max_time = *max_element(times.begin(), times.end()); // 가장 긴 심사 시간.
    long long left = 1;
    long long right = max_time* n;
    long long res = right;
    while(left<=right)
    {
        long long mid = (left+right)/2;
        // 심사 가능한지 체크
        long long cnt = 0;
        for(int i=0;i<times.size();i++)
        {
            cnt += mid/times[i];
        }  
        // mid 시간이면 모든 사람 심사가 가능하다면
        if(cnt >= n)
        {
            right = mid-1;
            res = min(mid,res);
        }
        // mid 시간이면 모든 사람 심사가 불가능하다면
        else
        {
            left = mid + 1;
        }
    }
    answer = res;
    return answer;
}