#include <bits/stdc++.h>
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

double calculate_trigonmetry_part(string input, double bound) {
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


int main()
{
    string s = "tanx";
    double bound = 0.523599;
    cout << calculate_trigonmetry_part(s, bound) << endl;
    return 0;
}
