/*
The problem is very straight forward and simple. You can solve this problem in O(n).
Key to solving this problem in O(n) lies in noticing that we need not operate on the jar with most honey each time.
Because eventually at some point, every jar will be a valid candidate for the jar with the most honey, so we could pick any jar, ignoring as if others didn't exist
Once we understand this, it becomes a very basic implementation problem.
Case 1 :
  Jar has x kilos of honey where x >= 3*k
  Piglet will get exactly (x - 3*k) kilos of honey
  Ex: Assume only one jar exists where x=10 , k=3 
  [10 - 3 = 7] --> [7 - 3 = 4] --> [4 - 3 = 1] = 1
Case 2 :
   Jar has x kilos of honey where x < 3*k
   Piglet will get exactly (x mod k) kilos of honey
   Ex: Assume only one jar exists where x=10 , k=4
   [10 - 4 = 6] --> [6 - 4 = 2] = 2
   which is the remainder left after Winnie eats exactly k kilos of honey 0/1/2 times from the jar.
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
    freopen("input.txt", "r" ,stdin);
    freopen("output.txt", "w" ,stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll n,k;
    cin>>n>>k;
    ll a[n];
    f(0,n)
      cin>>a[i];
    ll ans=0;
    f(0,n){
      if(a[i]<k)
        ans+=a[i];
      else{
        if(a[i]>=3*k)
        {
          ans+=(a[i]-3*k);
          continue;
        }
        else{
           ans+=(a[i]%k); 
        }
      }
    }
    cout<<ans<<endl;

    return 0;

}
