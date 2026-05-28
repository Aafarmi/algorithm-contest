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
int qpow(int a,int b){
    if(b==0) return 1LL;
    int res=qpow(a,b/2);
    if(b&1) return res*res%mod*a%mod;
    else return res*res%mod;
}
void Srend(){
    int n,m,k;cin>>n>>m>>k;
    if(k==0){
        int ans=qpow(m,n-1);
        cout<<ans<<endl;
        return;
    }
    vector<P> x;
    for(int i=1;i<=k;i++){
        int a,b;cin>>a>>b;
        x.emplace_back(make_pair(a,b));
    }
    sort(all(x));
    int up,down;
    P last=x[0];
    if(last.fr==1) up=1,down=0;
    else{
        int v=qpow(m,last.fr-2);
        up=(last.sc-1)*v%mod;
        down=(m-last.sc)*v%mod;
    }
    for(int i=1;i<x.size();i++){
        P now = x[i];
        int t1,t2;
        if(now.fr-last.fr>1){
            t1=t2=(last.sc-1)*up+(m-last.sc)*down;
            int cnt=now.fr-last.fr-2;
            t1=t2=t1*qpow(m,cnt);
            up=t1,down=t2;
            t1=(now.sc-1)*up,t2=(m-now.sc)*down;
            up=t1,down=t2;
        }else{
            if(now.sc<last.sc){
                t1=(now.sc-1)*up;
                t2=(last.sc-now.sc-1)*up+(m-last.sc)*down;
            }else if(now.sc>last.sc){
                t1=(last.sc-1)*up+(now.sc-last.sc-1)*down;
                t2=(m-now.sc)*down;
            }else{
                t1=(now.sc-1)*up;
                t2=(m-now.sc)*down;
            }
            up=t1%mod,down=t2%mod;
        }
        last=now;
    }
    int ans=down;
    if(last.fr<n){
        ans=(last.sc-1)*up%mod+(m-last.sc)*down%mod;
        ans=ans%mod%qpow(m,n-last.fr-1)%mod;
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