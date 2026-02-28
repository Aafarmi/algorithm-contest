/*https://codeforces.com/contest/2205/problem/D*/
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
    stack<int> st;
    vector<int> f(n+1),b(n+1);
    f[1]=0;b[n]=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        while(!st.empty()&&a[st.top()]<=a[i])
            st.pop();
        if(st.empty()){
            f[i]=0;st.push(i);
            continue;
        }
        f[i]=f[st.top()]+1;
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=n;i>=1;i--){
        while(!st.empty()&&a[st.top()]<=a[i])
            st.pop();
        if(st.empty()){
            b[i]=0;st.push(i);
            continue;
        }
        b[i]=b[st.top()]+1;
        st.push(i);
    }
    int mx=0;
    for(int i=1;i<=n;i++){
        int tmp=f[i]+b[i];
        mx=max(mx,tmp);
    }
    int ans=n-(mx+1);
    cout<<ans<<endl;
} 
signed main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    cin>>t;
    while(t--) Srend();
}