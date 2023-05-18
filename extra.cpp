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
            i++; // Increment i here
        }
    }

    string nicher_constant = "", reverse_upor_constant = "", upor_constant = "";
    string reverse_upor_extra_constant = "", upor_extra_constant = "";

    for (int i = bracket2 + 1; given_expression[i] != '*'; i++)
    {
        nicher_constant += given_expression[i];
    }

    for (int i = bracket1 - 1; i >= 0; i--)
    {
        if (given_expression[i] == '+' || given_expression[i] == '-')
            {
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

    string nicher_extra_constant = "";
    auto it = signs.begin();

    if (signs.size() == 1)
    {
        cout << "*it and sign_pos: " << *it << " " << signs_pos[1] << endl;
        if (*it == '+')
        {
            nicher_extra_constant += "-";
            for (int pos = signs_pos[1] + 1; given_expression[pos] != ')'; pos++)
            {
                nicher_extra_constant += given_expression[pos];
            }
        }
    }
    else
    {
        for (int pos = signs_pos[1] + 1; given_expression[pos] != ')'; pos++)
        {
            nicher_extra_constant += given_expression[pos];
        }
    }

    cout << "nicher_extra_constant: " << nicher_extra_constant << endl;

    int nicher_constant_int=0,upor_extra_constant_int=0,square_nicher_constant=0,new_extra_constant=0,uporw_constant_int;
    int extra_constant=0;
     nicher_constant_int=convert_string_to_int(nicher_constant);
     upor_extra_constant_int=convert_string_to_int(upor_extra_constant);
     nicher_extra_constant_int=convert_string_to_int(nicher_extra_constant);
     square_nicher_constant=square(nicher_constant_int);
     new_extra_constant1=nicher_constant_int*upor_extra_constant_int;
     new_extra_constant2=nicher_extra_constant_int*upor_constant_int;

     if(signs.size()==1)
     {
         extra_constant=abs(new_extra_constant1-new_extra_constant2);
     }
     else
     {
                  extra_constant=abs(new_extra_constant1+new_extra_constant2);

     }

}

int main() {
    string s;
    cin >> s;
    extra(s);
    return 0;
}
