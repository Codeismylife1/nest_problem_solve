#include <iostream>
using namespace std;

int main() {
    int N, d, ans = 0;
    cin >> N >> d;
    int apple[N];
    for (int i = 0; i < N; i++) {
        cin >> apple[i];
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = i + 2; j < N; j++) {
            if (apple[j] - apple[i] <= d) {
                ans += j - i - 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

