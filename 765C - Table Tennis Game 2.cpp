#include <bits/stdc++.h>
using namespace std;

#define f(a,b) for(ll i=a;i<b;i++)
#define ll long long int
#define pb(n) push_back(n)
#define endl "\n"

const ll mod = 10e9+7;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" ,stdin);
    freopen("output.txt", "w" ,stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  

    ll k,a,b;
    cin>>k>>a>>b;
    if((a<k&&b%k)||(b<k&&a%k))
      cout<<-1<<endl;
    else{
      cout<<(a/k)+(b/k)<<endl;
    }

  return 0;
}
