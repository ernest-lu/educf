    #include<bits/stdc++.h>
    using namespace std;
    typedef long long LL;
    typedef pair<LL,LL> pii;
    #define mp make_pair
    #define pb push_back
    #define f first
    #define s second
     
     
    //var 
    LL n, m, tr[400001], lz[400001], INF = 1e18;
     
    void psh(LL z, LL l, LL r){
    	tr[z] += lz[z];
    	if(l != r){
    		lz[2*z] += lz[z];
    		lz[2*z+1] += lz[z];
    	}
    	lz[z] = 0;
    	return;
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
    	tr[z] = min(tr[2*z], tr[2*z+1]);
    }
     
    LL ge(LL z, LL l, LL r, LL lb, LL rb){
    	psh(z, l, r);
    	if(l > rb || r < lb) return INF;
    	if(l >= lb && r <= rb)
    		return tr[z];
    	LL mid = (l + r)/2;
    	return min(ge(2*z, l, mid, lb, rb), ge(2*z+1, mid+1, r, lb, rb));
    	tr[z] = min(tr[2*z], tr[2*z+1]);
    }
     
    int main(){
    	ios_base::sync_with_stdio(0); 
    	cin.tie(0);
     
    	cin >> n >> m;
    	while(m--){
    		LL tt, l, r, v;
    		cin >> tt >> l >> r;
    		if(tt == 1){
    			cin >> v;
    			upd(1,1,n, l+1, r, v);
    			continue;
    		}
    		cout << ge(1, 1, n, l+1, r) << endl;
    	}
     
    	cout.flush();
    	return 0;
    }