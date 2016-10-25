/**
 * Ertsiger
 * 25/10/2016 (23 years!)
 * Time: 2.846
 */
#include <iostream>
#include <utility>
#include <vector>
#include <map>

#define LL long long

using namespace std;

typedef vector<LL> VI;
typedef vector<VI> VVI;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
    for (int j = 0; j < w[i].size(); j++) {
        if (w[i][j] && !seen[j]) {
            seen[j] = true;
            if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
                mr[i] = j;
                mc[j] = i;
                return true;
            }
        }
    }
    return false;
}

int BipartiteMatching(const VVI &w, VI &mr, VI &mc) {
    mr = VI(w.size(), -1);
    mc = VI(w[0].size(), -1);

    int ct = 0;

    for (int i = 0; i < w.size(); i++) {
        VI seen(w[0].size());
        if (FindMatch(i, w, mr, mc, seen)) ct++;
    }
    return ct;
}

pair<LL, LL> P[2501];

LL getIdForOp(LL& currentId, map<LL, LL>& opToId, map<LL, LL>& idToOp, LL opResult)
{
	auto it = opToId.find(opResult);

	LL resultId;

	if (it == opToId.end())
	{
		opToId[opResult] = currentId;
		idToOp[currentId] = opResult;
		resultId = currentId;
		++currentId;
	}
	else
	{
		resultId = it->second;
	}
	
	return resultId;
}

int main()
{
	int n = 0;
	
	bool first = true;
	
	while (cin >> n)
	{
		if (first) first = false;
		else cout << "\n";
	
		LL currentId = 0;
		map<LL, LL> opToId;
		map<LL, LL> idToOp;
	
		VVI matrix;
	
		for (int i = 0; i < n; ++i)
		{
			VI cols(7501, 0);
			matrix.push_back(cols);
		}
	
		for (int i = 0; i < n; ++i)
		{
			cin >> P[i].first >> P[i].second;
			
			LL sum = P[i].first + P[i].second;
			LL sub = P[i].first - P[i].second;
			LL mult = P[i].first * P[i].second;

			LL sum_id = getIdForOp(currentId, opToId, idToOp, sum);
			LL sub_id = getIdForOp(currentId, opToId, idToOp, sub);
			LL mult_id = getIdForOp(currentId, opToId, idToOp, mult);
			
			matrix[i][sum_id] = 1;
			matrix[i][sub_id] = 1;
			matrix[i][mult_id] = 1;
		}
		
		VI mr, mc;
		LL matchingSize = BipartiteMatching(matrix, mr, mc);
		
		if (matchingSize != n)
		{
			cout << "impossible" << endl;
		}
		else
		{
			for (LL i = 0; i < mr.size(); ++i)
			{
				LL firstNum = P[i].first;
				LL secondNum = P[i].second;
				LL result_id = mr[i];
				LL result = idToOp[result_id];
				
				cout << firstNum;
				
				if (firstNum + secondNum == result)
				{
					cout << " + "; 
				}
				else if (firstNum - secondNum == result)
				{
					cout << " - ";
				}
				else if (firstNum * secondNum == result)
				{
					cout << " * ";
				}
				
				cout << secondNum << " = " << result << "\n"; 
			}
		}
	}

	return 0;
}


