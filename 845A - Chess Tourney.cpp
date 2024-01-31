/*
This problem becomes very easy once you understand the logic.
Say you have 2*n players where each player has a rating Ri.
Now sort them in ascending order.
We want the first team to win always(each pair), remember win and not a draw/loss.
We just have to check if the rating of the nth player Rn is strictly less than(<) that of the (n+1)th player.
If this holds true then the answer is YES else NO.
Now let us understand with an example why this works.
say n=3, there are 6 players with the ratings 20,60,40,30,10,50 (we just have to concentrate on choosing the best players to team 1)
after sorting 10,20,30,40,50,60 compare rating of 3rd and 4th player, clearly 30<40 thus we can say yes
Because we can always be 100% sure that in a sorted array, if Rn < R(n+1) for all Rx where x > (n+1) will be greater than or equal to R(n+1) 
and for all Ry where y < n will be lesser than or equal to Rn
Thus we can include players with ratings from R(n+1) to R(2*n) in the first team and R1 to Rn in the second team ensuring for each pair first team wins always.
Now if the Rn < R(n+1) conditions fails which is Rn = R(n+1) [remember > never possible in a sorted array] clearly for that one pair the result will be a draw even if ideally we make teams
and we can conclude the answer is NO without even considering to check other pairs.
Hope this helped you understand the logic.
Thank you!
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
    ll size=2*n;
    ll a[size];
    f(0,size)
    cin>>a[i];
    sort(a,a+size);
    if(a[n-1]<a[n])
      cout<<"YES";
    else
      cout<<"NO";
    return 0;

}
