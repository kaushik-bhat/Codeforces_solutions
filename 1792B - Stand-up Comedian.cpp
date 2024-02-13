/*
You can probably brute force the solution by checking ideal combinations and returning the maximum answer but this approach could result in encountering a TLE (Time Limit Exceeded) error
You can solve this problem in O(1), basically lets say you can devise a formula.
Firstly we should understand that jokes of type a1 should be given more priority because they increase mood of both Alice and Bob by 1 giving us room to do other not liked by either/both jokes.
If a1 = 0 we return 1 because regardless of the type of joke we choose atleast one of their moods become negative and they leave.
Now lets say you have performed a1 jokes, moods of Alice and Bob is a1
Also, note that you can perform a2 and a3 type jokes alternatively, which result in no net change in the moods of Alice and Bob
Say moods of Alice and Bob = 10, you perform a2 type joke now their new mood is Alice=11 Bob=9
Now you perform a3 type joke, now their new mood is Alice=10 Bob=10
Thus no net change, but you can have this no net change alive till min(a2,a3)*2 because
say a2=3,a3=5 Only three times you can do (a2,a3) pair jokes total=6 after that only a3 remains which will decrease Alice's mood
After these steps, we can only perform the remaining a2/a3 type jokes and a4 jokes until either of their moods becomes negative
a1+(min(a2,a3)*2)+min(a1+1,max(a2,a3)-min(a2,a3)+a4)
a1 jokes first
Then pair of a2,a3 jokes until one of them is exhausted = min(a2,a3)*2
After this their mood is a1 so we can do minimum of a1+1(because after these many jokes either/both mood becomes negative) 
(or) max(a2,a3)-min(a2,a3) + a4 --> the max and min difference gives remaining a2/a3 type jokes after one of them is exhausted and a4 the last type of jokes is also considered
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
      ll a1,a2,a3,a4;
      cin>>a1>>a2>>a3>>a4;
      if(a1 == 0){
        cout<<1<<endl;
        continue;
      }
      cout<<a1+(min(a2,a3)*2)+min(a1+1,max(a2,a3)-min(a2,a3)+a4)<<endl;
    }

    return 0;

}
