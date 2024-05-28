#include <iostream>
#include <vector>
using namespace std;
#define int long long
#define endl '\n'
#define fori(i, a, b) for(int i=a; i<b; i++)
#define ford(i, a, b) for(int i=a;i>=b; i--)

int n, q;
const int SIZE=(int)1e5+2;
int arr[SIZE], sum[SIZE];

void snow(){
	int a, b, w;
	cin >> a >> b >> w;
	arr[b+1]-=w;
	arr[a]+=w;
}

signed main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> q;
	while(q--) snow();
	fori(i, 1, n+1) sum[i]=sum[i-1]+arr[i];
	fori(i, 1, n+1) cout << sum[i] << ' ';
}
