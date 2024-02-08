/*
Let us first understand some properties of LCM
LCM( x , n*x) =  n*x where n is a natural number [1,2,3,4......]
Lets take an example LCM(2,6) = 6 (6=3*2) , LCM(5,40) = 8 (40=8*5)
Now in the question given some l and r values, we have to print x and y such that l<=x<y<=r [Note : x is note equal to y]
Though there might be many solutions to this problem let us take the most intuitive or easy to understand approach
Let us choose l as our first number(x), clearly we cannot choose a smaller value for x
Since y cant be equal to x, the very next multiple of x is 2*x which will be 2*l because x=l in our approach
Now check if this second number(y) 2*l is lesser than or equal to <= r
If yes then we can print l(x) and 2*l(y), satisfies y>x condition and as LCM(l,2*l) will be 2*l even the LCM condition is satisfied.
Else we print -1 -1 because there are no other solutions.
Now let us understand why no values of x and y exist if 2*l is not less than equal to r [<=]
Say you pick any number between l and r, now since x and y cannot be the same numbers and y should be <=r
It is ideal to chose 2*x as y, because it is the very next multiple now if this is <=r we have obtained our solution
If you observe choosing a small value of x increases our chance of passing the 2*x<=r case as l is the smallest possible value for x
Thus checking 2*l <= r takes care of everything.
I hope the explanation was clear enough.
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
      ll l,r;
      cin>>l>>r;
      if(2*l<=r)
        cout<<l<<" "<<2*l<<endl;
      else
        cout<<"-1 -1"<<endl;
    }

    return 0;

}
