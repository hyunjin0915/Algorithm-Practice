#include <algorithm>
#include <iostream>

using namespace std;

bool arr[10001];

void isPrime() {
    arr[0] = false;
    arr[1] = false;

    for(int i=2;i*i<10000;i++)
    {
        if(!arr[i]) continue;
        for(int j=2*i;j<=10000;j+=i)
        {
            arr[j]=false;
        }
    }
}

int main() {
    int T;
    cin >> T;

    fill(arr, arr + 10000, true);
    isPrime();

    for (int i = 0; i < T; ++i) {
        int n;
        cin >> n;

        for (int k = 0; k < n/2; ++k) {
            if (arr[n / 2 - k] && arr[n / 2 + k]) {
                cout << n / 2 - k << " " << n / 2 + k <<endl;
                break;
            }
        }
    }

    return 0;
}