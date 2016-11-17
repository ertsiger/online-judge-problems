/* Binary indexed tree. Supports cumulative sum queries in O(log n) */
#define N (1<<18)
#define LL long long 

LL bit[N]={0};	//Binary Indexed Tree , nElements +1 positions
int arr[N]={0};	//Array that represents the BIT (simple data, no cumulative) , nElements +1 positions
//CAUTION !! INDEX STARTS IN 1
void update(LL* bit, int* arr,int x,int val) {	//add or update a value
    int dif = val - arr[x]; //diference between previous value and new value
    arr[x] = val;           //set new value in the array
    for(; x<N; x+=x&-x)     //jumps through indexes by jumps of the last 1 bit adding
        bit[x]+=dif;        //uploads the tree values
}
LL query(LL* bit,int x) {   //acumula desde x hasta 0 
    LL res=0;
    for(;x;x-=x&-x)         //salta quitando el bit de menor peso
        res+=bit[x];
    return res;
}
