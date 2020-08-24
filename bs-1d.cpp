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
int n, k, a[100005], fb, sb;

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n;
	FOR(i, n)
		cin >> a[i];

	sort(a+1, a+n+1);

	cin >> k;
	while(k--){
		int t1, t2;
		cin >> t1 >> t2;
		int l = 1, r = n, mid;
		while(l < r){
			mid = (l + r)/2;
			if(a[mid] >= t1) r = mid;
			else l = mid+1;
		}

		fb = l;

		if(a[l] < t1){
			cout << 0 << " ";
			continue;
		}

		l = 1, r = n, mid;
		while(l < r){
			mid = (l + r + 1)/2;
			if(a[mid] <= t2) l = mid;
			else r = mid-1;
		}

		sb = l;

		if(a[l] > t2){
			cout << 0 << " ";
			continue;
		}

		if(sb < fb){
			cout << 0 << " ";
			continue;
		}

		cout << (sb - fb + 1) << " ";
	}

	cout.flush();
	return 0;
}