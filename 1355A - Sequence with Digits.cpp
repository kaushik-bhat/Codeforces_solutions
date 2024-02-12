/*
The problem is very straight forward at first glance and brute force implementation seems like the only solution.
Given some number "a(1)" and a value k we have to print the value of "a(k)"
Where a(n) = a(n-1) + [Max_digit_of_a(n-1) * Min_digit_of_a(n-1)]
Example if a(1) = 916 then a(2) = 916 + [9*1] = 925
We can run a loop k times and each time find the digits of the number, use these to get the next number
But this approach gives TLE[TIME LIMIT EXCEEDED] for large values of k for large n values
Slightly tricky but if you took a few examples and solved this problem then you will notice that
There is one lets say important case that will help us to optimise the solution
If our input number or any a(i) at any point if it has 0 as one of its digits then
Regardless of the number of k operations further left to be performed the number remains the same
Because whatever the max digit of that number is minimum digit will always be 0, and product of any number with 0 is 0 itself
NOTE: There is no rule that starting number should have 0 as one of its digits, we should look for 0s at every step and exit accordingly
Ex: say at some point the number is 18053, next number = 18053 + [8*0] = 18053
Now the number remains the same if we perform the operation infinitely
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
    while(t--){
      ll a,k;
      cin>>a>>k;
      ll ans=a;
      ll temp;
      vector<ll> dig;
      f(0,k-1){
        temp = ans;
        dig.clear();
        while(temp){
          if(temp%10 == 0){
            goto one;
          }
          dig.pb(temp%10);
          temp/=10;
        }
      sort(dig.begin(),dig.end());
      ans+=(dig[0]*dig[dig.size()-1]);
      }
      one:
      cout<<ans<<endl;
    }

    return 0;

}
