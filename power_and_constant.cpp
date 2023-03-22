#include<bits/stdc++.h>
using namespace std;



long long int convert_string_to_int(string string_to_convert)
{
    long long int converted_int=0;
    long long int str_len=string_to_convert.size();
    long long int char_index=0,negative=0;

    if(string_to_convert[0]=='-')
    {
        char_index=1;
        negative=1;
    }

    for(int i=char_index;i<str_len;i++)
    {
        converted_int*=10;
        converted_int+=(long long int)(string_to_convert[i]-'0');
    }
    if(negative)
    {
        converted_int=-converted_int;
    }
    return converted_int;
}



void power_and_constant(string power,string constant)
{


   set<char>power_check;
   int store=0;
   for(int i=0;i<power.size();i++)
   {
        power_check.insert(power[i]);
        if(power[i]=='/')
        {
          store=i;
          break;
        }
   }
   string numerator_power="",denominator_power="";


   int numerator_two_int=0,denominator_two_int=0;
   if (power_check.find('/')!= power_check.end())
   {
       for(int i=0;i<store;i++)
       {
         numerator_power+=power[i];
       }

      numerator_two_int=convert_string_to_int(numerator_power);
      numerator_two_int++;
      for(int i=store+1;i<power.size();i++)
      {
          denominator_power+=power[i];
      }
      denominator_two_int=convert_string_to_int(denominator_power);
   }
   else
   {
       numerator_two_int++;
   }


   string numerator_constant="",denominator_constant="";
   int numerator_constant_int=0,denominator_constant_int=0,store1=0;
   set<char>constant_check;
   for(int i=0;i<constant.size();i++)
   {
        constant_check.insert(constant[i]);
        if(constant[i]=='/')
        {
          store1=i;
          break;
        }
   }


   cout<<"i:"<<store1<<endl;

       if(constant_check.find('/')!= constant_check.end())
       {
            for(int i=0;i<store1;i++)
       {
         numerator_constant+=constant[i];
       }
      // cout<<numerator_constant<<endl;
      numerator_constant_int=convert_string_to_int(numerator_constant);

      for(int i=store1+1;i<constant.size();i++)
      {
          denominator_constant+=constant[i];
      }
      denominator_constant_int=convert_string_to_int(denominator_constant);
       }
   else
   {
       numerator_constant_int=convert_string_to_int(constant);
       denominator_constant_int=1;
   }


   //cout<<numerator_two_int<<" "<<denominator_two_int<<endl;
   //cout<<numerator_constant_int<<" "<<denominator_constant_int<<endl;

   cout<<numerator_two_int*numerator_constant_int<<"/"<<denominator_two_int*denominator_constant_int<<endl;
}
int main()
{
    string power="3/2",constant="3/2";//12/4
    //cin>>s;
    power_and_constant(power,constant);
}
