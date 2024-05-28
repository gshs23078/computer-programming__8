#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
#define int long long
#define endl '\n'
#define fori(i, a, b) for(int i=a; i<b; i++)
#define ford(i, a, b) for(int i=a;i>=b; i--)

const int SIZE=(int)1e5+1;
int n, k;
pair<int, int> arr[SIZE];
vector<int> ans;

signed main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	fori(i, 0, n) cin >> arr[i].first >> arr[i].second;
	sort(arr, arr+n);
	int l=0;
	fori(i, 0, n){
		if(ans.empty()){
			ans.push_back(arr[i].second);
			l++;
			continue;
		}
		if(ans[l-1]<=arr[i].second){
			ans.push_back(arr[i].second);
			l++;
			continue;
		}
		int start=1, end=l;
		while(start!=end){
			int mid=(start+end)/2;
			if(ans[mid-1]<arr[i].second)
				start=mid+1;
			else end=mid;
		}
		ans[start-1]=arr[i].second;
	}
	cout << n-l;
}
