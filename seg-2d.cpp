#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
int n, m, tr[200005];

void upd(int g, int k){
	for(tr[g += n] = k; g>1; g/=2)
		tr[g/2] = max(tr[g], tr[g^1]);
}

int ge(int l, int r){
	int le = 0, ri = 0;
	for(l += n, r += n; l<r; l/=2, r/=2){
		if(l%2) le = max(le, tr[l++]);
		if(r%2) ri = max(ri, tr[--r]);
	} return max(le, ri);
}

int bs(int st, int g){
	int l = st, r = n-1, mid;
	while(l < r){
		mid = (l + r)/2;
		if(ge(st, mid+1) >= g) r = mid;
		else l = mid+1;
	} 
	if(ge(st,l+1) >= g) return l;
	else return -1;
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> m;
	for(int i = 1; i<=n; i++){
		int g; cin >> g;
		upd(i-1, g);
	}

	while(m--){
		int tt; cin >> tt; tt--;
		if(tt){
			int st, x; cin >> x >> st;
			cout << bs(st, x) << endl;
			continue;
		}
		int gg, kk;
		cin >> gg >> kk;
		upd(gg, kk);
	}

	cout.flush();
	return 0;
}