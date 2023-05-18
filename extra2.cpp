#include<bits/stdc++.h>
using namespace std;


vector<int> computeLPS(const std::string& pattern)
{
    std::vector<int> lps(pattern.length(), 0);
    int len = 0;

    for (size_t i = 1; i < pattern.length(); )
    {
        if (pattern[i] == pattern[len])
        {
            lps[i++] = ++len;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i++] = 0;
            }
        }
    }

    return lps;
}


vector<int> KMPSearch(const std::string& text, const std::string& pattern)
{
    std::vector<int> positions;
    int n = text.length();
    int m = pattern.length();
    std::vector<int> lps = computeLPS(pattern);

    int i = 0;  // Index for text
    int j = 0;  // Index for pattern

    while (i < n)
     {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            // Match found at index (i - j)
            positions.push_back(i - j);
            j = lps[j - 1];
        }
         else if (i < n && text[i] != pattern[j])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    return positions;
}


vector<int>find_substring(string text,string pattern)
{
    vector<int> pos = KMPSearch(text, pattern);
    if(!pos.empty())
    {
        return pos;
    }
    else
    {
        return pos;
    }
}
trigonmetry_diff_coefficient(string equation)
{
    ///sin(5*x)cos(4*x)

    vector<int>pos1=find_substring(equation,"sin");
    vector<int> pos2=find_substring(equation,"cos");
}
int main()
{
    string s;
    cin>>s;
}
