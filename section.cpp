#include <iostream>
#include <fstream>
#include <cmath>

#define EPS 0.01

using namespace std;
fstream out;

inline double sgn(double a) {
    if (a > 0)
        return 1;
    else if (a < 0)
        return -1;
    else
        return 0;
}

inline bool isNegative(double a) {
    if (a < 0)
        return true;
    return false;
}

class point;

class vector2d {
    private:
        double x, y;
    public:
        vector2d();
        vector2d(double xx, double yy);
        vector2d(const point&);
        void set(double xx, double yy);
        void set(const point&);
        double getX();
        double getY();
        vector2d operator-(const vector2d&);
        vector2d operator+(const vector2d&);
        vector2d operator*(const double);
        vector2d operator/(const double);
        vector2d& operator=(const vector2d&);
        double vectorProduct(const vector2d&);
        double scalarProduct(const vector2d&);
        double abs();
        double arg();
        point toPoint();

};

void vector2d::set(double xx, double yy) { x = xx; y = yy; }

vector2d::vector2d(double xx, double yy) { set(xx, yy); }

vector2d::vector2d() { set(0., 0.); }

double vector2d::getX() { return x; }

double vector2d::getY() { return y; }

vector2d vector2d::operator-(const vector2d& v) {
    vector2d res(x - v.x, y - v.y);
    return res;
}

vector2d vector2d::operator+(const vector2d& v) {
    vector2d res(x + v.x, y + v.y);
    return res;
}

vector2d vector2d::operator*(const double c) {
    vector2d res(x * c, y * c);
    return res;
}

vector2d vector2d::operator/(const double c) {
    vector2d res(x / c, y / c);
    return res;
}

vector2d& vector2d::operator=(const vector2d& v) {
    x = v.x; y = v.y;
    return *this;
}

double vector2d::vectorProduct(const vector2d& v) {
    return x * v.y - y * v.x;
}

double vector2d::scalarProduct(const vector2d& v) {
    return x * v.x + y * v.y;
}

double vector2d::abs() {
    return sqrt(x*x + y*y);
}

double vector2d::arg() {
    return atan2(y, x);
}

class nothing {
    public:
        nothing() {}
        virtual void show() { cout << "Nothing." << endl; }
        virtual void save() {}
        virtual ~nothing() { /* cout << "Bye nothing!" << endl; */ }
};

class section;

class point : public nothing {
    protected:
        double x, y;
    public:
        point(double xx, double yy);
        void show();
        void save();
        virtual ~point() { /* cout << "Bye point!" << endl; */ }
        point& operator=(const point&);
        bool operator==(const point&);
        friend void vector2d::set(const point&);
        friend bool isCrossed(section l1, section l2);
        friend point cross(section l1, section l2);

};

class section : public point {
    protected:
        double x1, y1;
    public:
        section(double xx, double yy, double xx1, double yy1);
        void show();
        void save();
        nothing* operator*(section);
        section& operator=(const section&);
        virtual ~section() { /* cout << "Bye section!" << endl; */ }
        friend bool isCrossed(section l1, section l2);
        friend point cross(section l1, section l2);
};

inline void swap(section& l1, section& l2) {
    section t = l2;
    l2 = l1;
    l1 = t;
}

bool isCrossed(section l1, section l2) {
    point& p1 = l1;
    point& p2 = l2;
    vector2d a(p1.x, p1.y);
    vector2d b(l1.x1, l2.y1);
    vector2d c(p2.x, p2.y);
    vector2d d(l2.x1, l2.y1);
    vector2d v1 = b - a;
    vector2d v2 = c - a;
    vector2d v3 = d - a;
    bool res1 = (isNegative(sgn(v1.vectorProduct(v2)) * sgn(v1.vectorProduct(v3))));
    swap(l1, l2);
    p1 = l1;
    p2 = l2;
    a = vector2d(p1.x, p1.y);
    b = vector2d(l1.x1, l2.y1);
    c = vector2d(p2.x, p2.y);
    d = vector2d(l2.x1, l2.y1);
    v1 = b - a;
    v2 = c - a;
    v3 = d - a;
    bool res2 = (isNegative(sgn(v1.vectorProduct(v2)) * sgn(v1.vectorProduct(v3))));
    return (res1 && res2);

}

