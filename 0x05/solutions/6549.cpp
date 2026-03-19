// Authored by : haneulkimdev
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/d98aedfde0e444509de83f1a21c8ef7e
#include <bits/stdc++.h>
#include <algorithm>

#define ll long long
#define x first
#define y second

using namespace std;

void print(stack<pair<int,int>> s){
    while (!s.empty()){
        cout << s.top().x << ' ' << s.top().y << '|';
        s.pop();
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(true){
        int n;
        cin >> n;
        if (!n) break;
        stack<pair<int,int>> s; // (높이, 해당 높이가 최초로 등장한 위치), 높이에 대한 monotone stack(오름차순 스택)으로 관리
        ll ans = 0;

        for(int i=0; i<n; i++){
            int h;
            cin >>h;
            int idx = i; //해당 높이가 최초로 등장한 위치

            while (!s.empty()&&s.top().x >= h){
                ans = max(ans, 1LL * (i-s.top().y)*s.top().x);
                idx = s.top().y;
                s.pop();
            }
            s.push({h, idx});
            print(s);
        }
        while (!s.empty()){
            ans = max(ans, 1LL * (n-s.top().y)*s.top().x);
            s.pop();
            print(s);
        }
        cout << ans << '\n';
    }

}

/*
스택에는 (높이, 해당 높이가 최초로 등장한 위치)가 저장된다. 기본적으로 스택은
높이에 대한 monotone stack으로 관리된다. 스택에서 pop이 발생할 때 마다 현재
스택의 top을 가지고 만들 수 있는 직사각형의 넓이를 계산할 수 있다.
long long으로의 형변환을 편하게 처리하기 위해 1LL을 매번 곱했고, 그냥 스택
자체를 pair<long long, long long>으로 선언해도 크게 상관 없다.
*/
