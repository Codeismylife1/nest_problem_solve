#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int count = 0;
    while (n != m) {
        if (m > n && m % 2 == 0) {
            m /= 2;
            count++;
        } else {
            n--;
            count++;
        }

        if (n < 0) {
            count = -1;
            break;
        }
    }

    cout << count << endl;

    return 0;
}

