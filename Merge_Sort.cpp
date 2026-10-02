#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r) {
    int size = r - l + 1;
    int* temp = new int[size];
    int i = l;
    int j = m + 1;
    int k = 0;

    while (i <= m && j <= r)
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];

    while (i <= m) temp[k++] = a[i++];

    while (j <= r) temp[k++] = a[j++];

    for (int p = 0; p < size; p++) {
        a[l + p] = temp[p];
    }

    delete[] temp;
}

void recurse(int a[], int l, int r) {
    if (l >= r) return;

    int m = l + (r - l) / 2;

    recurse(a, l, m);
    recurse(a, m + 1, r);
    merge(a, l, m, r);
}

int main() {
    int a[20], n;

    do {
        cin >> n;
    } while (n < 2 || n > 20);

    for (int i = 0; i < n; i++) cin >> a[i];

    recurse(a, 0, n - 1);

    for (int i = 0; i < n; i++) cout << a[i] << " ";

    return 0;
}