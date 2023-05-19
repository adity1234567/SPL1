#include<bits/stdc++.h>
using namespace std;


vector<int> computeLPS(const std::string& pattern)
{
    std::vector<int> lps(pattern.length(), 0);
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


vector<int> KMPSearch(const std::string& text, const std::string& pattern)
{
    std::vector<int> positions;
    int n = text.length();
    int m = pattern.length();
    std::vector<int> lps = computeLPS(pattern);

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

trigonmetry_diff_coefficient(string equation)
{
    ///sin(5*x)cos(4*x)

    vector<int>pos1=find_substring(equation,"sin");
    vector<int> pos2=find_substring(equation,"cos");
    int coefficient1=0,coefficient2=0,main_coefficient=0,plus_coefficient_int=0,minus_coefficient_int=0;
    vector<int>coefficients=extractNumbers(equation);
    string sign="/",output1="",output2="",main="x";

    coefficient1=convert_string_to_int(coefficients[0]);
    coefficient2=convert_string_to_int(coeeficients[1]);
    plus_coefficient_int=coefficient1+coefficient2;
    minus_coefficient_int=abs(coefficient1-coefficient2);

    int constant_int=extract_constant(equation);
    string constant,plus_coefficient,minus_coefficient;
    constant=convert_int_to_string(constant);
    plus_coefficient=convert_int_to_string(plus_coefficient_int);
    minus_coefficient=convert_int_to_string(minus_coefficient_int);

    if(!pos1.empty()||!pos2.empty())
    {
        if(pos1.size()==1&&pos2.size()==1)
        {
           output1+="("+constant;
           output1+=sign + "2)(sin(";
           output1+=plus_coefficient+output1+="*"+main+"+(sin(";
           output1+=minus_coefficient+"*"+main+")";

           cout<<output1<<endl;
           ///trigonmetry sin to cos kora lagbe.....

           output2+="("+constant+sign + "2)(-cos("+plus_coefficient;
        }

    }
    else
    {
        if(pos1.size()==2&&pos2.empty())
        {
           ///trigonmetry sin to cos kora lagbe.....

           output2+="("+constant+sign + "2)(-cos("+plus_coefficient;
        }
        else if(pos2.size()==2&&pos1.empty())
        {
            ///trigonmetry sin to cos kora lagbe.....

           output2+="("+constant+sign + "2)(-cos("+plus_coefficient;
        }
    }

}
int main()
{
    string s;
    cin>>s;
}
