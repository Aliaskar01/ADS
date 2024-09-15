#include <bits/stdc++.h> 
using namespace std; 
int main() 
{ 
 int t;cin>>t; 
 while (t--) 
 { 
  int n;cin>>n; 
  vector<int> nxt(n),prv(n),answer(n); 
  for (int e = 0;e<n;e++) 
  { 
   nxt[e] = (e+1)%n; 
   prv[e] = (e-1+n)%n; 
  } 
  int curr = 0; 
  for (int e = 1;e<=n;e++) 
  { 
   for (int x = 1;x<=e;x++) 
   { 
    curr = nxt[curr]; 
   } 
   nxt[prv[curr]] = nxt[curr]; 
   prv[nxt[curr]] = prv[curr]; 
   answer[curr] = e; 
   curr = nxt[curr]; 
  } 
  for (int i : answer) cout<<i<<" "; 
  cout<<"\n"; 
 } 
    return 0; 
}