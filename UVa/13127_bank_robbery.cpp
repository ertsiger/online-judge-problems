/**
 * Ertsiger
 * 15/11/2016
 * Time: 0.240
 */
#include <iostream>
#include <vector>
#include <set>
#include <utility>

#define SZ size()
#define X first
#define Y second
#define MP make_pair
#define PB push_back

using namespace std;

typedef pair<pair<int,int>,int> P; // par de nodos + coste

int N;                  // numero de nodos

int bellmanford(int a, int b, vector<int>& d, const vector<P>& v) {
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
    int n, m, b, p;

    while (cin >> n >> m >> b >> p)
    {
        N = n + 2;

		vector<P> V; // edges

        int u, v, t;

        for (int i = 0; i < m; ++i)
        {
            cin >> u >> v >> t;
            V.PB(MP(MP(u, v), t));
            V.PB(MP(MP(v, u), t));
        }

        int bankOrigin = n;
        int policeOrigin = n + 1;

        vector<int> banks(b);

        for (int i = 0; i < b; ++i)
        {
            cin >> banks[i];
			V.PB(MP(MP(banks[i], bankOrigin), 0));
        }

        vector<int> police(p);

        for (int i = 0; i < p; ++i)
        {
            cin >> police[i];
            V.PB(MP(MP(policeOrigin, police[i]), 0));
        }

        vector<int> z(N, 1000000000);
        bellmanford(policeOrigin, bankOrigin, z, V);

        int maxDist = -1;

        for (int i = 0; i < banks.size(); ++i)
        {
            if (maxDist < z[banks[i]])
            {
                maxDist = z[banks[i]];
            }
        }

        set<int> finalBanks;

        for (int i = 0; i < banks.size(); ++i)
        {
            if (maxDist == z[banks[i]])
            {
                finalBanks.insert(banks[i]);
            }
        }

        cout << finalBanks.size() << " ";

        if (maxDist == 1000000000)
        {
            cout << '*' << endl;
        }
        else
        {
            cout << maxDist << endl;   
        }

        for (auto it = finalBanks.begin(); it != finalBanks.end(); ++it)
        {
            if (it != finalBanks.begin())
            {
                cout << " ";
            }

            cout << *it;
        }

        cout << endl;
    }

    return 0;
}


