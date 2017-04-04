#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
void calculateChange(float *c, float amount, int *increment);
 
int main(void){
    float paid = 0.00;
    float owe = 0.00;
    float change = 0.00;
    int a[12] = {0};
    const float b[12] = {100.00,50.00,20.00,10.00,5.00,2.00,1.00,0.50,0.25,0.10,0.05,0.01};
 
    //Get the user input values
    //Example: 5625.24 3241.68
    scanf("%f %f",&paid,&owe);
 
    //Calculate the difference
    change = round((paid-owe) * 100.0)/100.0;
    
    //Calculate the change while updating its value and printing the result.
    for(int i = 0, n = (sizeof(a)/sizeof(a[0]))-1; i<=n; i++){
        calculateChange(&change,b[i],&a[i]);
    }
    return 0;
}
 
void calculateChange(float *c, float amount, int *increment){
    unsigned int divider = 0;
    divider = *c / amount;
    *c = *c - amount*divider;
    *increment += divider;
    if(*increment > 0){
        printf("%i x $%.2f\n",divider, amount);
    }
}
