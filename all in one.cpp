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

     //cout<<"simplified string is: "<<ans<<endl;
     return ans;

     ///jkhn minus lagbe tkhn minus kore dis....


}

string constant_with_coefficient(string constant_list,int size_constant_list,string coefficient_list,int size_coefficient_list,bool need_to_divide)
{


   // cout<<size_constant_list<<endl;
    int constant=0,coefficient=0;

        constant+=convert_string_to_int(constant_list);
       // constant*=10;

  //  cout<<constant<<endl;


    coefficient+=convert_string_to_int(coefficient_list);
       //coefficient*=10;

   // cout<<coefficient<<endl;
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

   cout<<power<<endl;
   cout<<"here"<<endl;
   if(power==""){
        numerator_two_int=2;
    if(constant!="1") cout<<"("<< numerator_constant_int/(denominator_constant_int*numerator_two_int)<<")";
     else cout<<"(1/"<<numerator_two_int<<")";
       cout<<main_function<<power1<<numerator_two_int<<endl;
   }
   else{
   if(denominator_two_int*denominator_constant_int!=1)
   {
       cout<<"("<<numerator_two_int/numerator_constant_int<<"/"<<denominator_two_int/denominator_constant_int<<")*";

       cout<<main_function<<power1<<"("<<numerator_two_int<<"/"<<denominator_two_int<<")"<<endl;
   }
   else
   {
       cout<<"("<<numerator_two_int/numerator_constant_int<<")";

       cout<<main_function<<power1<<numerator_two_int<<endl;
   }
   }
}

double sin_function(double bound) {
    return sin(bound);
}

double cos_function(double bound) {
    return cos(bound);
}

double sec_function(double bound) {
    return 1/cos(bound);
}

double cosec_function(double bound) {
    return 1/sin(bound);
}

double tan_function(double bound) {
    return tan(bound);
}

double cot_function(double bound) {
    return 1/tan(bound);
}

double e_function(double bound) {
    return exp(bound);
}

typedef double (*TrigFunction)(double);

map<string, TrigFunction> function_map = {
    {"sin", sin_function},
    {"cos", cos_function},
    {"sec", sec_function},
    {"cosec", cosec_function},
    {"tan", tan_function},
    {"cot", cot_function},
    {"e", e_function}
};

double work_for_trigonmetry(string input, double bound) {
    vector<char> check_function;
    int can_function = 0;
    int pos_function = 0;

    //cout << input << endl;
    bool a_power = false;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            if (input[i] != 'x') {
                check_function.push_back(input[i]);
            }
            pos_function = i;

            if (input[i] != 'x' && input[i + 1] == '^') {
                if (input[i + 2] == '2') {
                    a_power = true;
                }
            }
        }
    }

    string function_is = "";
   /* for (auto i : check_function) {
        cout << i << " ";
    }
    cout << endl;*/
    for (int i = 0; i < check_function.size(); i++) {
        function_is += check_function[i];
    }

   // cout<<"func is: "<<function_is<<endl;
    if (function_map.count(function_is)) {
        TrigFunction func = function_map[function_is];
        return func(bound);
    } else if (a_power) {
        if (function_is == "sec") {
            return sec_function(bound);
        } else if (function_is == "cosec") {
            return cosec_function(bound);
        }
    }
    return 0.0;
}


