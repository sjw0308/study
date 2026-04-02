#include <bits/stdc++.h>
#include <algorithm>

#define ll long long
#define x first
#define y second

using namespace std;

// int dx[4] = {1,0,-1,0};
// int dy[4] = {0,1,0,-1};
// int  b[105][105]; 
// int vi[105][105]; 
// int n, m;

int vi[2][500005];
int d[2] = {1,-1};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    queue<pair<int,int>> q;
    for (int i =0; i<2; i++) fill(vi[i], vi[i]+500004,-1);
    vi[0][n] = 0;
    q.push({n,0});
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        int time = cur.y + 1;
        for(int nx: {cur.x+1, cur.x-1, cur.x*2}){
            if(nx <0 || nx > 500000) continue;
            if(vi[time%2][nx] != -1) continue;
            vi[time%2][nx] = time;
            q.push({nx,time});
        }
    }

    int t=0, target = k;
    while(target<=500000){
        if(vi[t%2][target]<=t && vi[t%2][target]!=-1) {
            cout << t;
            return 0;
        }
        target += ++t;
    }
    cout << -1;

}