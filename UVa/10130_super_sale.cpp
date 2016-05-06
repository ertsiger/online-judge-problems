/**
 * Author: Ertsiger
 * 06/05/2016
 * Time: 0.080
 */
#include <iostream>

using namespace std;

int N; // number of objects
int v[1001]; // values
int p[1001]; // weights
int A[1001][1001]; // result matrix

int knapsack(int C)
{
    for (int j = 0; j <= C; j++)
    {
        A[0][j] = 0;
    }

    for (int i = 1; i <= N; i++)
    {
        A[i][0] = 0;
        for (int j = 1; j <= C; j++)
        {
            A[i][j] = A[i - 1][j];
            if (p[i - 1] <= j)
            {
                int r = A[i - 1][j - p[i - 1]] + v[i - 1];

                if (r > A[i][j])
                {
                    A[i][j] = r;
                }
            }
        }
    }

    return A[N][C];
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        cin >> N;

        for (int i = 0; i < N; ++i)
        {
            cin >> v[i] >> p[i];
        }

        int finalVal = 0, G = 0, g = 0;

        cin >> G;

        for (int i = 0; i < G; ++i)
        {
            cin >> g;
            finalVal += knapsack(g);
        }

        cout << finalVal << endl;
    }

    return 0;
}

