#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    // i번 수포자 방식
    int method1[5] = {1,2,3,4,5};
    int method2[8] = {2,1,2,3,2,4,2,5};
    int method3[10] = {3,3,1,1,2,2,4,4,5,5};
    
    // i번 수포자의 점수
    int arr[4] = {0};
    for(int i=0;i<answers.size();i++)
    {
        if( answers[i] == method1[i%5] )
            arr[1]++;
        if(answers[i] == method2[i%8])
            arr[2]++;
        if(answers[i] == method3[i%10])
            arr[3]++;
    }
    int max_val = max(arr[1],max(arr[2],arr[3]));
    for(int i=1;i<=3;i++)
    {
        if(arr[i]==max_val)
            answer.push_back(i);
    }
    return answer;
}