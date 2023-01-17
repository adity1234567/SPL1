#include<bits/stdc++.h>
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
    for(int i=0;i<n;i++)
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
    cout<<"Enter the lower-bound: ";
    cin>>lowerBound;
    cout<<"Enter the upper-bound: ";
    cin>>upperBound;
    int n=1000;

    dx=(double)(upperBound-lowerBound)/n;
    result=with_limit(lowerBound,n,dx);

    cout<<result<<endl;
}
