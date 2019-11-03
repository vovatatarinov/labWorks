#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
   // double x = 0;
    double v = 0;
    double* s = new double[n];
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    double* a = new double[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    double* t = new double[n];
    v = 0;
    t[0] = sqrt(2*s[0]/a[0]);
    //x += s[0];
    v += a[0] * t[0];
    for (int i = 1; i < n; ++i) {
        t[i] = -v + sqrt(v*v + 2 * a[i] * s[i]);
	t[i] /= a[i];
        v += a[i] * t[i];
    }
    double time = 0;
    for (int i = 0; i < n; ++i)
        time += t[i];
    printf("%.4lf\n", time);
    return 0;
        
}
