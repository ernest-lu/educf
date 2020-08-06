#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL n, m, tr[400005], lz[400005];

void psh(int z, int l, int r){
	if(lz[z]){
		tr[z] = (r - l + 1) - (tr[z]);
		if(l != r){
			lz[2*z] ^= lz[z];
			lz[2*z+1] ^= lz[z];
		}
	}
	lz[z] = 0; 
	return;
}

void upd(int z, int l, int r, int lb, int rb){
	psh(z, l, r);
	if(l > rb || r < lb) return;
	if(l >= lb && r <= rb){
		lz[z] ^= 1;
		psh(z, l, r);
		return;
	}

	int mid = (l + r)/2;
	upd(2*z, l, mid, lb, rb);
	upd(2*z+1, mid+1, r, lb, rb);
	tr[z] = tr[2*z] + tr[2*z+1];
}

LL ge(int z, int l, int r, int lb, int rb){
	psh(z, l, r);
	if(l > rb || r < lb) return 0;
	if(l >= lb && r <= rb)
		return tr[z];
	
	int mid = (l+r)/2;
	return ge(2*z, l, mid, lb, rb) + ge(2*z+1, mid+1, r, lb, rb);
	tr[z] = tr[2*z] + tr[2*z+1];
}

LL bs(LL k){
	int l = 1, r = n, mid;
	while(l < r){
		mid = (l+r)/2;
		if(ge(1,1,n,1,mid) >= k) r = mid;
		else l = mid+1;
	} return l;
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> m;
	while(m--){
		LL tt, l, r, k;
		cin >> tt;
		if(tt==1){
			cin >> l >> r;
			upd(1,1,n,l+1,r);
			continue;
		}

		cin >> k;
		cout << bs(k+1)-1 << endl;
	}

	cout.flush();
	return 0;
}