void vector2d::set(const point& p) { set(p.x, p.y); }

vector2d::vector2d(const point& p) { set(p); }

section& section::operator=(const section& s) {
    point& p = *this;
    const point& sp = s;
    p = sp;
    x1 = s.x1;
    y1 = s.y1;
    return *this;
}

point vector2d::toPoint() {
    point res(x, y);
    return res;
}

point::point(double xx, double yy) {
    x = xx;
    y = yy;
}

void point::show() {
    cout << "Point (" << x << ", " << y << ")" << endl;
}

void point::save() { 
    out << "Point (" << x << ", " << y << ")" << endl;
}

point& point::operator=(const point& p) {
    x = p.x;
    y = p.y;
    return *this;
}

bool point::operator==(const point& p) {
    bool res = false;
    if ((x == p.x) && (y == p.y))
        res = true;
    return res;
}



section::section(double xx, double yy, double xx1, double yy1) : point(xx, yy), x1(xx1), y1(yy1) {
    
}

void section::show() {
    cout << "Section (" << x << ", " << y << ") -- (" << x1 << ", " << y1 << ")" << endl;
}

void section::save() { 
    out << "Section (" << x << ", " << y << ") -- (" << x1 << ", " << y1 << ")" << endl;
}

point cross(section l1, section l2) {
    point& p1 = l1;
    point& p2 = l2;
    vector2d a(p1.x, p1.y);
    vector2d b(l1.x1, l2.y1);
    vector2d c(p2.x, p2.y);
    vector2d d(l2.x1, l2.y1);
    vector2d ab = b - a;
    vector2d ac = c - a;
    vector2d ad = d - a;
    vector2d cd = d - c;
    double cc1 = abs(ab.vectorProduct(ac)/(ab.abs()));
    double dd1 = abs(ab.vectorProduct(ad) / ab.abs());
    vector2d co = cd * cc1 / (dd1 + cc1);
    vector2d ao = ac + co;
    vector2d o = a + ao;
    return o.toPoint();

}

bool isColine(vector2d a, vector2d b, vector2d a1, vector2d b1) {
	vector2d ab = b - a;
	vector2d aa1 = a1 - a;
	vector2d ab1 = b1 - a;
	double phi1 = ab.arg();
	double phi2 = phi1 + M_PI;
	if (phi2 > M_PI)
		phi2 -= 2 * M_PI;
	if (!((abs(aa1.arg() - phi1) < EPS) || (abs(aa1.arg() - phi2) < EPS)))
		return false;
	if (!((abs(ab1.arg() - phi1) < EPS) || (abs(ab1.arg() - phi2) < EPS)))
		return false;
	return true;
}

nothing* crossColineSection(vector2d a, vector2d b, vector2d a1, vector2d b1) {
	vector2d ab = b - a;
	vector2d aa1 = a1 - a;
	vector2d ab1 = b1 - a;
	/*
	double phi1 = ab.arg();
	double phi2 = phi1 + M_PI;
	if (phi2 > M_PI)
		phi2 -= 2 * M_PI;
	*/
	vector2d e = ab / ab.abs();
	double sa = 0;
	double sb = e.scalarProduct(ab);
	double sa1 = e.scalarProduct(aa1);
	double sb1 = e.scalarProduct(ab1);

}

nothing* section::operator*(section s) {
    int res = 0;
    /* 
        res == 0 -> nothing
        res == 1 -> point
        res == 2 -> section
    */
    point a(x, y);
    point b(x1, y1);
    point a1(s.x, s.y);
    point b1(s.x1, s.y1);
    bool coline = isColine(vector2d(x, y), vector2d(x1, y1) , vector2d(s.x, s.y), vector2d(s.x1, s.y1));
    if ( coline ) {

    }
    else if (isCrossed(*this, s))
        res = 1;
    if (res == 0)
        return new nothing;
    if (res == 2)
        return new section(x, y, x1, y1);
    point* p = new point(0., 0.);
    *p = cross(*this, s);
    return p;
}

int main() {
    out = fstream("out.txt", fstream::out);
    nothing *p;
    section s1(3., 1., 7., 7.), s2(4., 2.5, 5., 4.);
    p = s1 * s2;
    p -> show();
    p -> save();
    delete p;
    out.close();
}
