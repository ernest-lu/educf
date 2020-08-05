#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL n, m, tt, l, r, v, tr[200100];

void upd(int g, int k){
	for(; g<=(n+10); g+=(g&-g))
		tr[g] += k;
}

LL ge(int g){
	LL res = 0;
	for (; g>0; g-=(g&-g))
		res += tr[g];
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> m;
	while(m--){
		cin >> tt;
		if(tt == 1){
			cin >> l >> r >> v;
			upd(l+5, v);
			upd(r+5, -v);
			continue;
		}
		LL g;
		cin >> g;
		cout << ge(g+5) << endl;
	}

	cout.flush();
	return 0;
}