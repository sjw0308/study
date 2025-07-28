#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int a, arr[100], b, cnt = 0;
    cin >> a;
    for (int i = 0; i < a; i++){
        cin >> arr[i];
    }
    cin >> b;
    for (int i = 0; i < a; i++){
        if (arr[i] == b) cnt++;
    }

    cout << cnt << endl;

    return 0;
}