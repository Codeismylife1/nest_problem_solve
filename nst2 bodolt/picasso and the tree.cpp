#include <iostream>
using namespace std;

void print(char c, int times) {
    while (times--) {
        cout << c;
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        print('-', N - i - 1);
        print('*', 2 * i + 1);
        print('-', N - i - 1);
        cout << endl;
    }

    return 0;
}

