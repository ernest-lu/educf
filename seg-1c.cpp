#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 

LL n, m, tt;
pii tr[200005];

pii ge(int l, int r){
	pii le = mp(INT_MAX, 0), ri = mp(INT_MAX, 0);
	for(l += n, r += n; l<r; l/=2, r/=2){
		if(l%2){
			if(le.f == tr[l++].f) le = mp(tr[l-1].f, tr[l-1].s + le.s);
			else le = min(le,tr[l-1]);
		}
		if(r%2){
			if(ri.f == tr[--r].f) ri = mp(tr[r].f, tr[r].s + ri.s);
			else ri = min(ri,tr[r]);	
		} 
	} 

	if(le.f == ri.f)
		return mp(le.f, le.s + ri.s);
	return min(le, ri);
}

void upd(LL g, LL k){
	for(tr[g += n] = mp(k,1); g>1; g/=2){
		if(tr[g].f == tr[g^1].f) tr[g/2] = mp(tr[g].f, tr[g].s + tr[g^1].s);
		else tr[g/2] = min(tr[g], tr[g^1]);
	}
}


int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> m;
	for(LL i = 0; i<n; i++){
		cin >> tt;
		upd(i, tt);
	}

	while(m--){
		cin >> tt; tt--;
		if(tt){
			LL l,r; cin >> l >> r; pii gg = ge(l, r);
			cout << gg.f << " " << gg.s << endl;
			continue;
		}
		LL g, k;
		cin >> g >> k;
		upd(g, k);
	}


	cout.flush();
	return 0;
}