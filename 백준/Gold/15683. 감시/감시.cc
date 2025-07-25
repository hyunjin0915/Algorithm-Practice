#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[8][8];
vector<tuple<int,int,int>> cctvs;
int ans = 1e9;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = { 0, 1, 0,-1};


int direction[6][4][4] = {
    {{-1,-1,-1,-1},{-1,-1,-1,-1},{-1,-1,-1,-1},{-1,-1,-1,-1}}, 
    {{0,-1,-1,-1}, {1,-1,-1,-1}, {2,-1,-1,-1}, {3,-1,-1,-1}},
    {{0,2,-1,-1}, {1,3,-1,-1}, {-1,-1,-1,-1}, {-1,-1,-1,-1}},
    {{0,1,-1,-1}, {1,2,-1,-1}, {2,3,-1,-1}, {3,0,-1,-1}},
    {{0,1,2,-1}, {1,2,3,-1}, {2,3,0,-1}, {3,0,1,-1}},
    {{0,1,2,3}, {-1,-1,-1,-1}, {-1,-1,-1,-1}, {-1,-1,-1,-1}}
};

int cases[6] = {0, 4, 2, 4, 4, 1};

void watch(int x, int y, int dir, int temp[8][8]) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    while (0 <= nx && nx < N && 0 <= ny && ny < M) {
        if (temp[nx][ny] == 6) break;         
        if (temp[nx][ny] == 0) temp[nx][ny] = -1; 
        nx += dx[dir];
        ny += dy[dir];
    }
}

int countBlind(int temp[8][8]) {
    int cnt = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (temp[i][j] == 0) ++cnt;
    return cnt;
}

void DFS(int idx, int mp[8][8]) {
    if ((int)idx == (int)cctvs.size()) {
        ans = min(ans, countBlind(mp));
        return;
    }

    int x, y, t;
    tie(x, y, t) = cctvs[idx];

    for (int c = 0; c < cases[t]; ++c) {
        int temp[8][8];
        copy(&mp[0][0], &mp[0][0] + 8*8, &temp[0][0]);

        for (int k = 0; k < 4; ++k) {
            int dir = direction[t][c][k];
            if (dir == -1) break;
            watch(x, y, dir, temp);
        }
        DFS(idx + 1, temp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
            if (1 <= board[i][j] && board[i][j] <= 5)
                cctvs.emplace_back(i, j, board[i][j]);
        }
    }

    DFS(0, board);
    cout << ans << '\n';
    return 0;
}
