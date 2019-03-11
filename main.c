#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct wrongAns{
		char *ans[100];
		}wrongAns;
		wrongAns wAns[10];

float findTotal(int n, float* operands, int* operators);  //function that computes the total
char findOp(int m);

int main(int argc, char* argv[])
{
    srand(time(NULL));      //initializing rand function

    if(argc!=2){
        printf("Invalid input\n");        //making sure the input is in the correct form
        return 0;
    }

    //generate vectors with dynamic allocation
    int n= atoi(argv[1]);       //n is the input from the user
    int* operators = (int*) malloc ((n-1)*sizeof(int));
    float* operands = (float*) malloc (n*sizeof(float));

    //initializing wrong counter and wrong array
    int wrong = 0;

    for(int k=0;k<10;k++){
        for(int i=0; i<n; i++){
            operands[i]=(rand()%100)+1;        //generating random numbers n times
        }
        for(int i=0; i<n-1; i++){
            operators[i]=rand()%4;         //generating n-1 operations
        }

        for(int i=0; i<n; i++){             //printing on screen the operations
            printf("%.0f ",operands[i]);
            if(i!=n-1){
                if(operators[i]==0){
                    printf("+ ");
                    }
                if(operators[i]==1){
                    printf( "- ");
                    }
                if(operators[i]==2){
                    printf( "* ");
                    }
                if(operators[i]==3){
                    printf("/ ");
                }
            }
        }
        printf("= ");
        float uTot;
        scanf("%f", &uTot);
        float tot = findTotal(n, operands, operators);      //computing total
        float Dtot = uTot - tot;           //checking answer
        if (Dtot>0.05||Dtot<-0.05){
            switch(n){
                case 3:	sprintf(wAns[wrong].ans, "%.0f %c %.0f %c %.0f = %.2f\n", operands[0], findOp(operators[0]), operands[1], findOp(operators[1]), operands[2], tot);
			break;
                case 4: sprintf(wAns[wrong].ans, "%.0f %c %.0f %c %.0f %c %.0f = %.2f\n", operands[0], findOp(operators[0]), operands[1], findOp(operators[1]), operands[2], findOp(operators[2]), operands[3],  tot);
                        break;
                case 5: sprintf(wAns[wrong].ans, "%.0f %c %.0f %c %.0f %c %.0f %c %.0f = %.2f\n", operands[0], findOp(operators[0]), operands[1], findOp(operators[1]), operands[2], findOp(operators[2]), operands[3], findOp(operators[3]), operands[4],  tot);
                        break;
                default: printf("Error");
                        break;
            }
                wrong++;
        }
    }  //end of 10 inputs
	printf("\n\nYour bitch ass got %d answers wrong.\n\n", wrong);
    for(int i=0; i<wrong; i++){
        printf("%s\n", wAns[i].ans);
	    }
    return 0;
}

//to determine operations we generate a number between 0 and 3 and assign an operation to each value
float findTotal(int n, float* operands, int* operators){
    float tot = operands[0];

    for(int i=0; i<n; i++){
        if (operators[i]==0){
            tot= tot+ operands[i+1];
        }
        if (operators[i]==1){
            tot= tot- operands[i+1];
        }
        if (operators[i]==2){
            tot= tot* operands[i+1];
        }
        if (operators[i]==3){
            tot= tot/ operands[i+1];
        }

    }
    return tot;
}

char findOp(int m){
	switch(m){
		case 0:
			return '+';
		case 1:
			return '-';
		case 2:
			return '*';
		case 3:
			return '/';
		default:
		exit(EXIT_FAILURE);
		}
}
