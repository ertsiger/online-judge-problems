/**
 * Authors: jorgealemangonzalez, Ertsiger
 * 28/09/2016
 * Time: 0.020
 */
#include<iostream>
#include<vector>
#include<queue>
#define X first
#define Y second
#define LI long long
#define MP make_pair
#define PB push_back
#define SZ size()
#define SQ(a) ((a)*(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define FOR(i,x,y) for(int i=(int)x; i<(int)y; i++)
#define RFOR(i,x,y) for(int i=(int)x; i>(int)y; i--)
#define SORT(a) sort(a.begin(), a.end())
#define RSORT(a) sort(a.rbegin(), a.rend())
#define IN(a,pos,c) insert(a.begin()+pos,1,c)
#define DEL(a,pos,cant) erase(a.begin()+pos,cant)

using namespace std;
int N; // numero de objetos N <= 1000
int v[201] = { 0 }; // valor de objetos
int p[201] = { 0 }; // peso de objetos
int A[201][10001]; // matriz de resultados
int C; // capacidad C <= 1000

int mochila() {

	for (int j = 0; j <= C; j++)
		A[0][j] = 0;
	for (int i = 1; i <= N; i++) {
		A[i][0] = 0;
		for (int j = 1; j <= C; j++) {
			A[i][j] = A[i - 1][j];
			if (p[i - 1] <= j) {
				int r = A[i - 1][j - p[i - 1]] + v[i - 1];
				A[i][j] = MAX(A[i][j], r);
			}
		}
	}
	return A[N][C];
}

int main() {

	int D, P, R, B, ent1, ent2;


	while (cin >> D >> P >> R >> B) {
		vector<int> Map[201];
		int S[101], T[101];
        for(int i = 0 ; i < 201 ; ++i){
            v[i] = 0;
            p[i] = 0;
        }
        
		for (int i = 0; i < D; ++i) {
			cin >> S[i];
		}

		for (int i = 0; i < P; ++i) {
			cin >> T[i];
		}

		for (int i = 0; i < R; ++i) {
			cin >> ent1 >> ent2;
			ent2 += D;
			Map[ent1 - 1].push_back(ent2 - 1);
			Map[ent2 - 1].push_back(ent1 - 1);
		}

		bool grouped[201] = { false };
		int indexV = -1;
		for (int pe = 0; pe < D + P; ++pe) {
			if (grouped[pe])
				continue;
			indexV++;

			queue<int> toVisit;
			toVisit.push(pe);

			while (!toVisit.empty()) {
				int first = toVisit.front();
				toVisit.pop();
				if (!grouped[first]) {
					grouped[first] = true;

					if (first < D) {
						v[indexV]++;
						p[indexV] += S[first];
					}
					else {
						v[indexV]--;
						p[indexV] += T[first - D];
					}

					for (int i = 0; i < Map[first].size(); ++i) {
						toVisit.push(Map[first][i]);
					}
				}
			}
		}

		//GO MOCHILA
		N = indexV + 1;
		C = B;
		//printf("N,v[0],p[0],A,C,D,P,R,B \n%d %d %d %d %d %d %d %d %d\n",N,v[0],p[0],A[0][0],C,D,P,R,B);
		int mochi1 = mochila();
		for(int i = 0 ; i < N ; ++i){
		    v[i] = -v[i];
		}
		int mochi2 = mochila();
		cout << (mochi2 >= 0 ? mochi2 : 0) + D << " ";
		cout << (mochi1 >= 0 ? mochi1 : 0) + P << endl;
	}

}