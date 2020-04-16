#include <iostream>

using namespace std;

class array
{
    private: // или protected:
        double *A;
        int N;
        // прочие скрытые переменные и функции
    public:
        array();
        array(int n);
        array(const array&);
        ~array();
        array& operator=(const array&);
        double& operator[] (int);
};

class polynomial : public array
{
    private:
        int N;
    public:
        polynomial();
        polynomial(int n);
        polynomial(const polynomial&);
        ~polynomial();
        polynomial operator*(const polynomial&);
        polynomial operator+(const polynomial&);
        polynomial& operator=(const polynomial&);
        double& operator[] (int);
        friend ostream& operator<<(ostream&, const polynomial&);
};

array::array() {
    N = 0;
    A = NULL;
}

array::array(int n) {
    N = n;
    A = new double[N];
}

array::array(const array& a) {
    N = a.N;
    A = new double[N];
    for (int i = 0; i < N; ++i) {
        A[i] = a.A[i];
    }
}

array::~array() {
    if (N != 0)
        delete[] A;
    N = 0;
    A = NULL;
}

array& array::operator=(const array& a) {
    if (&a == this)
        return *this;
    if (A != NULL)
        delete[] A;
    N = a.N;
    A = new double[N];
    for (int i = 0; i < N; ++i) {
        A[i] = a.A[i];
    }
    return *this;
}

double& array::operator[] (int n) {
    return A[n];
}

polynomial::polynomial() : array() {
    N = -1;
}

polynomial::polynomial(int n) : array(n + 1) {
    N = n;
}

polynomial::polynomial(const polynomial& p) : array() {
    const array& src = p;
    array& dst = *this;
    dst = src;
    N = p.N;
}

double& polynomial::operator[] (int n) {
    array& a = *this;
    return a[n];
}

polynomial::~polynomial() {

}

polynomial polynomial::operator*(const polynomial& pp) {
    polynomial& p = (polynomial&) pp;
    int N1 = N;
    int N2 = p.N;
    int N3 = N + p.N;
    polynomial res(N3);
    for (int i = 0; i <= N3; ++i)
        res[i] = 0;
    for (int i = 0; i <= N1; ++i) {
        for (int j = 0; j <= N2; ++j) {
            res[i + j] = res[i + j] + (*this)[i] * p[j];
        }
    }
    return res;
}
polynomial polynomial::operator+(const polynomial& pp) {
    polynomial& p = (polynomial&) pp;
    int N1 = N;
    int N2 = p.N;
    int N3 = max(N1, N2);
    int N4 = min(N1, N2);
    polynomial res(N3);
    for (int i = 0; i <= N3; ++i) {
        if (i <= N4)
            res[i] = p[i] + (*this)[i];
        else {
            if (N1 < N2)
                res[i] = p[i];
            else
                res[i] = (*this)[i];
        }
    }
    return res;
}
polynomial& polynomial::operator=(const polynomial& p){
    if (&p == this)
        return *this;
    const array& src = p;
    array& dst = *this;
    dst = src;
    N = p.N;
    return *this;
}

ostream& operator<<(ostream& s, const polynomial& pp) {
    polynomial& p = (polynomial&)pp;
    for (int i = p.N; i >= 0; --i) {
        if ((i != p.N) && (p[i] > 0))
            s << " + ";
        if (p[i] < 0)
            s << " - ";
        if ((p[i] != 0) && (i != 0) && (abs(p[i]) != 1) && (i != 1))
            s << abs(p[i]) << "x^" << i;
        if ((p[i] != 0) && (i != 0) && (abs(p[i]) != 1) && (i == 1))
            s << abs(p[i]) << "x";
        if ((p[i] != 0) && (i != 0) && (abs(p[i]) == 1) && (i != 1))
            s << "x^" << i;
        if ((p[i] != 0) && (i != 0) && (abs(p[i]) == 1) && (i == 1))
            s << "x";
        if ((p[i] != 0) && (i == 0))
            s << abs(p[i]);
    }
    return s;
}


int main() {
    /* Case 1 */
    polynomial p1(0);
    polynomial p2(2);
    p1[0] = 1;
    p2[0] = 0; p2[1] = 2; p2[2] = 3;
    polynomial p3;
    p3 = p1 * p2;
    polynomial p4 = p1 + p2;
    cout << endl << endl << "***Case 1***" << endl << "Polynomial 1> " << p1 << endl;
    cout  << "Polynomial 2> " << p2 << endl << "Product> " << p3 << endl; 
    cout << "Sum> " << p4 << endl;

    /* Case 2 */
  
    p1 = polynomial(1);
    /* p2 = polynomial(2); */
    p1[0] = -1; p1[1] = 1;
    p2[0] = 2; p2[1] = 0; p2[2] = 3;
    p3 = p1 * p2;
    p4 = p1 + p2;
    cout << endl << endl << "***Case 2***" << endl << "Polynomial 1> " << p1 << endl;
    cout  << "Polynomial 2> " << p2 << endl << "Product> " << p3 << endl; 
    cout << "Sum> " << p4 << endl;

    /* Case 3 */
    p1 = polynomial(4);
    /* p2 = polynomial(2); */
    p1[0] = 1; p1[1] = -1; p1[2] = 0; p1[3] = 0; p1[4] = 1;
    p2[0] = -1; p2[1] = 2; p2[2] = 3;
    p3 = p1 * p2;
    p4 = p1 + p2;
    cout << endl << endl << "***Case 3***" << endl << "Polynomial 1> " << p1 << endl;
    cout  << "Polynomial 2> " << p2 << endl << "Product> " << p3 << endl; 
    cout << "Sum> " << p4 << endl;
}
