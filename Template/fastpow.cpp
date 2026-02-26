#include <bits/stdc++.h>
using namespace std;
int fastpow(int x,int y){
	if(y==0) return 1;
	int ans=fastpow(x,y/2);
	if(y%2){
		return ans*ans*x;
	}else{
		return ans*ans;
	}
}
int main(){
	int a,b;
	cin>>a>>b;
	cout<<fastpow(a,b);
}
