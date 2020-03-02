#include <bits/stdc++.h>
#define EPS 0.000001

using namespace std;

struct point {
    double x,y;
    point* p;
};

inline double vectorProduct(point& a, point& b) {
    return a.x*b.y - a.y*b.x;
}

inline bool isPositive(double a) {
    if (a > 0)
        return true;
    return false;
}

int main() {
    fstream in("data.txt", fstream::in);
    point *base, *curr, *next;
    base = new point;
    curr = base;
    curr -> p = base;
    double nextNum;
    in >> nextNum;
    while(1) {
        curr -> x = nextNum;
        in >> curr -> y;
        in >> nextNum;
        if (in.eof())
            break;
        next = new point;
        next -> p = base;
        curr -> p = next;
        curr = next;
    }
    in.close();
    curr = base;
    bool flag = true;
    double sum = 0;
    while (curr->p->p != base) {
        point a;
        point b;
        point c;
        a.x = curr->p->x - curr->x;
        a.y = curr->p->y - curr->y;
        next = curr->p;
        b.x = next->p->x - next->x;
        b.y = next->p->y - next->y;
        complex<double> bc(b.x, b.y);
        c.x = next->p->p->x - next->p->x;
        c.y = next->p->p->y - next->p->y;
        complex<double> cc(c.x, c.y);
        double d2 = arg(cc) - arg(bc);
        if (d2 < 0)
            d2 += 2*M_PI;
        if (isPositive(vectorProduct(a,b)) != isPositive(vectorProduct(b,c))) {
            flag = false;
            break;
        }
        sum += d2;
        curr = next; 
    }
    point a;
    point b;
    curr = curr->p;
    a.x = curr->p->x - curr->x;
    a.y = curr->p->y - curr->y;
    b.x = curr->p->p->x - curr->p->x;
    b.y = curr->p->p->y - curr->p->y;
    complex<double> end1(a.x, a.y);
    complex<double> end2(b.x, b.y);
    double da = arg(end2) - arg(end1);
    if (da < 0)
        da += 2*M_PI;
    sum += da;
    curr = base;
    a.x = curr->p->x - curr->x;
    a.y = curr->p->y - curr->y;
    b.x = curr->p->p->x - curr->p->x;
    b.y = curr->p->p->y - curr->p->y;
    complex<double> beg1(a.x, a.y);
    complex<double> beg2(b.x, b.y);
    da = arg(beg2) - arg(beg1);
    if (da < 0)
        da += 2*M_PI;
    sum += da;
    do {
        next = curr -> p;
        delete curr;
        curr = next;
    } while(curr != base);
    if (abs(sum - 2*M_PI) > EPS) {
        cout << "\nМногоугольник может иметь пересечения с самим с собой.";
        flag = false;
    }
    else 
        cout << "\nМногоугольник не имеет пересечения сам с собой.";
    if (flag)
        cout << "\nВыпуклый\n";
    else
        cout << "\nНе является выпуклым\n";
    cout << "Суммарный угол: " << sum/M_PI << "*PI" << endl;
}
