/**
 * Author: Ertsiger
 * 29/04/2016
 * Time: 0.000
 */
#include <iostream>
#include <set>
#include <string>

using namespace std;

char c, c1, c2;
set<char> adj[129];
bool visited[129];

void markNodes(char id)
{
    for (auto it = adj[id].begin(); it != adj[id].end(); ++it)
    {
        if (!visited[*it])
        {
            visited[*it] = true;
            markNodes(*it);
        }
    }
}

int main()
{
    int cases = 0;
    cin >> cases;

    while (cases--)
    {
        cin >> c;

        for (char i = 'A'; i <= c; ++i)
        {
            adj[i].clear();
            visited[i] = false;
        }

        string line = "";

        getline(cin, line);

        while (getline(cin, line))
        {
            if (line.length() != 2)
            {
                break;
            }
            else
            {
                adj[line[0]].insert(line[1]);
                adj[line[1]].insert(line[0]);
            }
        }

        int count = 0;

        for (char i = 'A'; i <= c; ++i)
        {
            if (!visited[i])
            {
                visited[i] = true;
                markNodes(i);
                ++count;
            }
        }

        cout << count << endl;

        if (cases != 0)
        {
            cout << endl;
        }
    }

    return 0;
}

