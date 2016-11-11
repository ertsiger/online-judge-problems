/**
 * Ertsiger
 * 11/11/2016
 * Time: 0.010
 */
#include <iostream>
#include <vector>
#include <utility>

#define SZ size()
#define X first
#define Y second
#define MP make_pair

using namespace std;

typedef pair<pair<int, int>, int> P; // par de nodos + coste
int N;                             // numero de nodos
vector<P> v;                       // representacion aristas

int bellmanford(int N, vector<P>& v, int a, int b) {
    vector<int> d(N, 1000000000);
    d[a] = 0;
    for (int i = 1; i < N; i++)
    for (int j = 0; j < (int)v.SZ; j++)
    if (d[v[j].X.X] < 1000000000 && d[v[j].X.X] + v[j].Y < d[v[j].X.Y])
        d[v[j].X.Y] = d[v[j].X.X] + v[j].Y;
    for (int j = 0; j < (int)v.SZ; j++)
    if (d[v[j].X.X] < 1000000000 && d[v[j].X.X] + v[j].Y < d[v[j].X.Y])
        return -1000000000; // existe ciclo negativo
    return d[b];
}

int main()
{
    int c;
    cin >> c;

    while (c--)
    {
        int n, m;
        cin >> n >> m;

        int x, y, t;

        vector<P> v;

        for (int i = 0; i < m; ++i)
        {
            cin >> x >> y >> t;
            v.push_back(MP(MP(x, y), t));
        }

        int cost = bellmanford(n, v, 0, n - 1);

        if (cost == -1000000000)
        {
            cout << "possible\n";
        }
        else
        {
            cout << "not possible\n";
        }
    }

    return 0;
}

