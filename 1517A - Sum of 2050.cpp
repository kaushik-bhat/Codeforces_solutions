/*
Firstly, if the number n is less than 2050, then we print -1 because it cannot be represented as the sum of any combination of 2050 numbers.
We then check if n is divisible by 2050 because lets assume some number x can be represented as a sum of some 2050 numbers
k = 2050 + 20500 + 205000.... not necessarily this
k will be divisible by 2050 because, each of these numbers is of the form 2050*10^y where y is a whole number and they leave a quotient of 10^y when divided by 2050 thus the number itself is divisble by 2050.
Say n is divisible by 2050 now how can we find the minimum number of 2050 numbers required to get n
Let A = n / 2050
Now the units place digit of A represents the number of 2050 required
Tens place digit of A represents the number of 20500 required (2050 * 10^1)
Hundreds place digit of A represents the number of 205000 required (2050 * 10^2)
and so forth
So basically the problem is reduced to finding the sum of digits of this number A (A = n/2050)
If n is not divisible by 2050 we print -1 because we cannot represent n as a sum of any 2050 numbers combination.
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
      ll n,ans=0,temp;
      cin>>n;
      if(n<2050)
      cout<<-1<<endl;
      else{
        if(n%2050 == 0)
        {
          temp=n/2050;
          while(temp)
          {
            ans+=(temp%10);
            temp/=10;
          }
          cout<<ans<<endl;
        }
        else
          cout<<-1<<endl;
      }
    }

    return 0;

}
