#include<bits/stdc++.h>
using namespace std;


int gcd(int a, int b)
{
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }
    if (a == 0) {
        return b;
    }
    return a;
}


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


string reverse_sttring(string s)
{

}
string convert_int_to_string(long long int int_to_convert)
{
    string new_string,temp_string;
    int negative=0,last_digit=1;

    if(int_to_convert<0)
    {
        negative=1;
        int_to_convert=-int_to_convert;
    }
    while(int_to_convert>0)
    {
        last_digit=int_to_convert%10;
         temp_string+=(char)(last_digit+'0');
        int_to_convert=int_to_convert/10;
    }
    int temp_str_length=temp_string.size();
    if(negative)
    {
        new_string+="-";
    }
    for(int i=temp_str_length-1;i>=0;i--)
    {
        new_string+=temp_string[i];
    }

    return new_string;






}
void simplification_numerator_denominator(string numerator,string denominator)
{

     int numerator_int=convert_string_to_int(numerator);
     int denominator_int=convert_string_to_int(denominator);

     cout<<numerator<<" "<<denominator<<endl;
     cout<<numerator_int<<" "<<denominator_int<<endl;
    int numerator_final=numerator_int/gcd(numerator_int,denominator_int);
     int denominator_final=denominator_int/gcd(numerator_int,denominator_int);

      cout<<gcd(numerator_int,denominator_int)<<endl;
     cout<<numerator_final<<" "<<denominator_final<<endl;
     if(numerator_final<0&&denominator_final<0)
     {
         numerator_final=abs(numerator_final);
         denominator_final=abs(denominator_final);
     }
     else if((numerator_final<0&&denominator_final>0)||(numerator_final>0&&denominator_final<0))
     {
         if(numerator_final>0)
         {
             numerator_final=-numerator_final;
             denominator_final=abs(denominator_final);
         }
     }


     string numerator_string=convert_int_to_string(numerator_final);
     string denominator_string=convert_int_to_string(denominator_final);


    cout<<numerator_string+"/"+denominator_string<<endl;

     ///jkhn minus lagbe tkhn minus kore dis....


}

int main()
{
    string a="9",b="15";
    simplification_numerator_denominator(a,b);

}
