#include <bits/stdc++.h>
#include <algorithm>

#define ll long long
#define x first
#define y second

using namespace std;

// const int MX = 1505;
// int dx[4] = {1,0,-1,0};
// int dy[4] = {0,1,0,-1};
// int  b[MX][MX]; 
// bool vi[MX][MX];
// int n, m;

int vi[1000005];
// int d[2] = {1,-1};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, mx; 
    cin >> mx >> n;

    vector<int> start {};

    while(n--){
        int tmp;
        cin >> tmp;
        start.push_back(tmp);
    }

    fill(vi, vi+mx+2, -1);

    queue<int> q;
    for(auto e: start){
        vi[e] = 0;
        q.push(e);
    }

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int k{}; k<31; ++k){
            int next;
            if(cur & (1 << k)) next = cur & ~(1 << k);
            else next = cur | (1 << k);
            if(next > mx) continue;
            if(vi[next] >= 0) continue;
            vi[next] = vi[cur]  +1;
            q.push(next);
        }
    }

    int ans = 0;
    for(int i{}; i<=mx; ++i){
        ans = max(ans, vi[i]);
    }
    cout << ans;
    
}