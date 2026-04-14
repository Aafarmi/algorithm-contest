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
    int n,q;cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> st;
    vector<int> qu;
    stack<int> s1;
    queue<int> q1;
    while(q--){
        int op;cin>>op;
        if(op==1){
            int x;cin>>x;
            s1.push(x);
            q1.push(x);
        }else{
            st.emplace_back(s1.top());
            qu.emplace_back(q1.front());
            q1.pop();s1.pop();
        }
    }
    bool t1=true,t2=true;
    for(int i=0;i<st.size();i++)if(st[i]!=a[i]){
        t1=false;
        break;
    }
    for(int i=0;i<qu.size();i++)if(qu[i]!=a[i]){
        t2=false;
        break;
    }
    if(t1&&t2) cout<<"both";
    else if(t1&&!t2) cout<<"stack";
    else if(!t1&&t2) cout<<"queue";
    else cout<<"-1";
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) Srend();
}