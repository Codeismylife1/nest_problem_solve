#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n+1), b(n+1, 0), g(n+1, 0);

    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        if(p[i] != -1) {
            g[p[i]]++;
        }
    }

    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(g[i] == 0) {
            q.push(i);
            b[i] = 1;
        }
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        if(p[u] != -1) {
            b[p[u]] = max(b[p[u]], b[u] + 1);
            g[p[u]]--;
            if(g[p[u]] == 0) {
                q.push(p[u]);
            }
        }
    }

    cout << *max_element(b.begin(), b.end());

    return 0;
}

