#include <bits/stdc++.h>
using namespace std;


int main() {
    string str = "(x)+(234)";

    string digits;


    copy_if(str.begin(), str.end(),back_inserter(digits), [](char c) {
        return isdigit(static_cast<unsigned char>(c));
    });

  cout << "Digits in the string: " << digits << endl;

    return 0;
}
