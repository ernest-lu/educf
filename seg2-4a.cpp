#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL n, m, lza[400005], lzi[400005], tr[400005], pis[400005];

void psh(LL z, LL l, LL r){
	if(pis[z]){
		tr[z] = (r-l+1) * lza[z];
		if(l!=r){
			lza[2*z] = lza[z]; pis[2*z] = 1;
			lza[2*z+1] = lza[z]; pis[2*z+1] = 1;
			lzi[2*z] = 0; lzi[2*z+1] = 0;
		}
	}
	else{
		tr[z] += ((r-l+1) * lzi[z]);
		if(l != r){
			if(pis[2*z]) lza[2*z] += lzi[z];
			else lzi[2*z] += lzi[z];
			if(pis[2*z+1]) lza[2*z+1] += lzi[z];
			else lzi[2*z+1] += lzi[z];
		}
	}

	pis[z] = 0; lza[z] = 0; lzi[z] = 0;
	return;
}

void upa(LL z, LL l, LL r, LL lb, LL rb, LL g){
	psh(z, l, r);
	if(l > rb || r < lb) return;
	if(l >= lb && r <= rb){
		lzi[z] = 0;
		lza[z] = g;
		pis[z] = 1;
		psh(z,l,r);
		return;
	}

	LL mid = (l+r)/2;
	upa(2*z, l, mid, lb, rb, g);
	upa(2*z+1, mid+1, r, lb, rb, g);
	tr[z] = tr[2*z] + tr[2*z+1];
}

void upi(LL z, LL l, LL r, LL lb, LL rb, LL g){
	psh(z, l, r);
	if(l > rb || r < lb) return;
	if(l >= lb && r <= rb){
		if(pis[z]){
			lza[z] += g;
			psh(z, l, r);
		}
		else{
			lzi[z] += g;
			psh(z, l, r);
		}
		return;
	}

	LL mid = (l + r)/2;
	upi(2*z, l, mid, lb, rb, g);
	upi(2*z+1, mid+1, r, lb, rb, g);
	tr[z] = tr[2*z] + tr[2*z+1];
}

LL ge(LL z, LL l, LL r, LL lb, LL rb){
	psh(z, l, r);
	if(l > rb || r < lb) return 0;
	if(l >= lb && r <= rb)
		return tr[z];

	LL mid = (l + r)/2;
	return ge(2*z, l, mid, lb, rb) + ge(2*z+1, mid+1, r, lb, rb);
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> m;
	while(m--){
		LL tt, l, r, v;
		cin >> tt;
		if(tt == 1){
			cin >> l >> r >> v;
			upa(1,1,n,l+1,r,v);
			continue;
		}
		if(tt == 2){
			cin >> l >> r >> v;
			upi(1,1,n,l+1,r,v);
			continue;
		}

		cin >> l >> r;
		cout << ge(1,1,n,l+1,r) << endl;
	}

	cout.flush();
	return 0;
}