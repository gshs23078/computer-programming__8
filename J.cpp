#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define int long long
#define endl '\n'
#define fori(i, a, b) for(int i=a; i<b; i++)
#define ford(i, a, b) for(int i=a;i>=b; i--)

int n, q;
const int SIZE=502;
int plane[SIZE][SIZE];
int sum[SIZE][SIZE];

void solve(){
	int a, b, c, d, w;
	cin >> a >> b >> c >> d >> w;
	plane[a][b]+=w;
	plane[a][d+1]-=w;
	plane[c+1][b]-=w;
	plane[c+1][d+1]+=w;
	return;
}

signed main(){
	cin >> n >> q;
	while(q--) solve();
	fori(i, 1, n+1) fori(j, 1, n+1)
		sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+plane[i][j];
	fori(i, 1, n+1){
		fori(j, 1, n+1)
			cout << sum[i][j] << ' ';
		cout << endl;
	}
}