void calculate_power_part(string s,string constant,bool can_divide)
{
    int power_part=0;
    int power=0,bracket=0;
    //bool can_divide=false;
    set<char>for_power_one;
    string power_one="";
    for(int i=0;i<s.size();i++)
    {
        for_power_one.insert(s[i]);
        if(s[i]=='x'&&s[i+1]=='^')
        {
           power_part=i+1;
           power++;
        }

        if(s[i]=='/')
        {
            can_divide=true;
        }
        if(s[i]==')')
        {
            bracket=i;
            break;
        }
    }

    if(for_power_one.find('^')==for_power_one.end())
    {
      power_one="";
    }
    if(power==1)
    {
      for(int i=power_part+1;i<bracket;i++)
      {
         // while(i!=bracket){
          power_one=power_one+s[i];
         // }

      }
    }

    ///modify this-->5/5

    cout<<"power: "<<power_one<<" constant: "<<constant<<endl;
   // power_one++;
   if(can_divide==false&&power_one!="")power_and_constant(power_one+"/1",constant+"/1");
    else if(power>0&&power_one!="") power_and_constant(power_one+"/1",constant);
    else if(power_one=="")
    {
       // cout<<"power """<<endl;
        power_and_constant("",constant);
    }

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

    // cout<<"constant: "<<constant<<" coefficient: "<<coefficient<<endl;
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
/*
void calculate_trigonmetry_part(string input, string coefficient, string constant)
{
    vector<char> check_function;
    int can_function = 0;
    int pos_function = 0;

   // cout << input << endl;
    bool a_power = false;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] >= 'a' && input[i] <= 'z')
        {
            check_function.push_back(input[i]);
            pos_function = i;

            if (input[i] != 'x' && input[i + 1] == '^' && input[i + 2] == '2')
            {
                a_power = true;
            }
        }
    }

    string function_is = "";
   /* for (auto i : check_function)
    {
        cout << i << " ";
    }
    cout << endl;*/
   /* for (int i = 0; i < check_function.size(); i++)
    {
        function_is += check_function[i];
    }

    function_is = (check_function.size() != 1) ?
        ((function_is == "tansec" || function_is == "sectan") ? "tanxsecx" :
        ((function_is == "coseccot" || function_is == "cotcosec") ? "cotxcosecx" :
        ((a_power == true) ? ((function_is == "sec") ? "sec^2x" : "cosec^2x") : (function_is + 'x')))) :
        "x";
    cout << function_is << endl;

    string change_function = "";
    change_function += (function_is == "sinx") * "cos";
    change_function += (function_is == "cosx") * "(-1)*sin";
    change_function += (function_is == "secx") * "tan";
    change_function += (function_is == "cosecx") * "cot";
    change_function += (function_is == "cotxcosecx") * "(-1)*cosec";
    change_function += (function_is == "tanxsecx") * "sec";
    change_function += (function_is == "e") * "e";
    change_function += (function_is == "sec^2x") * "tan";
    change_function += (function_is == "cosec^2x") * "(-1)*cot";
    cout << "change function: " << change_function << endl;

    trigonmetry_with_coefficient(input, change_function, coefficient, constant);
}


*/
void calculate_trigonmetry_part(string input,string coefficient,string constant,int upper,int lower)
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

    cout<<"change function:\ "<<change_function<<endl;

    ///within limit
    ///-------------------------------------------------------------------------
    double upper_num=0.0000000,lower_num=0.000000000;
           cout<<"trigon"<<endl;
            double modified_upper=(upper*180)/3.1416;
            double modified_lower=(lower*180)/3.1416;
            upper_num=work_for_trigonmetry(change_function,modified_upper);
           lower_num=work_for_trigonmetry(change_function,modified_lower);
           cout<<"upper and lower num: "<<upper_num<<" "<<lower_num<<endl;
    ///-------------------------------------------------------------------------

    trigonmetry_with_coefficient(input,change_function,coefficient,constant);
}

double work_for_type_two(string input,int bound,string a_by_b)
{
   string str1="-",str2="x^2";
      int pos1=input.find(str1);
      int pos2=input.find(str2);
      double div1=0.0000,div2=0.0000;
      double a_plus_x=0.00000,a_minus_x1=0.00000,a_minus_x2=0.00000;
      double ans=0.000000;


        ///substring found
        double modified_a_by_b=stoi(a_by_b);
        cout<<"modified a_by_b: "<<modified_a_by_b<<endl;
        a_plus_x=modified_a_by_b+bound;
        a_minus_x1=bound-modified_a_by_b;
        a_minus_x2=modified_a_by_b-bound;

        div1=a_plus_x/a_minus_x2;
        div2=a_minus_x1/a_plus_x;

        if(pos1<pos2)
        {
            ans=log(div1);
        }
        else ans=log(div2);

    cout<<"ans is: "<<ans<<endl;
    return ans;
}

