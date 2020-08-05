#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL n, m, tr[400001], lz[400001], INF = 1e18, MOD = 1e9+7;

void psh(LL z, LL l, LL r){
	tr[z] *= lz[z];
	tr[z] %= MOD;
	if(l != r){
		lz[2*z] *= lz[z];
		lz[2*z] %= MOD;
		lz[2*z+1] *= lz[z];
		lz[2*z+1] %= MOD;
	}
	lz[z] = 1;
	return;
}

void upd(LL z, LL l, LL r, LL lb, LL rb, LL g){
	psh(z, l, r);
	if(l > rb || r < lb) return;
	if(l >= lb && r <= rb){
		lz[z] *= g;
		lz[z] %= MOD;
		psh(z, l, r);
		return;
	}
	LL mid = (l + r)/2;
	upd(2*z, l, mid, lb, rb, g);
	upd(2*z+1, mid+1, r, lb, rb, g);
	tr[z] = tr[2*z] + tr[2*z+1];
	tr[z] %= MOD;
}

LL ge(LL z, LL l, LL r, LL lb, LL rb){
	psh(z, l, r);
	if(l > rb || r < lb) return 0;
	if(l >= lb && r <= rb)
		return tr[z];
	LL mid = (l + r)/2;
	return ((ge(2*z, l, mid, lb, rb)+ge(2*z+1, mid+1, r, lb, rb))%MOD);
	tr[z] = tr[2*z] + tr[2*z+1];
	tr[z] %= MOD;
}

void bld(LL z, LL l, LL r){
	lz[z] = 1;
	if(l == r){
		tr[z] = 1;
		return;
	}
	LL mid = (l+r)/2;
	bld(2*z, l, mid);
	bld(2*z+1, mid+1, r);
	tr[z] = (tr[2*z] + tr[2*z+1])%MOD;
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> m; 
	bld(1,1,n);
	while(m--){
		LL tt, l, r, v;
		cin >> tt >> l >> r;
		if(tt == 1){
			cin >> v;
			upd(1,1,n, l+1, r, v);
			continue;
		}
		cout << ge(1, 1, n, l+1, r) << endl;
	}

	cout.flush();
	return 0;
}