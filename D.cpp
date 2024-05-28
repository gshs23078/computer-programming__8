#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define int long long
#define endl '\n'
#define fori(i, a, b) for(int i=a; i<b; i++)
#define ford(i, a, b) for(int i=a;i>=b; i--)

// 1 based

const int SIZE=(int)1e5+2;
int arr[SIZE], segtree[4*SIZE];
int student[3*SIZE];
int n, q;

int setseg(int node, int start, int end){
	if(start==end)
		return segtree[node]=arr[start];
	int mid=(start+end)/2;
	return segtree[node]
	=setseg(node*2, start, mid)
	+setseg(node*2+1, mid+1, end);
}

int update(int node, int start, int end, int idx, int v){
	if(start>idx || end<idx) return segtree[node];
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
	if(start>right || end<left) return 0;
	if(start>=left && end<=right)
		return segtree[node];
	int mid=(start+end)/2;
	return sum(node*2, start, mid, left, right)+sum(node*2+1, mid+1, end, left, right);
}

signed main(){
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	fori(i, 1, n+1){
		int a, b;
		scanf("%lld.%lld", &a, &b);
		student[i]=a*100+b;
		arr[a*100+b]++;
	}
	cin >> q;
	setseg(1, 1, SIZE-1);
	while(q--){
		int query;
		cin >> query;
		if(query==1){
			int a;
			cin >> a;
			cout << sum(1, 1, SIZE-1, student[a]+1, SIZE-1)+1 << endl;
		}
		else{
			int a, b, idx;
			cin >> idx;
			scanf("%lld.%lld", &a, &b);
			update(1, 1, SIZE-1, student[idx], arr[student[idx]]-1);
			student[idx]=a*100+b;
			update(1, 1, SIZE-1, student[idx], arr[student[idx]]+1);
		}
	}
}
