#include <stdio.h>
#include <stdlib.h>
 
void calculateChange(unsigned int *change, unsigned int denominations);
unsigned int countWords(FILE *f);
 
int main(void){
    unsigned int change = 0;
    unsigned int tender[2] = {0,0};
    unsigned int bill[2]  = {0,0};

    FILE *myFiles;
    
    //Get the number of lines of the file
    myFiles = fopen("denominations.txt", "r");
    const unsigned int size = countWords(myFiles);
    fclose (myFiles);
    //Set the array size of denominations to the number of lines in the file.
    unsigned int denominations[size];
    
    myFiles = fopen("denominations.txt", "r");
    
    if (myFiles == NULL){
        printf("Can't open file for reading.\n");
    }
    else{
    	for(unsigned int i = 0; i < sizeof(denominations)/sizeof(*denominations); ++i){
    		fscanf(myFiles, "%u", &denominations[i]);
    	}
        fclose(myFiles);
        while (!feof(stdin)){
		    if (scanf("%u.%u %u.%u",&tender[0],&tender[1],&bill[0],&bill[1]) == 4) break;
 	    }
 	    
 	    //Get the change total in cents
        change = (((tender[0] * 100) + tender[1]) - ((bill[0] * 100) + bill[1]));
    
        for (unsigned int i = 0; i < sizeof(denominations)/sizeof(*denominations); ++i){
            calculateChange(&change,denominations[i]);
        }
    }
    return 0;
}

unsigned int countWords(FILE *f){
   unsigned int count = 0;
   char ch;
   while ((ch = fgetc(f)) != EOF){
       if (ch == '\n')
           count++;
   }
   return ++count;
}
 
void calculateChange(unsigned int *change, unsigned int denominations){
    unsigned int count = *change / denominations;
    *change = *change - denominations*count;
    if(count > 0){
        printf("%u x $%u.%02u\n",count, denominations/100, denominations%100);
    }
}
