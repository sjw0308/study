#include <bits/stdc++.h>
#include <algorithm>

#define ll long long
#define x first
#define y second

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int b[105][105];
bool vi[105][105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m,k,cnt=0;
    cin >> n >> m >> k;
    vector<int> re={};
    queue<pair<int,int>> q;
    for (int i=0; i<k; i++){
        int lx, ly, rx, ry;
        cin >> ly >> lx >> ry >> rx;
        for(int x=lx; x<rx; x++){
            for(int y=ly; y<ry; y++) b[x][y] = 1;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vi[i][j] && !b[i][j]){
                cnt++;
                vi[i][j] = 1;
                int s = 1;
                q.push({i,j});
                while(!q.empty()){
                    auto cur = q.front();
                    q.pop();
                    for(int dir=0; dir<4; dir++){
                        int nx = cur.x + dx[dir];
                        int ny = cur.y + dy[dir];
                        if(nx<0 || nx>=n || ny < 0|| ny>=m) continue;
                        if(vi[nx][ny] || b[nx][ny]) continue;
                        s++;
                        vi[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
                re.push_back(s);
            }
        }
    }
    cout << cnt << '\n';
    sort(re.begin(), re.end());
    for(int i: re) cout << i << ' ';
}