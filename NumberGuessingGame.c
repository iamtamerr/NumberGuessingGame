#include <stdio.h>
#include <stdlib.h>


int main() {
	
	int rand_max,number,j,a,b,x,guess=0,i=1,counter1=0,counter2=0,guess_counter=1,k=0,temp=0;
	
	for(x=1;x<=46;x++)
		printf("-");
	printf("\n");
	
	printf("--------       NUMBER GUESS GAME      --------\n");
	
	for(x=1;x<=46;x++)
		printf("-");
	printf("\n");
	
	printf("Enter the number of digits for the game 4-10= ");
	scanf("%d",&rand_max);
	
	int org_serie[rand_max];
	int guess_serie[rand_max];
	int guess_elements[guess_counter];
	
	// Generates Random Number
	srand(time(0));

	switch(rand_max) {
		
		case 4: number = (rand() % (9000) + 1000);	
		break;
		case 5: number = (rand() % (90000) + 10000);	
		break;
		case 6: number = (rand() % (900000) + 100000);
		break;
		case 7: number = (rand() % (9000000) + 1000000); 
		break;
		case 8: number = (rand() % (90000000) + 10000000); 
		break;
		case 9: number = (rand() % (900000000) + 100000000); 
		break;
		case 10: number = (rand() % (9000000000) + 1000000000); 
		break;			
	}
	
	// Splits the Generated Number into Its Digits
	while (number > 0){  

        a = number % 10;  
        number = number/10;   
        
		org_serie[rand_max-i] = a;
		i++;
        
	}
	
	// Prediction and Control Section
	do{
		
		// Guessing Part
		printf("Enter a guess=");
		scanf("%d",&guess);
		
		guess_elements[k] = guess;
		
		i = 1; 
		// The Estimated Number Is Divided Into Digits.
		while (guess > 0){  

        
        b = guess % 10;  
        guess = guess/10;   
        
		guess_serie[rand_max-i] = b;
		i++;
		}
		
		i = 1; 
		
		// A Comparison Is Made Between The Number Generated And The Estimate
		for(i=0;i<rand_max;i++)
			for(j=0;j<rand_max;j++)
				if(org_serie[i]==guess_serie[j] && i==j)
					counter1++;
				else if(org_serie[i]==guess_serie[j] && i != j)
					counter2++;
		printf("+%d-%d\n",counter1,counter2);			
		if(counter1==rand_max){
			continue;
		}	
		else{
			counter1 = 0;
			counter2 = 0;				
		}
		guess_counter++;
		k++;	
	}	
	while(counter1!=rand_max);
	
	printf("Congratz you won the game\n");
	printf("Total number of tries=%d\n",guess_counter);
		
	// The Part where the Estimated Numbers are Sorted and Transferred to the Array
	 for (i = 0; i < guess_counter; i++) {     
        for (j = i+1; j < guess_counter; j++) {     
           if(guess_elements[i] > guess_elements[j]) {    
               temp = guess_elements[i];    
               guess_elements[i] = guess_elements[j];    
               guess_elements[j] = temp;    
           }     
        }     
    }    
    
    printf("All guesses from smallest to largest:");
    
 	 for (i = 0; i < guess_counter; i++) {     
        printf("%d  ", guess_elements[i]);    
    }    
      
		
	return 0;
}
