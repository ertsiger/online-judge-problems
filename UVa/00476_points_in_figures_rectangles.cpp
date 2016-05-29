/**
 * Author: Ertsiger
 * 29/05/2016
 * Time: 0.030
 * Note: not really necessary this amount of code, but used for the upcoming
 * problems (477, 478) :P
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

int main()
{
    char type = ' ';

    vector<vector<PT>> rectangles;

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

            vector<PT> rectangle(4);
            rectangle[0] = PT(ulx, uly);
            rectangle[1] = PT(ulx, lry);
            rectangle[2] = PT(lrx, lry);
            rectangle[3] = PT(lrx, uly);

            rectangles.push_back(rectangle);
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

        PT pp(px, py);

        bool iscontained = false;

        for (int i = 0; i < rectangles.size(); ++i)
        {
            if (PointInPolygon(rectangles[i], pp))
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

