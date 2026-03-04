/*https://www.nowcoder.com/practice/0757b8571cd047aab5dea52c1f369e55?channelPut=tracker2*/
#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define ll long long
#define all(arr) arr.begin(),arr.end()
#define fr first
#define sc second
#define endl '\n'
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int N=1e5+7;
void Srend(){
    int n,m;cin>>n>>m;
    vector<int> h(n);
    vector<P> x(n);//pos,high
    for(int i=0;i<n;i++) cin>>h[i];
    for(int i=0;i<n;i++){
        cin>>x[i].fr;
        x[i].sc=h[i];
    }
    sort(all(x));
    priority_queue<int> res;
    for(int i=0;i<n;i++){
        int mx=x[i].fr+x[i].sc;
        int cnt=0;
        for(int j=i;j<n;j++){
            if(x[j].fr<=mx){
                mx=max(mx,x[j].fr+x[j].sc);
                cnt++;
                if(j=n-1) i=j;
            }else{
                i=j-1;
                break;
            }
        }
        res.push(cnt);
    }
    int ans=0;
    for(int i=1;i<=m;i++){
        if(!res.empty()){
            ans+=res.top();
            res.pop();
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) Srend();
}