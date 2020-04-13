#include <iostream>
#include <cmath>
#include <stack>
#include <fstream>

#define EPSILON 0.01

using namespace std;

struct point { double x, y; };

struct line { point p1, p2; };

class polygon {
    private:
        point *A;
        int N;
    public:
        polygon();
        polygon(int n);
        polygon(const polygon&);
        ~polygon();
        polygon& operator=(const polygon&);
        point& operator[] (int);
        friend ostream& operator<< (ostream&, const polygon&);
        polygon operator*(const polygon&);
        bool inside(point a);
};

point operator-(const point &p1, const point &p2) {
    point res;
    res.x = p1.x - p2.x;
    res.y = p1.y - p2.y;
    return res;
}


point operator+(const point &p1, const point &p2) {
    point res;
    res.x = p1.x + p2.x;
    res.y = p1.y + p2.y;
    return res;
}

point operator/(const point &p, const double &c) {
    point res;
    res.x = p.x / c;
    res.y = p.y / c;
    return res;
}

point operator*(const point &p, const double &c) {
    point res;
    res.x = p.x * c;
    res.y = p.y * c;
    return res;
}
inline double vectorProduct(const point& a, const point& b) {
    return a.x*b.y - a.y*b.x;
}

inline double scalarProduct(const point& a, const point& b) {
    return a.x*b.x + a.y*b.y;
}

inline double abs(const point &p) {
    return (sqrt(p.x*p.x+p.y*p.y));
}

inline double arg(const point &p) {
    return atan2(p.y, p.x);
}

inline bool isNegative(double a) {
    if (a < 0)
        return true;
    return false;
}

inline double sgn(double a) {
    if (a > 0)
        return 1;
    else if (a < 0)
        return -1;
    else
        return 0;
}

point cross(line l1, line l2) {    
    point a = l1.p1;
    point b = l1.p2;
    point c = l2.p1;
    point d = l2.p2;
    point ab = b - a;
    point ac = c - a;
    point ad = d - a;
    point cd = d - c;
    /*
    double sina = abs(vectorProduct(ab,ac)/abs(ab)/abs(ac));
    double sinb = abs(vectorProduct(ab,ad)/abs(ab)/abs(ad));
    double cc1 = abs(ac) * sina;
    double dd1 = abs(ad) * sinb;
    */
    double cc1 = abs(vectorProduct(ab,ac)/abs(ab));
    double dd1 = abs(vectorProduct(ab,ad)/abs(ab));
   /* double k = cc1 / dd1; */
   /* double c2 = dd1 / cc1 + 1; */
   /* point co = cd / c2; */
    point co = cd * cc1 / (dd1 + cc1);
    point ao = ac + co;
    point o = a + ao;
    return o;
}

inline void swap(line& l1, line& l2) {
    line t = l2;
    l2 = l1;
    l1 = t;
}

bool isCrossed(line l1, line l2) {
    point a = l1.p1;
    point b = l1.p2;
    point c = l2.p1;
    point d = l2.p2;
    point v1 = b - a;
    point v2 = c - a;
    point v3 = d - a;
    bool res1 = (isNegative(sgn(vectorProduct(v1, v2)) * sgn(vectorProduct(v1, v3))));
    swap(l1, l2);
    a = l1.p1;
    b = l1.p2;
    c = l2.p1;
    d = l2.p2;
    v1 = b - a;
    v2 = c - a;
    v3 = d - a;
    bool res2 = (isNegative(sgn(vectorProduct(v1, v2)) * sgn(vectorProduct(v1, v3))));
    return (res1 && res2);
}


polygon::polygon() {
    A = NULL;
    N = 0;
}

polygon::polygon(int n) {
    N = n;
    A = new point[N];
}

polygon::polygon(const polygon& p) {
    N = p.N;
    A = new point[N];
    for (int i = 0; i < N; ++i) {
        A[i] = p.A[i];
    }
}

polygon::~polygon() {
    delete[] A;
}

polygon& polygon::operator=(const polygon& p) {
    N = p.N;
    for (int i = 0; i < N; ++i) {
        A[i] = p.A[i];
    }
    return *this;
}

point& polygon::operator[] (int n) {
    return A[n];   
}

