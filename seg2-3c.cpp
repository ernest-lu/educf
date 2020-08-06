	#include<bits/stdc++.h>
	using namespace std;
	typedef long long LL;
	typedef pair<int,int> pii;
	#define mp make_pair
	#define pb push_back
	#define f first
	#define s second


	//var 
	LL n, m, tr[400005], lz[400005], tmp;
	LL tt, l1, r1, v1, x1;

	void psh(LL z, LL l, LL r){
		tr[z] += lz[z];
		if(l != r){
			lz[2*z] += lz[z];
			lz[2*z+1] += lz[z];
		}
		lz[z] = 0;
	}

	void upd(LL z, LL l, LL r, LL lb, LL rb, LL g){
		psh(z, l, r);
		if(l > rb || r < lb) return;
		if(l >= lb && r <= rb){
			lz[z] += g;
			psh(z, l, r);
			return;
		}
		LL mid = (l + r)/2;
		upd(2*z, l, mid, lb, rb, g);
		upd(2*z+1, mid+1, r, lb, rb, g);
		tr[z] = max(tr[2*z], tr[2*z+1]);
	}

	LL ge(LL z, LL l, LL r, LL lb, LL rb){	
		psh(z, l, r);
		if(l > rb || r < lb) return 0;
		if(l >= lb && r <= rb)
			return tr[z];
		
		LL mid = (l + r)/2;
		return max(ge(2*z, l, mid, lb, rb) , ge(2*z+1, mid+1, r, lb, rb));
		tr[z] = max(tr[2*z], tr[2*z+1]);
	}

	LL bs(LL g, LL nn){
		LL l = nn, r = n, mid;
		while(l < r){
			mid = (l + r)/2;
			if(ge(1,1,n,nn,mid) >= g) r = mid;
			else l = mid+1;
		} 
		if(ge(1,1,n,nn,l) < g) return 0;
		return l;
	}

	int main(){
		ios_base::sync_with_stdio(0); 
		cin.tie(0);

		scanf("%lld %lld\n", &n, &m);
		while(m--){
			scanf("%lld ", &tt);
			if(tt == 1){
				scanf("%lld %lld %lld\n", &l1, &r1, &v1);
				upd(1,1,n,l1+1,r1,v1);
				continue;
			}

			scanf("%lld %lld\n", &x1, &l1);
			tmp = bs(x1, l1+1)-1;
			printf("%lld\n", tmp);

		}

		cout.flush();
		return 0;
	}