/**
 * Author: Ertsiger
 * 19/05/2016
 * Time: 0.320
 */
#include <iostream>

using namespace std;

int v[10000]; // primes
int N = 0;
int ring[17];
int ringSize = 0;
bool usedNum[17];

void savePrimes()
{
    int k = 0;
    v[k++] = 2;
    for (int i = 3; i <= 10010; i += 2) {
        bool b = true;
        for (int j = 0; b && v[j] * v[j] <= i; j++)
            b = i%v[j] > 0;
        if (b)
            v[k++] = i;
    }
}

bool isPrime(int x)
{
    bool prime = true;
    for (int j = 0; prime && v[j] * v[j] <= x; j++)
        prime = x%v[j] > 0;
    return prime;
}

void findRing()
{
    if (ringSize == N)
    {
        if (isPrime(1 + ring[ringSize - 1]))
        {
            cout << "1";
            for (int i = 1; i < N; ++i)
            {
                cout << " " << ring[i];
            }

            cout << endl;
        }
    }
    else
    {
        for (int i = 2; i <= N; ++i)
        {
            if (!usedNum[i])
            {
                if (isPrime(i + ring[ringSize - 1]))
                {
                    ring[ringSize] = i;
                    ++ringSize;
                    usedNum[i] = true;

                    findRing();

                    --ringSize;
                    usedNum[i] = false;
                }
            }
        }
    }
}

int main()
{
    savePrimes();

    int c = 1;

    while (cin >> N)
    {
        if (c != 1)
        {
            cout << endl;
        }

        for (int i = 1; i <= N; ++i)
        {
            usedNum[i] = false;
        }

        cout << "Case " << c << ":\n";

        ring[0] = 1;
        ringSize = 1;
        usedNum[1] = true;

        findRing();

        ++c;
    }

    return 0;
}

