#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2, ans;
    cin >> s1 >> s2;
    int n = s1.length();
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            ans += '1';
        } else {
            ans += '0';
        }
    }
    cout << ans << endl;
    return 0;
}

