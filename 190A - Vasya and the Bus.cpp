/*
Lets dive into understanding the problem directly.
When can our answer be Impossible? When there are no adults in the bus but there are children i.e., n=0 and m>=1
Note when there are no adults and no children on the bus i.e., n=0 m=0 we shouldn't print Impossible.
Now lets make some case to find min and max bus fare
Case 1 :
  Calculating the minimum bus fare
  We know that for each adult one child travelling with him/her gets a free ticket and other children travelling with the same adult are charged one ruble each.
  Therefore we can assign in such a way that every adult gets atleast 1 child with them thus their fare is 0 and the remaining kids can be included in the fare.
  If no of adults is equal to or greater than the number of children on bus, all the children can travel for free as each one can be assigned an adult therefore min = n (no of adults).
  If not then min = n + (m - n) becuase all adults must pay 1 ruble each which adds up to n, all the remaining children after assigning each adult to a child will be charged 1 ruble each (m-n).
Case 2:
  Calculating the maximum bus fare
  We know that only one child assigned to an adult will get a free bus ticket whereas if anymore children are assigned to the same adult they will be charged 1 ruble each.
  Therefore the maximum bus fare will be when all children are assigned to a single adult.
  If there are children present on the bus
  max = n + (m-1) one child gets a free bus ticket and all other remaining children and the n adults are charged 1 ruble each.
  Else if there are no children present on the bus
  max = n which is just the no of adults.
  
Yes the solution is that simple!!
*/
#include <bits/stdc++.h>
using namespace std;

#define f(a,b) for(ll i=a;i<b;i++)
#define ll long long int
#define pb(n) push_back(n)
#define endl "\n"

const ll mod = 1e9+7;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" ,stdin);
    freopen("output.txt", "w" ,stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    
    ll n,m;
    cin>>n>>m;
    if(n==0 && m>=1)
      cout<<"Impossible";
    else{
      ll min,max;
      if(n==m || n>m){
        min=n;
      }
      else{
        min=n+(m-n);
      }
      if(m)
        max=n+m-1;
      else
        max=n;
      cout<<min<<" "<<max;
    }

    return 0;

}
