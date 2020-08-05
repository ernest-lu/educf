#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


struct sht{
	bool sh[50];
};


//var 
int n, q, a[100001];
sht dee, tmp, tr[200001];

sht cmb(sht aa, sht bb){
	sht gg = dee;
	for(int i = 0; i<=40; i++)
		gg.sh[i] = (aa.sh[i] | bb.sh[i]);
	return gg;
}

void upd(int g, sht k){
	for(tr[g += n] = k; g>1; g/=2)
		tr[g/2] = cmb(tr[g], tr[g^1]);
}

sht ge(int l, int r){
	sht le = dee, ri = dee;
	for(l += n, r += n; l<r; l/=2, r/=2){
		if(l%2) le = cmb(le, tr[l++]);
		if(r%2) ri = cmb(ri, tr[--r]);
	} return cmb(le, ri);
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> q; 
	
	for(int i = 0; i<=40; i++)
		dee.sh[i] = 0;

	for(int i = 0; i<=2*n; i++)
		tr[i] = dee; 

	for(int i = 1; i<=n; i++){
		cin >> a[i]; tmp = dee; tmp.sh[a[i]] = 1;
		upd(i-1, tmp);
	}

	while(q--){
		int tt; cin >> tt; tt--;
		if(!tt){
			int x, y; cin >> x >> y;
			tmp = ge(x-1, y); int ans = 0;
			for(int i = 0; i<=40; i++)
				if(tmp.sh[i])ans++;
			cout << ans << endl;
			continue;
		}

		int g, k; cin >> g >> k;
		tmp = dee; tmp.sh[k] = 1;
		upd(g-1, tmp);
	}

	cout.flush();
	return 0;
}