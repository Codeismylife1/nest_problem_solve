#include <iostream>
#include <cstring>

using namespace std;

const int MAX_R = 200;
const int MAX_C = 200;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int r, c, n;
char grid[MAX_R][MAX_C];
bool bombs[MAX_R][MAX_C];
bool next_bombs[MAX_R][MAX_C];

void detonate(int x, int y) {
    bombs[x][y] = false;
    next_bombs[x][y] = false;
    for (int k = 0; k < 4; ++k) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
            bombs[nx][ny] = false;
            next_bombs[nx][ny] = false;
        }
    }
}

void update() {
    for (int x = 0; x < r; ++x) {
        for (int y = 0; y < c; ++y) {
            if (bombs[x][y]) {
                detonate(x, y);
            } else if (grid[x][y] == 'O') {
                bombs[x][y] = true;
            } else {
                next_bombs[x][y] = true;
            }
        }
    }
}

int main() {
    cin >> r >> c >> n;
    for (int x = 0; x < r; ++x) {
        cin >> grid[x];
        for (int y = 0; y < c; ++y) {
            bombs[x][y] = false;
            next_bombs[x][y] = false;
            if (grid[x][y] == 'O') {
                bombs[x][y] = true;
            }
        }
    }
    if (n == 1) {
        for (int x = 0; x < r; ++x) {
            cout << grid[x] << endl;
        }
        return 0;
    }
    if (n % 2 == 0) {
        memset(next_bombs, true, sizeof(next_bombs));
    }
    for (int t = 2; t <= min(n, 5); ++t) {
        update();
    }
    if (n <= 3) {
        for (int x = 0; x < r; ++x) {
            for (int y = 0; y < c; ++y) {
                cout << (next_bombs[x][y] ? 'O' : '.');
            }
            cout << endl;
        }
        return 0;
    }
    n -= 3;
    while (n >= 4) {
        memcpy(bombs, next_bombs, sizeof(bombs));
        update();
        n -= 4;
    }
    for (int t = 2; t <= n; ++t) {
        update();
    }
    for (int x = 0; x < r; ++x) {
        for (int y = 0; y < c; ++y) {
            cout << (bombs[x][y] ? '.' : 'O');
        }
        cout << endl;
    }
    return 0;
}

