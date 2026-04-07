#include <bits/stdc++.h>
#include <algorithm>

#define ll long long
#define x first
#define y second

using namespace std;

bool bo[7100][7100];

void func(int a, int b, int c, int d){
    if(c-a == 2){
        for(int i=0; i<5; ++i) bo[i+a][b] = 1;
        bo[c][d] = 1;
        bo[c-1][d+1] = 1;
        bo[c+1][d+1] = 1;
        return;
    }
    int h = (c-a)/2;
    func(a,b,a+h,b-h);
    func(a+h+1, b-h-1, c, d);
    func(c+1,b, 1+c+h, b-h);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
    cin >> n;
    func(0,n-1,n-1,0);

    for(int i=0; i<n; ++i){
        for(int j=0; j<n*2; ++j){
            if(bo[j][i]) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }
}
