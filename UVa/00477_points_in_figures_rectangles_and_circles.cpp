/**
 * Author: Ertsiger
 * 29/05/2016
 * Time: 0.030
 */
#include <iostream>
#include <cassert>
#include <iomanip>
#include <cmath>
#include <vector>

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

bool PointInPolygon(const vector<PT> &p, PT q) {
    bool c = 0;
    for (int i = 0; i < p.size(); i++){
        int j = (i + 1) % p.size();
        if ((p[i].y <= q.y && q.y < p[j].y ||
            p[j].y <= q.y && q.y < p[i].y) &&
            q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
            c = !c;
    }
    return c;
}

struct Figure
{
    virtual bool containsPoint(double x, double y) = 0;
};

struct Rectangle : public Figure
{
    vector<PT> p;

    Rectangle(double ulx, double uly, double lrx, double lry)
    {
        p.push_back(PT(ulx, uly));
        p.push_back(PT(ulx, lry));
        p.push_back(PT(lrx, lry));
        p.push_back(PT(lrx, uly));
    }

    virtual bool containsPoint(double x, double y)
    {
        return PointInPolygon(p, PT(x, y));
    }
};

struct Circle : public Figure
{
    double _radius;
    PT center;

    Circle(double cx, double cy, double radius)
        : _radius(radius)
    {
        center.x = cx;
        center.y = cy;
    }

    virtual bool containsPoint(double x, double y)
    {
        if (sqrt(dist2(PT(x, y), center)) <= _radius)
        {
            return true;
        }

        return false;
    }
};

int main()
{
    char type = ' ';

    vector<Figure*> figures;

    while (cin >> type)
    {
        if (type == '*')
        {
            break;
        }
        else if (type == 'r')
        {
            double ulx, uly, lrx, lry;
            cin >> ulx >> uly >> lrx >> lry;

            Figure* f = new Rectangle(ulx, uly, lrx, lry);
            figures.push_back(f);
        }
        else if (type == 'c')
        {
            double cx, cy, r;
            cin >> cx >> cy >> r;

            Figure* f = new Circle(cx, cy, r);
            figures.push_back(f);
        }
    }

    double px, py;
    int id = 1;
    while (cin >> px >> py)
    {
        if (px == 9999.9 && py == 9999.9)
        {
            break;
        }

        bool iscontained = false;

        for (int i = 0; i < figures.size(); ++i)
        {
            if (figures[i]->containsPoint(px, py))
            {
                cout << "Point " << id << " is contained in figure " << (i + 1) << endl;
                iscontained = true;
            }
        }

        if (!iscontained)
        {
            cout << "Point " << id << " is not contained in any figure" << endl;
        }

        ++id;
    }

    return 0;
}

