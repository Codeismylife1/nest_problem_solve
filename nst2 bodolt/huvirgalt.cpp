#include <iostream>
using namespace std;

int main() {
    int N, ans = 0;
    cin >> N;
    while (N != 1) {
        if (N % 2 == 0) {
            N /= 2;
        } else {
            N = 3 * N + 1;
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}

