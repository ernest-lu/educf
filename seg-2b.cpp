#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
int n, m, fen[100001], a[100001];

void upd(int g, int k){
	for(; g <= n; g+=(g&-g))
		fen[g] += k;
}

int ge(int g){
	int res = 0;
	for(; g>0; g-=(g&-g))
		res += fen[g];
	return res;
}

int bs(int k){
	int l = 1, r = n, mid;
	while(l < r){
		mid = (l + r)/2;
		if(ge(mid) >= k) r = mid;
		else l = mid+1;
	}
	return l;
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> m;
	for(int i = 1; i<=n; i++){
		cin >> a[i];
		upd(i, a[i]);
	}
	while(m--){
		int tt, kk;
		cin >> tt; tt--;
		if(tt){
			cin >> kk; kk++;
			cout << bs(kk)-1 << endl;
			continue;
		}
		cin >> kk; kk++;
		if(a[kk] == 1)upd(kk, -1); 
		else upd(kk, 1);
		a[kk] ^= 1;
	}

	cout.flush();
	return 0;
}