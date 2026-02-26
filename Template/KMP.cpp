#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define fr first
#define sc second
#define endl '\n'
const int N=2e5+7;
int t;
vector<int> prework(string s){
	int n=(int)s.size();
	vector<int> pi(n);
	pi[0]=0;
	for(int i=1;i<=n;i++){
		int j=pi[i-1];
		while(j>0&&s[i]!=s[j]) j=pi[j-1];
		if(s[i]==s[j]) j++;
		pi[i]=j;
	} 
	return pi;
}
vector<int> KMP(string text,string s){
	string now=s+'#'+text;
	int m=text.size(),n=s.size();
	vector<int> pos;
	vector<int> pi=prework(now);
	for(int i=n+1;i<=m+n;i++){
		if(pi[i]==n) pos.emplace_back(i-2*n);
	}
	return pos;
}
void solve(){
	string s="aabaaab";
	string a="aab";
	vector<int> qwq=KMP(s,a);
	for(auto p:qwq) cout<<p<<" ";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cin>>t;
    t=1;
    while(t--) solve();
}
