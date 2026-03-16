/*https://www.nowcoder.com/practice/070c12970c5240ddb71993e38d6aef49?tpId=391&contestId=129582&channelPut=tracker1*/
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
const int mod=998244353;
const int N=2e5+7;
void Srend(){
    int n;cin>>n;
    vector<int> a(n+1);
    ll sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    int t=sum/n;
    if(sum>=0) t+=(sum%n?1:0);
    int cnt=0,now=t*n-sum;
    for(int i=1;i<=n;i++){
        cnt=cnt+abs(a[i]-t);
    }
    int ans=(cnt-now)/2+now;
    cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) Srend();
}