#include<bits/stdc++.h>
using namespace std;

vector<int>loop;
string saved_answers="";
vector<string>all_answers;
double limit_answers_double=1.00000;
vector<double>all_answers_limit,within_limit;

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

double string_to_double(const string& s) {
    size_t delimiterPos = s.find('/');

    if (delimiterPos != string::npos) {
        string numeratorStr = s.substr(0, delimiterPos);
        string denominatorStr = s.substr(delimiterPos + 1);

        double numerator, denominator;
        istringstream(numeratorStr) >> numerator;
        istringstream(denominatorStr) >> denominator;

        if (denominator != 0.0) {
            return numerator / denominator;
        }
    }


    return 0.0;
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
    coefficient_list.clear();
    constant_list.clear();
    return result_main;
}



void power_and_constant(string power,string constant,int upper,int lower)
{
    cout<<"power is: "<<power<<endl;

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
      if(power=="") numerator_two_int++;
      else{
        numerator_two_int=convert_string_to_int(power)+1;
      }
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
   //cout<<"i:"<<store1<<endl;

       if(constant_check.find('/')!= constant_check.end())
       {
            for(int i=0;i<store1;i++)
       {
         numerator_constant+=constant[i];
       }
    //  cout<<numerator_constant<<endl;
      numerator_constant_int=convert_string_to_int(numerator_constant);

      for(int i=store1+1;i<constant.size();i++)
      {
          denominator_constant+=constant[i];
      }
      //cout<<"deno: "<<denominator_constant<<endl;
      denominator_constant_int=stoi(denominator_constant);
      //out<<"int: "<<denominator_constant_int<<endl;
       }
   else
   {
       numerator_constant_int=convert_string_to_int(constant);
       denominator_constant_int=1;
   }


//   cout<<numerator_two_int<<" "<<denominator_two_int<<endl;
  // cout<<numerator_constant_int<<" "<<denominator_constant_int<<endl;

  // cout<<power<<endl;
   //cout<<"here"<<endl;
   if(power=="")
    {
        numerator_two_int=2;
    if(constant!="1")
    {
        cout<<"("<< simplification_numerator_denominator(convert_int_to_string(numerator_constant_int),convert_int_to_string(denominator_constant_int*numerator_two_int))<<")";
        saved_answers="("+simplification_numerator_denominator(convert_int_to_string(numerator_constant_int),convert_int_to_string(denominator_constant_int*numerator_two_int))+")";

         limit_answers_double=(double)(numerator_constant_int/(denominator_constant_int*numerator_two_int));
         limit_answers_double*=(upper-lower);
    }
    else
    {
        //cout<<"remain"<<endl;
        cout<<"(1/"<<numerator_two_int<<")*x^";
        cout<<numerator_two_int<<endl;
        saved_answers= "(1/"+convert_int_to_string(numerator_two_int)+")*x^"+convert_int_to_string(numerator_two_int);
        ///remain
         limit_answers_double=0.5*(square(upper)-square(lower));
    }
   }
   else
   {
   if(denominator_two_int*denominator_constant_int!=1)
   {
       //cout<<"remain"<<endl;
       int new1=numerator_two_int*denominator_constant_int;
       cout<<"("<<simplification_numerator_denominator(convert_int_to_string(numerator_constant_int),convert_int_to_string(new1))<<")*x^";
       cout<<numerator_two_int<<endl;

       saved_answers="("+simplification_numerator_denominator(convert_int_to_string(numerator_constant_int),convert_int_to_string(new1))+")*x^"+convert_int_to_string(numerator_two_int);


       limit_answers_double=pow(upper,convert_string_to_int(power))-pow(lower,convert_string_to_int(power));
        limit_answers_double*=(double)((numerator_two_int*denominator_constant_int)/(numerator_constant_int*denominator_two_int));

   }
   else
   {
      // cout<<"remain2"<<endl;
       cout<<"("<<simplification_numerator_denominator(convert_int_to_string(numerator_constant_int),convert_int_to_string(numerator_two_int))<<")*";

      // cout<<main_function<<power1<<numerator_two_int<<endl;
       saved_answers+="("+simplification_numerator_denominator(convert_int_to_string(numerator_constant_int),convert_int_to_string(numerator_two_int))+")*x^"+convert_int_to_string(numerator_two_int);
       limit_answers_double=pow(upper,numerator_two_int)-pow(lower,numerator_two_int);
      limit_answers_double=(double)((limit_answers_double*numerator_constant_int)/numerator_two_int);
      //cout<<"limit2: "<<limit_answers_double<<endl;
   }
   }


   all_answers.push_back(saved_answers);
  //  cout<<"saved_answers: "<<saved_answers<<endl;
    all_answers_limit.push_back(limit_answers_double);
   saved_answers="";
   limit_answers_double=1.0000;

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


void calculate_power_part(string& s,string constant,bool can_divide,int upper,int lower)
{
    //cout<<"s"<<s<<endl;
    string s1=s;
    int power_part=0,cnt_divide=0;
    int power=0;
    //bool can_divide=false;
    set<char>for_power_one;
    string power_one="";
    //cout<<s1.size()<<endl;
    int bracket[100];
    int j=0;
    for(int i=0;i<s1.size();i++)
    {
       //cout<<i<<" "<<s1[i]<<" "<<endl;
        for_power_one.insert(s[i]);
        if(s1[i]=='x'&&s1[i+1]=='^')
        {
           power_part=i+1;
           power++;
        }

        if(s1[i]=='/')
        {
            can_divide=true;
            cnt_divide++;
        }
        if(s1[i]==')')
        {
            bracket[j]=i;
            j++;
            //break;
        }
    }

    //cout<<"f power1"<<" "<<power<<endl;
    if(for_power_one.find('^')==for_power_one.end())
    {
      power_one="";
    }
    if(power==1)
    {
      for(int i=power_part+1;;i++)
      {
          if(s1[i]==')') break;
         // while(i!=bracket){
          power_one=power_one+s[i];
         // }

      }
    }

    ///modify this-->5/5

    if(power_one!="")
    {
         power_and_constant(power_one+"/1",constant+"/1",upper,lower);
    }
    else if(power>0&&power_one!="")
    {
        power_and_constant(power_one+"/1",constant,upper,lower);
    }
    else if(power_one=="")
    {
        power_and_constant("",constant,upper,lower);
    }

}
string extractExpression(const string& input) {
    string expression;

    size_t startPos = input.find("(");

    if (startPos != string::npos) {
        size_t endPos = input.find(")", startPos);

        if (endPos != string::npos && endPos > startPos) {
            expression = input.substr(startPos + 1, endPos - startPos - 1);
        }
    }

    return expression;
}
string removeSubstring(const string& str, const string& substr) {
    string result = str;

    size_t pos = result.find(substr);

    if (pos != string::npos) {
        result.erase(pos, substr.length());
    }

    return result;
}


void extra(string given_expression)
 {
    bool can_divide = true;
    int  x=2,i = 0, bracket2 = 0, bracket1 = 0;
    set<char> signs;
    vector<int> signs_pos;
    vector<int> multi_pos;

    if (x == 2 && can_divide == true)
        {
        while (i < given_expression.size())
         {
            if (given_expression[i] == ')' && given_expression[i + 1] == '/' && given_expression[i + 2] == '(')
            {
                bracket2 = i + 2;
                bracket1 = i;
            }
            if (given_expression[i] == '+')
            {
                signs.insert('+');
                signs_pos.push_back(i);
            }
            if (given_expression[i] == '-')
            {
                signs.insert('-');
                signs_pos.push_back(i);
            }
            if (given_expression[i] == '*')
            {
                multi_pos.push_back(i);
            }
            i++;
        }
    }

    string nicher_constant = "", reverse_upor_constant = "", upor_constant = "";
    string reverse_upor_extra_constant = "", upor_extra_constant = "";

    for (int i = bracket2 + 1; given_expression[i] != '*'; i++)
    {
        nicher_constant += given_expression[i];
    }

    string upor_extra_constant_sign="";
    for (int i = bracket1 - 1; i >= 0; i--)
    {
        if (given_expression[i] == '+' )
            {
                upor_extra_constant_sign="+";
                break;
            }
        else if(given_expression[i] == '-')
        {
             upor_extra_constant_sign="-";
                break;
        }
        reverse_upor_extra_constant += given_expression[i];
    }

    upor_extra_constant = reverse_string(reverse_upor_extra_constant);
    //cout << "nicher_constant: " << nicher_constant << endl;

    for (int i = multi_pos[0] - 1; given_expression[i] != '('; i--)
    {
        reverse_upor_constant += given_expression[i];
    }

    upor_constant = reverse_string(reverse_upor_constant);
   // cout << "upor_constant: " << upor_constant << endl;
   // cout << "upor_extra_constant: " << upor_extra_constant << endl;

    string nicher_extra_constant = "",nicher_extra_constant_sign="";
    auto it = signs.begin();

    if (signs.size() == 1)
    {
     //   cout << "*it and sign_pos: " << *it << " " << signs_pos[1] << endl;
        if (*it == '+')
        {
            nicher_extra_constant_sign += "-";
            for (int pos = signs_pos[1] + 1; given_expression[pos] != ')'; pos++)
            {
                nicher_extra_constant += given_expression[pos];
            }
        }
    }
    else
    {
        nicher_extra_constant_sign += "+";
        for (int pos = signs_pos[1] + 1; given_expression[pos] != ')'; pos++)
        {
            nicher_extra_constant += given_expression[pos];
        }
    }

   // cout << "nicher_extra_constant: " << nicher_extra_constant << endl;

    int nicher_constant_int=0,upor_extra_constant_int=0,nicher_extra_constant_int,square_nicher_constant=0,new_extra_constant=0,upor_constant_int;
    int extra_constant_int=0,new_extra_constant1,new_extra_constant2;
    string extra_constant;

     nicher_constant_int=convert_string_to_int(nicher_constant);
    // cout<<"nicher_constant_int: "<<nicher_constant_int<<endl;
     upor_extra_constant_int=convert_string_to_int(upor_extra_constant);
     upor_constant_int=convert_string_to_int(upor_constant);
     nicher_extra_constant_int=convert_string_to_int(nicher_extra_constant);
     square_nicher_constant=nicher_constant_int*nicher_constant_int;
     new_extra_constant1=nicher_constant_int*upor_extra_constant_int;
     new_extra_constant2=nicher_extra_constant_int*upor_constant_int;

   //  cout<<"new_extra_constant1 &constant2: "<<new_extra_constant1<<" "<<new_extra_constant2<<endl;
     if(signs.size()==1)
     {
         extra_constant_int=abs(new_extra_constant1-new_extra_constant2);
         cout<<"extra_constant_int: "<<extra_constant_int<<endl;
         extra_constant=convert_int_to_string(extra_constant_int);
         cout<<"extra_constant: "<<extra_constant<<endl;
         if(new_extra_constant1>new_extra_constant2)
         {
             cout<<"extra_constant: "<<upor_extra_constant_sign<<extra_constant<<endl;
         }
         else
         {
              cout<<"extra_constant: "<<nicher_extra_constant_sign<<extra_constant<<endl;
         }
     }
     else
     {
        extra_constant=abs(new_extra_constant1+new_extra_constant2);
     }
     cout<<"extra_constant is: "<<extra_constant<<endl;
      string expression = extractExpression(given_expression);
    string expression1=removeSubstring(given_expression,expression);

  //  cout<<expression1<<endl;
   expression1=removeSubstring(expression1,"()/");
    cout<<"("<<upor_constant+"/"+convert_int_to_string(square_nicher_constant)+")+("+extra_constant+"/"+convert_int_to_string(square_nicher_constant)+")ln"+expression1<<endl;

    saved_answers+="("+upor_constant+"/"+convert_int_to_string(square_nicher_constant)+")+("+extra_constant+"/"+convert_int_to_string(square_nicher_constant)+")ln"+expression1;
    //limit_answers_double=
    ///remain

    all_answers.push_back(saved_answers);
    saved_answers="";
    signs_pos.clear();
    multi_pos.clear();
}



void trigonmetry_with_coefficient(string input,string change_function,string coefficient,string constant,int upper,int lower)
{

    double upper_num=0.0000000,lower_num=0.000000000;

     string main_function="x";

    if(constant!="1")
    {
        if(coefficient!="")
        {
          //cout<<"1st"<<endl;
          simplification_numerator_denominator(constant,coefficient);
          cout<<"("<<constant<<"/"<<coefficient<<")*"<<change_function+"("+coefficient+"*"+main_function+")"<<endl;
          saved_answers+="("+constant+"/"+coefficient+")*"+change_function+"("+coefficient+"*"+main_function+")";

           upper_num=work_for_trigonmetry(change_function,upper*convert_string_to_int(coefficient));
           lower_num=work_for_trigonmetry(change_function,lower*convert_string_to_int(coefficient));
           cout<<"upper and lower num: "<<upper_num<<" "<<lower_num<<endl;
           limit_answers_double*=(double)(convert_string_to_int(constant)/convert_string_to_int(coefficient));
           limit_answers_double*=(upper_num-lower_num);

        }
        else
        {
           cout<<constant<<change_function+"("+coefficient+"*"+main_function+")"<<endl;
            saved_answers+=constant+change_function+"("+coefficient+"*"+main_function+")";
             upper_num=work_for_trigonmetry(change_function,upper);
           lower_num=work_for_trigonmetry(change_function,lower);
           cout<<"upper and lower num: "<<upper_num<<" "<<lower_num<<endl;
           limit_answers_double*=convert_string_to_int(constant);
           limit_answers_double*=(upper_num-lower_num);
        }
    }
    else
    {
        if(coefficient=="")
        {
            //cout<<"2nd 1"<<endl;
            cout<<change_function+main_function<<endl;
             upper_num=work_for_trigonmetry(change_function,upper);
           lower_num=work_for_trigonmetry(change_function,lower);
           cout<<"upper and lower num: "<<upper_num<<" "<<lower_num<<endl;
           limit_answers_double*=(upper_num-lower_num);
        }
        else
        {
            simplification_numerator_denominator(constant,coefficient);
            cout<<"("<<constant<<"/"<<coefficient<<")*"<<change_function+"("+coefficient+"*"+main_function+")"<<endl;
            saved_answers+="("+constant+"/"+coefficient+")*"+change_function+"("+coefficient+"*"+main_function+")";
            upper_num=work_for_trigonmetry(change_function,upper*convert_string_to_int(coefficient));
           lower_num=work_for_trigonmetry(change_function,lower*convert_string_to_int(coefficient));
           cout<<"upper and lower num: "<<upper_num<<" "<<lower_num<<endl;
           limit_answers_double*=(double)(convert_string_to_int(constant)/convert_string_to_int(coefficient));
           limit_answers_double*=(upper_num-lower_num);

        }
    }
    all_answers.push_back(saved_answers);
    all_answers_limit.push_back(limit_answers_double);
    saved_answers="";
    limit_answers_double=1.0000000;
}


void calculate_trigonmetry_part(string input,string coefficient,string constant,int upper,int lower)
{
    vector<char>check_function;
    int can_function=0;
    int pos_function=0;

    //cout<<input<<endl;
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
    /*for(auto i:check_function)
    {
        cout<<i<<" ";
    }*/
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
   // cout<<function_is<<endl;
    string change_function="";


    if(function_is=="sinx")
    {
        change_function+="(-1)*cos";
    }
    else if(function_is=="cosx")
    {
        change_function+="sin";
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
    else if(function_is=="tanx")
    {
         change_function+="ln(sec";
    }

    cout<<function_is<<" changing the function: "<<change_function<<endl;


    check_function.clear();
    trigonmetry_with_coefficient(input,change_function,coefficient,constant,upper,lower);
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
int count_multi=0,count_power=0,count_divide=0,x=0;
bool trigonmetry=false,power=false,divide=false;
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
        //cout<<"before main coefficient: "<<int_coefficient<<" "<<int_constant<<endl;
        a_by_b=simplification_numerator_denominator(constant,coefficient);
        b_by_a=simplification_numerator_denominator(coefficient,constant);
        int_coefficient=int_coefficient*int_constant;
        //cout<<"after: "<<int_coefficient<<endl;
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
       saved_answers+="("+constant_is+")"+change_function+"(("+b_by_a+")*"+main_function+")";
    }
    else if(can_minus>0){
            cout<<"("<<constant_is<<")"<<change_function<<"(("<<a_by_b+plus1<<main_function<<")/("<<a_by_b+minus1+main_function<<")"<<endl;
            saved_answers+="("+constant_is+")"+change_function+"(("+a_by_b+plus1+main_function+")/("+a_by_b+minus1+main_function+")";
            double upper1=(string_to_double(a_by_b)+upper)/(string_to_double(a_by_b)-upper);
            double upper2=work_for_trigonmetry(change_function,upper1);
            double lower1=(string_to_double(a_by_b)+lower)/(string_to_double(a_by_b)-lower);
            double lower2=work_for_trigonmetry(change_function,lower1);
            limit_answers_double=upper2-lower2;
            limit_answers_double*=string_to_double(constant_is);
    }
    else
    {
         cout<<"("<<constant_is<<")"<<change_function<<"(("<<main_function<<minus1<<a_by_b<<")/("<<a_by_b+plus1+main_function<<")"<<endl;
          saved_answers+="("+constant_is+")"+change_function+"(("+main_function+minus1+a_by_b+")/("+a_by_b+plus1+main_function+")";
            double upper1=(upper-string_to_double(a_by_b))/(string_to_double(a_by_b)+upper);
            double upper2=work_for_trigonmetry(change_function,upper1);
            double lower1=(string_to_double(a_by_b)+lower)/(string_to_double(a_by_b)-lower);
            double lower2=work_for_trigonmetry(change_function,lower1);
            limit_answers_double=upper2-lower2;
            limit_answers_double*=string_to_double(constant_is);
    }
    all_answers.push_back(saved_answers);
    all_answers_limit.push_back(limit_answers_double);
    saved_answers="";
    limit_answers_double=1.0000;
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
    //pos_of_x.clear();
    formula_with_constant(formula,change_function,constant,can_minus,can_plus,coefficient,is_coefficient,upper,lower);
}



only_variable(string str,int upper,int lower)
{
    string str1;
    limit_answers_double=(upper-lower)*convert_string_to_int(str);
    str1=str1+str;
    str1+="*x";

   // cout<<str1<<" only variable "<<limit_answers_double<<endl;
    saved_answers+=str1;
    all_answers.push_back(saved_answers);
    all_answers_limit.push_back(limit_answers_double);
    saved_answers="";
    limit_answers_double=0.0000;
}


vector<int> computeLPS(const string& pattern)
{
    vector<int> lps(pattern.length(), 0);
    int len = 0;

    for (size_t i = 1; i < pattern.length(); )
    {
        if (pattern[i] == pattern[len])
        {
            lps[i++] = ++len;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i++] = 0;
            }
        }
    }

    return lps;
}


