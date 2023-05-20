#include<bits/stdc++.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

/*
///first equation of motion
motion1_distance(int upper,int lower)
{
    return upper-lower;
}

motion1_time(int upper,int lower)
{
    return upper-lower;
}

motion1_velocity(int initial,int final1)
{
    return initial+final1;
}

///second equation of motion-->a constant
motion2_velocity(int initial,int final1)
{
    return initial+final1;
}
motion2_time(int upper,int lower)
{
    return upper-lower;
}
*/


void replaceVariable(char *equation, const char *oldVar, const char *newVar) {
    char *pos = strstr(equation, oldVar);
    size_t oldLen = strlen(oldVar);
    size_t newLen = strlen(newVar);
    size_t equationLen = strlen(equation);
    size_t offset = 0;

    while (pos != NULL) {
        size_t newPos = pos - equation + offset;

        memmove(equation + newPos + newLen, equation + newPos + oldLen, equationLen - newPos - oldLen + 1);
        memcpy(equation + newPos, newVar, newLen);

        offset += newLen - oldLen;
        pos = strstr(equation + newPos + newLen, oldVar);
    }
}
motion_distance(string equation)
{
    int upper=0,lower=0;
    cout<<"distance: "<<equation;

}
motion_velocity(string equation)
{
    int upper=0,lower=0;
    cout<<"velocity to distance: ";
    parse(equation,upper,lower);
}

motion_acceleration(string equation)
{
    int upper=0,lower=0;
    cout<<"velocity to distance: ";
    motion_velocity(equation);


}

char about_motion()
{
     printf("\n\n");
     printf("motion\n");
     string dashes(7, '-');
     char input;
     cout<<dashes;
     printf("\n-->relation between velocity and acceleration\n-->relation between distance(d) and acceleration(a)\n-->relation between distance and velocity\n");
     printf("\n\n");

     cout<<"the equation want to input is about:\n--> distance(d),velocity(v) or acceleration(a)?:  ";
     cin>>input;

    //(input=='d')?
     return input;


}
work_force_limit(string equation,int upper,int lower)
{
    cout<<"W = F*x"<<endl;
    parse(equation,upper,lower);
}
work_force(string equation)
{
    int lower=0,upper=0;
    cout<<"W = F*x"<<endl;
    parse(equation,upper,lower);
}

about_work()
{
     printf("\n\n");
     printf("work --> done by force\n");
     string dashes(15, '-');
     char input;
     cout<<dashes;
     printf("\n-->relation among work,force and distance\n\n");

}

about_energy()
{
     printf("\n\n");
     printf("energy --> supplying power\n");
     string dashes(15, '-');
     char input;
     cout<<dashes;
     printf("\n-->relation between energy and power \n\n");

}
int main()
{
    /*printf("The velocity of a particle moving along the x-axis is ?.At t=0,its position is 3.\n");
    printf("what is the position of the particle,s(t),at any time t?");
    string equation;
    printf("v(t)= ");
    scanf("%s",&equation);
    replaceVariable(equation, "t", "x");
    parse(equation);

    ///double integration
    printf("As a particle moves along the number line, its position at time t is s(t), its velocity is v(t) and a(t)=");

    ///v dewa like--> e^t  t-->0 to 2

    ///w=integration of Fdx

    ///v-->s

    ///a-->v-->s



    printf("input the equation of acceleration: ");
    */

    int type=0;

    printf("what to want to do?\n");
    string dashes(20, '-'),equation;
    cout<<dashes;
    printf("\n-->motion\n-->force\n-->work\n\n\n");

    printf("enter your type(in number): ");
    scanf("%d",&type);
    char ch;

    if(type==1)  ch=about_motion();
    if(type==2) about_work(); ch='w';
    cout<<"equation is: "<<ch<<"() =";

    cin>>equation;

     (ch=='v')? motion_velocity(equation):
     (ch=='a')? motion_accleration(equation):motion_distance(equation);



}
