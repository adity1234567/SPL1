#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>


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

int main()
{
    printf("The velocity of a particle moving along the x-axis is ?.At t=0,its position is 3.\n");
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

}
