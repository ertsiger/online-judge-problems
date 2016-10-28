#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<unsigned long long> sheldons;

void printBits(unsigned long long n , int len){
	
	for(int j = len-1 ; j >= 0 ; --j){
		cout<< (int)((n & ((unsigned long long)1)<<j )>0) << " ";
	}
	cout<<endl;
}

void generateSheldon(int lng){
	if(lng == 64)
		return;
	unsigned long long num = 0;
	int nu , nc ;
	for(nu = 1 ; nu <= lng ; ++nu){
		//metemos nu  unos
		//num = ( ((unsigned long long) 1) << nu )-1;
		
		for(nc = lng-nu; nc >= 0; --nc ){	
			num = ( ((unsigned long long) 1) << nu )-1;
			//cout<<nu<<" "<<nc<<endl;
			num =  num << nc ;
			int totlen = nu + nc;
			if(nc != 0){
				for(totlen = nu + nc ; totlen < lng ; ){
					num = (num << nu)+(( ((unsigned long long) 1) << nu )-1);
					totlen += nu;
					if(totlen < lng){
						num = num << nc;
						totlen += nc;
					}
				}
			}
			//printBits(num,lng+3);
			if(totlen == lng)
				sheldons.push_back(num);
		}
		
	}
	generateSheldon(lng+1);
}


int main(){
	generateSheldon(0);
	/*
	for(int i = 0 ; i < sheldons.size() ; ++i){
		cout<<sheldons[i]<<endl;
		printBits(sheldons[i],64);
	}*/
	
	unsigned long long x , y ;
	while(cin>>x>>y){
		
		unsigned long long upp = lower_bound(sheldons.begin(),sheldons.end(),y)-sheldons.begin();
		unsigned long long low = lower_bound(sheldons.begin(),sheldons.end(),x)-sheldons.begin();
		//cout<<sheldons[low] << " " << sheldons[upp]<<endl;
		
		if(sheldons[upp] > y )
		{
			upp--;
		}
		
		//cout<<low << " " << upp<<endl;
		//if(low != 0 && sheldons[low] != x){
		//	low++;
		//}
		/*
		if(sheldons[upp] != y){
			upp--;
		}*/
		//cout<<low<<" "<<upp<<endl;
		cout<<upp-low+1<<endl;
		/*
		unsigned long long upp = lower_bound(sheldons.begin(),sheldons.end(),y)-sheldons.begin();
		unsigned long long low = upper_bound(sheldons.begin(),sheldons.end(),x)-sheldons.begin();
		//cout<<sheldons[low] << " " << sheldons[upp]<<endl;
		if(low != 0 && sheldons[low-1] == x){
			low--;
		}
		if(sheldons[upp] != y){
			upp--;
		}
		//cout<<low<<" "<<upp<<endl;
		cout<<upp-low+1<<endl;
		*/
		
	}
}


