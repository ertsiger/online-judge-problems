/**
 * Author: Ertsiger
 * 29/04/2016
 * Time: 0.000
 */
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <iomanip>

#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define SZ size()

using namespace std;

typedef vector<pair<double,pair<int,int> > > V;

int N, mf[10010]; // numero de nodos N <= 10010
V v;             // vector de aristas
                 // (coste, (nodo1, nodo2))

pair<double, double> points[10010];
                 
// vector< pair<long, int> > K[3001]; // kruskal tree

int set(int n) { // conjunto conexo de n
    if (mf[n] == n) return n;
    else mf[n] = set(mf[n]); return mf[n];
}

double kruskal() {
    int a, b;
    double sum = 0.0;
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++)
        mf[i] = i; // inicializar conjuntos conexos
    for (int i = 0; i < (int)v.SZ; i++) {
        a = set(v[i].Y.X), b = set(v[i].Y.Y);
        if (a != b) { // si conjuntos son diferentes
            mf[b] = a;  // unificar los conjuntos
            sum += v[i].X; // agregar coste de arista
            // K[v[i].Y.X].PB(MP(v[i].X, v[i].Y.Y));
            // K[v[i].Y.Y].PB(MP(v[i].X, v[i].Y.X));
        }
    }
    return sum;
}

double getDist(const pair<double, double>& p1, const pair<double, double>& p2)
{
    double diffx = p1.X - p2.X;
    double diffy = p1.Y - p2.Y;
    
    return sqrt(diffx * diffx + diffy * diffy);
}

int main()
{
    int cases = 0;
    cin >> cases;
    
    while (cases--)
    {
        v.clear();

        cin >> N;
    
        for (int i = 0; i < N; ++i)
        {
            cin >> points[i].X >> points[i].Y;
        }
    
        for (int i = 0; i < N - 1; ++i)
        {
            for (int j = i + 1; j < N; ++j)
            {
                double distance = getDist(points[i], points[j]);
                v.PB(MP(distance, MP(i, j)));
            }
        }
    
        cout << fixed << setprecision(2) << kruskal() << endl;
        
        if (cases > 0)
        {
            cout << endl;
        }
    }

    return 0;
}

