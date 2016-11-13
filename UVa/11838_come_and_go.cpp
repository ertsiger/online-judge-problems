/**
 * Ertsiger
 * 13/11/2016
 * Time: 0.060
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

#define MIN(a,b) ((a)<(b)?(a):(b))

using namespace std;

int index, ct;
vector<bool> I;
// L indica el indice del conjunto fuertemente conexo al que pertenece cada nodo
vector<int> D, L, S;

void tarjan(unsigned n, vector<vector<int> >& V) {
    D[n] = L[n] = index++;
    S.push_back(n);
    I[n] = true;
    for (unsigned i = 0; i < V[n].size(); ++i) {
        if (D[V[n][i]] < 0) {
            tarjan(V[n][i], V);
            L[n] = MIN(L[n], L[V[n][i]]);
        }
        else if (I[V[n][i]])
            L[n] = MIN(L[n], D[V[n][i]]);
    }
    if (D[n] == L[n]) {
        ++ct;
        // todos los nodos eliminados de S pertenecen al mismo scc
        while (S[S.size() - 1] != n) {
            I[S.back()] = false;
            S.pop_back();
        }
        I[n] = false;
        S.pop_back();
    }
}

void scc(vector<vector<int> >& V) {
    index = ct = 0;
    I = vector<bool>(V.size(), false);
    D = vector<int>(V.size(), -1);
    L = vector<int>(V.size());
    S.clear();
    for (unsigned n = 0; n < V.size(); ++n)
    if (D[n] < 0)
        tarjan(n, V);
    // ct = numero total de scc
}

int main()
{
    int n, m;

    while (cin >> n >> m)
    {
        if (n == 0 && m == 0) break;

        vector<vector<int> > V; // listas de adyacencia (grafo dirigido)

        for (int i = 0; i < n; ++i)
        {
            V.push_back(vector<int>());
        }

        int v, w, p;

        for (int i = 0; i < m; ++i)
        {
            cin >> v >> w >> p;
            --v;
            --w;

            V[v].push_back(w);

            if (p == 2)
            {
                V[w].push_back(v);
            }
        }

        scc(V);

        if (ct == 1) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}

