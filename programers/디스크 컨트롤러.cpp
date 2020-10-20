#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> v1, vector<int> v2){       // 소요시간 기준으로 정렬하기 위한 사용자 정의 함수  
   return v1[1] < v2[1];                            
}

int solution(vector<vector<int>> jobs) {             
    int now = 0;                                    // 현재 작업 시간
    int sum = 0;                                    // 각 작업의 "실제 소요시간"을 누적하여 저장
    int size = jobs.size();                         // input copy 없이 바로 정렬하여 진행하기 때문에 
                                                    // "총 작업량"을 기억

    sort(jobs.begin(), jobs.end(), compare);        // 1. "소요 시간"을 기준으로 오름차순 정렬
    
    while(jobs.size()){                             // 2. 모든 작업을 끝낼 때까지 진행
        auto it = jobs.begin();         
        
        while(it != jobs.end()){                    // 3. 작업 하나를 고르기 위해 완전 탐색
            if(it->at(0) <= now){                   // 4. 현재 작업 시간에 할 수 있거나(=) 
                now += it->at(1);                   //    이전에 누락된 것이 있으면 진행 
                sum += now - it->at(0);             //    실제 소요 시간 = 현재 작업 진행 완료 시간 - 현재 작업 요청 시간
                
                break;
            }
            
            it++;
        }

        if(it != jobs.end())    jobs.erase(it);     // 5. 진행한 작업은 스케쥴러에서 삭제
        else                    now++;              // 6. 현재 작업 시간까지 누적되거나 가능한 작업이 없으면 다음 시간으로 넘어감
    }

    return sum / size;                              // 7. 총 실제 소요 시간 / 총 작업량 반환
}