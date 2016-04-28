/**
 * Author: Ertisger
 * 28/04/2016
 * Time: 0.000
 */
#include <iostream>

using namespace std;

int m; // rows
int n; // columns
char map[101][101];

void markCells(int i, int j)
{
    if ((i >= 0) && (i <= m - 1) && (j >= 0) && (j <= n - 1))
    {
        if (map[i][j] == '@')
        {
            map[i][j] = '*';
            
            for (int x = -1; x <= 1; ++x)
            {
                for (int y = -1; y <= 1; ++y)
                {
                    if (x != 0 || y != 0)
                    {
                        markCells(i + x, j + y);
                    }
                }
            }
        }
    }
}

int main()
{
    while (cin >> m >> n)
    {
        if (!m && !n)
        {
            break;
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> map[i][j];
            }
        }

        int c = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (map[i][j] == '@')
                {
                    ++c;
                    markCells(i, j);
                }
            }
        }

        cout << c << endl;
    }

    return 0;
}

