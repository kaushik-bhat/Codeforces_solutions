/*
This problem seems straightforward, but the logic isn't very intuitive, in my opinion.
Because one can think the solution to be cery easy only to discover that some edge cases break your solution.
However, when you work out a few examples on your own and check, it starts making sense.
Firstly, you find the difference in number between the coders (c) and mathematicians (m) and redistribute them to the group of students with no specialization (x).
This is to ensure that we have an equal number of c and m left, which will be utilized to form teams with at least one coder and one mathematician, and the third person being any of the three.
To achieve that, we take the minimum of the three numbers, specifically c(or)m and x, as at this point, c and m are the same.
We subtract this number from our c and m because those students are now already part of a team and cannot be part of other teams.
After all this, if there are any c and m left, we can form teams. So we divide the sum of c and m by 3; these kinds of teams will have 2c 1m or 1c 2m.
The distribution of the difference of c and m initially plays an important role because it ensures that later, at (c+m)/3 after taking the min, we don't end up with teams having only c or m.
If we don't do that, there might be cases where, for example, c=4, m=0, (c+m)/3=4/3=1, but teams are 0 because a team should have at least 1c and 1m.
I hope the explanation was satisfactory.
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
    while(t--){
     ll c,m,x,ans=0;
     cin>>c>>m>>x;
     x+=(max(c,m)-min(c,m));
     if(c>=m)
      c-=(max(c,m)-min(c,m));
    else
      m-=(max(c,m)-min(c,m));
    ans=min(min(c,m),x);
    c-=ans;
    m-=ans;
    ans+=((c+m)/3);
    cout<<ans<<endl;
  }
}
