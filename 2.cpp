#include <bits/stdc++.h>
#include <algorithm>

#define ll long long
#define x first
#define y second

using namespace std;

int n, m;
char c[20];

bool check(vector<char> c){
    bool a=0, b = 0;
    int cnt = 0;
    for(int i=0; i<n; ++i) {
        bool tmp = (c[i]=='a' || c[i]=='e'|| c[i]=='i'|| c[i]=='o'|| c[i]=='u');
        a = a || tmp;
        if(!tmp) ++cnt;
    }
    b = (cnt>=2);
    return a && b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<m; ++i) cin >> c[i];
    sort(c, c+m);

    vector<int> v(m,1);
    for(int i=0; i<n; ++i) v[i] = 0;

    vector<char> tmp;

    do{
        tmp.clear();
        for(int i=0; i<m; ++i) if(!v[i]) tmp.push_back(c[i]);
        if(check(tmp)) {
            for(char ch : tmp) cout << ch;
            cout << "\n";
        }
    }while(next_permutation(v.begin(), v.end()));


}
