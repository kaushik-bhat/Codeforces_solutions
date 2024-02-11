/*
It is very crucial to start thinking on how to solve the problem in the right direction
Otherwise we might complicate a rather simple solution.
It is very inefficient to iterate through the array and for each element find if there exists equal element to form a team, else find the nearest number then remove those two numbers from the array.
The problem almost solves itself once you sort the input array
Because now students with equal programming skills are together and it is easier to compare
Also even if the very next student's programming skill is not equal it is the closest next value compared to any other student's programming skill.
Now in the sorted array just take consecutive pairs that is student (1,2) , (3,4) , (4,5) ,... and so on
If they are equal then continue to next pair else add the difference between them which is the no of problems the student with lesser skill should solve
This solution at times feels very weird, for example:
Say array is 4,10,6,1,4,6 now sort them to get 1,4,4,6,6,10
First glance at the sorted array tells that it is better to pair (4,4) , (6,6) , (1,10) 10 - 1 = 9 which should be the answer
Because it feels as if pairing (1,4) , (4,6) , (6,10) [this will be pairs according to our algorithm] will give a higher value of problems to be solved as the answer
But magically(mathematically) the answer is 9 even this way.
It is not a coincidence, if you look at it mathematically, though in the first approach you have got more equal skill pairs, the final pair (1,10) will have a big difference.
This big difference itself is encountered in our algorithm but as chunks of smaller differences [(4-1=3),(6-4=2),(10-6=4) total 9]
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
    
      ll n,ans=0;
      cin>>n;
      ll a[n];
      f(0,n)
      {
        cin>>a[i];
      }
      sort(a , a+n);
      for(ll i=0;i<n-1;i+=2)
      {
        if(a[i]==a[i+1])
          continue;
        else
          ans+=(a[i+1]-a[i]);
      }
      cout<<ans<<endl;

    return 0;

}
