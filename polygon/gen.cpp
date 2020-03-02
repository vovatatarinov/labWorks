#include <bits/stdc++.h>

using namespace std;

int main() {
    cout << "Введите количество точек> ";
    int n;
    cin >> n;
    fstream out("data.txt", fstream::out);
    for (int i = 0; i < n; ++i) {
        cout << "Точка №" << i+1 << " из " << n << '.' << endl << "Введите x> ";
        double x;
        cin >> x;
        cout << "Введите y> ";
        double y;
        cin >> y;
        out << x << ' ' << y << endl;
    }
    out.close();
}

