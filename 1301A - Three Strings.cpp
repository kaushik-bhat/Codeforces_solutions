/*
It is very important to notice "For every i (1≤i≤n) you must swap (i.e. exchange) ci with either ai or bi" , you must swap for every i brings a big difference in finding our answer.
It tells us that we must swap either Ai or Bi with Ci each time, it is not that we have a choice.
Let us initialise a variable called count to count the number of swaps(valid) such that after doing those swaps we have Ai = Bi
If this count at the end is equal to n that means the answer is YES because after doing n swaps(ideal method) A and B will be equal
Let us break the problem into cases where we can make a swap and such that the property Ai = Bi will be true
Case 1 :
  Ai = Bi = Ci which means all the three characters at position i are equal so we can swap either Ai or Bi with Ci and still Ai and Bi will be same, therefore we increment count.
Case 2 :
  Ai = Ci (or) Bi = Ci thus we can swap the character in Ci which is equal to Ai or Bi with the character which is different in Ai or Bi therefore after the swap Ai and Bi will be same, increment count.
Except for these two conditions if we encounter any other condition we can just come out of the loop because even if one character in A and B do not match it means A cannot become the same string as B.
The count of swaps can be compared at last to the length of the string which is n, if we can have n swaps such that after each Ai = Bi we print YES else NO.

I hope you found this explanation satisfactory.
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
      string a,b,c;
      cin>>a>>b>>c;
      ll count=0;
      ll len=a.size();
      f(0,len)
      {
        if(a[i]==b[i] && b[i]==c[i])
        {
          count++;
          continue;
        }
        else if(a[i]==c[i] || b[i]==c[i])
        {
          count++;
          continue;
        }
        else
        {
          break;
        }
      }
      if(count == len)
        cout<<"YES"<<endl;
      else
        cout<<"NO"<<endl;
    }

    return 0;

}