void  formula_with_constant(string main_string,string change_function,string constant,int can_minus,int can_plus,string coefficient,bool is_coefficient,int upper,int lower)
{
    int int_constant=convert_string_to_int(constant);
    int_constant=2*int_constant;
    string string_constant=convert_int_to_string(int_constant);
    string constant_is,plus1="+",minus1="-";
    string main_function="x";
    string a_by_b="",b_by_a="";

    it_can_be(is_coefficient==true)
    {
        int int_coefficient=convert_string_to_int(coefficient);
        cout<<"before main coefficient: "<<int_coefficient<<" "<<int_constant<<endl;
        a_by_b=simplification_numerator_denominator(constant,coefficient);
        b_by_a=simplification_numerator_denominator(coefficient,constant);
        int_coefficient=int_coefficient*int_constant;
        cout<<"after: "<<int_coefficient<<endl;
        string string_coefficient=convert_int_to_string(int_coefficient);

        constant_is=simplification_numerator_denominator("1",string_coefficient);
    }
    it_can_be(is_coefficient==false)
    {
        constant_is=simplification_numerator_denominator("1",string_constant);
         a_by_b=simplification_numerator_denominator(constant,"1");
         b_by_a=simplification_numerator_denominator("1",constant);
    }

    cout<<"constant is: "<<constant_is<<endl;
   cout<<"a_by_b: "<<a_by_b<<endl;
    double upper_num=work_for_type_two(change_function,upper,a_by_b);
    double lower_num=work_for_type_two(change_function,lower,a_by_b);
    cout<<"upper and lower num: "<<upper_num<<" "<<lower_num<<endl;
    if(can_plus>0)
    {
       cout<<"("<<constant_is<<")"<<change_function<<"(("<<b_by_a<<")*"<<main_function<<")"<<endl;
    }
    else if(can_minus>0){
            cout<<"("<<constant_is<<")"<<change_function<<"(("<<a_by_b+plus1<<main_function<<")/("<<a_by_b+minus1+main_function<<")"<<endl;
    }
    else
    {
         cout<<"("<<constant_is<<")"<<change_function<<"(("<<main_function<<minus1<<a_by_b<<")/("<<a_by_b+plus1+main_function<<")"<<endl;
    }
}


/// calcute_formulas(given_expression,pos_of_constant,pos_of_x,is_plus, is_minus,constant,coefficient,is_coefficient);

void calcute_formulas(string formula,int pos_constant,int pos_of_x,bool is_plus,bool is_minus,string constant,string coefficient,bool is_coefficient,int upper,int lower)
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
          can_minus=0;
        }
    }

    cout<<"calculate formula-change function: "<<change_function<<endl;


    ///string main_string,string change_function,string constant,int can_minus,int can_plus
    ///formula_with_constant(string main_string,string change_function,string constant,int can_minus,int can_plus)
    formula_with_constant(formula,change_function,constant,can_minus,can_plus,coefficient,is_coefficient,upper,lower);
}

int count_multi=0,count_power=0,count_divide=0,x=0;
bool trigonmetry=false,power=false,divide=false;
int terms_checking(const string& given_expression, int i=0) {


    if (i < given_expression.size()) {
        switch(given_expression[i])
    {
        case '*':
           count_multi++;
            break;
        case '^':
            count_power++;
            power=true;
            ///a^2+x^2 yes or not
            break;
        case '/':
            divide=true;
            count_divide++;
            break;
        case 'x':
            x++;
            break;
        default:
            if(given_expression[i]>='a'&&given_expression[i]<='z')
            {
                if(given_expression[i]!='x')
                {
                    trigonmetry=true;
                }
            }
            break;
    }
}

        terms_checking(given_expression, i+1);

}

