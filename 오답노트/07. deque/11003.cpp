#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

void solution_dq();
void solution_pq();

void solution(int a){
    if(a) solution_pq();
    else solution_dq();
}

void solution_dq(){
    /*
    새로운 숫자가 deque내에서 가장 큰 값의 숫자이고 마지막에 위치하도록 합니다.
    deque안의의 숫자들은 오름차순 상태를 유지
    */

    deque<pair<int,int>> dq;
    int n, l;
    cin >> n >> l;
    for(int i=1; i<=n; i++){
        int tmp; cin >> tmp;
        while(!dq.empty() && dq.back().y>=tmp){
            dq.pop_back();
        }
        dq.push_back({i,tmp});
        while(dq.front().x < i-l+1) dq.pop_front();
        cout << dq.front().y << ' ';
    }

}

void solution_pq(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int n,l;
    cin >> n >> l;
    for(int i=1; i<=n; i++){
        int tmp; cin >> tmp;
        pq.push({tmp,i});
        while(pq.top().y < i-l+1) pq.pop();
        cout << pq.top().x << ' ';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    solution(1);
}