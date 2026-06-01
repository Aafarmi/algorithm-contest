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
void Srend(){
    int n;cin>>n;
    unordered_map<int,int> mp;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        mp[x]++;
    }
    for(auto [x,y]:mp) if(y&1){
        cout<<"red\n";
        return;
    }
    cout<<"fang\n";
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) Srend();
}