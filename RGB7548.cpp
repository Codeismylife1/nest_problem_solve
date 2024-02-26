#include <iostream>
#include <iomanip>
using namespace std;

int main() {
int n;
cin >> n;
int a[n][n];
int num = 1;
int i = 0, j = 0;
int x = 0, y = n - 1;

while (num <= n * n) {
    a[i][j] = num;

    if (i == x && j < y) {
        j++;
    } else if (j == y && i < y) {
        i++;
    } else if (i == y && j > x) {
        j--;
    } else if (j == x && i > x + 1) {
        i--;
    } else {
        x++;
        y--;
        i = x;
        j = x;
    }

    num++;
}

for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
        cout << setw(3) << a[i][j];
    }
    cout << endl;
}

return 0;
}
