#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
int n, a[100001], fen[100001];

void upd(int g, int k){
	for(; g<=n; g+=(g&-g))
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
	for(int i = 1; i<=n; i++){
		cin >> a[i]; upd(a[i], 1);
		cout << i - ge(a[i]) << " ";
	} cout << endl;

	cout.flush();
	return 0;
}