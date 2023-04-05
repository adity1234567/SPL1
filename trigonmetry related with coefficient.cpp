#include<bits/stdc++.h>
using namespace std;

void handle_coefficient_and_variable()
{

}
void coefficient(string input,string change_function)
{
    int coefficient_pos_open=0;
     int coefficient_pos_close=0;
     string coefficient="";
    for(int i=0;i<input.size();i++)
    {
        if(input[i]=='(')
        {
            coefficient_pos_open=i;
        }
        if(input[i]=='x'&&input[i+1]==')')
        {
             coefficient_pos_close=i;
        }
    }
    for(int i=coefficient_pos_open+1;i<coefficient_pos_close;i++)
    {
        coefficient+=input[i];
    }

    cout<<coefficient<<endl;
}

void trigonometry(string input)
{
    vector<char>check_function;
    int can_function=0;
    int pos_function=0;

    for(int i=0;i<input.size();i++)
    {
        if(input[i]>='a'&&input[i]<='z')
        {
            if(input[i]!='x')
            {
                check_function.push_back(input[i]);
            }
            pos_function=i;
        }
    }

    string function_is="";
    for(int i=0;i<check_function.size();i++)
    {
        function_is=function_is+check_function[i];
    }

    if(check_function.size()!=1)
    {
        if(function_is=="tansec"||function_is=="sectan")
        {
            function_is="tanxsecx";
        }
        else if(function_is=="coseccot"||function_is=="cotcosec")
        {
          function_is="cotxcosecx";
        }
        else function_is+='x';

    }
    cout<<function_is<<endl;
    string change_function="";
    if(function_is=="sinx")
    {
        change_function+="cos";
    }
    else if(function_is=="cosx")
    {
        change_function+="(-1)*sin";
    }
    else if(function_is=="secx")
    {
       //if(power==2)
       {
           change_function+="tan";
       }
    }
    else if(function_is=="cosecx")
    {
       // if(power==2)
        {
            change_function+="cot";
        }
    }
    else if(function_is=="cotxcosecx")
    {
        change_function+="(-1)*cosec";
    }
    else if(function_is=="tanxsecx")
    {
        change_function+="sec";
    }
    else if(function_is=="e")
    {
        change_function+="e";
    }

    cout<<change_function<<endl;

    coefficient(input,change_function);
}
int main()
{
   string s;
   //cin>>s;
   s="sin(3x)";
   trigonometry(s);
}
