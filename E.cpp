#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fori(i, a, b) for(int i=a; i<b; i++)
#define ford(i, a, b) for(int i=a;i>=b; i--)

const int SIZE=(int)1e5+1;
int arr[SIZE], segtree[SIZE*4], a[SIZE];
int n;

int update(int node, int start, int end, int idx, int v){
	if(start>idx || end<idx)
		return segtree[node];
	if(start==end){
		arr[idx]=v;
		return segtree[node]=v;
	}
	int mid=(start+end)/2;
	return segtree[node]
	=update(node*2, start, mid, idx, v)
	+update(node*2+1, mid+1, end, idx, v);
}

int sum(int node, int start, int end, int left, int right){
	if(start>right || end<left)
		return 0;
	if(start>=left && end<=right)
		return segtree[node];
	int mid=(start+end)/2;
	return sum(node*2, start, mid, left, right)+sum(node*2+1, mid+1, end, left, right);
}

signed main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int cnt=0;
	cin >> n;
	fori(i, 1, n+1) cin >> a[i];
	fori(i, 1, n+1){
		update(1, 1, SIZE-1, a[i], arr[a[i]]+1);
		cnt+=sum(1, 1, SIZE-1, a[i]+1, SIZE-1);
	}
	cout << cnt;
}
