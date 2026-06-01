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
    int n,a,b;cin>>n>>a>>b;
    vector<int> v(14,0);int o;
    for(int i=1;i<=n;i++) cin>>o,v[o]++;
    int lim=1,ans=0;
    for(int i=1;i<=11;i++) lim*=3;
    for(int op=0;op<lim;op++){
        int now=0;
        vector<int> used(12,0),d(14,0);
        for(int t=op,i=1;t>0;t/=3,i++){
            int r=t%3;
            used[i]+=r;
            now+=r*b;
        }
        for(int i=1;i<=11;i++){
            d[i]+=used[i];
            d[i+1]+=used[i];
            d[i+2]+=used[i];
        }
        bool con=false;
        for(int i=1;i<=13;i++){
            d[i]=v[i]-d[i];
            if(d[i]<0) con=true;
        }
        if(con) continue;
        for(int i=1;i<=13;i++){
            d[i]/=3;
            now+=d[i]*a;
        }
        if(b>a) for(int i=1;i<=11;i++){
            int mi=min({d[i],d[i+1],d[i+2]});
            d[i]-=mi;
            d[i+1]-=mi;
            d[i+2]-=mi;
            now+=3*mi*(b-a);
        }
        ans=max(ans,now);
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