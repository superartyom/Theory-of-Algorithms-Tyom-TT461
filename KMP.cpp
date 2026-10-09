#include <iostream>
#include <string>
using namespace std;

void calcLPS(string pattern, int* lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1, m = pattern.length();

    while(i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len != 0) len = lps[len - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmp(string t, string p)
{
    int n = t.length();
    int m = p.length();

    if (m == 0 || n < m) return;

    int* lps = new int[m];

    calcLPS(p, lps);

    int i = 0, j = 0;
    while (i < n)
    {
        if (t[i] == p[j])
        {
            i++;
            j++;
            if (j == m)
            {
                cout << i - j + 1<< endl;
                j = lps[j - 1];
            }
        }
        else
        {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }

    delete[] lps;
}

int main()
{
    string t, p;
    cin>>t>>p;
    kmp(t, p);
    return 0;
}
