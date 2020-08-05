#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second

struct ppsort{
	bool operator()(pii t1, pii t2){
		return mp(t1.s, t1.f) < mp(t2.s, t2.f);
	}
};

//var 
int n, a[200001], fen[200001], ans[100001], st[100001], en[100001], ins[100001], lf[100001], rf[100001];
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
		ins[a[u.f]] = ge(u.s);
		upd(u.s, 1);
	} for(auto u : rng) upd(u.s, -1);
	for(auto u : rng){
		lf[a[u.f]] = ge(u.s);
		upd(u.f, 1);
	} for(auto u : rng) upd(u.f, -1); 
	sort(rng.begin(), rng.end(), ppsort()); int cnt = 0;
	for(auto u : rng){
		rf[a[u.f]] = cnt - ge(u.f);
		upd(u.s, 1); cnt++;
	}

	for(int i = 1; i<=n; i++)
		cout << lf[i] + rf[i] - 2*ins[i] << " ";
	cout << endl;

	cout.flush();
	return 0;
}