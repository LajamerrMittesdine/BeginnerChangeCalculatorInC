#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
void calculateChange(int *c, int amount, int *increment);
 
int main(void){
    //input[0] = Paid Dollars, input[1] = Paid Cents 
    //input[2] = Owe Dollars,  input[3] = Owe Cents
    int input[4] = {0,0,0,0};
 
    //a[0] = Number of $100 bills, a[1] = Number of $50 bills
    //a[2] = Number of $20 bills,  a[3] = Number of $10 bills
    //a[4] = Number of $5 bills,   a[5] = Number of $2 bills
    //a[6] = Number of $1 bills,   a[7] = Number of $0.50 coins
    //a[8] = Number of $0.25 coins,a[9] = Number of $0.10 coins
    //a[10]= Number of $0.05 coins,a[11]= Number of $0.01 coins
    int a[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    
    //Denomination values converted to cents
    //$100 = 10000 cents, $0.01 = 1
    const int b[12] = {10000,5000,2000,1000,500,200,100,50,25,10,5,1};
 
    //Get the user input values
    //Format is amount the user paid and the amount that is actually owed
    //2135.35 1454.86 gets broken up into 2135 35 1454 86
    scanf("%d.%d %d.%d",&input[0],&input[1],&input[2],&input[3]);
 
    //Calculate the difference
    //2135.35 - 1454.86 = 680.49
    //Covert the dollars to cents
    //((2135 * 100) + 35) = 213535 cents
    //((1454 * 100) + 86) = 145486 cents
    //213535 - 145486     =  68049 cents
    input[0] = (((input[0] * 100) + input[1]) - ((input[2] * 100) + input[3]));
    
    //debug value only
    int debugValue = input[0];
    
    //Calculate the change while updating its value and printing the result.
    for(int i = 0, n = (sizeof(a)/sizeof(a[0]))-1; i<=n; i++){
        calculateChange(&input[0],b[i],&a[i]);
    }
    
    //Verify the output
    //Debug Message Only
    printf("Debug Message: The change is $%.2f and we calculated $%.2f\n",(debugValue)/100.00,
    (a[0]*b[0]/100.00) +  (a[1]*b[1]/100.00)   + (a[2]*b[2]/100.00) + 
    (a[3]*b[3]/100.00) +  (a[4]*b[4]/100.00)   + (a[5]*b[5]/100.00) +  
    (a[6]*b[6]/100.00) +  (a[7]*b[7]/100.00)   + (a[8]*b[8]/100.00) + 
    (a[9]*b[9]/100.00) +  (a[10]*b[10]/100.00) + (a[11]*b[11]/100.00)
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
