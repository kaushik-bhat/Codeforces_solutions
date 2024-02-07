/*
You are given two positive integers a and b. 
We can choose any positive odd integer x (x > 0) and add it to a (or) We can chose any positive even integer y (y > 0) and subtract y from a.
Firstly, let us prove that we can always turn a into b in some finite moves, assuming they are not equal in the first place
Say a > b , difference = a - b , if we subtract 1 from 'a' difference number of times we will get b but we cannot reduce a by 1, but we can just reduce by 2(even) then increase a by 1(odd) thus net change is -1.
Say a , b , difference = b - a, here clearly we can just add 1 to 'a' difference number of times to get b.
Now that we have understood given any a and b we can obtain b from a let us try to find the minimum number of moves required to achieve the same.
There will be 3 cases
Case 1 :
  a = b
  We print 0 because they are already equal and we need not perform any number of operations
Case 2 :
  a > b
  We calculate difference = a - b
  If this difference is even we can print 1 because we know that a can be replaced with a - y where y is even
  If this difference is odd we can print 2 because whatever the odd difference is add 1 to it(to get an even number) you get an even number now subtract that from a, after this add 1(odd) to a to get b.
  This works because difference-1+1 is equal to difference.
  Ex : say a=11 and b=6 difference=5 --> 5+1=6 subtract 6 from 11, after this operation a will be 5 now add 1(odd) to a to get a=6
Case 3 :
  b > a
  We calculate difference = b - a
  If this difference is odd we can print 1 because we know that a can be replaced with a + x where x is odd.
  If this difference is even we can print 2 because whatever the even difference is subtract 1 to it(to get an odd number) you get an odd number now add that to a, after this add 1(odd) to a to get b.
  This works because difference-1+1 is equal to difference.
Something we can notice is our answer is always 0,1,2 therefore never greater than 2.
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
      ll a,b;
      cin>>a>>b;
      if(a==b)
        cout<<"0"<<endl;
      else if (a>b)
      {
        cout<<(((a-b)&1)?"2":"1")<<endl;
      }
      else
      {
        cout<<(((b-a)&1)?"1":"2")<<endl;
      }
    }

    return 0;

}
