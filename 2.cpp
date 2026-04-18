#include <bits/stdc++.h>
#include <algorithm>

#define ll long long
#define x first
#define y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

using namespace std;

int n, m;
ll ans = LLONG_MAX;
vector<vector<int>> bo(55,vector<int>(55,0));
vector<pair<int,int>> chi, house;

ll calc(vector<int> v){
    ll ret = 0;
    for (auto h: house){
        int tmp=INT32_MAX;
        for(int i=0; i<(int)v.size(); ++i){
            if(v[i] == 0) tmp = min(tmp, abs(h.x-chi[i].x)+abs(h.y-chi[i].y));
        }
        ret += (ll)tmp;
    }
    return ret;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> bo[i][j];
            if(bo[i][j] == 1) house.push_back({i,j});
            if(bo[i][j] == 2) chi.push_back({i,j});
        }
    }
    vector<int> combi(chi.size(),1);
    for(int i=0; i<m; ++i) combi[i] = 0; // 0이면 살릴 치킨집
    do{
        ans = min(ans, calc(combi));
    }while(next_permutation(combi.begin(), combi.end()));
    cout << ans;
}
