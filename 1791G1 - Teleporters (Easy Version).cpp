/*
Easy problem once you understand why sorting helps.
I will be addressing teleporters as tp in my explanation.
There are tps on points 1 to n and you start from point 0.
Let us create an array x of size n x[n] that stores the cost of coins to travel from 0 to that tp and also the cost to use that tp
Let tp cost array be a[n]
x[i] = (i+1) + a[i]
Because you start from 0 and you travel to say the 4th tp it is in index 3 of cost array a, so you do i+1.
a[i] will give the cost to use the tp.
Now we sort this new total cost array x
While we have coins left we just go to the tp and use it, since the total cost is sorted in this way we will use the most number of tps
We shouldnt consider starting from going to the nearest tp because say tp at 1 has cost 100 but tp at 2 has cost 1 its cheaper to travel to tp 2 and use it, we will be saving more coins for further use also.

Too easy?
*/
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
    
    ll t;
    cin>>t;
    while(t--)
    {
      ll n,c;
      cin>>n>>c;
      ll a[n],x[n],ans=0,z;
      f(0,n)
      cin>>a[i];
      f(0,n)
      {
        x[i]=(i+1)+a[i];
      }
      sort(x,x+n);
      z=0;
      while(c-x[z]>=0 && z<n)
      {
        c-=x[z];
        z++;
        ans++;
      }
      cout<<ans<<endl;
    }

    return 0;

}
