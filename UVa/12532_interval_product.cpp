/**
 * Author: drako9
 * 17/11/2016
 * Time: 0.170
 */
#include <bits/stdc++.h>
using namespace std;

#define PB(a) push_back(a)
#define MP(a,b) make_pair(a,b)
#define FOR(i,j) for(int i = 0 ; i < j; ++i)
typedef pair<int,pair<int,int> > PII;


int N , C;
int reptable[3][100005];



int getRep(int ent){//-1 = 2 , 0 = 0; 1 = 1
    int rep;
    if(ent < 0)rep = 2; 
    else if(ent == 0)rep = 0;
    else if(ent > 0)rep = 1;
    return rep;
}

void initialize(int* values){
    for(int i = 1 ; i < N+1 ; ++i){
        int x = i;
        for(; x<N+1; x+=x&-x)		
            reptable[getRep(values[i])][x]++;
    }
}

void update(int* values,int x,int val) {//val no viene representado
    int initRep = getRep(values[x]);
    int repVal = getRep(val);
    if(initRep == repVal)return;
    
    values[x] = val;
    
    for(;x < N+1 ; x+=x&-x){
        reptable[initRep][x]--;
        reptable[repVal][x]++;
    }
    
}

PII query(int x) {   //Cuidado con llegar a la posicion 0
    int acum[3];
    acum[0] = 0;
    acum[1] = 0;
    acum[2] = 0;
    
    for(;x;x-=x&-x){
        acum[0] += reptable[0][x];
        acum[1] += reptable[1][x];
        acum[2] += reptable[2][x];
    }
    
    return MP(acum[0],MP(acum[1],acum[2]));
}

int queryRange(int x,int y){ //x < y
    
    PII xq = query(x-1);
    PII yq = query(y);
    
    if(yq.first - xq.first > 0 )return 0;
    else{
        int neg = yq.second.second - xq.second.second;
        if(neg % 2 == 0)return 1;
        else return 2;
    }
    
}


int main() {
    while(cin>>N>>C){
        
        int values[N+1];
        FOR(i,N+1)reptable[0][i]=0,reptable[1][i]=0,reptable[2][i]=0;
        FOR(i,N){
            int bi = i+1;
            int rep,ent;
            cin>>ent;
            values[bi] = ent;
            
        }
        initialize(values);
        
        int x , y ;
        char cha;
        string sol = "";
        FOR(i,C){
            cin>>cha>>x>>y;
            if(cha == 'C'){
                update(values,x,y);
            }else{
                int val = queryRange(x,y);
                if(val == 0)sol+="0";
                if(val == 1)sol+="+";
                if(val == 2)sol+="-";
                /*cout<<sol<<endl;
                FOR(i,N)cout<<values[i+1]<<" ";
                cout<<endl;*/
            }           
        }
        cout<<sol<<endl;
    }
}
