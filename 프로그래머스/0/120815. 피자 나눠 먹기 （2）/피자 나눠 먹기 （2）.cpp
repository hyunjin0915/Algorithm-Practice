#include <string>
#include <vector>
#include <numeric>

using namespace std;

// int gcd(int a, int b)
// {
//     return
    
//     else
//     {
//         gcd(b, a/b);
//     }
// }

int solution(int n) {
    int answer = 0;
    answer = ((n * 6)/gcd(n, 6)) / 6;
    return answer;
}



