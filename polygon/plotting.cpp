#include <bits/stdc++.h>

using namespace std;

struct point {
    double x,y;
    point* p;
};

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
    fstream out("plot.dat", fstream::out);
    curr = base;
    do {
        point a;
        a.x = curr->p->x - curr->x;
        a.y = curr->p->y - curr->y;
        next = curr->p;
        out << curr->x << ' ' << curr->y << ' ' << a.x << ' ' <<a.y << endl;
        curr = next; 
    } while (curr != base);
    curr = base;
    do {
        next = curr -> p;
        delete curr;
        curr = next;
    } while(curr != base);
}
