#include<bits/stdc++.h>
using namespace std;




parse(string given_expression)
{
    string power="";
    string constant="";
    int power_part=0;
    int constant_part=0;
    int first_bracket=0;
    int second_bracket=0;
    int count_bracket=0;
    vector<string>v;
    bool need_to_divide=false;
    int divide=0,can_divide=0;
    string numerator,denominator;
    for(int i=0;i<given_expression.size();i++)
    {
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
       for(int i=0;i<given_expression.size();i++)
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

   if(first_bracket>constant_part&&count_bracket!=2)
    {
    if(constant_part>0)
    {
        for(int i=1;i<constant_part;i++)
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
   else if(first_bracket<constant_part&&count_bracket!=2)
   {
       for(int i=first_bracket+1;i<second_bracket;i++)
       {
           constant+=given_expression[i];
       }
        cout<<constant;
   }

    else
    {
        if(count_bracket==2)
        {

        for(int i=1;i<j-1;i++)
        {
            constant+=given_expression[i];
        }
         v.push_back(constant);
         constant="";
         for(int i=first_bracket+1;i<second_bracket;i++)
         {
             constant+=given_expression[i];
         }
         v.push_back(constant);


        }
    }
      //  cout<<"3rule"<<endl;
      /* for(int i=0;i<v.size();i++)
       {
           cout<<v[i]<<endl;
       }*/

       string numerator_one="",denominator_one="";
       string numerator_two="",denominator_two="";
       if(need_to_divide==true)
       {
           //cout<<"ok"<<endl;
           for(int i=1;i<k;i++)
           {
               numerator_one+=given_expression[i];
           }
           for(int i=k+1;i<j-1;i++)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          ;i++)
           {
               denominator_one+=given_expression[i];
           }

           cout<<numerator_one<<" "<<denominator_one<<endl;

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

          cout<<numerator_two<<" "<<denominator_two<<endl;

          simplification_numerator_denominator(numerator_two,denominator_two);
       }


}




int main()
{
    string s;
    cin>>s;
    parse(s);

}
