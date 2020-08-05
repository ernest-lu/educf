#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
int n, a[200001], fen[200001], ans[100001], st[100001], en[100001];
vector<pii> rng;

void upd(int g, int k){
	for(; g<=2*n; g+=(g&-g))
		fen[g] += k;
}

int ge(int g){
	int res = 0;
	for(; g>0; g-=(g&-g))
		res += fen[g];
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n;
	for(int i = 1; i<=2*n; i++){
		cin >> a[i]; 
		if(!st[a[i]]) st[a[i]] = i;
		else en[a[i]] = i;
	}
	
	for(int i = 1; i<=n; i++){
		rng.pb(mp(st[i], en[i]));
		//cout << st[i] << " " << en[i] << endl;
	}
	sort(rng.begin(), rng.end(), greater<pii>());
	for(auto u : rng){
		ans[a[u.f]] = ge(u.s);
		upd(u.s, 1);
	}

	for(int i = 1; i<=n; i++)
		cout << ans[i] << " ";
	cout << endl;

	cout.flush();
	return 0;
}