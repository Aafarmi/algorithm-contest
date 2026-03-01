#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(arr) arr.begin(),arr.end()
#define fr first
#define sc second
#define endl '\n'
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int N=1e5+7;
vector<int> spf(N);
void init_spf(){
    for(int i=1;i<N;i++) spf[i]=i;
    for(int i=2;i<N;i++){
        if(spf[i]==i){
            for(int j=i*i;j<N;j+=i) spf[j]=i;
        }
    }
}
void Srend(){
    int n;cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(is_sorted(all(a))){
        printf("Bob\n");
        return;
    }
    vector<int> p(n+1);
    bool Alice=false;
    for(int i=1;i<=n;i++){
        if(a[i]==1){
            p[i]=1;
            continue;
        }
        int pp=spf[a[i]];
        int tmp=a[i];
        while(tmp>0&&tmp%pp==0) tmp/=pp;
        if(tmp>1) Alice=true;
        p[i]=pp; 
    }
    if(Alice){
        printf("Alice\n");
        return;
    }
    if(is_sorted(all(p))) printf("Bob\n");
    else printf("Alice\n");
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_spf();
    int t=1;
    cin>>t;
    while(t--) Srend();
}