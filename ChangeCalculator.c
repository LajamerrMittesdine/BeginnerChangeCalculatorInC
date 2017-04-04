#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
void calculateChange(int *c, int amount, int *increment);
 
int main(void){
    int input[4] = {0,0,0,0};
    int a[12] = {0};
    const float b[12] = {10000,5000,2000,1000,500,200,100,50,25,10,5,1};
 
    //Get the user input values
    scanf("%d.%d %d.%d",&input[0],&input[1],&input[2],&input[3]);
 
    //Calculate the difference
    input[1] += input[0] * 100;
    input[3] += input[2] * 100;
    input[0] = input[1] - input[3];
    
    //Calculate the change while updating its value and printing the result.
    for(int i = 0, n = (sizeof(a)/sizeof(a[0]))-1; i<=n; i++){
        calculateChange(&input[0],b[i],&a[i]);
    }
    //Debugging Message Only
    //Verify the output
    printf("The change is $%.2f and we calculated $%.2f\n",(input[1]-input[3])/100.00,
    (a[0]*b[0]/100) + (a[1]*b[1]/100) + (a[2]*b[2]/100) + (a[3]*b[3]/100) + (a[4]*b[4]/100) +
    (a[5]*b[5]/100) + (a[6]*b[6]/100) + (a[7]*b[7]/100) + (a[8]*b[8]/100) + (a[9]*b[9]/100) +
    (a[10]*b[10]/100) + (a[11]*b[11]/100)
    );
    return 0;
}
 
void calculateChange(int *c, int amount, int *increment){
    unsigned int divider = 0;
    divider = *c / amount;
    *c = *c - amount*divider;
    *increment += divider;
    if(*increment > 0){
        printf("%i x $%.2f\n",divider, amount/100.00);
    }
}
