#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Cow {
    int a, b;
};

bool cmp(const Cow& c1, const Cow& c2) {
    return c1.b < c2.b;
}

int main() {
    int n;
    cin >> n;
    vector<Cow> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i].a >> cows[i].b;
    }
    sort(cows.begin(), cows.end(), cmp);
    int count = 1;  // First cow is always safe
    int max_a = cows[0].a;
    for (int i = 1; i < n; i++) {
        if (cows[i].a > max_a) {
            count++;
            max_a = cows[i].a;
        }
    }
    cout << count << endl;
    return 0;
}

