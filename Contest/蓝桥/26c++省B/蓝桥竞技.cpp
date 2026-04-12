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
    vector<int> a(n);
    int sum=0,cnt;//总人数，总队数
    for(int& x:a){
        cin>>x;
        sum+=x;
    }
    cnt=sum/5;
    if(sum%5!=0){
        cout<<"F\n";
        return;
    }
    for(int& x:a){
        if(x>cnt){
            cout<<"F\n";
            return;
        }
    }
    cout<<"T\n";
    return;
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) Srend();
}