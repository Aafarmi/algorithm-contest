#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define ll long long
#define db double
#define fr first
#define sc second
#define endl '\n'
#define all(arr) arr.begin(),arr.end()
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;
const ll mod=1e9+7;
const ll _mod=998244353;
const int N=2e5+7;
string Getstr(string& s){
    string tmp="#";
    for(char c:s){
        tmp+=c;
        tmp+='#';
    }
    return tmp;
}
void Srend(){
    string s;cin>>s;
    s=Getstr(s);
    vector<int> r(s.size(),0);
    int c=0,ans=0;
    for(int i=1;i<s.size();i++){
        if(i<=c+r[c]) r[i]=min(r[2*c-i],c+r[c]-i);
        while(i-r[i]>=0&&s[i-r[i]]==s[i+r[i]]) r[i]++;
        r[i]--;
        if(i+r[i]>=c+r[c]) c=i;
        ans=max(ans,r[i]);
    }
    cout<<ans<<endl;
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) Srend();
}