#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "N ���: ";
    cin >> N;

    int max_divisor = 0;
    for (int i = 1; i < N; ++i) {
        if (N % i == 0) {
            max_divisor = i;
        }
    }

    cout << "������� �� �������: " << max_divisor << endl;
    return 0;
}

