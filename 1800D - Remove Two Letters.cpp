/*
Using brute force techniques like probably using a set(STL) to store each string combination after removing every consecutive letter will give memory limit exceeded error
It is possible to solve this problem in O(n) with constant space complexity
Firstly let us see how many combinations(max) we can get after removing every two consecutive character pair from a string
Let string s="abcde" length n=5, remove "ab" to get "cde", remove "bc" to get "ade", do this exhaustively
Different strings are ["cde","ade","abe","abc"] count = 4
We can try this method out for some more examples and figure out that the maximum different strings you get is never greater than n-1 where n is length of the string
In this case all the strings obtained are unique this need not be the case each time, it is just that we have established an upper bound to the answer
Let us try to uncover some more pattern by looking at examples:
say, s="aaabbcd" remove the first two "aa" to get "abbcd", but you notice that on removing the next two "aa"(2,3) also you get "abbcd"
but say, s="aabbcd" remove the first two "aa" to get "bbcd", next remove "ab" to get "abcd"
let s="aaaabbcd",remove the first two "aa" to get "aabbcd", and you get "aabbcd" on removing "aa" position (2,3) and (3,4) [1-based]
On working out more examples we can find out that for any character considering we are removing it and the next character
If the previous and next characters with respect to that character are same we get a string which is not unique
Even logically if you give it a thought, when (i-1,i+1)are equal removing (i,i+1) characters makes (i-1,i+2) as consecutive letters
i-1 is same as i+1 therefore i+2 has the same neighbour even though we removed two consecutive previous letters
Everytime we encounter this condition we can subtract 1 from our answer which should be initialised to n-1 at first, because we are sure that this string is not unique
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
      ll n;
      cin>>n;
      string s;
      cin>>s;
      ll ans=n-1; //(no of possible deletions)
      for (ll i = 1; i + 1 < n; ++i) {
        if (s[i - 1] == s[i + 1]) {
            ans--;
        }
    }
    cout<<ans<<endl;
    }
}
