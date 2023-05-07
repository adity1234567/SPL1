#include<bits/stdc++.h>
using namespace std;


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

double work_for_trigonmetry(string for_limit_calculation,int bound)
{
    int i=0;
    while(i<for_limit_calculation.size())
    {

    }
}
double with_limit(vector<string>&for_limit_calculation,int lower,int upper)
{
    int i=0;
    double upper_num,lower_num;
    while(i<for_limit_calculation.size())
    {
        bool check=check_is_trigonmetry(for_limit_calculation[i]);
        bool only_x_type=check_type_two(for_limit_calculation[i]);
        bool x_type=check_type_one(for_limit_calculation[i]);

        if(check==true)
        {
           upper_num=work_for_trigonmetry(for_limit_calculation[i],upper);
           lower_num=work_for_trigonmetry(for_limit_calculation[i],lower);
        }
        else if(only_x_type==true)
        {
            upper_num=work_for_type_two(for_limit_calculation[i],upper);
            lower_num=work_for_type_two(for_limit_calculation[i],lower);
        }
        else
        {
            upper_num=work_for_type_one(for_limit_calculation[i],upper);
            lower_num=work_for_type_one(for_limit_calculation[i],lower);
        }

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
