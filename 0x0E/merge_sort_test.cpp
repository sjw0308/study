#include <bits/stdc++.h>
using namespace std;

int n = 10;
int arr[1000001] = {15, 25, 22, 357, 16, 23, -53, 12, 46, 3};
int tmp[1000001]; // merge 함수에서 리스트 2개를 합친 결과를 임시로 저장하고 있을 변수

// mid = (st+en)/2라고 할 때 arr[st:mid], arr[mid:en]은 이미 정렬이 되어있는 상태일 때 arr[st:mid]와 arr[mid:en]을 합친다.
void merge(int st, int en){
  int mid = (st+en)/2;
  int p1 = st, p2 = mid;
  for(int i=0; i< en-st; ++i){
    if((p1<mid && arr[p1] <= arr[p2]) || p2 == en) tmp[i] = arr[p1++];
    else tmp[i] = arr[p2++];
  }
  for(int i=0; i< en-st; ++i) arr[i+st] = tmp[i];
}

// arr[st:en]을 정렬하고 싶다.
void merge_sort(int st, int en){
  if(st+1 == en) return;
  int mid = (st+en)/2;
  merge_sort(st, mid); // arr[st:mid]을 정렬한다.
  merge_sort(mid, en); // arr[mid:en]을 정렬한다.
  merge(st, en); // arr[st:mid]와 arr[mid:en]을 합친다.
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  merge_sort(0, n);
  bool cor = true;
  for(int i = 0; i < n-1; i++) if(arr[i] > arr[i+1]) cor = false;
  if(cor) cout << "CORRECT\n";
  // for(int i = 0; i < n; i++) cout << arr[i] << ' ';  // -53 3 12 15 16 22 23 25 46 357
}
