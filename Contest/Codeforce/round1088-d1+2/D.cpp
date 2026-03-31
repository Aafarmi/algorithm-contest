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
    int n,k;cin>>n>>k;
    vector<int> a(n),b(n);
    for(int &x:a) cin>>x;
    for(int &x:b) cin>>x;
    vector<int> cnt(n+1,0);
    for(int i=0;i<k;i++) cnt[a[i]]++;
    for(int i=0;i<k;i++){
        bool equal=true;
        int val=a[i];
        for(int j=i;j<n;j+=k)if(a[j]!=val){
            equal=false;
            break;
        }
        if(equal){
            int tmp=-1;
            for(int j=i;j<n;j+=k){
                if(b[j]!=-1){
                    if(tmp==-1) tmp=b[j];
                    if(b[j]!=tmp){
                        cout<<"No\n";
                        return;
                    }
                }
            }
            if(tmp!=-1) cnt[tmp]--;
            if(tmp!=-1&&cnt[tmp]<0){
                cout<<"No\n";
                return;
            }
        }else{
            bool ok=true;
            for(int j=i;j<n;j+=k)if(a[j]!=b[j]){
                if(b[j]==-1) continue;
                ok=false;
                break;
            }
            if(!ok){
                cout<<"No\n";
                return;
            }
            cnt[a[i]]--;
            if(cnt[a[i]]<0){
                cout<<"No\n";
                return;
            }
        }
    }
    cout<<"Yes\n";
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) Srend();
}