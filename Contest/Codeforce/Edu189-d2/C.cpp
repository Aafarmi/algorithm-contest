#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define all(a) a.begin(), a.end()
#define pb push_back
#define in insert
#define vii vector<vector<int>>
#define vs vector<string>
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define on cout << -1 << endl;
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
void work()
{
    int n;cin>>n;
    vector<int> c(n+1),w(n+1);
    for(int i=1;i<=n;i++) cin>>c[i];
    for (int i = 1; i <= n; i++) cin>>w[i];
    vector<vector<int>> mp(n+1);
    vector<int> f(n+1,0); 
    for(int l=1,r=1;r<=n;){
        while(r<=n&&c[l]==c[r]) r++;
        if(l==1&&r==n+1){
            mp[c[l]].emplace_back(r-l);
            break;
        }else if(l==1||r==n+1){
            mp[c[l]].emplace_back(-1);
            f[c[l]]+=r-l;
            l=r;
        }else{
            mp[c[l]].emplace_back(r-l);
            l=r;
        }
    }
    vector<int> ans(n+1);
    for(int i=1;i<=n;i++){
        if(mp[i].size()&&mp[i][0]==n){
            ans[i]=0;
            continue;
        }
        int cnt=f[i],k=mp[i].size()+1;
        for(int p:mp[i]){
            if(p==-1){
                k--;
            }
            else if(p<=w[i]) k--;
            else cnt+=p;
        }
        cnt=n-cnt;
        ans[i]=cnt+w[i]*k;
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int qwq = 1;
    //cin >> qwq;
    while (qwq--)
    {
        work();
    }
    return 0;
}