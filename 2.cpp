#include <bits/stdc++.h>
#include <algorithm>

#define ll long long
#define x first
#define y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

using namespace std;

int n, m;
const int mod = 123456789;
ll dp[63];

void print(){
    for (int i=0; i<n; ++i) cout << dp[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    dp[1] = 1;
    dp[2] = 1;
    if(n<3){
        cout << dp[n];
        return 0;
    }
    for(int i=3; i<=n; ++i){
        dp[i] = 1;
        for(int j=1; j<=i-2; ++j) dp[i] += 2*dp[j];
    }
    cout << dp[n];
}
