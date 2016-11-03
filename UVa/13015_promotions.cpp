
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>

#define PB(a) push_back(a)
#define FOR(i,j) for(int i = 0 ; i < j; ++i)
using namespace std;

int DFS(vector<int> *em,int act, set<int> *visit){
    int sum = 0;
    
    FOR(i,em[act].size()){
        if(!visit->count(em[act][i])){
            visit->insert(em[act][i]);
            sum += DFS(em,em[act][i],visit) +1;
        }
    }
    return sum;
}
int main() {
    int A , B , E , P;
    while(cin>>A>>B>>E>>P){

        vector<int> em[E];
        int pred[E];
        int suc[E];
        FOR(i,P){
            int an , sig;
            cin>>an>>sig;
            em[an].PB(sig);
        }
        FOR(i,E)pred[i] = suc[i] = 0;

        FOR(i,E){
            set<int> *visit = new set<int>();
            suc[i] = DFS(em,i,visit);
            for(set<int>::iterator it = visit->begin() ; it != visit->end() ; ++it){
                pred[*it]++;
            }
            //cout<<"suc "<<suc[i]<<endl;
        }

        int ca=0,cb=0,np=0;
        FOR(i,E){
            //cout<<"pred "<<pred[i]<<endl;
            if(pred[i] >= B)np++;
            if(E - A <0 || suc[i] >= E - A)ca++;
            if(E - B < 0 || suc[i] >= E - B)cb++;
        }
        cout<<ca<<endl<<cb<<endl<<np<<endl;
    }
}