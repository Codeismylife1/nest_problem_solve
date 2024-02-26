#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "N тоо: ";
    cin >> N;

    int max_divisor = 0;
    for (int i = 1; i < N; ++i) {
        if (N % i == 0) {
            max_divisor = i;
        }
    }

    cout << "Хамгийн их хуваагч: " << max_divisor << endl;
    return 0;
}