vector<int> KMPSearch(const string& text, const string& pattern)
{
    vector<int> positions;
    int n = text.length();
    int m = pattern.length();
    vector<int> lps = computeLPS(pattern);

    int i = 0;  // Index for text
    int j = 0;  // Index for pattern

    while (i < n)
     {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            // Match found at index (i - j)
            positions.push_back(i - j);
            j = lps[j - 1];
        }
         else if (i < n && text[i] != pattern[j])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    return positions;
}

vector<int>find_substring(string text,string pattern)
{
    vector<int> pos = KMPSearch(text, pattern);
    return pos;
}
vector<int> extractNumbers(const string& input) {
    vector<int> numbers;
    string numberString;

    for (char c : input)
     {
        if (c == '(')
        {
            numberString.clear();
        }
        else if (c == ')')
        {
            if (!numberString.empty())
            {
                int number = stoi(numberString);
                numbers.push_back(number);
                numberString.clear();
            }
        }
        else if (isdigit(c))
        {
            numberString += c;
        }
    }

    return numbers;
}
int extract_constant(const string& input) {
    int leadingNumber = 0;
    int sign = 1;
    bool foundDigit = false;

    for (char c : input)
    {
        if (c == '-')
        {
            sign = -1;
        }
       else if (isdigit(c))
        {
            leadingNumber = leadingNumber * 10 + (c - '0');
            foundDigit = true;
        }
       else if (foundDigit)
        {

            break;
        }
    }

    return leadingNumber * sign;
}


