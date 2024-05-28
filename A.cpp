#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fori(i, a, b) for(int i=a; i<b; i++)
#define ford(i, a, b) for(int i=a;i>=b; i--)

const int SIZE=100001;
int n, q, g;
int a[SIZE], b[1001];

int sum(int l, int r){
	int ans=0;
	for(int i=l; i<=r; ){
		if(i%g==0 && i+g<=r){
			ans+=b[i/g];
			i+=g;
		}
		else ans+=a[i++];
	}
	return ans;
}

signed main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for(g=1; g*g<n; g++);
	fori(i, 0, n){
		cin >> a[i];
		b[i/g]+=a[i];
	}
	while(q--){
		int l, r;
		cin >> l >> r;
		cout << sum(l-1, r-1) << endl;
	}
}
