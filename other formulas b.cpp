#include<bits/stdc++.h>
using namespace std;

void formula(string s)
{
    int first_bracket=0,power=0;
    int second_bracket=0;
   for(int i=0;i<s.size();i++)
   {
       if(formula[i]=='(')
       {
          first_bracket=i;
       }
       if(formula[i]=='^')
       {
           power=i;
       }
       if(formula[i]==')')
       {
           second_bracket=i;
       }
       if(formula[i]=='+')
       {
           plus1=i;
       }

       if(formula[i]=='-')
       {
           minus1=i;
       }
       //if(formula[i]=='')

   }
   int k;
   ///use parsing
   int value_for_formula1=sqrt(parsing_constant);

   string changed_function="tan^-1(",simplified_function="";
   string added_part="x";

       if(plus1>first_bracket&&plus1<second_bracket)
       {
          simplified_function=changed_function+added_part+"/"+value_for_formula1+")";

       }

    string changed_function="ln(";
    simplified_function="";

    /**a2+(-x2)

  a2-(-x2)
  -a2+x2
  **/
     if(minus1>first_bracket&&minus1<second_bracket)
       {
         simplified_function=changed_function;
       }





}

int main()
{
    string s;
    cin>>s;
}
