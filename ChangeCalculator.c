#include <stdio.h>
#include <stdlib.h>
 
void calculateChange(int *change, int denominations);
 
int main(void){
    int change = 0;
    int tender[2] = {0,0};
    int bill[2]  = {0,0};
    const int denominations[12] = {10000,5000,2000,1000,500,200,100,50,25,10,5,1};
 
    while (!feof(stdin)){
		if (scanf("%d.%d %d.%d",&tender[0],&tender[1],&bill[0],&bill[1]) == 4) break;
 	}
    change = (((tender[0] * 100) + tender[1]) - ((bill[0] * 100) + bill[1]));
    for (size_t i = 0; i < sizeof denominations / sizeof *denominations; ++i){
        calculateChange(&change,denominations[i]);
    }
 
    return 0;
}
 
void calculateChange(int *change, int denominations){
    unsigned int count = *change / denominations;
    *change = *change - denominations*count;
    if(count > 0){
        printf("%d x $%d.%02d\n",count, denominations/100, denominations%100);
    }
}
