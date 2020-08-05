#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second

struct nd{
	LL mx;
	LL mxl;
	LL mxr;
	LL su;
};

//var 
LL n, m, lz[400005], pis[400005];
nd tr[400005];

void psh(LL z, LL l, LL r){
	if(pis[z]){
		tr[z].mx = max((LL)0, (r-l+1) * (lz[z]));
		tr[z].mxr = max((LL)0, (r-l+1) * (lz[z]));
		tr[z].mxl = max((LL)0, (r-l+1) * (lz[z]));
		tr[z].su = (r-l+1) * (lz[z]);

		if(l!=r){
			lz[2*z] = lz[z]; pis[2*z] = 1;
			lz[2*z+1] = lz[z]; pis[2*z+1] = 1;
		}
	}

	lz[z] = 0; pis[z] = 0;
	return;
}

void upd(LL z, LL l, LL r, LL lb, LL rb, LL g){
	psh(z, l, r);
	if(l > rb || r < lb) return;
	if(l >= lb && r <= rb){
		lz[z] = g;
		pis[z] =  1;
		psh(z, l, r);
		//cout << l << " " << r << " " << tr[z].mx << endl;
		return;
	}

	LL mid = (l + r)/2;
	upd(2*z, l, mid, lb, rb, g);
	upd(2*z+1, mid+1, r, lb, rb, g);
	tr[z].mx = max(max(tr[2*z].mx, tr[2*z+1].mx), tr[2*z].mxr + tr[2*z+1].mxl);
	tr[z].mxl = max(tr[2*z].mxl, tr[2*z].su + tr[2*z+1].mxl);
	tr[z].mxr = max(tr[2*z+1].mxr, tr[2*z+1].su + tr[2*z].mxr);
	tr[z].su = tr[2*z].su + tr[2*z+1].su;
}

LL ge(){
	psh(1,1,n);
	return tr[1].mx;
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> m;
	while(m--){
		LL tt, l, r, v;
		cin >> l >> r >> v;
		upd(1,1,n,l+1,r,v);
		cout << ge() << endl;
	}

	cout.flush();
	return 0;
}