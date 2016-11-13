/**
 * Ertsiger
 * 13/11/2016
 * Time: 0.000
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

const int INF = 1000000000;

struct MaxFlow {
    int N;
    VVI cap, flow;
    VI dad, Q;

    MaxFlow(int N) :
        N(N), cap(N, VI(N)), flow(N, VI(N)), dad(N), Q(N) {}

    void AddEdge(int from, int to, int cap) {
        this->cap[from][to] += cap;
    }

    void SetEdge(int from, int to, int cap) {
        this->cap[from][to] = cap;
    }

    int BlockingFlow(int s, int t) {
        fill(dad.begin(), dad.end(), -1);
        dad[s] = -2;

        int head = 0, tail = 0;
        Q[tail++] = s;
        while (head < tail) {
            int x = Q[head++];
            for (int i = 0; i < N; i++) {
                if (dad[i] == -1 && cap[x][i] - flow[x][i] > 0) {
                    dad[i] = x;
                    Q[tail++] = i;
                }
            }
        }

        if (dad[t] == -1) return 0;

        int totflow = 0;
        for (int i = 0; i < N; i++) {
            if (dad[i] == -1) continue;
            int amt = cap[i][t] - flow[i][t];
            for (int j = i; amt && j != s; j = dad[j])
                amt = min(amt, cap[dad[j]][j] - flow[dad[j]][j]);
            if (amt == 0) continue;
            flow[i][t] += amt;
            flow[t][i] -= amt;
            for (int j = i; j != s; j = dad[j]) {
                flow[dad[j]][j] += amt;
                flow[j][dad[j]] -= amt;
            }
            totflow += amt;
        }

        return totflow;
    }

    int GetMaxFlow(int source, int sink) {
        fill(Q.begin(), Q.end(), 0);

        for (int i = 0; i < N; ++i)
        {
            fill(flow[i].begin(), flow[i].end(), 0);
        }

        int totflow = 0;
        while (int flow = BlockingFlow(source, sink))
            totflow += flow;
        return totflow;
    }
};

void addEdges(const string& s, MaxFlow& maxFlow)
{
    int app = s[0] - 'A' + 2;
    int users = s[1] - '0';
    maxFlow.AddEdge(0, app, users);

    for (int i = 3; i < s.size() - 1; ++i)
    {
        int computerId = s[i] - '0' + 28;
        maxFlow.AddEdge(app, computerId, 1);
    }
}

int main()
{
    string s = "";

    while (getline(cin, s))
    {
        if (s.length() == 0) continue;

        string assign = "__________";
        int usersTotal = 0;

        vector<int> apps;

        MaxFlow maxFlow(38);
        addEdges(s, maxFlow);
        apps.push_back(s[0] - 'A' + 2);
        usersTotal += s[1] - '0';

        while (getline(cin, s) && s.length() != 0)
        {
            addEdges(s, maxFlow);
            apps.push_back(s[0] - 'A' + 2);
            usersTotal += s[1] - '0';
        }

        for (int i = 0; i < 10; ++i)
        {
            maxFlow.AddEdge(i + 28, 1, 1);
        }

        int totalFlow = maxFlow.GetMaxFlow(0, 1);

        if (usersTotal == totalFlow)
        {
            for (int i = 0; i < apps.size(); ++i)
            {
                int appid = apps[i];
                char appchar = appid - 2 + 'A';

                for (int j = 28; j < 38; ++j)
                {
                    if (maxFlow.flow[appid][j] == 1)
                    {
                        assign[j - 28] = appchar;
                    }
                }
            }

            cout << assign << "\n";
        }
        else
        {
            cout << "!\n";
        }
    }

    return 0;
}

