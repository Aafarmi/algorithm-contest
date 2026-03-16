/*https://www.nowcoder.com/practice/c7c06d5a388d45c3a57cc3df1068068e?tpId=391&contestId=125587&channelPut=tracker1*/
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
const int mod=1e9+7;
const int mod_=9;
const int N=2e5+7;
vector<int> prime;
void init(){
    vector<bool> p(17607,1);
    for(int i=2;i<=17600;i++){
        if(p[i]){
            prime.emplace_back(i);
            for(int j=i*i;j<=17600;j+=i) p[j]=false;
        }
    }
}
void Srend(){
    int ans=1;
    for(int p:prime){
        int tmp=p,cnt=0;
        while(tmp<=17600){
            cnt++;
            tmp*=p;
        }
        ans=ans*cnt%mod;
    }
    cout<<ans;
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t=1;
    //cin>>t;
    while(t--) Srend();
}