#include <bits/stdc++.h>
#include <algorithm>
#define x first
#define y second
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    ll cnt=0;

    stack<pair<ll, int>> s; //키, 키가 같은 사람이 쌓인 명수
    while(n--){
        ll tmp;
        cin >> tmp;
        while(!s.empty() && s.top().x<tmp) {
            cnt += s.top().y;
            s.pop();
        }
        if(s.empty()) 
            s.push({tmp,1});
        else if(s.top().x==tmp) {
            cnt += s.top().y;
            if(s.size()>1) ++cnt;
            ++s.top().y;
        }
        else {
            ++cnt;
            s.push({tmp, 1});
        }
    }
    cout << cnt;
}

/*
새로운 사람이 들어옴
1. 스택이 비어있다 = 첫번째 사람이다 cnt는 추가 없음
2. 스택의 top보다 작다 -> 스택의 top에 있는 사람만 볼 수 있음, cnt += 1하고 스택에 넣음
3. 스택의 top과 같다 -> 스택의 top에 쌓인 사람들 + 그 직전에 있는 사람 한명(만약 있다면) 까지 볼 수 있음
4. 스택의 top보다 크다 -> 스택을 pop하면서 top이 작아질때까지 cnt += top.y하고 1. 또는 2., 3. 을함
*/