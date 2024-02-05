/*
One of those problems where you have to take a pen and paper just write down some reults, check for patterns and eventually you find the answer.
Firstly let us manually count the number of hexagons located at "exactly n cell distance" from 0th cell in the given figure.
n=1 , there are 6 cells
n=2 , there are 12 cells
n=3 , there are 18 cells
If you are not normal then draw cells after the 3rd that is 4 cell distance ones 
n=4 , there will be 24 cells
and so on; if you found the pattern here, it will be 30 for n=5 and 36 for n=6.
Therefore no of cells exactly at n cell distance are 6*n.
The problem wants us to print the count of all cells not farther than n cell distance
Basically 1 cell distance count + 2 cell distance count + ..... + n cell distance count
We can use Arithmetic Progression to find the sum as clearly 6,12,18,24,...(multiples of 6) are in an Arithmetic progression 
First term a=6, common difference d=6, for finding the first n terms sum we can use any formula n/2[2*a + (n-1)d] or n/2[a+l] where l is the last term or nth term
Substitute the values to get a simplified equation which is n[3 + 3*n]
But remember we left out the 0th cell while counting, so we just add 1 at the end.

Thanks:)
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
    
    ll n;
    cin>>n;
    cout<<(n*(3 + (3*n)))+1<<endl;

    return 0;

}
