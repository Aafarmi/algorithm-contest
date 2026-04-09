#include <bits/stdc++.h>
#define int long long
using namespace std;
void work()
{
    string s ; cin >> s ; 
    int n = s.size() ;
    s = " " + s ;  
    if(s[1] == s[n])
    {
        cout << 0 << endl ;
        return ; 
    }
    int cur = 0 ; 
    for(int i = 2 ; i <= n ; i++)
    {
        cur++ ; 
        if(s[i] == s[i - 1])
        {
            cout << cur << endl ; 
            return ; 
        }
    }
    cout << -1 << endl ; 
}
signed main()
{
    int  t ; cin >> t ; 
    while(t--)
    {
        work() ; 
    }
    return 0 ; 
}