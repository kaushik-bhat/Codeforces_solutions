#include <bits/stdc++.h>
using namespace std;

#define f(a,b) for(ll i=a;i<b;i++)
#define ll long long int
#define pb(n) push_back(n)
#define endl "\n"

const ll mod = 1e9+7;

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
    sort(a,a+n);
    if(k==n){
      cout<<a[n-1]<<endl;
    }
    else if(k==0){
      if(a[0]==1)
        cout<<"-1"<<endl;
      else
        cout<<1<<endl;
    }
    else{
      if(a[k-1]==a[k])
        cout<<"-1"<<endl;
      else
        cout<<a[k-1]<<endl;
    }

    return 0;

}
