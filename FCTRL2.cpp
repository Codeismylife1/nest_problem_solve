#include <iostream>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        long long fact = 1; // use long long to avoid integer overflow
        for(int i=2; i<=n; i++) {
            fact *= i;
        }
        cout << fact << endl;
    }
    return 0;
}


