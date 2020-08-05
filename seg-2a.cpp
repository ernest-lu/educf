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
LL n, m, gg, bb;
nd tr[400005], tmp;

void upd(int g, int b, int k, int l, int r){
	if(l <= g && g <= r){
		if(l == r){
			tr[k].mx = b;
			tr[k].mxl = b;
			tr[k].mxr = b;
			tr[k].su =  b;
			return;
		}
		int mid = (l + r)/2;
		upd(g, b, 2*k, l, mid);
		upd(g, b, 2*k+1, mid+1, r);
		tr[k].su = tr[2*k].su + tr[2*k+1].su;
		tr[k].mxl = max(tr[2*k].mxl, tr[2*k].su + tr[2*k+1].mxl);
		tr[k].mxr = max(tr[2*k+1].mxr, tr[2*k+1].su + tr[2*k].mxr);
		tr[k].mx = max(max(tr[2*k].mx, tr[2*k+1].mx), tr[2*k].mxr + tr[2*k+1].mxl);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> m; tmp.mx = 0; tmp.mxl = 0; tmp.mxr = 0; tmp.su = 0;
	for(int i = 1; i<=4*n; i++) tr[i] = tmp;
	for(int i = 1; i<=n; i++){
		cin >> gg;
		upd(i, gg, 1, 1, n);
	}

	cout << max((LL)0,tr[1].mx) << endl;
	while(m--){
		cin >> gg >> bb;
		upd(gg+1, bb, 1, 1, n);
		cout << max((LL)0,tr[1].mx) << endl;
	}

	cout.flush();
	return 0;
}