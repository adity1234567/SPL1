#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string equation = "2*x^2+3*x-4=0 x^2 dx x^2";
    string delimiters = "+-*/=^ dx";
    string token;
    for (int i = 0; i < equation.length(); i++) {
        if (delimiters.find(equation[i]) != std::string::npos) {
            cout << equation[i] << endl;
        } else if (isspace(equation[i])) {
            continue;
        }
        else {
            token += equation[i];
        }
        if (i == equation.length() - 1 || delimiters.find(equation[i + 1]) != std::string::npos || isspace(equation[i+1])) {
            cout << token << endl;
            token.clear();
        }
    }
    return 0;
}
