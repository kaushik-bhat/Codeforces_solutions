/*
Modular exponentiation is essentially a fast exponentiation technique where the result is computed modulo a given value.
This is done to ensure that the final answer is less than or equal to the specified modulo value, preventing potential overflow issues when dealing with large values.
https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/

If n=1, the door plates can be either 7 or 8 therefore max no of offices is 2
if n=2, 7,8,77,88,78,87 therefore ans=6
if n=3, 7,8,77,88,78,87,777,788,778,787,877,888,878,887 therefore ans=14
We can observe that everytime we increase n its just previous n multiplied by 2 because either 7 or 8 can be added to increase the length of door plate.
What I mean to convey is that to find n=4, all the n=3 door plates remain. For each door plate of length 3, we can add 7 or 8 to get a door plate of length 4.
The number of length 3 door plates is 8, so 8*2=16. Therefore, for n=4, the answer is 14 + 16 = 30
Also we know that 2^0 + 2^1 + 2^2 + 2^3 +.....+ 2^n = 2^(n+1) - 1
For a given length n or positions if only two possiblities is there either 7 or 8 then all combinations is 2^n because each position we have two options.
But for a given n, the total maximum number of door plates will be the sum of the combinations of lengths 1+2+3...+n.
Theres no 2^0 term as door plate with length 0 makes no sense so lets move it to right side of eqn
2^1 + 2^2 + 2^3 +.....+ 2^n = 2^(n+1) - 1 - 2^0 or (2^(n+1)-2)
Thus we have the solution, just plug in the value of n to get the answer now, to implement this in code use fast exponentiation or bit manipulation anything you find easy.
*/
#include <bits/stdc++.h>
using namespace std;

#define f(a,b) for(ll i=a;i<b;i++)
#define ll long long int
#define pb(n) push_back(n)
#define endl "\n"

const ll mod = 10e9+7;

ll fast_expo( ll b , ll a=2)
{
  ll res=1;
  while(b)
  {
   if(b&1)
    res*=a;
   a*=a;
   b=b>>1; 
  }
  return res;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" ,stdin);
    freopen("output.txt", "w" ,stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    
    ll n;
    cin>>n;
    cout<<fast_expo(n+1)-2<<endl;

    return 0;

}
