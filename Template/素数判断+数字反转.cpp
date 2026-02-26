#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;vector<int> a;vector<int> b;
bool judge(int x){
	int cnt=0;
	for(int i=2;i*i<=x;i++){
		if(x%i==0) cnt++;
	}
	if(cnt!=0) return false;
	else return true;
}
int fan(int x){
	string s=to_string(x);
	reverse(s.begin(),s.end());
	int ans=stoll(s);
	return ans;
}
signed main(){
	cin>>m>>n;int d=0; 
	for(int i=m;i<=n;i++){ 
		if(judge(i)&&judge(fan(i))){
			if(d==0){
				cout<<i;
				d+=100;
			}
			else{
				cout<<","<<i;
			}
		}
	}
	if(d==0) cout<<"No";
}
