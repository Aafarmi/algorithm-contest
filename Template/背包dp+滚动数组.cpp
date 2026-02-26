#include <iostream>
#include <math.h>
using namespace std;
int a[1001],b[1001];
int dp[2][1001];
int n,m;
int dfs(int i,int j){
	int now=0,old=1;
	for(;i<=n;i++){
		swap(old,now);
		for(int j=0;j<=m;j++){
			if(a[i]>j) dp[now][j]=dp[old][j];
			else dp[now][j]=fmax(dp[old][j],dp[old][j-a[i]]+b[i]);
		}
	}
	return dp[now][m];
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	cout<<dfs(1,m);
	
}
