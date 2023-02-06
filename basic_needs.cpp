#include<bits/stdc++.h>
using namespace std;

bool is_digit(char ch)
{
    if((ch>='0'&&ch<='9')||ch=='/') return true;
    else return false;
}



bool is_perfect_square(int num_to_check)
{
     if(sqrt(num_to_check)*sqrt(num_to_check)==num_to_check) return true;
     else return false;
}



long long int convert_string_to_int(string string_to_convert)
{
    long long int converted_int=0,str_len=string_to_convert.size();
    long long int char_index=0,negative=0;

    if(string_to_convert[0]=='-')
    {
        char_index=1;
        negative=1;
    }

    for(int i=char_index;i<str_len;i++)
    {
        converted_int*=10;
        converted_int=(long long int)(string_to_convert[i]-'0');
    }
    if(negative)
    {
        converted_int=-converted_int;
    }
    return converted_int;
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

string remove_brackets(string string_to_remove_brackets)
{
    string removing_bracket;

    for(int i=0;i<string_to_remove_brackets.size();i++)
    {
        if(string_to_remove_brackets[i]!='('&&string_to_remove_brackets[i]!=')')
        {
            removing_bracket+=string_to_remove_brackets[i];
        }
    }
    return removing_bracket;
}


string string_multiply(string mul_str1,mul_str2)
{
    long long int mul_int1=convert_string_to_int(mul_str1);
    long long int mul_int2=convert_string_to_int(mul_str2),int_ans;
    int_ans=mul_int1*mul_int2;

    return convert_int_to_string(int_ans);

}


string adding_root(string str_to_root)
{
    return ("("+str_to_root+"^(1/2))");
}

string adding_root_sign(string str_to_root)
{
     string sign=(string)((char)(251))+"("+str_to_root+")";
     return sign;
}
void simple_numerator_denominator(string& upor,string& niche)
{
    long long int int_upor,int_niche;
    int_upor=convert_string_to_int(upor);
    int_niche=convert_string_to_int(niche);

    long long int niche_final,upor_final;

    upor_final=int_upor/__gcd(int_upor,int_niche);
    niche_final=int_niche/__gcd(int_upor,int_niche);



    if(upor_final<0&&niche_final<0)
    {
        upor_final=abs(upor_final);
        niche_final=niche_final;
    }

    else if((upor_final<0 && niche_final>0)||(upor_final>0 && niche_final<0))
    {
        if(upor_final>0)
        {
            upor_final=-upor_final;
            niche_final=abs(niche_final);
        }
    }
    upor=convert_int_to_string(upor_final);
    niche=convert_int_to_string(niche_final);

}
