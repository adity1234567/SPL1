#include<bits/stdc++.h>
using namespace std;

vector<int>loop;

void function_for(int i,int n)
{

    if(i>=n) return;

    loop.push_back(i);
    //cout<<i<<" ";
   // cout<<endl;
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

int square(int num)
{
    return num*num;
}

#define it_can_be if

string reverse_string(string s)
{
    stack<char> st;

    string p="";
    for (char x : s) st.push(x);
    while (!st.empty())
    {
        p+=st.top();
        st.pop();
    }
    return p;
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


string simplification_numerator_denominator(string numerator,string denominator)
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

     string ans=numerator_string+"/"+denominator_string;

     cout<<"simplified string is: "<<ans<<endl;
     return ans;

     ///jkhn minus lagbe tkhn minus kore dis....


}

string constant_with_coefficient(string constant_list,int size_constant_list,string coefficient_list,int size_coefficient_list,bool need_to_divide)
{


   // cout<<size_constant_list<<endl;
    int constant=0,coefficient=0;

        constant+=convert_string_to_int(constant_list);
       // constant*=10;

    cout<<constant<<endl;


    coefficient+=convert_string_to_int(coefficient_list);
       //coefficient*=10;

    cout<<coefficient<<endl;
  //  int constant=string_to_int(constant_list);
   // int coefficient=string_to_int(coefficient_list);
    int result=0;
    if(need_to_divide==false)
    {
        result=constant*coefficient;
    }

    string result_main=convert_int_to_string(result);
    return result_main;
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


     string main_function="x";
     string power1="^";
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

   if(denominator_two_int*denominator_constant_int!=1)
   {
       cout<<"("<<numerator_two_int*numerator_constant_int<<"/"<<denominator_two_int*denominator_constant_int<<")*";

       cout<<main_function<<power1<<"("<<numerator_two_int<<"/"<<denominator_two_int<<")"<<endl;
   }
   else
   {
       cout<<"("<<numerator_two_int*numerator_constant_int<<")";

       cout<<main_function<<power1<<numerator_two_int<<endl;
   }
}

void calculate_power_part(string s,string constant,bool can_divide)
{
    int power_part=0;
    int power=0;
    //bool can_divide=false;
    string power_one="";
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='x'&&s[i+1]=='^')
        {
           power_part=i+1;
           power++;
        }
        if(s[i]=='/')
        {
            can_divide=true;
        }
    }

    if(power==1)
    {
      for(int i=power_part+1;i<s.size()-1;i++)
      {
          power_one=power_one+s[i];
      }
    }

    cout<<"power: "<<power_one<<" constant: "<<constant<<endl;
   if(can_divide==false)power_and_constant(power_one+"/1",constant+"/1");
    else power_and_constant(power_one+"/1",constant);

}

void trigonmetry_with_coefficient(string input,string change_function,string coefficient,string constant)
{
    //coefficient(input,change_function,coefficient);

     string main_function="x";
    /*int coefficient_pos_open=0;
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

    cout<<coefficient<<endl;*/

     //coefficient(input,change_function,coefficient);

     cout<<"constant: "<<constant<<" coefficient: "<<coefficient<<endl;
    if(constant!="1")
    {
        if(coefficient!="")
        {
          //cout<<"1st"<<endl;
          simplification_numerator_denominator(constant,coefficient);
          cout<<"("<<constant<<"/"<<coefficient<<")"<<change_function+"("+coefficient+main_function+")"<<endl;
        }
        else
        {
           cout<<constant<<change_function+"("+coefficient+main_function+")"<<endl;
        }

    }

    else
    {
       // constant=1;
        // cout<<"2nd"<<endl;
        if(coefficient=="")
        {
            cout<<"2nd 1"<<endl;
            cout<<change_function+main_function<<endl;
        }
        else
        {
            simplification_numerator_denominator(constant,coefficient);
            cout<<"("<<constant<<"/"<<coefficient<<")"<<change_function+"("+coefficient+main_function+")"<<endl;
        }
    }
}

