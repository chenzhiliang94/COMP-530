#include<stdio.h>
#define outsize 81
int main(){
   char ruler[]="1=========2=========3=========4==ruler==5=========6=========7=========8=========";
	printf("%s\n%s\n%s\n",ruler,"Welcome to Duo's 80-character Output Homework\n(Up to Unlimited lines, Press Control+C to terminate)",ruler);
	printf("Please enter characters:\n");
	char stdin = 0;//For temporary store the input.
	char stdout[outsize]="";
  	int n = 0;// Index of Output lines, subject to Maximal number of Lines 
	int i=0,j=0,flag=0;//,outsize=81;
       while(1){// unlimited output, 80 filled and then output, otherwise Ctr1+C suspend.
	//for(n=0,j=0;n<200;n++){during testing, up to 200 lines, the upper bound may be revised
	if(flag==-1)break;
	n++;//The line number;
	while(j<outsize-1){ 
		// a loop which read 80 charcters from input
		// compress ** into ^, recode \n as white space
		if(scanf("%1c",&stdin)==EOF){
			flag=-1; break;
		}
		if(stdin=='\n'){
			stdout[j]=' ';
		}
		else if(j!=0&&stdin=='*'&&stdout[j-1]=='*'){
			stdout[--j]='^';
		  }
		else{
		 	stdout[j]=stdin;
		    }
		j++;
	     }
	if(flag==-1)break;
	if(stdout[outsize-2]!='*'){//output when the last input is not '*'
		stdout[outsize-1]=0;//End of char[]
		printf("\nOutput--80-character Line: %d Ctrl+C to terminate\n",n);
		printf("%s\n",ruler);
		printf("%s\n",stdout);
		printf("%s\n\n",ruler);
		j=0;
	    }
	else{//stdout[79]='*', Last input is '*',possible to have a next '*' 
		scanf("%1c",&stdin);//read the 81st character
		char temp = stdin;
		if(temp=='*'){ //81st is '*', compress ** to ^ as the 80th char and output
			stdout[outsize-2]='^';
			stdout[outsize-1]=0;
		        printf("\nOutput--80-character Line: %d Ctrl+C to terminate\n",n);
                	printf("%s\n",ruler);
                	printf("%s\n",stdout);
                	printf("%s\n\n",ruler);
                	j=0;
		}
		else{ //81st is not '*',output stdout and put 81st char into the next line.
			if(temp=='\n'){temp=' ';}
			stdout[outsize-1]=0;
                        printf("\nOutput--80-character Line: %d Ctrl+C to terminate\n",n);
			printf("%s\n",ruler);
                        printf("%s\n",stdout);
                        printf("%s\n\n",ruler);
			stdout[0]=temp;
                        j=1;			
		}
	   }	
       }	
       return 0;
}
