#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define fro for
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using cahr = char;
using itn = int;
using db = double;
//ll mod = 1e9 + 7;
ll mod=998244353;
int d[8][2] = {{1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
const int MaX = 65;
ll C[MaX][MaX];
vector<bool>is(1e6,true);
vector<ll>prime;
void pr() {
    // C[0][0] = 1;
    // for (int i = 1; i < MaX; ++i) {
    //     C[i][0] = 1;
    //     for (int j = 1; j <= i; ++j) {
    //         C[i][j] = C[i-1][j-1] + C[i-1][j];
    //     }
    // }
	is[0]=is[1]=false;
	for(itn i=2;i<=1e5;i++){
		if(is[i])prime.pb(i);
		for(int k:prime){
			if(i*k>1e5)break;
			is[i*k]=false;
			if(i%k==0)break;
		}
	}
}
ll qpow(ll a, ll b) {
	ll res = 1%mod;
	a%=mod;
	while (b > 0) {
		if (b & 1) {
			res = res * a % mod;
		}
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
void solve() {
	int n;
	cin>>n;
	if(n==1){
		cout<<"YES"<<endl;
		cout<<"1"<<endl;
		return;
	}
	if(n==2){
		cout<<"YES"<<endl;
		cout<<"1 2"<<endl;
		cout<<"3 4"<<endl;
		return;
	}
	vector<vector<int>>v(n+1,vector<int>(n+1,1));
	int l=2;
	for(int i=1;i<=n;i++){
		v[i][i]=l;
		l++;
	}
	v[1][n]=l;
	l++;
	v[n][1]=l;
	l++;
	for(itn i=2;i<=n/2;i++){
		v[i][n-i+1]=l;
		v[n-i+1][i]=l;
		l++;
	}
	for(itn i=2;i<=n/2;i++){
		int k=i+1,r=n-i;
		for(itn j=k;j<=r;j++){
			v[i][j]=l;
			v[n-i+1][j]=l;
			v[j][i]=l;
			v[j][n-i+1]=l;
		}
		l++;
	}
	cout<<"YES"<<endl;
	for(itn i=1;i<=n;i++){
		for(itn j=1;j<=n;j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main() {
//	pr();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
//	cin>>t;
	while (t--) {
		solve();
	}
}