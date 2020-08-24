#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define FOR(i, n) for(int i = 1; i<=n; i++)
#define F0R(i, n) for(int i = 0; i<n; i++)
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
int n, k, a[100005];

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> k;
	FOR(i, n)
		cin >> a[i];

	while(k--){
		int t1;
		cin >> t1;
		int l = 1, r = n, mid;
		while(l < r){
			mid = (l + r)/2;
			if(a[mid] >= t1) r = mid;
			else l = mid+1;
		}

		cout << ((a[l] == t1) ? "YES" : "NO") << endl;
	}

	cout.flush();
	return 0;
}