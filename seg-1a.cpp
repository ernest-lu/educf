#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 

LL n, m, tr[200005], tt;

void bld(){
	for(LL i = n-1; i>0; i--)
		tr[i] = tr[2*i] + tr[2*i+1];
}


LL ge(int l, int r){
	LL le = 0, ri = 0;
	for(l += n, r += n; l<r; l/=2, r/=2){
		if(l%2) le += tr[l++];
		if(r%2) ri += tr[--r];
	} return (le + ri);
}

void upd(LL g, LL k){
	for(tr[g += n] = k; g>1; g/=2)
		tr[g/2] = tr[g] + tr[g^1]; 
}


int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> m;
	for(LL i = 0; i<n; i++)
		cin >> tr[i + n];
	bld(); //cout << ge(2, 5) << endl;

	while(m--){
		cin >> tt; tt--;
		if(tt){
			LL l,r; cin >> l >> r;
			cout << ge(l, r) << endl;
			continue;
		}
		LL g, k;
		cin >> g >> k;
		upd(g, k);
	}


	cout.flush();
	return 0;
}