#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int nStyleA[5] = {1,2,3,4,5};
    int nStyleB[8] = {2,1,2,3,2,4,2,5};
    int nStyleC[10] = {3,3,1,1,2,2,4,4,5,5};
    
    int nCnt[3] = {0,0,0};
    int nIdx[3] = {0,0,0};
    
    for(int ans : answers){
        nCnt[0] = (ans == nStyleA[nIdx[0]++ % 5])  ? nCnt[0] + 1 : nCnt[0];
        nCnt[1] = (ans == nStyleB[nIdx[1]++ % 8])  ? nCnt[1] + 1 : nCnt[1];
        nCnt[2] = (ans == nStyleC[nIdx[2]++ % 10]) ? nCnt[2] + 1 : nCnt[2];
    }
    
    int nMax = -1;
    
    for(int i = 0; i<3; i++)
        nMax = (nCnt[i] > nMax) ? nCnt[i] : nMax;
    
    for(int i = 0; i<3; i++)
        if(nCnt[i] == nMax) answer.push_back(i+1);
    
    return answer;
}