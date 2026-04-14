#include <bits/stdc++.h>
using namespace std;
#define int long long
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
void Srend(){
    string s;cin>>s;
    int n=s.size();
    s='#'+s;
    int ans=0;
    for(int l=1;l<=n;l++){
        int cnt=0;
        if(s[l]=='0') cnt++;
        for(int r=l+1;r<=n;r++){
            if((r-l)&1){
                if(s[r]=='0') cnt++;
            }else{
                if(s[r]=='1') cnt++;
            }
            ans+=min(cnt,r-l+1-cnt);
        }
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