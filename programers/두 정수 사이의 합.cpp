#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(int a, int b) {
    return ((long long)(b+a) * (abs(b-a) + 1))/ 2;
}