///uv
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
   string new_constant=convert_int_to_string(constant),new_i;
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


trigonmetry_diff_coefficient(string equation,int upper,int lower)
{
    ///sin(5*x)cos(4*x)

    vector<int>pos1=find_substring(equation,"sin");
    vector<int> pos2=find_substring(equation,"cos");
    int coefficient1=0,coefficient2=0,main_coefficient=0,plus_coefficient_int=0,minus_coefficient_int=0;
    vector<int>coefficients=extractNumbers(equation);
    string sign="/",output1="",output2="",main="x";

    coefficient1=coefficients[0];
    coefficient2=coefficients[1];
    plus_coefficient_int=coefficient1+coefficient2;
    minus_coefficient_int=abs(coefficient1-coefficient2);

    int constant_int=extract_constant(equation);
    string constant,plus_coefficient="",minus_coefficient="";
    constant=convert_int_to_string(constant_int);
     plus_coefficient=convert_int_to_string(plus_coefficient_int);
     minus_coefficient=convert_int_to_string(minus_coefficient_int);

    cout<<"plus_minus: "<<plus_coefficient<<" "<<minus_coefficient<<endl;
    if(!pos1.empty()||!pos2.empty())
    {
        if(pos1.size()==1&&pos2.size()==1)
        {
           output1+="("+constant;
           output1+=sign + "2)(((-1)*cos(";
           //output1+=plus_coefficient+output1+="*"+main+"+(sin(";
           //output1+=minus_coefficient+"*"+main+")";

          // cout<<output1<<endl;
           ///trigonmetry sin to cos kora lagbe.....

           output2+="("+output1+plus_coefficient+"*x)/"+plus_coefficient+")"+"-(cos("+minus_coefficient+"*x)/"+minus_coefficient+"))";
           //cout<<output2<<endl;
           saved_answers+=output2;
        }


    else if(pos1.size()==2&&pos2.empty())
        {
           ///trigonmetry sin to cos kora lagbe.....sin(Ax)sin(bx)

            output1+="("+constant;
             output1+=sign + "2)((sin(";
            output2+="("+output1+minus_coefficient+"*x)/"+minus_coefficient+")"+"-(sin("+plus_coefficient+"*x)/"+plus_coefficient+"))";

           saved_answers+=output2;
        }
    else if(pos2.size()==2&&pos1.empty())
        {
            ///trigonmetry sin to cos kora lagbe.....

             output1+="("+constant;
             output1+=sign + "2)((sin(";
            output2+="("+output1+minus_coefficient+"*x)/"+minus_coefficient+")"+"+(sin("+plus_coefficient+"*x)/"+plus_coefficient+"))";

           saved_answers+=output2;


           //cout<<output2<<endl;
        }
    }
    all_answers.push_back(saved_answers);
    string saved_answers="";

}

