#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
pii tr[200001];
LL n, m, cur;

void upd(LL l, LL r, pii k){
	for(l += n, r += n; l<r; l/=2, r/=2){
		if(l%2) {tr[l] = max(tr[l], k); l++;}
		if(r%2) {--r; tr[r] = max(tr[r], k);}
	}
}

LL ge(LL g){
	pii res;
	for(res = tr[g += n]; g>1; g/=2)
		res = max(res, tr[g/2]);
	return res.s;
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> m; cur = 1;
	while(m--){
		LL tt, t1,t2, t3;
		cin >> tt; tt--;
		if(tt){
			cin >> t1;
			cout << ge(t1) << endl;
			continue;
		}	

		cin >> t1 >> t2 >> t3;
		cur++;
		upd(t1, t2, mp(cur, t3));
	}

	cout.flush();
	return 0;
}