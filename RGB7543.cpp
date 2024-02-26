#include <iostream>
using namespace std;

int main() {
int i, j, n, t = 1;
cin >> n;
int a[n][n];
for (i = 0; i < n; i++) {
    if (i % 2 != 0) {
        for (j = 0; j < n; j++) {
            a[i][j] = t;
            t++;
        }
    } else {
        for (j = n - 1; j >= 0; j--) {
            a[i][j] = t;
            t++;
        }
    }
}

for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
        cout << a[i][j] << " ";
    }
    cout << endl;
}

return 0;
}

