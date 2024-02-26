#include <iostream>
using namespace std;

bool is_lucky(int n) {
    while (n > 0) {
        int digit = n % 10;
        if (digit != 4 && digit != 7) {
            return false;
        }
        n /= 10;
    }
    return true;
}

bool is_almost_lucky(int n) {
    for (int i = 4; i <= n; i++) {
        if (is_lucky(i) && n % i == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    if (is_almost_lucky(n)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}

