#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    int a = 2 * n / (2 * n - m);
    int b = m * (a - 1) / (n - m);

    vector<int> ans;
    ans.push_back(a);
    ans.push_back(b);

    int curr = a + b - 1;
    while (curr < n) {
        ans.push_back(curr);
        curr += curr - ans[ans.size() - 2];
    }

    for (int i = 0; i < ans.size() - 1; i++) {
        cout << ans[i] << " ";
    }
    cout << ans[ans.size() - 1] << endl;

    return 0;
}

