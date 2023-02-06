
#include<bits/stdc++.h>
using namespace std;

int string_to_int(string str) {
    int result = 0;
    int sign = 1;
    int i = 0;

    if (str[0] == '-') {
        sign = -1;
        i++;
    }

    while (i < str.length()) {
        result = result * 10 + str[i] - '0';
        i++;
    }

    return result * sign;
}

int main()
{
    int type,a,pos_a,pos_n,pos_div;
    string A="",n="",equation,B="",n2="";
    int upor,niche;
    string partToAdd="x";

    cout<<"type 1: a*x^n"<<endl;
    cout<<"type 2: a*x^(-1)"<<endl;
    cout<<"type 3: a*sin(px/q) or a*sin(mx)"<<endl;
    cout<<"type 4: a*cos(px/q) or a*cos(mx)"<<endl;
     cin>>type;
    cout<<"Equation: ";
    cin>>equation;
    //getline(cin,equation);
     cout<<"  "<<equation<<endl;
    if(type==1)
    {
       upor=0,niche=0;

        for(int i=0;i<equation.size();i++)
        {
            if(equation[i]=='/')//2/3*x^2 pos_div=2 pos=4 pos_n=6
            {
                pos_div=i;
            }
            if(equation[i]=='*')
            {
               pos_a=i;
            }
            if(equation[i]=='^')
            {
                pos_n=i;
               // break;
            }
        }
        for(int i=0;i<pos_a;i++)
        {
           /* if(equation[i]=='/')
            {
                for(int j=0;j<pos_div;j++)
                {
                    B+=equation[j];//b=2
                }
                for(int j=pos_div+1;j<pos_a;i++)
                {
                    n2+=equation[j];//n2=3
                }
               // break;
            }
            else
            {
               A+=equation[i];
            }*/
             A+=equation[i];
        }
        for(int i=pos_n+1;i<=equation.size();i++)
        {
            n+=equation[i];
        }

       // cout<<A<<"a "<<n<<"n "<<B<<"b "<<n2<<endl;

        upor=stoi(A);
       niche=stoi(n);
        cout<<"= "<<upor<<"*("<<partToAdd<<"^"<<niche+1<<")/"<<niche+1<<"+C"<<endl;
        cout<<"= ("<<upor<<"/"<<niche+1<<")*"<<partToAdd<<"^"<<niche+1<<"+C"<<endl;
    }

    else if(type==2)
    {
        upor=0,niche=0;

         for(int i=1;i<=equation.size();i++)
        {
            if(equation[i]=='*')
            {
              pos_a=i;
            }
        }
        for(int i=0;i<pos_a;i++)
        {
            A+=equation[i];
        }
         upor=stoi(A);
         cout<<"= "<<upor<<"*(1/"<<partToAdd<<")+C"<<endl;
         cout<<"= "<<upor<<"*ln("<<partToAdd<<")+C"<<endl;
    }

    else if(type==3)
    {
        upor=0,niche=0;
        int pos_b,pos_x;
        string sintocos="cos",sin="sin";

       A="",B="";
         for(int i=1;i<=equation.size();i++)
        {
            if(equation[i]=='*')
            {
              pos_a=i;
            }
            if(equation[i]=='(')
            {
               pos_b=i;
            }
             if(equation[i]=='x')
            {
               pos_x=i;
            }

        }
        for(int i=0;i<pos_a;i++)
        {
            A+=equation[i];
        }
        for(int i=pos_b+1;i<pos_x;i++)
        {
            B+=equation[i];
        }
         upor=stoi(A);
         niche=stoi(B);
         cout<<"= "<<upor<<"*(-"<<sintocos<<"("<<niche<<"x))/"<<niche<<"+c"<<endl;
         cout<<"= -"<<upor<<"/"<<niche<<"*"<<sintocos<<"("<<niche<<"x)+c"<<endl;
    }
    else if(type==4)
    {
        upor=0,niche=0;
        int pos_b,pos_x;
        string costosin="sin",cos="cos";

       A="",B="";
         for(int i=1;i<=equation.size();i++)
        {
            if(equation[i]=='*')
            {
              pos_a=i;
            }
            if(equation[i]=='(')
            {
               pos_b=i;
            }
             if(equation[i]=='x')
            {
               pos_x=i;
            }

        }
        for(int i=0;i<pos_a;i++)
        {
            A+=equation[i];
        }
        for(int i=pos_b+1;i<pos_x;i++)
        {
            B+=equation[i];
        }
         upor=stoi(A);
         niche=stoi(B);
         cout<<"= "<<upor<<"*("<<costosin<<"("<<niche<<"x))/"<<niche<<"+c"<<endl;
         cout<<"= "<<upor<<"/"<<niche<<"*"<<costosin<<"("<<niche<<"x)+c"<<endl;
    }
}