string parse(string& given_expression,int upper,int lower)
{

  given_expression=removeSubstring(given_expression,"+c");
  //cout<<"\n _expression<<endl;

///working for  terms--->>
///----------------------------
    int task=1;
    task++;
    int check = 0;
    int count_term=1;
    int count_sign=0;
    int arr_terms_pos[100];
    memset(arr_terms_pos,0,sizeof(arr_terms_pos));

    stack<char>signs_of_expression;
    string main_output="";
    vector<int>terms_pos;
    vector<char>signs_are;

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
                    signs_are.push_back('+');
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
                     signs_are.push_back('-');
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

    cout<<"Total terms in the given expression are: "<<count_term<<endl;
   // cout << "count_term: " << check << " " << count_term << endl;


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
    count_term--;

    int pos_checker=0;


    add_terms="";
  //  cout<<"now term is: "<<count_term<<endl;

      while(count_term>1){
        for(int i=terms_pos[pos_checker]+1;i<terms_pos[pos_checker+1];i++)
        {
           add_terms+=given_expression[i];
           //cout<<add_terms<<endl;
        }
         pos_checker++;

       //  cout<<add_terms<<" "<<pos_checker<<endl;
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

  //  cout<<"terms_string.size()"<<terms_string.size()<<endl;
     for(int i=0;i<terms_string.size();i++)
    {
        cout<<"-------------------------------------------------"<<endl;
        cout<<"Before modififying string is: "<<terms_string[i]<<endl;
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
    bool no_coefficient=false;
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
         if(given_expression[i]=='('&&given_expression[i+1]=='x')
        {
                   no_coefficient=true;
        }
    }

        int system=0;
        string digits,digits_main="";
        string str=given_expression;
        copy_if(str.begin(), str.end(),back_inserter(digits), [](char c){
        return isdigit(static_cast<unsigned char>(c));
        });

       //cout << "Digits in the string: " << digits << endl;

       pos_of_x.clear();

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

    int coefficient1=0,coefficient2=0,main_coefficient=0,plus_coefficient_int=0,minus_coefficient_int=0;
    string sign="/",output1="",output2="",main="x";

    if(is_trigonmetry==true&&can_divide==0){
    vector<int>pos1=find_substring(given_expression,"sin");
    vector<int>pos2=find_substring(given_expression,"cos");

    vector<int>coefficients=extractNumbers(given_expression);


    coefficient1=coefficients[0];
    coefficient2=coefficients[1];

   //cout<<"coefficient1 and 2: "<<coefficient1<<" "<<coefficient2<<endl;
    }
    if(coefficient1!=coefficient2)
    {
        system=6;
    }
    if(digits_main==digits)
    {
       system=4;
    }
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
        if(coefficient1==0||coefficient2==0) system=2;
        else if(coefficient1!=0&&coefficient2!=0)
        {
            if(coefficient1==coefficient2)
                system=2;
        }
    }
    else if(x==2&&can_divide==true&&is_trigonmetry==false)
    {
        system=5;
    }


     cout<<"The term's operating number: "<<system<<endl;

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
      /* if(exist_power==true&&is_trigonmetry==false)
       {
          calculate_power_part(given_expression,constant,need_to_divide);
       }*/


       if(system==4)
       {
           only_variable(digits,upper,lower);
       }
       if(system==5)
       {
           extra(given_expression);
       }

    if(system==1)
    {
    constant="";
    cout<<"given: "<<given_expression<<endl;
    if(exist_constant==true)
    {
        if(can_divide)
        {
        int pos = given_expression.find('*');
        //cout << "The first position of '*' is: " << pos <<endl;
        loop.clear();
        function_for(2,pos-1);
            for(auto i:loop)
        {
            constant+=given_expression[i];
        }
        }
        else{
        int pos = given_expression.find('*');
        //cout << "The first position of '*' is: " << pos <<endl;
        loop.clear();
        function_for(1,pos);
        for(auto i:loop)
        {
            constant+=given_expression[i];
        }
        }
    }
    else if(exist_constant==false)
    {
        constant="1";
    }

    cout<<"constant: "<<constant<<endl;
         // deal_with_only_x(power,main_term,constant);
         //cout<<given_expression<<endl;
          calculate_power_part(given_expression,constant,need_to_divide,upper,lower);
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
//      cout<<"position of coefficient and first bracket: "<<position_coefficient<<" "<<first_bracket<<endl;

        int main_str_size=0;
        if(no_coefficient==false){
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
        }
        else
        {
            coefficient="";
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

       if(system==6)
       {
           trigonmetry_diff_coefficient(given_expression,upper,lower);
       }
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
                  //  cout<<"pagol minus ase"<<endl;
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

          secondBrackets.clear(),firstBrackets.clear();
         //  pos_of_x.clear();

         //  coefficients.clear();
         //  waiting_x.clear();
           saving_square_pos.clear();
       }

       cout<<endl;
       cout<<endl;

      // cout<<main_output<<endl;
    }
    //if(count_term==all_answers.size()-1){
       int l=0;
//cout<<"size: "<<all_answers.size()<<endl;
for(int i=0;i<all_answers.size();i++)
{
    cout<<all_answers[i]<<endl;
}
       for(int i=0;i<all_answers.size();i++)
       {
           if(i==all_answers.size()-1)
           {
             // cout<<all_answers[i]<<"+c";
              main_output+="("+all_answers[i]+")"+"+c";
           }
           else
           {
               //cout<<all_answers[i]<<signs_are[l];
               main_output+="("+all_answers[i]+")"+signs_are[l];
                l++;
           }

       }
     //  }
      double main_output_within_limit=0.000000000;
        for(int i=0;i<all_answers_limit.size();i++)
       {
           if(i==0) main_output_within_limit+=all_answers_limit[i];
           else
           {
               if(signs_are[i-1]=='+')
               {
                    main_output_within_limit+=all_answers_limit[i];
               }
               else if(signs_are[i-1]=='-')
               {
                   main_output_within_limit-=all_answers_limit[i];
               }
           }
       }


       cout<<"main_output_within_limit: "<<endl;
       string dashes(30, '-');
       cout<<dashes;
       cout<<endl;
       cout<<(double)main_output_within_limit<<endl;
       within_limit.push_back(main_output_within_limit);


            cout<<"within limit:"<<endl;
            cout<<"--------------"<<endl;
       for(int i=0;i<within_limit.size();i++)
       {
           cout<<within_limit[i]<<endl;
       }

       cout<<endl;
       cout<<"The output is: "<<endl;
       string dashes1(15, '-');
       cout<<dashes1;
       cout<<endl;
       cout<<main_output<<endl;

       terms_pos.clear(),signs_are.clear();
       terms_string.clear();
       //constant_list.clear(),coefficient_list
       //secondBrackets.clear(),firstBrackets.clear();
       //pos_of_x.clear();
       all_answers.clear();
       all_answers_limit.clear();
      saved_answers="";
       limit_answers_double=1.00000;
       //limit_answers.clear();
       return main_output;
}


