/**
 * Ertsiger
 * 03/11/2016
 * Time: 0.590
 */
#include <iostream>
#include <set>

#define LL long long

using namespace std;

int main()
{
    int t = 0;
    cin >> t;

    int n = 0;
    LL s = 0;

    while (t--)
    {
        multiset<LL> canvas;

        cin >> n;

        for (int i = 0; i < n; ++i)
        {
            cin >> s;
            canvas.insert(s);
        }

        LL totalInk = 0;

        while (canvas.size() > 1)
        {
            LL a = *canvas.begin();
            canvas.erase(canvas.begin());

            LL b = *canvas.begin();
            canvas.erase(canvas.begin());

            totalInk += a + b;
            canvas.insert(a + b);
        }

        cout << totalInk << endl;
    }

    return 0;
}

