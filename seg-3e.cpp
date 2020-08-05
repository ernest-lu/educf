#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL n, m, tr[200005];

LL ge(LL g){
	LL res = 0;
	for(g += n; g>0; g/=2)
		res += tr[g];
	return res;
}

void upd(LL l, LL r, LL k){
	for(l += n, r += n; l<r; l/=2, r/=2){
		if(l%2) tr[l++] += k;
		if(r%2) tr[--r] += k;
	}
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> m;

	while(m--){
		LL tt; cin >> tt; tt--;
		if(tt){
			LL g;
			cin >> g;
			cout << ge(g) << endl;
			continue;
		} 
		int l, r, k;
		cin >> l >> r >> k;
		upd(l, r, k);
	}

	cout.flush();
	return 0;
}