/**
 * Author: Ertsiger
 * 29/05/2016
 * Time: 0.000
 */
#include <iostream>
#include <cassert>
#include <iomanip>
#include <cmath>

using namespace std;

double INF = 1e100;
double EPS = 1e-12;

struct PT {
    double x, y;
    PT() {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
    PT operator + (const PT &p)  const { return PT(x + p.x, y + p.y); }
    PT operator - (const PT &p)  const { return PT(x - p.x, y - p.y); }
    PT operator * (double c)     const { return PT(x*c, y*c); }
    PT operator / (double c)     const { return PT(x / c, y / c); }
};

double dot(PT p, PT q)     { return p.x*q.x + p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p - q, p - q); }
double cross(PT p, PT q)   { return p.x*q.y - p.y*q.x; }

// determine if lines from a to b and c to d are parallel or collinear
bool LinesParallel(PT a, PT b, PT c, PT d) {
    return fabs(cross(b - a, c - d)) < EPS;
}

bool LinesCollinear(PT a, PT b, PT c, PT d) {
    return LinesParallel(a, b, c, d)
        && fabs(cross(a - b, a - c)) < EPS
        && fabs(cross(c - d, c - a)) < EPS;
}

// compute intersection of line passing through a and b
// with line passing through c and d, assuming that unique
// intersection exists; for segment intersection, check if
// segments intersect first
PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
    b = b - a; d = c - d; c = c - a;
    assert(dot(b, b) > EPS && dot(d, d) > EPS);
    return a + b*cross(c, d) / cross(b, d);
}

int main()
{
    int N = 0;
    cin >> N;

    cout << "INTERSECTING LINES OUTPUT\n";

    for (int i = 0; i < N; ++i)
    {
        PT a, b, c, d;
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;

        if (LinesCollinear(a, b, c, d))
        {
            cout << "LINE\n";
        }
        else if (LinesParallel(a, b, c, d))
        {
            cout << "NONE\n";
        }
        else
        {
            PT r = ComputeLineIntersection(a, b, c, d);
            cout << "POINT " << fixed << setprecision(2) << r.x << " " << r.y << endl;
        }
    }

    cout << "END OF OUTPUT\n";

    return 0;
}
