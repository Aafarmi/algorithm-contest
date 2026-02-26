#include <bits/stdc++.h>
using namespace std;
const int N=1e5+7;
struct dsu{
	vector<int> fa;
	explicit dsu(int size) : fa(size){iota(fa.begin(),fa.end(),0);}
	public:
		int find(int x);
		void unite(int x,int y);
};
int dsu::find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void dsu::unite(int x,int y){
	fa[find(x)]=find(y);
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
