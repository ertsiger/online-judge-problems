/**
 * Ertsiger
 * 24/10/2016
 * Time: 4.558
 */
#include <iostream>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

pair<int, int> tasks[350001];

int main()
{
    int n = 0, m = 0;

    while (cin >> n >> m)
    {
        int a, s;

        for (int i = 0; i < n; ++i)
        {
            cin >> a >> s;
            tasks[i].first = a;
            tasks[i].second = a + s;
        }

        sort(tasks, tasks + n);

        int numMachines = 0;

        set< pair<int, int> > lockTimes; // priorize those tasks finishing first

        for (int i = 0; i < n; ++i)
        {
            const pair<int, int>& p = tasks[i];

            while (!lockTimes.empty() && p.first > lockTimes.begin()->first + m)
            {
                lockTimes.erase(lockTimes.begin());
            }

            if (lockTimes.empty())
            {
                lockTimes.insert(make_pair(p.second, numMachines));
                ++numMachines;
            }
            else
            {
                const pair<int, int>& firstLock = *lockTimes.begin();

                if (firstLock.first <= p.first && p.first <= firstLock.first + m)
                {
                    int machineId = firstLock.second;
                    lockTimes.erase(lockTimes.begin());
                    lockTimes.insert(make_pair(p.second, machineId));
                }
                else
                {
                    lockTimes.insert(make_pair(p.second, numMachines));
                    ++numMachines;
                }
            }
        }

        cout << n - numMachines << endl;
    }

    return 0;
}


