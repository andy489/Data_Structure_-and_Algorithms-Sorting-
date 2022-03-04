#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<>> p;
    int n, m;
    cin >> n >> m;

    int c, a = 0;
    while (n--) {
        cin >> c;
        p.push(c);
    }

    while (!p.empty() && p.top() < m) {
        int o = p.top();
        p.pop();

        if (p.empty()) {
            cout << -1;
            return 0;
        }

        o += (2 * p.top());

        p.pop();
        p.push(o);

        ++a;
    }

    cout << a;

    return 0;
}