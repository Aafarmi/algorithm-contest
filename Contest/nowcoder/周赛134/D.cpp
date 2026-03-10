//滑动窗口，双指针
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define fr first
#define sc second
#define endl '\n'
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int N=2e5+7;
void solve(){
    int n;cin>>n;
    int ans=0;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
//-----way1-----
/*    deque<int> q1,q2;//1up,2down
    for(int i=0,l=0;i<n;i++){
        while(q1.size()&&a[i]>a[q1.back()]) q1.pop_back();
        q1.push_back(i);
        while(q2.size()&&a[i]<a[q2.back()]) q2.pop_back();
        q2.push_back(i);
        while(q1.size()&&q2.size()&&a[q1.front()]-a[q2.front()]>1){
            if(q1.front()==l) q1.pop_front();
            if(q2.front()==l) q2.pop_front();
            l++;
        }
        ans+=i-l+1;
    }
*/
//------way2-----
    map<int,int> mp;
    for(int r=0,l=0;r<n;r++){
        mp[a[r]]++;
        while(l<r&&mp.size()>2||(mp.size()==2&&mp.rbegin()->fr-mp.begin()->fr>1)){
            mp[a[l]]--;
            if(mp[a[l]]==0) mp.erase(a[l]);
            l++;
        }
        ans+=r-l+1;
    }
    cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) solve();
}
