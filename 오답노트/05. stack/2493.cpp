#include <bits/stdc++.h>
#include <algorithm>
#define x first
#define y second
#define ll longlong


using namespace std;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int arr[500005], n;
    stack<pair<int,int>> s;
    arr[0] = 100'000'005;
    s.push({0,arr[0]});
    cin >> n;
    for(int i=1; i<=n; i++) cin >> arr[i];


    for(int i=1; i<=n; i++){
        while(s.top().y < arr[i]) s.pop();
        cout << s.top().x << ' ';
        s.push({i,arr[i]});
    }

}