/**
 * Ertisger
 * 08/10/2016
 * Time: 0.006
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int P, n=0;
	cin >> P;

	for(int i = 0; i < P; i++){
		int k, p, q;
		char z;
		cin >> k >> p >> z >> q;
		vector<bool> v;
		while(p != 1 || q != 1){
			if(p>=q){
				v.push_back(true);
				p = p - q;
			}else{
				v.push_back(false);
				q = q - p;
			}
		}

		long long n = 1;
		for (int j = v.size() - 1; j >= 0; j--){
			n = 2*n;
			if (v[j]){
				n++;
			}
		}
		cout << k << " " << n << endl;
	}

	return 0;
}