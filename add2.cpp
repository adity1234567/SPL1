#include<bits/stdc++.h>
using namespace std;

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


int function_i_increase(int i)
{
    i++;
    return i;
}

bool check_is_trigonmetry(string str)
{
    bool check=false;
    //string str = "Calculate the value of sin(x) + cos(x)";
    string search_terms[] = {"sin", "cos", "tan", "asin", "acos", "atan"};

    for (int i = 0; i < sizeof(search_terms)/sizeof(search_terms[0]); i++) {
        string term = search_terms[i];
        int pos = str.find(term);
        if (pos != string::npos) {
                check=true;
        }
    }
    return check;
}

double only_x_type(string input,int bound)
{
    return bound;
}


double type_no_two(string input,int bound)
{
   string str1="-";str2="x^2";
      int pos1=input.find(str1);
      int pos2=input.find(str2);
      double div1=0.0000,div2=0.0000;
      double a_plus_x=0.00000,a_minus_x1=0.00000,a_minus_x2=0.00000;
      double ans=0.000000;

    if (pos1 != string::npos&& pos2 != string::npos)
    {
        ///substring found
        double modified_a_by_b=convert_string_to_int(a_by_b)
        a_plus_x=modified_a_by_b+bound;
        a_minus_x1=bound-modified_a_by_b;
        a_minus_x2=modified_a_by_b-bound;

        div1=a_plus_x/a_minus_x2;
        div2=a_minus_x1/a_plus_x;

        if()
        {
            ans=log(div1);
        }
        else ans=log(div2);
    }
}
double with_limit(vector<string>&for_limit_calculation,int lower,int upper)
{
    int i=0;
    vector<double>store_diff;
    double upper_num,lower_num,difference=0.000000000;
    while(i<for_limit_calculation.size())
    {
        bool check=check_is_trigonmetry(for_limit_calculation[i]);
        bool only_x_type=check_type_two(for_limit_calculation[i]);
        bool x_type=check_type_one(for_limit_calculation[i]);

        if(check==true)
        {
            double modified_upper=(upper*180)/3.1416;
            double modified_lower=(lower*180)/3.1416;
           upper_num=work_for_trigonmetry(for_limit_calculation[i],modified_upper);
           lower_num=work_for_trigonmetry(for_limit_calculation[i],modified_lower);

           //difference=upper_num-lower_num;
        }
        else if(only_x_type==true)
        {
            upper_num=work_for_type_two(for_limit_calculation[i],upper);
            lower_num=work_for_type_two(for_limit_calculation[i],lower);

           // difference=upper_num-lower_num;
        }
        else
        {
            upper_num=work_for_type_one(for_limit_calculation[i],upper);
            lower_num=work_for_type_one(for_limit_calculation[i],lower);

            //difference=upper_num-lower_num;
        }


           if(power==true)
           {
               int int_power=convert_string_to_int(power);

               upper_num=pow(upper_num,power);
               lower_num=pow(lower_num,power);
           }
           if(constant==true)
           {
               double double_constant=convert_string_to_int(constant);

               upper_num=constant*upper_num;
               lower_num=constant*lower_num;
           }

           difference=upper_num-lower_num;
           store_diff.push_back(difference);

        function_i_increase(i);
    }

}
int main()
{
    int lower,upper;
    cout<<"input upper and lower limit: "<<endl;
    cin>>upper>>lower;

    vector<string>for_limit_calculation;
    with_limit(for_limit_calculation,lower,upper)
}
