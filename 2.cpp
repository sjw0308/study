#include <bits/stdc++.h>
#include <algorithm>

#define ll long long
#define x first
#define y second

using namespace std;

int b[200005];
int dx[2] = {1,-1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    if (n >= m) {
        cout << n - m;
        return 0;
    }
    fill(b, b+200005, -1);
    b[n] = 0;
    queue<int> q;
    q.push(n);
    while(b[m] == -1){
        int cur = q.front();
        q.pop();
        for(int dir = 0; dir < 2; dir++){
            int nx = cur + dx[dir];
            if (nx < 0 || nx > 2*m) continue;
            if (b[nx] != -1)continue;
            b[nx] = b[cur] + 1;
            q.push(nx);
        }
        int nx = 2*cur;
        if (nx < 0 || nx > 2*m) continue;
        if (b[nx] != -1)continue;
        b[nx] = b[cur] + 1;
        q.push(nx);
    }
    cout << b[m];
}