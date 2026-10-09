#include <iostream>
#include <string>

using namespace std;

struct badTable {
    char letter;
    int val;
};

int BadChar(string pattern, badTable* table) {
    int m = pattern.length();
    int count = 0;

    for (int i = 0; i < m - 1; i++) {
        char c = pattern[i];
        int foundIndex = -1;

        for (int k = 0; k < count; k++) {
            if (table[k].letter == c) {
                foundIndex = k;
                break;
            }
        }

        int shift = m - i - 1;

        if (foundIndex != -1) {
            table[foundIndex].val = shift;
        } else {
            table[count].letter = c;
            table[count].val = shift;
            count++;
        }
    }

    table[count].letter = '*';
    table[count].val = m;
    return ++count;
}

int getShift(char c, badTable* table, int tableSize) {
    for (int i = 0; i < tableSize - 1; i++) {
        if (table[i].letter == c) {
            return table[i].val;
        }
    }
    return table[tableSize - 1].val;
}

void getSuffix(string pattern, int* suff) {
    int m = pattern.length();
    suff[m - 1] = m;

    for (int i = m - 2; i >= 0; i--) {
        int j = i;
        while (j >= 0 && pattern[j] == pattern[m - 1 - i + j]) {
            j--;
        }
        suff[i] = i - j;
    }
}

void goodSuffix(string pattern, int* gs) {
    int m = pattern.length();
    int* suff = new int[m];

    getSuffix(pattern, suff);

    for (int i = 0; i < m; i++) {
        gs[i] = m;
    }

    int j = 0;
    for (int i = m - 1; i >= 0; i--) {
        if (suff[i] == i + 1) {
            for (; j < m - 1 - i; j++) {
                if (gs[j] == m) {
                    gs[j] = m - 1 - i;
                }
            }
        }
    }

    for (int i = 0; i <= m - 2; i++) {
        gs[m - 1 - suff[i]] = m - 1 - i;
    }

    delete[] suff;
}

int maxVal(int a, int b) {
    if (a > b) return a;
    return b;
}

void boyerMoore(string t, string p) {
    int n = t.length();
    int m = p.length();

    if (m == 0 || n < m) return;

    badTable* table = new badTable[m + 1];
    int tableSize = BadChar(p, table);

    int* gs = new int[m];
    goodSuffix(p, gs);

    int i = 0;
    while (i <= n - m) {
        int j = m - 1;

        while (j >= 0 && p[j] == t[i + j]) {
            j--;
        }

        if (j < 0) {
            cout << i << endl;
            i += gs[0];
        } else {
            int badCharShift = getShift(t[i + m - 1], table, tableSize);
            int goodSuffixShift = gs[j];
            i += maxVal(badCharShift, goodSuffixShift);
        }
    }

    delete[] table;
    delete[] gs;
}

int main() {
    string t, p;
    cin >> t >> p;

    boyerMoore(t, p);

    return 0;
}
