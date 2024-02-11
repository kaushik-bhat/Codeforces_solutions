/*
"A pair of two consecutive members u and v on a line is considered photogenic if their average height is an integer, i.e. (au+av)/2 is an integer."
Any number by 2 is an integer only when the number itself itself is even.
We know that -->
odd number + odd number (or) even number + even number = even number
even number + odd number (or) odd number + even number = odd number
Therefore, we have to ensure that our answer has the highest number of photogenic pairs.
We can achieve this by placing all members with odd heights first, followed by all members with even heights (or vice versa also works).
Let us take a random array of numbers for example and understand why this works
1,3,11,17,45,22,16,72
Every consecutive pair satisfies the required condition except for one pair that is 45,22 which is basically the point of meeting of odd and even numbers
Any other approach will have more pairs of odd and even numbers thus not achieving the maximum expected answer.
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
      ll n;
      cin>>n;
      ll a[n];
      vector<ll> odd;
      vector<ll> even;
      f(0,n)
      {
        cin>>a[i];
        if(a[i]&1)
          odd.pb(a[i]);
        else
          even.pb(a[i]);
      }
      for(auto x:odd)
        cout<<x<<" ";
      for(auto x:even)
        cout<<x<<" ";
      cout<<endl;
    }

    return 0;

}
