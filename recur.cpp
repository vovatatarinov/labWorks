#include <bits/stdc++.h>

using namespace std;

void f(int* a, int* b, int l, int r, int i) {
    int m = (l + r) / 2;
    if (l != r) {
        f(a, b, l, m, 2 * i);
        f(a, b, m + 1, r, 2 * i + 1);
    }
    int max = a[l];
    for (int i = l; i <= r; ++i)
        if (max < a[i])
            max = a[i];
    b[i - 1] = max;
    if (l == r)
        return;
}

int main() {
    srand(time(NULL));
    cout << "Введите p (N = 2^p)>  ";
    int p;
    cin >> p;
    int n = (1 << p);
    cout << endl << "N = " << n << endl << endl;
    int* a = new int[n];
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % 99 + 1;
        cout << a[i] << " ";
    }
    int* b = new int[2*n - 1];
    f(a, b, 0, n - 1, 1);
    cout << endl << endl;
    for (int i = 0; i < 2*n - 1; ++i)
        cout << b[i] << ' ';
    cout << endl << endl;
 }
