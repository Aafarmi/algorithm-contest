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
const int N=3e6+7;
void Srend(){
    int n,p;cin>>n>>p;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    deque<int> q1,q2;//mx,mi
    int ans=0;
    for(int l=0,r=0;r<n;r++){
        while(q1.size()&&a[q1.back()]<a[r]) q1.pop_back();
        q1.push_back(r);
        while(q2.size()&&a[q2.back()]>a[r]) q2.pop_back();
        q2.push_back(r);
        while(a[q1.front()]-a[q2.front()]>2*p){
            if(q1.front()==l) q1.pop_front();
            if(q2.front()==l) q2.pop_front();
            l++;
        }
        ans=max(ans,r-l+1);
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