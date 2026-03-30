#include <bits/stdc++.h>
#include <algorithm>

#define ll long long
#define x first
#define y second

using namespace std;

// int dx[4] = {1,0,-1,0};
// int dy[4] = {0,1,0,-1};
// int b[105][105];
// int vi[105][105];

int b[100005];
int vi[200005];
int d[] = {1,-1};
int n, m;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin >> n >> k;
    deque<int> dq;
    fill(vi,vi+200005,-1);
    if(k<=n) {
        cout << n-k;
        return 0;
    }
    vi[n] = 0;
    dq.push_back(n);
    while(!dq.empty()){
        int cur = dq.front();
        if (cur == k) break;
        dq.pop_back();
        int nx;
        for(int i =0;i<2;i++){
            nx = cur + d[i];
            if(nx <0 || nx>=200005) continue;
            if(vi[nx]!=-1) continue;
            vi[nx] = vi[cur]+1;
            dq.push_back(nx);
        }
        nx = cur * 2;
        if(nx < 0 || nx >= 200005) continue;
        if(vi[nx] != -1) continue;
        vi[nx] = vi[cur];
        dq.push_front(nx);
    }
    cout << vi[k];

}