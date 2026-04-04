#include <bits/stdc++.h>
#include <algorithm>
#define x first
#define y second
#define ll long long

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, arr[80005];
    ll cnt = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    stack<pair<int,int>> s;

    for(int i=0; i<n; i++){
        while(!s.empty() && s.top().y <= arr[i]) s.pop();
        cnt += s.size();
        s.push({i,arr[i]});
    }
    cout << cnt;
}