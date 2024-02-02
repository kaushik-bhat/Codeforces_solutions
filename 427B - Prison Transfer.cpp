/*
Firstly lets understand how does selecting groups that are contiguous of size c from size l equal to l-c+1
Lets say we have 10 numbers 1,2,3,4,5,6,7,8,9,10 now we have to select 3 numbers from this such that the 3 numbers are a contiguous part 
Basically we cannnot chose random 3 numbers according to our wish, we have to select (7,8,9) , (3,4,5) , (1,2,3) , (8,9,10) in this fashion
Now how is it equal to 10-3+1 = 8 ?
Start from 1, select the next 2 numbers so totally 3 numbers (1,2,3)
Now go to 2, select in the same way as we did for 1 (2,3,4)
Now move to3, continue the process.
But wait once you reach 9 you have only 10 left (9,10) possible or if you move to 10 we can select only 10.
Therefore the point till which you can continue the above process is until there's minimum c-1 numbers ahead of your number
which is basically (c-1) distance from the last number therefore l-(c-1) = l-c+1
Now lets come to part of understanding the solution.
Iterate through the array of numbers, everytime if you encounter an element greater than t just check the length of sequence you have travelled so far
If it is >=c we can select l-c+1 groups from there of size c each.
Now your length of sequence should be updated to 0 as the number>t should never be included.
You start your sequence again from the next number that is <= t
After iterating the array also you need to update your ans+=(l-c+1) because there might be a sequence at the end of array waiting to be calculated :)

I hope this explanation was satisfactory.
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
    
    ll n,t,c;
    cin>>n>>t>>c;
    ll arr[n];
    f(0,n)
    cin>>arr[i];
    ll l=0,ans=0;
    f(0,n)
    {
      if(arr[i]>t)
      {
        if(l>=c)
       { 
        ans+=(l-c+1);
        l=0;
      }
      else
        l=0;
      }
      else{
        l++;
      }
    }
    if(l>=c)
      ans+=(l-c+1);

    cout<<ans<<endl;
    return 0;

}
