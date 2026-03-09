#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define ll long long
#define fr first
#define sc second
#define endl '\n'
#define all(arr) arr.begin(),arr.end()
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int N=2e5+7;
struct DSU{
    vector<int> fa,sz;
    DSU(int size) : fa(size+1),sz(size,1){iota(all(fa),0);}
    public:
        int findfa(int x);
        void unite(int x,int y);
};
int DSU::findfa(int x){
    return fa[x]==x?x:fa[x]=findfa(fa[x]);
}
void DSU::unite(int x,int y){
    x=findfa(x);
    y=findfa(y);
    if(x==y) return;
    if(sz[x]<sz[y]) swap(x,y);
    fa[y]=x;
    sz[x]+=sz[y];
}
int n,m,cnt;
bool vis[N];
int main(){
	cin>>n>>m;
	dsu pa(n+1);
	for(int i=1;i<=m;i++){
		int p,q;cin>>p>>q;
		pa.unite(p,q);
	}
	for(int i=1;i<=n;i++){
		int qwq=pa.find(i);
		if(!vis[qwq]){
			vis[qwq]=1;
			cnt++;
		}
	}
	cout<<cnt;
}
