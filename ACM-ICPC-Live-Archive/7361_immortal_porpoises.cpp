#include <iostream>

#define SIZE 4
#define MOD 1000000000

// http://math.stackexchange.com/questions/784710/how-to-prove-fibonacci-sequence-with-matrices

using namespace std;

struct matriz {
    long v[SIZE][SIZE];
    matriz() { init(); } // matriz de 0's
    matriz(int x) {      // matriz con x's en la diagonal
        init();
        for (int i = 0; i < SIZE; i++) v[i][i] = x;
    }
    void init() {
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                v[i][j] = 0;
    }
    // multiplicacion de matrices modulo MOD
    matriz operator*(matriz &m) {
        matriz n;
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                for (int k = 0; k < SIZE; k++)
                    n.v[i][j] = (n.v[i][j] + v[i][k]*m.v[k][j])%MOD;
        return n;
    }
};

// funciona con T=matriz y U=big
template <typename T,typename U> T expo(T &t, U n) {
    if (n == U(0)) return T(1);
    else {
        T u = expo(t, n/2);
        if (n%2 > 0) return u*u*t;  else return u*u;
    }
}

int main()
{
    int p = 0;
    cin >> p;

    matriz m;
    m.v[0][0] = 1;
    m.v[0][1] = 1;
    m.v[1][0] = 1;
    m.v[1][1] = 0;

    while (p--)
    {
        int k = 0;
        long y = 0;
        
        cin >> k >> y;
        
        matriz res = expo(m, y);
        cout << k << " " << res.v[0][1] << endl;
    }

    return 0;
}


