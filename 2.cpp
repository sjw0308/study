#include <bits/stdc++.h>
#include <algorithm>

#define ll long long
#define x first
#define y second

using namespace std;

int n, m, o[10];
bool isused[10];

void func(int k, vector<int> arr){
    if(k==m){
        for(int i=0; i<m; ++i) cout << arr[o[i]] << ' ';
        cout << '\n';
        return;
    }
    for(int i=0; i<n; ++i){
        if(!isused[i]){
            o[k] = i;
            isused[i] = true;
            func(k+1, arr);
            isused[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<int> arr(n);
    for(int i=0; i<n; ++i) cin >> arr[i];
    sort(arr.begin(), arr.end());
    func(0,arr);
}
