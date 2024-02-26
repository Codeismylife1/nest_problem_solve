#include <iostream>
#include<vector>
using namespace std;

int main() {
	freopen("xxx.in","r",stdin);
	freopen("xxx.out","w",stdout);
    string N, M;
    int answer = 0;
 vector<int> pos;
    cin >> N >> M;

    N += N;

    for (int i = 0; i < N.length() / 2; i++) {
        string tmp = "";
        for (int j = i; j < i + M.length(); j++) {
            tmp += N[j];
        }

        if (tmp == M) {
            answer++;
            if (i > N.length() / 2) {
                pos.push_back(i - N.length() / 2);
            } else {
                pos.push_back(i);
            }
        }
    }

    if (answer == 0) {
        cout << -1 << endl;
        return 0;
    }

    cout << answer << endl;
    for (int i = 0; i < pos.size(); i++) {
        cout << pos[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}

