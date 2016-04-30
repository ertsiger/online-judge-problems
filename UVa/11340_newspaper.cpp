/**
 * Author: Ertsiger
 * 30/04/2016
 * Time: 0.300
 */
#include <iostream>
#include <string>
#include <iomanip>
#include <map>

using namespace std;

int main()
{
    int N = 0; // num tests
    int K = 0; // number of paid chars
    int M = 0; // num lines

    cin >> N;

    while (N--)
    {
        cin >> K;

        map<unsigned char, int> money;

        unsigned char c;
        int q;

        for (int i = 0; i < K; ++i)
        {
            cin >> c >> q;
            money[c] = q;
        }

        cin >> M;

        string line = "";

        double totalCents = 0;

        getline(cin, line);

        for (int i = 0; i < M; ++i)
        {
            getline(cin, line);

            for (int j = 0; j < line.length(); ++j)
            {
                if (money.find(line[j]) != money.end())
                {
                    totalCents += money[line[j]];
                }
            }
        }

        cout << fixed << setprecision(2) << totalCents * 0.01 << "$" << endl;
    }

    return 0;
}

