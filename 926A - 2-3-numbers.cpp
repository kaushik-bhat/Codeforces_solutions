/*
I feel the problem is not worthy to be categorised under 1300. Maybe?
They give us two numbers l and r, we have to print the count of all numbers between l and r (inclusive) [l,r] which can be represented as 2^x * 3^y
x and y are non negative integers that is 0,1,2.....
Basically all numbers between l and r whose prime factor representation has only 2 and 3 in it
We can directly run two nested loops one for the two's power and other for three's power, we start from 1 because 2^0 and 3^0 both equal to 1 and even that should be included.
We just keep a check inside the loop so that we do not unnecessarily calculate products greater than the given r.
Lets try to understand why the loop works with an example
say l=1 and r=100
lets see for each values of i one by one
Format below: i value , j value then inside [] value of product of i*j [i*j] our number.
i=1 --> j=1 [1], j=3 [3], j=9 [9], j=27 [27], j=81 [81], j=243 [243] but at this point i*j which is 243 is > r which is 100 therefore we break out of this loop, ans at the end of this loop = 5
i=2 --> j=1 [2], j=3 [6], j=9 [18], j=27 [54], j=81 [162] 162>100 therefore we break out of this loop, ans at the end of this loop = 9
i=4 --> j=1 [4], j=3 [12], j=9 [36], j=27 [108] 108>100 therefore we break out of this loop, ans at the end of this loop = 12
i=8 --> j=1 [1], j=3 [24], j=9 [72], j=27 [216] 216>100 therefore we break out of this loop, ans at the end of this loop = 15
i=16 --> j=1 [16], j=3 [48], j=9 [144] 144>100 therefore we break out of this loop, ans at the end of this loop =17
i=32 --> j=1 [32], j=3 [96], j=9 [288] 288>100 therefore we break out of this loop, ans at the end of this loop =19
i=64 --> j=1 [64], j=3 [192], 192>100 therefore we break out of this loop, ans at the end of this loop =20
i=128 but 128 itself is > 100 even if j is 1 it is > r therefore we will be exiting the main loop
ans = 20 and we print that
Also this method takes care of duplicates because each loop i(power of 2) is different thus theres no possibility of repeating numbers.

Too easy!!
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

    ll l,r;
    cin>>l>>r; 
    
    ll ans=0;
    for(ll i=1;i<=r;i*=2){
        for(ll j=1;j<=r;j*=3){
            if((i*j)>=l){
                if((i*j)<=r)
                    ans++;
                else
                    break;
            }
        }
    }
    cout<<ans<<endl;

    return 0;

}
