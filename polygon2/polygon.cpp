#include <iostream>

using namespace std;

struct point { double x, y; };

struct line { double x1, x2, y1, y2; };

class polygon {
    private:
        point *A;
        int N;
        point cross(line l1, line l2);
    public:
        polygon();
        polygon(int n);
        polygon(const polygon&);
        ~polygon();
        polygon& operator=(const polygon&);
        point& operator[] (int);
        friend ostream& operator<< (ostream&, const polygon&);
        polygon operator*(const polygon&);
};

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
    int n = p.N;
    polygon* res = new polygon(n);
    for (int i = 0; i < n; ++i) {
        res -> A[i] = p.A[i];
    }
    return *res;
}

point& polygon::operator[] (int n) {
    return A[n];   
}

ostream& operator<< (ostream& s, const polygon& p) {
    //s << endl;
    for (int i = 0; i < p.N; ++i) {
        s<< p.A[i].x << ' ' << p.A[i].y << endl;
    }
    return s;
}

polygon polygon::operator*(const polygon&) {

}

point polygon::cross(line l1, line l2) {
    point res;
    double px = l1.x2 - l1.x1;
    double py = l1.y2 - l1.y1;
    double rx = l2.x2 - l2.x1;
    double ry = l2.y2 - l2.y1;

}

int main() {
    polygon p(4);
    p[0].x = 0;
    p[0].y = 0;
    p[1].x = 0;
    p[1].y = 1;
    p[2].x = 1;
    p[2].y = 1;
    p[3].x = 1;
    p[3].y = 0;
    cout << p;
}
