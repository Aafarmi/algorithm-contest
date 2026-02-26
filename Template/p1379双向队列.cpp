#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second
const string t="123804765";
int ans;
unordered_map<string,bool> vis;
void bfs(string s){
	queue<pair<string,int>> q;
	q.push({s,0});
	while(!q.empty()){
		auto x=q.front();
		q.pop();
		vis[x.fr]=1;
		if(x.fr==t){
			ans=x.sc;
			return;
		}
		int i=0;
		for(;i<=8;i++)if(x.fr[i]=='0')break;
		if(i>=1&&i!=3&&i!=6){
			string tmp=x.fr;
			swap(tmp[i],tmp[i-1]);
			if(!vis[tmp]){q.push({tmp,x.sc+1});
			vis[tmp]=1;}
		}
		if(i<=7&&i!=5&&i!=2){
			string tmp=x.fr;
			swap(tmp[i],tmp[i+1]);
			if(!vis[tmp]){q.push({tmp,x.sc+1});
			vis[tmp]=1;}
		}
		if(i>=3){
			string tmp=x.fr;
			swap(tmp[i],tmp[i-3]);
			if(!vis[tmp]){q.push({tmp,x.sc+1});
			vis[tmp]=1;}
		}
		if(i<=5){
			string tmp=x.fr;
			swap(tmp[i],tmp[i+3]);
			if(!vis[tmp]){q.push({tmp,x.sc+1});
			vis[tmp]=1;}
		}
	}
}
void solve(){
	string s;cin>>s; 
	bfs(s);
	cout<<ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}