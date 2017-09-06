#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
  string s;
  int n;
  cin>>n>>s;
  if(s.find("xx")+1)
    cout<<s.find("xx")+1<<endl;
  else
    cout<<n<<endl;
}
