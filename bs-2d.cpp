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
LL n, m, t[1005], y[1005], z[1005], amt[1005];

bool valid(LL g){
	LL cnt = 0;
	FOR(i, n) amt[i] = 0;
	FOR(i, n){
		LL cur = z[i] * (g / (t[i] * z[i] + y[i]));
		LL md = g % ((t[i] * z[i] + y[i]));
		if(md >= (t[i] * z[i])) cur += z[i];
		else cur += md/t[i];
		amt[i] = cur; cnt += cur;
	}

	if(cnt < m) return 0;
	LL rem = cnt-m;
	FOR(i, n){
		LL tmp = amt[i];
		amt[i] -= min(tmp, rem);
		rem -= min(tmp, rem);
	}

	return 1;
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> m >> n;
	FOR(i, n)
		cin >> t[i] >> z[i] >> y[i];

	LL l = 0, r = 1e9, mid;
	while(l < r){
		mid = (l + r)/2;
		if(valid(mid)) r = mid;
		else l = mid+1;
	}

	valid(l);
	cout << l << endl;
	FOR(i, n)
		cout << amt[i] << " ";
	cout << endl;

	cout.flush();
	return 0;
}