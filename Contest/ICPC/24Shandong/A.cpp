#include <bits/stdc++.h>
#define int long long
using namespace std;
void work()
{
    int n , k ;
    cin >> n >> k ; 
    int lo = 0 ; 
    int r = 2e18 ; 
    vector<int>t(n+10),l(n+10),w(n+10);
	for(int i=1;i<=n;i++)cin>>t[i]>>l[i]>>w[i];
    auto check = [&](int mid)->bool{
        int sum = 0 ; 
        for(int i = 1 ; i <= n ; i++)
        {
           int z=mid/(t[i]*l[i]+w[i]);
		   int s=mid%(t[i]*l[i]+w[i]);
		   s=min(s/t[i],l[i]);
		   sum=sum+z*l[i]+s;
		   if(sum>=k)return true;
        }
        return sum>=k;
    }; 
    while(lo < r)
    {
        int mid = (r+lo)>>1;
        if(check(mid))
        {
            r = mid; 
        }
        else
        {
            lo = mid + 1 ; 
        }
    }
    cout << lo << '\n'; 
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