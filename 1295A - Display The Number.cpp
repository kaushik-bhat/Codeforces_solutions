/*
Firstly let us write down the number of segments that need to be turned on for each number
0 = 6
1 = 2
2 = 5
3 = 5
4 = 4
5 = 5
6 = 6
7 = 3
8 = 7
9 = 6
It is very intuitive to think for a given n, exhaustively turn on number 9's then probably 8's or some different approach that seems like we are printing very big integer
But it is very important to understand that if you take the number that requires the least no of segments to be turned on you can display a number that has more number of digits itself
Number 1 requires only 2 segments, say n=6 though 9>1 if we use the 6 segments to display 9 the answer is wrong because we can use the same 6 segments to display number 111
Therefore if n is even we can just print n/2 1's which is technically the biggest number we can display, cause the digits in that number itself is n/2 no other approach even comes close to this.
How do you solve the problem if n is odd?
Notice that to print 7 we need only 3 segments, the secong lowest in the list
say n=11 use 8 segments to display 4 1's and the remaining 3 to print 1 7 but the order makes a lot of difference
because 71111 > (17111 , 11711 , 11171 , 11117)
So if n is odd let the first digit from right be 7 and the remaining numbers be 1's to the left.
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
      string ans="";
      ll n;
      cin>>n;
      while(n)
      {
        if(n&1)
        {
          ans+="7";
          n-=3;
          continue;
        }
        ans+="1";
        n-=2;
      }
      cout<<ans<<endl;
    }

    return 0;

}