bool search1(string main,string input)
{
    if(main==input)
    {
        return true;
    }
    else
    {
        return false;
    }
}
motion_distance(string equation)
{
    int upper=0,lower=0;
    cout<<"distance: "<<equation;

}
motion_velocity(string equation)
{
    int upper=0,lower=0;
    string s1=parse(equation,upper,lower);
    cout<<endl;
    cout<<"----------------------------------------------------------------------"<<endl;
    cout<<"|       [ This is the output expression of velocity to distance ]"<<endl;
    cout<<"|                                                                  "<<endl;
    cout<<"|                   "<<s1<<"                                       "<<endl;
    cout<<"----------------------------------------------------------------------"<<endl;
}

motion_acceleration(string equation)
{
    int upper=0,lower=0;
    string s=parse(equation,upper,lower),s1;
    cout<<"----------------------------------------------------------------------"<<endl;
    cout<<"|       [ This is the output expression of velocity to distance ]"<<endl;
    cout<<s<<endl;
    cout<<"----------------------------------------------------------------------"<<endl;

    cout<<motion_velocity(s);


}

char about_motion()
{
     printf("\n\n");
     printf("motion\n");
     string dashes(7, '-');
     char input;
     cout<<dashes;
     printf("\n-->relation between velocity and acceleration\n-->relation between distance(d) and acceleration(a)\n-->relation between distance and velocity\n");
     printf("\n\n");

     cout<<"the equation want to input is about:\n--> distance(d),velocity(v) or acceleration(a)?:  ";
     cin>>input;

    //(input=='d')?
     return input;


}
work_force_limit(string equation,int upper,int lower)
{
    cout<<"W = F*x"<<endl;
    parse(equation,upper,lower);
}
work_force(string equation)
{
    int lower=0,upper=0;
    cout<<"W = F*x"<<endl;
    string s1=parse(equation,upper,lower);
    cout<<endl;
    cout<<"work is: "<<s1<<endl;
}

