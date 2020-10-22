#include <string>
#include <vector>
#include <algorithm>

#define PILLAR  0
#define BEAM    1
#define REMOVE  0
#define INSTALL 1

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    return a[0] == b[0] ? (a[1] == b[1] ? a[2] < b[2] : a[1] < b[1]) : a[0] < b[0];                     //  0. 사용자 정의 함수
}                                                                                                       //     삼항연산자로 x, y, 종류 순으로 비교하도록 set

bool isOk(int x, int y, vector<vector<int>> answer) {                                                   //  0. 구조물 확인 함수
    vector<int> temp1, temp2, temp3, temp4;                                                             //     작업한 구조물이 영향을 끼치는 합집합 범위만 확인
                                                                                                        //     구조물의 영향력은 설치한 위치를 중심으로 한칸 더
    for (vector<int> stuff : answer) {
        if(stuff[0] < x -1 || stuff[0] > x + 1 || stuff[1] < y -1 || stuff[1] > y + 1)  continue;       //     유효범위 밖의 것은 확인할 필요가 없음(채점 속도 감소)
        
        if (stuff[2] == BEAM) {                                                                         //  0. 보가 존재할 수 있는 조건
            temp1 = { stuff[0],     stuff[1] - 1, PILLAR };                                             //     조건 1 : 보의 좌측 하단에 기둥 존재
            temp2 = { stuff[0] + 1, stuff[1] - 1, PILLAR };                                             //     조건 2 : 보의 우측 하단에 기둥 존재
            temp3 = { stuff[0] - 1, stuff[1],     BEAM };                                               //     조건 3 : 보를 잇는 보가 양측에 존재
            temp4 = { stuff[0] + 1, stuff[1],     BEAM };

            if (find(answer.begin(), answer.end(), temp3) != answer.end() && 
                find(answer.begin(), answer.end(), temp4) != answer.end())              continue;
            if (find(answer.begin(), answer.end(), temp1) != answer.end())              continue;
            if (find(answer.begin(), answer.end(), temp2) != answer.end())              continue;
        }
        else {                                                                                          //  0. 기둥이 존재할 수 있는 조건 
            temp1 = { stuff[0],     stuff[1] - 1, PILLAR };                                             //     조건 1 : 기둥 하단에 기둥 존재
            temp2 = { stuff[0] - 1, stuff[1],     BEAM };                                               //     조건 2 : 기둥 좌측에 보 존재
            temp3 = { stuff[0],     stuff[1],     BEAM };                                               //     조건 3 : 기둥 우측에 보 존재

            if (!stuff[1])                                                              continue;
            if (find(answer.begin(), answer.end(), temp1) != answer.end())              continue;
            if (find(answer.begin(), answer.end(), temp2) != answer.end())              continue;
            if (find(answer.begin(), answer.end(), temp3) != answer.end())              continue;
        }
        
        return false;                                                                                   //    맞는 조건이 하나라도 없을 경우 부적합
    }

    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    vector<int> stuff;

    for (vector<int> v : build_frame) {                                                                 //  1. 각 로봇 동작마다 진행
        stuff = { v[0], v[1], v[2] };

        if (v[3] == INSTALL)        answer.push_back(stuff);                                            //  2. 명령에 따라 우선 설치 또는 제거 진행
        else                        answer.erase(find(answer.begin(), answer.end(), stuff));            

        if (!isOk(v[0], v[1], answer)) {                                                                //  3. 확인 후 이상 시
            if (v[3] == INSTALL)    answer.pop_back();                                                  //     설치했던 것을 제거
            else                    answer.push_back(stuff);                                            //     제거했던 것을 복구(재설치)
        }
    }

    sort(answer.begin(), answer.end(), compare);                                                        //  4. 구조물을 사용자 정의 함수를 이용하여 정렬

    return answer;
}