void calculate_trigonmetry_part(string input,string coefficient,string constant)
{
    vector<char>check_function;
    int can_function=0;
    int pos_function=0;

    cout<<input<<endl;
    bool a_power=false;
    for(int i=0;i<input.size();i++)
    {
        if(input[i]>='a'&&input[i]<='z')
        {
            //cout<<"ok1"<<endl;
            if(input[i]!='x')
            {
                check_function.push_back(input[i]);
            }
            pos_function=i;

            ///5*sec^2(mx)
            if(input[i]!='x'&&input[i+1]=='^')
            {
                if(input[i+2]=='2')
                {
                    a_power=true;
                   // check_function.push_back(input[i]);
                }
            }
        }

    }

    string function_is="";
    for(auto i:check_function)
    {
        cout<<i<<" ";
    }
    cout<<endl;
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
        else if(a_power==true)
        {
            if(function_is=="sec")
            {
                function_is="sec^2x";
            }
            else if(function_is=="cosec")
            {
                function_is="cosec^2x";
            }
        }
        else function_is+='x';

    }
    //else if(check_function.size()==1)function_is="x";
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

           change_function+="tan";

    }
    else if(function_is=="cosecx")
    {
       // if(power==2)

            change_function+="cot";

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
    else if(function_is=="sec^2x")
    {
        change_function+="tan";
    }
    else if(function_is=="cosec^2x")
    {
        change_function+="(-1)*cot";
    }

    cout<<"change function: "<<change_function<<endl;

    trigonmetry_with_coefficient(input,change_function,coefficient,constant);
}



void  formula_with_constant(string main_string,string change_function,string constant,int can_minus,int can_plus,string coefficient,bool is_coefficient)
{
    int int_constant=convert_string_to_int(constant);
    int_constant=2*int_constant;
    string string_constant=convert_int_to_string(int_constant);
    string constant_is,plus1="+",minus1="-";
    string main_function="x";
    string a_by_b="";

    it_can_be(is_coefficient==true)
    {
        int int_coefficient=convert_string_to_int(coefficient);
        cout<<"before main coefficient: "<<int_coefficient<<" "<<int_constant<<endl;
        a_by_b=simplification_numerator_denominator(constant,coefficient);
        int_coefficient=int_coefficient*int_constant;
        cout<<"after: "<<int_coefficient<<endl;
        string string_coefficient=convert_int_to_string(int_coefficient);

        constant_is=simplification_numerator_denominator("1",string_coefficient);
    }
    it_can_be(is_coefficient==false)
    {
        constant_is=simplification_numerator_denominator("1",string_constant);
    }

    cout<<"constant is: "<<constant_is<<endl;

    cout<<"("<<constant_is<<")"<<change_function<<"(("<<a_by_b+plus1<<main_function<<")/("<<a_by_b+minus1+main_function<<")"<<endl;
}


/// calcute_formulas(given_expression,pos_of_constant,pos_of_x,is_plus, is_minus,constant,coefficient,is_coefficient);

void calcute_formulas(string formula,int pos_constant,int pos_of_x,bool is_plus,bool is_minus,string constant,string coefficient,bool is_coefficient)
{
    ///1/((25^2-(6*x)^2)
    string change_function="";
    string main_function="x";
    int can_plus=0,can_minus=0;

    if(pos_constant<pos_of_x)
    {
        if(is_plus==true)
        {
            change_function+="tan^-1";
            can_plus++;
        }
        else if(is_minus==true)
        {
          change_function+="ln";
          can_minus++;
        }

    }
    else
    {
        if(is_minus==true)
        {
          change_function+="ln";
          can_minus++;
        }
    }

    cout<<"calculate formula-change function: "<<change_function<<endl;

    ///string main_string,string change_function,string constant,int can_minus,int can_plus
    ///formula_with_constant(string main_string,string change_function,string constant,int can_minus,int can_plus)
    formula_with_constant(formula,change_function,constant,can_minus,can_plus,coefficient,is_coefficient);
}

