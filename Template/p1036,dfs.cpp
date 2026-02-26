#include <bits/stdc++.h>
using namespace std;
int n,k,p,ans;
int a[21],s[21];
bool check(int x){
	if(1>=x) return false;
	if(x==2) return true;
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
}
void dfs(int x,int sum,int p){
	if(x==0){
		if(check(sum)) ans++;
		return;
	}
	for(int i=p+1;i<=n;i++){
		dfs(x-1,sum+a[i],i);
		
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("C:\\Users\\Aafar\\Desktop\\c++\\freopen.in","r",stdin);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(k,0,0);
	cout<<ans<<flush;
	return 0;
}
