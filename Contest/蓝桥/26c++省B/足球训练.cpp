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
//const ll INF=0x3f3f3f3f3f3f3f3f;
//const ll mod=1e9+7;
const ll mod=998244353;
const int N=2e5+7;
struct player{
    int id,e,r;
    int up;//a%b
    int down;//b
    player(){}
    player(int i,int a,int b){
        e=a/b;
        up=a%b;
        down=b;
        r=up/down;
        id=i;
    }
    bool operator<(const player& other) const {
        int t1=up*other.down,t2=other.up*down;
        return t1<t2;
    }
};
void Srend(){
    int n,m;cin>>n>>m;
    vector<int> a(n+1),b(n+1),k(n+1,0);
    vector<player> p(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        p[i]=player(i,a[i],b[i]);
    }
    int z0,l=1,r=INF;
    while(l<=r){
        int mid=(l+r)/2;
        int sum=0;
        for(int i=1;i<=n;i++){
            int tmp=max(mid-p[i].e,0LL);
            //这里注意类型匹配
            sum+=tmp;
        }
        if(sum>=m){
            z0=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    z0--;
    int rest=m;
    for(int i=1;i<=n;i++){
        k[i]+=max(z0-p[i].e,0LL);
        rest-=k[i];
    }
    vector<player> res;
    for(int i=1;i<=n;i++)if(p[i].e<=z0){
    //这里排除掉本身就大于z0的队员
        res.emplace_back(p[i]);
    }
    sort(all(res));
    for(int i=0;i<rest;i++) k[res[i].id]++;
    int ans=1;
    for(int i=1;i<=n;i++){
        int tmp=(a[i]+k[i]*b[i])%mod;
        ans=(ans*tmp)%mod;
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