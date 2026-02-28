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
void Srend(){
    int n;cin>>n;
    vector<int> a(n+1);
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    set<int> s;
    for(int i=1;i<=n;i++){
        vector<int> b=a;
        int win=i,tmp=sum;
        while(tmp>0){
            if(b[win]>0){
                b[win]--;
                tmp--;
            }
            if(tmp==0){
                s.insert(win);
                break;
            }
            win=(win%n)+1;
        }
    }
    int ans=s.size();
    cout<<ans<<endl;
} 
signed main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    cin>>t;
    while(t--) Srend();
}