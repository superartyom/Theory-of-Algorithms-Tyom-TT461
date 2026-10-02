#include <iostream>

using namespace std;

int partition(int a[], int l, int r) {
    int pivot = a[r];
    int i = l - 1;

    for (int j = l; j < r; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void recurse(int a[], int l, int r) {
    if (l >= r) return;

    int m = partition(a, l, r);

    recurse(a, l, m - 1);
    recurse(a, m + 1, r);
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