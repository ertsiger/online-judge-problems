// O(log n) ops. to compute nth fibonacci number
// use methods 'matriz' and 'expo' of the notebook
matriz m;
m.v[0][0] = 1;
m.v[0][1] = 1;
m.v[1][0] = 1;
m.v[1][1] = 0;

int n = 2; // find 2nd fibo number
matriz res = expo(m, n);
res.v[0][1]
