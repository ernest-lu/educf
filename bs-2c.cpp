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
LL n, x, y;

bool valid(LL g){
	LL ans = (g/x) + (((g-x)/y));
	return ans>=n;
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> x >> y; 
	if(x > y) swap(x, y);

	LL l = x, r = 2e10, mid;
	while(l < r){
		mid = (l + r)/2;
		if(valid(mid)) r = mid;
		else l = mid+1;
	}

	cout << l << endl;


	cout.flush();
	return 0;
}