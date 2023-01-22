
#include <stdio.h>
#include <math.h>
#include<bits/stdc++.h>
using namespace std;



double f(double x,string equation)
{
    string delimiters = "+-*/=^ dx";
    string token;
    for (int i = 0; i < equation.size(); i++) {
        if (delimiters.find(equation[i]) != std::string::npos)
        {
            cout << equation[i] << endl;
        }
        else if (isspace(equation[i]))
        {
            continue;
        }
        else {
            token += equation[i];
        }
        if (i == equation.length() - 1 || delimiters.find(equation[i + 1]) != std::string::npos || isspace(equation[i+1]))
        {
            //cout << token << endl;
            return token;
            token.clear();
        }
    //return x*x + 1;
}

double area(string equation,double a, double b, int n)
{
    double h = (b-a)/n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; i++) {
        double x = a + i*h;
        sum += f(x,equation);
        printf("x: %f, f(x): %f, sum: %f\n",x,f(x),sum);
    }
    return sum * h;
}

int main()
{
    string equation;
    printf("enter equation: ");
    cin>>equation;
    double a = 0;
    double b = 2;
    int n = 10;

    printf("y = %f\n", area(equation,a, b, n));
    return 0;
}

























/*#include<bits/stdc++.h>
using namespace std;

double equation(double x)
{
   // string equat;
    cout<<"Input an equation: ";
    cout<<"the degree of equation: ";
    cin>>deg;
    float values[deg+5];
    for(int i=0;i<=deg;i++)
    {
        cout<<"Enter the value for "<<i<<" :";
        cin>>values[i];
    }

    cout<<"Equation is: ";
    for(int i=deg;i>=0;i--)
    {
        if(i==0)
        {
           cout<<values[i]<<endl;
        }
        else
        {
           cout<<values[i]<<"*x^"<<i<<"+";
        }
    }
   //9   cin>>equat;
    return equat;
}

double with_limit(double lowerBound,int n,double dx)
{
    double total=0,p[1000],equ[10000],area;
   /* for(int i=0;i<n;i++)
    {
        p[i]=lowerBound+i*dx;
        //equ=equation;
        //area=equation*dx;
        for(int j=0;j<deg;j++)
        {
            equ[i]=values[j]*pow(p[i],j);
        }

        total+=area;
    }*/
   /* for(int i=0;i<n;i++)
    {
        double xi=lowerBound+i*dx;
        double value=equation(xi);
        double area=value*dx;
        total+=area;
    }
    return total;
}



int main()
{
    cout<<"Calculation of equation within limit"<<endl;
    cout<<"----------------------------------------------------------------";
    cout<<endl;


    double lowerBound,upperBound,dx,result,equation;
    int deg;
   // cout<<"Input an equation: ";
  /*  cout<<"the degree of equation: ";
    cin>>deg;
    float values[deg+5];
    for(int i=0;i<=deg;i++)
    {
        cout<<"Enter the value for "<<i<<" :";
        cin>>values[i];
    }

    cout<<"Equation is: ";
    for(int i=deg;i>=0;i--)
    {
        if(i==0)
        {
           cout<<values[i]<<endl;
        }
        else{
        cout<<values[i]<<"*x^"<<i<<"+";
        }
    }*/
   /* cout<<"Enter the lower-bound: ";
    cin>>lowerBound;
    cout<<"Enter the upper-bound: ";
    cin>>upperBound;
    int n=1000;

    dx=(double)(upperBound-lowerBound)/n;
    result=with_limit(lowerBound,n,dx);

    cout<<result<<endl;
}
*/
