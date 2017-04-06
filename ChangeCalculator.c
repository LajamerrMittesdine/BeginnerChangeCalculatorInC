#include <stdio.h>
#include <stdlib.h>
 
void calculateChange(unsigned int *change, unsigned int denominations);
unsigned int getSizeOfDenominations(FILE *f);

int main(void){
    FILE *myFiles;
    
    myFiles = fopen("denominations.txt", "r");
    
    if (myFiles == NULL){
        printf("./denominations.txt either does not exist or can't be opened.\n");
        return 1;
    }
    else{
       unsigned int change = 0;
       unsigned int tender[2] = {0,0};
       unsigned int bill[2]  = {0,0};
       unsigned int denominations[getSizeOfDenominations(myFiles)];
       
       if(sizeof(denominations)/sizeof(*denominations) == 0){
           printf("./denominations.txt was empty.\n");
           return 2;
       }
       
       for(size_t i = 0; i < sizeof(denominations)/sizeof(*denominations); ++i){
           fscanf(myFiles, "%u", &denominations[i]);
       }
       fclose(myFiles);
       
       while (!feof(stdin)){
           if (scanf("%u.%u %u.%u",&tender[0],&tender[1],&bill[0],&bill[1]) == 4) break;
       }
       
       //Get the change total in cents
       change = (((tender[0] * 100) + tender[1]) - ((bill[0] * 100) + bill[1]));
       
       for (size_t i = 0; i < sizeof(denominations)/sizeof(*denominations); ++i){
           calculateChange(&change,denominations[i]);
       }
       if(change > 0){
           printf("The change wasn't completely divisible by the denominations set.\n"
           "Your total change left over is $%u.%02u\n",change/100,change%100);
       }
    }
    return 0;
}

unsigned int getSizeOfDenominations(FILE *f){
   unsigned int count = 0;
   char ch;
   if (f == NULL){
       fclose(f);
       return 0;
   }
   else{
       while(!feof(f)){
           ch = fgetc(f);
           if(ch == '\n'){
               count++;
           }
       }
       if(count==0){
           if(ftell(f) > 0){
               rewind(f);
               return 1;
           }
           else{
               rewind(f);
               return 0;
           }
       }
       else{
           rewind(f);
           return ++count;
       }
   }
}
 
void calculateChange(unsigned int *change, unsigned int denominations){
    unsigned int count = *change / denominations;
    *change -= denominations*count;
    if(count > 0){
        printf("%u x $%u.%02u\n",count, denominations/100, denominations%100);
    }
}
