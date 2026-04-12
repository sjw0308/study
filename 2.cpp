#include <bits/stdc++.h>
#include <algorithm>

#define ll long long
#define x first
#define y second
int d1[4] = {0,0,1,1};
int d2[4] = {2,3,2,3};

using namespace std;

const int MX = 1005;
int n, m, ans = MX;
vector<pair<int,int>> v;

void print(vector<vector<int>>& bo){
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j) cout << bo[i][j] << ' ';
        cout <<'\n';
    }
    cout << '\n';
}

int cnt_none(vector<vector<int>>& bo){
    // print(bo);
    int cnt=0;
    for(int i=0; i<n; i++)
    for(int j=0; j<m; ++j) if(bo[i][j] == 0) ++cnt;
    return cnt;
}

void watch(vector<vector<int>>& bo, int i, int j, int dir){//dir = 0(+i), 1(-i), 2(+j), 3(-j)
    if(dir == 0){
        int nx = i+1;
        while(nx<n && bo[nx][j] != 6) {
            if(bo[nx][j] == 0) bo[nx][j] = -1;
            ++nx;
        }
        return;
    }
    if(dir == 1){
        int nx = i-1;
        while(nx>=0 && bo[nx][j] != 6) {
            if(bo[nx][j] == 0)bo[nx][j] = -1;
            --nx;
        }
        return;
    }
    if(dir == 2){
        int nx = j+1;
        while(nx<m && bo[i][nx] != 6) {
            if(bo[i][nx] == 0) bo[i][nx] = -1;
            ++nx;
        }
        return;
    }
    if(dir == 3){
        int nx = j-1;
        while(nx>=0 && bo[i][nx] != 6) {
            if(bo[i][nx] == 0) bo[i][nx] = -1;
            --nx;
        }
        return;
    }
}

void run(vector<vector<int>>& bo, int k){
    if(k == v.size()){
        ans = min(cnt_none(bo), ans);
        return;
    }
    vector<vector<int>> aft;
    auto cur = v[k];
    int tmp = bo[cur.x][cur.y];
    if(tmp == 1){
        for(int dir=0; dir<4; ++dir){
            aft = bo;
            watch(aft, cur.x, cur.y, dir);
            run(aft, k+1);
        }
    }
    if(tmp == 2){
        for(int dir=0; dir<2; ++dir){
            aft = bo;
            watch(aft, cur.x, cur.y, 2*dir);
            watch(aft, cur.x, cur.y, 2*dir+1);
            run(aft, k+1);
        }
    }
    if(tmp == 3){
        for(int dir=0; dir<4; ++dir){
            aft = bo;
            watch(aft, cur.x, cur.y, d1[dir]);
            watch(aft, cur.x, cur.y, d2[dir]);
            run(aft, k+1);
        }
    }
    if(tmp == 4){
        for(int dir=0; dir<4; ++dir){
            aft = bo;
            watch(aft, cur.x, cur.y, dir);
            watch(aft, cur.x, cur.y, (dir+1)%4);
            watch(aft, cur.x, cur.y, (dir+2)%4);
            run(aft, k+1);
        }
    }
    if(tmp == 5){
        aft = bo;
        watch(aft, cur.x, cur.y, 0);
        watch(aft, cur.x, cur.y, 1);
        watch(aft, cur.x, cur.y, 2);
        watch(aft, cur.x, cur.y, 3);
        run(aft, k+1);
    }
    
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<vector<int>> bo(9,vector<int>(9));
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j) {
            int tmp;
            cin >> tmp; bo[i][j] = tmp;
            if(tmp!=0 && tmp!=6) v.push_back({i,j}); 
        }
    }
    run(bo, 0);
    cout << ans;
    
}
