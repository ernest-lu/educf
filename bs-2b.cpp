#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
#define FOR(i, n) for(int i = 1; i<=n; i++)
#define F0R(i, n) for(int i = 0; i<n; i++)
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
const LD eek = 1e-7;
LL n, k, a[100005], cans = 0;

bool valid(LL g){
	if(g == 0) return 1;
	LL pc = 0;
	FOR(i, n)
		pc += (a[i]/g);
	return (pc >= k);
}

bool vl2(LL g){
	if(g == 0) return 1;
	LL pc = 0;
	FOR(i, n){
		pc += floor((LD)a[i]/((LD)cans + eek * (LD)g));
	} return (pc >= k);
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> k;
	FOR(i, n)
		cin >> a[i];

	LL l = 0, r = 1e7, mid;
	while(l < r){
		mid = (l + r + 1)/2;
		if(valid(mid)) l = mid;
		else r = mid-1;
	}

	cans = l;
	l = 0, r = 1e7, mid;
	while(l < r){
		mid = (l + r + 1)/2;
		if(vl2(mid)) l = mid;
		else r = mid-1;
	}

	cout << fixed << setprecision(8);
	cout << (LD)cans + ((LD)eek * l) << endl;

	cout.flush();
	return 0;
}