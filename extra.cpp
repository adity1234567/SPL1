#include <bits/stdc++.h>
using namespace std;

string reverse_string(string s) {
    stack<char> st;
    string p = "";
    for (char x : s)
        st.push(x);
    while (!st.empty()) {
        p += st.top();
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
long long int convert_string_to_int(string string_to_convert)
{
    long long int converted_int=0,str_len=string_to_convert.size();
    long long int char_index=0,negative=0;

    if(string_to_convert[0]=='-')
    {
        char_index=1;
        negative=1;
    }

    for(int i=char_index;i<str_len;i++)
    {
        converted_int*=10;
        converted_int=(long long int)(string_to_convert[i]-'0');
    }
    if(negative)
    {
        converted_int=-converted_int;
    }
    return converted_int;
}



void extra(string given_expression)
 {
    bool can_divide = true;
    int x = 2, i = 0, bracket2 = 0, bracket1 = 0;
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
    cout << "nicher_constant: " << nicher_constant << endl;

    for (int i = multi_pos[0] - 1; given_expression[i] != '('; i--)
    {
        reverse_upor_constant += given_expression[i];
    }

    upor_constant = reverse_string(reverse_upor_constant);
    cout << "upor_constant: " << upor_constant << endl;
    cout << "upor_extra_constant: " << upor_extra_constant << endl;

    string nicher_extra_constant = "",nicher_extra_constant_sign="";
    auto it = signs.begin();

    if (signs.size() == 1)
    {
        cout << "*it and sign_pos: " << *it << " " << signs_pos[1] << endl;
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

    cout << "nicher_extra_constant: " << nicher_extra_constant << endl;

    int nicher_constant_int=0,upor_extra_constant_int=0,nicher_extra_constant_int,square_nicher_constant=0,new_extra_constant=0,upor_constant_int;
    int extra_constant_int=0,new_extra_constant1,new_extra_constant2;
    string extra_constant;

     nicher_constant_int=convert_string_to_int(nicher_constant);
     cout<<"nicher_constant_int: "<<nicher_constant_int<<endl;
     upor_extra_constant_int=convert_string_to_int(upor_extra_constant);
     upor_constant_int=convert_string_to_int(upor_constant);
     nicher_extra_constant_int=convert_string_to_int(nicher_extra_constant);
     square_nicher_constant=nicher_constant_int*nicher_constant_int;
     new_extra_constant1=nicher_constant_int*upor_extra_constant_int;
     new_extra_constant2=nicher_extra_constant_int*upor_constant_int;

     cout<<"new_extra_constant1 &constant2: "<<new_extra_constant1<<" "<<new_extra_constant2<<endl;
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
     cout<<"extra_constant: "<<extra_constant<<endl;

}

int main()
{
    string s;
    cin >> s;
    extra(s);
    return 0;
}
