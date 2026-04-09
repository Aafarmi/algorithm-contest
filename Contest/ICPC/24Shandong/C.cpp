#include <bits/stdc++.h>
#define int long long
#define fr first
#define sc second
using namespace std;
typedef pair<int,int> P;
const int mod=998244353;
struct node{
    int x,type;
    bool operator<(const node& other){
        if(x==other.x){
            return type>other.type;
        }
        return x<other.x;
    }
};
void work()
{
    int n,k;cin>>n>>k;
    vector<P> a(n+1);//l-fr,r-sc
    for(int i=1;i<=n;i++) cin>>a[i].fr>>a[i].sc;
    vector<node> d;
    for(int i=1;i<=n;i++){
        d.push_back({a[i].fr,1});
        d.push_back({a[i].sc,-1});
    }
    sort(d.begin(),d.end());
    int now=0;
    int ans=1;
    for(auto p:d){
        if(p.type==1){
            int choice=k-now;
            if(choice<0){
                ans=0;
                break;
            }
            ans=(ans*choice)%mod;
            now++;
        }else{
            now--;
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}