parse(string given_expression)
{
    string power="";
    string constant="",constant_co="";
    string coefficient="",coefficient_co="";
    int power_part=0;
    bool exist_power=false;
    bool exist_constant=false;
    bool exist_coefficient=false;
    bool is_trigonmetry=false;
    int constant_part=0;
    int first_bracket=0;
    int second_bracket=0;
    int count_bracket=0;
    int size_of_constant=0;
    int size_of_coefficient=0;
    bool only_x=false;
    int two_power=0;
    vector<string>constant_list,coefficient_list;
    bool need_to_divide=false;
    int divide=0,can_divide=0;
    string numerator,denominator;
   //  vector<int>loop;

   int pos=0;
    function_for(0,given_expression.size());


    for(auto i:loop)
    {
      //  cout<<i<<" ";

        if(given_expression[i]=='*')
        {
            constant_part=i;
            exist_constant=true;
           // break;
        }
        if(given_expression[i]=='^')
        {
           power_part=i;
           exist_power=true;
           two_power++;///a^2+x^2 yes or not

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
        ///5*sin(mx)

        if(given_expression[i]>='a'&&given_expression[i]<='z')
        {
            if(given_expression[i]!='x')
            {
                pos=i;
               is_trigonmetry=true;
            }
        }

        if(given_expression[i]=='x')
        {
            only_x=true;
        }




    }

   // cout<<"is_trigonmetry: "<< is_trigonmetry<<" pos: "<<pos<<endl;

   // cout<<need_to_divide<<" "<<divide<<" "<<can_divide<<endl;
//cout<<count_bracket<<endl;
   //  cout<<first_bracket<<" "<<second_bracket<<endl;
// cout<<"p.p"<<" "<<power_part<<endl;


///working for  terms--->>
///----------------------------
    int check = 0;
    int count_term=1;
    int count_sign=0;
    int arr_terms_pos[100];
    memset(arr_terms_pos,0,sizeof(arr_terms_pos));

    stack<char>signs_of_expression;
    vector<int>terms_pos;

    ///(1/(2^2+(3*x)^2))+(3*x^2)+(x)

    int another_check=0;
    while (check<=given_expression.size())
        {
        switch (given_expression[check])
         {
            case '+':
                //cout << "got it +" << endl;
                if (signs_of_expression.empty())
                {
                    terms_pos.push_back(check);
                    arr_terms_pos[another_check]=check;

                    count_term++;
                    another_check++;
                }
                break;
            case '-':
                //cout << "got it -" << endl;
                if (signs_of_expression.empty())
                {
                    terms_pos.push_back(check);
                    arr_terms_pos[another_check]=check;

                    another_check++;
                    count_term++;
                }
                break;
            case '(':
                //cout << "got it (" << endl;
                signs_of_expression.push('(');
                break;
            case ')':
                //cout << "got it )" << endl;
                signs_of_expression.pop();
                break;
        }
        check++;
    }

    cout << "count_term: " << check << " " << count_term << endl;


///19/4/2023
///korbo j terms_pos pojhonto shb gula elements insert korbo

     string term1="";

     for(int i=0;i<terms_pos[0];i++)
     {
         term1+=given_expression[i];
     }
     cout<<term1<<endl;

     for(int i=0;i<count_term-1;i++)
     {
        cout<<arr_terms_pos[i]<<endl;
     }
    count_term--;

    int pos_checker=0;

    vector<string>terms_string;
    string add_terms="";
    cout<<"now term is: "<<count_term<<endl;
      while(count_term!=0){
        for(int i=arr_terms_pos[pos_checker]+1;i<arr_terms_pos[pos_checker+1];i++)
        {
           add_terms+=given_expression[i];

           cout<<add_terms<<endl;
        }
         pos_checker++;

         cout<<add_terms<<endl;
        terms_string.push_back(add_terms);
        count_term--;
        add_terms="";
    }
    for(int i=0;i<terms_string.size();i++)
    {
        cout<<terms_string[i]<<endl;
    }

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

            loop.clear();

       // cout<<"s.b: "<<j<<" "<<k<<endl;

        /**
          5*(x^5)

          constant part x ar ageh pojhonto
          so 1 to before x is constant

          **/

          cout<<"constant part: "<<constant_part<<endl;
   if(first_bracket>constant_part&&count_bracket!=2)
    {
       // cout<<"5*(x)^5"<<endl;
    if(exist_constant==true)
    {
        function_for(0,constant_part);
        for(auto i:loop)
        {
            constant+=given_expression[i];
        }

    }
    else if(exist_constant==false)
    {
        constant="1";
    }
    cout<<endl;
     cout<<"constant: "<<constant<<endl;
     loop.clear();
   //ta cout<<constant;

   }
   /**
     (3x)
     **/
   else if(first_bracket<constant_part&&count_bracket!=2)
   {
      // cout<<"(5*x^5)"<<endl;

      function_for(first_bracket+1,second_bracket);

      for(auto i:loop)
       {
           constant+=given_expression[i];
       }
        cout<<"constant: "<<constant<<endl;
         loop.clear();
   }

    else
    {
        /**(5/3)*(x^10)
        tan(x)sec(x)

        **/
        if(count_bracket==2&&is_trigonmetry==false)
        {

        for(int i=1;i<j-1;i++)
        {
            constant+=given_expression[i];

             size_of_constant++;
        }
        //constant_list.push_back(constant);
         constant_co=constant;
         //constant="";
         for(int i=first_bracket+1;i<second_bracket-1;i++)
         {
             coefficient=given_expression[i];
             size_of_coefficient++;
         }
       //  coefficient_list.push_back(constant);
        coefficient_co=coefficient;

        }
    }
   // cout<<"3rule"<<endl;

   // cout<<constant_co<<" "<<coefficient_co<<endl;
   //   cout<<constant_with_coefficient(constant_co,size_of_constant,coefficient_co,size_of_coefficient,need_to_divide);

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

         // cout<<numerator_one<<" "<<denominator_one<<endl;

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

       ///checking for x^n
       if(exist_power==true&&is_trigonmetry==false)
       {
          calculate_power_part(given_expression,constant,need_to_divide);
       }


       /**
           5*sin(4x)
           sec(x)tan(x)
           **/
       if(is_trigonmetry==true)
       {
           int position_coefficient=0;
           int first_bracket=0;
           string coefficient="";
           string constant="";
           bool exist_constant=false;
            int first_char=0;
           function_for(0,given_expression.size());
           for(auto i:loop)
           {
               if(given_expression[i]=='x')
               {
                  position_coefficient=i;
               }
               if(given_expression[i]=='(')
               {
                   first_bracket=i;
               }
           }
           ///sec(x)tan(x)
           loop.clear();
        cout<<"position of coefficient and first bracket: "<<position_coefficient<<" "<<first_bracket<<endl;

           if(position_coefficient>0)
           {
               for(int i=first_bracket+1;i<position_coefficient;i++)
               {
                   coefficient+=given_expression[i];
               }

           }

           if(count_bracket==2)
           {
               for(int i=0;i<first_bracket;i++)
               {
                  // cout<<given_expression[i]<<endl;
                   if(given_expression[i]=='*')
                   {
                       if(given_expression[i+1]>='a'&&given_expression[i+1]<='z')
                       {
                          first_char=i;
                          exist_constant=true;
                          //break;
                       }
                   }

                           if(exist_constant==false)
                           {
                            first_char=0;
                           // break;
                          }
                       }



                   for(int i=0;i<first_char;i++)
                   {
                       constant+=given_expression[i];
                   }


               cout<<"first char: "<<first_char<<endl;


           }


        if(first_char!=0) calculate_trigonmetry_part(given_expression,coefficient,constant);
        else
        {
            constant="1";
            calculate_trigonmetry_part(given_expression,coefficient,constant);
        }
       }

       cout<<"new"<<endl;

       if(two_power==2)
       {
           int below_part_start=0;
           int plus_pos=0;
           int minus_pos=0;
           bool is_plus=false;
           bool is_minus=false;
           bool is_a_before_x=false;
           bool is_x_before_a=false;

           int first_square=0;
           int pos_of_x=0,pos_of_x_1=0;


           loop.clear();
           vector<int>saving_square_pos;
           //function_for(0,given_expression.size());
           for(int i=0;i<given_expression.size();i++)
           {

               if(given_expression[i]=='-')
               {
                   is_minus=true;
                    cout<<"pagol minus ase"<<endl;
                   minus_pos=i;
               }
                if(given_expression[i]=='+')
               {
                   is_plus=true;
                  // cout<<"pagol plus ase"<<endl;
                   plus_pos=i;
               }
                if(given_expression[i]=='/')
               {
                   below_part_start=i;
               }

               if(given_expression[i]=='^')
               {
                   first_square=i;
                   saving_square_pos.push_back(i);
                  // break;
               }

               if(given_expression[i]=='x')
               {
                   pos_of_x=i;
                   pos_of_x_1=i-1;
               }
           }

           cout<<"first square: "<<first_square<<endl;
           cout<<"pos of x: "<< pos_of_x<<endl;

           string constant="";
           string coefficient="";
           int pos_of_constant=0;
           bool is_coefficient=false;
           cout<<"below part start: "<<below_part_start<<endl;
           cout<<"pos_plus: "<<plus_pos<<endl;
           cout<<"pos_minus: "<<minus_pos<<endl;
           loop.clear();
           it_can_be(is_plus==true||is_minus==true)
           {
               int index=0;
               if(is_plus==true)
               {
                   index=plus_pos;
               }
               else index=minus_pos;

               //function_for(index+2,pos_of_x_1);
               if(given_expression[pos_of_x_1]=='*'){
                    is_coefficient=true;
                   int i=pos_of_x_1-1;

                   while(given_expression[i]!='(')
                    {
                      coefficient+=given_expression[i];
                      i--;
                    }

               }
               coefficient=reverse_string(coefficient);

               cout<<"coefficient a_X: "<<coefficient<<endl;
           }
         //  cout<<"saving_square_pos[0]: "<<saving_square_pos[0]<<endl;


         if(plus_pos!=0||minus_pos!=0){
           if((pos_of_x>minus_pos)&&minus_pos!=0||(pos_of_x>plus_pos)&&plus_pos!=0)
           {
               for(int sign=below_part_start+3;sign<saving_square_pos[0];sign++)
             {
                   constant+=given_expression[sign];

             }
             pos_of_constant=below_part_start+2;

             cout<<"constant1: "<<constant<<endl;
           }
           else ///1/((2*x)^2-2^2)
           {
               for(int sign=minus_pos+1;sign<power_part;sign++)
             {

                   constant+=given_expression[sign];

             }
               pos_of_constant=minus_pos+1;

             cout<<"constant: "<<constant<<endl;
           }
         }

         calcute_formulas(given_expression,pos_of_constant,pos_of_x,is_plus, is_minus,constant,coefficient,is_coefficient);

       }

}





int main()
{
    string s;
    cin>>s;
    parse(s);

}

