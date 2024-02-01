/*
I personally liked solving this problem. My approach to solving such problems is to take a pen and paper and solve a few exxamples.
You might find some pattern or logic that lies hidden.
Now coming to the solution.
We know that we have to output 3 integers say x,y,z such that x+y+z = n and LCM(x,y,z) <= (n/2).
There are some interesting properties or rather lets say results involving LCM.
LCM(1,num)=num -> when finding LCM of two numbers if one of those numbers is 1 then LCM is always the other number.
LCM(num,num) -> LCM of two numbers that are equal is always the number itself.
LCM(num,2) -> if number is even then LCM is always equal to num.
Lets break this complex(kind of) problem to simpler problems and solve them individually(Modular approach).
Case 1 : n is odd
  when n is odd n/2 in programming languages gives an integer result. Say n=11 though n/2 is 5.5 we get 5 as the answer.
  So what if we take 2 numbers to be equal to n/2 and n/2 and the third number to be 1.
  We lost 0.5 and 0.5 in each of the first two numbers because 11/2 gave 5 though its 5.5, which is compensated with the third number 1 now their sum is n which satisfies the first condition.
  regarding the LCM part 2 of the 3 numbers are equal and the third is 1, 1 isnt much of a problem and as the other two numbers are same LCM comes out to be n/2 always whatever n we take.
Case 2 : n is even
  Here we willll have to make two sub cases again
  Case 2.1 : n/2 is even
    say n=20, now n/2=10 which is even
    We can observe that we could take n/2 and n/2 as two numbers but we cannot take the third number to be 0 we fall short by 1
    So we just divide the second n/2 by half giving us two new numbers n/4 (20 / 4 = 5 in this case) the two n/4 will add up to n/2 and the first n/2 all together satisfy the sum n condition.
    What is LCM(n/2 , n/4) it will always be n/2 if n/2 is even because we just have to multiply n/4 by 2 to get n/2.
    Thus we have also satisfied the second condition of LCM(n/2 , n/4 , n/4) <= n/2
  Case 2.2 : n/2 is odd
    This could work like the previous 2.1 case but unlike that case LCM(n/2 , n/4) will not be n/2 because as n/2 itself is odd n/4 will not be exactly half of n/2
    Ex: say n=22 then n/2=11 now n/4 will yield 5, LCM(11,5) != 11.
    Thus we observe and make use of the fact that as n/2 is odd, we for sure know that (n/2)-1 will be even so let us take two (n/2)-1 as our numbers.
    As n was even and the two numbers are (n/2)-1 we fall short by 2 with respect to the sum n condition. Let us include the 2 to satisfy the sum condition.
    Now regarding the LCM condition LCM will be always (n/2)-1 as it is even the 2 will not cause a problem and anyways the other two numbers are equal.

I hope the explanation was helpful.
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
      ll n,k;
      cin>>n>>k;
      if(!(n&1))
      {
        if(!((n/2) & 1))
          cout<<n/2<<" "<<n/4<<" "<<n/4<<endl;
        else
          cout<<(n/2)-1<<" "<<(n/2)-1<<" "<<2<<endl;
      }
      else
      {
        cout<<n/2<<" "<<n/2<<" "<<1<<endl;
      }
    }
 
    return 0;
 
}