only_variable(string str)
{
    string str1;
    str1=str1+str;
    str1+="x";

    cout<<str1<<endl;
}
parse(string given_expression,int upper,int lower)
{


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

    string add_terms="";
    vector<string>terms_string;

    if(count_term==1)
    {
        terms_string.push_back(given_expression);
    }

    else if(count_term>1){
     for(int i=0;i<terms_pos[0];i++)
     {
         add_terms+=given_expression[i];
     }
     //cout<<term1<<endl;
     terms_string.push_back(add_terms);

     for(int i=0;i<count_term-1;i++)
     {
        cout<<terms_pos[i]<<endl;
     }
    count_term--;

    int pos_checker=0;


    add_terms="";
    cout<<"now term is: "<<count_term<<endl;

      while(count_term>1){
        for(int i=terms_pos[pos_checker]+1;i<terms_pos[pos_checker+1];i++)
        {
           add_terms+=given_expression[i];

           cout<<add_terms<<endl;
        }
         pos_checker++;

         cout<<add_terms<<" "<<pos_checker<<endl;
        terms_string.push_back(add_terms);
        count_term--;
        add_terms="";
    }


    add_terms="";
    int last_pos=terms_pos.size()-1;
    for(int i=terms_pos[last_pos]+1;i<check-1;i++)
    {
        add_terms+=given_expression[i];
    }
    terms_string.push_back(add_terms);

    cout<<"terms_string.size()"<<terms_string.size()<<endl;
     for(int i=0;i<terms_string.size();i++)
    {
        cout<<"before string is: "<<terms_string[i]<<endl;
    }
    cout<<endl;
    }
    for(int i=0;i<terms_string.size();i++)
    {
        cout<<"string is: "<<terms_string[i]<<endl;

        string given_expression="";
        given_expression=terms_string[i];

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
    string numerator,denominator,main_term="x";
    vector<int>secondBrackets,firstBrackets;
    vector<int> pos_of_x;
  //  bool exist_power=false;
   int pos=0;

   x=0;
    loop.clear();
    function_for(0,given_expression.size());


    for(auto i:loop)
    {
      //  cout<<i<<" ";

        if(given_expression[i]=='*')
        {
            count_multi++;
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
            firstBrackets.push_back(first_bracket);
          //  break;
        }
        if(given_expression[i]==')')
        {
            second_bracket=i;
            secondBrackets.push_back(second_bracket);
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
            x++;
            pos_of_x.push_back(i);
            only_x=true;
        }




    }


        int system=0;
        string digits,digits_main="";
        string str=given_expression;
        copy_if(str.begin(), str.end(),back_inserter(digits), [](char c){
        return isdigit(static_cast<unsigned char>(c));
        });

       cout << "Digits in the string: " << digits << endl;

    for(int i=0;i<given_expression.size();i++)
    {
        int digits_size=given_expression.size()-2;


       if(given_expression[i]=='('||given_expression[i]==')')
       {
           digits_main+="";
       }
       else
       {
           digits_main+=given_expression[i];
       }

    }
    if(digits_main==digits)
    {
       system=4;
    }
    ///24/4/2023-->work on every terms count

    cout<<"x: "<<x<<endl;
    if(two_power==2)
    {
        system=3;
    }
    else if(x==1&&is_trigonmetry==false)
    {
        system=1;
    }
    else if(is_trigonmetry==true)
    {
        system=2;
    }



     cout<<"system: "<<system<<endl;

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

         // cout<<"constant part: "<<constant_part<<endl;

   ///for every constant
   ///----------------------------


    if(exist_constant==true)
    {
         size_t pos = given_expression.find('^');
       // cout << "The first position of '^' is: " << pos <<endl;
        loop.clear();
        function_for(1,pos);
        for(auto i:loop)
        {
            constant+=given_expression[i];
        }

    }
    else if(exist_constant==false)
    {
        constant="1";
    }

   // cout<<endl;

    // loop.clear();
   // cout<<"constant: "<<constant<<endl;



   int openBracketPlace=0,closeBracketPlace=0;
   for(int i=0;i<=firstBrackets.size();i++)
   {
       if(i==1) openBracketPlace=firstBrackets[i];
   }
    for(int i=0;i<=secondBrackets.size();i++)
   {
       if(i==0) closeBracketPlace=secondBrackets[i];
   }
   //cout<<"openBracketPlace and close: "<<openBracketPlace<<" "<<closeBracketPlace<<endl;
   /**
     (3x)
     **/
   //else if(first_bracket<constant_part&&count_bracket!=2)
    if(need_to_divide==true)
   {
     //((3/2)*x^2)--> check the firstBracket=2
      for(int i=openBracketPlace+1;i<closeBracketPlace;i++);
       {
          constant+=given_expression[i];
       }



    // cout<<"constant: "<<constant<<endl;
   }



     ///power
     power="";
     if(exist_power==true&&count_power==1)
     {
         for(int i=power_part+1;i<second_bracket;i++)
         {
             power=power+given_expression[i];
         }
     }
   cout<<"power: "<<power<<endl;


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


       if(system==4)
       {
           only_variable(digits);
       }
       if(system==1)
       {

      constant="";


    if(exist_constant==true)
    {

         size_t pos = given_expression.find('*');
        cout << "The first position of '*' is: " << pos <<endl;
        loop.clear();
        function_for(1,pos);
        for(auto i:loop)
        {
            constant+=given_expression[i];
        }

    }
    else if(exist_constant==false)
    {
        constant="1";
    }

   // cout<<endl;

    // loop.clear();
    cout<<"constant: "<<constant<<endl;
         // deal_with_only_x(power,main_term,constant);
          calculate_power_part(given_expression,constant,need_to_divide);

       }
       /**
           (5*sin(4x))
     ---------------------
           sec(x)tan(x)
           **/
       if(system==2)
       {
        //(1/(a2+x2)) dx = (1/a) tan-1(x/a)

        cout<<"system 2"<<endl;
           int position_coefficient=0;
           int first_bracket=0;
           string coefficient="";
           string constant="";
           bool exist_constant=false;
            int first_char=0;
           function_for(0,given_expression.size());
           vector<int>waiting_x;
           for(auto i:loop)
           {
               if(given_expression[i]=='x')
               {
                  position_coefficient=i;
                  waiting_x.push_back(position_coefficient);
               }
               if(given_expression[i]=='(')
               {
                   first_bracket=i;
               }
           }
           ///sec(4*x)tan(4*x)
           loop.clear();
      cout<<"position of coefficient and first bracket: "<<position_coefficient<<" "<<first_bracket<<endl;

        int main_str_size=0;
        if(waiting_x.size()==2){
         int main_str_size=0;
         for(int i=0;i<waiting_x.size()/2;i++){

               int k=waiting_x[i]-2;
               while(given_expression[k]!='(')
               {
                    coefficient+=given_expression[k];
                    k--;
               }
               i++;

        }
        }
        else
        {
            //(x)+(35*sin(4*x))

            for(int i=0;i<waiting_x.size();i++){

               int k=waiting_x[i]-2;
               //cout<<"k: "<<endl;
               while(given_expression[k]!='(')
               {
                    coefficient+=given_expression[k];
                    // cout<<"check coefficient"<< coefficient<<endl;
                    k--;
               }
               i++;
        }
        }
    cout<<"co-efficient: "<< coefficient<<endl;

    /**  for(int i=plus-3;;i--)
         {
             while(given_expression[i]!='(')
             {
                 constant+=given_expression[i];
             }
         }
         cout<<"new constant: "<<constant<<endl;**/

           if(x==2)
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
                          break;
                       }
                   }

                           if(exist_constant==false)
                           {
                            first_char=0;
                           // break;
                           }
                }



                   for(int i=1;i<first_char;i++)
                   {
                       constant+=given_expression[i];
                   }


               //cout<<"first char: "<<first_char<<endl;


           }

           cout<<"constant: "<<constant<<endl;

        if(first_char!=0) calculate_trigonmetry_part(given_expression,coefficient,constant,upper,lower);
        else
        {
            constant="1";
            calculate_trigonmetry_part(given_expression,coefficient,constant,upper,lower);
        }
       }

 //      cout<<"new"<<endl;

       if(system==3)
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

              if(coefficient!="") cout<<"coefficient a_X: "<<coefficient<<endl;
              else cout<<"coefficient a_X: "<<1<<endl;
           }
         //  cout<<"saving_square_pos[0]: "<<saving_square_pos[0]<<endl;


         if(plus_pos!=0||minus_pos!=0){
           if((pos_of_x>minus_pos)&&minus_pos!=0||(pos_of_x>plus_pos)&&plus_pos!=0)
           {
               for(int sign=below_part_start+2;sign<saving_square_pos[0];sign++)
             for(int sign=saving_square_pos[0]-1;;sign--)
             {
                 if(given_expression[sign]=='(') break;
               constant+=given_expression[sign];


             }
             pos_of_constant=below_part_start+2;
             constant=reverse_string(constant);

             cout<<"constant1: "<<constant<<endl;
           }
           else ///1/((2*x^2)-2^2)
           {
               for(int sign=minus_pos+1;sign<power_part;sign++)
             {

                   constant+=given_expression[sign];

             }
               pos_of_constant=minus_pos+1;

             cout<<"constant: "<<constant<<endl;
           }
         }

         calcute_formulas(given_expression,pos_of_constant,pos_of_x,is_plus, is_minus,constant,coefficient,is_coefficient,upper,lower);

       }
    }
}






int main()
{
    string s;
    cin>>s;

    int upper,lower;
    printf("input upper and lower limit: ");
    cin>>upper>>lower;
     parse(s,upper,lower);
}


