#include <iostream>
#include <sstream>

using namespace std;

class ratio
{
    private:
        int num, den;
        void reduce();
        //int numOfDig(int n);
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

inline int max(int n1, int n2) {
    if (n1 > n2)
        return n1;
    return n2;
}

int numOfDig(int n) {
    if (n < 0)
        n = (-n);
    int r = 0;
    while (n > 0) {
        n /= 10;
        ++r;
    }
    return r;
}

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
/*
void ratio::show() {
    int num2 = num;
    int n = max(numOfDig(num), numOfDig(den));
    string s = "";
    if (num < 0) {
        s += "- ";
        num2 = (-num2);
    }
    for (int i = 0; i < n; ++i)
        s += "#";
    cout << endl << num2 << endl << s << endl << den << endl;
}
*/

void ratio::show() {
    int num2 = num;
    int den2 = den;
    int dignum = numOfDig(num2);
    int dennum = numOfDig(den2);
    int n = max(dignum, dennum);
    stringstream s1 , s2 , s3;
    if (num < 0) {
        num2 = (-num2);
        s2 << "- ";
        s1 << "  ";
        s3 << "  ";
    }
    int n1 = (n - dignum) / 2;
    for (int i = 0; i < n1; ++i)
        s1 << " ";
    n1 = (n - dennum) / 2;
    for (int i = 0; i < n1; ++i)
        s3 << " ";
    for (int i = 0; i < n; ++i)
        s2 << "#";
    s1 << num2;
    s3 << den;
    cout << endl << s1.str() << endl << s2.str() << endl << s3.str() << endl;
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
    ratio r1(234511,32), r2(3,1);
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
