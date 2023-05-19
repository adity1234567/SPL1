///uv
#include<stdio.h>
#include<math.h>
#include <string.h>


int extract_power(const char* str)
 {
    int exponent = 0;
    const char* ptr = str;

    while (*ptr != '\0')
    {
        if (*ptr == '^')
        {
            ptr++;
            while (*ptr >= '0' && *ptr <= '9')
            {
                exponent = exponent * 10 + (*ptr - '0');
                ptr++;
            }
            break;
        }
        ptr++;
    }

    return exponent;
}


the_series_of_x(int main_power,int constant,int i)
{
   vector<string>all_x;
   string with_x;
   string new_power=convert_int_to_string(main_power);
   string new_constant=convert_int_string(constant),new_i;
   new_i=convert_int_to_string(i);

   if(i%2!=0)
   {
       with_x="((x^"+new_power+")/"+new_constant+"^"+new_i+")";
       all_x.push_back(with_x);
       with_x="-";
   }
   else
   {
       with_x="((x^"+new_power+")/"+new_constant+"^"+new_i+")";
       all_x.push_back(with_x);
       with_x="+";
   }
   the_series_of_x(main_power-1,constant,i+1);
}

uv_e_mx(string equation)
{
   // char str[] = "x^2*e^(4*x)";
   char* equation1=equation,equation2=equation;
   int power=0,constant=0;
   //for removing
    const char delimiter[] = "*e";
    char* match1 = strstr(equation1, delimiter);
    if (match1 != NULL)
    {
        *match1 = '\0';
    }

    //for using e...
    char* match2 = strstr(equation2, delimiter);
    if (match2 != NULL)
    {
        char* substring = match2 + strlen(delimiter);

    }

   power=extract_power(equation1);
   constant=extract_power(substring);
   int i=1;
    the_series_of_x(new_power,power,i);



}
int main()
{
    string s;
    cin>>s;
}