ostream& operator<< (ostream& s, const polygon& p) {
    for (int i = 0; i < p.N; ++i) {
        s<< p.A[i].x << ' ' << p.A[i].y << endl;
    }
    return s;
}
/*
ostream& operator<< (ostream& s, const point& p) {
    cout << p.x << ' ' << p.y << endl;
    return s;
}

ostream& operator<< (ostream& s, const line& l) {
    cout << l.p1 << l.p2;
    return s;
}
*/
point centerOfMass(point* A, int size) {
    point res;
    res.x = 0;
    res.y = 0;
    for (int i = 0; i < size; ++i) {
        res = res + (A[i]/(double)size);
    }
    return res;
}

inline void swap(point& a, point& b) {
    point t = a;
    a = b;
    b = t;
}

void sortPoints(point* A, int size) {
    point cm = centerOfMass(A, size);
    for (int i = 0; i < size; ++i) {
        A[i] = A[i] - cm;
    }
    for (int i = 0; i < size - 1; ++i)
        for (int j = i + 1; j < size; ++j)
            if (arg(A[i]) > arg(A[j]))
                swap(A[i], A[j]);
    for (int i = 0; i < size; ++i)
        A[i] = A[i] + cm;
}

bool polygon::inside(point a) {
    point* Ac = new point[N];
    for (int i = 0; i < N; ++i) {
        Ac[i] = A[i];
    }
    for (int i = 0; i < N; ++i) {
        Ac[i] = Ac[i] - a;
    }
    double Phi = 0;
    for (int i = 1; i < N; ++i ) {
        double y = vectorProduct(Ac[i], Ac[i - 1]);
/*        cout << y << endl; */
        double x = scalarProduct(Ac[i], Ac[i - 1]);
        double dp = atan2(y, x);
        Phi += dp;
    }
    double y = vectorProduct(Ac[0], Ac[N - 1]);
/*    cout << y << endl; */
    double x = scalarProduct(Ac[0], Ac[N - 1]);
    double dp = atan2(y, x);
    Phi += dp;
    Phi = abs(Phi);
/*   cout << "Phi = " << Phi << endl; */
    delete[] Ac;
    if (abs(Phi - 2*M_PI) < EPSILON) {
/*        cout << "OK!" << endl; */
        return true;
    }
    return false;

}

polygon polygon::operator*(const polygon& p) {
    stack<point> s;
    line* L1 = new line[N];
    for (int i = 1; i < N; ++i) {
        L1[i - 1].p1 = A[i - 1];
        L1[i - 1].p2 = A[i];
    }
    L1[N - 1].p1 = A[N - 1];
    L1[N - 1].p2 = A[0];
    line* L2 = new line[p.N];
    for (int i = 1; i < p.N; ++i) {
        L2[i - 1].p1 = p.A[i - 1];
        L2[i - 1].p2 = p.A[i];
    }
    L2[p.N - 1].p1 = p.A[p.N - 1];
    L2[p.N - 1].p2 = p.A[0];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < p.N; ++j) {
            if (!(isCrossed(L1[i], L2[j])))
                continue;
            s.push(cross(L1[i], L2[j]));
            /* cout << "Crossed with "  << L1[i]  << L2[j] << endl; */
        }
    }
    delete[] L1;
    delete[] L2;
    for (int i = 0; i < p.N; ++i) {
        if (inside(p.A[i]))
            s.push(p.A[i]);        
    }
    for (int i = 0; i < N; ++i) {
        if (((polygon&)p).inside(A[i]))
            s.push(A[i]);        
    }
    int Psize = s.size();
    point* P = new point[Psize];
    for (int i = Psize - 1; i >= 0; --i) {
        P[i] = s.top();
        s.pop();
    }
    sortPoints(P, Psize);
    polygon res(Psize);
    for (int i = 0; i < Psize; ++i)
        res[i] = P[i];
    delete[] P;
    return res;
}


int main() {
    fstream in1("in1.txt", fstream::in);
    fstream in2("in2.txt", fstream::in);
    fstream out("out.txt", fstream::out);
    int N1;
    int N2;
    in1 >> N1;
    in2 >> N2;
    polygon p1(N1);
    for (int i = 0; i < N1; ++i)
        in1 >> p1[i].x >> p1[i].y;
    polygon p2(N2);
    for (int i = 0; i < N2; ++i)
        in2 >> p2[i].x >> p2[i].y;
    polygon p3 = p2 * p1;
    out << p3;
}
