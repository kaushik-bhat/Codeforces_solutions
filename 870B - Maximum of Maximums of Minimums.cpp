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

    ll n,k;
    cin>>n>>k;
    ll a[n];
    f(0,n)
    cin>>a[i];
    if(k==1){
      sort(a,a+n);
      cout<<a[0]<<endl;
    }
    else if(k>=3){
      sort(a,a+n);
      cout<<a[n-1]<<endl;
    }
    else{ 
      cout<<max(a[0],a[n-1])<<endl;
    }

  return 0;
}
