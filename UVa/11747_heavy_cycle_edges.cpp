/**
 * Ertsiger
 * 08/11/2016
 * Time: 0.190
 */
#include <iostream>
#include <set>
#include <utility>
#include <stack>
#include <vector>
#include <map>

using namespace std;

int N, M;
set<int> A[1001];
map< pair<int, int>, int> E;

bool findCycle(int current, int pred, bool& adding, set<int>& visited, vector<int>& cycle)
{
    if (visited.find(current) != visited.end())
    {
        cycle.push_back(current);
        adding = true;
        return true;
    }
    else
    {
        visited.insert(current);

        for (auto it = A[current].begin(); it != A[current].end(); ++it)
        {
            if (*it != pred)
            {
                if (findCycle(*it, current, adding, visited, cycle))
                {
                    if (adding)
                    {
                        cycle.push_back(current);

                        if (cycle[0] == current)
                        {
                            adding = false;
                        }
                    }

                    return true;
                }
            }
        }

        visited.erase(current);
    }

    return false;
}

void findHeavyEdges(set<int>& heavyEdges)
{
    for (int i = 0; i < N; )
    {
        set<int> visited;
        vector<int> cycle;
        bool adding = false;
        findCycle(i, -1, adding, visited, cycle);

        if (cycle.empty())
        {
            ++i;
        }
        else
        {
            int maxA = -1;
            int maxB = -1;
            int maxEdgeCost = -1;

            for (int i = 0; i < cycle.size() - 1; ++i)
            {
                int a = cycle[i];
                int b = cycle[i + 1];
                int edgeCost = E[make_pair(a, b)];

                if (edgeCost > maxEdgeCost)
                {
                    maxA = a;
                    maxB = b;
                    maxEdgeCost = edgeCost;
                }
            }

            A[maxA].erase(maxB);
            A[maxB].erase(maxA);
            heavyEdges.insert(maxEdgeCost);
        }
    }
}

int main()
{
    while (cin >> N >> M)
    {
        if (N == 0 && M == 0) break;

        for (int i = 0; i < N; ++i)
        {
            A[i].clear();
        }

        int u, v, w;

        for (int i = 0; i < M; ++i)
        {
            cin >> u >> v >> w;

            A[u].insert(v);
            A[v].insert(u);

            E[make_pair(u, v)] = w;
            E[make_pair(v, u)] = w;
        }

        set<int> hEdges;
        findHeavyEdges(hEdges);

        if (hEdges.empty())
        {
            cout << "forest\n";
        }
        else
        {
            bool first = true;

            for (auto it = hEdges.begin(); it != hEdges.end(); ++it)
            {
                if (first)
                {
                    first = false;
                }
                else
                {
                    cout << " ";
                }

                cout << *it;
            }

            cout << '\n';
        }
    }

    return 0;
}

