#include <bits/stdc++.h>
#define x first
#define y second
#define ll long long

using namespace std;

/*
(높이, 해당 높이가 최초로 등장한 위치) 로 오름차순 스택을 만듦
*/

int main(){
    while(true){
        int n;
        cin >> n;
        if(!n) return 0;
        ll ans = 0;
        stack<pair<ll, int>> s;
        for(int i=0; i<n; i++){
            ll tmp; cin >> tmp;
            int lidx = i;
            while(!s.empty() && s.top().x > tmp){
                ans = max(ans, (ll)s.top().x*(i-s.top().y));
                lidx = s.top().y;
                s.pop();
            }
            if(s.empty() || s.top().x < tmp) s.push({tmp, lidx});
        }
        while (!s.empty()){
            ans = max(ans, s.top().x*(ll)(n-s.top().y));
            s.pop();
        }
        cout << ans << '\n';
    }
}