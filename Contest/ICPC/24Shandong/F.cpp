#include <bits/stdc++.h>
#define int long long
#define fr first
#define sc second
using namespace std;
void work()
{
    int n;cin>>n;
    vector<int> a(n+1);
    vector<pair<int,int>> b(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    b[n].fr=a[n];b[n].sc=n;
    for(int i=n-1;i>=1;i--){
        b[i].fr=b[i+1].fr+a[i];
        b[i].sc=i;
    }
    vector<pair<int,int>> back=b;
    sort(b.begin()+2,b.end(),greater<pair<int,int>>());
    int sum=back[1].fr;
    for(int k=1;k<=n;k++){
        if(k==1){
            cout<<back[1].fr<<" ";
            continue;
        }
        if(k==n){
            int sum=0;
            for(int i=1;i<=n;i++){
                sum+=a[i]*i;
            }
            cout<<sum<<" ";
            continue;
        }
        sum+=back[b[k].sc].fr;
        cout<<sum<<" ";
    }
    cout<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}