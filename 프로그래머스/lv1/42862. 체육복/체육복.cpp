#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    // 잃어버렸는지 여부.
    bool losted[32] = {false};
    bool reserved[32] = {false};
    for(int i=0;i<lost.size();i++)
    {
        losted[lost[i]] = true;
    }
    for(int i=0;i<reserve.size();i++)
    {
        // 도난당한 학생이면 여분의 옷 없다고 처리한후 잃어버리지 않은 척.
        if(losted[reserve[i]])
            losted[reserve[i]] = false;   
        else
            reserved[reserve[i]] = true;
    }
    // 몇명 못 듣는지
    int cnt = 0;
    for(int i=1;i<=n;i++)
    {
        // 도난당한 경우
        if(losted[i])
        {
            // 먼저 전에 번호 학생이 빌려줄 수 있는지 체크.
            if(reserved[i-1])
            {
                reserved[i-1] = false;
            }
            // 전에 번호 학생 없으면 다음 번호 학생 체크.
            else if(reserved[i+1])
            {
                reserved[i+1] = false;
            }
            // 아무도 안 빌려주면 카운트
            else
            {
                cnt++;
            }
        }
    }
    answer = n-cnt;
    return answer;
}