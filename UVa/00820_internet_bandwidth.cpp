/**
 * Ertsiger
 * 11/11/2016
 * Time: 0.000
 * Max-Flow code from: https://github.com/jaehyunp/stanfordacm/blob/master/code/MaxFlow.cc
 */
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define X first
#define Y second
#define PB push_back
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MP make_pair
#define SZ size()

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
        int totflow = 0;
        while (int flow = BlockingFlow(source, sink))
            totflow += flow;
        return totflow;
    }
};

int main()
{
    int nid = 1;
    int n;

    while (cin >> n)
    {
        if (n == 0) break;

        MaxFlow mf(n);

        int s, t, c;
        cin >> s >> t >> c;

        --s;
        --t;

        int n1, n2, cap;

        for (int i = 0; i < c; ++i)
        {
            cin >> n1 >> n2 >> cap;

            --n1;
            --n2;

            if (n1 == s || n2 == t)
            {
                mf.AddEdge(n1, n2, cap);
            }
            else if (n2 == s || n1 == t)
            {
                mf.AddEdge(n2, n1, cap);
            }

            if (n1 != s && n1 != t && n2 != s && n2 != t)
            {
                mf.AddEdge(n1, n2, cap);
                mf.AddEdge(n2, n1, cap);
            }
        }

        cout << "Network " << nid << endl;
        cout << "The bandwidth is " << mf.GetMaxFlow(s, t) << "." << endl << endl;

        ++nid;
    }

    return 0;
}