about_work(string equation)
{
     printf("\n\n");
     printf("work --> done by force\n");
     string dashes(15, '-');
     char input;
     cout<<dashes;
     printf("\n-->relation among work,force and distance\n\n");
     parse(equation,0,0);

}

about_energy()
{
     printf("\n\n");
     printf("energy --> supplying power\n");
     string dashes(15, '-');
     char input;
     cout<<dashes;
     printf("\n-->relation between energy and power \n\n");

}


string about_practice(string s)
{
    string s2,s1;
    cout<<"    TRY TO SOLVE IT "<<endl;
    cout<<"-----------------------"<<endl;
    cout<<"Enter your answer: ";
    cin>>s1;
    cout<<endl;
    return s1;
}



still_searching(string s2,string s1,string s)
{
    int ans;
    string s3;
     if(search1(s2,s1)==true)
        {
            cout<<"------------------------"<<endl;
            cout<<"       YOU GOT IT....   "<<endl;
            cout<<"------------------------"<<endl;
        }
        if(search1(s2,s1)==false)
        {
            cout<<"---------------------------------------------"<<endl;
            cout<<"         WRONG ANSWER"<<endl;
            cout<<"---------------------------------------------"<<endl;
            cout<<"1.Want to try again?\n"<<"2.Show answer..\n";
            cout<<"Enter : ";
            cin>>ans;
            if(ans==1)
            {
               s3=about_practice(s);
               still_searching(s2,s3,s);

            }
            else
            {
              cout<<endl;
              cout<<"---------------------------------------------"<<endl;
              cout<<"The ans is: "<<s2<<endl;
              cout<<endl;
              cout<<"                 Practice More!!!...."<<endl;
            }
        }

        cout<<endl;
        cout<<endl;
}
int main()
{
    string s;
    int upper,lower;
    cout<<endl;
    cout<<endl;

    string spaces(42, ' '),equation;
    cout<<spaces;
    cout<<"INTEGRATION ANALYZER"<<endl;
    string spaces1(30, ' '),dashes(45, '-');;
    cout<<spaces1;
    cout<<dashes;

    printf("\n\n");
    printf("WANT TO SOLVE SOME INTEGRAL PROBLEMS OR PHYSICS PROBLEMS OR WANT TO PRACTICE ?\n");
    string dashes1(90, '-');
    int type;
    cout<<dashes1;
    printf("\n");
    printf("Type 01: Ingeral problems\nType 02: Area between two equation\nType-03: Physics problems\nType 04: Practice\n\nEnter type: ");
    cin>>type;
    if(type==1)
    {
      printf("Enter the equation: ");
      cin>>s;
      printf("input upper and lower limit: ");
      cin>>upper>>lower;
      //parse(s,upper,lower);
      string s1=parse(s,upper,lower);
     // cout<<"s1: "<<s1<<endl;
    // parse(s1,lower,upper);
    }

    else if(type==2)
    {
        string s4,s5,s6,s7,s8;
        double area1=0.00000,area2=0.0000;
        printf("Enter the first equation: ");
        cin>>s4;
        printf("Enter the second equation: ");
        cin>>s5;
        printf("input upper and lower limit: ");
        cin>>upper>>lower;
        s6=parse(s4,upper,lower);
        s7=parse(s5,upper,lower);
        area1=within_limit[0];
        area2=within_limit[1];
        printf("\n\n");
        cout<<"-------------------------------------------------------------"<<endl;
        cout<<"The function of area is: ("<<s6<<")-("<<s7<<")"<<endl;
        cout<<"The area: "<<abs(area1-area2)<<endl;
        cout<<"-------------------------------------------------------------"<<endl;

    }
   else if(type==3){
     int type1=0;

    printf("what to want to do?\n");
    string dashes(20, '-'),equation;
    cout<<dashes;
    printf("\n-->motion\n-->force\n-->work\n-->energy\n\n\n");

    printf("enter your type(in number): ");
    scanf("%d",&type1);
    char ch;

    if(type1==1)
    {
        ch=about_motion();
    }
    if(type==2)
    {
        cout<<"F=m*a(suppose m is constant"<<endl;
        cout<<"-------------------------------"<<endl;
        ch='f';
    }
    if(type1==3)
    {
        ch='w';
    }
    if(type1==4) about_energy();
    cout<<"equation is: "<<ch<<"(x) =";

    cin>>equation;

     (ch=='v')? motion_velocity(equation):
     (ch=='a')? motion_acceleration(equation):
     (ch=='d')? motion_distance(equation):
     (ch=='w')? about_work(equation):work_force(equation);

    }
    else if(type==4)
    {
        string s,s2,s1,s3;
        int ans,an=30;
        cout<<"An equation given by teacher(an indefinite equation): "<<endl;
        cin>>s;
        s2=parse(s,0,0);
        while(an!=0)
        {
            cout<<endl;
            an--;
        }
        s1=about_practice(s);
       still_searching(s2,s1,s);
    }

}

