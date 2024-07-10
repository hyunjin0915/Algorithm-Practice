#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define P pair<int,int>
using namespace std;
//[물품 수][무게]
int arr[101][100001];
int allweight[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k, w, v;
	cin >> n >> k;
	//(무게,가치)의 쌍을 담는 벡터 vv
	vector<P> vv;
	for (int i = 0; i < n; i++) {
		cin >> w >> v;
		vv.push_back(P(w, v));
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			int curweight = vv[i-1].first;
			int curval = vv[i-1].second;
			//현재 검토중인 짐을 담을 수 있는 경우(두 경우 중 최적의 경우 선정->max함수 사용)
			//1. 현재 짐을 넣지 않는다(바로 윗 칸의 값을 가져온다.) arr[i-1][j]
			//2. 현재 짐을 넣는다.arr[i-1][j-curweight]+curval
			if (curweight <= j) {
				arr[i][j] = max(arr[i - 1][j - curweight] + curval, arr[i - 1][j]);
			}
			//현재 검토중인 짐을 담을 수 없는 경우
			//바로 윗 칸의 값을 가져온다. arr[i-1][j]
			else {
				arr[i][j] = arr[i - 1][j];
			}
		}
	}
	cout << arr[n][k];

}