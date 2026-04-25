//并查集，启发式合并
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
struct MakeDsu{
    vector<int> fa,sz;
    MakeDsu(int size) : fa(size+1),sz(size+1,1){iota(all(fa),0);}
    public:
        int findfa(int x);
        void unite(int x,int y);
};
int MakeDsu::findfa(int x){
    return fa[x]==x?x:fa[x]=findfa(fa[x]);
}
void MakeDsu::unite(int x,int y){
    int a=findfa(x);
    int b=findfa(y);
    if(a==b) return;
    if(sz[a]<sz[b]) swap(a,b);
    fa[b]=a;
    sz[a]+=sz[b];
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
