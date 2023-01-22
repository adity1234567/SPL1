#include<bits/stdc++.h>
using namespace std;

#define size1 100

double evaluate_expression(double x,char *equation)
{
    double stack1[size1],operand1,operand2;
    int top=-1;

    //one kind od tokenization
    char *token;
    token=strtok(equation," ");
    while(token!=NULL)
    {
        if(token[0]>='0'&&token[0]<='9')
        {
            top++;
           stack1[top]=strtod(token,NULL);
        }
        else if(token[0]=='x')
        {
            top++;
            stack1[top]=x;
        }
        else
        {
          operand2=stack1[top--];
          operand1=stack1[top--];
          if(token[0]=='+')
          {
              top++;
              stack1[top]=operand1+operand2;
          }
          else if(token[0]=='-')
          {
              top++;
              stack1[top]=operand1-operand2;
          }
          else if(token[0]=='*')
          {
              top++;
              stack1[top]=operand1*operand2;
          }
           else if(token[0]=='/')
          {
              top++;
              stack1[top]=operand1/operand2;
          }
          else if(token[0]=='^')
          {
              top++;
              stack1[top]=pow(operand1,operand2);
          }
         // token=strtok(NULL," ");
         else if(strcmp(token, "sin") == 0)
         {
             top++;
            stack1[top] = sin(operand2);
         }
         else if(strcmp(token, "cos") == 0)
         {
              top++;
              stack1[top] = cos(operand2);
         }
         else if(strcmp(token, "tan") == 0)
         {
             top++;
             stack1[top] = tan(operand2);
         }
        else if(strcmp(token, "e") == 0)
        {
            top++;
            stack1[++top] = exp(operand2);

        }
    }
        token=strtok(NULL," ");
  }
    return stack1[top];
}

int main() {
    double a, b, n, h, result = 0.00;
    char equation[100];
    cout << "Enter the function to be integrated: ";
    cin >> equation;
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;
    cout << "Enter the value of n: ";
    cin >> n;

    h = (b - a) / n;

    for (int i = 1; i < n; i++) {
        result += evaluate_expression(a + i*h, equation);
    }

    result = (h / 2) * (evaluate_expression(a, equation) + evaluate_expression(b, equation) + 2*result);

    cout << "The result is: " << result << endl;

    return 0;
}
