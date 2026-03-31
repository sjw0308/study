#include <bits/stdc++.h>
#include <algorithm>

#define ll long long
#define x first
#define y second

using namespace std;

// int dx[4] = {1,0,-1,0};
// int dy[4] = {0,1,0,-1};
// int  b[205][205];
// int vi[205][205][31];
// int n, m;

int vi[2][200005];
int d[2] = {1,-1};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,k;
    cin >> n >> k;
    if (k <= n){
        cout << n-k << '\n';
        for(int i=n; i>=k; i--) cout << i << ' ';
        return 0;
    }
    fill(vi[1], vi[1]+200005, -1);
    fill(vi[0], vi[0]+200005, -1);
    vi[0][n] = 0;
    vi[1][n] = 0;
    queue<int> q;
    q.push(n);
    int find = 0;
    while(!q.empty()){
        if(find) break;
        int cur = q.front();
        q.pop();
        int nx;
        for(int dir=0; dir<2; dir++){
            nx = cur + d[dir];
            if(nx < 0 || nx > 200001) continue;
            if(vi[0][nx] > -1) continue;
            vi[0][nx] = vi[0][cur]+1;
            vi[1][nx] = cur;
            if(nx == k){
                find = 1;
                break;
            }
            q.push(nx);
        }
        nx = 2*cur;
        if(nx < 0 || nx > 200001) continue;
        if(vi[0][nx] > -1) continue;
        vi[0][nx] = vi[0][cur]+1;
        vi[1][nx] = cur;
        if(nx == k){
            find = 1;
            break;
        }
        q.push(nx);
    }
    int cur = k;
    vector<int> ans;
    cout << vi[0][k] << '\n';
    while(cur != n){
        ans.push_back(cur);
        cur = vi[1][cur];
    }
    ans.push_back(n);
    for(int i = ans.size()-1; i >= 0; i--){
        cout << ans[i] << ' ';
    }
}