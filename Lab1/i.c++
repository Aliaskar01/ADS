#include <iostream>
#include <deque>
using namespace std;
#define pb push_back
int main()
{
int n;
cin>>n;
string st;
cin>>st;
deque<int>s;
deque<int>k;
for(int i=0;i<st.size();++i)
{
    if(st[i]=='K') k.push_back(i);
    else s.push_back(i);
}
while(!s.empty() and !k.empty())
{
    if(k.front() < s.front()) k.push_back(k.front()+st.size());
    else s.push_back(s.front()+st.size());
    s.pop_front();
    k.pop_front();
}
if(!s.empty() ) cout<<"SAKAYANAGI"<<endl;
else cout<<"KATSURAGI"<<endl;
  return 0;
 
}