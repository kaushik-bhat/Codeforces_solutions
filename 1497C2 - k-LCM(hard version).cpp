/*
The problem seems to be very tough at first glance.
Remember always when you have solved/know the solution for the same problem but simpler conditions try changing the complex problem into the simpler problem.
Once you have managed to reduce it to that it is just like solving the earlier simple problem.
Notice that having any number of 1s does not make a difference to your LCM result.
So take (k-3) 1s now we have to find 3 more elements such that sum of (k-3) 1s which is k-3 and the remaining 3 numbers should add up to n.
The 3 numbers should be chosen in such a way that the LCM doesn't exceed n/2.
Basically we have reduced the problem to the previous problem that is k-LCM easy version where our n will be (n-(k-3)) and k=3.
Add everything -> (k-3) = (n-(k-3)) = n
LCM -> (1,1,1,... k-3 times , the 3 numbers to (n-(k-3))) n/2 condition will be taken care of because we can use the same solution used in the easy version problem.

Try reading my explanation to the easy version problem for better understanding.
I hope this helped you understand the code.
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
      ll n,k;
      cin>>n>>k;
      n=n-(k-3);
      while(k>3){
        cout<<1<<" ";
        k--;
      }
      if(!(n&1))
      {
        if(!((n/2) & 1))
          cout<<n/2<<" "<<n/4<<" "<<n/4<<endl;
        else
          cout<<(n/2)-1<<" "<<(n/2)-1<<" "<<2<<endl;
      }
      else
      {
        cout<<n/2<<" "<<n/2<<" "<<1<<endl;
      }
    }

  return 0;
}
