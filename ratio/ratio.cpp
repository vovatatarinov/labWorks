#include <iostream>

using namespace std;

class ratio
{
private:
int num, den;
void reduce();
int gcd(int n, int m);
int lcm(int a, int b);
public:
ratio();
ratio(int n, int d);
void set(int, int);
void show();
ratio operator*(ratio);
ratio operator+(ratio);
ratio operator*(int);
friend ratio operator*(int, ratio);
};

void ratio::set(int n, int d) {
    num = n;
    den = d;
    reduce();
}

ratio::ratio() {
    set(1,1);
}

ratio::ratio(int n, int d) {
    set(n, d);
}

void ratio::show() {
    if (num < 0)
        cout << endl << "  "<< -num << endl << "- ###" << endl << "  " << den << endl;
    else
        cout << endl << num << endl << "###" << endl << den << endl;
}

int ratio::gcd (int a, int b) {
	return b ? gcd (b, a % b) : a;
}

int ratio::lcm (int a, int b) {
	return a / gcd (a, b) * b;
}

void ratio::reduce() {
    int buf = abs(gcd(num,den));
    num /= buf;
    den /= buf;
    if (den < 0) {
        num *= (-1);
        den *= (-1);
    }
}

ratio ratio::operator*(ratio r) {
    return ratio(num * r.num, den * r.den);
}

ratio ratio::operator+(ratio r) {
    int b = lcm(r.den, den);
    int a = num * b / den + r.num * b / r.den;
    return ratio(a,b);
}

ratio ratio::operator*(int k) {
    return ratio(k * num, den);
}

ratio operator*(int k, ratio r) {
    return r*k;
}

int main() {
    ratio r1(2,-3), r2(3,4);
    r1 = r1 * r2;
    r1.show();
    r1.set(1,-6);
    r2.set(-3,14);
    r1 = r1 + r2;
    r1.show();
    r1 = 6 * r1;
    r1.show();
    r2 = r2 * 3;
    r2.show();
}
