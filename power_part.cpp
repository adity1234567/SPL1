#include<bits/stdc++.h>
using namespace std;

void power_part(string s)
{
    int power_part=0;
    int power=0;
    string power_one="";
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='x'&&s[i+1]=='^')
        {
           power_part=i+1;
           power++;
        }
    }

    if(power==1)
    {
      for(int i=power_part+1;i<s.size();i++)
      {
          power_one=power_one+s[i];
      }
    }
    cout<<power_one<<endl;

}
int main()
{
   string s;
   cin>>s;
   power_part(s);
}
