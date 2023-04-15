#include<bits/stdc++.h>
using namespace std;

vector<int>loop;

void function_for(int i,int n)
{
    if(i>n) return;

    loop.push_back(i);
    function_for(i+1,n);

}
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

    // cout<<numerator<<" "<<denominator<<endl;
    // cout<<numerator_int<<" "<<denominator_int<<endl;
    int numerator_final=numerator_int/gcd(numerator_int,denominator_int);
     int denominator_final=denominator_int/gcd(numerator_int,denominator_int);

      //cout<<gcd(numerator_int,denominator_int)<<endl;
     //cout<<numerator_final<<" "<<denominator_final<<endl;
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


parse(string given_expression)
{
    string power="";
    string constant="";
    int power_part=0;
    int constant_part=0;
    int first_bracket=0;
    int second_bracket=0;
    int count_bracket=0;
    vector<string>constant_list,coefficient_list;
    bool need_to_divide=false;
    int divide=0,can_divide=0;
    string numerator,denominator;


    function_for(0,given_expression.size());


    for(auto i:loop)
    {
      //  cout<<i<<" ";

        if(given_expression[i]=='x')
        {
            constant_part=i;
           // break;
        }
        if(given_expression[i]=='^')
        {
           power_part=i;
          // break;
        }

        if(given_expression[i]=='(')
        {
            first_bracket=i;
            count_bracket++;
          //  break;
        }
        if(given_expression[i]==')')
        {
            second_bracket=i;
           // break;
        }
        if(given_expression[i]=='/')
        {
            need_to_divide=true;
            divide=i;
            can_divide++;
        }

    }

    cout<<need_to_divide<<" "<<divide<<" "<<can_divide<<endl;
  //  cout<<count_bracket<<endl;
   //  cout<<first_bracket<<" "<<second_bracket<<endl;
// cout<<"p.p"<<" "<<power_part<<endl;

     int j,k=0;
          for(auto i:loop)
            {
                if(given_expression[i]=='(')
                {
                    j=0;

                }
                j++;

                if(given_expression[i]==')')
                {
                   break;
                }
                if(need_to_divide==true)
                {
                    if(given_expression[i]=='/')
                    {
                        k=i;
                    }
                }
            }

        cout<<"s.b: "<<j<<" "<<k<<endl;

        /**
          25x

          constant part x ar ageh pojhonto
          so 1 to before x is constant

          **/
   if(first_bracket>constant_part&&count_bracket!=2)
    {
    if(constant_part>0)
    {
        function_for(1,constant_part);
        for(auto i:loop)
        {
            constant+=given_expression[i];
        }

    }
    if(constant_part==0)
    {
        constant="1";
    }
     cout<<constant;
   //ta cout<<constant;

   }
   /**
     (25x)
     **/
   else if(first_bracket<constant_part&&count_bracket!=2)
   {

      function_for(first_bracket+1,second_bracket);

      for(auto i:loop)
       {
           constant+=given_expression[i];
       }
        cout<<constant;
   }

    else
    {
        /**(25)*(25x)

        **/
        if(count_bracket==2)
        {

        for(int i=1;i<j-1;i++)
        {
            constant+=given_expression[i];
        }
         constant_list.push_back(constant);
         constant="";
         for(int i=first_bracket+1;i<second_bracket;i++)
         {
             constant+=given_expression[i];
         }
         coefficient_list.push_back(constant);


        }
    }
      // cout<<"3rule"<<endl;


       string numerator_one="",denominator_one="";
       string numerator_two="",denominator_two="";
       if(need_to_divide==true)
       {
           //cout<<"ok"<<endl;
           int i;
           for(i=1;i<k;i++)
           {
               numerator_one+=given_expression[i];
           }
           for(i=k+1;i<j-1;i++)
           {
               denominator_one+=given_expression[i];
           }

         //  cout<<numerator_one<<" "<<denominator_one<<endl;

           simplification_numerator_denominator(numerator_one,denominator_one);
       }
       if(need_to_divide==true&&can_divide==2)
       {
           for(int i=first_bracket+1;i<divide;i++)
         {
             numerator_two+=given_expression[i];
         }
         for(int i=divide+1;i<second_bracket;i++)
         {
             denominator_two+=given_expression[i];
         }

         // cout<<numerator_two<<" "<<denominator_two<<endl;

          simplification_numerator_denominator(numerator_two,denominator_two);
       }


}




int main()
{
    string s;
    cin>>s;
    parse(s);

}

