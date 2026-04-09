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
bool cmp(P x,P y){
    if (x.fr==y.fr) return x.sc>=y.sc;
    return x.fr<y.fr;
}
void Srend(){
    int n,a,b,c;cin>>n>>a>>b>>c;
    vector<vector<int>> g1(n+1,vector<int>(3));
    vector<vector<int>> g2(n+1,vector<int>(3));
    for(int i=1;i<=n;i++){
        cin>>g1[i][0]>>g1[i][1]>>g1[i][2];
        cin>>g2[i][0]>>g2[i][1]>>g2[i][2];
    }
    int ans=0;
    for(int i=0;i<3;i++){
        vector<P> d;
        for(int j=1;j<=n;j++){
            if(g1[j][i]>g2[j][i]) swap(g1[j][i],g2[j][i]);
            P st=make_pair(g1[j][i],1);
            P ed=make_pair(g2[j][i]+1,-1);
            d.emplace_back(st);
            d.emplace_back(ed);
        }
        sort(all(d),cmp);
        int mxlen=0,now=0;
        for(int j=0;j<d.size();j++){
            int tmp=d[j].fr;
            while(j+1<d.size()&&d[j+1].fr==tmp){
                now+=d[j++].sc;
                mxlen=max(now,mxlen);
            }
            now+=d[j].sc;
            mxlen=max(now,mxlen);
        }
        ans=max(mxlen,ans);
    }
    cout<<ans;
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) Srend();
}