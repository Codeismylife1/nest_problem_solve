#include <iostream>
using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a > b ? b : a;
}

int main() {
    int N, M,MAX,MIN;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int MAX, MIN, tmp;
        cin >> tmp;
        MAX = MIN = tmp;
        for (int j = 1; j < M; j++) {
            cin >> tmp;
            MAX = max(MAX, tmp);
            MIN = min(MIN, tmp);
        }
        cout << MAX - MIN << endl;
    }
    
    return 0;
}

